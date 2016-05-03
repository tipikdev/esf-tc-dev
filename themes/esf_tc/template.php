<?php
/**
 * @file
 * Default theme functions.
 */

/**
 * Implements template_preprocess_page().
 */
function esf_tc_preprocess_page(&$variables) {
  if (drupal_is_front_page()) {
    // Remove system_main content.
    unset($variables['page']['content']['system_main']['default_message']);
    unset($variables['page']['content']['#children']);
    $variables['regions']['content'] = render($variables['page']['content']);
  }
}

/**
 * Implements template_preprocess_node().
 */
function esf_tc_preprocess_node(&$variables) {
  if ($variables['type'] == 'esf_tnc_organisation') {
    // Manage legal contact data.
    if ($variables['field_org_contact_account'][0]['value'] == 'yes') {
      $legal_contact = user_load($variables['field_org_contact'][0]['target_id']);
      $variables['contact_name'] = $legal_contact->field_firstname[LANGUAGE_NONE][0]['value'] . ' ' . $legal_contact->field_lastname[LANGUAGE_NONE][0]['value'];
      $contact_profile = profile2_load_by_user($legal_contact, 'contact_profile');
      if (isset($contact_profile)) {
        if ($contact_profile->field_profile_cont_email_private[LANGUAGE_NONE][0]['value'] == 'no') {
          $variables['contact_email'] = $legal_contact->mail;
        }
      }
    }
    else {
      if ($variables['field_org_contact_account'][0]['value'] == 'no') {
        if (!empty($variables['field_org_contact_legal_name'][0]['value'])) {
          $variables['contact_name'] = $variables['field_org_contact_legal_name'][0]['value'];
        }
        if (!empty($variables['field_org_contact_legal_email'][0]['value'])) {
          $variables['contact_email'] = $variables['field_org_contact_legal_email'][0]['value'];
        }
      }
    }
    if (!empty($variables['field_org_contact_legal_role'][0]['value'])) {
      $variables['contact_role'] = $variables['field_org_contact_legal_role'][0]['value'];
    }
  }
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
      $contact = $variables['elements']['#entity']->field_fc_org_contact[LANGUAGE_NONE][0]['entity'];
      $variables['contact_name'] = $contact->field_firstname[LANGUAGE_NONE][0]['value'] . ' ' . $contact->field_lastname[LANGUAGE_NONE][0]['value'];
      $contact_profile = profile2_load_by_user($contact, 'contact_profile');
      if (isset($contact_profile)) {
        if ($contact_profile->field_profile_cont_email_private[LANGUAGE_NONE][0]['value'] == 'no') {
          $variables['contact_email'] = $contact->mail;
        }
      }
    }
    else {
      if ($contact_entity->field_fc_contact_account[LANGUAGE_NONE][0]['value'] == 'no') {
        $variables['contact_name'] = $variables['field_fc_org_name'][0]['value'];
        $variables['contact_email'] = $variables['field_fc_org_email'][0]['value'];
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
