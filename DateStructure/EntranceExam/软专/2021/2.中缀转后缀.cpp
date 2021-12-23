#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

using namespace std;

/**
 *
(1)初始化运算符栈
(2)从左至右扫描中缀表达式；
(3)遇到操作数时，将其输出；
(4)遇到运算符时，比较其与栈顶运算符的优先级：
    a：如果栈为空，则直接将此运算符入栈；
    b：否则，若优先级比栈顶运算符的高，也将运算符压入栈
    c：否则，将栈顶的运算符弹出并输出，再次重复步骤(4)与新的栈顶运算符相比较；
(5)遇到括号时：
    a：如果是左括号“(”，则直接压栈；
    b：如果是右括号“)”，则依次弹出栈顶的运算符，并输出，直到遇到左括号为止，此时将这一对括号丢弃；
(6)重复步骤(2)至(5)，直到表达式的最右边；
(7)将 s1 中剩余的运算符依次弹出并输出
 */

int prior(char op) { // 给运算符优先级排序
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (op == '(') return 0;
}

string inToPost(string &infix) {
    stack<char> stk;
    string postfix;
    for (int i = 0; i < infix.size(); i++) {
        if (infix[i] >= '0' && infix[i] <= '9') postfix += infix[i]; // 遇到操作数，直接输出
        else if (stk.empty()) stk.push(infix[i]); // 栈为空时，直接入栈
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
