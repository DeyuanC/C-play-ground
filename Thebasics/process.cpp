#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<process.h>		//进程函数

void run(void *p)
{
	int *temp = (int *)p;
	char ch[50];
	sprintf(ch, "thread %d start", *temp);
	MessageBoxA(0, ch, "mult thread", 0);
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		//第一个参数为函数的地址，第二个参数为栈的大小，0代表默认大小，第三个参数为函数的实参，必须为void*类型
		_beginthread(run, 0, &i);	//多线程调用函数
		Sleep(1000);
	}
return 0;
}
