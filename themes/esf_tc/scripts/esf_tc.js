/**
 * @file
 * Javascripts for ESF TC theme.
 */

jQuery(document).ready(function ($) {
  var $sidebarLeft = $('#sidebar-left');
  $sidebarLeft
    // Expand/collapse.
    .find('.panel-heading')
    .click(function () {
      var $this = $(this),
        $content = $this.siblings('.content');
      if (!$this.is('.active')) {
        $('.active')
          .removeClass('active')
          .siblings('.content')
          .toggle(120);
        $content
          .toggle(120);
        $this
          .addClass('active');
      }
      else {
        $this
          .removeClass('active');
        $content
          .toggle(120);
      }
    })
    // Add closing cross.
    .end()
    .find('.panel-body')
    .append('<span class="glyphicon glyphicon-remove out" />');

  // Allows to close left submenu's when clicking outside.
  $('body').on('click', function (event) {
    var eventTarget = $(event.target);
    if (eventTarget.parent('#sidebar-left').length === 0 && !eventTarget.is('.panel-heading') && !eventTarget.is('.panel-body') && !eventTarget.is('[class*="facetapi"]')) {
      $sidebarLeft.find('.active').trigger('click');
    }
  });
});
