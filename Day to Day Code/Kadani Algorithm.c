#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a[100],n,max=0,tmax=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        tmax=tmax+a[i];
        if(tmax<0)
            tmax=0;
        if(max<tmax)
            max=tmax;
    }
    printf("%d",max);
}
