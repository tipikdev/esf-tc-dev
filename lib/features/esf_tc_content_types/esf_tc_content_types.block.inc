<?php
/**
 * @file
 * Block process.
 */

/**
 * Implements hook_block_info().
 */
function esf_tc_content_types_block_info() {
  return array(
    'statistics' => array(
      'info' => t('Statistics'),
      'cache' => DRUPAL_NO_CACHE,
    ),
  );
}

/**
 * Implements hook_block_view().
 */
function esf_tc_content_types_block_view($delta = '') {
  switch ($delta) {
    case 'statistics':
      $block = array(
        'subject' => t('Statistics'),
        'content' => _esf_tc_build_stats_block(),
      );
      break;
  }
  if ($block) {
    return $block;
  }
}

/**
 * Build the content of Statistics block.
 *
 * @return array
 *    Return additionals information to build statistics blocks.
 */
function _esf_tc_build_stats_block() {
  $info = array();
  $editorial_status_validation = TRUE;
  $search_path = _esf_tc_helper_get_solr_default_page_path();
  // Count number of Organisations.
  $count = _esf_tc_helper_count_published_content('esf_tnc_organisation', $editorial_status_validation);

  $facet = array('f' => array('bundle:esf_tnc_organisation'));
  $info['organisations'] = array(
    'title' => t('Organisations'),
    'count' => $count,
    'link' => url($search_path, array('query' => $facet)),
  );

  // Count number of Project.
  $count = _esf_tc_helper_count_published_content('esf_tnc_project', $editorial_status_validation);

  $facet = array('f' => array('bundle:esf_tnc_project'));
  $info['projects'] = array(
    'title' => t('Projects'),
    'count' => $count,
    'link' => url($search_path, array('query' => $facet)),
  );

  // Count number of Active Searching Project.
  $fields = array('field_project_searching' => 1);
  $count = _esf_tc_helper_count_published_content('esf_tnc_project', $editorial_status_validation, $fields);

  $facet = array('f' => array('bundle:esf_tnc_project', 'bm_field_project_searching:true'));
  $info['searching'] = array(
    'title' => t('Active searches'),
    'count' => $count,
    'link' => url($search_path, array('query' => $facet)),
  );

  // Count number of TCA.
  $count = _esf_tc_helper_count_published_content('esf_tnc_tca', $editorial_status_validation);

  $facet = array('f' => array('bundle:esf_tnc_tca'));
  $info['TCA'] = array(
    'title' => t('TCAs'),
    'count' => $count,
    'link' => url($search_path, array('query' => $facet)),
  );

  // Count number of Calls.
  $count = _esf_tc_helper_count_published_content('esf_tnc_call_for_project');

  $facet = array('f' => array('bundle:esf_tnc_call_for_project'));
  $info['calls'] = array(
    'title' => t('Calls'),
    'count' => $count,
    'link' => url($search_path, array('query' => $facet)),
  );

  return array('#children' => $info);
}

/**
 * Helper function - Count of published content.
 *
 * @param string $bundle
 *    The node bundle.
 * @param bool $editorial_status
 *    add an editorial_status published constraint if TRUE.
 * @param array $fields
 *    Add field Contditions array of $field => $value.
 *
 * @return int
 *    Return the count of content type.
 */
function _esf_tc_helper_count_published_content($bundle, $editorial_status = FALSE, $fields = array()) {
  // Field_esf_editorial_status.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle)
    ->propertyCondition('status', 1);

  if ($editorial_status) {
    $query->fieldCondition('field_esf_editorial_status', 'value', 'published');
  }
  if (is_array($fields) && count($fields)) {
    foreach ($fields as $field => $value) {
      $query->fieldCondition($field, 'value', $value);
    }
    unset($field);
  }
  $query->count();

  return intval($query->execute());
}
