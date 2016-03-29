<?php
/**
 * @file
 * esf_tc_core.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function esf_tc_core_menu_default_menu_custom() {
  $menus = array();
  
  // Exported menu: menu-left-menu.
  $menus['menu-left-menu'] = array(
    'menu_name' => 'menu-left-menu',
    'title' => 'Left-Menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Left-Menu');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
