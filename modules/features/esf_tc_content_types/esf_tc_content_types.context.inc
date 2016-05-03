<?php
/**
 * @file
 * esf_tc_content_types.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function esf_tc_content_types_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'esf_tc_homepage';
  $context->description = 'context for the ESF home page';
  $context->tag = 'homepage';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'content_top',
          'weight' => '-9',
        ),
        'forum-new' => array(
          'module' => 'forum',
          'delta' => 'new',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-hp_slider-block' => array(
          'module' => 'views',
          'delta' => 'hp_slider-block',
          'region' => 'content_right',
          'weight' => '-10',
        ),
        'esf_tc_content_types-statistics' => array(
          'module' => 'esf_tc_content_types',
          'delta' => 'statistics',
          'region' => 'content_bottom',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for the ESF home page');
  t('homepage');
  $export['esf_tc_homepage'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'esf_tnc_site_wide';
  $context->description = 'global context';
  $context->tag = 'site wide';
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
          'weight' => '-44',
        ),
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'header_top',
          'weight' => '-43',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'header_top',
          'weight' => '-10',
        ),
        'easy_breadcrumb-easy_breadcrumb' => array(
          'module' => 'easy_breadcrumb',
          'delta' => 'easy_breadcrumb',
          'region' => 'featured',
          'weight' => '-10',
        ),
        'system-main-menu' => array(
          'module' => 'system',
          'delta' => 'main-menu',
          'region' => 'featured',
          'weight' => '-9',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-9',
        ),
        'menu-menu-left-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-left-menu',
          'region' => 'sidebar_left',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'workbench-block' => array(
          'module' => 'workbench',
          'delta' => 'block',
          'region' => 'content',
          'weight' => '-8',
        ),
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'cce_basic_config-footer_ipg' => array(
          'module' => 'cce_basic_config',
          'delta' => 'footer_ipg',
          'region' => 'footer',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('global context');
  t('site wide');
  $export['esf_tnc_site_wide'] = $context;

  return $export;
}
