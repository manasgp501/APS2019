#include <stdio.h>
#include <stdlib.h>
int n;


int partition(int arr[n],int l,int h)
{
    int pivot,i,j,temp;
    pivot=arr[h];
    i=l-1;
    for(j=l;j<n;j++)
    {
        if(pivot>arr[j])
        {
            i++;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=pivot;
    arr[h]=temp;
    printf("****************\n");
    for(j=0;j<n;j++)
    {
        printf("%d\n",arr[j]);
    }
    return (i+1);
}

void quick(int arr[n],int l,int h)
{
    int pi;
    if(l<h)
    {
       pi=partition(arr,l,h);
       quick(arr,l,pi-1);
       quick(arr,pi+1,h);
    }
}

int main()
{
    scanf("%d",&n);
  int i,arr[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("**********\n");
    quick(arr,0,n);
   // for(i=0;i<n;i++)
    //{
      //  printf("%d",arr[i]);
   // }
}
