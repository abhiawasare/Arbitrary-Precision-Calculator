/*
 Description:
 This function traverses the linked list from head to tail and prints each digit to display the complete number.
*/

#include "apc.h"
int print_list(Dlist *head)
{
    //If list is empty
    if(head == NULL)
    {
        printf(" List is Empty ");
        return FAILURE;
    }

    
    //Traverse list from head to tail
    while(head != NULL)
    {
        printf("%d",head->data); //print data of each node
        head = head->next; //Move to next node
    }
    
    return SUCCESS;
}