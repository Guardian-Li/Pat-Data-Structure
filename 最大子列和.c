#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,sum,max;
    scanf("%d",&n);
    int *p = (int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        scanf("%d",&p[i]);
    sum=0;
    max=0;
    for(i=0; i<n; i++)
    {
        sum+=p[i];
        if(sum<0)
            sum=0;
        else if(sum>max)
            max=sum;
    }
    printf("%d\n",max);
    return 0;
}
