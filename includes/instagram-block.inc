<?php


 /**
  * Implements hook_block_info().
  */
 function instagram_block_info() {

   $blocks['time'] = array(
     'info' => t('Time instagram'),
     'cache' => DRUPAL_NO_CACHE
   );  
   return $blocks;
 }

 /**
  * Implements hook_block_view().
  */
 function instagram_block_view($delta = '') {
   $block = array();
   switch ($delta) {
     case 'time':
      $block['content'] =  theme('instagram_template');
       break;
   }
   return $block;
 }

/**
 * Implementation of hook_block_configure().
 */

function instagram_block_configure($delta = ''){
  $form = array();
  switch ($delta) {
    case 'time':
      $form['fieldset'] = array(
        '#type' => 'fieldset',
        '#title' => 'Configuración del bloque.',
      );
      $options = array();
      foreach (node_type_get_types() as $key => $value) {
        $options[$key] = $value->name;
      }

      $form['fieldset']['contact_information'] = array(
         '#markup' => t('If the field @Machine Name Field is empty, the data is obtained from @Profile'),
      );

      $form['fieldset']['config_field_type_content'] = array(
        '#type' => 'select',
        '#title' => t('Slider de qué tipo de contenido.'),
        '#options' => $options,
        '#default_value' => variable_get($delta . '_type_content', NULL),
      );

      $form['fieldset']['field_name'] = array(
        '#type' => 'textfield', 
        '#title' => t('Machine Name Field'), 
        '#size' => 20, 
        '#maxlength' => 60, 
        '#default_value' => variable_get('field_name', NULL),
      );

      $form['fieldset']['count_post'] = array(
        '#type' => 'textfield', 
        '#title' => t('Count post Intagram'), 
        '#size' => 20, 
        '#maxlength' => 60, 
        '#default_value' => variable_get('count_post', NULL),
      );

      $form['fieldset']['username'] = array(
        '#type' => 'textfield', 
        '#title' => t('Profile'), 
        '#size' => 20, 
        '#maxlength' => 60, 
        '#default_value' => variable_get('username', NULL),
        '#description' => t('Example https://www.instagram.com/procolombiaco @Profile = "procolombiaco"'),
      );

    break;
  }
  return $form;
}

/**
 * Implementation of hook_block_save().
 */

function instagram_block_save($delta = '', $edit = array()){
  switch ($delta) {
    case 'time':
      if (isset($edit['config_field_type_content'])) {
        variable_set($delta . '_type_content', $edit['config_field_type_content']);
      }
      if (isset($edit['field_name'])) {
        variable_set('field_name', $edit['field_name']);
      }  
      if (isset($edit['count_post'])) {
        variable_set('count_post', $edit['count_post']);
      } 
      if (isset($edit['username'])) {
        variable_set('username', $edit['username']);
      }                  
    break;
  }
}