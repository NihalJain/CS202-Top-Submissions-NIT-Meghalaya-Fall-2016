#include<stdio.h>
#include<malloc.h>
/*
 * Function:  struct node
 * Creates a node with two fields a data field and a next field
 * The data field will store the values and the next will store the address of the next node(NULL if there is no next node)
 */
struct node
{
    char data;
    struct node* next;
};
typedef struct node node;/* User defined data type */
/*
 * Function:  new_node
 * Creates a node and allocates memory for it
 * The argument is value which will be inserted in the data field
 * The address of the temporary variable p will be returned
 */
node *new_node(char x)
{
    node* p=(node*)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    return p;
}
/*
 * Function:  insertEnd
 * The pointer to the head,last node and the value to be inserted are passed as the arguments
 * Creates a node,allocates memory for it and stores the number passed by value into the data field
 * The temporary node temp will create a node,allocate memory for it
   and store the character passed by char data into the data field
 * The temporary node temp1 will be assigned the value of the head node
 * The temporary node temp2 will be assigned the value of the last node
 * The last node will be searched and the new node will be inserted after it
 */
void insertEnd(node **head,node **last,char data)
{
    node *temp1=*head;
    node *temp2=*last;
    if(temp1==NULL)
    {
        node*temp=new_node(data);
        temp->next=temp;
        *head=temp;
        *last=temp;
    }
    else if(temp1!=NULL)
    {
        node*temp=new_node(data);
        temp->next=*head;
        temp2->next=temp;
        *last=temp;
    }
/*
 * Function:  deleteChar
 * The pointer to the head node and last node is passed as an argument
 * The temporary node temp will be assigned the value of argument passed which is a
 * The temporary node prev will be assigned the value of argument passed which is b
 * The value and address stored by temp will be deleted
*/
}
void deleteChar(node **a,node **b )
{
    node *temp=*a;
    node *prev=*b;
    prev->next=temp->next;
    free(temp);
    temp=NULL;
}
/*
 * Function:  deleteChar1
 * The pointer to the head is passed as an argument
 * The pointer to the last node is also passed as an argument
 * The temporary node temp will be assigned the value of argument passed which is a
 * The temporary node temp2 will be assigned the value of argument passed which is b
 * The value and address stored by temp will be deleted
 */
void deleteChar1(node **a,node **b)
{
    node *temp=*a;
    node *temp2=*b;
    *a=temp->next;
    temp2->next=*a;
    free(temp);
    temp=NULL;
}
/*
 * Function:  kill
 * The pointer to the head is passed as an argument
   the pointer to the last node is passed as an argument and
   the pointer to the sequence to kill the soldiers in  is passed as an argument
 * The temporary node temp will be assigned to head
 * The temporary node temp2 will be assigned to the last node
 * The temporary node prev will be store the value of the node temp
   before its value changes due to looping
 * The temporary node temp3 will be store the value of the node prev
 * The loop will search for the desired position depending on the sequence value passed
 * Then the deleteChar or deleteChar1 functions will be called depending on the value of counter i
 */
void kill(node **head,node **last,int value)
{
    node *temp=*head;
    node *temp2=*head;
    node *temp3;
    node *temp1=*last;
    int i=0;
    node *prev;
    while(temp->next!=temp&&i<value)
    {
        if(value==1)
        {
            {
                printf("Killing soldier %c",temp->data);
                deleteChar1(&temp,&temp1);
                printf("\nThe new count begins from soldier %c\n",temp->data);
            }
        }
        else
        {
            if(i==value-1)
            {
                printf("Killing soldier %c",temp->data);

                deleteChar(&temp,&prev);
                i=0;
                temp=temp3->next;
                printf("\nThe new count begins from soldier %c\n",temp->data);
            }
            prev=temp;
            temp=temp->next;
            temp3=prev;
            i++;
        }

    }
    printf("Only %c is remaining in count\n",temp->data);
    printf("So the soldier escaping is %c",temp->data);

}
int main()
{
    node *head=NULL;
    node *last=NULL;
    int m,i,n;
    char x;
    printf("Enter the number of soldiers:");
    scanf(" %d",&m);
    printf("Enter the number sequence:");
    scanf(" %d",&n);
    printf("Enter the name of the soldiers:");
    for(i=0; i<m; i++)
    {
        scanf(" %c",&x);
        insertEnd(&head,&last,x);
    }
    kill(&head,&last,n);
}
