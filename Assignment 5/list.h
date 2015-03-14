struct node { 
 int val; //data
 struct node *next; //pointer to next node 
}; 
 
int length(struct node *); //Computes number of elements in the list
void push(struct node **, int); //add to front of list
void print(struct node *, int); //prints the node value


void append(struct node **, int); //add to rear of list 
void clear(struct node **); 
void delete(struct node **, int); 
void sort_ascending(struct node **); //Assign 5 stuff 
void sort_descending(struct node **); //Assign 5 stuff 
