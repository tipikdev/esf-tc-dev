<?php
/**
 * @file
 * esf_tc_library.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function esf_tc_library_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access filedepot'.
  $permissions['access filedepot'] = array(
    'name' => 'access filedepot',
    'roles' => array(
      'AEIDL publisher' => 'AEIDL publisher',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'contact' => 'contact',
      'contributor' => 'contributor',
      'editor' => 'editor',
      'editorial team member' => 'editorial team member',
      'forum moderator' => 'forum moderator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'filedepot',
  );

  // Exported permission: 'administer filedepot'.
  $permissions['administer filedepot'] = array(
    'name' => 'administer filedepot',
    'roles' => array(
      'administrator' => 'administrator',
      'forum moderator' => 'forum moderator',
      'webmaster' => 'webmaster',
    ),
    'module' => 'filedepot',
  );

  return $permissions;
}
