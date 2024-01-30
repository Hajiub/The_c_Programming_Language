#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct tnode {
    int data;
    int count;
    struct tnode *left, *right;
}tnode;

tnode *addtree(tnode *p, int n, int *tc)
{
    if(p == NULL)
    {
        p = (tnode *)malloc(sizeof(tnode));
        assert(p != NULL);
        p->data = n;
        p->count = 1;
        p->left = p->right = NULL;
        (*tc)++;
    }
    else if(p->data == n)
    {
        p->count++;
    }
    else if (p->data > n)
    {
        p->left = addtree(p->left, n, tc);
    }
    else
        p->right = addtree(p->right, n, tc);
    return p; 
}

void populateNodesArray(tnode *p, tnode **NodesArray, int *index) {
    if (p != NULL) {
        populateNodesArray(p->left, NodesArray, index);
        NodesArray[(*index)++] = p;
        populateNodesArray(p->right, NodesArray, index);
    }
}

void treeprint(tnode *p)
{
    if (p != NULL)
    {
       treeprint(p->left);
       printf("%i:%i\n", p->data, p->count);
       treeprint(p->right);
    }
}

void treefree(tnode *p)
{
    if (p != NULL)
    {
        treefree(p->left);
        free(p);
        treefree(p->right);
    }
}

void swap(tnode **arr, int a, int b)
{
    tnode *temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partion(tnode **arr, int left, int right)
{
    int piv = arr[right]->count;
    int i, j;
    for (i = left - 1, j = left; j < right; j++)
    {
        if (arr[j]->count >= piv)
        {
            swap(arr, ++i, j);
        }
    }
    swap(arr, ++i, right);
    return i;
}

void quickSort(tnode **arr, int left, int right)
{
    if (left >= right)
        return;
    int piv = partion(arr, left, right);
    quickSort(arr, left, piv - 1);
    quickSort(arr, piv + 1, right);
}

int main(void)
{
    int array[] = {234, 34, 4, 87, 320, 343, 569, 1, 3, 7, 14, 14, 34, 234, 14, 14};
    size_t size = sizeof array / sizeof array[0];
    tnode *root = NULL;
    int treecount = 0;
    for (int i = 0; i < size; i++)
       root = addtree(root, array[i], &treecount);

    tnode **NodesArray = (tnode **)malloc(sizeof(tnode) * treecount);
    assert(NodesArray != NULL);

    int index = 0;
    populateNodesArray(root, NodesArray, &index);
    printf("Orignal: ");
    for(int i = 0; i < index; i++)
        printf("%i ", NodesArray[i]->count );
    putchar('\n');
    printf("Sorted: ");
    quickSort(NodesArray, 0, index - 1);
    for(int i = 0; i < index; i++)
       printf("%i ", NodesArray[i]->count );
    putchar('\n');
    treefree(root);
    free(NodesArray);
    return 0;
}
