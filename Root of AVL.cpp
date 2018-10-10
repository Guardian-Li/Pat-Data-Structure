//
//  main.cpp
//  Root of AVL
//
//  Created by 郭晓芃 on 2018/10/6.
//  Copyright © 2018年 郭晓芃. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Tree* Position;
struct Tree{
    int height;
    int Data;
    Position Left;
    Position Right;
};

typedef Position T;
int Height(Position Tree){
    if(Tree == NULL)
        return  -1;
    else
        return 1+max(Height(Tree->Left),Height(Tree->Right));
    
}
Position LL(Position K2){
    Position K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    K2->height = 1+max(Height(K2->Left),Height(K2->Right));
    K1->height = 1+max(Height(K1->Left),Height(K1->Right));
    return K1;
}
Position RR(Position K2){
    Position K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    K2->height = 1+max(Height(K2->Left),Height(K2->Right));
    K1->height = 1+ max(Height(K1->Left),Height(K1->Right));
    return K1;
    
}
Position LR(Position K3){
    K3->Left = RR(K3->Left);
    return LL(K3);
}
Position RL(Position K3){
    K3->Right = LL(K3->Right);
    return  RR(K3);
}
Position Insert(int X,Position Root){
    if(Root == NULL){
        Root = (T)malloc(sizeof(struct Tree));
        Root->Data = X;
        Root->Left = Root->Right = NULL;
        Root->height=0;
    }else if(Root->Data > X){
        Root->Left = Insert(X, Root->Left);
        if(Height(Root->Left)-Height(Root->Right) == 2)
        {
            if(X < Root->Left->Data)
                Root = LL(Root);
            else
                Root = LR(Root);
        }
    }else if( X > Root->Data){
        Root->Right = Insert(X, Root->Right);
        
        if(Height(Root->Right)- Height(Root->Left) == 2){
            if(X> Root->Right ->Data)
                Root = RR(Root);
            else
                Root = RL(Root);
        }
    }
    Root->height = max(Height(Root->Right),Height(Root->Left))+1;
    return  Root;
}

int main(void){
    int n;
    cin>>n;
    Position Root = NULL;
    for (int i = 0; i<n; i++) {
        int tmp;
        cin>>tmp;
        Root = Insert(tmp, Root);
    }
    printf("%d\n",Root->Data);
    return 0;
    
    
}
