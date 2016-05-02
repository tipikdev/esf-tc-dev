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
