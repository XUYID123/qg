#ifndef __ZUOYE_H
#define __ZUOYE_H

#include <bits/stdc++.h>
using namespace std;

typedef struct // 链栈
{
    int data; // 数据
    struct x *next;
} x;

x *stackCreate(); // 创建栈
x *Push(x *top);  // 入栈
x *Pop(struct x *top);
void couT(x *top);

int youxian(const string &x);
vector<string> zhongtohou(const vector<string> &infix); // 中缀转后缀
int houzhhuijisuan(const vector<string> &token);        // 计算

#endif
