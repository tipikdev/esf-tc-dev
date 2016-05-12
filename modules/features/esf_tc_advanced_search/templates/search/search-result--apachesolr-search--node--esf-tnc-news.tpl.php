<?php
/**
 * @file
 * Default theme implementation for displaying a single news search result.
 */
?>
<li class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="search-snippet-info">
    <?php if ($display = render($snippet)): ?>
      <?php print $display; ?>
    <?php elseif ($snippet): ?>
      <p class="search-snippet"<?php print $content_attributes; ?>><?php print $snippet; ?></p>
    <?php endif; ?>
  </div>
</li>
