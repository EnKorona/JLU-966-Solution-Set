#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

/**
 * 首先设定上下左右边界
 * 其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
 * 判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
 * 若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
 * 不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
 */
void circleMatrix() {
    int a[10][10];
    memset(a, 0, sizeof(int)*100);
    int cnt = 1; // 需要赋值的数
    int up = 0,down = 9,left = 0,right = 9; // 分别赋值上下左右边界
    while(true) {
        for(int i = left;i<=right;i++) a[up][i]= cnt++; // 向右移动直到最右
        if(++up > down) break;
        for(int i = up;i<=down;i++) a[i][right] = cnt++; //向下
        if(--right < left) break;
        for(int i = right;i >= left;i--) a[down][i] = cnt++;
        if(-- down < up) break;
        for(int i = down;i >= up;i--) a[i][left] = cnt++;
        if(++left > right) break;
    }
    for(int i = 0;i<10;i++) {
        for(int j = 0;j < 10;j++) {
            printf("%5d ",a[i][j]);
        }
        printf("\n");
    }
}