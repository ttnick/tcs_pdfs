#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

int max(int a, int b) {
	return (a >= b) ? a : b;
}

Node* construct_node(int val) {
	Node* node;

	if ((node = malloc(sizeof(*node))) == NULL) {
		return NULL;
	}

	node->data = val;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;

	return node;
}

Node* rotate_right(Node* node) {
	Node* new_root;
	Node* tree2;
	new_root = node->left;
	tree2 = new_root->right;

	// rotation
	new_root->right = node;
	node->left = tree2;

	// update heights
	node->height = 1 + max(node->left->height, node->right->height);
	new_root->height = 1 + max(new_root->left->height, new_root->right->height);

	return new_root;
}

Node* rotate_left(Node* node) {
	Node* new_root;
	Node* tree2;
	new_root = node->right;
	tree2 = new_root->left;

	// rotation
	new_root = node;
	node->right = tree2;

	// update heights
	node->height = 1 + max(node->left->height, node->right->height);
	new_root->height = 1 + max(new_root->left->height, new_root->right->height);

	return new_root;
}

int get_balance(Node* node) {
	if (node == NULL) {
		return 0;
	}
	return (node->left->height - node->right->height);
}

Node* insert(Node* node, int key) {
	int b;

	// first perform normal BST insert
	if (node == NULL) {
		return construct_node(key);
	}

	if (key < node->data) {
		node->left = insert(node->left, key);
	} else if (key > node->data) {
		node->right = insert(node->right, key);
	} else {
		// no duplicates
		return node;
	}

	// update height of this node
	node->height = 1 + max(node->left->height, node->right->height);

	// balancing if necessary
	b = get_balance(node);

	if (b > 1 && key < node->left->data) {
		return rotate_right(node);
	} else if (b < -1 && key > node->right->data) {
		return rotate_left(node);
	} else if (b > 1 && key > node->left->data) {
		node->left = rotate_left(node->left);
		return rotate_right(node);
	} else if (b < -1 && key < node->right->data) {
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}	

	return node;
}

void print_tree(Node* node, int space) {
	if (node != NULL) {
		space += 10;

		print_tree(node->right, space);

		printf("\n");
		for (int i = 10; i < space; i++) {
			printf(" ");
		}
		printf("%d\n", node->data);

		print_tree(node->left, space);
	}
}

int main(int argc, char** argv) {
	Node* root = NULL;

	root = insert(root, 1);
	print_tree(root, 0);
	root = insert(root, 2);
	print_tree(root, 0);
	root = insert(root, 3);
	print_tree(root, 0);
	root = insert(root, 4);
	print_tree(root, 0);
	root = insert(root, 5);
	print_tree(root, 0);
	root = insert(root, 6);
	print_tree(root, 0);
	root = insert(root, 7);
	print_tree(root, 0);
	root = insert(root, 8);
	print_tree(root, 0);
	return 0;
}
