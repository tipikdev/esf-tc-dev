<?php
/**
 * @file
 * esf_tc_content_types.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function esf_tc_content_types_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-left-menu_esf-transnational-cooperation:<front>.
  $menu_links['menu-left-menu_esf-transnational-cooperation:<front>'] = array(
    'menu_name' => 'menu-left-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'ESF Transnational Cooperation',
    'options' => array(
      'identifier' => 'menu-left-menu_esf-transnational-cooperation:<front>',
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
    'external' => 1,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-left-menu_mytnc:user.
  $menu_links['menu-left-menu_mytnc:user'] = array(
    'menu_name' => 'menu-left-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'myTNC',
    'options' => array(
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
        'class' => 'mytnc',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'identifier' => 'menu-left-menu_mytnc:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-left-menu_esf-transnational-cooperation:<front>',
  );
  // Exported menu link: menu-left-menu_news--events:forum/552.
  $menu_links['menu-left-menu_news--events:forum/552'] = array(
    'menu_name' => 'menu-left-menu',
    'link_path' => 'forum/552',
    'router_path' => 'forum/%',
    'link_title' => 'News & Events',
    'options' => array(
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
        'class' => 'news',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'identifier' => 'menu-left-menu_news--events:forum/552',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-left-menu_esf-transnational-cooperation:<front>',
  );
  // Exported menu link: menu-left-menu_partner-database:search/partners-search.
  $menu_links['menu-left-menu_partner-database:search/partners-search'] = array(
    'menu_name' => 'menu-left-menu',
    'link_path' => 'search/partners-search',
    'router_path' => 'search/partners-search',
    'link_title' => 'Partner database',
    'options' => array(
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
        'class' => 'partner',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'identifier' => 'menu-left-menu_partner-database:search/partners-search',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-left-menu_esf-transnational-cooperation:<front>',
  );
  // Exported menu link: menu-left-menu_search-transnational-platform:search/site.
  $menu_links['menu-left-menu_search-transnational-platform:search/site'] = array(
    'menu_name' => 'menu-left-menu',
    'link_path' => 'search/site',
    'router_path' => 'search/site',
    'link_title' => 'Search transnational platform',
    'options' => array(
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
        'class' => 'search',
        'data-remove-class' => 0,
        'style' => '',
      ),
      'identifier' => 'menu-left-menu_search-transnational-platform:search/site',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-left-menu_esf-transnational-cooperation:<front>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('ESF Transnational Cooperation');
  t('News & Events');
  t('Partner database');
  t('Search transnational platform');
  t('myTNC');

  return $menu_links;
}
