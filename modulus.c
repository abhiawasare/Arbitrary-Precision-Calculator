/*
 Description:
 This function calculates the remainder of division of two large integers using repeated subtraction.
*/

#include "apc.h"

int modulus(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	// modulus by zero check
    if (*head2 == NULL ||((*head2)->data == 0 && (*head2)->next == NULL))
    {
        printf("Error: Modulus by zero\n");
		exit (1);
    }

    // Pointer to traverse dividend (operand1) from MSB
    Dlist *temp = *head1;

    // These pointers store the current remainder list
    Dlist *remH = NULL, *remT = NULL;

    // Process each digit of operand1 one by one
    while (temp != NULL)
    {
        //bring down next digit to remainder
        // Equivalent to: rem = rem * 10 + next_digit
        insert_at_last(&remH, &remT, temp->data);

        while (remH != NULL && compare_list(remH, *head2) >= 0)
        {
            // Temporary list to store subtraction result
            Dlist *resultH = NULL, *resultT = NULL;

            
            // rem = rem - divisor
            subtraction(&remH, &remT, head2, tail2, &resultH, &resultT);

            // Free old remainder memory
            free_list(&remH, &remT);

            // Update remainder with new value
            remH = resultH;
            remT = resultT;

            resultH = resultT = NULL;

            // Remove leading zeros from remainder
            remove_leading_zeros(&remH, &remT);
            
        }
        // Remove leading zeros from remainder
        temp = temp->next;

        // Update final remainder pointers
        *headR = remH;
        *tailR = remT;

    }
        // Final cleanup of leading zeros
       remove_leading_zeros(headR, tailR);
        return SUCCESS;
}