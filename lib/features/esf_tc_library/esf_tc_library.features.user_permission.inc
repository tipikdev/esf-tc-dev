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

  // Exported permission: 'create filedepot_folder content'.
  $permissions['create filedepot_folder content'] = array(
    'name' => 'create filedepot_folder content',
    'roles' => array(
      'administrator' => 'administrator',
      'forum moderator' => 'forum moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any filedepot_folder content'.
  $permissions['delete any filedepot_folder content'] = array(
    'name' => 'delete any filedepot_folder content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own filedepot_folder content'.
  $permissions['delete own filedepot_folder content'] = array(
    'name' => 'delete own filedepot_folder content',
    'roles' => array(
      'administrator' => 'administrator',
      'forum moderator' => 'forum moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in library_vocabulary'.
  $permissions['delete terms in library_vocabulary'] = array(
    'name' => 'delete terms in library_vocabulary',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any filedepot_folder content'.
  $permissions['edit any filedepot_folder content'] = array(
    'name' => 'edit any filedepot_folder content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own filedepot_folder content'.
  $permissions['edit own filedepot_folder content'] = array(
    'name' => 'edit own filedepot_folder content',
    'roles' => array(
      'administrator' => 'administrator',
      'forum moderator' => 'forum moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in library_vocabulary'.
  $permissions['edit terms in library_vocabulary'] = array(
    'name' => 'edit terms in library_vocabulary',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
