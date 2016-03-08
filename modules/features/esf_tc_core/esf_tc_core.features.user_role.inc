<?php
/**
 * @file
 * esf_tc_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function esf_tc_core_user_default_roles() {
  $roles = array();

  // Exported role: contact.
  $roles['contact'] = (object) array(
    'name' => 'contact',
    'weight' => 5,
  );

  // Exported role: webmaster.
  $roles['webmaster'] = (object) array(
    'name' => 'webmaster',
    'weight' => 6,
  );

  return $roles;
}
