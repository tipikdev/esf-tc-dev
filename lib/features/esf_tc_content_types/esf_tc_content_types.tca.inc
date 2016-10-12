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
}

/**
 * TCA custom validation.
 */
function esf_tc_content_types_tca_validate($form, &$form_state) {
  // Check Budget format.
  $budget = $form_state['values']['field_tca_budget'][LANGUAGE_NONE][0]['value'];
  if (!$budget && preg_match('/(^([0-9]{1,3}(\s[0-9]{3})*)|^([0-9]+))(\.[0-9]{0,2})?$/', $budget) == FALSE) {
    form_set_error('field_tca_budget', t('Please enter a valid Budget format.'));
  }

  $partners = $form_state['values']['field_tca_partner_organisations'][LANGUAGE_NONE];
  if ($form_state['values']['op'] == 'Publish') {
    // Check Partners.
    foreach ($partners as $key => $partner) {
      if (is_numeric($key)) {
        if (empty($partner['field_fc_partner_project'][LANGUAGE_NONE][0]['target_id'])) {
          form_set_error('field_fc_partner_project', t('!name field is required.', array('!name' => $form['field_tca_partner_organisations'][LANGUAGE_NONE][0]['field_fc_partner_project'][LANGUAGE_NONE]['#title'])));
        }
      }
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
