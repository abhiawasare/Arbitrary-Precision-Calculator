/*
 Description:
 This function converts a numeric string into a oubly linked list where each node stores one digit.
*/

#include "apc.h"


int str_to_list(char *str, Dlist **head, Dlist **tail)
{   
    int i = 0;

    //Traverse each character of the string
    while(str[i] != '\0')
    {
    //Create new node for each digit
    Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));
    if(newnode == NULL)
    {
        return FAILURE;
    }

    //Convert character digit to integer
    newnode->data = str[i] - '0';

    //Initialize links
    newnode->next = NULL;
    newnode->prev = NULL;

    //If list is empty, newnode becomes head and tail
    if(*head == NULL)
    {
        *head = *tail = newnode;
    }
    else
    {
        //Insert at last position
        newnode->prev = *tail;
        (*tail)->next = newnode;
        *tail = newnode;
    }
    
        i++;
    }
    return SUCCESS;
}