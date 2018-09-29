//
//  卖个萌.cpp
//  卖个萌
//
//  Created by 郭晓芃 on 2018/9/28.
//  Copyright © 2018年 郭晓芃. All rights reserved.
//
//有bug版本
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int flag=1;
//如果超出范围 就令flag = 0,最后不输出表情,删除vector
string find(string s,int n){
    int cnt=0;
    int i=0;
    while(cnt != n && (i)<s.length()){
        if(s[i] == '[')
            cnt ++;
        i++;
    }
    int index = i;
    if(i == s.length() || n < 1)
//    当i == s.length()时候表示没找到 当cnt为负数的时候也找不到 但是当n == 0 会出现错误
    {
        printf("Are you kidding me? @\\/@");
        flag = 0;
//        flag = 0之后后面的就不用输出vector了
    }
    else{
        while(s[i]!=']')
        {
            i++;
        }
    }
    string tmp = s.substr(index,i-index);
//    i是结束的地址 index是开始的地址 相减表示长度
    return tmp;
}
int main(void)
{
    string s[3];
    vector<string> face;
//    用来存储放好的表情
    for(int i=0 ;i<3; i++)
        getline(cin,s[i]);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        for(int k=0; k<5; k++){
            int tmp;
            scanf("%d",&tmp);
            if(k==0 || k== 4){
                if(k==4)
                    face.push_back(")");
                face.push_back(find(s[0],tmp));
            if(!flag)
                break;
            }
            else if(k==1|| k==3){
                if(k==1)
                    face.push_back("(");
                face.push_back(find(s[1],tmp));
                if(!flag)
                    break;
            }
            else{
                face.push_back(find(s[2],tmp));
                if(!flag)
                    break;
            }
        }
        if(flag){
            for(int j=0; j<face.size(); j++)
            {
                cout<<face[j];
            }
        }
        printf("\n");
        flag =1;
        face.clear();
//        vector清空
    }
    return 0;
}
