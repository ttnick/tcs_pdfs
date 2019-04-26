#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"

int max(int a, int b) {
	return (a >= b) ? a : b;
}

Node* construct_node(int val) {
	Node* node;
	node = (Node*) malloc(sizeof(Node));
	if (node == NULL) {
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
	node->height = 1 + max(get_height(node->left), get_height(node->right));
	new_root->height = 1 + max(get_height(new_root->left), get_height(new_root->right));

	return new_root;
}

Node* rotate_left(Node* node) {
	Node* new_root;
	Node* tree2;
	new_root = node->right;
	tree2 = new_root->left;

	// rotation
	new_root->left = node;
	node->right = tree2;

	// update heights
	node->height = 1 + max(get_height(node->left), get_height(node->right));
	new_root->height = 1 + max(get_height(new_root->left), get_height(new_root->right));

	return new_root;
}

int get_height(Node* node) {
	if (node == NULL) {
		return 0;
	}
	return node->height;
}

int get_balance(Node* node) {
	if (node == NULL) {
		return 0;
	}
	return (get_height(node->left) - get_height(node->right));
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
	node->height = 1 + max(get_height(node->left), get_height(node->right));

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
	if (space == 0) {
		printf("========================================================");
	}
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
