<?php

/**
 * @file
 * Contains the 'taxonomy term' overridden argument validator plugin.
 */

/**
 * Validate whether an argument is an acceptable node.
 */
class views_plugin_argument_validate_taxonomy_term_machine_name extends views_plugin_argument_validate_taxonomy_term {

  function options_form(&$form, &$form_state) {

    parent::options_form($form, $form_state);

    // Add new validator.
    $form['type']['#options']['machine_name'] = t('Term machine name');
  }

  function validate_argument($argument) {
    $vocabularies = array_filter($this->options['vocabularies']);
    $type = $this->options['type'];
    $transform = $this->options['transform'];

    switch ($type) {
      case 'machine_name':
        $query = db_select('taxonomy_term_data', 'td');
        $query->leftJoin('taxonomy_vocabulary', 'tv', 'td.vid = tv.vid');
        $query->fields('td');
        $query->fields('tv', array('machine_name'));
        if (!empty($vocabularies)) {
          $query->condition('tv.machine_name', $vocabularies);
        }
        if ($transform) {
          $query->where("replace(td.machine_name, ' ', '-') = :name", array(':name' => $argument));
        }
        else {
          $query->condition('td.machine_name', $argument);
        }
        $term = $query->execute()->fetchObject();

        if ($term && (empty($vocabularies) || !empty($vocabularies[$term->machine_name]))) {
          if ($type == 'convert') {
            $this->argument->argument = $term->tid;
          }
          $term = taxonomy_term_load($term->tid);
          $this->argument->validated_title = check_plain(entity_label('taxonomy_term', $term));
          return TRUE;
        }
        return FALSE;

      default:
        return parent::validate_argument($argument);
    }
  }
}
