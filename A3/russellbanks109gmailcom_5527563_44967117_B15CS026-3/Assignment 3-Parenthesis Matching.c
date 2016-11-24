#include<stdio.h>
#include<string.h>
#include<malloc.h>
/*
 * Function:  struct stack
 * Creates a stack with two fields a data field and a next field
 * The data field will store the values and the next will store the
   address of the next stack item(NULL if there is no next stack item)
 */
struct stack
{
    char data;
    struct stack *next;
};
typedef struct stack stack;/* User defined data type */
/*
 * Function:  new_stack
 * Creates a stack item and allocates memory for it
 * The argument is value which will be inserted in the data field
 * The address of the temporary variable temp will be returned
 */
stack *new_stack(char value)
{
    stack *temp;
    temp=(stack*)malloc(sizeof(stack));
    temp->data=value;
    temp->next=NULL;
    return temp;
}
/*
 * Function:  push
 * The pointer to the top and the value(char) to be inserted are passed as the arguments
 * Creates a stack,allocates memory for it and stores the number passed by value into the data field
 * The new stack item's next will be the top pointer's next
 * The new stack item will be assigned as top
 * The address of the temporary variable temp will be returned
 */
void push(stack **top,char x)
{
    stack *temp=new_stack(x);
    temp->next=*top;
    *top=temp;
}
/*
 * Function:  peek
 * The pointer to the top is passed as the argument
 * Creates a temporary stack temp and assigns it the value of the passed argument
 * Returns the data of the item the top pointer is pointing to
 */
int peek(stack **top)
{
    stack *temp=*top;
    return temp->data;
}
/*
 * Function:  pop
 * The pointer to the top
 * Creates a temporary stack temp and assigns it the value of the passed argument
 * A temporary character variable is assigned the value of the data of top
 * Returns the character of x;
 */
int pop(stack **top)
{
    stack *temp=*top;
    if(temp==NULL)
    {
        printf("underflow");
        return;
    }
    char x=temp->data;
    *top=temp->next;
    return x;
}
/*
* Function:  disp
* The pointer to the top is passed as an argument
* The temporary node temp will be assigned the value of top
* While the loop does not stop the data field of temporary stack temp will be displayed in the output
*/
void disp(stack **top)
{
    stack *temp=*top;
    if(temp==NULL)
    {
        printf("Empty");
    }
    while(temp->next!=NULL)
    {
        printf("\n%c\n",pop(top));
        temp=temp->next;
    }
    printf("\n%c\n",temp->data);
}

int main()
{
    stack *top=NULL;
    int m;
    int i,n,p,c=0;
    char x[1000],y='c';
    printf("Enter the parenthesis combination:");
    scanf("%s",&x);
    p=strlen(x);
    for (i=0; i<p; i++)
    {
        if(x[i]=='('|x[i]=='{'|x[i]=='[')
        {
            push(&top,x[i]);
        }
        else if(x[i]==')')
        {
            if(y=='(')
            {
                pop(&top);
            }
            else
            {
                c=c+1;
                i=p;
            }
        }
        else if(x[i]=='}')
        {
            if(y=='{')
            {
                pop(&top);
            }
            else
            {
                c=c+1;
                i=p;
            }

        }
        else if(x[i]==']')
        {
            if(y=='[')
            {
                pop(&top);
            }
            else
            {
                c=c+1;
                i=p;
            }

        }
        if(top!=NULL)
        {
            y=peek(&top);
        }
        if(x[i]==')'|x[i]=='}'|x[i]==']'&&y=='c')
        {
            c=c+1;
            i=p;
        }
        if(top==NULL)
        {
            y='c';
        }
    }
    if(top==NULL&&c==0)
    {
        printf("\nmatching\n");
    }
    else
    {
        printf("\n not matching\n");
    }
}

