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
        'content' => esf_tc_build_stats_block(),
      );
      break;
  }
  if ($block) {
    return $block;
  }
}


/**
 * Build the content of Statistics block.
 */
function esf_tc_build_stats_block() {
  $info = array();

  // Count number of Organisations.
  $count = esf_tc_helper_count_published_content('esf_tnc_organisation');

  $info['organisations'] = array(
    'title' => t('Organisations'),
    'count' => $count,
  );

  // Count number of Project.
  $count = esf_tc_helper_count_published_content('esf_tnc_project');

  $info['projects'] = array(
    'title' => t('Projects'),
    'count' => $count,
  );

  // Count number of Active Searching Project.
  $fields = array('field_project_searching' => 1);
  $count = esf_tc_helper_count_published_content('esf_tnc_project', $fields);

  $info['searching'] = array(
    'title' => t('Active searches'),
    'count' => $count,
  );

  unset($query);

  // Count number of TCA.
  $count = esf_tc_helper_count_published_content('esf_tnc_tca');

  $info['TCA'] = array(
    'title' => t('TCAs'),
    'count' => $count,
  );

  // Count number of Calls.
  $count = esf_tc_helper_count_published_content('esf_tnc_global_call');

  $info['calls'] = array(
    'title' => t('Calls'),
    'count' => $count,
  );

  return array('#children' => $info);
}

/**
 * Helper function - Count of published content.
 */
function esf_tc_helper_count_published_content($bundle, $fields = array()) {
  // Field_esf_editorial_status.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $bundle)
    ->fieldCondition('field_esf_editorial_status', 'value', 'published')
    ->propertyCondition('status', 1);

  if (is_array($fields) && count($fields)) {
    foreach ($fields as $field => $value) {
      $query->fieldCondition($field, 'value', $value);
    }
    unset($field);
  }
  $query->count();

  return intval($query->execute());
}
