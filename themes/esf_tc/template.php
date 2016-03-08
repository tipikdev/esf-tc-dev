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
