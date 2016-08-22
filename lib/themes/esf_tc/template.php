<?php
/**
 * @file
 * Default theme functions.
 */

/**
 * Implements template_preprocess_page().
 */
function esf_tc_preprocess_page(&$variables) {
  // Change sidebar left grid size.
  $regions = array(
    'sidebar_left' => (isset($variables['page']['sidebar_left']) ? render($variables['page']['sidebar_left']) : ''),
    'sidebar_right' => (isset($variables['page']['sidebar_right']) ? render($variables['page']['sidebar_right']) : ''),
  );

  $variables['cols']['sidebar_left']['md'] = (!empty($regions['sidebar_left']) ? 3 : 0);
  $variables['cols']['content_main']['md'] = ($variables['cols']['sidebar_right']['md'] == 4 ? 8 : 12 - $variables['cols']['sidebar_left']['md']);

  // Add favorites flag inside specific published content.
  if (isset($variables['node'])) {
    $node = $variables['node'];
    if ($node->status && ($node->type == 'esf_tnc_organisation' || $node->type == 'esf_tnc_call_for_project' || $node->type == 'esf_tnc_project' || $node->type == 'esf_tnc_call_for_project')) {
      $variables['flag_favorites'] = flag_create_link('esf_tc_favorites', $node->nid);
    }
  }
}

/**
 * Implements hook_menu_alter().
 */
function esf_tc_menu_alter(&$items) {
  // Change homepage (node) page callback.
  $items['node']['page callback'] = '_esf_tc_homepage_callback';
}

/**
 * Helper to remove Home page system default_message + set title.
 */
function _esf_tc_homepage_callback() {
  drupal_set_title(t('Welcome to the website of the ESF Transnational Platform'));
  return array();
}

/**
 * Implements template_preprocess_node().
 */
function esf_tc_preprocess_node(&$variables) {
  $resend = array(
    'role' => 'legal contact',
    'nid' => $variables['nid'],
  );

  if ($variables['type'] == 'esf_tnc_organisation') {

    if (isset($variables['field_org_contact_account'][0])) {
      // Manage legal contact data.
      if ($variables['field_org_contact_account'][0]['value'] == 'yes') {
        $resend['type'] = 'ecas';
        if (!empty($variables['field_org_contact'][0])) {
          $legal_contact = $variables['field_org_contact'][0]['entity'];

          $resend['name'] = format_username($legal_contact);
          $resend['email'] = $legal_contact->mail;

          // Diplay user profile (esf_teaser).
          $variables['content']['contact'] = $variables['content']['field_org_contact'];
          if (!empty($variables['field_org_contact_legal_role'][0]['value']) && $legal_contact->uid) {
            $variables['content']['contact'][0]['user'][$legal_contact->uid]['#additional_info'] = $variables['field_org_contact_legal_role'][0]['value'];
          }
        }
      }
      else {
        $resend['type'] = 'simple';
        if ($variables['field_org_contact_account'][0]['value'] == 'no') {
          if (!empty($variables['field_org_contact_legal_name'][0]['value'])) {
            // Diplay contact fields.
            $variables['content']['contact']['field_org_contact_legal_name'] = $variables['content']['field_org_contact_legal_name'];
            $variables['content']['contact']['field_org_contact_legal_email'] = $variables['content']['field_org_contact_legal_email'];
            $variables['content']['contact']['field_org_contact_legal_role'] = $variables['content']['field_org_contact_legal_role'];

            $resend['name'] = $variables['field_org_contact_legal_name'][0]['value'];
          }
          if (!empty($variables['field_org_contact_legal_email'][0]['value'])) {
            $resend['email'] = $variables['field_org_contact_legal_email'][0]['value'];
          }
        }
      }
    }
    // Add link to notify contact again.
    // Check if array is fully filled.
    if (count($resend) == 5 && node_access('update', $variables['node'])) {
      $contact_role = $variables['field_org_contact_legal_role'][0]['value'];
      $options = array(
        'query' => array('destination' => current_path()),
        'attributes' => array(
          'type' => 'message',
          'class' => array('btn-danger'),
        ),
        'html' => FALSE,
      );
      $variables['contact_notify_link'] = l(t('Resend invitation'), drupal_encode_path(format_string('esf/notify/contact/@type/@nid/@name/@role/@email',
        array(
          '@type' => $variables['type'],
          '@nid' => $variables['nid'],
          '@name' => $resend['name'],
          '@role' => $contact_role,
          '@email' => $resend['email'],
        ))),
        $options
      );
    }
  }

  if ($variables['type'] == 'esf_tnc_project') {
    $_arr_fields = array('field_project_manager', 'field_project_operat_contact');
    foreach ($_arr_fields as $field_name) {
      $element = &$variables['content'][$field_name];
      if (!empty($element)) {
        $indexes = array_filter(array_keys($element), 'is_int');
        foreach ($indexes as $index) {
          $element[$index]['user'][$element['#items'][$index]['target_id']]['#additional_info'] = $element['#title'];
        }
        unset($index);
      }
    }
    unset($field_name);
  }

  // Link the TN tag to related section page with term selected in a facet.
  _esf_tc_link_tag_to_section($variables);
}

/**
 * Implements template_preprocess_entity().
 *
 * Runs a entity specific preprocess function, if it exists.
 */
function esf_tc_preprocess_entity(&$variables, $hook) {
  $function = __FUNCTION__ . '_' . $variables['entity_type'];
  if (function_exists($function)) {
    $function($variables, $hook);
  }
}

/**
 * Field Collection-specific implementation of template_preprocess_entity().
 */
function esf_tc_preprocess_entity_field_collection_item(&$variables) {
  if ($variables['elements']['#bundle'] == 'field_org_additional_contacts') {
    $contact_entity = $variables['elements']['#entity'];
    if ($contact_entity->field_fc_contact_account[LANGUAGE_NONE][0]['value'] == 'yes') {
      $variables['content']['contact'] = $variables['content']['field_fc_org_contact'];
      $uid = $contact_entity->field_fc_org_contact[LANGUAGE_NONE][0]['target_id'];
      if (!empty($variables['field_fc_org_role'][0]['value']) && $uid) {
        $variables['content']['contact'][0]['user'][$uid]['#additional_info'] = $variables['field_fc_org_role'][0]['value'];
      }
    }
    else {
      if ($contact_entity->field_fc_contact_account[LANGUAGE_NONE][0]['value'] == 'no') {
        $variables['content']['contact']['field_fc_org_name'] = $variables['content']['field_fc_org_name'];
        $variables['content']['contact']['field_fc_org_email'] = $variables['content']['field_fc_org_email'];
        $variables['content']['contact']['field_fc_org_role'] = $variables['content']['field_fc_org_role'];
      }
    }
  }
}

/**
 * Implements theme_preprocess_block().
 */
function esf_tc_preprocess_block(&$variables) {
  // Add a specific class to the SolR Facet block
  // - Based on title of name of the facet.
  if ($variables['block']->module == 'facetapi') {
    if (module_load_include('inc', 'pathauto', 'pathauto') !== FALSE) {
      if (function_exists('pathauto_cleanstring')) {
        $variables['classes_array'][] = pathauto_cleanstring($variables['elements']['#title']);
      }
    }
  }
  // Remove notice error on block.tpl.php.
  if (!$variables['panel']) {
    $variables['panel'] = 0;
  }
}

/**
 * Implements theme_facetapi_title().
 */
function esf_tc_facetapi_title($variables) {
  // Customize SolR facet block title.
  switch ($variables['title']) {
    case "Activities":
      return t('Filter by activity');

    case "Target groups":
      return t('Filter by target group');

    case "Themes":
      return t('Filter by theme');

    case "Searching":
      return t('Filter by Active searches');

    case "Content type":
      return t('Filter by domain');

    case "Linked TN":
      return t('Filter by Thematic Network');

    default:
      return t('Filter by @title', array('@title' => drupal_strtolower($variables['title'])));
  }
}

/**
 * Implements hook_theme().
 */
function esf_tc_theme($existing, $type, $theme, $path) {
  return array(
    'bootstrap_btn_dropdown' => array(
      'variables' => array(),
      'template' => 'bootstrap_btn_dropdown',
      'path' => drupal_get_path('theme', 'esf_tc') . '/templates',
    ),
  );
}

/**
 * Implements theme_apachesolr_sort_list().
 */
function esf_tc_apachesolr_sort_list($variables) {
  return theme('bootstrap_btn_dropdown', $variables);
}

/**
 * Implements theme_menu_link().
 */
function esf_tc_menu_link__menu_left_menu($variables) {
  $sub_menu = '';
  $element = $variables['element'];
  $menu_string = $element['#title'];
  $menu_item = menu_get_item();

  // Add forum topics in left menu.
  if ($menu_item['page_callback'] == 'forum_page') {
    if (module_load_include('inc', 'pathauto', 'pathauto') !== FALSE) {
      $menu_string = pathauto_cleanstring($menu_string);
    }

    if ($menu_string == 'networking') {
      $sub_menu = _esf_tc_get_forum_categories_menu();
    }

    if ($sub_menu) {
      $element['#attributes']['class'][] = 'haschildren';
    }
  }

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }

  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Create a menu of forum topics (taxonomy terms).
 */
function _esf_tc_get_forum_categories_menu() {
  $output = '';

  // Get current category from menu.
  $menu_item = menu_get_item();
  $current_category = (isset($menu_item['page_arguments'][0]) ? $menu_item['page_arguments'][0]->tid : 0);

  $vocab = taxonomy_vocabulary_machine_name_load('forums');
  if (!empty($vocab)) {
    $tree = taxonomy_get_tree($vocab->vid, 0, 1);
    if (!empty($tree)) {
      $output = '<ul class="menu forum-category">';
      foreach ($tree as $term) {
        $safe_term = pathauto_cleanstring($term->name);
        $class = ($current_category == $term->tid) ? 'active' : '';
        $output .= '<li>' . l($term->name, 'forums/' . $safe_term, array('attributes' => array('class' => $class))) . '</li>';
      }
      $output .= '</ul>';
    }
  }

  return $output;
}

/**
 * Link a content to a specific section based on selected tag and content type.
 *
 * The tag is also selected in a facet.
 */
function _esf_tc_link_tag_to_section(&$variables) {

  $solr_page = apachesolr_search_page_load(apachesolr_search_default_search_page());
  $solr_path = $solr_page['search_path'];

  if ($variables['type'] == 'esf_tnc_event') {
    foreach ($variables['field_esf_linked_tn'] as $id => $term) {
      $variables['content']['field_esf_linked_tn'][$id]['#markup'] = l($term['taxonomy_term']->name, 'events', array('query' => array('f[0]' => 'im_field_esf_linked_tn:' . $term['tid'])));
    }
    foreach ($variables['field_esf_event_country'] as $id => $term) {
      $variables['content']['field_esf_event_country'][$id]['#markup'] = l($term['taxonomy_term']->name, 'events', array('query' => array('f[0]' => 'im_field_esf_event_country:' . $term['tid'])));
    }
  }
  elseif ($variables['type'] == 'esf_tnc_news') {
    foreach ($variables['field_esf_linked_tn'] as $id => $term) {
      $variables['content']['field_esf_linked_tn'][$id]['#markup'] = l($term['taxonomy_term']->name, 'news', array('query' => array('f[0]' => 'im_field_esf_linked_tn:' . $term['tid'])));
    }
  }
  elseif ($variables['type'] == 'esf_tnc_project' || $variables['type'] == 'esf_tnc_call_for_project' || $variables['type'] == 'esf_tnc_organisation') {
    if (isset($variables['field_project_target_groups'])) {
      foreach ($variables['field_project_target_groups'] as $id => $term) {
        $variables['content']['field_project_target_groups'][$id]['#markup'] = l($term['taxonomy_term']->name, $solr_path, array(
          'query' => array(
            'f[0]' => 'im_field_project_target_groups:' . $term['tid'],
            'f[1]' => 'bundle:' . $variables['type'],
          ),
        ));
      }
    }
    if (isset($variables['field_project_activities_list'])) {
      foreach ($variables['field_project_activities_list'] as $id => $term) {
        $variables['content']['field_project_activities_list'][$id]['#markup'] = l($term['taxonomy_term']->name, $solr_path, array(
          'query' => array(
            'f[0]' => 'im_field_project_activities_list:' . $term['tid'],
            'f[1]' => 'bundle:' . $variables['type'],
          ),
        ));
      }
    }
    if (isset($variables['field_esf_themes_ref'])) {
      foreach ($variables['field_esf_themes_ref'] as $id => $term) {
        $variables['content']['field_esf_themes_ref'][$id]['#markup'] = l($term['taxonomy_term']->name, $solr_path, array(
          'query' => array(
            'f[0]' => 'im_field_esf_themes_ref:' . $term['tid'],
            'f[1]' => 'bundle:' . $variables['type'],
          ),
        ));
      }
    }
    if (isset($variables['field_esf_country_ref'])) {
      foreach ($variables['field_esf_country_ref'] as $id => $term) {
        $variables['content']['field_esf_country_ref'][$id]['#markup'] = l($term['taxonomy_term']->name, $solr_path, array(
          'query' => array(
            'f[0]' => 'im_field_esf_country_ref:' . $term['tid'],
            'f[1]' => 'bundle:' . $variables['type'],
          ),
        ));
      }
    }
  }
}

/**
 * Implements hook_user_view_alter().
 */
function esf_tc_user_view_alter(&$build) {
  $account = $build['#account'];
  $profile2 = profile2_load_by_user($account);

  if (isset($profile2['contact_profile'])) {
    $wrapper = entity_metadata_wrapper('profile2', $profile2['contact_profile']);
    // If user do not keep his email private.
    if ($wrapper->field_profile_cont_email_private->value() != 'yes') {
      // Display his email address on fake field.
      $access = profile2_profile2_access('view', $profile2['contact_profile']) ? TRUE : FALSE;
      $build['profile_contact_profile']['view']['profile2']['field_mail'] = array(
        '#theme' => 'field',
        '#weight' => 1,
        '#field_type' => 'text',
        '#label_display' => 'inline',
        '#field_name' => 'email',
        '#entity_type' => 'user',
        '#bundle' => 'user',
        '#title' => t('E-mail'),
        '#items' => array(array('value' => $account->mail)),
        '#access' => $access,
        0 => array('#markup' => $account->mail),
      );
    }
  }

  if (isset($build['tmgmt_translation_skills']['#items']) && !count($build['tmgmt_translation_skills']['#items'])) {
    unset($build['tmgmt_translation_skills']);
  }
}

/**
 * Implements template_preprocess_user_profile().
 */
function esf_tc_preprocess_user_profile(&$variables) {
  // Replace date by additional info.
  if (empty($variables['user_info']['date']) && !empty($variables['elements']['#additional_info'])) {
    $variables['user_info']['date'] = ucfirst($variables['elements']['#additional_info']);
  }
}
