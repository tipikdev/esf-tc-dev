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
    '#markup' => '<h1>' . $title . '</h1>',
  );

  // Add notification on editorial status contents.
  if (array_key_exists($content_type, $_content_types)) {

    $_title = 'Status';
    $form['contenttype_status'] = array(
      '#type' => 'markup',
      '#markup' => '<h2>' . $_title . '</h2>',
    );

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
        '#title' => $state,
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
  // Specific menu.
  switch ($content_type) {
    case 'organisation':
    case 'project':
      $_title = 'Contact';
      $form['contenttype_contact'] = array(
        '#type' => 'markup',
        '#markup' => '<h2>' . $_title . '</h2>',
      );
      // Contact notification.
      $form['notifycontact'] = array(
        '#type' => 'vertical_tabs',
      );

      $keys = array(
        'contact_ecas' => 'ECAS account',
        'contact_simple' => 'Without ECAS account',
      );

      $options['type'] = 'contact';

      foreach ($keys as $key => $value) {
        $key_prefix = $_content_types[$content_type] . '_notification_' . $key;
        $form[$key] = array(
          '#type' => 'fieldset',
          '#title' => $value,
          '#collapsible' => TRUE,
          '#descriptions' => t('Block status'),
          '#group' => 'notifycontact',
        );
        $form[$key][$key_prefix . '_subject'] = array(
          '#type' => 'textfield',
          '#title' => t('Subject'),
          '#required' => 'true',
          '#group' => 'notifyform',
          '#default_value' => _esf_tc_content_types_mail_text($key_prefix . '_subject', $options),
        );
        $form[$key][$key_prefix . '_body'] = array(
          '#type' => 'textarea',
          '#title' => t('Body'),
          '#required' => 'true',
          '#group' => 'notifyform',
          '#default_value' => _esf_tc_content_types_mail_text($key_prefix . '_body', $options),
        );
        $form[$key][$key_prefix . '_token'] = array(
          '#theme' => 'token_tree_link',
          '#token_types' => array('node', 'user', 'site', 'contact'),
          '#global_types' => FALSE,
          '#click_insert' => FALSE,
          '#group' => 'notifyform',
        );
      }
      unset($key);
      break;
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
            $info = node_type_get_type($variables['content_type']);
            $content_type = is_object($info) && isset($info->name) ? drupal_strtolower($info->name) : $variables['content_type'];
            if (is_array($input_type) && count($input_type)) {
              $input_type = end($input_type);
              $action = drupal_strtolower($_states[$variables['action']] ? $_states[$variables['action']] : $variables['action']);
              switch ($input_type) {
                case 'subject':
                  return t('The @ctype has been @action', array(
                    '@ctype' => $content_type,
                    '@action' => $action,
                  ));

                case 'body':
                  $body = t('The @ctype [node:title] has been @action by [user:name]', array(
                    '@ctype' => $content_type,
                    '@action' => $action,
                  ));
                  if ($variables['action'] != 'deleted') {
                    $body .= PHP_EOL . PHP_EOL . '[node:url]';
                  }
                  return $body;
              }
            }
          }
          break;

        case 'contact':
          $keys = explode('_', $key);
          if (is_array($keys) && count($keys)) {
            $input_type = array_pop($keys);
            $type = array_pop($keys);

            switch ($input_type) {
              case 'subject':
                return t('[ESF Transnationality] – Invitation to EU ESF transnationality cooperation platform on [node:content-type] "[node:title]"');

              case 'body':

                $body = 'Dear [contact:name],' . PHP_EOL . PHP_EOL .
                        'On the ESF Transnationality Cooperation platform of the European Commission, [user:field-firstname] [user:field-lastname] invites you with an active contributing role as [contact:role] of [node:title] on [node:url].' . PHP_EOL . PHP_EOL;

                if ($type == 'simple') {
                  $body .= 'Please validate your invitation by clicking on the following link (or please make to copy all the elements of that link and paste it in your Internet browser).' . PHP_EOL .
                    'You will be asked to connect using your ECAS account, the login system to the websites of the European institutions.' . PHP_EOL .
                    'Invitation link:' . PHP_EOL .
                    '[site:url]/my-tnc' . PHP_EOL . PHP_EOL .
                    'Token email:' . PHP_EOL .
                    '[contact:email]' . PHP_EOL . PHP_EOL .
                    'In case you don’t have a user ECAS account yet, please create one first on https://ecas.ec.europa.eu/cas/eim/external/register.cgi, and then, come back to the present email and click on the above invitation link.' . PHP_EOL . PHP_EOL .
                    'If you need any further information, you may find more details on the Partner search tool and the Transnationality cooperation activities of the European Social Fund on the European Commission website at http://ec.europa.eu/esf/main.jsp?catId=56&langId=en.';
                }

                $body .= PHP_EOL . PHP_EOL .
                  'Welcome to the ESF Transnational Platform!' . PHP_EOL .
                  'Brice Gatelet, Partner Search Database Manager' . PHP_EOL .
                  'bga@aeidl.eu' . PHP_EOL .
                  '+32 2 736 1890' . PHP_EOL;
                return $body;

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
  if ($params['type'] == 'editorial_status' || $params['type'] == 'contact') {
    $tokens = array(
      'node' => $params['node'],
      'user' => $user,
    );
    if (isset($params['contact'])) {
      $tokens['contact'] = $params['contact'];
    }
    $message['subject'] = token_replace(_esf_tc_content_types_mail_text($key . '_subject', $params), $tokens);
    $message['body'][] = token_replace(_esf_tc_content_types_mail_text($key . '_body', $params), $tokens);
  }
}
