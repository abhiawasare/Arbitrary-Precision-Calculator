/*
 Description:
 This function adds two large integers represented
 as doubly linked lists and stores the result in
 another linked list.
*/

#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	//Start from the last node of both numbers
	Dlist *t1 = *tail1;
	Dlist *t2 = *tail2;
	int carry = 0; //to store carry while addition
	
	// addition by zero check
    if (*head2 == NULL ||((*head2)->data == 0 && (*head2)->next == NULL))
    {
        printf("Error: Addition by zero\n");
		exit (1);
    }

	while(t1 != NULL || t2 != NULL || carry) //Loop until both lists are finished and no carry remains 
	{

		int d1 = (t1) ? t1->data : 0; // If t1 is not NULL, take its digit otherwise take 0

        int d2 = (t2) ? t2->data : 0; // If t2 is not NULL, take its digit otherwise take 0

		int sum = d1 + d2 + carry; //Add both digits and carry

		carry = sum / 10; //calulate new carry

		int digit = sum % 10; //current digit to store in result list

		// Insert this digit at the beginning of result list
        // because we are adding from LSB to MSB
		insert_first(headR, tailR, digit);

		if(t1) //move to previous node of list1 if exists
		t1 = t1->prev;
		if(t2) //move to previous node of list1 if exists
		t2 = t2->prev;
	}
	return SUCCESS;
}
