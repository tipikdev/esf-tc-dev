<?php

/**
 * @file
 * Helpers for the install scripts.
 */

/**
 * Helper to replace default field base image.
 *
 * @param string $field_name
 *   Name of the field.
 * @param string $filename
 *   Default picture filename.
 * @param string $source
 *   Full path to default image.
 */
/*
function _esf_tc_content_types_replace_default_image($field_name, $filename, $source) {
  // Create new file object and get new fid.
  if (file_exists($source)) {
    $file = new stdClass();
    $file->filename = $filename;
    $file->timestamp = REQUEST_TIME;
    $file->uri = $source;
    $file->filemime = file_get_mimetype($source);
    $file->uid = 1;
    $file->status = FILE_STATUS_PERMANENT;
    $file = file_copy($file, 'public://default_images', FILE_EXISTS_REPLACE);
    variable_set('esf_tc_' . $field_name . '_fid', $file->fid);
  }
}
*/
