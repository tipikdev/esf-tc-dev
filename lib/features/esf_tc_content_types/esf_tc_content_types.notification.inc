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
 *
 * @param string $key
 *    The key for identifying the type of input and notification.
 * @param array $variables
 *    Additionals variables to build the notification.
 * @param string $language
 *    The language to use for the notification.
 *
 * @return bool|null|string
 *    Return content used in email for notifications.
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
 *
 * @return array
 *    Return the list of editorial status.
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
 * Helper to notify users when node is saved.
 *
 * @param object $node
 *    The node used to notify.
 */
function _esf_tc_content_types_node_notify($node) {
  global $user;

  $content_types = _esf_tc_content_types_get_project_database_types();
  // Projects databases notifications.
  if (in_array($node->type, $content_types)) {
    $fieldname = _esf_tc_content_types_get_editorial_status_field_name();

    // Status.
    $field = field_get_items('node', $node, $fieldname);
    if (is_array($field) && reset($field)['value']) {
      $status = reset($field)['value'];
    }
    // Old status.
    $old_status = "";
    if (isset($node->original)) {
      $field = field_get_items('node', $node->original, $fieldname);
      if (is_array($field) && reset($field)['value']) {
        $old_status = reset($field)['value'];
      }
    }

    if (isset($status) && $status && $status != 'draft') {
      // Status notifications.
      if ($status != $old_status) {
        // Notify related users.
        $emails = _esf_tc_content_types_get_associated_email($node, TRUE);
        // Notify webmasters on special status.
        if (in_array($status, array('blocked', 'needs-deletion'))) {
          $emails = array_merge($emails, _esf_tc_content_types_get_webmasters_email());
        }
        if (count($emails)) {
          // Get approprieted message.
          $options = array(
            'type' => 'editorial_status',
            'content_type' => $node->type,
            'action' => $status,
            'node' => $node,
          );
          $key_prefix = $node->type . '_notification_' . $status;
          foreach ($emails as $email) {
            if (valid_email_address($email)) {
              drupal_mail('esf_tc_content_types', $key_prefix, $email, language_default(), $options);
            }
          }
          unset($email, $emails);
        }
      }
    }

    // Notify contact to the content if new or changed.
    $force_notify = $node->is_new;
    $default_role = 'member';
    $contacts = array(
      'simple' => array(),
      'ecas' => array(),
    );
    switch ($node->type) {
      case 'esf_tnc_organisation':
        // Legal contact.
        // Role.
        $role = field_get_items('node', $node, 'field_org_contact_legal_role');
        $role = is_array($role) && isset(reset($role)['value']) ? reset($role)['value'] : $default_role;

        if (isset($node->original) && $node->field_org_contact_account !== $node->original->field_org_contact_account) {
          $force_notify = TRUE;
        }

        $has_account = field_get_items('node', $node, 'field_org_contact_account');

        if (is_array($has_account) && isset(reset($has_account)['value'])) {
          $has_account = reset($has_account)['value'];
        }
        if ($has_account == 'no') {
          if ($force_notify || $node->field_org_contact_legal_email[LANGUAGE_NONE][0]['value'] !== $node->original->field_org_contact_legal_email[LANGUAGE_NONE][0]['value']) {
            // Email.
            $field_value = field_get_items('node', $node, 'field_org_contact_legal_email');
            if (is_array($field_value) && isset(reset($field_value)['value'])) {
              $email = reset($field_value)['value'];
            }
            // Name.
            $field_value = field_get_items('node', $node, 'field_org_contact_legal_name');
            if (is_array($field_value) && isset(reset($field_value)['value'])) {
              $name = reset($field_value)['value'];
            }
            // Add contact to simple email list.
            if ($user->mail != $email) {
              $contacts['simple'][] = array(
                'name' => $name,
                'role' => $role,
                'email' => $email,
              );
            }
          }
        }
        elseif ($has_account == 'yes') {
          if ($node->field_org_contact !== $node->original->field_org_contact || $force_notify) {
            $uids = _esf_tc_content_types_get_references_ids('field_org_contact', $node);
            if (is_array($uids)) {
              foreach ($uids as $uid) {
                $usr = user_load($uid);
                if ($usr->mail) {
                  // Add contact to ecas list.
                  if ($usr->mail != $user->mail) {
                    $contacts['ecas'][] = array(
                      'name' => format_username($usr),
                      'role' => $role,
                      'email' => $usr->mail,
                    );
                  }
                }
              }
              unset($uid, $usr);
            }
          }
        }
        break;

      case 'esf_tnc_project':
        $emails = _esf_tc_content_types_get_associated_email($node);
        if (!$force_notify) {
          $emails = array_diff($emails, _esf_tc_content_types_get_associated_email($node->original));
          if (is_array($emails) && count($emails)) {
            foreach ($emails as $email) {
              if (valid_email_address($email)) {
                $usr = user_load_by_mail($email);
                if ($usr->uid && $email != $user->mail) {
                  $contacts['ecas'][] = array(
                    'name' => format_username($usr),
                    'role' => 'a ' . $default_role,
                    'email' => $email,
                  );
                }
              }
            }
            unset($email);
          }
        }
        break;
    }
    // Get approprieted message.
    $options = array(
      'type' => 'contact',
      'content_type' => $node->type,
      'node' => $node,
    );

    // Send notifications.
    $keys = array_keys($contacts);
    foreach ($keys as $key) {
      $key_prefix = $node->type . '_notification_contact_' . $key;
      foreach ($contacts[$key] as $contact) {
        $email = $contact['email'];
        if (valid_email_address($email)) {
          $options['contact'] = $contact;
          drupal_mail('esf_tc_content_types', $key_prefix, $email, language_default(), $options);
        }
      }
      unset($contact);
    }
    unset($key);

  }

}

/**
 * Helper to notify users when contact field collection is saved.
 *
 * @param object $field_collection_item
 *    The field collection used to notify.
 */
function _esf_tc_content_types_field_collection_notify($field_collection_item) {
  // Contact of organisation.
  if ($field_collection_item->field_name == 'field_org_additional_contacts') {
    $force_notify = $field_collection_item->is_new;
    $default_role = 'member';
    $contacts = array(
      'simple' => array(),
      'ecas' => array(),
    );
    $node = $field_collection_item->hostEntity();
    $role = $field_collection_item;
    $role = is_array($role) && isset(reset($role)['value']) ? reset($role)['value'] : $default_role;

    if (isset($field_collection_item->original) && $field_collection_item->field_fc_contact_account !== $field_collection_item->original->field_fc_contact_account) {
      $force_notify = TRUE;
    }

    $has_account = field_get_items('field_collection_item', $field_collection_item, 'field_fc_contact_account');

    if (is_array($has_account) && isset(reset($has_account)['value'])) {
      $has_account = reset($has_account)['value'];
    }
    if ($has_account == 'no') {
      if ($force_notify || $field_collection_item->field_fc_org_email[LANGUAGE_NONE][0]['value'] !== $field_collection_item->original->field_fc_org_email[LANGUAGE_NONE][0]['value']) {
        // Email.
        $field_value = field_get_items('field_collection_item', $field_collection_item, 'field_fc_org_email');
        if (is_array($field_value) && isset(reset($field_value)['value'])) {
          $email = reset($field_value)['value'];
        }
        // Name.
        $field_value = field_get_items('field_collection_item', $field_collection_item, 'field_fc_org_name');
        if (is_array($field_value) && isset(reset($field_value)['value'])) {
          $name = reset($field_value)['value'];
        }
        // Add contact to simple email list.
        $contacts['simple'][] = array(
          'name' => $name,
          'role' => $role,
          'email' => $email,
        );
      }
    }
    elseif ($has_account == 'yes') {
      if ($field_collection_item->field_fc_org_contact !== $field_collection_item->original->field_fc_org_contact || $force_notify) {
        $uids = _esf_tc_content_types_get_references_ids('field_fc_org_contact', $field_collection_item, 'field_collection_item');
        if (is_array($uids)) {
          foreach ($uids as $uid) {
            $user = user_load($uid);
            if ($user->mail) {
              // Add contact to ecas list.
              $contacts['ecas'][] = array(
                'name' => format_username($user),
                'role' => $role,
                'email' => $user->mail,
              );
            }
          }
          unset($uid, $user);
        }
      }
    }
    // Get approprieted message.
    $options = array(
      'type' => 'contact',
      'content_type' => $node->type,
      'node' => $node,
    );
    // Send notifications.
    $keys = array_keys($contacts);
    foreach ($keys as $key) {
      $key_prefix = $node->type . '_notification_contact_' . $key;
      foreach ($contacts[$key] as $contact) {
        $email = $contact['email'];
        if (valid_email_address($email)) {
          $options['contact'] = $contact;
          drupal_mail('esf_tc_content_types', $key_prefix, $email, language_default(), $options);
        }
      }
      unset($contact);
    }
    unset($key);
  }
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
