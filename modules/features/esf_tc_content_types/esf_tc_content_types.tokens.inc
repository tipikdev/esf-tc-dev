<?php
/**
 * @file
 * Builds placeholder replacement tokens for contact related data.
 */

/**
 * Implements hook_token_info().
 */
function esf_tc_content_types_token_info() {
  $type = array(
    'name' => t('Contact'),
    'description' => t('Tokens related to individual contact from the project databases.'),
  );

  $contact = array(
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
  );

  return array(
    'types' => array('contact' => $type),
    'tokens' => array('contact' => $contact),
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
  return $replacements;
}
