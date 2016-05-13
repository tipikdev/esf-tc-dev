<?php

/**
 * @file
 * Displays a forum.
 *
 * May contain forum containers as well as forum topics.
 *
 * Available variables:
 * - $forums: The forums to display (as processed by forum-list.tpl.php).
 * - $topics: The topics to display (as processed by forum-topic-list.tpl.php).
 * - $forums_defined: A flag to indicate that the forums are configured.
 *
 * @see template_preprocess_forums()
 *
 * @ingroup themeable
 */
?>
<?php if ($forums_defined): ?>
  <?php if (isset($variables['parents'][0])): ?>
    <?php print $variables['parents'][0]->description; ?>
  <?php endif; ?>
  <?php if (!empty($news)): ?>
    <h2 class="section-title">
      <span
        class="glyphicon glyphicon-chevron-right"></span><?php print t('News'); ?>
    </h2>
    <?php print $news; ?>
  <?php endif; ?>
  <?php if (!empty($events)): ?>
    <h2 class="section-title">
      <span
        class="glyphicon glyphicon-chevron-right"></span><?php print t('Events'); ?>
    </h2>
    <?php print $events; ?>
  <?php endif; ?>
  <div id="forum">
    <?php print $forums; ?>
    <?php if (isset($topics_title)): ?>
      <h2><span
          class="glyphicon glyphicon-chevron-right"></span><?php print $topics_title; ?>
      </h2>
      <ul class="action-links">
        <?php print render($action_links); ?>
      </ul>
    <?php endif; ?>
    <?php print $topics; ?>
  </div>
<?php endif; ?>
