#include<stdio.h>
#include<malloc.h>

typedef struct node* nodeptr;
struct node {
    int data;
    nodeptr next;
};

nodeptr new_node(int value)
{
        nodeptr new = malloc(sizeof(nodeptr));
        new->data = value;
        new->next = NULL;
        return new;
}

void count_display(nodeptr top)
{
    if (!top){
        printf("Stack is empty, nothing to POP\n");
        return;
    }
    int count = 0;
    printf("TOP is: %d\n", top->data);
    nodeptr temp = top;
    while(top) {
        count++;
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\nTotal element in Stack: %d\n", count);
}

nodeptr push(nodeptr top, int value)
{
    if (!top){
        top = new_node(value);
        return top;
    }
    nodeptr temp =  new_node(value);
    temp->next =  top;
    top = temp;
    return top;
}

nodeptr pop(nodeptr top)
{
        if (!top)
        {
            printf("Stack is empty, nothing to POP\n");
            return NULL;
        }
        nodeptr temp = top;
        top = top->next;
        printf("Pop data is: %d\n", temp->data);
        if (!top)
            printf("Stack is Empty now\n");
        free(temp);
        return top;
}

int main()
{
        nodeptr top = NULL;
        top = push(top, 5);
        top = push(top, 6);
        top = push(top, 7);
        top = push(top, 8);
        top = push(top, 9);
        top = push(top, 10);
        top = push(top, 11);
        count_display(top);
        top = pop(top);
        top = pop(top);
        top = pop(top);
        top = pop(top);
        top = pop(top);
        top = pop(top);
        top = pop(top);
        top = pop(top);
        count_display(top);
        return 0;
}
