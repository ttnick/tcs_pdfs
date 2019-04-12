#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adlist.h"

node* construct_node(int val) {
	node* node;

	if ((node = malloc(sizeof(*node))) == NULL) {
		return NULL;
	}

	node->data = val;
	node->pred = node;
	node->succ = node;

	return node;
}

adlist* construct_adlist() {
	adlist* list;

	if ((list = malloc(sizeof(*list))) == NULL) {
		return NULL;
	}

	node* head = construct_node(-1);
	list->head = head;

	return list;
}

void append_node(node* node1, node* node2) {
	node1->succ->pred = node2;
	node2->succ = node1->succ;
	node1->succ = node2;
	node2->pred = node1;
}

void append_adlist(adlist* list, node* node) {
	append_node(list->head->pred, node);
}

void delete_node(node* node) {
	node->pred->succ = node->succ;
	node->succ->pred = node->pred;

	free(node);
}

void delete_adlist(adlist* list) {
	node* next;
	node* node = list->head->succ;
	while (node != list->head) {
		next = node->succ;
		delete_node(node);
		node = next;
	}
	delete_node(node);
	free(list);	
}

void print_list(adlist* list) {
	printf("[");
	node* node = list->head;
	do {
		printf("%d ", node->data);
		node = node->succ;
	} while (node != (list->head));
	printf("\b]\n");
}

int length(adlist* list) {
	int len = 0;
	node* node = list->head;
	do {
		len++;
		node = node->succ;
	} while (node != (list->head));
	return len;
}

void concat(adlist* list1, adlist* list2) {
	if (list2->head->succ != list2->head) {
		list1->head->pred->succ = list2->head->succ;
		list2->head->succ->pred = list1->head->pred;
		list2->head->pred->succ = list1->head;
		list1->head->pred = list2->head->pred;
	}
	free(list2->head);
	free(list2);
}

int main(int argc, char** argv) {
	adlist* list1 = construct_adlist();
	adlist* list2 = construct_adlist();
	adlist** list = &list1;

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "c")) {
			node* node = construct_node(atoi(argv[i]));
			append_adlist(*list, node);
		} else {
			list = &list2;
		}
	}

	printf("List 1:\n");
	print_list(list1);
	printf("List 2:\n");
	print_list(list2);
	printf("concatenate...");
	concat(list1, list2);
	printf("done\n");
	printf("List 1:\n");
	print_list(list1);

	delete_adlist(list1);

	return 0;
}

