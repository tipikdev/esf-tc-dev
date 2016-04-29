<?php

/**
 * @file
 * Theme implementation to display an event.
 */
?>
<div id="node-<?php print $node->nid; ?>"
     class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print $user_picture; ?>

  <?php if ($display_submitted): ?>
    <div class="submitted">
      <?php print $submitted; ?>
    </div>
  <?php endif; ?>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    ?>
    <?php if ($view_mode == 'teaser'): ?>
      <?php print render($content['field_esf_event_start_date']); ?>
      <h2<?php print $title_attributes; ?>><a
          href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <div class="news-wrapper">
        <?php print render($content['field_esf_event_picture']); ?>
        <?php print render($content['body']); ?>
      </div>
      <?php print render($content['field_esf_linked_tn']); ?>
    <?php else: ?>
      <?php print render($content['field_esf_event_start_date']); ?>
      <div class="news-wrapper">
        <?php print render($content['field_esf_event_picture']); ?>
        <?php print render($content['body']); ?>
      </div>
      <?php print render($content['field_esf_event_country']); ?>
      <?php print render($content['field_esf_event_organiser']); ?>
      <?php print render($content['field_esf_event_location']); ?>
      <?php if (isset($content['field_esf_event_attached_doc']['#items']) || isset($content['field_esf_event_external_link']['#items'])): ?>
        <h3><?php print t('Related info'); ?></h3>
        <?php print render($content['field_esf_event_attached_doc']); ?>
        <?php print render($content['field_esf_event_external_link']); ?>
      <?php endif; ?>
      <?php print render($content['field_esf_linked_tn']); ?>
    <?php endif; ?>
  </div>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
