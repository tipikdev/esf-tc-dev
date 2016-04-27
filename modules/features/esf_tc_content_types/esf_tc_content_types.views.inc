<?php

/**
 * @file
 * Drupal Module: esf_tc_content_types.
 *
 * Adds custom code specific to views.
 */

/**
 * Implements hook_views_pre_render().
 */
function esf_tc_content_types_views_pre_render(&$view) {
  // Display last events in ascending order.
  if ($view->name == 'esf_events' && $view->current_display == 'block_1') {
    $view->result = array_reverse($view->result);
  }
}
