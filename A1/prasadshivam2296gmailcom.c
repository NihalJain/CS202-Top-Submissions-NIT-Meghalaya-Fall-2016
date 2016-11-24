
/* PROGRAM FOR GENERAL FUNCTIONS IN A SINGLY LINKED LIST
%
% Author: Shivam Prasad (prasadshivam2296@gmail.com)
% Roll no.  :B15CS034
% Date:    31st August 2016
% Course:  Data Structures(CS202)
% Course Instructor: Dr. Rajarshi Ray
%
%
% Description: The program can 1. INSERT AT THE BEGINNING OF THE LIST
                               2. INSERT AT THE END OF THE LIST
                               3. DELETE AT THE BEGINNING OF THE LIST
								 4. DELETE AT THE END OF THE LIST
							 5. REVERSE THE LIST
							 6. INSERT AT A GIVEN POSITION
							 7. DELETE AT A GIVEN POSITION
							 8. DELETE GIVEN NUMBER IN A LIST
							 9. INSERT AFTER GIVEN NUMBER
							 10.DELETE BEFORE GIVEN NUMBER
							 11.DELETE AFTER GIVEN NUMBER

*/
#include<stdio.h>

/* STRUCTURE: Node

 Defines a new node.
 COMPONENTS: 1. int data-> To store the values inside a node
             2. pointer *next-> To store the address of the next node
*/

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

/*
 * Function:  newNode
 * --------------------
 * Argument: The value which we want to have in the newly created node.
 *
 * Functioning: Creates a new node(temp) and inputs Data(passed argument) into it.
 *
 *
 *  returns: a pointer to the newly created node.
 */
Node* newNode(int Data)
{
    Node* temp=(Node*)(malloc(sizeof(Node)));
    temp->data=Data;
    temp->next=NULL;
    return temp;
}

/*
 * Function:  InsertBeg
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *           2>The data to be inserted at the start of the list.
 *
 * Functioning: Creates a new node(temp) and inserts it to the start of the list.
 *
 *
 *  returns: NULL.
 */
void InsertBeg(Node** HEAD,int data)
{
    Node* temp=newNode(data);
    temp->next=*HEAD;
    *HEAD=temp;
}

/*
 * Function:  InsertGivenPos
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *           2>The data to be inserted at any position of the list.
 *           3>The position to insert the data.
 *
 * Functioning: Creates a new node(temp) and inserts it to the given position of the list.
 *               Prints "INPUT POSiTION OUT OF RANGE" if position is out of range.
 *
 *  returns: NULL.
 */
void InsertGivenPos(Node** HEAD,int data,int pos)
{
    Node* temp=newNode(data);
    Node* p=*HEAD;

    if(p==NULL)
    {
        *HEAD=temp;
        return ;
    }

    if(pos==1)
    {
        temp->next=p;
        *HEAD=temp;
        return;
    }

    int i=1;

    while((i!=(pos-1))&&(p!=NULL))
    {
        p=p->next;
        i++;
    }

    if(p==NULL)
    {
        printf("INPUT POSITION OUT OF RANGE!!\n");
        return ;
    }

    Node*q=p->next;
    p->next=temp;
    temp->next=q;
}

/*
 * Function:  DeleteGivenPos
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *           2>The position to to delete the node.
 *
 * Functioning: Deletes element at a given position,
 *              Prints UNDERFLOW!!!, if list is empty.
 *              Prints "POS OUT OF RANGE" if position is out of range.
 *
 *  returns: NULL.
 */
void DeleteGivenPos(Node** HEAD,int pos)
{
    Node* p=*HEAD;

    if(p==NULL)
    {
        printf("UNDERFLOW!!!\n");
        return;
    }

    if(pos==1)
    {
        *HEAD=p->next;
        free(p);
        p=NULL;
        return;
    }

    int i=1;

    while(i!=(pos-1))
    {
        p=p->next;
        i++;

        if(p==NULL)
        {
            printf("POS OUT OF rANGE\n");
            return;
        }
    }

    Node*q=p->next;
    p->next=q->next;
    free(q);
    q=NULL;
}

/*
 * Function:  DeleteGivenNum
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *           2>The element to be deleted.
 *
 * Functioning: Deletes the passed element,
 *              Prints UNDERFLOW!!!, if list is empty.
 *              Prints "NOT FOUND" if element to be deleted is not present.
 *
 *  returns: NULL.
 */
void DeleteGivenNum(Node** HEAD,int num)
{
    Node* p=*HEAD;

    if(p==NULL)
    {
        printf("UNDERFLOW!!!\n");
        return;
    }

    if(p->data==num)
    {
        *HEAD=p->next;
        free(p);
        p=NULL;
        return;
    }

    if(p->next==NULL)
        return;

    Node* q=p->next;
    while((q->data!=num)&&(q->next!=NULL))
    {
        p=p->next;
        q=q->next;
    }

    if(q->data==num)
    {
        p->next=q->next;
        free(q);
        q=NULL;
        return;
    }

    if(q->next==NULL)
    {
        printf("%d NOT FOUND!!!\n",num);
        return;
    }

    p->next=q->next;
    free(q);
    q=NULL;
}

/*
 * Function:  InsertAfterNum
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *           2>The element after which we have to insert data.
 *           3>The data to be inserted
 *
 * Functioning: Inserts data after Given num
 *              Prints LIST IS EMPTY!!!, if list is empty.
 *              Prints "NOT FOUND" if Given num is not present.
 *
 *  returns: NULL.
 */
void InsertAfterNum(Node** HEAD,int target,int num)
{
    Node* p=*HEAD;
    Node*temp=newNode(num);

    if(p==NULL)
    {
        printf("LIST IS EMPTY!!!\n");
        return;
    }

    Node* q=p->next;

    if(p->data==target)
    {
        p->next=temp;
        temp->next=q;
        return;
    }

    while((q->data!=target)&&(q->next!=NULL))
    {
        q=q->next;
    }

    if(q->data!=target)
    {
        printf("%d NOT FOUND!!\n",target);
        return;
    }

    Node*r=q->next;
    q->next=temp;
    temp->next=r;
}

/*
 * Function:  DeleteBeforeNum
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *           2>The element before which we have to delete data.
 *
 *
 * Functioning: Deletes data before Given num
 *              Prints LIST IS EMPTY!!!, if list is empty.
 *              Prints "NOT FOUND" if Given num is not present.
 *				Prints "UNDERFLOW" if Given num is the first element.
 *
 *  returns: NULL.
 */
void DeleteBeforeNum(Node**HEAD,int target)
{
    Node* p=*HEAD;

    if(p==NULL)
    {
        printf("LIST IS EMPTY!!!\n");
        return;
    }

    if(p->data==target)
    {
        printf("\nUNDERFLOW!!\n");
        return;
    }

    if(p->next==NULL)
        return;

    Node* q=p->next;

    if(q->data==target)
    {
        *HEAD=q;
        free(p);
        p=NULL;
        return;
    }

    while((q->next->data!=target)&&(q->next!=NULL))
    {

        p=p->next;
        q=q->next;

        if(q==NULL)
        {
            printf("\n%d NOT FOUND!!!",target);
            return;
        }
    }

    if((q->data==target)&&(q->next==NULL))
    {
        p->data=q->data;
        free(q);
        q=NULL;
        return ;
    }

    p->next=q->next;
    free(q);
    q=NULL;
}

/*
 * Function:  DeleteAfterNum
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *           2>The element after which we have to delete data.
 *
 *
 * Functioning: Deletes data after Given num
 *              Prints "LIST IS EMPTY!!!", if list is empty.
 *              Prints "NOT FOUND" if Given num is not present.
 *				Prints "UNDERFLOW" if Given num is the last element.
 *
 *  returns: NULL.
 */
void DeleteAfterNum(Node**HEAD,int target)
{
    Node* p=*HEAD;

    if(p==NULL)
    {
        printf("LIST IS EMPTY!!!\n");
        return;
    }
    while((p->data!=target)&&(p->next!=NULL))
    {
        p=p->next;
    }

    Node* q=p->next;

    if((p->data==target)&&(p->next==NULL))
    {
        printf("UNDERFLOW!!\n");
        return ;
    }

    else if(p->data==target)
    {
        q=p->next;
        p->next=q->next;
        free(q);
        q=NULL;
        return;
    }

    else if(p->next==NULL)
    {
        printf("\n%d NOT FOUND!!!",target);
        return;
    }
}

/*
 * Function:  InsertEnd
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *           2>The data to be insert at the end.
 *
 *
 * Functioning: Inserts data at the end of the list.
 *
 *  returns: NULL.
 */
void InsertEnd(Node** HEAD,int data)
{
    Node* temp=newNode(data);
    Node* p=*HEAD;

    if(p==NULL)
    {
        *HEAD=temp;
        return;
    }

    while(p->next!=NULL)
    {
        p=p->next;
    }

    p->next=temp;
    temp->next=NULL;
}

/*
 * Function:  display
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *
 *
 *
 * Functioning: Displays the list.
 *
 *  returns: NULL.
 */
void display(Node** HEAD)
{
    Node* p=*HEAD;

    printf("  LIST=");

    while(p!=NULL)
    {
        printf("%d,",p->data);
        p=p->next;
    }

    printf("\n");
}

/*
 * Function:  deleteBeg
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *
 *
 *
 * Functioning: 1>Deletes the first element of the list.
 *              2>prints "LIST IS EMPTY" if list is empty.
 *
 *  returns: NULL.
 */
void deleteBeg(Node** HEAD)
{
    Node* p=*HEAD;

    if(p==NULL)
    {
        printf("\nLIST IS EMPTY!\n");
        return ;
    }

    else
    {
        *HEAD=p->next;
        free(p);
        p=NULL;
    }
}

/*
 * Function:  deleteEnd
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *
 *
 *
 * Functioning: 1>Deletes the last element of the list.
 *              2>Prints "UNDERFLOW!" if list is empty.
 *
 *  returns: NULL.
 */
void deleteEnd(Node** HEAD)
{
    Node* p=*HEAD;

    if(p==NULL)
    {
        printf("UNDERFLOW!\n");
        return;
    }

    else if(p->next==NULL)
    {
        *HEAD=NULL;
        free(p);
        p=NULL;
        return;
    }

    else
    {
        Node* q=p->next;

        while(q->next!=NULL)
        {
            q=q->next;
            p=p->next;
        }

        free(p->next);
        p->next=NULL;
    }
}

/*
 * Function:  Reverse
 * --------------------
 * Argument: 1>The pointer to the HEAD of the list.
 *
 *
 *
 * Functioning: 1>Reverses the LINKED LIST.
 *              2>prints "UNDERFLOW" if list is empty.
 *
 *  returns: NULL.
 */
void Reverse(Node** HEAD)
{
    Node* ini=*HEAD;
    Node* p=*HEAD;


    if(ini==NULL)
    {
        printf("\nUNDERFLOW!");
        return;
    }

    else if(ini->next==NULL)
    {
        return;
    }
    Node* q=p->next;
    if(q->next==NULL)
    {
        *HEAD=q;
        q->next=p;
        p->next=NULL;
    }

    else
    {
        Node* r=q->next;
        while(r!=NULL)
        {
            r=q->next;
            q->next=p;
            p=q;
            q=r;
        }

        ini->next=NULL;
        *HEAD=p;
    }
}

int main()
{
    int choice,n,x,pos;

    Node* list = NULL;

    do
    {

        printf("\n HELLO user! WHAT DO YOU WANT TO DO??");

        printf("\n\t1.INSERT BEG:\n");
        printf("\n\t2.DELETE BEG\n");
        printf("\n\t3.INSERT AT END\n");
        printf("\n\t4.DELETE FROM END\n");
        printf("\n\t5.REVERSING LIST:\n");
        printf("\n\t6.INSERT_AT_GIVEN_POS\n");
        printf("\n\t7.DELETE_AT_GIVEN_POS\n");
        printf("\n\t8.DELETE_NUM\n");
        printf("\n\t9.INSERT_AFTER_GIVEN_NUM:\n");
        printf("\n\t10.DELETE_BEFORE_GIVEN_NUM:\n");
        printf("\n\t11.DELETE_AFTER_GIVEN_NUM:\n");
        printf("\n\t12.PRESS 0 TO EXIT!\n");

        scanf("%d",&choice);

        switch(choice)
        {

        case 1:
        {
            printf("How many Numbers?\n");
            scanf("%d",&n);
            printf("Enter numbers:\n");
            while(n--)
            {
                scanf("%d",&x);
                InsertBeg( &list,x);
            }
            display(&list);
        }
        break;

        case 2:
        {
            deleteBeg(&list);
            display(&list);
        }
        break;

        case 3:
        {
            printf("Enter number to insert:");
            scanf("%d",&x);
            InsertEnd(&list,x);
            display(&list);
        }
        break;

        case 4:
        {
            deleteEnd(&list);
            display(&list);
        }
        break;

        case 5:
        {
            Reverse(&list);
            display(&list);
        }
        break;

        case 6:
        {
            printf("Enter data and pos:\n");
            scanf("%d%d",&x,&pos);
            InsertGivenPos(&list,x,pos);
            display(&list);
        }
        break;


        case 7:
        {
            printf(" Enter pos:\n");
            scanf("%d",&pos);
            DeleteGivenPos(&list,pos);
            display(&list);
        }
        break;


        case 8:
        {
            printf("Enter num:\n");
            scanf("%d",&x);
            DeleteGivenNum(&list,x);
            display(&list);
        }
        break;

        case 9:
        {
            printf(" Enter target number and num to be inserted :");
            scanf("%d%d",&pos,&x);
            InsertAfterNum(&list,pos,x);
            display(&list);
        }
        break;

        case 10:
        {
            printf(" Enter target num :");
            scanf("%d",&pos);
            DeleteBeforeNum(&list,pos);
            display(&list);
        }
        break;

        case 11:
        {
            printf("Enter target num :");
            scanf("%d",&pos);
            DeleteAfterNum(&list,pos);
            display(&list);
        }
        break;

        case 0:
        {
            printf("\nTHANKS FOR USING THE PROGRAM");
        }
        break;

        default:
            printf("Wrong INPUT\n");
        }
    }
    while(choice!=0);

    return 0;
}
