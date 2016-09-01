<?php

function views_reset_config_form($form, &$form_state) {
  $views = views_get_enabled_views();
  $view_options = array();
  foreach ($views as $view_name => $view) {
    $view_options[$view_name] = !empty($view->human_name) ? $view->human_name : $view_name;
  }
  $form['views_reset_views'] =  array(
    '#type' => 'checkboxes',
    '#title' => t('Views'),
    '#description' => t('Select views to apply the reset link. Only enabled views are shown here. Reload this page to get checkbox for recently enabled views.'),
    '#options' => $view_options,
    '#default_value' => variable_get('views_reset_views', array()),
  );
  return system_settings_form($form);
}
