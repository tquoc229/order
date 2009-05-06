<?php
function order_admin_setting(){
	$form = array();
	$node_types = node_get_types();
	
	foreach ($node_types as $key => $value){
		$options[$key] = $value->name;
	}
	$form['order_node_types'] = array(
	  '#type' => 'checkboxes',
	  '#options' => $options,
	  '#title' => 'Choose node type to order',
	  '#default_value' => variable_get('order_node_types',array()),
	);
	$form['order_admin_mail'] = array(
    '#type' => 'textfield',
    '#title' => 'Order admin mail',
    '#default_value' => variable_get('order_admin_mail',variable_get('site_mail','')),
	  '#description' => t('You can input multi email separate by ",". Ex: "admin@mail.com,kaka@mail.com'),
  );
	return system_settings_form($form);
}
