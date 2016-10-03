<?php
/**
 * Renders settings form
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function n4t_ndafw_countdown_admin_form($form, &$form_state) {
  $endDate = variable_get(N4T_NDAFW_DATE_END_DATE, '');

  $form['ndafw_end_date'] = array(
    '#title'              => t('NDAFW End Date'),
    '#type'               => 'date_popup',
    '#date_format'        => N4T_NDAFW_DATE_FORMAT,
    '#datepicker_options' => array(
      'minDate' => '+0D',
    ),
    '#default_value'      => $endDate,
    '#required'           => TRUE,
  );

  $form['submit'] = array(
    '#type'  => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Handles settings form submit
 *
 * @param $form
 * @param $form_state
 */
function n4t_ndafw_countdown_admin_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  if ($values['op'] === t('Save')) {
    $endDate = '';

    if ($form['ndafw_end_date']['#type'] === 'date_popup') {
      $endDate = $values['ndafw_end_date'];
    }
    else {
      $endDate = $values['ndafw_end_date']['month'] . '-' .
                 $values['ndafw_end_date']['day'] . '-' .
                 $values['ndafw_end_date']['year'];
    }

    variable_set(N4T_NDAFW_DATE_END_DATE, $endDate);
    drupal_set_message(t('Settings have been successfully updated.'), 'status');
  }
}