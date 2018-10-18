//
//  main.cpp
//  栈排序
//
//  Created by 郭晓芃 on 2018/10/15.
//  Copyright © 2018年 郭晓芃. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main(void) {
    stack<int > S;
    stack<int > R;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        R.push(tmp);
    }
    if(!R.empty()){
        int t = R.top();
        R.pop();
        while(!R.empty()||(!S.empty() && S.top() < t)){
            if(S.empty() || S.top() >= t)
            {
                S.push(t);
                t = R.top();
                R.pop();
            }else{
                R.push(S.top());
                S.pop();
            }
        }
         S.push(t);
    }
    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }
    return 0;
}
