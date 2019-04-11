/**
 * struct node
 * list node
 */
typedef struct node
{
	int data;
	struct node* pred;
	struct node* succ;
} node;

/**
 * struct adlist
 * double linked list
 */
typedef struct adlist
{
	node* head;
} adlist;

/**
 * node constructor
 * @param val		node data
 * @returns			node
 */
node* construct_node(int val);

/**
 * adlist constructor
 * @returns			adlist
 */
adlist* construct_adlist();

/**
 * append node to another node (to the right)
 * @param node1		first node
 * @param node2		second node
 */
void append_node(node* node1, node* node2);

/**
 * append node to list (at the end)
 * @param list		list to append the node
 * @param node		node to be appended
 */
void append_adlist(adlist* list, node* node);

/**
 * delete node
 * @param node		node to be deleted
 */
void delete_node(node* node);

/**
 * delete adlist 
 * @param list		list to be deleted
 */
void delete_adlist(adlist* list);

/**
 * print list
 * @param list		list to be printed
 */
void print_adlist(adlist* list);

/**
 * get length of a list
 * @param list		list in question
 * @returns			length of list
 */
int lenght(adlist* list);

/**
 * concatenate two lists
 * @param list1		first list
 * @param list2		second list
 */
void concat(adlist* list1, adlist* list2);
