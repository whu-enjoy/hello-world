/*******************************************************************************
����Ա		: ���ܱ�
����޸�ʱ��: 2016��3��15�� 01:18:53
���Ի���:Windows XP SP2 + VC6.0
����˵��:
	���������ڼ��һ��ָ��Ͷ���ָ���ں�����ֵ�е��÷�
����˵��:
test1(n);	����������Բ���ָ�봫ֵ
test2(&n);	�������������һ��ָ�봫ֵ
test3(&p);	������������ö���ָ�봫ֵ
test4(a);	����������Դ�������
test5(&q);	�������������ָ�����鴫������
test6(&q);	������������ö���ָ�봫������
*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define ArraySize 10

int test1(int n)
{
	printf("int n��n��ֵΪ��%d\n",n);
	n = 1;

	return 0;
}

int test2(int* n)
{
	printf("int* n��n��ֵΪ��%x\n",n);
	printf("int* n��*n��ֵΪ��%d\n",*n);
	*n = 2;

	return 0;
}

int test3(int** n)
{
	printf("int** n��n��ֵΪ��%x\n",n);
	printf("int** n��*n��ֵΪ��%x\n",*n);
	printf("int** n��**n��ֵΪ��%d\n",**n);
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

	//���Դ��ݵ�ֵ
	printf("���ڲ��Դ��ݵ�ֵ\n...\n...\n...\nbefore : n = %d,p = %x\n\n",n,p);
	test1(n);
	printf("after  test1(int n) n = %d\n\n",n);
	test2(&n);
	printf("after  test2(int* n) n = %d\n\n",n);
	test3(&p);
	printf("after  test3(int** n) n =  %d\n\n",n);

	//���Դ�������
	printf("���ڴ�������\n...\n...\n...\nbefore :" );
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