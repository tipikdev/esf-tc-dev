<?php
/**
 * @file
 * esf_tc_library.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function esf_tc_library_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-left-menu_library:filedepot.
  $menu_links['menu-left-menu_library:filedepot'] = array(
    'menu_name' => 'menu-left-menu',
    'link_path' => 'filedepot',
    'router_path' => 'filedepot',
    'link_title' => 'Library',
    'options' => array(
      'identifier' => 'menu-left-menu_library:filedepot',
      'attributes' => array(
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'data-remove-class' => 0,
      ),
      'item_attributes' => array(
        'data-image' => '',
        'data-display-title' => 1,
        'data-hide-children' => 0,
        'id' => '',
        'class' => '',
        'data-remove-class' => 0,
        'style' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-left-menu_esf-transnational-cooperation:<front>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Library');

  return $menu_links;
}
