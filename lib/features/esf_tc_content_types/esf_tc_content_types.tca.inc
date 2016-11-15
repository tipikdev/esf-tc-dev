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
      $element_wrapper = "fc_" . $index;
      if (!empty($field_partner_organisations[$index]) &&  $status == 'pending-key-changes') {
        $field_partner_organisations[$index]['#prefix'] = "<div id='" . $element_wrapper . "' class='subtree'>";
        $field_partner_organisations[$index]['#suffix'] = "</div>";
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
          '#weight' => '999',
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
  $ed_status = '';
  if (!empty($form['#node']->field_esf_editorial_status[LANGUAGE_NONE][0]['value'])) {
    $ed_status = $form['#node']->field_esf_editorial_status[LANGUAGE_NONE][0]['value'];
  }

  if (!empty($arr_status[$op]) && in_array($arr_status[$op], array('published', 'negotiation')) || $op == 'save' && $ed_status == 'published') {
    // Check Partners.
    foreach ($partners as $key => $partner) {
      if (is_numeric($key)) {
        $focused_field_error = 'field_tca_partner_organisations][' . LANGUAGE_NONE . '][' . $key . '][field_fc_partner_project][' . LANGUAGE_NONE;
        // Parter project name is required.
        if (empty($partner['field_fc_partner_project'][LANGUAGE_NONE][0]['target_id'])) {
          form_set_error($focused_field_error, t('!name field is required.', array('!name' => $form['field_tca_partner_organisations'][LANGUAGE_NONE][0]['field_fc_partner_project'][LANGUAGE_NONE]['#title'])));
        }
        // Is required for the negotiation.
        $partner_status = $partner['field_fc_mas_approval_status'][LANGUAGE_NONE][0]['value'];
        if (!empty($arr_status[$op]) && $arr_status[$op] == 'negotiation' && $partner_status != 'ready') {
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
  $has_error = FALSE;
  // Find delta.
  sscanf($button['#name'], 'ready_button_%d', $delta);
  $element = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -1));
  $parent = drupal_array_get_nested_value($form, array_slice($button['#array_parents'], 0, -2));

  unset($element['_weight']);
  if (!empty($element['field_fc_partner_project'][LANGUAGE_NONE]['#value'])) {
    // Check if project is valid.
    $entities = drupal_explode_tags($element['field_fc_partner_project'][LANGUAGE_NONE]['#value']);
    foreach ($entities as $entity) {
      // Check if nid is defined.
      if (preg_match('/.+\((\d+)\)/', $entity, $matches)) {
        $nid = $matches[1];
        // Check if project is well published and have a Managing Authority.
        $pjt_wrapper = entity_metadata_wrapper('node', $nid);
        $pjt_status = $pjt_wrapper->field_esf_editorial_status->value();
        $pjt_mas = _esf_tc_content_types_get_responsible_authorities($pjt_wrapper->getBundle(), $pjt_wrapper->value());

        if ($pjt_status != 'published' || empty($pjt_mas)) {
          $has_error = TRUE;
          $attributes = array(
            'attributes' => array(
              'target' => '_blank',
            ),
          );
          $message = t('Some data or action are missing for the corresponding !project_url. Before sending it for validation within the present TCA, you may need to effectively "Publish" your project and/or to add missing information in the description of your project, such as the chosen call for proposals. Please save any current change in your TCA in draft mode and then go to your !project_url or ask the corresponding project responsible to update and publish it.', array(
            '!project_url' => l(t('project'), 'node/' . $nid, $attributes),
          ));
          form_set_error('field_tca_partner_organisations[' . LANGUAGE_NONE . '][' . $delta . '][field_fc_partner_project', $message);
        }
        else {
          // Check if partners project is duplicated.
          $projects = _esf_tc_content_types_get_partners_project_form_tca($parent);
          if (in_array($nid, $projects)) {
            $has_error = TRUE;
            $message = t('This project is already selected as a partnering project. Please remove it.');
            form_set_error('field_tca_partner_organisations[' . LANGUAGE_NONE . '][' . $delta . '][field_fc_partner_project', $message);
          }
        }
      }
      else {
        form_set_error('field_tca_partner_organisations[' . LANGUAGE_NONE . '][' . $delta . '][field_fc_partner_project', t('Please insert a valid project'));
        $nid = 0;
        $has_error = TRUE;
      }
    }
    if (intval($nid) && !$has_error) {
      $element['field_fc_mas_approval_status'][LANGUAGE_NONE]['#value'] = $ready_status;
      $element['field_fc_mas_approval_status'][LANGUAGE_NONE]['#default_value'][0] = $ready_status;
      unset($element['ready_button']);

      // Replace select input to markup.
      $element['markup'] = _esf_tnc_content_types_get_partners_status_markup($element['field_fc_mas_approval_status'][LANGUAGE_NONE]);
      // Read only projects input.
      $element['field_fc_partner_project'][LANGUAGE_NONE]['#attributes']['readonly'] = TRUE;
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

/**
 * Helper to handle the project partners validation of a TCA.
 *
 * @param object $tca
 *    The node object of the TCA.
 * @param object $fc
 *    The field collection object of the project to validate.
 * @param string $action
 *    The action to proceed on the partner's project
 *    allowed_values (accepted/rejected).
 */
function _esf_tc_content_types_tca_partners_validation($tca, $fc, $action) {
  $action = check_plain(drupal_strtolower($action));
  $tca_wrapper = entity_metadata_wrapper('node', $tca);
  $fc_wrapper = entity_metadata_wrapper('field_collection_item', $fc);

  $status = $fc_wrapper->field_fc_mas_approval_status->value();
  if ($status != 'pending-key-changes') {
    if ($action == 'accepted') {
      $fc_wrapper->field_fc_mas_approval_status = $action;
      $fc_wrapper->save();
      drupal_set_message(t('the partners project has been accepted'));
      // Check if all project are validated.
      $tca_ready = TRUE;
      foreach ($tca_wrapper->field_tca_partner_organisations->getIterator() as $partner) {
        if ($partner->field_fc_mas_approval_status->value() != 'accepted') {
          $tca_ready = FALSE;
        }
      }
      unset($partner);
      // Change TCA status if ready.
      if ($tca_ready) {
        $tca_wrapper->field_esf_editorial_status = 'published';
        $tca_wrapper->field_tca_status = 'green';
        $tca_wrapper->status = 1;
        $tca_wrapper->save();
        drupal_set_message(t('the TCA has turned green'));
      }
    }
    elseif ($action == 'rejected') {
      $fc_wrapper->field_fc_mas_approval_status = $action;
      $fc_wrapper->save();
      $tca_wrapper->field_tca_status = 'red';
      $tca_wrapper->save();
      drupal_set_message(t('the partners project has been rejected'), 'error');
      drupal_set_message(t('the TCA has turned red'), 'error');
    }
  }
  drupal_goto('node/' . $tca->nid);
}

/**
 * Custom access for TCA partners project validation.
 *
 * @param object $field_collection
 *    The Field Collection item object of the partners project.
 *
 * @return bool
 *    Return true if the access is granted.
 */
function _esf_tc_content_types_tca_partners_project_access($field_collection) {
  global $user;

  $fc_wrapper = entity_metadata_wrapper('field_collection_item', $field_collection);
  $project = $fc_wrapper->field_fc_partner_project->value();

  $admin_role = array('administrator', 'webmaster');
  $access = FALSE;

  foreach ($admin_role as $role) {
    if (in_array($role, $user->roles)) {
      $access = TRUE;
    }
  }
  unset($role);

  if (!$access) {
    // Check if use is a MA for the node.
    $mas = _esf_tc_content_types_get_responsible_authorities($project->type, $project);

    foreach ($mas as $ma) {
      if (!$access) {
        $access = node_access('update', node_load($ma));
      }
    }
    unset($ma);
  }

  return $access;
}

/**
 * Helper to find a related TCA.
 *
 * @param object $node
 *    The linked node object.
 *
 * @return mixed
 *    Return a list of the related TCA node object
 *    return NULL if not found or not appropriated content type.
 */
function _esf_tc_content_types_find_related_tca($node) {
  $return = NULL;
  switch ($node->type) {
    case 'esf_tnc_organisation':
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'esf_tnc_tca')
        ->fieldCondition('field_tca_main_contact_point', 'target_id', $node->nid)
        ->execute();
      if (!empty($result['node'])) {
        $return = node_load_multiple(array_keys($result['node']));
      }
      break;

    case 'esf_tnc_project':
      $query = new EntityFieldQuery();
      $result = $query->entityCondition('entity_type', 'field_collection_item')
        ->entityCondition('bundle', 'field_tca_partner_organisations')
        ->fieldCondition('field_fc_partner_project', 'target_id', $node->nid)
        ->execute();

      if (!empty($result['field_collection_item'])) {
        foreach (field_collection_item_load_multiple(array_keys($result['field_collection_item'])) as $fc) {
          if ($tca = $fc->hostEntity()) {
            $return[$tca->nid] = $tca;
          }
        }
        unset($fc);
      }
      break;
  }
  return $return;
}

/**
 * Helper to get allowed values of TCA status field.
 *
 * @return array
 *    Return a list of status.
 */
function _esf_tc_content_types_get_tca_status() {
  return _esf_tc_content_types_get_allowed_values_list('field_tca_status');
}

/**
 * Helper to get allowed values of partners project field.
 *
 * @return array
 *    Return a list of status.
 */
function _esf_tc_content_types_get_partners_projects_status() {
  return _esf_tc_content_types_get_allowed_values_list('field_fc_mas_approval_status');
}

/**
 * Helper to get allowed values of a list field.
 *
 * @return array
 *    Return a list of status.
 */
function _esf_tc_content_types_get_allowed_values_list($fieldname) {
  $return = array();
  $info = field_info_field($fieldname);
  if (!empty($info) && !empty($info['settings']['allowed_values'])) {
    $return = $info['settings']['allowed_values'];
  }

  return $return;
}

/**
 * Helper to get all node id for partners' projects of a TCA.
 *
 * @param array $element
 *    The form element of partners projects.
 *
 * @return array
 *    Return an array of the partners' projects node ids.
 */
function _esf_tc_content_types_get_partners_project_form_tca($element) {
  $return = array();
  $indexes = array_filter(array_keys($element), 'is_int');
  if (!empty($indexes)) {
    foreach ($indexes as $index) {
      $item = $element[$index];
      if (!empty($item['field_fc_partner_project'][LANGUAGE_NONE]['#value'])) {
        preg_match('/.+\((\d+)\)/', $item['field_fc_partner_project'][LANGUAGE_NONE]['#value'], $matches);
        if ($nid = intval($matches[1])) {
          $return[] = $nid;
        }
      }
    }
    unset($item);
  }
  return $return;
}
