#include<stdio.h>
#include<malloc.h>
/*
 * Function:  struct node
 * Creates a node with two fields a data field and a next field
 * The data field will store the values and the next will store the address of the next node(NULL if there is no next node)
 */
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;/* User defined data type */
/*
 * Function:  new_node
 * Creates a node and allocates memory for it
 * The argument is value which will be inserted in the data field
 * The address of the temporary variable temp will be returned
 */
node *new_node(int value)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->data=value;
    temp->next=NULL;
    return temp;
}
/*
 * Function:  insertBeg
 * The pointer to the head and the value(number) to be inserted are passed as the arguments
 * Creates a node,allocates memory for it and stores the number passed by value into the data field
 * The new node's next will be the head pointer's next
 * The new node will be assigned as head
 * The address of the temporary variable temp will be returned
 */
void insertBeg(node **head,int value)
{
    node *temp=new_node(value);
    temp->next=*head;
    *head=temp;
}
/*
 * Function:  insertEnd
 * The pointer to the head and the value(number) to be inserted are passed as the arguments
 * Creates a node,allocates memory for it and stores the number passed by value into the data field
 * The temporary node temp1 will create a node,allocate memory for it
   and store the number passed by value into the data field
 * The temporary node temp2 will be assigned the value of head
 * The last node will be searched and the new node will be inserted after it
 */
void insertEnd(node **head,int value)
{
    node *temp1=new_node(value);
    node *temp2=*head;
    if(temp2==NULL)
    {
        temp1->next=*head;
        *head=temp1;
    }
    else
    {
        while(temp2->next!=NULL)
        {
            temp2=temp2->next;
        }
        temp2->next=temp1;
    }
}
/*
 * Function:  insertBefore
 * The argument value2 is the number which the new number will be inserted before
 * The pointer to the head and the value(number) to be inserted are passed as the arguments
 * The temporary node temp1 will be a node,with memory allocated for it
   and store the number passed by value1 into the data field
 * The temporary node temp2 will be assigned the value of head
 * The temporary node prev will store the value of temp2 during looping
 * The node before the node containing the key will be searched for during looping
 * When found the new node will be assigned the required values and will be inserted before value2
 */
void insertBefore(node **head,int value1,int value2)
{
    node *temp1=new_node(value1);
    node *temp2=*head;
    node *prev;
    if(temp2->data==value2)
    {
        temp1->next=temp2;
        *head=temp1;
    }
    else
    {
        while(temp2->data!=value2)
        {
            prev=temp2;
            temp2=temp2->next;
        }
        temp1->next=prev->next;
        prev->next=temp1;
    }

}
/*
 * Function:  insertAfter
 * The argument value2 is the number which the new number will be inserted after
 * The pointer to the head and the value(number) to be inserted are passed as the arguments
 * The temporary node temp1 will be a node,with memory allocated for it
   and store the number passed by value1 into the data field
 * The temporary node temp2 will be assigned the value of head
 * The temporary node prev will store the value of temp2 during looping
 * The node containing the key will be searched
 * When found the new node will be assigned the required values and will be inserted before value2
 */
void insertAfter(node **head,int value1,int value2)
{
    node *temp1=new_node(value1);
    node *temp2=*head;

    while(temp2->data!=value2)
    {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
/*
 * Function:  insertPos
 * The argument value2 is the position which the new number will be inserted in
 * The pointer to the head and the value(number) to be inserted are passed as the arguments
 * The temporary node temp1 will be a node,with memory allocated for it
   and store the number passed by value1 into the data field
 * The temporary node temp2 will be assigned the value of head
 * The temporary node prev will store the value of temp2 during looping
 * The node containing the key value2 will be searched
 * When found the new node will be assigned the required values and will be inserted at value2
 */
void insertPos(node **head,int value1,int value2)
{
    node *temp1=new_node(value1);
    node *temp2=*head;
    node *prev;
    int i=0;
    if(value2==1)
    {
        temp1->next=temp2;
        *head=temp1;
    }
    else
    {
        while(i<value2-1)
        {
            prev=temp2;
            temp2=temp2->next;
            i++;
        }
        temp1->next=prev->next;
        prev->next=temp1;
    }
}
/*
 * Function:  deleteNum
 * The argument value is the number which will be deleted
 * The pointer to the head is also passed as an argument
 * The temporary node temp will be assigned the value of head
 * The temporary node prev will store the value of temp during looping
 * The node containing the key value2 will be searched
 * When found the node containing the key(value) will be deleted
 */
void deleteNum(node **head,int value)
{
    node *temp=*head;
    node *prev;
    int c;
    if(temp->data==value)
    {
        *head=temp->next;
        free(temp);
        temp=NULL;
    }
    else
    {
        while(temp->data!=value&&temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp->data=value)
        {
            prev->next=temp->next;
            free(temp);
            temp=NULL;
        }
        else if(temp->data!=value)
        {
            printf("Underflow");
        }
    }

}
/*
 * Function:  DeleteBefore
 * The argument value is the number which the number previous to it will be deleted
 * The pointer to the head is also passed as an argument
 * The temporary node temp will be assigned the value of head
 * The temporary node prev1 will store the value of prev2 during looping
   and prev2 will store the value of temp during looping
 * The node before the node containing the key(value) will be searched for during looping
 * When found the node before the key(value) will be deleted
 */
void deleteBefore(node **head,int value)
{
    node *temp=*head;
    node *prev1=NULL,*prev2=NULL;
    if(temp->data==value)
    {
        printf("Underflow\n");
    }
    else
    {
        while(temp->data!=value&&temp->next!=NULL)
        {
            prev1=prev2;
            prev2=temp;
            temp=temp->next;
        }
        if(prev1==NULL)
        {
            *head=temp;
            free(prev2);
            prev2=NULL;
        }
        else if(temp->data=value)
        {
            prev1->next=prev2->next;
            free(prev2);
            prev2=NULL;
        }

    }


}
/*
 * Function:  DeleteAfter
 * The argument value is the number which the number after it will be deleted
 * The pointer to the head is also passed as an argument
 * The temporary node temp will be assigned the value of head
 * The temporary node temp1 will store the value of temp2 during looping
 * The node containing the key(value) will be searched for during looping
 * When found the node after the key(value) will be deleted
 */
void deleteAfter(node **head,int value)
{
    node *temp=*head;
    node *temp1;
    while(temp->data!=value)
    {
        temp=temp->next;
    }
    if(temp->next!=NULL)
    {
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        temp1=NULL;
    }
    else
    {
        printf("Underflow");
    }
}
/*
 * Function:  DeleteBeg
 * The pointer to the head is passed as an argument
 * The temporary node temp will be assigned the value of head
 * Head will point to temp next
 * The temporary node temp will be freed
 */
void deleteBeg(node **head)
{
    node *temp=*head;
    *head=temp->next;
    free(temp);
    temp=NULL;
}
/*
 * Function:  deleteEnd
 * The pointer to the head is passed as an argument
 * The temporary node temp will be assigned the value of head
 * The last node will be searched and the node will then be deleted
 */
void deleteEnd(node **head)
{
    node *temp=*head;
    node *prev;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;

}
/*
 * Function:  Rev
 * The pointer to the head is passed as an argument
 * The temporary node temp will be assigned the value of head
 * While the loop doesn't stop the nodes next will be broken and the nodes will be reversed
 */
void Rev(node **head)
{
    node *prev=NULL,*n=NULL;
    node *temp=*head;
    while(temp->next!=NULL)
    {
        n=temp->next;
        temp->next=prev;
        prev=temp;
        temp=n;
    }
    temp->next=prev;
    *head=temp;
}
/*
 * Function:  disp
 * The pointer to the head is passed as an argument
 * The temporary node temp will be assigned the value of head
 * While the loop does not stop the data field of temporary node temp will be displayed in the output
 */
void disp(node **head)
{

    if(head==NULL)
    {
        printf("Underflow");
    }
    node *temp=*head;
    while(temp->next!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf(" %d",temp->data);
    printf("\n");
}
int main()
{
    node *head=NULL;
    int x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12,x13,x14;
    printf("Enter a number:");
    scanf("%d",&x1);
    insertBeg(&head,x1);
    disp(&head);

    printf("Enter a number to insert in the beginning:");
    scanf("%d",&x2);
    insertBeg(&head,x2);
    disp(&head);

    printf("Enter another number to insert in the beginning:");
    scanf("%d",&x3);
    insertBeg(&head,x3);
    disp(&head);

    printf("Enter number to insert in the end:");
    scanf("%d",&x4);
    insertEnd(&head,x4);
    disp(&head);

    printf("Enter another number to insert in the end:");
    scanf("%d",&x5);
    insertEnd(&head,x5);
    disp(&head);

    printf("Enter the number to insert and the position:");
    scanf("%d%d",&x6,&x7);
    insertPos(&head,x6,x7);
    disp(&head);

    printf("Enter the number in the list to delete:");
    scanf("%d",&x8);
    deleteNum(&head,x8);
    disp(&head);

    printf("Enter the number in the list to delete before:");
    scanf("%d",&x9);
    deleteBefore(&head,x9);
    disp(&head);

    printf("Enter the number in the list to delete after:");
    scanf("%d",&x10);
    deleteAfter(&head,x10);
    disp(&head);

    printf("Enter the number to insert and the number in the list which it will be inserted after:");
    scanf("%d%d",&x11,&x12);
    insertAfter(&head,x11,x12);
    disp(&head);

    printf("Enter the number to insert and the number in the list which it will be inserted before:");
    scanf("%d%d",&x13,&x14);
    insertBefore(&head,x13,x14);
    disp(&head);

    printf("Deleting beginning:");
    deleteBeg(&head);
    disp(&head);

    printf("Deleting end:");
    deleteEnd(&head);
    disp(&head);

    printf("Reversing:");
    Rev(&head);
    disp(&head);

    return 0;
}
