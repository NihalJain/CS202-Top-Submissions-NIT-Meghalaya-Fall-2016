/* PROGRAM TO IMPLEMENT THE FOLLOWING SORTING ALGORITHMS
                SELECTION SORT
                INSERTION SORT
                MERGE SORT
                QUICK SORT


                SUBMITTED BY
                CHANDRANI KAR
                ROLL NUMBER: B15CS031
                ASSIGNMENT NO 6
                */
#include<stdio.h>
/*Function to implement selection sorting..
input:
a: array
n: number of elements in the array
*/
void selsort(int a[],int n)
{
    int i,j,temp,small;
    for (i = 0; i <n-1; i++)
    {
        small=i;
        for(j = i+1; j < n; j++)
        {
            if(a[j] < a[small])
                small=j;
        }
        temp=a[small];
        a[small]=a[i];
        a[i]=temp;
    }
}

/*Function to implement insertion sorting..
input:
a: array
n: number of elements*/
void insertsort(int a[],int n)
{
    int i,j,z;
    for(j=1; j<n-1; j++)
    {
        z=a[j];
        i=j-1;
        while(i>=0 && a[i]>z)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=z;
    }
}
/*Function to partition in quick sorting..
input:
array a
l:leftmost index
r:rightmost index
*/
int partq(int a[],int l,int r)
{
    int down,up,temp;
    int pivot=a[l];
    up=r;
    down=l;
    while(up>down)
    {

        while(a[down]<=pivot)
            down++;
        while(a[up]>pivot)
            up--;
        if(down<up)
        {
            temp=a[down];
            a[down]=a[up];
            a[up]=temp;
        }
    }
    a[l]=a[up];
    a[up]=pivot;
    return up;

}
/*
Recursive function to sort an array using quick sort..
a: array
pivot: pivot element
*/
void qsort(int a[],int l,int r)
{
    int pivot;
    if(l<r)
    {
        pivot=partq(a,l,r);
        qsort(a,l,pivot-1);
        qsort(a,pivot+1,r);
    }
}
/*Function to do the merging
a: array
m:mid
l:leftmost index
r:rightmost index*/
void merge(int a[],int temp[],int l,int m,int r)
{
    int i,lend,n,t;
    n=r-l+1;
    lend=m-1;
    t=l;
    while(l<=lend && m<=r)
    {
        if(a[l]<=a[m])
            temp[t++]=a[l++];
        else
            temp[t++]=a[m++];
    }
    while(l<=lend)
        temp[t++]=a[l++];
    while(m<=r)
        temp[t++]=a[m++];

    for(i=0; i<n; i++)
    {
        a[r]=temp[r];
        r--;
    }
}
/*recursive function to implement merge sort
a:array
t:temp array
l:leftmost index
r:rightmost index
*/
void merges(int a[],int t[],int l,int r)
{
    int m;
    if(r>l)
    {
        m=(l+r)/2;
        merges(a,t,l,m);
        merges(a,t,m+1,r);
        merge(a,t,l,m+1,r);
    }
}
/*
Function to print the array
*/
void print(int a[],int n)
{
    int i;
    for(i = 0; i < n; i++ )
        printf("%d\t",a[i]);
    printf("\n");
}


int main()
{
    int a[100],t[100],i,n,c;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements which we have to sort: ");
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    do
    {
        printf("ENTER THE SORTING METHOD WHICH YOU WANT TO USE:\n");
        printf("1.SELECTION SORT\n");
        printf("2.INSERTION SORT\n");
        printf("3.MERGE SORT\n");
        printf("4.QUICK SORT\n");
        printf("5.EXIT\n");
        printf("ENTER CHOICE\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nSorted array using selection sorting is:\n ");
            selsort(a,n);
            print(a,n);
            break;

        case 2:
            printf("\nSorted array using insertion sorting is:\n ");
            insertsort(a,n);
            print(a,n);
            break;

        case 3:
            printf("\nSorted array using merge sorting is:\n ");
            merges(a,t,0,n-1);
            print(a,n);
            break;

        case 4:
            printf("\nSorted array using quick sorting is:\n ");
            qsort(a,0,n-1);
            print(a,n);
            break;

        case 5:
            break;

        default:
            printf("Invalid choice\n");
            break;
        }
    }
    while(c!=5);
    return 0;
}
