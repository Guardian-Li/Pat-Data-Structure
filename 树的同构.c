//
//  main.c
//  树的同构
//
//  Created by 郭晓芃 on 2018/9/20.
//  Copyright © 2018年 郭晓芃. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define Null -1
#define maxn 100
//typedef Tree* T;
struct Tree{
    int Right;
    int Left;
    char Data;
} T1[maxn],T2[maxn];
int Read(struct Tree T[]);
int Isomorphic(int R1,int R2);
int main(void) {
    int R1 = Read(T1);
    int R2 = Read(T2);
    if(Isomorphic(R1, R2))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
    
    
    
    
}
int Read(struct Tree T[])
{
    int n,i,Root;
    Root = Null;
//    char cl,cr;
    int check[maxn]={0};
    scanf("%d",&n);
    if(n){
        for(i=0; i<n; ++i){
            char R,L;
            scanf("\n%c %c %c",&T[i].Data,&L,&R);
            if(L == '-'){
                T[i].Left = Null;
            }
            else{
                T[i].Left = L - '0';
                check[T[i].Left] = 1;
            }
                
            if(R == '-'){
                T[i].Right = Null;
            }
            else{
                T[i].Right = R - '0';
                check[T[i].Right] = 1;
            }
                
        }
//        for end
        for(i=0; i<n; ++i)
            if(check[i] == 0)
//                等于0的时候说明没有指向这个节点的 指针 说明这个节点是根结点
                break;
        Root = i;
    }
    return  Root;
}
int Isomorphic(int R1, int R2)
{
    if(R1 ==Null && R2 == Null){
        return 1;
    }
    else if((R1 == Null && R2!=Null)||(R1 != Null && R2 == Null))
        return 0;
    if(T1[R1].Data != T2[R2].Data)
        return 0;
    if((T1[R1].Left == Null) && (T2[R2].Left == Null))
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    if((T1[R1].Left !=Null) && (T2[R2].Left !=Null) &&(T1[T1[R1].Left].Data == T2[T2[R2].Left].Data))
        return (Isomorphic(T1[R1].Left,T2[R2].Left)&&Isomorphic(T1[R1].Right,T2[R2].Right));
    else
        return (Isomorphic(T1[R1].Left,T2[R2].Right)&&Isomorphic(T1[R1].Right,T2[R2].Left));
}
