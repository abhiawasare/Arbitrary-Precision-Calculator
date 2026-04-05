#ifndef APC_H
#define APC_H

#include <stdio.h>
#include<stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Validation */
int validation(int argc, char *argv[]);

/* Convert string to Doubly Linked list */
int str_to_list(char *str, Dlist **head, Dlist **tail);

/* Comapare Both list */
int compare_list(Dlist *head1, Dlist *head2);

/* remove zeros (remove Ans Starting Zero)*/
void remove_leading_zeros(Dlist **, Dlist **);

/* Print list */
int print_list(Dlist *head);

/* Result store in list  */
int insert_first (Dlist **headR, Dlist **tailR, int data);

/* insert at last in list */
int insert_at_last(Dlist **headR, Dlist **tailR, int data);

/* free list */
int free_list(Dlist **head, Dlist **tail);

/* Arithmetic operations */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR); //additon

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR); //subtraction

int multiplication(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR); //multiplication

int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR); //division

int modulus(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR); //modulus

#endif
