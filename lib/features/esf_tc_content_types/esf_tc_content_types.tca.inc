<?php
/**
 * @file
 * Code for the tca content type.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Alter TCA node form.
 */
function esf_tc_content_types_form_esf_tnc_tca_node_form_alter(&$form, &$form_state, $form_id) {
  $form['body']['#access'] = FALSE;
  // Replace status by read only markup.
  $list = $form['field_tca_status'][LANGUAGE_NONE];
  $list_value = $list['#options'][$list['#default_value'][0]];
  if ($list_value) {
    $form['field_tca_status_item'] = array(
      '#type' => 'markup',
      '#markup' => "<strong>" . $list['#title'] . ": </strong>" . $list_value,
      '#weight' => $form['field_tca_status']['#weight'],
    );
    $form['field_tca_status'][LANGUAGE_NONE]['#access'] = FALSE;
  }
  // Add custom validate function.
  $form['#validate'][] = 'esf_tc_content_types_projects_database_draft_validate';
  $form['#validate'][] = 'esf_tc_content_types_tca_validate';
  $form['#submit'][] = 'esf_tc_content_types_tca_submit';
  // Add after build for projects partners field.
  $field_partner_organisations = &$form['field_tca_partner_organisations'][LANGUAGE_NONE];
  $indexes = array_filter(array_keys($field_partner_organisations), 'is_int');

  // Add ready buttons.
  if (!empty($indexes)) {
    $element_wrapper = $field_partner_organisations['add_more']['#ajax']['wrapper'];
    foreach ($indexes as $index) {
      $status = !empty($field_partner_organisations[$index]['field_fc_mas_approval_status'][LANGUAGE_NONE]['#default_value'][0]) ? $field_partner_organisations[$index]['field_fc_mas_approval_status'][LANGUAGE_NONE]['#default_value'][0] : "";
      if (!empty($field_partner_organisations[$index]) &&  $status == 'pending-key-changes') {
        $field_partner_organisations[$index]['ready_button'] = array(
          '#type' => 'submit',
          '#name' => 'ready_button_' . $index,
          '#value' => t('Ready for MA/IBs validation'),
          '#submit' => array('_esf_tnc_content_types_tca_partners_ready_submit'),
          '#validate' => array(),
          '#limit_validation_errors' => array(),
          '#attributes' => array('class' => array('btn-success')),
          '#ajax' => array(
            'callback' => '_esf_tnc_content_types_tca_partners_ready_js',
            'wrapper' => $element_wrapper,
            'effect' => 'fade',
          ),
          '#weight' => '99',
        );
      }
      else {
        // Project autocomplete input become read only.
        $field_partner_organisations[$index]['field_fc_partner_project'][LANGUAGE_NONE]['#attributes']['readonly'] = TRUE;
      }
      // Hide select input.
      $field_partner_organisations[$index]['field_fc_mas_approval_status']['#attributes']['class'][] = 'sr-only';
      $field_partner_organisations[$index]['markup'] = _esf_tnc_content_types_get_partners_status_markup($field_partner_organisations[$index]['field_fc_mas_approval_status'][LANGUAGE_NONE]);
    }
    unset($index);
  }
}

/**
 * TCA custom validation.
 */
function esf_tc_content_types_tca_validate($form, &$form_state) {
  // Check Budget format.
  $budget = $form_state['values']['field_tca_budget'][LANGUAGE_NONE][0]['value'];
  $partners = $form_state['values']['field_tca_partner_organisations'][LANGUAGE_NONE];
  $arr_status = _esf_tc_content_types_get_status();
  $op = drupal_strtolower($form_state['values']['op']);

  if (!empty($arr_status[$op]) && in_array($arr_status[$op], array('published', 'negotiation'))) {
    // Check Partners.
    foreach ($partners as $key => $partner) {
      if (is_numeric($key)) {
        $focused_field_error = 'field_tca_partner_organisations][' . LANGUAGE_NONE . '][' . $key . '][field_fc_partner_project][' . LANGUAGE_NONE;
        // Parter project name is required.
        if (empty($partner['field_fc_partner_project'][LANGUAGE_NONE][0]['target_id'])) {
          form_set_error($focused_field_error, t('!name field is required.', array('!name' => $form['field_tca_partner_organisations'][LANGUAGE_NONE][0]['field_fc_partner_project'][LANGUAGE_NONE]['#title'])));
        }
        // Parter project status 'Ready for MA/IB validation'
        // is required for the negotiation.
        $partner_status = $partner['field_fc_mas_approval_status'][LANGUAGE_NONE][0]['value'];
        if ($arr_status[$op] == 'negotiation' && $partner_status != 'ready') {
          form_set_error($focused_field_error, t('!name is not ready for validation', array('!name' => $form['field_tca_partner_organisations'][LANGUAGE_NONE][0]['field_fc_partner_project'][LANGUAGE_NONE]['#title'])));
        }
      }
    }
  }
  if ($op != 'save as draft') {
    if (!$budget && preg_match('/(^([0-9]{1,3}(\s[0-9]{3})*)|^([0-9]+))(\.[0-9]{0,2})?$/', $budget) == FALSE) {
      form_set_error('field_tca_budget', t('Please enter a valid Budget format.'));
    }
  }
}

/**
 * TCA custom submit.
 */
function esf_tc_content_types_tca_submit($form, &$form_state) {
  // Format the budget value.
  if (!empty($form_state['values']['field_tca_budget'][LANGUAGE_NONE][0]['value'])) {
    $budget = str_replace(' ', '', $form_state['values']['field_tca_budget'][LANGUAGE_NONE][0]['value']);
    if ($budget) {
      $form_state['values']['field_tca_budget'][LANGUAGE_NONE][0]['value'] = number_format($budget, 2, '.', ' ');
    }
  }
}

/**
 * Helper defining specific submit function for the partners status button.
 *
 * @param array $form
 *    The form.
 * @param array $form_state
 *    The form state.
 */
function _esf_tnc_content_types_tca_partners_ready_submit(&$form, &$form_state) {
  $button = $form_state['triggering_element'];
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -1));
}

/**
 * Helper Ajax for change partners status.
 *
 * @param array $form
 *    The form.
 * @param array $form_state
 *    The form state.
 *
 * @return array|mixed|null
 *    Return the form element.
 */
function _esf_tnc_content_types_tca_partners_ready_js(&$form, &$form_state) {
  $button = $form_state['triggering_element'];
  $ready_status = 'ready';
  // Find delta.
  sscanf($button['#name'], 'ready_button_%d', $delta);
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -2));
  if (!empty($element[$delta]['field_fc_partner_project'][LANGUAGE_NONE]['#value'])) {
    // Check if project is valid.
    $entities = drupal_explode_tags($element[$delta]['field_fc_partner_project'][LANGUAGE_NONE]['#value']);
    $value = array();
    foreach ($entities as $entity) {
      if (preg_match("/.+\((\d+)\)/", $entity, $matches)) {
        $nid = $matches[1];
      }
      else {
        form_set_error('field_tca_partner_organisations[' . LANGUAGE_NONE . '][' . $delta . '][field_fc_partner_project', t('Please insert a valid project'));
        $nid = 0;
      }
    }
    if (intval($nid)) {
      $element[$delta]['field_fc_mas_approval_status'][LANGUAGE_NONE]['#value'] = $ready_status;
      $element[$delta]['field_fc_mas_approval_status'][LANGUAGE_NONE]['#default_value'][0] = $ready_status;
      unset($element[$delta]['ready_button']);

      // Replace select input to markup.
      $element[$delta]['markup'] = _esf_tnc_content_types_get_partners_status_markup($element[$delta]['field_fc_mas_approval_status'][LANGUAGE_NONE]);
      // Read only projects input.
      $element[$delta]['field_fc_partner_project'][LANGUAGE_NONE]['#attributes']['readonly'] = TRUE;
      // Hide select.
      $form_state['rebuild'] = TRUE;
    }
  }
  return $element;
}

/**
 * Helper to get the partners status markup element.
 *
 * @param array $select_element
 *    The partners status form select input element.
 *
 * @return array
 *    Return a markup form element.
 */
function _esf_tnc_content_types_get_partners_status_markup($select_element) {
  return array(
    '#prefix' => "<div class='parnters--status-markup'>",
    '#suffix' => '</div>',
    '#type' => 'markup',
    '#markup' => _esf_tc_content_types_field_get_markup_text($select_element),
    '#weight' => 99,
  );
}
