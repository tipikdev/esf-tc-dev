<?php
/**
 * @file
 * Code for the esf_tc_content_types feature.
 */

/**
 * Form system form for notifications settings.
 */
function esf_tc_content_state_notification_form($form, &$form_state, $content_type = 'organisation') {

  $title = ucfirst($content_type);
  drupal_set_title($title);

  $_states = _esf_tc_content_type_get_notification_states();

  $_content_types = array(
    'organisation' => 'esf_tnc_organisation',
    'project' => 'esf_tnc_project',
  );

  $form['contenttype'] = array(
    '#type' => 'markup',
    '#markup' => '<h1>' . t($title) . '</h1>',
  );

  // Add notification on editorial status contents.
  if (array_key_exists($content_type, $_content_types)) {

    $options = array(
      'type' => 'editorial_status',
      'content_type' => $content_type,
    );

    $form['notifyform'] = array(
      '#type' => 'vertical_tabs',
    );

    foreach ($_states as $key => $state) {
      $key_prefix = $_content_types[$content_type] . '_notification_' . $key;
      $options['action'] = $key;

      $form[$state . 'state'] = array(
        '#type' => 'fieldset',
        '#title' => t($state),
        '#collapsible' => TRUE,
        '#descriptions' => t('Block status'),
        '#group' => 'notifyform',
      );
      $form[$state . 'state'][$key_prefix . '_subject'] = array(
        '#type' => 'textfield',
        '#title' => t('Subject'),
        '#required' => 'true',
        '#group' => 'notifyform',
        '#default_value' => _esf_tc_content_types_mail_text($key_prefix . '_subject', $options),
      );
      $form[$state . 'state'][$key_prefix . '_body'] = array(
        '#type' => 'textarea',
        '#title' => t('Body'),
        '#required' => 'true',
        '#group' => 'notifyform',
        '#default_value' => _esf_tc_content_types_mail_text($key_prefix . '_body', $options),
      );
      $form[$state . 'state'][$key_prefix . '_token'] = array(
        '#theme' => 'token_tree_link',
        '#token_types' => array('node', 'user'),
        '#global_types' => FALSE,
        '#click_insert' => FALSE,
        '#group' => 'notifyform',
      );
    }
    unset($state);
  }
  return system_settings_form($form);
}

/**
 * Helper - Define default notification text.
 */
function _esf_tc_content_types_mail_text($key, $variables = array(), $language = LANGUAGE_NONE) {

  $_states = _esf_tc_content_type_get_notification_states();
  // Check if message is customized.
  if ($predef_setting = variable_get($key, FALSE)) {
    return $predef_setting;
  }
  else {
    // Generate message with options arguments.
    if (isset($variables['type'])) {
      switch ($variables['type']) {
        case 'editorial_status':
          if (isset($variables['content_type']) && isset($variables['action'])) {
            $input_type = explode('_', $key);
            if (is_array($input_type) && count($input_type)) {
              $input_type = end($input_type);
              $action = strtolower($_states[$variables['action']] ? $_states[$variables['action']] : $variables['action']);
              switch ($input_type) {
                case 'subject':

                  return t('The @ctype has been @action', array(
                    '@ctype' => $variables['content_type'],
                    '@action' => $action,
                  ));

                break;

                case 'body':

                  $body = t('The @ctype [node:title] has been @action by [user:name]', array(
                    '@ctype' => $variables['content_type'],
                    '@action' => $action,
                  ));
                  if ($variables['action'] != 'deleted') {
                    $body .= PHP_EOL . PHP_EOL . '[node:url]';
                  }
                  return t($body);

                break;

              }
            }
          }
          break;
      }
    }
  }
  return FALSE;
}

/**
 * Helper to get notification states.
 */
function _esf_tc_content_type_get_notification_states() {
  return array(
    'published' => 'Published',
    'blocked' => 'Blocked',
    'archived' => 'Archived',
    'needs-deletion' => 'Asked for deletion',
    'deleted' => 'Deleted',
  );
}

/**
 * Implements hook_mail().
 */
function esf_tc_content_types_mail($key, &$message, $params) {
  global $user;
  if ($params['type'] == 'editorial_status') {
    $tokens = array(
      'node' => $params['node'],
      'user' => $user,
    );
    $message['subject'] = token_replace(_esf_tc_content_types_mail_text($key . '_subject'), $tokens);
    $message['body'][] = token_replace(_esf_tc_content_types_mail_text($key . '_body'), $tokens);
  }
}
