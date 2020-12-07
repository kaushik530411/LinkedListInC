#include <stdio.h>
#include <assert.h>

#include "list.h"
void initialize(list_t* l) {
  list_add_to_back(l, 2);
  list_add_to_back(l, 11);
  list_add_to_back(l, 16);
  list_add_to_back(l, 17);
}

void test_basics() {
  printf("First Test run \n");
  list_t* list_1 = list_alloc();
  initialize(list_1);
  list_print(list_1);
  assert(list_length(list_1) == 4);
	list_remove_from_back(list_1);
	list_print(list_1);
  assert(list_length(list_1) == 3);
  list_free(list_1);
  printf("Basic tests passed. \n");
}

void test_add_remove_front() {
	printf("Second Test run \n");
  list_t* list_1 = list_alloc();
	list_add_to_front(list_1, 1);
	initialize(list_1);
  list_print(list_1);
  assert(list_length(list_1) == 5);
	list_remove_from_front(list_1);
  list_print(list_1);
  assert(list_length(list_1) == 4);
  list_free(list_1);
  printf("Test two passed. \n");
}

void test_add_remove_specific_index() {
	printf("Third Test run \n");
  list_t* list_1 = list_alloc();
	initialize(list_1);
	list_add_at_index(list_1, 20, 1);
  list_print(list_1);
  assert(list_length(list_1) == 5);
	
	list_remove_at_index(list_1, -10);
  list_remove_at_index(list_1, 10);
  list_remove_at_index(list_1, 1);
  list_print(list_1);
  assert(list_length(list_1) == 4);
  list_free(list_1);
  printf("Test three passed. \n");
}

void test_element_exists() {
	printf("Fourth Test run \n");
  list_t* list_1 = list_alloc();
	initialize(list_1);
	assert(list_is_in(list_1, 15) == false);
  assert(list_is_in(list_1, 16) == true);
	list_free(list_1);
  printf("Test four passed. \n");
}

void test_get_element_sepecific_index() {
	printf("Fifth Test run \n");
	list_t* list_1 = list_alloc();
	initialize(list_1);
	assert(list_get_elem_at(list_1, 1) == 11);
  assert(list_get_elem_at(list_1, 10) == -1);
  assert(list_get_elem_at(list_1, -10) == -1);
	printf("Test five passed. \n");
}

void test_find_first_occurence() {
  printf("Sixth Test run \n");
	list_t* list_1 = list_alloc();
	initialize(list_1);
  assert(list_get_index_of(list_1, 11) == 1);
  assert(list_get_index_of(list_1, 51) == -1);
  list_free(list_1);
  printf("Test six passed. \n");
}
int main() {
  printf("Tests for linked list implementation\n");
  test_basics();
	test_add_remove_front();
	test_add_remove_specific_index();
	test_element_exists();
	test_get_element_sepecific_index();
  test_find_first_occurence();
  printf("All tests for linked list implementation PASSED.\n");
  return 0;
}