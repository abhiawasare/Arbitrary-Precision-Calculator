/*
 Description:
 This function performs division of two large integers using long division with repeated subtraction and
 returns the quotient.
*/

#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{	
	// Pointer to traverse dividend (operand1) from MSB side
	Dlist *temp = *head1;

	// Remainder list – stores current partial dividend
	Dlist *remH = NULL, *remT = NULL;

	// divide by zero check
    if (*head2 == NULL ||((*head2)->data == 0 && (*head2)->next == NULL))
    {
        printf("Error: Divide by zero\n");
		exit (1);
    }

	// Process each digit of dividend one by one
	while(temp != NULL)
	{
		// Bring down next digit to remainder
        // Equivalent to: rem = rem * 10 + next_digit
		insert_at_last(&remH, &remT, temp->data);
		
		// Remove any leading zeros in remainder
		remove_leading_zeros(&remH, &remT);

		// This will store current quotient digit
		int count = 0;


		while (compare_list(remH, *head2) >= 0)
		{
			// To store result of subtraction
			Dlist *resultH = NULL, *resultT = NULL;

			// rem = rem - divisor
			subtraction(&remH, &remT, head2, tail2, &resultH, &resultT);

			// Free old remainder list
			free_list(&remH, &remT);

			// Update remainder with new result
			remH = resultH;
			remT = resultT;

			resultH = resultT = NULL;

			// Increase quotient digit
			count++;
		}
		
		// Store quotient digit in result list
		insert_at_last(headR, tailR, count);

		// Move to next digit of dividend
		temp = temp->next;
	
	}
	
	// Remove leading zeros from final quotient
	remove_leading_zeros(headR, tailR);

	return SUCCESS;
}
