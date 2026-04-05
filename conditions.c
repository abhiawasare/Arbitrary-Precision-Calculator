#include "apc.h"

/*  -------------------------[ INSERT AT FIRST ]-------------------------  */
/*
 Description:
 This function inserts a new digit node at the beginning of the linked list.
*/

int insert_first(Dlist **headR, Dlist **tailR, int data)
{
    // Allocate memory for new node
    Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));
    if (newnode == NULL)
        return FAILURE;

    // Store digit in new node
    newnode->data = data;

    // Since this node becomes first, prev is always NULL
    newnode->prev = NULL;

    // Point new node's next to current head
    newnode->next = *headR;

    // If result list is empty
    if (*headR == NULL)
    {
        *headR = *tailR = newnode;
    }
    else
    {
        // Connect old head back to new node
        (*headR)->prev = newnode;

        // Update head to new node
        *headR = newnode;
    }

    return SUCCESS;
}

/*  -------------------------[ INSERT AT LAST ]-------------------------  */
/*
 Description:
 This function inserts a new digit node at the end of the linked list.
*/

int insert_at_last(Dlist **headR, Dlist **tailR, int data)
{
    
    // Allocate memory for new node
    Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));
    if (newnode == NULL)
        return FAILURE;

    // Store digit in new node
    newnode->data = data;

   //new node prev connect tail 
    newnode->prev = *tailR;

    // Point new node's next to NULL
    newnode->next = NULL;

    // If result list is empty
    if (*headR == NULL)
    {
        *headR = *tailR = newnode;
    }
    else
    {
        // Connect old tail next to new node
        (*tailR)->next = newnode;

        // Update tail to new node
        *tailR = newnode;
    }

    return SUCCESS;
}

/*  -------------------------[ FREE LIST ]-------------------------  */
/*
 Description:
 This function frees all nodes of a linked list and resets head and tail pointers to NULL.
*/

int free_list(Dlist **head, Dlist **tail)
{
    // If list is already empty
    if(*head == NULL)
    {
        return FAILURE;
    }

    // Start from the first node
    Dlist *temp = *head;

    // Traverse and free each node one by one
    while (temp != NULL)
    {
        *head = temp->next; // move head to next node
        free(temp); // free current node
        temp = (*head); // update temp to new head
    }

    // After freeing all nodes, set both head and tail to NULL
    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}

/*  -------------------------[ COMPARE LIST ]-------------------------  */
/*
 Description:
 This function compares two linked list numbers and returns whether the first number is greater than,
 equal to, or less than the second number.
*/

int compare_list(Dlist *head1, Dlist *head2)
{
    Dlist *t1 = head1;
    Dlist *t2 = head2;

    int len1 = 0;
    int len2 = 0;

    // count length of first number
    while(t1 != NULL)
    {
        len1++;
        t1 = t1 -> next;
    }

    // count length of second number
    while(t2 != NULL)
    {
        len2++;
        t2 = t2 -> next;
    }

    // if first number is bigger
    if(len1 > len2)
        return 1;
    
    // if second number is bigger
    if(len1 < len2)
        return -1;

    // if both lengths are equal -> compare digit by digit
    t1 = head1;
    t2 = head2;
    while(t1 != NULL && t2 != NULL)
    {
        if(t1->data > t2->data)
            return 1;

         if(t1->data < t2->data)
            return -1;


        t1 = t1 -> next;
        t2 = t2 -> next;
    }

    return SUCCESS;
}

/*  -------------------------[ REMOVE LEADING ZEROS ]-------------------------  */
/*
 Description:
 This function removes unnecessary leading zeros from the result linked list to maintain correct
 numerical representation.
*/

void remove_leading_zeros(Dlist **head, Dlist **tail)
{
    // delete all leading zeros except last digit
    while (*head && (*head)->data == 0 && (*head)->next != NULL)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    // if list becomes empty
    if (*head == NULL)
        *tail = NULL;
}