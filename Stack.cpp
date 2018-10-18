//
//  main.cpp
//  栈
//
//  Created by 郭晓芃 on 2018/10/18.
//  Copyright © 2018年 郭晓芃. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
typedef struct stack_{
    int top;
    char data[100010][30];
    
}stack;
int main(void) {
    stack s;
    s.top = -1;
    int n,op;
    scanf("%d",&n);
    for(int i=0 ;i<n; i++){
        scanf("%d",&op);
        if(op == 1){
            s.top++;
            scanf("%s",s.data[s.top]);
        }else if(op == 2){
            printf("%s\n",s.data[s.top]);
            s.top--;
        }else{
            int index;
            scanf("%d",&index);
            printf("%s\n",s.data[index-1]);
        }
    }
    return 0;
}
