//
//  dynamic_programming.hpp
//  The_Design_of_algorithms
//
//  Created by lizhengxin on 2019/7/29.
//  Copyright © 2019 lizhengxin. All rights reserved.
//

#ifndef dynamic_programming_hpp
#define dynamic_programming_hpp

#include <iostream>
#define MAX 10000;
using namespace std;
void initmatrix(int **&c,int m,int n);
void initmatrixvalue(int **c,int m,int n,int value);
void initVector(int *&c,int n);
void initVectorvalue(int *c,int n,int value);
/*    动态规划算法程序设计   */
int Fibonacci(int n);
int coinrow(int *coin,int n);
int ChangMaking(int *D,int n,int money);
int RobotCoinCollection(int **C,int m,int n);
int maxlengthzixulie(char *s,char *t,int n);
int maxlengthzixulie2(char *s,char *t,int n);
int bag01(int *value,int *weight,int n,int w);
int bagwanquan(int *value,int *weight,int n,int w);
void bufenhe(int *a,int *m,int n,int k);
int zuichangzixulie(int *a,int n);
int mdividen(int m,int n);
#endif /* dynamic_programming_hpp */
