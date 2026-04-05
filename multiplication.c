/*
 Description:
 This function multiplies two large integers using the standard long multiplication method and stores
 the result in a linked list.
*/

#include "apc.h"


int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	Dlist *ophead1 = NULL, *optail1 = NULL; // To store cumulative result of multiplication

	Dlist *ophead2 = NULL, *optail2 = NULL; // To store current partial multiplication result

	Dlist *reshead = NULL, *restail = NULL; // Temporary list for addition result

	Dlist *t2 = *tail2; // Start from least significant digit of operand2

	// used to append zeros for place shifting
	int count = 0;

	// multiplication by zero check
    if (*head2 == NULL ||((*head2)->data == 0 && (*head2)->next == NULL))
    {
        printf("Error: Multiplication by zero\n");
		exit (1);
    }

	// Outer loop – for each digit of operand2
	while (t2 != NULL)
	{
		ophead2 = optail2 = NULL; // Reset partial result list

		// Add required number of trailing zeros (10^count shift)
		for(int i = 0; i < count; i++)
		{
			insert_at_last(&ophead2, &optail2, 0);
		}

		// Start from least significant digit of operand1
		Dlist *t1 = *tail1;
		int carry = 0;

		// Inner loop – multiply one digit of operand2 with full operand1
		while (t1 != NULL)
		{
			int prod = (t1->data * t2->data) + carry;

			carry = prod / 10; //calculate carry

			int digit = prod % 10; //store single digit

			// Insert digit at front (MSD side)
			insert_first(&ophead2, &optail2, digit);

			t1 = t1 -> prev; // move to next digit of operand1
		}

		// If carry remains, insert it at front
		if(carry)
			insert_first(&ophead2, &optail2, carry);

		// If this is the first partial result, copy directly
		if(ophead1 == NULL)
		{
			ophead1 = ophead2;
			optail1 = optail2;
		}
		else
		{
			// Otherwise add previous result with new partial result
			reshead = NULL;
			restail = NULL;

			addition(&ophead1, &optail1, &ophead2, &optail2, &reshead, &restail);

			// Free old partial lists
			free_list(&ophead1, &optail1);
			free_list(&ophead2, &optail2);

			// Store new accumulated result
			ophead1 = reshead;
			optail1 = restail;
		}


		t2 = t2 -> prev; // move to next digit of operand2
		count++; // increase place value shift
	}

	// Final result assigned to output pointers
	*headR = ophead1;
	*tailR = optail1;

	return SUCCESS;
}