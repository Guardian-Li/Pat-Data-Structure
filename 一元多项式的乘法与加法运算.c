//
//  一元多项式的乘法与加法运算.c
//  一元多项式的乘法与加法运算
//
//  Created by 郭晓芃 on 2018/9/17.
//  Copyright © 2018年 郭晓芃. All rights reserved.
//4 3 4 -5 2  6 1  -2 0
//3 5 20  -7 4  3 1
//5 20 -4 4 -5 2 9 1 -2 0 多项式相加
#include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
struct Node{
    int coef;
    int index;
    PtrToNode Next;
};
typedef PtrToNode List;
List Read(void);
void Print(List head);
List ListPlus(List L1,List L2);
List ListMutil(List L1,List L2);
int main()
{
    List L1,L2;
    L1 = Read();
    L2 = Read();
    //    int sum = L1->coef+L2->coef;
    //    int musum = L1->coef*L2->coef;
    //    printf("%d ",sum);
    Print(ListMutil(L1,L2));
    Print(ListPlus(L1,L2));
    //Print(L1);
    //Print(L2);
    return 0;
    
    
}
List Read(void)
{
    List head = (List)malloc(sizeof(struct Node));
    List Last = head;
    int n,i,coef,index;
    scanf("%d",&n);
    head->coef =n;
    for( i=0 ; i<n; ++i){
        List tmp = (List)malloc(sizeof(struct Node));
        scanf("%d%d",&coef,&index);
        tmp->Next = NULL;
        tmp->coef = coef;
        tmp->index = index;
        Last->Next = tmp;
        Last = Last->Next;
    }
    return head;
}
void Print(List head)
{
    List p = head->Next;
    if(!p)
        printf("0 0\n");
    else{
        for(  ; p!=NULL;p=p->Next){
            printf("%d %d",p->coef,p->index);
            if(p->Next != NULL)
                printf(" ");
        }
        printf("\n");
    }
}
//ListPlus就是两个链表插入合并的过程 两个链表原本是有序的 Two Pointers 插入
//两个链表的指数从高到低降序排列
List ListPlus(List L1,List L2)
{
    List p,q;
    p = L1->Next;
    q = L2->Next;
    List head = (List)malloc(sizeof(struct Node));
    List Last = head;
    while(p != NULL && q != NULL)
    {
        List tmp = (List)malloc(sizeof(struct Node));
        tmp->Next = NULL;
        if (p->index > q->index) {
            tmp->coef = p->coef;
            tmp->index = p->index;
            Last->Next =tmp;
            //            Last = Last->Next;
            p = p->Next;
        }
        else if(p->index < q->index){
            tmp->coef = q->coef;
            tmp->index = q->index;
            Last->Next = tmp;
            //            Last = Last->Next;
            q = q->Next;
        }
        else{
            tmp->coef = p->coef+q->coef;
            tmp->index = p->index;
            p = p->Next;
            q = q->Next;
            Last->Next = tmp;
            //            Last = Last->Next;
        }
        if(tmp->coef == 0)
        {
            free(tmp);
            Last->Next=NULL;
//          free释放指针之后 指针依然存在 指向一块地址 head后并不是NULL指针
        }
        else
            Last = Last->Next;
    }
    while(p !=NULL )
    {
        List tmp = (List)malloc(sizeof(struct Node));
        tmp->coef = p->coef;
        tmp->index = p->index;
        tmp->Next = NULL;
        Last->Next = tmp;
        Last = Last->Next;
        p = p->Next;
    }
    while (q !=NULL ){
        List tmp = (List)malloc(sizeof(struct Node));
        tmp->coef = q->coef;
        tmp->index = q->index;
        tmp->Next = NULL;
        Last->Next = tmp;
        Last = Last->Next;
        q = q->Next;
    }
    return head;
}
List ListMutil(List L1,List L2)
{
    List head = (List)malloc(sizeof(struct Node));
//    List Last = head;
    head->Next = NULL;
    List tempL = (List)malloc(sizeof(struct Node));
    List LastT = tempL;
    List p,q;
    for(p = L1->Next; p!=NULL; p =p->Next){
        for(q = L2->Next; q!=NULL; q = q->Next){
            List tmp = (List)malloc(sizeof(struct Node));
            tmp->coef =(p->coef)*(q->coef);
            tmp->index = p->index + q->index;
            if(tmp->coef == 0)
                tmp->index = 0;
            LastT->Next = tmp;
            LastT = LastT->Next;
        }
        head = ListPlus(head, tempL);
        tempL->Next = NULL;
        LastT = tempL;
    }
    return head;
}

