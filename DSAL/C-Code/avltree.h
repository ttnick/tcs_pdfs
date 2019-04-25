/**
 * struct node
 * avl tree node
 */
typedef struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	int height;
} Node;

/**
 * max function
 * @param a		first number
 * @param b		second number
 * @returns		maximum
 */
int max(int, int);

/**
 * node constructor
 * @param val	node data
 * @returns		node
 */
Node* construct_node(int);

/**
 * right rotation
 * @param node	current root
 * @returns		new root
 */
Node* rotate_right(Node*);

/**
 * left rotation
 * @param node	current root
 * @returns		new root
 */
Node* rotate_left(Node*);

/**
 * get balance value of a node
 * how much longer is the left subtree compared to the right subtree?
 * @param node	root node
 * @returns int	balance value
 */
int get_balance(Node*);

/**
 * insert node to given node
 * @param node		root node
 * @param key		node data to be inserted
 * @returns			new root
 */
Node* insert(Node*, int);

/**
 * print tree
 * @param node		root node
 * @param space		how much space to next level
 */
void print_tree(Node*, int);
