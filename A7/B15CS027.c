//Name-Debjanee Dhar; Roll Number- B15CS027; Dated- 15.11.16
//ASSIGNMENT 7-Trees
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
typedef struct node node;
node* createnewnode(int n)//create a new  node
{
    node* temp =(node* )malloc(sizeof(node));
    temp->data = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
int insertnode(node *temp,int info)//inserting new nodes
{
    if(temp==NULL)
    {
       createnewnode(info);
    }
    else if(info < temp->data)//because it is a binary tree
    {
        temp=insertnode(&( temp)->left,info );
    }
    else if(info > temp->data)//because it is a binary tree
    {
        temp=insertnode( &( temp)->right,info );
    }
}
int deletenode(node *temp,int info)//delete nodes in the tree
{
    if(temp==NULL)
        return temp->data;
    else if(info < temp->data)
        temp->left=deletenode(temp->left,info);
     else if(info > temp->data)
        temp->right=deletenode(temp->right,info);
    else
    {
        if(temp->left==NULL)
        {
            node *store = temp->right;
            free(temp);
            return temp;
        }
        else if(temp->right==NULL)
        {
            node *store=temp->left;
            free(temp);
            return temp;
        }
    }
}
int searchtree(node* temp,int number)//search the tree for any data
{
    printf("Enter the number you want to search: \n");
    scanf("%d",&number);
    while(temp!=NULL)
    {
        if(temp->data==NULL)
        {
            printf("The list is empty!\n");
        }
        else if(temp->data >= number)
        {
            temp=temp->left;
            if(temp->data==number)
            {
                printf("%d is found\n",number);
            }
            else
                searchtree(temp,number);
        }
        else if(temp->data < number)
        {
            temp=temp->right;
            if(temp->data==number)
            {
                printf("%d is found\n",number);
            }
            else
                searchtree(temp,number);
        }
    }
}
int findsmallest(node* temp)//find the smallest element in the tree
{
    while(temp!=NULL)
    {
        if(temp->data > (temp->left)->data)
            {
                findsmallest(temp);
                if((temp->left)==NULL)
                    return;
            }
    }
    printf("The smallest number in the tree is: %d \n",temp->data);
}
int findlargest(node* temp)//find the largest element in the tree
{
    while(temp!=NULL)
    {
        if(temp->data < (temp->right)->data)
        {
            findlargest(temp);
            if(temp->right==NULL)
                return;
        }
    }
    printf("The largest number in the tree is: %d \n",temp->data);
}

int countnumberofnodes(node *temp)//counts the total number of nodes in the tree
{
    int count=1;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        count +=countnumberofnodes(temp->left);
        count +=countnumberofnodes(temp->right);
        return count;
    }
}
int countnumberofinternalnodes(node *temp)//counts total number of internal nodes,i.e., total number of nodes leaving out the leaves of the tree
{
    int countint=1;
    if(temp==NULL)
        return 0;
    else
    {
        if(temp->left!=NULL && temp->right!=NULL)
        {
        countint +=countnumberofinternalnodes(temp->left);
        countint +=countnumberofinternalnodes(temp->right);
        return countint;
        }
    }
}
int countnumberofexternalnodes(node *temp)//counts totl number of external nodes,i.e.,total number of leaves in the tree
{
    int countext=1;
    if(temp==NULL)
        return 0;
    else
    {
        if(temp->left==NULL && temp->right==NULL)
        {
        countext +=countnumberofexternalnodes(temp->left);
        countext +=countnumberofexternalnodes(temp->right);
        return countext;
        }
    }
}
void mirroroftree(node *temp)//gives the mirror image of the inserted tree
{
    node *store;
    if(temp==NULL)
        return;
    else
    {
        mirroroftree(temp->left);
        mirroroftree(temp->right);
        store=temp->left;
        temp->left=temp->right;
        temp->right=store;
    }
}

void inorder(node* temp)//prints the tree in inorder format
{
    while(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d",temp->data);
        inorder(temp->right);
    }
    printf("\n");
}
int main()
{
	node *temp;
	insertnode(temp,8);
	insertnode(temp,3);
	insertnode(temp,10);
	insertnode(temp,1);
	insertnode(temp,6);
	insertnode(temp,14);
	insertnode(temp,4);
	insertnode(temp,7);
	insertnode(temp,13);
	inorder(temp);
	deletenode(temp,14);
	inorder(temp);
	searchtree(temp,6);
	searchtree(temp,4);
	findsmallest(temp);
	findlargest(temp);
	countnumberofnodes(temp);
	countnumberofexternalnodes(temp);
	countnumberofinternalnodes(temp);
	mirroroftree(temp);
	inorder(temp);
	return 0;
}
