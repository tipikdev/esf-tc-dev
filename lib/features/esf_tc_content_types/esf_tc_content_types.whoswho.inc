<?php

/**
 * @file
 * Code for the who's who content type.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function esf_tc_content_types_form_esf_tc_whoswho_node_form_alter(&$form, &$form_state, $form_id) {
  $nid = _esf_tc_content_types_get_whoswho_nid();

  if ($nid && $nid != $form['nid']['#value']) {
    // Alert the user.
    $message = t('A content of this type already exists. !link', array(
      '!link' => l(t('Please check this page'), 'node/' . $nid),
    ));

    drupal_set_message($message, 'error', TRUE);
    // Block the submit button.
    $form['actions']['submit']['#disabled'] = TRUE;
  }
}

/**
 * Helper to get the whoswho node ID.
 *
 * @return int|bool
 *   Return the nid of the who's who content
 *    or FALSE if not found.
 */
function _esf_tc_content_types_get_whoswho_nid() {
  $return = FALSE;

  try {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'esf_tc_whoswho')
      ->range(0, 1);

    $result = $query->execute();

    if (!empty($result) && is_array($result['node'])) {
      $return = key($result['node']);
    }
  }
  catch (\Exception $e) {
    watchdog('Who_is_who', 'An error occurs when tryning to retrieve count of who s who count', WATCHDOG_ERROR);
  }

  return $return;
}

/**
 * Helper to redirect to the who's who page.
 */
function _esf_tc_content_types_whoswho_page() {
  $nid = _esf_tc_content_types_get_whoswho_nid();

  if (!empty($nid)) {
    drupal_goto('node/' . $nid);
  }
  else {
    drupal_not_found();
  }
}
