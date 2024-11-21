#include<stdio.h>
//声明外部文件的函数
extern int Add(int x,int y);
int main()
{
    int a =200;
    int b =500;
    int sum=Add(a,b);
    printf("%d\n",sum);
    return 0;
}
