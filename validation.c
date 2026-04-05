/*
 Description:
 This function validates the command line input. It checks whether the correct number of arguments,
 valid operator, and valid numeric operands are provided.
*/

#include "apc.h"

#include <ctype.h>
#include <string.h>

int validation( int argc, char *argv[])
{
    //Check number of command line arguments
    if(argc != 4)
    {
         printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    int i;
    //operand 1 validation
    
    for(i = 0; argv[1][i] != '\0'; i++)
    {
        //Allow '-' only at first position for negative number
        if(i == 0 && argv[1][i] == '-') 
            continue;

        //All other characters must be digits
        else if(!isdigit(argv[1][i]))
        {
            printf("Error: Operand 1 must contain only digits\n");
            return FAILURE;
        }
    }

    //operator validation

    //operator must be exactly one character
    if (strlen(argv[2]) != 1)
    {
        printf("Error: Operator must be a single character\n");
        return FAILURE;
    }

    char op = argv[2][0];
    if(!(op == '+' || op == '-' || op == 'x' || op == '/' || op == '%')) //operator must be +, -, *, /, %
    {
        printf("Error: Invalid operator\n");
        return FAILURE;
    }

    //operand 2 validation

        for(i = 0; argv[3][i] != '\0'; i++)
    {
        if(i == 0 && argv[3][i] == '-')
           continue;
        else if(!isdigit(argv[3][i]))
        {
            printf("Error: Operand 2 must contain only digits\n");
            return FAILURE;
        }
    }
    return SUCCESS;
}