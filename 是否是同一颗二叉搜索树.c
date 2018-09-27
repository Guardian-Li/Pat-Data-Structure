//
//  main.c
//  是否是同一颗二叉搜索树
//
//  Created by 郭晓芃 on 2018/9/27.
//  Copyright © 2018年 郭晓芃. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef struct Tree* Position;
struct Tree{
    int Data;
    Position Right;
    Position Left;
    int flag;
};
typedef Position T;
int check(T Tree, int X);
int Judge(int N,T Tree);
void Reset(T Tree){
    if(Tree->Left) Reset(Tree->Left);
    if(Tree->Right) Reset(Tree->Right);
    Tree->flag = 0;
}
void FreeTree(T Tree){
    if(Tree->Left) FreeTree(Tree->Left);
    if(Tree->Right) FreeTree(Tree->Right);
    free(Tree);
}
T Insert(T BST, int V){
    if(!BST){
        BST = (T)malloc(sizeof(struct Tree));
        BST->Left=BST->Right = NULL;
        BST->Data = V;
        BST->flag = 0;
    }else{
        if(BST->Data > V)
            BST->Left = Insert(BST->Left, V);
        else if(BST->Data < V)
            BST->Right = Insert(BST->Right, V);
    }
    return BST;
}
T MakeTree(int n){
    T Tree;
    int i,V;
    scanf("%d",&V);
    Tree = (T)malloc(sizeof(struct Tree));
    Tree->Left=Tree->Right = NULL;
    Tree->Data =V;
    Tree->flag=0;
    for(i=1;i<n; i++){
        scanf("%d",&V);
        Tree = Insert(Tree, V);
    }
    return  Tree;
}
int main(void)
{
    int n,L,i;
    scanf("%d",&n);
    T base=NULL;
    while(n){
        scanf("%d",&L);
        base = MakeTree(n);
        for(i=0; i<L; i++){
            if(Judge(n,base))
                printf("Yes\n");
            else
                printf("No\n");
            Reset(base);
        }
        FreeTree(base);
        scanf("%d",&n);
    }
    return 0;
    
    
}
int check(T Tree,int X)
{
    if(Tree->flag){
        if(Tree->Data>X)
            return  check(Tree->Left,X);
        else if(Tree->Data<X)
             return check(Tree->Right,X);
        else
            return 0;
    }
    else{
        if(X == Tree->Data){
            Tree->flag=1;
            return 1;
        }
        else{
            return 0;
        }
    }
    return 1;
}
int Judge(int N,T Tree)
{
    int i, V;
    int flag=0;
    scanf("%d",&V);
    if(Tree->Data != V)
        flag = 1;
    else
        Tree->flag = 1;
    for(i=1;i<N; i++){
        scanf("%d",&V);
        if((!check(Tree,V)) && (!flag)){
            flag = 1;
        }
    }
    if(flag) return 0;
    else return 1;
}
