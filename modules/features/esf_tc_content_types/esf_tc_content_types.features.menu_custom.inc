<?php
/**
 * @file
 * esf_tc_content_types.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function esf_tc_content_types_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: navigation.
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Navigation');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');
  t("The <em>User</em> menu contains links related to the user's account, as well as the 'Log out' link.");
  t('User menu');

  return $menus;
}
