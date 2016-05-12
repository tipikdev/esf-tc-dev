<?php

/**
 * @file
 * Theme implementation to display a news.
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
      <?php print render($content['field_esf_news_date']); ?>
      <?php print render($content['field_esf_news_picture']); ?>
      <div class="news-teaser-wrapper">
        <h2<?php print $title_attributes; ?>><a
            href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
        <div class="news-wrapper">
          <?php print render($content['body']); ?>
        </div>
        <?php print render($content['field_esf_linked_tn']); ?>
        <?php print render($content['links']); ?>
      </div>
    <?php else: ?>
      <?php print render($content['field_esf_news_date']); ?>
      <?php print render($content['field_esf_linked_tn']); ?>
      <div class="news-wrapper">
        <?php print render($content['field_esf_news_picture']); ?>
        <?php print render($content['body']); ?>
      </div>
      <?php if (isset($content['field_esf_news_attached_doc']['#items']) || isset($content['field_esf_news_external_link']['#items'])): ?>
        <div class='related-info'>
          <h3><?php print t('Related info'); ?></h3>
          <?php print render($content['field_esf_news_attached_doc']); ?>
          <?php print render($content['field_esf_news_external_link']); ?>
        </div>
      <?php endif; ?>
      <?php print render($content['links']); ?>
    <?php endif; ?>
  </div>

  <?php print render($content['comments']); ?>

</div>
