/**
 * @file
 * Javascripts for ESF TC theme.
 */

jQuery(document).ready(function ($) {
  var $body = $('body'),
    $sidebarLeft = $('#sidebar-left');

  if ($body.is('.page-partners-search')) {

    // Clone filters.
    (function () {
      // Create a container element - Filtering system.
      var a_facetapiActive = $('.facetapi-active'),
        $contentTitleParent = $('#content-title').parent(),
        $hiderCloser = '<span class="glyphicon glyphicon-remove hider"/>',
        $filtersList = $('<ul/>', {
          'id': 'filtersList',
          'class': 'panel-body'
        }),
        $respFiltersContainer = $('<div/>', {
          'class': 'collapse navbar-ex2-collapse',
          'id': 'sidebar-left-resp'
        });

        $respFiltersContainer.insertBefore($contentTitleParent);

        // If there is a least one facet (filter) active.
        if (a_facetapiActive.length > 0) {

          // Prepend it to the content element.
          $filtersList.wrap('<div class="filters-container"></div>').insertBefore($contentTitleParent);
          a_facetapiActive.each(function () {
            var $this = $(this),
            _text = $this[0].nextSibling.nodeValue,
            _href = $this.attr('href'),
            $parent = $this.parent(),
            _class = $this.parents('.block-facetapi').attr('class');

            // Create a <li> including cloned content of active filter.
            var $clone = $('<li>', {
              'class': _class
            })
              .html('<a href="' + _href + '"><span>' + _text + '</span> ' + $hiderCloser + '</a>');

            $filtersList
              .append($clone);
          });

        }

        // Clone filters for responsive display.
        $sidebarLeft
          .find('.block-facetapi')
          .clone()
          .appendTo($respFiltersContainer);

        $('#menu-button')
          .clone()
          .attr({
            'id': 'filters-button',
            'data-target': '.navbar-ex2-collapse',
            'class': 'glyphicon glyphicon-filter'
          })
            .html('<span>Filter by</span>')
            .insertBefore($respFiltersContainer);

          $('[id^="sidebar-left"]')
          // Expand/collapse.
            .find('.panel-heading')
            .click(function () {
              var $this = $(this),
                $content = $this.siblings('.content');
              if (!$this.is('.active')) {

                // If not mobile --> simple toggle.
                if ($(this).parents('#sidebar-left').length > 0) {
                  $('.active')
                    .removeClass('active')
                    .siblings('.content')
                    .toggle(120);
                  $content
                    .toggle(120);
                }
                // If mobile --> slide toggle.
                else {
                  $content
                    .slideToggle(120);
                }

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
            .find('.block-facetapi .panel-body')
            .append('<span class="glyphicon glyphicon-remove out" />');

          // Collapse/collide subfilters.
          $('[id^="sidebar-left"]')
            .find('.facetapi-facetapi-links .expanded')
            .has('.item-list')
            .contents()
            .filter(function () {
              return this.nodeType === 3;
            })
            .wrap('<span class="filter-text"></span>')
            .end()
            .end()
            .has('.filter-text')
            .find('.filter-text')
            .after('<span class="opener glyphicon glyphicon-plus"/>')
            .end()
            .end()
            .not(':has(".filter-text")')
            .find('>a')
            .after('<span class="opener glyphicon glyphicon-plus"/>');

          $('.opener')
            .click(function () {
              var $this = $(this),
                $next = $this.next();

              $next.slideToggle(190);
              $this.toggleClass('glyphicon-minus glyphicon-plus');

            });

    })();

  }

  // Allows to close left submenu's when clicking outside.
  $('body').on('click', function (event) {
    var eventTarget = $(event.target);
    if (eventTarget.parent('#sidebar-left').length === 0 && !eventTarget.is('.panel-heading') && !eventTarget.is('.panel-body') && !eventTarget.is('[class*="facetapi"]') && !eventTarget.is('[class*="opener"]')) {
      $sidebarLeft.find('.active').trigger('click');
    }
  });
});
