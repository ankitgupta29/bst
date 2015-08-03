#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define MAX 10
#define Kth 3
struct node
{
    int v; //value
    int c; //count
};

typedef struct node node;
void print_node(node n[])
{
    int i;
    printf("\n======\n");
    for(i=0; i < MAX; i++)
        printf("%d => %d\n", n[i].v, n[i].c);
}
void swap(node *a, node *b)
{
    /* if two addresses are same then we have to check them */
    if (a == b)
        return;
    int v,c;
    printf("swap: a(%d:%d) b(%d:%d)\n", a->v,a->c, b->v,b->c);
    v= a->v; c= a->c;
    a->v=b->v; a->c = b->c;
    b->c=c; b->v=v;
}

int get_left(int i)
{
    return (2 * i + 1);
}

int get_right(int i)
{
    return (2 * i +  2);
}

void heapify(node arr[], int i)
{
   int left = get_left(i);
   int right = get_right(i);
   int largest = i;

   if (left < Kth && arr[left].c < arr[largest].c)
           largest = left;

   if (right < Kth && arr[right].c < arr[largest].c)
           largest = right;

   if (i != largest) {
           swap(arr + i, arr + largest);
           heapify(arr, largest);
   }
}

void build_heap(node a[], int k)
{
    int i;
    for (i = (k/2 -1); i >= 0; i--)
        heapify(a, i);
    print_node(a);
}

void topk(node a[], int k, int len)
{
    int i;
    for (i = k; i < MAX; i++)
    {
        printf("top: i: %d val: %d count: %d\n", i, a[i].v, a[i].c);
        if (a[0].c < a[i].c)
        {
            swap(a + 0, a + i);
            heapify(a, 0);
        }
    }
    print_node(a);
}

int main()
{

    int a[] = {4,2,1,4,4,5,6,3,4,1,2,8,5,3,9,4,3, 5, 5, 5, 5, 0};
    int len = sizeof(a)/sizeof(a[0]);
    int i,j;

    node *node_array = malloc(sizeof(node) * MAX);
    for (i = 0; i < MAX; i++) {
        node_array[i].v = i;
        node_array[i].c = 0;
    }
    for(i = 0; i < len; i++) {
        node_array[a[i]].c++;
    }
    print_node(node_array);

   // node heap[Kth] = {0,};
    build_heap(node_array, Kth);
    topk(node_array, Kth, len);
}
