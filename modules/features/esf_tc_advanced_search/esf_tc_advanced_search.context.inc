<?php
/**
 * @file
 * esf_tc_advanced_search.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function esf_tc_advanced_search_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'esf_tnc_search';
  $context->description = 'Context for the search pages';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'partners-search*' => 'partners-search*',
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
        'facetapi-GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu' => array(
          'module' => 'facetapi',
          'delta' => 'GiIy4zr9Gu0ZSa0bumw1Y9qIIpIDf1wu',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'facetapi-ramaXcarIJYtkchWjnhLKJ01WcPZps8b' => array(
          'module' => 'facetapi',
          'delta' => 'ramaXcarIJYtkchWjnhLKJ01WcPZps8b',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
        'facetapi-vsSLrOcP6IW0okSfzp6XIBYdkp4Pl38d' => array(
          'module' => 'facetapi',
          'delta' => 'vsSLrOcP6IW0okSfzp6XIBYdkp4Pl38d',
          'region' => 'sidebar_left',
          'weight' => '-7',
        ),
        'facetapi-zp8ortpktyXz6ssgriwmd0500qUbCBYo' => array(
          'module' => 'facetapi',
          'delta' => 'zp8ortpktyXz6ssgriwmd0500qUbCBYo',
          'region' => 'sidebar_left',
          'weight' => '-6',
        ),
        'facetapi-f8T8WxOvyylmZ4Hhyj0zOl7Tg1BxnAa7' => array(
          'module' => 'facetapi',
          'delta' => 'f8T8WxOvyylmZ4Hhyj0zOl7Tg1BxnAa7',
          'region' => 'sidebar_left',
          'weight' => '-5',
        ),
        'facetapi-p1mdJDnWm1Svtyhr8RxKzvtH84BX1q2U' => array(
          'module' => 'facetapi',
          'delta' => 'p1mdJDnWm1Svtyhr8RxKzvtH84BX1q2U',
          'region' => 'sidebar_left',
          'weight' => '-4',
        ),
        'apachesolr_search-sort' => array(
          'module' => 'apachesolr_search',
          'delta' => 'sort',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context for the search pages');
  t('search');
  $export['esf_tnc_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'esf_tnc_site_wide_search';
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
        'esf_tc_advanced_search-partners_search_block' => array(
          'module' => 'esf_tc_advanced_search',
          'delta' => 'partners_search_block',
          'region' => 'content_top',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('global context');
  t('site wide');
  $export['esf_tnc_site_wide_search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'event-search';
  $context->description = 'context for event search page';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'events' => 'events',
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
        'facetapi-MLVrCOI59V1xb6WMeEPREpT89ZpN5ZxP' => array(
          'module' => 'facetapi',
          'delta' => 'MLVrCOI59V1xb6WMeEPREpT89ZpN5ZxP',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
        'facetapi-M25HaXJhGFuf90wFawfbm1lhspReJ9nY' => array(
          'module' => 'facetapi',
          'delta' => 'M25HaXJhGFuf90wFawfbm1lhspReJ9nY',
          'region' => 'sidebar_left',
          'weight' => '-8',
        ),
        'facetapi-ahPHo0uhIJPJC2xhqiJd81U13Zi2Hbes' => array(
          'module' => 'facetapi',
          'delta' => 'ahPHo0uhIJPJC2xhqiJd81U13Zi2Hbes',
          'region' => 'sidebar_left',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for event search page');
  t('search');
  $export['event-search'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news-search';
  $context->description = 'context for news search page';
  $context->tag = 'search';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news' => 'news',
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
        'facetapi-MLVrCOI59V1xb6WMeEPREpT89ZpN5ZxP' => array(
          'module' => 'facetapi',
          'delta' => 'MLVrCOI59V1xb6WMeEPREpT89ZpN5ZxP',
          'region' => 'sidebar_left',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('context for news search page');
  t('search');
  $export['news-search'] = $context;

  return $export;
}
