#include<stdio.h>
#define maxn 11
#define Null -1
//int cnt=0;
struct Tree{
    int Data;
    int Right;
    int Left;
}T[maxn];
struct queue{
  int rear;
  int front;
  int Data[maxn];
}Q;
int Read();
void Leaves(int Root);
int main()
{
    int Root;
    Root = Read();
    //printf("%d\n",Root);
    Leaves(Root);
    return 0;
}
void Leaves(int Root)
{
    int queue[maxn];
    //int rear = -1;
    //int front = 0;
    int leaves = 0;
    Q.rear = -1;
    Q.front = 0;
    Q.Data[++Q.rear] = Root;
    while (Q.rear != Q.front -1){
        int node = Q.Data[Q.front++];
        if(T[node].Left == Null && T[node].Right == Null)
        {
            if(leaves)
                printf(" ");
            printf("%d",node);
            ++leaves;
        }
        if(T[node].Left != Null)
            Q.Data[++Q.rear] = T[node].Left;
        if(T[node].Right != Null)
            Q.Data[++Q.rear] = T[node].Right;
    }
}

int Read()
{
    int n,i,Root;
    Root = Null;
    int checked[maxn]={0};
    scanf("%d",&n);
    if(n){
        for(i=0 ; i<n; ++i){
        char L,R;
        scanf("\n%c %c",&L,&R);
        if(L != '-'){
            T[i].Data = i;
            T[i].Left = L - '0';
            checked[T[i].Left] = 1;
        }
        else{
            T[i].Left = Null;
            T[i].Data = i;
        }
        if( R != '-'){
            T[i].Data = i;
            T[i].Right = R -'0';
            checked[T[i].Right] = 1;
        }
        else{
            T[i].Right = Null;
            T[i].Data = i;
        }
        }
        for(i=0; i<n; ++i){
            if(checked[i] == 0)
                break;
        }
        Root = i;
    }
    return Root;
}
