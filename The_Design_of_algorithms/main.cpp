//
//  main.cpp
//  The_Design_of_algorithms
//
//  Created by lizhengxin on 2019/7/29.
//  Copyright © 2019 lizhengxin. All rights reserved.
//

#include "dynamic_programming.hpp"

int main() {
    // insert code here...
     cout<<"Fibonacci级数："<<endl;
    for(int i=0;i<=10;i++)
        cout<<Fibonacci(i)<<" ";
    cout<<endl;
    
    cout<<"币值最大化问题："<<endl;
    int coin[]={0,5,1,2,10,6,2};
    cout<<coinrow(coin, 6)<<endl;;
   
    cout<<"找零问题："<<endl;
    int D[]={1,3,4};
    cout<<ChangMaking(D, 3, 6)<<endl;
    
    
    cout<<"硬币收集问题："<<endl;
  
    int A[5][6]={{0,0,0,0,1,0},{0,1,0,1,0,0},{0,0,0,1,0,1},{0,0,1,0,0,1},{1,0,0,0,1,0}};
    int **C=new int*[5];
    for(int i=0;i<5;i++)
        C[i]=new int[6];
    for(int i=0;i<5;i++)
        for(int j=0;j<6;j++)
            C[i][j]=A[i][j];
    cout<<RobotCoinCollection(C, 5, 6)<<endl;
   
    cout<<"最长公共子序列："<<endl;
    char s[]="abcdkjshaiuehcjauwa";
    char t[]="dnasdhwakdkawdhkawh";
    cout<<maxlengthzixulie(s, t, 19)<<endl;
    cout<<maxlengthzixulie2(s, t, 19)<<endl;
    
    cout<<"背包问题："<<endl;
    int value[]={0,1,2,3,4,5};
    int weight[]={0,2,1,5,7,4};
    int w=10;
    cout<<bag01(value, weight, 5, w)<<endl;
    cout<<bagwanquan(value, weight, 5, w)<<endl;
    
    cout<<"部分和问题："<<endl;
    int a[]={0,3,5,8};
    int m[]={0,3,2,2};
    int k=30;
    bufenhe(a, m, 3, k);
   
    
    cout<<"最长子序列："<<endl;
    int c[]={0,4,2,3,1,5};
    cout<<zuichangzixulie(c, 5)<<endl;
    
    cout<<"m划分n:"<<endl;
    cout<<mdividen(2, 10)<<endl;
    return 0;
}
