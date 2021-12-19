#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

int main() {
    char str[100];
    stack<char> stk; // 符号栈
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+' || str[i] == '*') { // 如果符号为+或*入栈
            stk.push(str[i]);
        } else if (str[i] == ')') { // 遇到右括号时原样输出，并输出栈顶符号，栈顶符号出栈
            printf("%c", str[i]);
            printf("%c", s.top());
            stk.pop();
        } else {
            printf("%c", str[i]); // 其余字符原样输出
        }
    }
    return 0;
}