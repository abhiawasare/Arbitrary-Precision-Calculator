/*
 Name: Abhijit Awasare
 Description: This program works as a driver to perform arithmetic operations 
              on very large integers using doubly linked lists to store digits.

              It supports the following operations:
              + Addition
              - Subtraction
              x Multiplication
              / Division
              % Modulus

 Key Features:
 * Large Number Support: Uses doubly linked lists for digit-by-digit storage,
                         allowing calculations beyond built-in data types.
 * Signed Number Handling: Supports both positive and negative operands.
 * Input Checking: Validates operands and operators before processing.
 * Correct Output: Displays accurate results with proper sign.
 * Zero Safety: Handles cases where one or both numbers are zero.
*/

#include "apc.h"

int main(int argc, char *argv[])
{
    // Head and tail pointers for operand1, operand2 and result
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
	char option;
    int sign1 = 0, sign2 = 0, signR = 0;

    // Validate command line arguments
    if(validation(argc, argv) == FAILURE)
    {
        printf("INFO: Invalid Input\n");
        return FAILURE;
    }

    // Check if operand1 is negative
    if(argv[1][0] == '-')
    {
        sign1 = 1; // mark operand1 as negative
        argv[1]++; // skip '-' sign, point to actual digits
    }

    // Check if operand2 is negative
    if(argv[3][0] == '-')
    {
        sign2 = 1;
        argv[3]++;
    }

    // Convert operand1 string to doubly linked list
    str_to_list(argv[1], &head1, &tail1);

    // Convert operand2 string to doubly linked list
    str_to_list(argv[3], &head2, &tail2);

    // Print both operands
	printf("Print operand 1: ");
 
    if(sign1 == 1)
        printf("-");

	print_list(head1);
 

	printf("\nPrint operand 2: ");

    if(sign2 == 1)
        printf("-");

	print_list(head2);



    // Get operator character
    char operator = argv[2][0];

    // Compare magnitudes of operand1 and operand2
    int cmp = compare_list(head1, head2);

    // Perform operation based on operator
    switch (operator)
    {
    case '+':
            printf("\nINFO: Addition successful\n");
            // If both have same sign -> simple addition
            if (sign1 == sign2)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                signR = sign1;  // result sign same as operands
            }
            // If signs different -> subtraction
            else
            {
                if(cmp >= 0)
                {
                    subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    signR = sign1;  
                }
                else
                {
                    subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                    signR = sign2;
                }
            }
        break;

    case '-':
            
            printf("\nINFO: Subtraction successful\n");

            // If signs different -> convert to addition
            if (sign1 != sign2)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                signR = sign1;
            }
            // If signs same -> subtraction
            else
            {
                if(cmp >= 0)
                {
                    subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                    signR = sign1;
                }
                else
                {
                    subtraction(&head2,&tail2,&head1,&tail1,&headR,&tailR);
                    signR = !sign1; // reverse sign
                }
            }
        break;

    case 'x':

            printf("\nINFO: Multiplication successful\n");
            multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            signR = sign1 ^ sign2; //XOR logic for sign

        break;

    case '/':
        
        printf("\nINFO: Division successful\n");
        division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            signR = sign1 ^ sign2;
       
        break;

    case '%':
        
        printf("\nINFO: Modulus successful\n");
        modulus(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            signR = sign1;
      
        break;
    
    default:
        printf("\nINFO: Invalid operator \n");
        break;
    }

    printf("Print Result: ");

    // Remove unwanted zeros at the beginning of result
    remove_leading_zeros(&headR, &tailR);

    if (headR != NULL && headR->data == 0 && headR->next == NULL) //starting and endling value zero sign always postive
    {
        signR = 0;
    }

    if (signR == 1) // Print negative sign if result is negative
        printf("-");

	print_list(headR); // Print final result list

    printf("\n");
	return SUCCESS;
}
