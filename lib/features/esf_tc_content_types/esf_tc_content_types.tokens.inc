<?php
/**
 * @file
 * Builds placeholder replacement tokens for contact related data.
 */

/**
 * Implements hook_token_info().
 */
function esf_tc_content_types_token_info() {
  $types = array(
    'contact' => array(
      'name' => t('Contact'),
      'description' => t('Tokens related to individual contact from the project databases.'),
    ),
    'partner' => array(
      'name' => t('Partner'),
      'description' => t('Tokens related to individual a project partner of a TCA'),
    ),
  );

  $tokens = array(
    'contact' => array(
      'name' => array(
        'name' => t('contact name'),
        'description' => t('Returns the name of the contact'),
      ),
      'email' => array(
        'name' => t('contact email'),
        'description' => t('Returns the email of the contact'),
      ),
      'role' => array(
        'name' => t('contact role'),
        'description' => t('Returns the role of the contact'),
      ),
    ),
    'partner' => array(
      'project' => array(
        'name' => t('Project'),
        'description' => t('The node of the partner project'),
        'type' => 'node',
      ),
    ),
  );

  return array(
    'types' => $types,
    'tokens' => $tokens,
  );
}

/**
 * Implements hook_tokens().
 */
function esf_tc_content_types_tokens($type, $tokens, array $data = array(), array $options = array()) {

  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'contact') {
    $data = $data['contact'];
    foreach ($tokens as $name => $original) {
      if (array_key_exists($name, $data)) {
        $replacements[$original] = $sanitize ? check_plain($data[$name]) : $data[$name];
      }
    }
    unset($name, $original);
  }

  if ($type == 'partner' && !empty($data['partner'])) {
    $node = $data['partner'];
    if ($project_tokens = token_find_with_prefix($tokens, 'project')) {
      $replacements += token_generate('node', $project_tokens, array('node' => $node), $options);
    }
  }
  return $replacements;
}
