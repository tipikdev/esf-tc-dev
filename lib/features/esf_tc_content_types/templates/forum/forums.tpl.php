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

  <div class="row">
    <?php if (!empty($articles)): ?>
      <div class="section-wrapper col-sm-12 col-xs-12">
        <h2 class="section-title">
          <span class="glyphicon glyphicon-chevron-right"></span><?php print t('Articles'); ?>
        </h2>
        <?php print $articles; ?>
      </div>
    <?php endif; ?>
  </div>
  <div class="row">
    <?php if (!empty($news)): ?>
      <div
        class="section-wrapper<?php print (!empty($events) ? ' col-lg-6' : ' col-lg-12'); ?> col-sm-12 col-xs-12">
        <h2 class="section-title">
      <span
        class="glyphicon glyphicon-chevron-right"></span><?php print t('News'); ?>
        </h2>
        <?php print $news; ?>
      </div>
    <?php endif; ?>
    <?php if (!empty($events)): ?>
      <div
        class="section-wrapper<?php print (!empty($news) ? ' col-lg-6' : ' col-lg-12'); ?> col-sm-12 col-xs-12">
        <h2 class="section-title">
      <span
        class="glyphicon glyphicon-chevron-right"></span><?php print t('Events'); ?>
        </h2>
        <?php print $events; ?>
      </div>
    <?php endif; ?>
  </div>
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
