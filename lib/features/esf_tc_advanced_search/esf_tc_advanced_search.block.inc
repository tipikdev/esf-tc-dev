<?php

/**
 * @file
 * Code for the esf_tc_advanced_search feature.
 */

/**
 * Implements hook_block_info().
 */
function esf_tc_advanced_search_block_info() {
  $path = _esf_tc_helper_get_solr_default_page_path();
  return array(
    'partners_search_block' => array(
      'info' => t('Partners search block'),
      'visibility' => 0,
      'custom' => 0,
      'pages' => $path . '\n' . $path . '/*',
    ),
  );
}

/**
 * Implements hook_block_view().
 */
function esf_tc_advanced_search_block_view($delta = '') {
  switch ($delta) {
    case 'partners_search_block':
      $path = _esf_tc_helper_get_solr_default_page_path();
      $block = array(
        'content' => _esf_tc_helper_custom_search_block($path),
      );
  }
  if ($block) {
    return $block;
  }
}

/**
 * Custom Search Block for parners.
 */
function _esf_tc_helper_custom_search_block($path) {
  $form = drupal_get_form('esf_tc_custom_partner_search_form');
  return drupal_render($form);
}

/**
 * Helper function get Default search page path.
 */
function _esf_tc_helper_get_solr_default_page_path() {
  $solr_page = apachesolr_search_page_load(apachesolr_search_default_search_page());
  return $solr_page['search_path'];
}

/**
 * Override Custom Search Block for parners.
 */
function esf_tc_custom_partner_search_form($form, &$form_state) {
  $form['#attributes']['class'][] = 'form-inline';
  $form['keys'] = array(
    '#type' => 'textfield',
    '#name' => 'keys',
    '#attributes' => array('placeholder' => t('Search in the databases')),
    '#prefix' => '<div class=form-group >',
    '#suffix' => '</div>',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('search'),
  );
  $form['#submit'][] = 'esf_tc_custom_partner_search_form_submit';
  return $form;

}

/**
 * Submit handler for custom Search Block for parners.
 */
function esf_tc_custom_partner_search_form_submit($form, &$form_state) {
  $path = _esf_tc_helper_get_solr_default_page_path();
  $path_return = $path . '/' . trim($form_state['values']['keys']);
  drupal_goto($path_return);
}
