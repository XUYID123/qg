#include <bits/stdc++.h>
using namespace std;

// 比较运算符优先级
int youxian(const string &x)
{
    if (x == "+" || x == "-")
        return 1;
    if (x == "*" || x == "/")
        return 2;
    return 0; //   是左括号则返回0；
}

// 中缀转后缀
vector<string> zhongtohou(const vector<string> &infix)
{
    stack<string> st;
    vector<string> postfix;
    for (const string &element : infix)
    {
        if (isalnum(element[0])) // 判断是数字，则直接进入数组
            postfix.push_back(element);
        else if (element == "(") // 如果是左括号，直接进入栈
        {
            st.push(element);
        }
        else if (element == ")") // 如果是右括号
        {
            while (!st.empty() && st.top() != "(")
            { // 遇到左括号之前不断弹出压入栈的符号
                postfix.push_back(st.top());
                st.pop();
            }
            if (!st.empty() && st.top() == "(")
            {
                st.pop(); // 遇到后把左括号弹出
            }
        }
        else
        {
            while (!st.empty() && youxian(st.top()) >= youxian(element)) // 判断运算符号优先级，返回值越大优先级越高
            {
                postfix.push_back(st.top()); // 栈顶优先级高，则循环pop出栈顶符号一直到栈顶优先级小于判断的符号
                st.pop();
            }
            st.push(element); // 优先级低则直接压入
        }
    }
    while (!st.empty())
    {
        postfix.push_back(st.top()); // 最后处理栈内未被处理的符号
        st.pop();
    }
    return postfix;
}
int houzhhuijisuan(const vector<string> &token)
{
    stack<int> st;
    for (int i = 0; i < token.size(); i++)
    {
        // 遇见字符
        if (token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/")
        {
            int num2 = st.top();
            st.pop();
            int num1 = st.top(); // 弹出栈顶的两项数据
            st.pop();
            if (token[i] == "+") // 根据符号计算后把结果压入栈顶
                st.push(num1 + num2);
            if (token[i] == "-")
                st.push(num1 - num2);
            if (token[i] == "*")
                st.push(num1 * num2);
            if (token[i] == "/")
                st.push(num1 / num2);
        }
        else
        {
            st.push(stoi(token[i])); // 遇见数字把字符类型转化为整数并压入栈顶
        }
    }
    int result = st.top(); // 最后栈顶即为所需结果
    st.pop();
    return result;
}

int main()
{
    vector<string> infix = {"9", "+", "(", "5", "-", "2", ")", "*", "3", "+", "160", "/", "2"};
    vector<string> postfix = zhongtohou(infix);
    int result = houzhhuijisuan(postfix);
    cout << "后缀表达式结果：" << result << endl;
    return 0;
}