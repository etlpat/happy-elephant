﻿#define _CRT_SECURE_NO_WARNINGS 1



//////////////////////////////////////////////////////////////////////////////////////////////////////
////1. 两数之和
////给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
////你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
////你可以按任意顺序返回答案。
////
////示例 1：
////输入：nums = [2, 7, 11, 15], target = 9
////输出：[0, 1]
////解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
// 
//#include<stdio.h>
//#define num 10
//
//int* pri(int arr[], int sz)
//{
//	int i;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	return arr;
//}
//
//void judge(int* arr, int x, int sz)
//{
//	int i, j, n=0;
//	for (i = 0; i < sz; i++)//i从0到sz-1递增
//	{
//		for (j = i+1; j < sz; j++)//j从i+1到sz-1递增，可以保证不和i重复
//		{
//			if (arr[i] + arr[j] == x)
//			{
//				printf("%2d+%-2d=%-2d，下标为%2d,%-2d\n", arr[i], arr[j], x, i, j);
//				n++;
//			}
//		}
//	}
//	if (n == 0)
//	{
//		printf("没有想要的结果\n");
//	}
//}
//
//int main()
//{
//	int arr[num] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("输入数组元素\n");
//	pri(arr, sz);
//	printf("输入目标数字\n");
//	int target;
//	scanf("%d", &target);
//	judge(arr, target, sz);
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////






////////////////////////////////////////////////////////////////////////////////////////////////////////
//////44. 通配符匹配
//////给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
//////'?' 可以匹配任何单个字符。'*' 可以匹配任意字符串（包括空字符串）。两个字符串完全匹配才算匹配成功。
//////说明 :
//////s 可能为空，且只包含从 a - z 的小写字母。
//////p 可能为空，且只包含从 a - z 的小写字母，以及字符  ? 和  * 。
////// 
//////示例 1 : 
//////输入:s = "aa",p = "a"
//////输出 : false
//////解释 : "a" 无法匹配 "aa" 整个字符串。
////// 
//////示例 2 :
//////输入:s = "aa",p = "*"
//////输出 : true
//////解释 : '*' 可以匹配任意字符串。
////// 
//////示例 3 :
//////输入:s = "cb",p = "?a"
//////输出 : false
//////解释 : '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
////// 
//////示例 4 :
//////输入:s = "adceb",p = "*a*b"
//////输出 : true
//////解释 : 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
////// 
//////示例 5 :
//////输入 :s = "acdcb",p = "a*c?b"
//////输出 : false
//
//
//
//////char *gets( char *buffer );  返回值：成功返回实参（首元素地址），失败返回NULL；形参：输入字符串的存储位置（首元素地址）
//////gets函数,输入一行字符组成一行字符串，该字符串由第一个换行符('\n')以外的所有字符组成。然后在返回行之前将换行符替换为空字符('\0')。
//////  '\n'==10  ， '\0'==0
//
//#include<stdio.h>
//#define MAX 20
//
//char* my_gets(char* arr)//输入字符串的函数
//{
//	int i;
//	for (i = 0;; i++)//这里每输入一次，i+1。若遇到'\n'则将其改为'\0'
//	{
//		*(arr + i) = getchar();
//		if (*(arr + i) == '\n')
//		{
//			break;
//		}
//	}
//	*(arr + i) = '\0';
//	return arr;
//}
//
//
//void judge(char* arr1, char* arr2)//根据题意给出的判断函数
//{
//	int i = 0, j = 0;
//	while (1)
//	{
//		if (arr1[i] == '\0' && arr2[j] == '\0')
//		{
//			printf("true");
//			break;
//		}
//		if (arr2[j] != '*' && arr2[j] != '?')
//		{
//			if (arr1[i] == arr2[j])
//			{
//				i++;
//				j++;
//			}
//			if (arr2[j] != '*' && arr2[j] != '?' && arr1[i] != arr2[j])
//			{
//				printf("false");
//				break;
//			}
//		}
//		if (arr2[j] == '*')//当arr2的元素*，arr2向后跳一位，arr1元素向后循环跳，直到等于[arr2的*的下一位]或['0']
//		{
//			j++;
//			do
//			{
//				i++;
//			} while ((arr1[i] != '0') && (arr1[i] != arr2[j]));
//		}
//		if (arr2[j] == '?')//若arr2元素为？，两数组均向后跳一元素
//		{
//			i++;
//			j++;
//		}
//	}
//}
//
//int main()
//{
//	char arr1[MAX] = { 0 };
//	char arr2[MAX] = { 0 };
//	my_gets(arr1);
//	my_gets(arr2);
//	judge(arr1, arr2);
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////
























//////////////////////////////////////////////////////////////////////////////////////////////////////
////////350. 两个数组的交集 II
////////给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
////////返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致
////////（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
////////
////////示例 1：
////////输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
////////输出：[2, 2]
////////
////////示例 2:
////////输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
////////输出：[4, 9]
//////////
//////////提示：
//////////1 <= nums1.length, nums2.length <= 1000
//////////0 <= nums1[i], nums2[i] <= 1000
//
// 
//#include<stdio.h>
//
//int strsca(char arr[], int sz)//数组中输入元素函数
//{
//	int i,num=0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = getchar();
//		num++;
//		if (arr[i] == 10)//回车时，getchar()获得的值时'\n'，对应ASCII值为10
//		{
//			arr[i] = '\0';  
//			num--;
//			break;
//		}
//	}
//	return num;
//}
//
//
//void pri(char arr[], int sz)//打印函数
//{
//	int i;
//	for (i = 0; i < sz && arr[i] != '\0'; i++)
//	{
//		printf("%c ", arr[i]);
//	}
//}
//
//
//int initarr(int(*pstrsca)(char*,int),char arr[], int sz)//初始化数组函数
//{
//	printf("请输入数组：>");
//	int a = pstrsca(arr, sz);
//}
//
//
//void judge(char* arr1, char* arr2, char* arr3)//实现交集放入arr3的数组
//{
//	while ((*arr1) && (*arr2))
//	{
//		if (*arr1 == *arr2)
//		{
//			*arr3 = *arr1;
//			arr1++, arr2++, arr3++;
//		}
//		else if ((*arr1 >= *arr2) || *arr1 == '\0')
//		{
//			arr2++;
//		}
//		else if ((*arr2 >= *arr1) || *arr2 == '\0')
//		{
//			arr1++;
//		}
//	}
//	*arr3 = '\0';
//}
//
//
//void p(char arr[], int num)//数组排序函数
//{
//	int i, j;
//	for (i = 0; i < num-1; i++)//循环num-1次，每次目的是第一次把最大的放最后，第二次把次大的放倒数第二个位置...
//	{
//		for (j = 0; j < num - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				char tmp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j+1] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[20] = { 0 };
//	char arr3[20] = { 0 };
//	int sz = sizeof(arr1) / sizeof(arr1[0]);
//	int num1 = initarr(strsca, arr1, sz);//初始化数组元素,返回元素个数
//	int num2 = initarr(strsca, arr2, sz);
//	p(arr1, num1);//排序函数
//	p(arr2, num2);
//	int max = num2;
//	if (num1 > num2)
//	{
//		max = num1;//max是最大数组的元素个数
//	}
//	judge(arr1, arr2, arr3);
//	pri(arr3,sz);
//	return 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////////////////