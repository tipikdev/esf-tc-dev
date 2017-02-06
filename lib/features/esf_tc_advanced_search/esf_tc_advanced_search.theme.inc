<?php

/**
 * @file
 * Drupal Module: esf_tc_advanced_search.theme.inc.
 *
 * Theme code for the ESF TC content types feature.
 */

/**
 * Implements hook_theme_registry_alter().
 *
 * Add custom template files.
 */
function esf_tc_advanced_search_theme_registry_alter(&$theme_registry) {
  // Defined path to current module.
  $module_path = drupal_get_path('module', 'esf_tc_advanced_search');
  // Find all .tpl.php files in this module's folder recursively.
  $template_file_objects = drupal_find_theme_templates($theme_registry, '.tpl.php', $module_path . '/templates');
  // Iterate through all found template file objects.
  foreach ($template_file_objects as $key => $template_file_object) {
    // Alter the theme path and template elements.
    $theme_registry[$key]['template'] = $template_file_object['template'];
    $theme_registry[$key]['path'] = $template_file_object['path'];
    $theme_registry[$key]['type'] = 'module';
  }
}
