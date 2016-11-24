  /* PROGRAM FOR IMPLEMENTING THE JOSEPHUS PROBLEM
  %
  % Author: Shivam Prasad (prasadshivam2296@gmail.com)
  % Roll no.  :B15CS034
  % Date:    13th September 2016
  % Course:  Data Structures(CS202)
  % Course Instructor: Dr. Rajarshi Ray
  %
  %
  % Description: The program can 1. CREATE A CIRCULAR LINKED LIST OF THE NAMES OF THE SOLDIERS
                                 2. ASK THE USER FOR THE NUMBER OF COUNTS
                                 3. ASK THE USER FROM WHOM TO START THE COUNTING FROM
  								 4. SIMULATE THE JOSEPHUS PROBLEM
								 5. DISPLAY THE NAME OF THE SOLDIER WHO WILL ESCAPE
  */


#include<iostream>
#include<string.h>
#include<malloc.h>

/* STRUCTURE: Node

 Defines a new node.
 COMPONENTS: 1. char data-> To store the names of the soldiers
             2. pointer *next-> To store the address of the next node in the list
*/
struct Node
{
  char data[7];
  struct Node *next;
};
typedef struct Node Node;

/*
 * Function:  newNode
 * --------------------
 * Argument: The name of the soldier to be added in the circular list
 *
 * Functioning: Creates a new node(temp) and inputs Data(passed argument) into it.
 *
 *
 *  returns: a pointer to the newly created node.
 */
Node* newNode(char *Data)
{
    Node* temp=(Node*)(malloc(sizeof(Node)));
    strcpy(temp->data,Data);
    temp->next=temp;

	return temp;
}

/*
 * Function:  InsertEnd
 * --------------------
 * Argument: 1>The pointer to the LAST of the list.
 *           2>The data to be inserted at the end(name of soldier).
 *
 *
 * Functioning: Inserts name of soldier at the end of the list.
 *
 *  returns: NULL.
 */
void InsertEnd(Node** LAST,char *data)
{
	 Node* temp=newNode(data);

	if(*LAST==NULL){
		*LAST=temp;
		temp->next=temp;
        return;
	 }

	Node* p=*LAST;
	Node* head=p->next;

    p->next=temp;
    temp->next=head;
	*LAST=temp;
}

/*
 * Function:  display
 * --------------------
 * Argument: 1>The pointer to the LAST of the list.
 *
 *
 * Functioning: Displays the list if the list has more than one element.
 *              Prints the name of the soldier who will escape if the list has only one element.
 *
 *  returns: NULL.
 */
void display(Node** LAST)
{
	Node* p=*LAST;

  	if(p->next==p){
		printf("%s survives!!",p->data);
     	return;
	}

  	printf("  Count starts from:");

  	while(p->next!=*LAST){
  		printf("%s->",p->data);
   		p=p->next;
    }

  printf("%s",p->data);
  printf("\n");
}

/*
 * Function:  die
 * --------------------
 * Argument: 1>The pointer to the LAST of the list.
 *           2>The number of counts(k) to kill a soldier.
 *
 * Functioning: Moves to the node to be deleted.
 *              Deletes the node(kills the soldier).
 *              Prints the name of the soldier which dies.
 *
 *  returns: NULL.
 */
void die(Node** LAST,int ite)
{
	Node* p=*LAST;

  while(ite!=1){
	p=p->next;
  	ite--;
  }

   Node*q=p->next;
   p->next=q->next;

   printf("\n%s DIES!!!!\n",q->data);
    free(q);
    q=NULL;

   *LAST=p->next;

  printf("\n");
}

/*
 * Function:  search
 * --------------------
 * Argument: 1>The pointer to the LAST of the list.
 *           2>The name of the soldier to be searched(name)
 *
 * Functioning: Searches the list for the soldier. If found, puts the LAST pointer at that node.
 *
 *
 *  returns: 1 if soldier is found.
 *			 0 if soldier is not found.
 */
int search(Node** LAST,char* name)
{
	Node* p=*LAST;

   while((strcmp(p->data,name)!=0)&&(p->next!=*LAST))
     p=p->next;

   if(strcmp(p->data,name)==0){
  	  *LAST=p; return 1;
	}

   else {
	  printf("%s Not found!\n",name);
      return 0;
	}
}

/*
 * Function:  Initial
 * --------------------
 * Argument: 1>The pointer to the LAST of the list.
 *
 *
 * Functioning: Forms the circular linked list of the soldiers.
 *				Inputs the number of soldiers(n).
 *				Puts the name of n soldiers in the list.
 *
 *
 *  returns:NULL
 */
void Initial(Node** LIST)
{
	int n,pos,k;
	char x[5],start[5];

	printf("\n\tHow many Soldiers?\n");
	scanf("%d",&n);

	printf("Enter the names:\n");
   		while(n--){
     		scanf("%s",x);
     		InsertEnd( LIST,x);
   		}
}

/*
 * Function:  Kill
 * --------------------
 * Argument: 1>The pointer to the LAST of the list.
 *           2>The number of counts(k) to kill a soldier.
 *
 * Functioning: Simulates the killing of the soldiers by calling function "die" till the list has more than one element.
 *              Displays the list after each killing.
 *
 *  returns:NULL
 */
void Kill(Node* LIST,int k)
{
   while(LIST->next!=LIST) {

   	die(&LIST,k);
    display(&LIST);
   }
}

int main()
{

/*
 * Initialising the list to NULL */
  	Node* list = NULL;
 	int k;
	char start[5];
	strcpy(start,"?");

/*
 * Calling the function "Initial" to make the circular linked list of soldiers. */
 	Initial(&list);

/*
 * Displaying the initial list of soldiers.  */
 	 printf("\nSOLDIERS :\n ");
  		display(&list);

/*
 * Input name of the soldier from which to start the counting. */
  	printf("Whom do you want to start counting from? <Press # to end program>");

/*
 * Searching the list for the inputted name of soldier. If not found, ask again and again until "#" is passed */
	while(strcmp(start,"#")!=0){
    	  scanf("%s",start);
  		 if(search(&list,start)==1)
     		break;

  	}

/*
 * Exit from the program if "#" is inputted */
  if(strcmp(start,"#")==0)
    return 0;
    //exit(0);
/*
 * If inputted name of soldier is in the list.
 * Input the number of counts(k) to kill a soldier  */
  	else {
  	  display(&list);
	  printf("Enter k\n");
      scanf("%d",&k);
      k--;
	}
/*
 * Simulate the killing process by calling "Kill" function */
	Kill(list,k);

 return 0;
}



