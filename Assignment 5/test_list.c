#include "list.h" 
#include <stdio.h> 
#include <stdlib.h> 
 
int main (){ 
	 char ans; 
	 int num; 
	 struct node *head = NULL; 
	 do { 
		 do { 
	 		printf("Enter a number: "); 
			scanf("%d", &num); 
	 		push(&head, num);//Can change to append for back 
	 
	 		printf("Do you want another num (y or n): "); 
	 		scanf("%1s",&ans); 
	 	} while(ans == 'y'); 
	 
	 printf("Sort ascending or descending (a or d)? "); 
	 scanf("%1s",&ans);
	  if(ans == 'a') sort_ascending(&head); 
	 else if(ans == 'd') sort_descending(&head); 
	 
	 //delete(&head, 3);

	 print(head, length(head)); 
	 
	 printf("Do you want to do this again (y or n)? "); 
	 scanf("%1s",&ans); 
	 if(ans == 'y') clear(&head); 
	 
	 } while(ans == 'y'); 
	 
	 return 0; 
}