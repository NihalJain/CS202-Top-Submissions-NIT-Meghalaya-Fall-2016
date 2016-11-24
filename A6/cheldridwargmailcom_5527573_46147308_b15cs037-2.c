#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 256


int partition(int a[], int lower, int upper)  //partition function to find the position of the pivot
{
    int pivot, i, j, temp;
    pivot = a[lower];
    i = lower + 1;
    j = upper;
    while (i < j)
    {
        while((i < upper) && (a[i] <= pivot)) i++;
        while (a[j] > pivot) j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    if (pivot > a[j])
    {
        temp = a[j];
        a[j] = a[lower];
        a[lower] = temp;
    }
    return j;
}

void quick(int a[], int lower, int upper)
{
    int loc;
    if (lower < upper)
    {
        loc = partition(a, lower, upper);//finding the position of the pivot
        quick(a, lower, loc-1);//left recursive call
        quick(a, loc+1, upper);//right recursive call
    }
    else
        return;
}
void main()
{
    int a[ARRAY_SIZE],i,n;
    printf("\nenter size of array:");
    scanf("%d",&n);
    printf("\nenter array elements one by one for quicksort:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\nArray after quicksort:\n");
    quick(a,0,n-1);//calling quick sort;
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nenter array elements one by one for merge sort:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\n array after merge sort:");
    mergeSort(a,0,n-1);//calling merge sort
    for(i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\nenter array elements one by one for bubble sort:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);//calling bubble sort
    printf("\narray after bubble sort:");
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\nenter array elements one by one for insertion sort:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\narray after insertion  sort:");
    insert_sort(a,n);//calling insertion sort
    for(i=0; i<n; i++)
        printf("%d ",a[i]);
    printf("\nenter array elements one by one for selection sort:");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\narray after selection  sort:");
    selection_sort(a,n);//calling selection sort
    for(i=0; i<n; i++)
        printf("%d ",a[i]);

}
void mergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        int m;
        m= (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,m+1,r);
    }
}
void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[50];    //temporary array used for merging
    int i,j,k;
    i=i1;    //beginning of the first list
    j=i2;    //beginning of the second list
    k=0;

    while(i<=j1 && j<=j2)    //while elements in both lists
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)    //to copy the remaining elements of the first part and second part
        temp[k++]=a[i++];

    while(j<=j2)
        temp[k++]=a[j++];

    //Transfer elements from temp back to a[]
    for(i=i1,j=0; i<=j2; i++,j++)
        a[i]=temp[j];
}
void bubble_sort(int a[],int n)
{
    int i,j,temp=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}
void insert_sort(int a[],int n)
{
    int i,j,k,key;
    for(j=1; j<n; j++)
    {
        i=j-1;
        key=a[j];
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;
        }
        a[i+1]=key;
    }
}
void selection_sort(int a[],int n)
{
    int min=0,j,i,temp=0;
    for ( i = 0 ; i < ( n - 1 ) ; i++ )
    {
        min = i;

        for ( j = i + 1 ; j < n ; j++ )
        {
            if ( a[min] > a[j] )
                min = j;
        }
        if ( min != i )
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

}

//void swap(int a,int b){
//int temp=0;
//temp=b;
//b=a;
//a=temp;}


