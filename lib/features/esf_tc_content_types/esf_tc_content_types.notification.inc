<?php
/**
 * @file
 * Code for the esf_tc_content_types feature.
 */

/**
 * Form system form for notifications settings.
 */
function esf_tc_content_state_notification_form($form, &$form_state, $content_type = 'organisation') {

  $title = drupal_ucfirst($content_type);
  drupal_set_title($title);

  $more = $content_type == 'tca';
  $_states = _esf_tc_content_type_get_notification_states($more);

  $_content_types = array(
    'organisation' => 'esf_tnc_organisation',
    'project' => 'esf_tnc_project',
    'tca' => 'esf_tnc_tca',
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

    // Additional status.
    if ($more) {
      $options['more'] = TRUE;
    }

    $form['notifyform'] = array(
      '#type' => 'vertical_tabs',
    );

    $token_types = array('node', 'user');
    // Generate inputs of the form.
    _esf_tc_content_get_email_inputs($_content_types[$content_type], $_states, $options, 'notifyform', $token_types, $form);
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
      );

      if ($content_type == 'organisation') {
        $keys['contact_simple'] = 'Without ECAS account';
      }

      $options['type'] = 'contact';

      // Generate inputs of the form.
      $token_types = array('node', 'user', 'site', 'contact');
      _esf_tc_content_get_email_inputs($_content_types[$content_type], $keys, $options, 'notifycontact', $token_types, $form);
      break;

    case 'tca':
      // Partners projects status.
      $_title = 'Partners projects';
      $form['tca_partners'] = array(
        '#type' => 'markup',
        '#markup' => '<h2>' . $_title . '</h2>',
      );
      $form['partnersform'] = array(
        '#type' => 'vertical_tabs',
      );

      $keys = _esf_tc_content_types_get_partners_projects_status();

      // Special notification for Managing Authorities.
      $spectial = array('mapjt-validation' => 'MA project validation');
      $keys = $spectial + $keys;

      $options['type'] = 'partners';

      $token_types = array('node', 'user', 'site');
      _esf_tc_content_get_email_inputs($_content_types[$content_type], $keys, $options, 'partnersform', $token_types, $form);

      // Type TCA status.
      $_title = 'Color status';
      $form['tca_status'] = array(
        '#type' => 'markup',
        '#markup' => '<h2>' . $_title . '</h2>',
      );
      $form['colorform'] = array(
        '#type' => 'vertical_tabs',
      );

      $keys = _esf_tc_content_types_get_tca_status();

      $options['type'] = 'color';

      // Generate inputs of the form.
      $token_types = array('node', 'user', 'site');
      _esf_tc_content_get_email_inputs($_content_types[$content_type], $keys, $options, 'colorform', $token_types, $form);
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
  $more = !empty($variables['more']);
  $_states = _esf_tc_content_type_get_notification_states($more);
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

        case 'color':
          $keys = explode('_', $key);
          if (is_array($keys) && count($keys)) {
            $input_type = array_pop($keys);
            $action = array_pop($keys);

            switch ($input_type) {
              case 'subject':
                return t('The TCA [node:title] has turned @action', array(
                  '@action' => $action,
                ));

              case 'body':
                $body = t('The TCA [node:title] has turned @action by [user:name]', array(
                  '@action' => $action,
                ));
                $body .= PHP_EOL . PHP_EOL . '[node:url]';

                return $body;
            }
          }
          break;

        case 'partners':
          $keys = explode('_', $key);
          if (is_array($keys) && count($keys)) {
            $input_type = array_pop($keys);
            $action = array_pop($keys);
            $_states = _esf_tc_content_types_get_partners_projects_status();

            // Exception for MA partners validation.
            if ($action == 'mapjt-validation') {
              switch ($input_type) {
                case 'subject':
                  return t('The partner project for TCA [node:title] needs validation');

                case 'body':
                  return t('Please approve or reject the partners projects on [node:url]');
              }
            } else {
              $action = drupal_strtolower($_states[$action] ? $_states[$action] : $action);

              switch ($input_type) {
                case 'subject':
                  return t('The partner project for TCA [node:title] is @action', array(
                    '@action' => $action,
                  ));

                case 'body':
                  $body = t('The partner project for TCA [node:title] is @action', array(
                    '@action' => $action,
                  ));
                  $body .= PHP_EOL . PHP_EOL . '[node:url]';

                  return $body;
              }
              break;
            }
          }
      }
    }
  }
  return FALSE;
}

/**
 * Helper to get notification states.
 *
 * @param boolean $more
 *    Binary choice for additional status.
 *
 * @return array
 *    Return the list of editorial status.
 */
function _esf_tc_content_type_get_notification_states($more=FALSE) {
  $return = array(
    'published' => 'Published',
    'blocked' => 'Blocked',
    'archived' => 'Archived',
    'needs-deletion' => 'Asked for deletion',
    'deleted' => 'Deleted',
  );
  if ($more) {
    $additionals = array(
      'negotiation' => 'In negotiation',
    );
    $return = $additionals + $return;
  }

  return $return;
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

    if ($node->type == 'esf_tnc_tca') {
      // Special notification for Managing Authorities partners validation.
      if ($status == 'negotiation' && $status != $old_status) {
        // Notify all partners projects Managing Authorities.
        $options = array(
          'type' => 'partners',
          'content_type' => $node->type,
          'action' => $status,
          'node' => $node,
        );
        $emails = array();

        $wrapper = entity_metadata_wrapper('node', $node);

        foreach ($wrapper->field_tca_partner_organisations->getIterator() as $partner) {
          $project = $partner->field_fc_partner_project->value();
          if (!empty($project)) {
            $mas = _esf_tc_content_types_get_responsible_authorities($project->type, $project);
            foreach ($mas as $ma) {
              $ma = node_load($ma);
              $contacts = _esf_tc_content_types_get_associated_email($ma, FALSE);
              if (count($contacts)) {
                $emails = array_merge($emails, $contacts);
              }
            }
            unset($ma);

            $key_prefix = $node->type . '_notification_mapjt-validation';
            $emails = array_unique($emails);
            foreach ($emails as $email) {
              if (valid_email_address($email)) {
                drupal_mail('esf_tc_content_types', $key_prefix, $email, language_default(), $options);
              }
            }
            unset($email, $emails);
          }
        }
        unset($partner);
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

      case 'esf_tnc_tca':

      case 'esf_tnc_project':
        $emails = _esf_tc_content_types_get_associated_email($node);
        if (!$force_notify) {
          $emails = array_diff($emails, _esf_tc_content_types_get_associated_email($node->original));
          if (is_array($emails) && count($emails)) {
            foreach ($emails as $email) {
              if (valid_email_address($email)) {
                $usr = user_load_by_mail($email);
                if (!empty($usr->uid) && $email != $user->mail) {
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

    // TCA - Color status.
    if ($node->type == 'esf_tnc_tca') {
      // Options for email.
      $options = array(
        'type' => 'color',
        'content_type' => $node->type,
        'node' => $node,
      );

      // Status.
      $fieldname = 'field_tca_status';
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
      // Status.
      $fieldname = _esf_tc_content_types_get_editorial_status_field_name();
      $field = field_get_items('node', $node, $fieldname);
      if (is_array($field) && reset($field)['value']) {
        $ed_status = reset($field)['value'];
      }

      $key_prefix = $node->type . '_notification_' . $status;

      if (!$node->is_new && !empty($status) && $ed_status != 'draft' && $status != $old_status) {
        $emails = _esf_tc_content_types_get_associated_email($node, TRUE);
        foreach ($emails as $email) {
          if (valid_email_address($email)) {
            drupal_mail('esf_tc_content_types', $key_prefix, $email, language_default(), $options);
          }
        }
        unset($email, $emails);
      }
    }
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
  // Projects partners.
  if ($field_collection_item->field_name == 'field_tca_partner_organisations') {
    $wrapper_fc = entity_metadata_wrapper('field_collection_item', $field_collection_item);
    $status = '';
    if (!empty($wrapper_fc->field_fc_mas_approval_status->value())) {
      $status = $wrapper_fc->field_fc_mas_approval_status->value();
    }
    if (empty($field_collection_item->is_new) || $status != 'pending-key-changes') {
      $tca_id = $field_collection_item->hostEntityId();
      $tca = node_load($tca_id);
      $key_prefix = $tca->type . '_notification_' . $status;
      $options = array(
        'type' => 'partners',
        'content_type' => $tca->type,
        'node' => $tca,
      );

      if (!empty($tca)) {
        $emails = _esf_tc_content_types_get_associated_email($tca, TRUE);
        foreach ($emails as $email) {
          if (valid_email_address($email)) {
            drupal_mail('esf_tc_content_types', $key_prefix, $email, language_default(), $options);
          }
        }
        unset($email);
      }
    }
  }
}

/**
 * Implements hook_mail().
 */
function esf_tc_content_types_mail($key, &$message, $params) {
  global $user;

  $allowed_types = array(
    'editorial_status',
    'contact',
    'color',
    'partners',
  );

  if (in_array($params['type'], $allowed_types)) {
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

/**
 * Helper to generate form inputs for notifications administration.
 *
 * @param string $content_type
 *    The machine name of the content type.
 * @param array $keys
 *    The array of keys used to fill the fieldset.
 * @param array $options
 *    The options passed to the message manager function.
 * @param string $fieldset
 *    The name of the generated fieldset.
 * @param array $token_types
 *    The types of token allowed.
 * @param array $form
 *    The types of token allowed.
 * @param string $group
 *    The name of the group to associate to the inputs.
 *
 * @return array
 *    Return the form with inputs.
 */
function _esf_tc_content_get_email_inputs($content_type, $keys, $options, $fieldset, $token_types = NULL, &$form = array(), $group = 'notifyform') {
  if (is_array($keys) && count($keys)) {
    foreach ($keys as $key => $value) {
      $key_prefix = $content_type . '_notification_' . $key;
      $options['action'] = $key;
      $form[$key] = array(
        '#type' => 'fieldset',
        '#title' => $value,
        '#collapsible' => TRUE,
        '#descriptions' => t('Block status'),
        '#group' => $fieldset,
      );
      $form[$key][$key_prefix . '_subject'] = array(
        '#type' => 'textfield',
        '#title' => t('Subject'),
        '#required' => 'true',
        '#group' => $group,
        '#default_value' => _esf_tc_content_types_mail_text($key_prefix . '_subject', $options),
      );
      $form[$key][$key_prefix . '_body'] = array(
        '#type' => 'textarea',
        '#title' => t('Body'),
        '#required' => 'true',
        '#group' => $group,
        '#default_value' => _esf_tc_content_types_mail_text($key_prefix . '_body', $options),
      );
      // Display the help for token if exists.
      if (is_array($token_types) && count($token_types)) {
        $form[$key][$key_prefix . '_token'] = array(
          '#theme' => 'token_tree_link',
          '#token_types' => $token_types,
          '#global_types' => FALSE,
          '#click_insert' => FALSE,
          '#group' => $group,
        );
      }
    }
    unset($key);
  }

  return $form;
}
