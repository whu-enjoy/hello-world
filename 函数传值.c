/*******************************************************************************
程序员		: 何能斌
最后修改时间: 2016年3月15日 01:18:53
测试环境:Windows XP SP2 + VC6.0
程序说明:
	本程序用于检测一级指针和二级指针在函数传值中的用法
函数说明:
test1(n);	这个函数测试不用指针传值
test2(&n);	这个函数测试用一级指针传值
test3(&p);	这个函数测试用二级指针传值
test4(a);	这个函数测试传递数组
test5(&q);	这个函数测试用指针数组传递数组
test6(&q);	这个函数测试用二级指针传递数组
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define ArraySize 10

int test1(int n)
{
	printf("int n中n的值为：%d\n",n);
	n = 1;

	return 0;
}

int test2(int* n)
{
	printf("int* n中n的值为：%x\n",n);
	printf("int* n中*n的值为：%d\n",*n);
	*n = 2;

	return 0;
}

int test3(int** n)
{
	printf("int** n中n的值为：%x\n",n);
	printf("int** n中*n的值为：%x\n",*n);
	printf("int** n中**n的值为：%d\n",**n);
	**n = 3;

	return 0;
}

int test4(int a[])
{
	int i = 0;
	
	for(i = 0;i < ArraySize;i++)
	{
		a[i] = 1;
	}

	return 0;
}

int test5(int* a[])
{
	int i = 0;
	
	for(i = 0;i < ArraySize;i++)
	{
		**a = 2;
		*a += 1;;
	}	
	
	return 0;
}

int test6(int** a)
{
	int i = 0;
	
	for(i = 0;i < ArraySize;i++)
	{
		**a = 3;
		*a += 1;;
	}	
	
	return 0;
}

int main(void)
{
	int i =0;
	int n = 0;
	int a[ArraySize] = {0};
	int *p = &n;
	int *q = a;

	//测试传递单值
	printf("现在测试传递单值\n...\n...\n...\nbefore : n = %d,p = %x\n\n",n,p);
	test1(n);
	printf("after  test1(int n) n = %d\n\n",n);
	test2(&n);
	printf("after  test2(int* n) n = %d\n\n",n);
	test3(&p);
	printf("after  test3(int** n) n =  %d\n\n",n);

	//测试传递数组
	printf("现在传递数组\n...\n...\n...\nbefore :" );
	for(i = 0;i < ArraySize;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\nq = %x,*q = %x\n\n",q,*q);

	test4(a);
	printf("after test4 : ");
	for(i = 0;i < ArraySize;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");

	test5(&q);
	printf("after test5 : ");
	for(i = 0;i < ArraySize;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");

	q = a;
	test6(&q);
	printf("after test6 : ");
	for(i = 0;i < ArraySize;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\n");

	system("pause");
	return 0;
}