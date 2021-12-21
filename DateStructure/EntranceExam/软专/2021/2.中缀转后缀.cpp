/**
 *
遇到操作数，直接输出
栈为空时，遇到运算符入栈
遇到左括号，入栈
遇到右括号，执行出栈操作，并将出栈的元素输出，直到弹栈的是左括号，左括号不输出
遇到其他运算符+ - * /时，弹出所有优先级大于等于该运算符的栈顶元素，然后将该运算符入栈
最终将栈中元素依次出栈。

 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int prior(char op) { // 给运算符优先级排序
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '(') return 0;
}

string inToPost(string &infix) {
    stack<char> stk;
    string postfix;
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] >= '0' && infix[i] <= '9') { // 遇到操作数，直接输出
            postfix += infix[i];
        } else if (stk.empty()) stk.push(infix[i]); // 栈为空时，直接入栈
        else if (infix[i] == '(') stk.push(infix[i]); // 遇到左括号，直接入栈
        else if (infix[i] == ')') {  // 遇到右括号，执行出栈操作，直到弹栈的是左括号，左括号不输出
            while (stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop();
        } else {
            while (prior(infix[i]) <= prior(stk.top())) { // 遇到其他运算符+ - * /时，弹出所有优先级大于等于该运算符的栈顶元素，然后将该运算符入栈
                postfix += stk.top();
                stk.pop();
                if (stk.empty()) break;
            }
            stk.push(infix[i]);
        }
    }
    while (!stk.empty()) { // 最终将栈中元素依次出栈
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}
