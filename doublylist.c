#include<stdio.h>
#include<malloc.h>

typedef struct node* nodeptr;

struct node {
    nodeptr  prev;
    nodeptr next;
    int data;
};

//typedef struct node* nodeptr;

nodeptr get_node(int val)
{
    nodeptr node = (nodeptr)malloc(sizeof(struct node));
    node->prev =  node->next = NULL;
    node->data = val;
    return node;
}

void init_list(nodeptr *head, int val)
{
    *head = get_node(val);
}

void insert_sorted(nodeptr *head, int val)
{
    nodeptr curr = *head;
    nodeptr prev = NULL;
    if (!curr) {
        init_list(head, val);
        return;
    }

    nodeptr new = get_node(val);

    while(curr && curr->data < val)
    {
        prev = curr;
        curr = curr->next;

    }

    if (!prev)
    {
        new->next = curr;
        curr->prev = new;
        *head = new;
    }
    else
    {
        new->next = curr;
        prev->next = new;
        new->prev = prev;

        if (curr)
                curr->prev = new;
    }

}

void print_list(nodeptr head)
{
    nodeptr curr = head;

    while(curr) {
        printf("%d ->", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main()
{
    nodeptr head =  NULL;
    insert_sorted(&head, 2);
    insert_sorted(&head, 3);
    insert_sorted(&head, 5);
    insert_sorted(&head, 7);
    print_list(head);
    insert_sorted(&head, 1);

    print_list(head);
    insert_sorted(&head, 6);
    print_list(head);
    insert_sorted(&head, 9);
    print_list(head);
}
