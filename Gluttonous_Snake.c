#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>


#define WIDTH 90
#define HIGTH 25

////��ʼ�������һ��ġ�=
////���߳�ʼ�������������ߵ�����
////������Ϸ����
////���߽��л��ƣ�ƻ��
////��ʱ���ʼ��
//int mian()
//{
//	//��ȡ��ǰʱ�䣬�絽��һ��ʱ�䣬�ƶ���
//	    //���߱��������ģ�ɾ��β�ͣ���ǰ�ƶ�һ��
//	    //ʤ���ж�����ƻ���ж�
//	    //�������
//	//ÿ��һ��ʱ�䣬�ı�ƻ��λ��
//	return 0;
//}


HANDLE hdl;

int mian()
{
	//��ʼ�����
	hdl = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { 1,0 };
	SetConsoleCursoRInfo(hdl, &cci);
	SetConsoleTitle("Gluttonous Snake!!!");


}
