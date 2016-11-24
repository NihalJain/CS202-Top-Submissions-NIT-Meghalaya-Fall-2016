/*
   Assignment 7
    Operations on Binary Search Trees
   Submitted by-       Chandrani Kar
                       B15CS031
                       CSE department
                       */


#include<stdio.h>
#include<stdlib.h>
/*
structure for a binary search tree
*/
struct tree
{
    int data;           /* data field for storing information */
    struct tree* left;
    /* left pointer for the left child */
    struct tree* right;
    /* right pointer for the right child */

} ;
typedef struct tree tree;
/*
Function for creating a new node in a binary search tree
*/
tree *create_newnode(int info)
{
    tree *temp;
    temp = (tree*)malloc(sizeof(tree));
    temp->data=info;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
/*
Function to insert an element into a binary search tree
*/
void InsertElement(tree *root, int info)
{

    tree* t = create_newnode(info);
    if (info<=root->data)  /*if the num to be inserted is less than the root value then it has to be inserted in the left side*/
    {
        if (root->left==NULL)
            root->left = t;
        else
            InsertElement(root->left, info);
    }
    if (info>root->data)
    {
        if (root->right == NULL)/*if the num to be inserted is more than the root value then it has to be inserted in the right side*/
            root->right = t;
        else
            InsertElement(root->right, info);
    }
}
/*
Function to search an element in a given binary search tree
*/
void SearchElement(tree *root, int k)
{
    int t=0;
    if(root==NULL)
        printf("No element in binary search tree\n");
    /* root is NULL means there is no element in binary search tree*/

    while(root!=NULL)
    {
        if(root->data==k)
        {
            printf("Element %d is found\n",root->data);/*if the root's data matches with the key,print it*/
            t=1;
            break;
        }

        else if(root->data>k)/*if root's data is greater than key then check the numbers at roots left*/
            root=root->left;

        else
            root=root->right;/*if root's data is less than key then check the numbers at roots right*/
    }
    if(t==0)
        printf("Element not found\n");

}
/*
Function to find maximum element of a binary search tree
*/
tree* FindLargestElement(tree* root)
{
    if(root==NULL)
        return NULL;

    while(root->right!=NULL)
        root=root->right;
    return root;
}
/*
Function to find minimum element of a binary search tree
*/
tree* FindSmallestElement(tree* root)
{

    if(root==NULL)
        return NULL;

    while(root->left!=NULL)
        root=root->left;
    return root;
}
/*
Function to delete an element from a binary search tree
*/
tree* DeleteElement(tree *root,int info)
{
    tree* temp;
    if(root==NULL)
        printf("The given data is not present in the binary search tree\n");


    else if (info<root->data)
        root->left=DeleteElement(root->left,info);

    else if (info>root->data)
        root->right=DeleteElement(root->right,info);

    else
    {
        if(root->left!=NULL&&root->right!=NULL)
        {
            temp=FindLargestElement(root->left);
            root->data=temp->data;
            root->left=DeleteElement(root->left,root->data);
        }
        else
        {
            temp=root;
            if(root->left==NULL)
                root=root->right;
            if(root->right==NULL)
                root=root->left;
            free(temp);
            temp=NULL;
        }
    }
    return root;
}

/*
Recursive implementation of Inorder traversal
*/
void inorder(tree *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("  %d", temp->data);
        inorder(temp->right);
    }
}
/*
Recursive implementation of Preorder traversal
*/
void preorder(tree *temp)
{
    if (temp != NULL)
    {
        printf("  %d", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
/*
Recursive implementation of Postorder traversal
*/
void postorder(tree *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("  %d", temp->data);
    }
}
/*Function to count the total number of nodes in a binary search tree
*/
int CountNumberOfNodes(tree* root)
{
    if (root==NULL)
        return 0;
    else
        return CountNumberOfNodes(root->left)+CountNumberOfNodes(root->right)+1;
}
/*
Function to count the number of external nodes in a binary search tree
*/
int CountNumberOfExternalNodes(tree* root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right==NULL)
        return 1;
    else
        return CountNumberOfExternalNodes(root->left)+CountNumberOfExternalNodes(root->right);
}
/*
Function to count the no of internal nodes in a binary search tree
*/
int CountNumberOfInternalNodes(tree* root)
{
    int d=CountNumberOfNodes(root);
    int a=CountNumberOfExternalNodes(root);
    return(d-a);
}
/*
 Function to create mirror of a tree
*/
tree* CreateMirrorOfTree( tree* root)
{
    tree* t;
    if (root==NULL)
        return;
    CreateMirrorOfTree(root->left);
    CreateMirrorOfTree(root->right);
    t= root->left;
    root->left=root->right;
    root->right=t;
    return root;
}
/*
Function to check whether trees are identical or not
*/
int identical_bst(tree* root1, tree* root2)
{
    if (root1==NULL&&root2==NULL)
        return 1;

    if (root1!=NULL && root2!=NULL)
    {
        return( root1->data == root2->data && identical_bst(root1->left, root2->left) && identical_bst(root1->right, root2->right));
    }
    return 0;
}
/*
 *
 *function to check whether a given tree is a valid mirror of the second one or not
 *
 */
int CheckIfValidMirror(tree*root1, tree* root2)
{
    tree* w=CreateMirrorOfTree(root1);
    int a=identical_bst(root2,w);
    return a;
}

void main()
{
    int i,choice,key,x=0;
    tree* t,*q,*y;
    tree* root=NULL;
    for(i=0; i<5; i++)
        printf("\n");

    printf("\nProgram To Demonstrate Operations on Binary Search Trees(bst) ");
    do
    {
        printf("\n1.Insert an element in a bst");
        printf("\n2.Delete an element in a bst");
        printf("\n3.Search an element in a bst");
        printf("\n4.Find the smallest element in a bst");
        printf("\n5.Find the largest element in a bst");
        printf("\n6.Count the total number of nodes in a bst");
        printf("\n7.Count the total number of external nodes in a bst");
        printf("\n8.Count the total number of internal nodes in a bst");
        printf("\n9.Create the mirror of the bst");
        printf("\n10.Check if one tree is valid mirror of the first tree or not");
        printf("\n11.Preorder traversal");
        printf("\n12.Inorder traversal");
        printf("\n13.Postorder traversal");
        printf("\n14.Exit");
        printf("\nEnter your choice :");
        scanf("%d", &choice);
        int d,e;
        switch (choice)
        {
        case 1:

            printf("\nEnter tha data of the node of the bst:");
            scanf("%d",&e);

            if (root == NULL)
                root = create_newnode(e);
            else
                InsertElement(root,e);
            break;
        case 2:

            printf("\nEnter node data to be deleted of the bst:");
            scanf("%d",&d);
            DeleteElement(root,d);
            break;
        case 3:
            printf("\nEnter Element to be searched :");
            scanf("%d", &key);
            SearchElement(root, key);
            break;
        case 4:
            q= FindLargestElement(root);
            printf("The largest element is %d",q->data);
            break;
        case 5:
            q=FindSmallestElement(root);
            printf("The smallest element is %d",q->data);
            break;
        case 6:
            printf("The total number of nodes in the tree is%d\n",CountNumberOfNodes(root));
            break;
        case 7:
            printf("The total number of external nodes in the tree is%d\n",CountNumberOfExternalNodes(root));
            break;
        case 8:
            printf("The total number of internal nodes in the tree is%d\n",CountNumberOfInternalNodes(root));
            break;
        case 9:
            printf("The inorder traversal of the tree is:\n");
            inorder(root);
            printf("\n");
            printf("The inorder traversal of the mirror tree is\n");
            y=CreateMirrorOfTree(root);
            inorder(y);

            break;
        case 10:
            if(CheckIfValidMirror(root,CreateMirrorOfTree(root))==1)
                printf("\nYes");
            else
                printf("\nNo");
            break;
        case 11:
            if (root == NULL)
                printf("No binary search tree is present\n");
            else
            {

                printf("\nThe Preorder traversal of the binary search tree is: ");
                preorder(root);
            }
            break;
        case 12:
            if (root == NULL)
                printf("No binary search tree is present\n");
            else
            {
                printf("\nThe Inorder traversal of the binary search tree is: ");
                inorder(root);
            }
            break;
        case 13:
            if (root == NULL)
                printf("No binary search tree is present\n");
            else
            {
                printf("\nThe Postorder traversal of the binary search tree is: ");
                postorder(root);
            }
            break;
        }
    }
    while (choice!=14);
}

