#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,j,max,sum;
    scanf("%d",&n);
    int *p = (int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++)
        scanf("%d",&p[i]);
    j=0;
    i=0;
    sum=0;
    max=-1;
    int begin=n-1;
    int end=n-1;
    while( i<n && j<n){
        sum+=p[j];
        if(sum>max){
            max=sum;
            begin=i;
            end=j;
        }
        else if(sum<0){
            sum = 0;
            i=j+1;
        }
        j++;
    }
    if(max<0)
        printf("0 %d %d",p[0],p[n-1]);
    else
        printf("%d %d %d",max,p[begin],p[end]);


    return 0;
}
