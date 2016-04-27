<?php
/**
 * @file
 * Default theme implementation for displaying a single search result.
 */
?>
<li class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <h2 class="title"<?php print $title_attributes; ?>>
    <a href="<?php print $url; ?>"><?php print $title; ?></a>
  </h2>
  <?php print render($title_suffix); ?>
  <div class="search-snippet-info">
    <?php if ($type = $result['type']): ?>
      <p class="search-info"><?php print $type; ?></p>
    <?php elseif ($info): ?>
      <p class="search-info"><?php print $info; ?></p>
    <?php endif; ?>
    <?php if ($display = render($snippet)): ?>
      <?php print $display; ?>
    <?php elseif ($snippet): ?>
      <p
        class="search-snippet"<?php print $content_attributes; ?>><?php print $snippet; ?></p>
    <?php endif; ?>
  </div>
</li>
