<?php
/**
 * @file
 * esf_tc_library.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function esf_tc_library_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'library';
  $context->description = 'context for library search page refined';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'library*' => 'library*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-left-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-left-menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'views-recent_library_files-block' => array(
          'module' => 'views',
          'delta' => 'recent_library_files-block',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'block-3' => array(
          'module' => 'block',
          'delta' => '3',
          'region' => 'content_right',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for library search page refined');
  t('search');
  $export['library'] = $context;

  return $export;
}
