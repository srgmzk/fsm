#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "fsm.h"

unsigned int is_tt_entry_empty(tt_entry_t *tt_entry) {
	
	tt_entry_ptr->next_state;

}

tt_entry_t *
get_next_emtpy_tt_entry(fmt_t *trans_table) {

	unsigned int i = 0;
	for (; i < MAX_TRANSITION_TABLE_SIZE; i++)
		if (is_tt_entry_empty(trans_table))	
			return trans_table[i]; 
	return NULL;
}


fsm_t *
create_new_fsm(const char *fsm_name) {
	fsm_t *fsm = calloc(1, sizeof(fsm_t));
	strncpy(fsm->fsm_name, fsm_name, MAX_FSM_NAME_SIZE - 1);
	fsm->fsm_name[MAX_FSM_NAME_SIZE - 1] = '\0';
	return fsm;
}

state_t *
create_new_state(char *state_name, fsm_boot_t is_final) {
	assert(state_name);
	state_t *state = calloc(1, sizeof(state_t));
	strncpy(state->state_name, state_name, MAX_STATE_NAME_SIZE-1);
	state->state_name[MAX_STATE_NAME_SIZE - 1] = '\0';
	
	state->is_final = is_final;
	return state;
}

void 
set_fsm_initial_state(fsm_t *fsm, state_t *state) {
	assert(!fsm->initial_state);
	fsm->initial_state = state;
}

tt_entry_t *
create_and_insert_new_tt_entry(tt_t *trans_table, 
							char *transition_key,
							unsigned int sizeof_key,
							state_t *next_state ) {

	assert(sizeof_key < MAX_TRANSITION_KEY_SIZE);
	tt_entry_t *tt_etnry_ptr = get_next_emtpy_tt_entry(trans_table);

	if (!tt_entry_ptr) {
		printf("FATAL : Transition Table is Full\n");
		return;
	}
	
	memcpy(tt_entry_ptr->transition_key, transition_key, sizeof_key);
	tt_entry_ptr->transition_key[sizeof_key] = '\0';
	tt_entry_ptr->transition_key_size = sizeof_key;
	tt_entry_ptr->next_state = next_state;
}
