(function ($) {
  Drupal.behaviors.n4t_ndafw_countdown = {
    attach: function (context, settings) {
      var deadline = settings.n4t_ndafw_countdown.enddate;

      initializeCountdown('n4t-ndafw-countdown', deadline);

      function timeRemaining(endtime) {
        var t = Date.parse(endtime) - Date.parse(new Date());
        var days = Math.floor(t / (1000 * 60 * 60 * 24));
        return {
          'total': t,
          'days': days
        };
      }

      function initializeCountdown(id, endtime) {
        var $clock = $('#' + id, context);
        var $daysSpan = $('.days', $clock);

        function updateCountdown() {
          var t = timeRemaining(endtime);

          $daysSpan.html(t.days);

          if (t.total <= 0) {
            clearInterval(timeinterval);
          }
        }

        updateCountdown();
        var timeinterval = setInterval(updateCountdown, 1000);
      }
    }
  };
})(jQuery);