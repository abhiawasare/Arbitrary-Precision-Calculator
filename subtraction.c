/*
 Description:
 This function subtracts the second large integer from the first one using digit-by-digit subtraction
 with borrow handling.
*/

#include "apc.h"


int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	// Start from least significant digits (tail side)
	Dlist *t1 = *tail1;  // minuend  (larger number)
	Dlist *t2 = *tail2; // subtrahend (smaller number)

	int borrow = 0; //borrow flag

	// subtraction by zero check
    if (*head2 == NULL ||((*head2)->data == 0 && (*head2)->next == NULL))
    {
        printf("Error: Subtraction by zero\n");
		exit (1);
    }

	// Process until first number ends
	while (t1 != NULL)
	{
		// Take digit from list1 and subtract previous borrow
		int d1 = t1->data - borrow;

		// If list2 still has digits take it, else take 0
		int d2 = (t2) ? t2->data : 0;

		//If d1 < d2 -> we need borrow from next digit
		if(d1 < d2)
		{
			d1 = d1 + 10; //take borrow
			borrow = 1; //set borrow for next iteration
		}else
			borrow = 0; //no borrow needed

		// Actual digit difference
		int diff = d1 - d2;

		// Insert this digit at the beginning of result list
        // because we are adding from LSB to MSB
		insert_first(headR, tailR, diff);

		if(t1) //move to previous node of list1 if exists
			t1 = t1->prev;
		if(t2) //move to previous node of list2 if exists
			t2 = t2->prev;
	}
	return SUCCESS;
}
