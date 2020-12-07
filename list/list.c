// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() {
  list_t* new_list_t = malloc(sizeof(list_t));
  new_list_t->head = NULL;
  return new_list_t; 
}

void node_free(node_t *n) {
  if (n->next != NULL){
    node_free(n->next);
  } else {
    free(n);
  }
}
void list_free(list_t *l) {
  node_t* curr = l->head;
  if (curr != NULL){
    node_free(curr);
  }
}

void list_print(list_t *l) {
  node_t* curr = l->head;
  while(curr != NULL) {
    printf("%d", curr->value);
		printf("\n");
    curr = curr->next;
  }
  printf("\n");
}

int list_length(list_t *l) {
  int len = 0;
  node_t* curr = l->head;
  while(curr != NULL) {
    len += 1;
    curr = curr->next;
  }
  return len; 
}

void list_add_to_back(list_t *l, elem value) {
  node_t* curr = l->head;
  node_t* new = malloc(sizeof(node_t));
  new->value = value;
  new->next = NULL;
  if (curr == NULL){
    l->head = new;
    return;
  }
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new;
}

void list_add_to_front(list_t *l, elem value) {
  node_t* new = malloc(sizeof(node_t));
  new->value = value;
  new->next = l->head;
  l->head = new;
}
void list_add_at_index(list_t *l, elem value, int index) {
  if ((index < 0) || (list_length(l) <= index)) {
    return;
  }
  node_t* new = malloc(sizeof(node_t));
  new->value = value;
  int curr_index = 0;
  node_t* curr = l->head;
  while (curr_index+1 != index) {
    curr_index += 1;
    curr = curr->next;
  }
  if (curr == NULL) {
    l->head = new;
  } else {
		printf("here is fine \n");
		new->next = curr->next;
		curr->next = new;
  }
}

elem list_remove_from_back(list_t *l) {
  node_t* curr = l->head;
  node_t* result = curr;
  while((curr != NULL) && (curr->next != NULL)) {
    if ((curr->next->next == NULL)) {
      result = curr->next;
      curr->next = NULL;
    } else {
      curr = curr->next;
    }
  }
  return result->value;
}

elem list_remove_from_front(list_t *l) {
  if (l->head == NULL) {
    return 0;
  } else {
    int val = l->head->value;
    l->head = l->head->next;
    return val;
  }
}

elem list_remove_at_index(list_t *l, int index) {
  if ((index < 0) || (list_length(l) <= index)) {
    return;
  }
  int curr_index = 0;
  node_t* curr = l->head;
  while (curr_index+1 != index) {
    curr_index += 1;
    curr = curr->next;
  }
  int result = curr->next->value;
  curr->next = curr->next->next;
  return result;
}

bool list_is_in(list_t *l, elem value) {
  node_t* curr = l->head;
  while (curr != NULL) {
    if (curr->value == value) {
      return true;
    }
    curr = curr->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if ((index < 0) || (list_length(l) <= index)) {
    return -1;
  }
  int curr_index = 0;
  node_t* curr = l->head;
  while (curr_index+1 != index) {
    curr_index += 1;
    curr = curr->next;
  }
  return curr->next->value;
}

int list_get_index_of(list_t *l, elem value) {
  node_t* curr = l->head;
  int curr_index = 0;
  while (curr != NULL) {
    if (curr->value == value) {
      return curr_index;
    }
    curr = curr->next;
    curr_index += 1;
  }
  return -1;
}