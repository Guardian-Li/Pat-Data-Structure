//
//  两个有序链表合并.c
//  Pat&Data Structure
//
//  Created by 郭晓芃 on 2018/9/15.
//  Copyright © 2018年 郭晓芃. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
//在Xcode里括号里不写Void会警告 
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
/* 你的代码将被嵌在这里 */
//在合并中要完全使用原来的节点，当出现重复的时候两个节点要并列排在新链表中

List Merge( List L1, List L2 )
{
    List p,q,head,last;
    head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    last = head;
    p = L1->Next;
    q = L2->Next;
    while(p && q)
    {
        if(p->Data <= q->Data){
            last->Next = p;
            p = p->Next;
            last = last->Next;
        }
        else{
            last->Next = q;
            q = q->Next;
            last = last->Next;
        }
    }
    last->Next = p ? p : q;
    L1->Next = NULL;
    L2->Next = NULL;
    return  head;
}
List Read(  )
{
    int n,i,tmp;
    List head;
    scanf("%d",&n);
    head = (List)malloc(sizeof(struct Node));
    head->Next = NULL;
    List last = head;
    for(i = 0; i < n; ++i)
    {
        scanf("%d",&tmp);
        List p = (List)malloc(sizeof(struct Node));
        p->Next = NULL;
        p->Data = tmp;
        last->Next = p;
        last = last->Next;
    }
    return head;
}
void Print(List head)
{
    List p;
    if(!(head->Next))
        printf("NULL");
    for(p = head->Next ; p != NULL; p = p->Next)
    {
        if(p == head->Next)
            printf("%d",p->Data);
        else
            printf(" %d",p->Data);
            
    }
    printf("\n");
}










