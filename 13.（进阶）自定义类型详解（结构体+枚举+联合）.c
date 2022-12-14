//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>

 




/////////////////////////////////////////////////////////////////////////结构体////////////////////////////////////////////////////////////////////////////////



////////////////////        1.结构体类型的声明
// 
////结构体是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量
//
// struct tag  //结构体标签
// {
//  	number_list;//成员列表
//
// }variable_list;//变量列表




////声明一个结构体类型
////声明一个学生类型，是像通过学生类型来创建一个学生变量（对象）
////描述学生：属性——名字+电话+性别+年龄
//struct stu
//{
//	char name[20];//名字
//	char tele[12];//电话
//	char sex[10];//性别
//	int age;//年龄
//
//}s3, s4;//全局结构体变量
//
//int main()
//{
//	//创建的结构体变量
//	struct stu s1;
//	struct stu s2;
//	
//	return 0;
//}





//////匿名结构体类型（没写结构体标签）
//struct
//{
//	int a;
//	char b;
//	float c;
//}x, arr[10], * p;
//////上面是匿名结构体（变量、数组、指针）
//////匿名结构体类型只能在这里创建一次全局变量
//////之后由于没有名字，不能在其他地方创建变量

















////////////////////        2.结构体的自引用





////在结构体中包含一个（和该结构体类型本身一致）的成员时，不能直接引这个结构体变量，要通过指针的形式来实现
//
// 
//////代码1（不可行）
//struct Node
//{
//	int date;
//	struct Node next;
//};
////如果是上面那样，sizeof(struct Node)则为无穷大
////（相当于没有结束条件的死循环递归）
//
//
//////代码2（可行）
//struct Node
//{
//	int date;
//	struct Node* next;
//};
////指针大小是可以确定的，可行






//////结构体成员自引用时，可以这样类型重定义：
//////代码1
//typedef struct Node
//{
//	int date;
//	struct Node* next;
//}Node;
// 
//
//////但是不允许这样类型重定义：
//////代码2
//typedef struct Node
//{
//	int date;
//	Node* next;
//}Node;
//
//
//////更不允许这样匿名类型重定义：
//////代码3
//typedef struct
//{
//	int date;
//	Node* next;
//}Node;
//
////因为程序从上向下执行，在结尾重定义类型名称，若像代码2、3那样在定义之前先引用，就会err

















////////////////////        3.结构体变量的定义和初始化


//struct T
//{
//	double d;
//	short b;
//};
//
//struct S
//{
//	char c;
//	int a;
//	struct T st;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 'c',124 ,{3.14,12},"hello" };
//	printf("%c %d %lf %d %s", s.c, s.a, s.st.d, s.st.b, s.arr);
//	return 0;
//}

















////////////////////        4.结构体内存对齐



////////# 1.第一个成员默认在与结构体变量偏移量为0的地址处
////
////////# 2.其他成员变量要对齐到（各自对齐数）的整数倍的地址处
////
////
////////对齐数 = (编译器默认对齐数)和(该成员大小）两个值中的较小值
////////          VS中对齐数默认值为8
////////          gcc没有默认对齐数
//////////e.g. char类型大小为1，VS默认8，取1为对齐数，char类型成员可放到偏移量为 0,1,2,3,4,5,6...
//////////e.g. int类型大小为4，VS默认8，取4为对齐数，int类型成员可放到偏移量为 4,8,12,16...
////
//// 
////////# 3.结构体总体大小为最大对齐数的整数倍 (每个成员变量都有一个对齐数)
////
////////# 4.如果结构体A嵌套了结构体B的情况，嵌套结构体B对齐到【"B自己的成员"的最大对齐数的整数倍处】，
////////    结构体A的整体大小就是所有最大对齐数（含嵌套类型结构体B的对齐数）的整数倍
////
////////# 5.数组的对齐数就是其元素的对齐数； 和结构体不同，数组整体大小不会被当作最大对齐数，数组的最大对齐数就是它的元素对齐数
////////    也就是说数组完全可以看作(把数组拆开后的元素)来计算对齐 
//// 
////////# 6.按照结构体对齐方式排列出的空间，没被占用的相当于浪费掉，不存放其他的东西了
////
//// 
////
//////// 既然内存对齐浪费空间，为什么存在内存对齐？
////////   大部分资料都是如是说的：
//////// 1.平台原因（移植原因）：不是所以硬件平台都能访问任意地址上的任意数据；某些硬件平台只能
////////                         在某些地址处取某些特定类型的数据，否则抛出硬件问题。
//////// 2.性能原因：数据结构（尤其是栈）应该尽可能地在自然边界上对齐。原因在于：为了访问[未对齐]的
////////             内存，处理器需要操作两次内存访问；而[对齐]的内存访问仅需要一次访问
//////// 总体来说：
////////          【结构体的内存对齐是拿空间来换取时间的做法】
//
//
// 
//////////【设计结构体的小技巧】：
////// 在设计结构体的时候，我们【既要满足对齐，又要节省空间】，如何做到？
//////【让占用空间小的成员尽量集中在一起】
////// 如下，S1 S2成员一样，S2占用内存更小
//
//
//
////////////【修改默认对齐数】 宏——#pragma pack()
//////默认对齐数设置成4
//////#pragma pack(4)
//////
//////()内不填，把对齐数改回默认
//////#pragma pack()






/////【练习】
/////下面数字代表各成员的所在位置偏移量，以及结构体的总大小
//
//练习1：
//struct S1
//{
//	char c1;  //0
//	int a;    //4567
//	char c2;  //8
//};     //9<3*4-------->12
//
//
//练习2：
//struct S2
//{
//	char c1;  //0
//	char c2;  //1
//	int a;    //4567
//};     //8=2*4-------->8
//
//
//练习3：
//struct S3
//{
//	double d; //01234567
//	char c;   //8
//	int i;    //12 13 14 15
//};       //16=2*8------------->16
//
//
//练习4：
//struct S4
//{
//	char c1;     //0
//	struct S3 s3;//8 9 10 ...22 23（S3类型占16字节,S3中成员最大对齐数为8，所以这里偏移量为8）
//	double d;    //24 25 ...30 31
//};       //32=2*16----------------------->32
//
//
//练习5：
//struct S5
//{
//	char a[5]; //0 1 2 3 4
//	short b;   //6 7
//	char c[5]; //8 9 10 11 12
//};       //14=2*7--------------->14
//
//                           S5 S6 可以看出，数组的对齐数就是其元素的对齐数，数组大小不会当作最大对齐数来计算
//练习6:				   //也就是说数组完全可以看作(把数组拆开后的元素)来计算对齐
//struct S6
//{
//	char a;     //0
//	short b[3]; //2 3 4 5 6 7 
//	int c;      //8 9 10 11
//	char d[5];  //12 13 14 15 16
//};       //20=4*5----------------->20
//
//
//#include<stddef.h>
//int main()
//{
//	struct S1 s1 = { 0 };
//	struct S2 s2 = { 0 };
//	struct S3 s3 = { 0 };
//	struct S4 s4 = { 0 };
//	struct S5 s5 = { 0 };
//	struct S6 s6 = { 0 };
//
//	printf("%d\n", sizeof(s1));//12
//	printf("%d\n", sizeof(s2));//8
//	printf("%d\n", sizeof(s3));//16
//	printf("%d\n", sizeof(s4));//32
//	printf("%d\n", sizeof(s5));//20
//	printf("%d\n", sizeof(s6));//16
//
//	return 0;
//}






//////////  百度笔试题：
//////////写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//////ofsrtof(结构体类型，成员名)，如下，计算偏移量
//
//#include<stddef.h>
//struct S
//{
//	char c;
//	int i;
//	double d;
//};
//int main()
//{
//	////offset:偏移量
//	//offsetof()计算并返回结构体成员相对起始位置的偏移量
//
//	//offsrtof();//是宏，参数可以传类型----对应头文件<stddef.h>
//	printf("%d\n", offsetof(struct S, c));//0
//	printf("%d\n", offsetof(struct S, i));//4
//	printf("%d\n", offsetof(struct S, d));//8
//
//	return 0;
//}

















////////////////////        5.结构体传参



//struct S
//{
//	int a;
//	char c;
//	float d;
//};
//
//
////传址
//void init(struct S *ps)//想在函数中改变结构体，必须传址调用
//{
//	ps->a = 100;
//	ps->c = 'w';
//	ps->d = 3.14;
//}
//
//
////传值(这种方法会在内存开辟一块新空间存放临时变量，结构体空间较大，最好用传址)
//void pri1(struct S tmp)
//{
//	printf("%d %c %f\n", tmp.a, tmp.c, tmp.d);
//}
//
//
////传址（只传4/8字节，不创建大量新空间存结构体，但要防止内存被改变，最好加const）
//void pri2(const struct S* const ps)
//{
//	printf("%d %c %f\n", ps->a, ps->c, ps->d);
//}
//
//
//int main()
//{
//	struct S s = { 0 };
//
//	init(&s);//区别于数组，数组名是地址，可以直接传参，但结构体名不是地址
//	pri1(s);
//	pri2(&s);
//
//	return 0;
//}



/////////////pri1 与 pri2哪个好？
///////pri1传参，实参传递给形参时，形参是实参的一份临时拷贝，会新开辟一块空间，若结构体较大，形参占空间多，拷贝时间长
///////pri2传递指针，形参是地址，只传4/8字节，通过地址找到数据
////////////所以首选pri2（传地址）
//////官方解释：函数传参时，参数需要压栈。如果传递一个结构体对象的时候，结构体过大，参数压栈的系统开销比较大，会导致性能下降

















////////////////////        6.结构体实现位段（位段的填充&可移植性）
//////【位段的作用就是为了节省空间】【位段--二进制位】


//////位段也是结构体的一种类型
//////位段声明和结构体类似，有两个不同
// 
////// 1.位段的成员必须是【整形】：|int ,unsigned int ,signed int |,short ,char(字符型也算整型)...    
//////                        （很多书上只标明前三种整型，实际上经过测试所有整型都可以）
//////
////// 2.位段成员后边有一个冒号和一个数字【数字中标明了位段所占用的二进制位数】
//////   （成员的值和位段大小不一样时：少了补0，多了截断） 
//   
// 
////// 位段的内存分配（有点像结构体内存对齐）
//////1.位段的成员是整型
//////2.位段按照成员大小开辟空间：int类型每次开辟4字节，char类型每次开辟1字节
//////3.每当上一块开辟的空间放不下下一个成员时，就新申请一块空间开开辟
//////4.位段涉及很多不确定因素，位段是不跨平台的，注重可移植性的程序应该避免使用位段




////例1：
//struct S  //（成员是int，所以每开辟一次空间是开辟4个字节(32比特位)）
//{
//	int a : 2;  //第一次开辟4个字节 2/32
//	int b : 5;  //第一次开辟4个字节 (2+5)/32
//	int c : 10; //第一次开辟4个字节 (2+5+10)/32//-------//第一次的4个字节，占用了17/32；a,b,c 一共用了17个比特位，这4个字节(32bit)不能再放下d，所以再申请一次空间，把d存放在下4个字节中
//	int d : 30; //第二次开辟4个字节：占用 30/32
//
//};//一共占用 2*4=8 个字节
// 
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));//8
// 
//	return 0;
//}




////例2；
//struct S  //（成员是char，所以每开辟一次空间是开辟1个字节）
//{
//	char a : 3;//第一个1字节 3/8 （每当放不下下一个成员就新申请一块空间，空间大小的类型大小）
//	char b : 4;//第一个1字节 7/8
//	char c : 5;//第二个1字节 5/8
//	char d : 4;//第三个1字节 4/8
//
//};//总共占用 3*1=3 个比特位
//
//int main()
//{
//	struct S s = { 0 };
//	s.a = 10;//1010  --> 010  （经过截断后的结果）
//	s.b = 20;//10100 --> 0100                   
//	s.c = 3; //11    --> 00011         在内存中为 [0|0100|010][000|00011][0000|0100] ==> 0x 22 03 04
//	s.d = 4; //100   --> 0100                      x  (b) (a)   x   (c)    x    (d) 【这里x是浪费掉的区域】
//	                                   //这里每个字节内，数据从后向前存放，C语言没有规定，每个编译器不一样，这是位段不跨平台的原因
//	printf("%d\n", sizeof(s));//3
//
//	return 0;
//}



////////位段的跨平台问题
//////1.int位段被当作有符号数还是无符号数是不确定的
//////2.位段中最大位的数目不能确定。（16为机器最大16，32位机器最大32，不通用）
//////3.位段中的成员在内存中从左到右分配还是从右向左分配，C语言标准未定义
//////4.当一个结构包含两个位段，第二个位段成员较大，无法容纳于第一个位段剩余位时，舍弃剩余位还是利用，标准没有规定
////////总结：
//////跟结构相比，位段可以达到同样的效果，但是可以更好的节省空间，但是跨平台的问题存在。







//////////位段【题目】 ：以下输出结果是多少？
//
//int main()
//{
//	unsigned char puc[4];
//	struct tagPIM
//	{
//		unsigned char ucPim1;
//		unsigned char ucData0 : 1;
//		unsigned char ucData1 : 2;
//		unsigned char ucData2 : 3;
//	}*pstPinData;
//	pstPinData = (struct tagPIM*)puc;
//	memset(puc, 0, 4);
//	pstPinData->ucPim1 = 2;
//	pstPinData->ucData0 = 3;//11 -> 1
//	pstPinData->ucData1 = 4;//100 -> 00   }-> 00|101|00|1
//	pstPinData->ucData2 = 5;//101 -> 101
//
//	printf("%02x %02x %02x %02x", puc[0], puc[1], puc[2], puc[3]);
//	return 0;
//}
//
//
////数组puc内存为 0000000 00000000 00000000 00000000
////pstPinData = (struct tagPIM*)puc;，把数组指针pstPinData放到了puc的位置
////之后对pstPinData内容进行赋值，同时改变了puc位置的值
////0000010 00|101|00|1 00000000 00000000
////输出 02 29 00 00































/////////////////////////////////////////////////////////////////////////枚举类型////////////////////////////////////////////////////////////////////////////////



////////////////////        1.枚举类型的定义

//enum Day//枚举类型名
//{
//	Mon,//枚举可能取值 -- 枚举常量
//	Tues,
//	Wed,
//	Thur,
//	Fir,
//	Sat,
//	Sun
//};
//
//enum Sex
//{
//	MALE,    // 0 (默认值从0开始，之后递增1)--（枚举常量默认大小为4字节，即整型的大小）
//	FEMALE,  // 1
//	SECRET   // 2
//};
//
//enum Color
//{
//	RED = 2,  //枚举常量可以在定义时赋初值（由于是常量，赋完初值后在主函数中不可改变）
//	GREEN = 4,
//	BLUE      //若上一个枚举常量赋值，这个不赋值，这个的值默认是上一个+1
//};
//
//int main()
//{
//	enum Sex s = MALE;//s的值只能是该枚举的可能取值
//	s = FEMALE;
//	printf("%d %d %d\n", MALE, FEMALE, SECRET);//0 1 2
//
//	enum Color c = BLUE;
//	////错误写法：enum Color c = 5; -- 这里不报错，但是不正确，因为BLUE类型是枚举类型，5类型是int，这么写不标准
//	printf("%d %d %d\n", RED, GREEN, BLUE);//0 1 2
//
//	return 0;
//}






////////////////////        2.枚举的优点

////////枚举的优点
////////我们可以使用#define定义常量，为什么非要使用枚举？
//////1.增加代码的可读性、可维护性
//////2.和#define定义的标识符比较，枚举有类型检查，更加严谨
//////3.防止命名污染（封装）
//////4，便于调试
//////5使用方便，一次可以定义多个常量










//////////【题目】1.下面代码结果是？
//enum E
//{
//	X1,//0
//	Y1,//1
//	Z1 = 255,//255
//	A1,//256
//	B1//257
//};
//int main()
//{
//	enum E A = Y1;
//	enum E B = B1;
//	printf("%d %d\n", A, B);//1,257
//	return 0;
//}





























//////////////////////////////////////////////////////////////////////////联合（共用体）////////////////////////////////////////////////////////////////////////////////


//////联合类型的定义：
////联合也是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员，特征是这些成员共用一块空间（所以联合也叫共用体）
//// 从低地址开始共用（从左边开始存储） 
//
//////联合的特点：
////联合的成员是共用一块空间，这样一个联合变量的大小，至少是最大成员的大小（因为联合至少要放得下最大的成员）
////联合体的各成员不能同时使用，因为使用一个成员，则另一个成员的内容也跟着改变了


//union Un //联合类型的声明：（省略Un就是匿名结构体类型）
//{
//	char c;//联合体成员
//	int i;
//}u;//联合体变量
//
//int main()
//{
//	//联合变量的定义
//	union Un u;
//	printf("%d\n", sizeof(u));//4
//
//	printf("%p\n", &u);      //000000B3A70FF854
//	printf("%p\n", &(u.c));  //000000B3A70FF854
//	printf("%p\n", &(u.i));  //000000B3A70FF854
//	return 0;
//}
//
//////从上面结果可以得出：
//////联合体u总大小为4字节；各元素地址一致
//////所以联合体各元素公用一块空间，联合体也称共用体






//////联合体的应用：
//////////面试题：判断当前计算机的大小端 
//// int a = 0x11223344
//// 低地址---------------------------->高地址
////...[][][][][][11][22][33][44][][][][][][]... 大端字节序
////...[][][][][][44][33][22][11][][][][][][]... 小端字节序
//
//
//int check_sys1()
//{
//	int i = 1;
//
//	//把int*类型强转为char*，以此来访问原本int*中的第一字节空间
//	return *(char*)&i;
//}
//
//
//int check_sys2()
//{
//	union Un
//	{
//		int i;
//		char c;
//	}u;
//
//	//利用联合体共用一块空间的特点，用字符类型c取出u第一字节空间中的内容
//	u.i = 1;
//	return u.c;
//}
//
//
//int main()
//{
//	int ret = check_sys2();
//	if (1 == ret) {
//		printf("小端\n");
//	}
//	else {
//		printf("大端\n");
//	}
//	return 0;
//}





////////////////////       联合体大小的计算
// 
////联合的大小【至少】是最大成员的大小
////当最大成员大小不是最大对齐数的整数倍是，就要对齐到最大对齐数的整数倍(对齐规数则和结构体相同)



//union UN
//{
//	int a;       //大小：4 ；对齐数：4 
//	char c[5];   //大小：5 ；对齐数：1 （和结构体一样，数组的最大对齐数就是其元素的对齐数）
//}; //2*4=8---->8
//
//int main()
//{
//	union UN u = { 0 };
//	printf("%d\n", sizeof(u));//8
//
//	return 0;
//}





//////计算大小总结：
//////结构体存需要对齐，位段不存在对齐，枚举不存在对齐，联合体需要对齐











//////////【题目】1.下面代码结果是？
//
//union Un
//{
//	short s[7];
//	int n;
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));//16
//	return 0;
//}
//
//////内存至少是14，最大对齐数是16，使用内存为16字节









////////////【题目】2.下面代码结果是？
//
//int main()
//{
//	union
//	{
//		short k;
//		char i[2];
//	}*s, a;
//	s = &a;
//	s->i[0] = 0x39;
//	s->i[1] = 0x38;
//	printf("%x\n", a.k);//3839
//	return 0;
//}
//
////// 赋值后内存为 0x39 38
////// 小端存储，short结果为 0x3839