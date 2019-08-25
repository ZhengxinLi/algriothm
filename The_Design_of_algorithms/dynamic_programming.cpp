//
//  dynamic_programming.cpp
//  The_Design_of_algorithms
//
//  Created by lizhengxin on 2019/7/29.
//  Copyright © 2019 lizhengxin. All rights reserved.
//

#include "dynamic_programming.hpp"
/*   生成动态规划算法所需要的状态矩阵  */
void initmatrix(int **&c,int m,int n){
    c=new int*[m];
    for(int i=0;i<m;i++)
        c[i]=new int[n];
}
/*      给矩阵中的每一个元素赋初识值value */
void initmatrixvalue(int **c,int m,int n,int value){
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            c[i][j]=value;
}
/*        动态规划算法所需的一维向量     */
void initVector(int *&c,int n){
    c=new int[n];
}
/*       给向量d赋初始值               */
void initVectorvalue(int *c,int n,int value){
    for(int i=0;i<n;i++)
        c[i]=value;
}
/*               Fibonacci级数   */
//输入：正整数n
//输出：n的Fibonacci级数
int Fibonacci(int n){
    int *array=new int[n+1];
    array[0]=0;
    array[1]=1;
    for(int i=2;i<n+1;i++)
        array[i]=array[i-1]+array[i-2];  //F[n]=F[n-1]+F[n-2]
    return array[n];
}
/*                币值最大化问题               */
//从硬币数组中选取最大价值，要求不能选取相邻硬币
//输入：硬币值数组
//输出：最大币值
int coinrow(int *coin,int n){  //数组元素从1号单元开始
    int *value=new int[n+1];
    int *s=new int[n+1];
    value[0]=0;
    value[1]=coin[1];
    s[0]=0;
    s[1]=1;
    for(int i=2;i<=n;i++){
        if(value[i-1]>value[i-2]+coin[i]){
            value[i]=value[i-1];
            s[i]=0;
        }
        else{
            value[i]=value[i-2]+coin[i];
            s[i]=1;
        }
    }
    int m=n;
    cout<<"币值选取情况："<<endl;
    while (m>0) {
        if(s[m]==1){
            cout<<m<<"  ";
            m-=2;
        }
        else{
            m--;
        }
    }
    cout<<endl;
    return value[n];
}


/*            找零问题      */
//输入：零钱数额D，需要找的钱值
//输出：最少找零数
int ChangMaking(int *D,int n,int money){
    int *num=new int[money+1];
    int *s=new int[money+1];
    num[0]=0;
    s[0]=0;
    for(int i=1;i<=money;i++){
        int temp=MAX;
        for(int j=1;j<n;j++){
            if(i>=D[j]){
                if(num[i-D[j]]<temp){   //F[i]=min{F(i-D[j]}+1  j=1,2....n
                    temp=num[i-D[j]];
                    s[i]=D[j];
                }
            }
            num[i]=temp+1;
        }
    }
    int m=money;
    while (m>0) {
        cout<<s[m]<<" ";
        m-=s[m];
    }
    cout<<endl;
    return num[money];
}


/*       硬币收集问题     */
//输入：硬币数组，C[i][j]=1,代表该位置有一个硬币，0则表示没有
//输出：从[1][1]到[m][n],每次只能往右，或者往下，能够收集的最大硬币数

int RobotCoinCollection(int **C,int m,int n){
    int **F=new int*[m+1];
    for(int i=0;i<=m;i++)
        F[i]=new int[n+1];
    for(int i=0;i<=m;i++)
        F[i][0]=0;
    for(int i=0;i<=n;i++)
        F[0][i]=0;
    F[1][1]=C[0][0];
    for(int i=1;i<=m;i++){
        
        for(int j=1;j<=n;j++){
            if(F[i-1][j]>F[i][j-1])
                F[i][j]=F[i-1][j]+C[i-1][j-1];
            else
                F[i][j]=F[i][j-1]+C[i-1][j-1];
        }
    }
    return F[m][n];
}

/*           求解最长公共子序列         */
//输入：字符串s，t，以及长度n
//输出：两个字符串的最长公共子序列的长度。（子序列只要求序列下标在原序列中是递增的，不要求连续递增。）
int maxlengthzixulie(char *s,char *t,int n){
    int **length=new int*[n+1];
    for(int i=0;i<n+1;i++)
        length[i]=new int[n];
    for(int i=0;i<n+1;i++){
        length[i][0]=0;
        length[0][i]=0;
    }
    for(int i=1;i<n+1;i++)
        for(int j=1;j<n+1;j++){
            if(length[i-1][j]==length[i-1][j-1]&&length[i][j-1]==length[i-1][j-1])
                if(s[i]!=t[j]){
                     length[i][j]=length[i-1][j-1];
                    continue;
                }
            length[i][j]=length[i-1][j-1]+1;
        }
    return length[n][n];
}
/*          问题同上         */
/*
 c[i+1][j+1]=max{c[i][j]+1,c[i][j+1],c[i+1][j]} if s[i+1]=t[j+1]
 c[i+1][j+1]=max{c[i+1][j],c[i][j+1]}           else
 */
int maxlengthzixulie2(char *s,char *t,int n){
    int **length=new int*[n+1];
    for(int i=0;i<n+1;i++)
        length[i]=new int[n];
    for(int i=0;i<n+1;i++){
        length[i][0]=0;
        length[0][i]=0;
    }
    for(int i=1;i<n+1;i++)
        for(int j=1;j<n+1;j++){
            int max=0;
            if(s[i]==t[j]){
                if(max<(length[i-1][j-1]+1))
                    max=length[i-1][j-1]+1;
                if(max<length[i-1][j])
                    max=length[i-1][j];
                if(max<length[i][j-1])
                    max=length[i][j-1];
            }
            else{
                if(max<length[i-1][j])
                    max=length[i-1][j];
                if(max<length[i][j-1])
                    max=length[i][j-1];
            }
            length[i][j]=max;
        }
    return length[n][n];
}

/*                 求解0-1背包问题          */
//输入：物品的价值，以及权重两个数组，物品的数量，背包的容量，要求下标从1开始
//输出：背包所能装下的最大价值
/*
 
 c[i][j]=max{c[i-1][j-k*weight[i]]+k*v[i]}  k=0,1
 其中需要满足k*weight[i]<=j  即物品i的装载不能超过背包的容量
 */
int bag01(int *value,int *weight,int n,int w){
    int **c=new int*[n+1];
    for(int i=0;i<n+1;i++)
        c[i]=new int[w+1];
    for(int i=0;i<n+1;i++){
        c[i][0]=0;
    }
    for(int i=0;i<w+1;i++){
        c[0][i]=0;
    }
    for(int i=1;i<n+1;i++)
        for(int j=1;j<w+1;j++){
            if((j-weight[i])>=0){
                c[i][j]=(c[i-1][j]>(c[i-1][j-weight[i]]+value[i]))?c[i-1][j]:c[i-1][j-weight[i]]+value[i];
            }
            else{
                c[i][j]=c[i-1][j];
            }
        }
    return c[n][w];
}

/*                  完全背包问题              */
//输入同上，输出同上，要求：物品可以选取任意次，求最大价值
int bagwanquan(int *value,int *weight,int n,int w){
    int **c=new int*[n+1];
    for(int i=0;i<n+1;i++)
        c[i]=new int[w+1];
    for(int i=0;i<n+1;i++){
        c[i][0]=0;
    }
    for(int i=0;i<w+1;i++){
        c[0][i]=0;
    }
    for(int i=1;i<n+1;i++)
        for(int j=1;j<w+1;j++){
            int k=0;
            c[i][j]=0;
            while (j>=(k*weight[i])) {
                if(c[i][j]<c[i-1][j-k*weight[i]]+k*value[i])
                    c[i][j]=c[i-1][j-k*weight[i]]+k*value[i];
                k++;
            }
        }
    return c[n][w];
}

/*              部分和问题，是否能用数字a[i]合成k，其中m[i]记录a[i]的个数*/
//输入：数组a，数组nm，数组的元素个数，需要g合成的数字k
//输出：是否能够合成，若能输出合成的式子
void bufenhe(int *a,int *m,int n,int k){
    int **c;
    int **s;
    initmatrix(c, n+1, k+1);
    initmatrixvalue(c, n+1, k+1, 0);
    initmatrix(s, n+1, k+1);
    initmatrixvalue(s, n+1, k+1, 0);
    for(int i=0;i<n+1;i++)
        c[i][0]=1;
    for(int i=1;i<n+1;i++)
        for(int j=1;j<k+1;j++){
            int t=0;
            while (t*a[i]<=j&&t<=m[i]) {
                if(c[i-1][j-t*a[i]]){
                    c[i][j]=1;
                    break;
                }
                t++;
            }
            if(t*a[i]<=j)
                s[i][j]=t;
            else{
                s[i][j]=-1;
                c[i][j]=0;
            }
        }
    if(c[n][k]){
        cout<<"存在";
        while(n){
            if(s[n][k]==0)
                n--;
            else{
                cout<<s[n][k]<<"*"<<a[n]<<",";
                k-=s[n][k]*a[n];
                n--;
            }
        }
        cout<<endl;
    }
    else
        cout<<"不存在"<<endl;
}

/*           最长上升子序列       */
//输入：数组元素，以及数组长度，元素起始位置：1
//输出：最长序列的长度
//思路：d[k]=max{d[i]+(a[k]>a[i])?1:0}  i=1,2....k-1     d[i]表示前i个元素的最长序列，且该序列最大元素为a[i]
int zuichangzixulie(int *a,int n){
    int *c;
    initVector(c, n+1);
    initVectorvalue(c, n+1, 0);
    c[1]=1;
    for(int i=2;i<n+1;i++){
        int maxlength=1;
        for(int j=i-1;j>=1;j--){
            int temp=c[j];
            temp+=(a[i]>a[j])?1:1-temp;
            if(maxlength<temp)
                maxlength=temp;
        }
        c[i]=maxlength;
    }
    return c[n];
}

/*  将n个无区分的球分成最多m组的方案数     */
//输入：n，m，n为球的数量，m为最多组数
//输出：m划分n的方案数目
/*思路：c[i][j]=c[i-j][j]+c[i][j-1]
 将i个球划分最多j组的方案，相当于将i个球划分最多j-1组的方案，和将i个球划分为j组的方案
 而将i个球划分为j组的方案相当于将i-j个球划分为最多i组的情况U将j个球分成j组的情况
 所以上式成立
 */
int mdividen(int m,int n){
    int **c;
    initmatrix(c, n+1, m+1);
    for(int i=0;i<m+1;i++)
        c[0][i]=1;
    for(int i=1;i<n+1;i++)
        c[i][0]=0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(i-j>=0)
                c[i][j]=c[i-j][j]+c[i][j-1];
            else
                c[i][j]=c[i][j-1];
        }
    }
    return c[n][m];
}
