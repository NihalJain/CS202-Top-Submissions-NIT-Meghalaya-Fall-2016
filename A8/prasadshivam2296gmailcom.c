/* PROGRAM FOR MAKE A GRAPH AND DO A DFS
  %
  % Author: Shivam Prasad (prasadshivam2296@gmail.com)
  % Roll no.  :B15CS034
  % Date:    14th Nov 2016
  % Course:  Data Structures(CS202)
  % Course Instructor: Dr. Rajarshi Ray
  %
  %
  % Description: The program can 1. CREATE A GRAPH FROM A ADJACENCY MATRIX
                                 2. DO A DFS IN THE GRAPH
                                 3. CHECK IF REACHABLE.
  */
#include<stdio.h>

/* STRUCTURE: Node

 Defines a new node.
 COMPONENTS: 1. int data-> To store the values inside a node
             2. pointer *next-> To store the address of the next node
             3. int status- To store whether the node has been explored or not.
*/
struct node{
    int data;
    struct node* next;
	int status;
};
typedef struct node node;

/*
 * Function:  create_newNode
 * --------------------
 * Argument: The value which we want to have in the newly created node.
 *
 * Functioning: Creates a new node(temp) and inputs Data(passed argument) into it.
 *
 *
 *  returns: a pointer to the newly created node.
 */
node* create_newNode(int data)
{   node* temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->status=0;
    temp->next=NULL;

    return temp;
}

/*
 * Function:  join
 * --------------------
 * Argument: The two nodes which we want to join
 *
 * Functioning: Creates a new node(temp) and adds it to the start of the node start.
 *
 *
 *  returns: void.
 */
void join(node* start,int to)
{
	node* temp;
    temp=create_newNode(to);
    node* store=start->next;
    start->next=temp;
    temp->next=store;

}

/*
 * Function:  disp
 * --------------------
 * Argument: The node whose connected nodes we want to display.
 *
 * Functioning: Displays all the nodes connected the start node via a direct link.
 *
 *
 *  returns: void.
 */
void disp(node* start)
{
	node* move=start;
	while(move!=NULL){
		printf("%d",move->data);
		move=move->next;
		if(move!=NULL)
			printf(" -> ");
	}
}

/*
 * Function:  DFS
 * --------------------
 * Argument: a pointer to the node to be explored, array of vertices
 *
 * Functioning: Simulates the DFS by recursively calling itself.
 *
 *
 *  returns: void
 */
void DFS(node* start,node* vertex[])
{
	if(start==NULL)
		return;

	printf("-%d",start->data);
	start->status=1;

	while(start->next!=NULL){
        if(vertex[start->next->data-1]->status != 1)
            DFS(vertex[start->next->data-1],vertex);
		start=start->next;
	}
}

/*
 * Function:  Search
 * --------------------
 * Argument: a pointer to the start node, array of vertices, the end node
 *
 * Functioning: Checks whether end node is reachable from the start node.
 *
 *
 *  returns: 1 if yes, 0 if no.
 */
int Search(node* start,node* vertex[],int end)
{
	if(start==NULL)
		return 0;

	if(start->data==end )
		return 1;

    start->status=1;

	while(start->next!=NULL){
        if(vertex[start->next->data-1]->status != 1)
            if(Search(vertex[start->next->data-1],vertex,end))
                return 1;

		start=start->next;
	}
	return 0;
}

int main()
{
    int n,i,j,source,dest,num;
    printf("How many vertices in the graph??");
        scanf("%d",&n);

	printf("Fill in the adjacency matrix:");

	int Adj[n][n];

	node* vertex[n];

	for(i=0;i<n;i++){
        vertex[i]=create_newNode(i+1);
    }


	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&Adj[i][j]);
			if(Adj[i][j]!=0){
				join(vertex[i],j+1);
			}
		}
	}

    printf("\nDisplaying the Adjacency list: \n");
    for(i=0;i<n;i++){
        disp(vertex[i]);
        printf("\n");
    }

    printf("\nStart DFS from? ");
    	scanf("%d",&num);
    printf("\nSTART>");

    DFS(vertex[num-1],vertex);

    /*ADDED to traverse all the nodes of the graph
    i.e. even the nodes not reachable from source, here "num"*/
    for(i=0;i<n;i++){
        if(i == num -1)
            continue;
        if(vertex[i]->status != 1)
            DFS(vertex[i],vertex);

    }

    for(i=0;i<n;i++){
        vertex[i]->status = 0;
    }

    printf("\nEnter the source and destination node: \n");
    	scanf("%d%d",&source,&dest);
    	Search(vertex[source-1],vertex,dest)?printf("\nREACHABLE"):printf("\nNON-REACHABLE");

return 0;
}
