#include <stdio.h>
#include "bst_for_arrange_number.c"

/*
 * Input: arr[] = {5, 3, 5, 1, 3, 3}
 * Output:        {5, 5, 3, 3, 3, 1}
 * Logic: add numbers first in tree and then increment
 * count there. and at last remove them from tree and print
 * to array and delete node from tree.
 * Complexity: O(nlogn)
 */

int main()
{
	nodeptr head = NULL;
	nodeptr new = NULL;

    //int a[] = {5, 3, 5, 1, 3, 3};
    int a[] =  {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
    int i,j, q = 0;
    int len = sizeof(a)/ sizeof(a[0]);
    int temp_arr[len];
    for (i = 0; i < len; i++)
        	head = add_node(head, a[i]);
	print_inorder(head);
    nodeptr node, parent, temp;
    for (i = 0; i < len; i++)
    {
        temp = head;
        node = search_node(temp, a[i], &parent);
        if (node){
            for (j = 0; j < node->count; j++){
                    temp_arr[q] = node->data;
                    q++;
                }
                head = delete_node(temp, node->data);
                if (!head) {
                     printf("Tree is EMPTY NOW\n");
                     break;
                }
        }
    }
    for(i= 0; i < len; i++)
            printf("%d ", temp_arr[i]);

}
