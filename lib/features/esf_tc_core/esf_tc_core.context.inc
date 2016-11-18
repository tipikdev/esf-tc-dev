<?php

/**
 * @file
 * esf_tc_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function esf_tc_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE;
  $context->api_version = 3;
  $context->name = 'core-sitewide';
  $context->description = '';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-service-tools' => array(
          'module' => 'menu',
          'delta' => 'menu-service-tools',
          'region' => 'header_top',
          'weight' => '-10',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'footer',
          'weight' => '-37',
        ),
        'cce_basic_config-footer_ipg' => array(
          'module' => 'cce_basic_config',
          'delta' => 'footer_ipg',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Sitewide');
  $export['core-sitewide'] = $context;

  return $export;
}
