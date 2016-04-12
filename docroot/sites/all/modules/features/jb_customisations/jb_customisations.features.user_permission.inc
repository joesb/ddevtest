<?php
/**
 * @file
 * jb_customisations.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function jb_customisations_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view prepublished special articles'.
  $permissions['view prepublished special articles'] = array(
    'name' => 'view prepublished special articles',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jb_customisations',
  );

  return $permissions;
}
