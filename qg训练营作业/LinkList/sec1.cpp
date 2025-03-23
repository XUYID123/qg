#include <bits/stdc++.h>
using namespace std;                
struct x
{
    int data; // 数据
    struct x *next;
};
struct x *stackCreate() // 创建栈
{
    struct x *top = NULL;
    return top;
}
struct x *Push(struct x *top) // 入栈
{
    struct x *newnode = (struct x *)malloc(sizeof(struct x));
    cin >> newnode->data;
    newnode->next = top;
    top = newnode; // 更新栈顶
    return top;
}
struct x *Pop(struct x *top)
{
    if (top == NULL)
        return top;
    struct x *temp = top;
    top = top->next;
    cout << temp->data << endl; // 显示弹出节点数据
    free(temp);
    return top;
}
void couT(struct x *top)
{
    if (top == NULL)
        return;
    cout << top->data << endl;
}
int main()
{
    struct x *top = stackCreate();
    for (int i = 0; i < 3; i++)              //i为链栈长度
    {
        top = Push(top);                     //压入数据
        couT(top); 
    } 
    for (int i = 0; i < 3; i++)
    {
        top = Pop(top);                  //弹出数据
    }
    return 0;
}