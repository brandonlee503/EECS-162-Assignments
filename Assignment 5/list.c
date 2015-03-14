/********************************************************************* 
 ** Program Filename: 5assignment.cpp
 ** Author: Brandon Lee
 ** Date: 6/6/14
 ** Description: Assignment 5
 ** Input: ints that you want to put in nodes
 ** Output: Sorted linked list
 *********************************************************************/
#include "list.h" 
#include <stdio.h> 
#include <stdlib.h> 

//Computes number of elements in the list and does the physical linking
//Takes in a linked list and computers the number of elements in the list.

/*********************************************************************
 ** Function: int length(struct node *head)
 ** Description: Computes number of elements in the list and does the physical linking
 ** Parameters: struct node *
 ** Preconditions: Takes in a linked list and computers the number of elements in the list.
 ** Return: int
 *********************************************************************/
int length(struct node *head){
	struct node *current = head;
	int count = 0;

	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

//add to front of list aka InsertAtFront()
/*********************************************************************
 ** Function: void push(struct node **headref, int num)
 ** Description: Adds another node to the front of the linked list 
 ** Parameters: struct node **
 ** Preconditions: Takes in a linked list and computers the number of elements in the list.
 ** Return: N/A
 *********************************************************************/
void push(struct node **headref, int num){
	struct node *newnode = malloc(sizeof(struct node)); //allocate memory

	newnode->val = num;
	newnode->next = *headref; //link next, the * to dereferences back to the real head
	*headref = newnode; //link head, same comment as above
}

//add to rear of list
/*********************************************************************
 ** Function: void append(struct node **headref, int num)
 ** Description: Adds another node to the end of the linked list 
 ** Parameters: struct node **, int
 ** Preconditions: Takes in a linked list and computers the number of elements in the list.
 ** Return: N/A
 *********************************************************************/
void append(struct node **headref, int num){
	struct node *current = *headref;
	struct node *newnode;

	newnode = malloc(sizeof(struct node));
	newnode->val = num;
	newnode->next = NULL;

	//Case for length = 0
	if(current==NULL){
		*headref=newnode;
	}
	else{
		//Locate last node
		while(current->next != NULL){
			current=current->next;
		}
		current->next = newnode;
	}
}

//Clear all the nodes
/*********************************************************************
 ** Function: void clear(struct node **head)
 ** Description: Deletes all the nodes in linked list 
 ** Parameters: struct node **
 ** Preconditions: The linked list is not empty
 ** Return: N/A
 *********************************************************************/
void clear(struct node **head){
	struct node *next, *delete_me;
	delete_me = *head;
	while(delete_me){
		next = delete_me->next;
		free(delete_me);
		delete_me = next;
	}
	*head = NULL;
}

//Deletes a single selected node
/*********************************************************************
 ** Function: void delete(struct node **head, int node_to_delete)
 ** Description: Deletes a single selected node through selected value
 ** Parameters: struct node **, int
 ** Preconditions: The linked list is not empty
 ** Return: N/A
 *********************************************************************/

void delete(struct node **head, int node_to_delete){
	struct node *delete_me, *next1;

	next1 = NULL;
	for(delete_me = *head; delete_me != NULL; next1 = delete_me, delete_me = delete_me->next){
		if(delete_me->val == node_to_delete){
			if(next1 == NULL){
				*head = delete_me->next;
			}
			else{
				next1->next = delete_me->next;
			}
	free(delete_me);
	return;
		}
	}
}

/*********************************************************************
 ** Function: void print(struct node *head, int p)
 ** Description: Deletes a single selected node
 ** Parameters: struct node **, int
 ** Preconditions: The linked list is not empty
 ** Return: N/A
 *********************************************************************/
void print(struct node *head, int p){
	struct node *current = head;
	printf("Print list: ");
	while(current != NULL){
		printf("%d ", (current->val));
		current=current->next;
	}
	printf("\n");
}

/*********************************************************************
 ** Function: void sort_ascending(struct node **headref)
 ** Description: Sorts the nodes by ascending value 
 ** Parameters: struct node **
 ** Preconditions: There is a linked list
 ** Return: N/A
 *********************************************************************/
void sort_ascending(struct node **headref){
	
	struct node *current = *headref; //Reference the head node
	struct node *temp_ptr = malloc(sizeof(struct node)); //Temporary pointer to store nodes

	//Bubble Sort Method
	if(*headref != NULL){
		for(; current->next != NULL; current = current->next){
			for(temp_ptr = current->next; temp_ptr != NULL; temp_ptr = temp_ptr->next){
				if(current->val > temp_ptr->val){
					int temp = current->val;
					current->val = temp_ptr->val;
					temp_ptr->val = temp;
				}
			}
		}
	}
}

/*********************************************************************
 ** Function: void sort_descending(struct node **headref)
 ** Description: Sorts the nodes by descending value 
 ** Parameters: struct node **
 ** Preconditions: There is a linked list
 ** Return: N/A
 *********************************************************************/
void sort_descending(struct node **headref){

	struct node *current = *headref; //Reference the head node
	struct node *temp_ptr = malloc(sizeof(struct node)); //Temporary pointer to store nodes 

	//Bubble Sort Method
	if(*headref != NULL){
		for(; current->next != NULL; current = current->next){
			for(temp_ptr = current->next; temp_ptr != NULL; temp_ptr = temp_ptr->next){
				if(current->val < temp_ptr->val){
					int temp = current->val;
					current->val = temp_ptr->val;
					temp_ptr->val = temp;
				}
			}
		}
	}
}

