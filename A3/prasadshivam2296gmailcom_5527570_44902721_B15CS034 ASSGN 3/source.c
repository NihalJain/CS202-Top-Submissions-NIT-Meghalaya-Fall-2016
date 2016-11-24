  /* PROGRAM FOR PARENTHESIS MATCHING
  % 
  % Author: Shivam Prasad (prasadshivam2296@gmail.com) 
  % Roll no.  :B15CS034 
  % Date:    16th September 2016 
  % Course:  Data Structures(CS202)
  % Course Instructor: Dr. Rajarshi Ray
  % 
  % 
  % Description: The program can 1. TAKE INPUT FROM THE USER A STRING OF PARENTHESIS
                                 2. CHECK WHETHER THE STRING IS VALID OR NOT
                                 3. DISPLAY THE RESULT. 
  */ 

#include<stdio.h>
#include<string.h>

/* STRUCTURE: Stack

 Defines a stack of parenthesis
 COMPONENTS: 1. string Brackets- To store the Brackets in the stack.
             2. int top- To keep track of the top of the stack.*/
struct Stack{
 char Brackets[10];
 int top;
};
typedef struct Stack stack;

/*
 * Function:  push
 * --------------------
 * Argument: 1>The pointer to stack of braces.
 *           2>The element to be pushed(ele).
 *           
 * 
 * Functioning: Pushes the element(ele) at the top of the stack.
 * 
 *  returns: NULL.  */ 
void push(stack *BRACES, char ele)
{
    int Top=BRACES->top;
    
	BRACES->top=Top+1;
    BRACES->Brackets[Top+1]=ele;
}

/*
 * Function:  pop
 * --------------------
 * Argument: 1>The pointer to stack of braces.
 *          
 * 
 * Functioning: Pops the element at the top of the stack.
 *              Returns 0 if stack is empty.
 *
 *  returns: int  */ 
int pop(stack *BRACES)
{    
	int Top=BRACES->top;
    
	if((BRACES->top)<0){
       return 0;
    }
   
    else { 
       BRACES->top--;
    }
}

/*
 * Function:  check
 * --------------------
 * Argument: 1>The pointer to stack of braces.
 *           2>The element to be checked
 * 
 * Functioning: Checks if the element(ele) passed is the closing complementary of the stack top.
 *              If yes, pops the top element in the stack.
 *              Else, pushes the element(ele).
 *
 *  returns: NULL.  */ 
void check(stack *BRACES,char ele)
{    
    int top=BRACES->top;
    
    if((BRACES->Brackets[top]=='{')&&(ele=='}')){
       pop(BRACES);
       return;
     }
    if((BRACES->Brackets[top]=='[')&&(ele==']')){
       pop(BRACES);
       return;
      }
    if((BRACES->Brackets[top]=='(')&&(ele==')')){
       pop(BRACES);
       return;
      }
    
	push(BRACES,ele);
}

int main()
{  stack chef;
   int i;
   char input[20];
   
    /* Initialise the stack*/   
   chef.top=-1;
      
   /* Read the input*/  
   printf("\nEnter the string(len<20):");
   scanf("%s",input);

   /* This loop is for enabling the stack operations only for that character which is a parenthesis.*/   
    for(i=0;i<strlen(input);i++){
       if((input[i]=='{')||(input[i]=='}')||(input[i]=='(')||(input[i]==')')||(input[i]=='[')||(input[i]==']')){
	   		check(&chef,input[i]);
       }
    }
  /* If stack is empty, String is VALID*/   
  	if(pop(&chef)==0){
  		 printf("\nITS VALID\n");
  	}
  
  /* Else it is INVALID*/   
  else
    printf("\nITS NOT VALID\n");

  return 0;
}
