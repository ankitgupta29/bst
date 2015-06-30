#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include <stdlib.h>

#define MAX_CHAR (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct trie_node trie_node_t;
typedef struct trie trie_t;

struct trie_node
{
    int value;
    trie_node_t *child[MAX_CHAR];
};

struct trie
{
    trie_node_t *root;
    int count; // no of child it has
};

trie_node_t* get_node()
{
       trie_node_t *pnode = NULL;
       pnode =(trie_node_t*)malloc(sizeof(trie_node_t));

       if (pnode)
       {
                int i;
                pnode->value = 0;
                for (i = 0; i < MAX_CHAR; i++)
                        pnode->child[i] = NULL;
       }
       return pnode;
}

void initialize_trie(trie_t *ptrie)
{
        ptrie->root = get_node();
        ptrie->count = 0;
}

void insert(trie_t *ptrie, char str[])
{

    int len = strlen(str);
    int level;
    ptrie->count++;
    trie_node_t *piter = ptrie->root;

    for (level = 0; level < len; level++)
    {
        int index = CHAR_TO_INDEX(str[level]);
        if (!piter->child[index])
        {
            piter->child[index] = get_node();
        }
        piter = piter->child[index];
    }

    /* mark as a leaf node */
    piter->value  = ptrie->count;
}

int search(trie_t *ptrie, char str[])
{
    int level, index;
    trie_node_t *piter = ptrie->root;
    int len = strlen(str);

    for(level = 0; level < len; level++)
    {
        int index = CHAR_TO_INDEX(str[level]);
        if (!piter->child[index])
                return 0;
        else {
            piter = piter->child[index];
        }
    }

    /* check if piter exist and it marked as a leaf node before */
    return (piter && piter->value);
}

int main()
{
        trie_t trie;
        initialize_trie(&trie);
        int size = 0;
        char *str[] = {"the", "a", "there", "answer", "any", "big", "bye", "their"};

        while(str[size] != '\0') { size++; }

        int i;
        for (i = 0; i < size; i++)
        {
            insert(&trie, str[i]);
        }

        printf("%s: %d\n", "there", search(&trie, "there"));
        printf("%s: %d\n", "thereee", search(&trie, "thereee"));
        printf("%s: %d\n", "any", search(&trie, "any"));
        printf("%s: %d\n", "anyy", search(&trie, "anyy"));

        return 0;
}
