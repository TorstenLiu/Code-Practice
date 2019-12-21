#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include "math.h"

//�����û�����������������ɶ�ά����A L U D ���� b x y ����ȫ����ʼ��Ϊ0
double **A, *b, *x, *y, **L, **U, **D;
double calculate_e = 0.0001;//Ĭ�Ͼ���Ϊ10^-4
unsigned int RANK = 4;
unsigned int makematrix()
{
	unsigned int r, c;

	printf("������������������ÿո������");
	scanf_s("%d %d", &r, &c);

	A = (double**)malloc(sizeof(double*)*r);//����һ��ָ�����飬��ָ������ĵ�ַ��ֵ��a ,*r�ǳ���r����˼
	for (int i = 0; i < r; i++)
		A[i] = (double*)malloc(sizeof(double)*c);//���ڶ�ά����ռ�
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			A[i][j] = 0.0;
	}

	b = (double*)malloc(sizeof(double)*r);
	for (int i = 0; i < r; i++)
	{
		b[i] = 0.0;
	}
	x = (double*)malloc(sizeof(double)*c);
	for (int i = 0; i < c; i++)
	{
		x[i] = 0.0;
	}

	L = (double**)malloc(sizeof(double*)*r);//����һ��ָ�����飬��ָ������ĵ�ַ��ֵ��a ,*r�ǳ���r����˼
	for (int i = 0; i < r; i++)
		L[i] = (double*)malloc(sizeof(double)*c);//���ڶ�ά����ռ�
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			L[i][j] = 0.0;
	}
	U = (double**)malloc(sizeof(double*)*r);//����һ��ָ�����飬��ָ������ĵ�ַ��ֵ��a ,*r�ǳ���r����˼
	for (int i = 0; i < r; i++)
		U[i] = (double*)malloc(sizeof(double)*c);//���ڶ�ά����ռ�
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			U[i][j] = 0.0;
	}
	D = (double**)malloc(sizeof(double*)*r);//����һ��ָ�����飬��ָ������ĵ�ַ��ֵ��a ,*r�ǳ���r����˼
	for (int i = 0; i < r; i++)
		D[i] = (double*)malloc(sizeof(double)*c);//���ڶ�ά����ռ�
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			D[i][j] = 0.0;
	}
	y = (double*)malloc(sizeof(double)*c);
	for (int i = 0; i < c; i++)
	{
		y[i] = 0.0;
	}
	return r;
}
//��ʾ�û�����һ����������� ���г������� ���㾫��
void getmatrix(void)//������󲢳���
{
	printf("�밴�д�������������ϵ������A����ͬԪ���ÿո����\n");
	for (int i = 0; i < RANK; i++)
	{
		for (int j = 0; j < RANK; j++)
		{
			scanf_s("%lf", &A[i][j]);
		}
	}
	printf("ϵ����������\n");
	for (int i = 0; i < RANK; i++)
	{
		for (int j = 0; j < RANK; j++)
		{
			printf("%g\t", A[i][j]);
		}
		printf("\n");
	}
	printf("�밴���ϵ����������볣����b����ͬԪ���ÿո����\n");
	for (int i = 0; i < RANK; i++)
	{
		scanf_s("%lf", &b[i]);
	}
	printf("����������\n");
	for (int i = 0; i < RANK; i++)
	{
		printf("%g\t", b[i]);
	}printf("\n");
	printf("��������㾫�ȣ������磺0.0001��\n");
	scanf_s("%lf", &calculate_e);
	printf("�������ľ���Ϊ��%g\n", calculate_e);
}

bool Jacobi_calculation(void)//Jacobi�����������Է�����
{
	double get_add = 0.0, get_e = 0.0;
	printf("��������A��b��ɵ����������Jacobi�����������㷽����\n");
	for (int i = 0; i < RANK; i++) //��ʼ����ֵΪ0
	{
		x[i] = 0.0;
		y[i] = 0.0;
	}
	for (int k = 0; k < 100; k++)//������100�Σ���Ϊ��ɢ
	{
		for (int i = 0; i < RANK; i++)//����һ�ε�ֵ ���������
		{
			x[i] = y[i];
		}
		for (int i = 0; i < RANK; i++)//����һ��
		{
			get_add = 0;
			for (int j = 0; j < RANK; j++)
			{
				get_add = get_add + A[i][j] * x[j];
			}
			y[i] = (-get_add + A[i][i] * x[i] + b[i]) / A[i][i];
		}
		get_add = 0;
		for (int i = 0; i < RANK; i++)//���������
		{
			get_add = (fabs(x[i] - y[i]) > get_add) ? fabs(x[i] - y[i]) : get_add;
		}
		if (fabs(get_add) <= calculate_e)
		{
			printf("��������Ϊ��%d", k + 1);
			break;
		}
		if (k == 99)//ʧЧ
		{
			return false;
		}
	}
	for (int i = 0; i < RANK; i++) //����xy
	{
		double temp;
		temp = x[i];
		x[i] = y[i];
		y[i] = temp;
	}
	printf("���x����ã�\n");
	for (int i = 0; i < RANK; i++)
	{
		printf("x%d = %g\n", i + 1, x[i]);
	}
}

bool Gusse_Seidel_calculation(void)//Gausse_Seidel�����������Է�����
{
	double get_add = 0.0, get_e = 0.0;
	printf("��������A��b��ɵ����������Gausse_Seidel�����������㷽����\n");
	for (int i = 0; i < RANK; i++) //��ʼ����ֵΪ0
	{
		x[i] = 0.0;
		y[i] = 0.0;
	}
	for (int k = 0; k < 100; k++)//������100�Σ���Ϊ��ɢ
	{
		for (int i = 0; i < RANK; i++)//����һ�ε�ֵ ���������
		{
			y[i] = x[i];
		}
		for (int i = 0; i < RANK; i++)//����һ��
		{
			get_add = 0;
			for (int j = 0; j < RANK; j++)
			{
				get_add = get_add + A[i][j] * x[j];
			}
			x[i] = (-get_add + A[i][i] * x[i] + b[i]) / A[i][i];
		}
		get_add = 0;
		for (int i = 0; i < RANK; i++)//���������
		{
			get_add = (fabs(x[i] - y[i]) > get_add) ? (x[i] - y[i]) : get_add;
		}
		if (fabs(get_add) <= calculate_e)
		{
			printf("��������Ϊ��%d", k + 1);
			break;
		}
		if (k == 99)//ʧЧ
		{
			return false;
		}
	}
	printf("���x����ã�\n");
	for (int i = 0; i < RANK; i++)
	{
		printf("x%d = %g\n", i + 1, x[i]);
	}
}

int main()
{
	bool retry;

_again:
	RANK = makematrix();
	getmatrix();
	retry = Jacobi_calculation();
	if (retry == false)
	{
		printf("Jacobi������ʧЧ������ʹ��Gausse_Seidel����������\n");
	}
	retry = Gusse_Seidel_calculation();
	if (retry == false)
	{
		printf("Gausse_Seidel������ʧЧ\n");
	}

	printf("������ɣ����س��˳������1�����������\n");
	getchar();
	if ('1' == getchar())	goto _again;
	return 0;
}
