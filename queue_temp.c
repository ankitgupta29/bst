#include<stdio.h>
#include<malloc.h>

typedef struct node* nodeptr;
struct node {
    int data;
    nodeptr next;
};

nodeptr front;
nodeptr rear;

nodeptr new_node(int value)
{
        nodeptr new = malloc(sizeof(nodeptr));
        new->data = value;
        new->next = NULL;
        return new;
}

void count_display()
{
    nodeptr temp = rear;
    if (!temp){
        printf("Queue is empty, nothing to Display\n");
        return;
    }
    int count = 0;
    printf("Front is: %d Rear: %d\n", front->data, rear->data);
    while(temp) {
        count++;
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\nTotal element in queue: %d\n", count);
}

void push(int value)
{
    if (front == rear && front == NULL){
        front = new_node(value);
        rear = front;
        return;
    }

    nodeptr temp =  new_node(value);
    temp->next =  rear;
    rear = temp;
}

void pop()
{
        if (front == rear) {
            if(front == NULL)
            {
                    return;
            }
            else {
                nodeptr temp = front;
                printf("Pop value is: %d\n", front->data);
                front = rear = NULL;
                free(temp);
                return;
            }
        }
        nodeptr temp = rear;
        while (temp->next != front)
            temp = temp->next;
        printf("Pop value is: %d\n", front->data);
        temp->next = NULL;
        nodeptr save = front;
        front = temp;
        free(save);
}

int main()
{
        push(1);
        push(2);
        push(3);
        push(4);
        push(5);
        push(6);
        push(7);
        push(8);
        count_display();
        pop();
        pop();
        pop();
        pop();
        pop();
        count_display();
        pop();
        pop();
        pop();
        pop();
        pop();
        return 0;
}
