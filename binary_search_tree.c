#include<stdio.h>
#include<malloc.h>

typedef struct node* nodeptr;

struct node
{
	int data;
	nodeptr left;
	nodeptr right;
	nodeptr parent;
};

nodeptr add_node(struct node *head, int value)
{
	if (head == NULL)
	{
		head = malloc(sizeof(nodeptr));
		head->left = head->right = NULL;
		head->data = value;
		head->parent = head;
		return head;
	}
	
	nodeptr current = head;	
	nodeptr temp = malloc(sizeof(nodeptr));
	temp->left = temp->right = NULL;
	temp->data = value;
	temp->parent = current;
	
	while (current)
	{
		if (current->data == value) { 
			printf("Node with Value: %d already present in tree\n", value);
			break;
		}

		if (value > current->data) {
			if (current->right == NULL) {
				current->right = temp;
				//temp->parent = current;
				break;
			}
			else {
				current = current->right;
			}
		}
		else {
			if (current->left ==  NULL) {
				current->left = temp;
				//temp->parent = current;
				break;
			}
			else
				current = current->left;
		}
	}
	printf("Node Added: %d Parent: %d\n", temp->data, current->data);
	return head;
}

void print_inorder(nodeptr head)
{
	if (!head)
		return;
	print_inorder(head->left);
	printf("%d ", head->data);		
	print_inorder(head->right);
}

void print_preorder(nodeptr head)
{
	if (!head)
		return;
	printf("%d ", head->data);		
	print_preorder(head->left);
	print_preorder(head->right);
}


void print_postorder(nodeptr head)
{
	if (!head)
		return;
	print_postorder(head->left);
	print_postorder(head->right);
	printf("%d ", head->data);		
}

nodeptr search_node(nodeptr head, int value)
{
	if (head == NULL)
                return head;
        nodeptr current = head;
	printf("Node Parent head: %p %p %d\n", current->parent, head->parent, head->data);

        while (current)
        {
                if (current->data == value) {
                        printf("Node with Value: %d Found\n", value);
			printf("Node Parent: %d\n", current->parent->data);
			return current;
                }
                if (value > current->data)
                         current = current->right;
                else
                         current = current->left;
	}
	return NULL;
}

void delete_node(nodeptr head, int value)
{
	printf("DELETING NODE\n");
	if (!head) {
		printf("Head is NULL\n");
		return;
	}
	
	nodeptr current = search_node(head, value);
	if(!current) {
		printf("Node with value: %d not present in tree\n", value);
		return;
	}
	nodeptr parent = current->parent;
	printf("DELETING NODE: %d\n", current->data);
	printf("current: %d parent: %d\n", current->data, current->parent->data);
	
	/* if both childs of current are null */
	if (current->left == NULL && current->right == NULL)
	{
		printf("HERE\n");
		if (parent->right == current)
			parent->right = NULL;
		else
			parent->left = NULL;
		free(current);
		return;
	}
	
	/* if one of the child is NULL */
	if (parent->right == current)
	{
		if (current->left == NULL)
			parent->right = current->right;
		else
			parent->right = current->left;
		free(current);
		return;
	}
	else
	{
		if (current->left == NULL)
			parent->left = current->right;
		else
		{
			printf("Should come here\n");
			parent->left = current->left;
		}
		free(current);
		return;
	}	
	
}

nodeptr predecessor(nodeptr head, int value)
{
	if (!head)
		return NULL;
	nodeptr current = head;
	nodeptr temp = search_node(current, value);
	nodeptr parent = temp->parent;
	if (!temp)
		return NULL;
	if (temp->left) {
		current = temp->left;
		while(current->right)
			current = current->right;
		return current;
	}
	else {
		return parent;
	}
}

nodeptr successor(nodeptr head, int value)
{
        if (!head)
                return NULL;
        nodeptr current = head;
        nodeptr parent = head->parent;
	nodeptr parenti;
        nodeptr temp = search_node(current, value);
	parent = temp->parent;
        if (!temp)
                return NULL;
        if (temp->right) {
                current = temp->right;
                while(current->left)
                        current = current->left;
                return current;
        }
        else {
                while(temp != parent->left) {
			temp = parent;
			parent = parent->parent;
		}
		return parent;
	}
}


int main()
{
	nodeptr head = NULL;
	nodeptr new = NULL;
	head = add_node(head, 8);
	head = add_node(head, 15);
	head = add_node(head, 3);
	head = add_node(head, 6);
	head = add_node(head, 2);
	head = add_node(head, 10);
	nodeptr current = head;
	print_preorder(current);
	printf("\n");
	print_inorder(current);
	printf("\n");
	print_postorder(current);
	printf("\n");
	nodeptr temp = head;
	
	delete_node(temp, 15);
	print_inorder(temp);
	printf("\n");
	new = add_node(head, 15);
	new = add_node(head, 9);
	print_inorder(temp);
	return 0;
}

