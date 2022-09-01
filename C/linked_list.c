#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL, *last = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf ("%d ", p->data);
        p = p->next;
    }
}

struct Node* Create (int A[], int n)
{   
    // Create list head
    int i;
    struct Node *t, *last;
    head = (struct Node *) malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;

    // Linking List
    for (i = 1; i < n; i++)
    {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    
    printf("\nLinked List: ");
    Display(head);
    return head;
}

struct Node* Merge(struct Node *first, struct Node *second)
{
    struct Node *result = NULL;
    
    if (first->data < second->data)
    {
        result = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        result = last = second;
        second = second->next;
        last->next = NULL;
    }
    
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    
    if (first != NULL)
        last->next = first;
    else
        last->next = second;

    return result;
}

struct Node* MergeKList(struct Node** listas, int listSize){
    struct Node *result = NULL;

    if (listSize < 2){
        return listas[0];
    }

    int count = 1;
    while (count < listSize){
        result = Merge(listas[count-1],listas[count]);
        count++;
    }
    return result;  
}

int main()
{
    struct Node *linked_Result;
    
    int A[] = {1, 3, 8};
    int B[] = {1, 3, 6};
    int C[] = {8, 9};

    struct Node* listas[] = {Create(A, 3), Create(B, 3), Create(C, 2)};
    linked_Result = MergeKList(listas, 3);
    
    printf ("\n\nMerged Linked List: \n");
    Display (linked_Result);
    system("pause");
    return 0;
}