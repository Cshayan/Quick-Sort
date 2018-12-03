#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high)
{
    int i, temp;
    int pivot= arr[high];
    int partitionIndex= low;

    for(i=low; i<high; i++)
    {
        if(arr[i] <= pivot)
        {
            temp= arr[i];
            arr[i]= arr[partitionIndex];
            arr[partitionIndex]= temp;

            partitionIndex++;
        }
    }

    //swap the partition index element with pivot
    temp= arr[partitionIndex];
    arr[partitionIndex]= arr[high];
    arr[high]= temp;

    return partitionIndex;
}
void quick_sort(int arr[], int low , int high)
{
    if(low < high)
    {
      int partitionIndex= partition(arr, low, high);

      quick_sort(arr, low, partitionIndex-1);
      quick_sort(arr, partitionIndex+1, high);
    }
}

int main()
{
    int *arr;
    int n, i, low, high;
    printf("\nEnter the size of the array:- ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    printf("\nEnter the array to be sorted:- \n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    low = 0; high = n-1;
    quick_sort(arr, low, high);
    printf("\nAfter sorting :-\n ");
    for(i=0; i< n; i++)
        printf("%d\t", arr[i]);

        printf("\n");
}
