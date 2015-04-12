#include<stdio.h>
#include<malloc.h>

typedef struct node* nodeptr;

struct node
{
	int data;
	nodeptr left;
	nodeptr right;
};

nodeptr add_node(struct node *head, int value)
{
	if (head == NULL)
	{
		head = malloc(sizeof(nodeptr));
		head->left = head->right = NULL;
		head->data = value;
		return head;
	}

	nodeptr current = head;
	nodeptr temp = malloc(sizeof(nodeptr));
	temp->left = temp->right = NULL;
	temp->data = value;

	while (current)
	{
		if (current->data == value) {
			printf("Node with Value: %d already present in tree\n", value);
			break;
		}

		if (value > current->data) {
			if (current->right == NULL) {
				current->right = temp;
				break;
			}
			else {
				current = current->right;
			}
		}
		else {
			if (current->left ==  NULL) {
				current->left = temp;
				break;
			}
			else
				current = current->left;
		}
	}
	printf("Node Added: %d\n", temp->data);
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

nodeptr search_node(nodeptr head, int value, struct node **parent)
{
	if (head == NULL)
                return head;
        nodeptr current = head;

        printf("search: %d HEAD: %d \n",value,  head->data);
        while (current)
        {
                if (current->data == value) {
                        printf("Node with Value: %d Found\n", value);
             			return current;
                }
        		*parent = current;
                if (value > current->data)
                         current = current->right;
                else
                         current = current->left;
        }
	return NULL;
}

nodeptr maximum_left_subtree(nodeptr current, struct node **parent)
{
    if (current->left) {
        *parent = current;
        current = current->left;
        while(current->right){
                *parent = current;
                current = current->right;
        }
        return current;
    }
    else
        return NULL;
}

nodeptr minimum_right_subtree(nodeptr current, struct node **parent)
{
    if (current->right) {
        *parent = current;
        current = current->right;
        while(current->left){
                *parent = current;
                current = current->left;
        }
        return current;
    }
    else
        return NULL;
}

void delete_node(nodeptr head, int value)
{
	if (!head) {
		printf("Head is NULL\n");
		return;
	}
	nodeptr parent = NULL;
	nodeptr current = search_node(head, value, &parent);
	if(!current) {
		printf("Node with value: %d not present in tree\n", value);
		return;
	}
	printf("DELETING NODE: %d\n", current->data);

    if (current->left && current->right) {
        /* if none of the child is null */
        nodeptr temp = maximum_left_subtree(current, &parent);
        if (!temp)
                temp = minimum_right_subtree(current, &parent);
        int var = temp->data;
        temp->data = current->data;
        current->data = var;
        current = temp;

    }
	/* if both childs of current are null */
	if (current->left == NULL && current->right == NULL)
	{
		if (parent->right == current)
			parent->right = NULL;
		else
			parent->left = NULL;
		free(current);
		return;
	}

    else {
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
                parent->left = current->left;
            }
            free(current);
            return;
        }
    }
}

nodeptr predecessor(nodeptr head, int value)
{
	if (!head)
		return NULL;
	nodeptr current = head;
	nodeptr pred = NULL;

	while(current && current->data != value)
	{
		if (current->data > value) {
			current = current->left;
		}
		else {
			pred = current;
			current = current->right;
		}
	}

	if (current->data == value) {
		if (current->left) {
			pred = current->left;
			while(pred->right)
				pred = pred->right;
		}
	}
	return pred;
}

nodeptr successor(nodeptr head, int value)
{
        if (!head)
                return NULL;
        nodeptr current = head;
        nodeptr succ = NULL;

        while(current && current->data != value)
        {
                if (current->data < value) {
                        current = current->right;
                }
                else {
                        succ = current;
                        current = current->left;
                }
        }

        if (current->data == value) {
                if (current->right) {
			succ = current->right;
                        while(succ->left)
                                succ = succ->left;
                }
        }
        return succ;
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
	nodeptr parent = NULL;
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
	new = add_node(head, 7);
	new = add_node(head, 12);
	print_inorder(temp);
	printf("\n");
	int p = 12;
	int q = 8;
	temp = predecessor(head, p);
	if (!temp)
		printf("Predecessor of %d is not present\n",p);
	else
		printf("Predecessor of %d is %d\n", p, temp->data);
	temp = predecessor(head, q);
	if (!temp)
		printf("Predecessor of %d is not present\n",q);
	else
		printf("Predecessor of %d is %d\n", q, temp->data);

	temp = successor(head, p);
	if (!temp)
		printf("Successor of %d is not present\n",p);
	else
		printf("Successor of %d is %d\n", p, temp->data);

	temp = successor(head, q);
	if (!temp)
		printf("Successor of %d is not present\n",q);
	else
		printf("Successor of %d is %d\n", q, temp->data);
    delete_node(head, 10);
	print_inorder(head);
	printf("\n");
    delete_node(head, 8);
	print_inorder(head);
	printf("\n");

	return 0;
}
