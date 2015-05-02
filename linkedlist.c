#include<stdio.h>
#include<malloc.h>

typedef struct node* nodeptr;

struct node
{
	int data;
	nodeptr next;
};

nodeptr head;

void print_list()
{
	nodeptr save = head;
	while(head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
	head = save;
}

void add_node_at_last(int value)
{
	if (head == NULL) {
		head  = malloc(sizeof(nodeptr));
		head->data = value;
		head->next = NULL;
	}
	else {
		nodeptr current = head;
		while(current->next != NULL)
			current = current->next;
		nodeptr temp;
		temp  = malloc(sizeof(nodeptr));
		temp->data = value;
		current->next = temp;
		temp->next = NULL;
	}
}

void add_node_at_front(int value)
{
	if (head == NULL) {
		head  = malloc(sizeof(nodeptr));
		head->data = value;
		head->next = NULL;
	}
	else {
		nodeptr temp;
		temp  = malloc(sizeof(nodeptr));
		temp->data = value;
		temp->next = head;
		head = temp;  /* point head back to start */
	}
}

void add_node_in_between(int value, int position_data)
{
	if (head == NULL) {
		head  = malloc(sizeof(nodeptr));
		head->data = value;
		head->next = NULL;
	}
	else {
		nodeptr current = head;
		while(current)
		{
			if (current->data == position_data)
			{
				nodeptr temp;
				temp  = malloc(sizeof(nodeptr));
				temp->data = value;
				temp->next = current->next;
				current->next = temp;
				break;
			}
			current = current->next;
			if (current == NULL)
				printf("Node Value: %d not found\n", position_data);
		}
	}
}

void delete_node(int value)
{
	nodeptr current = head;
	nodeptr parent = head;

	if (head->data == value)
	{
		head = head->next;
		current->next = NULL;
		free(current);
		return;
	}
	while(current)
	{
		if (current->data == value)
		{
			parent->next = current->next;
			current->next = NULL;
			free(current);
			return;
		}
		else
		{
			parent =  current;
			current = current->next;
		}
	}
	printf("Node with value: %d not found in list\n", value);
}

int return_position(int value)
{
	nodeptr current = head;
	int i = 0;
	while(current)
	{
		i++;
		if (current->data == value)
			return i;
		else
			current = current->next;
	}
	return 0;
}

void reverse_list_recursive(struct node** head)
{
	nodeptr current = *head;
	nodeptr rest = current->next;
	if (current == NULL || rest == NULL)
		return;

	reverse_list_recursive(&rest);
	current->next->next = current;
	current->next = NULL;
	*head = rest;
}

void reverse_list_iterative(struct node** head)
{
	nodeptr previous = NULL;
	nodeptr next = NULL;
	nodeptr current = *head;

	while(current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}

/*
 * int main()
{
	printf("Hello, World\n");
	add_node_at_last(3);
	add_node_at_last(5);
	add_node_at_last(7);
	print_list();
	add_node_in_between(4,3);
	print_list();
	delete_node(3);
	print_list();
	add_node_at_front(1);
	print_list();
	add_node_at_last(8);
	print_list();
	delete_node(5);
	print_list();
	int find_position = 7;
	int ret = return_position(find_position);
	if (!ret)
		printf("Value %d not found\n", find_position);
	else
		printf("Postion of %d is : %d\n",find_position, ret);

	reverse_list_iterative(&head);
	print_list();
	reverse_list_recursive(&head);
	print_list();
	reverse_list_recursive(&head);
	print_list();
	reverse_list_iterative(&head);
	print_list();
}
*/
