#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>




////// C语言文件操作
//// 
//// 什么是文件
//// 文件名
//// 文件类型
//// 文件缓冲区
//// 文件指针
//// 文件的打开和关闭
//// 文件的顺序读写
//// 文件的随机读写
//// 文件的结束判定





////  什么是文件？
//磁盘上的文件就是文件
//但在程序设计中，文件分两种：【程序文件】、【数据文件】

// 【程序文件】
//包括源文件(.c)、目标文件(windows环境后缀为.obj)、可执行程序(windows环境后缀为.exe)
// 【数据文件】
//文件内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件


//以前各章所处理的数据的输入输出都是以终端为对象的，即从终端的键盘输入数据，运行结果显示到显示器上。
//其实有时候我们会把信息输出到磁盘上，当需要的时候再从磁盘上把数据读取到内存中使用，这里处理的就是磁盘上的文件







////  文件名
//一个文件要有一个唯一的文件标识，以便用户识别和引用
//文件包含3部分：【文件路径+文件名主干+文件后缀】
//例如：c:\code\test.txt
//为了方便起见，文件标识常被称为文件名







////  文件类型
//根据数据的组织形式，数据文件被称为【文本文件】或者【二进制文件】。
//数据在内存中以二进制的形式存储，如果不加转换的【以二进制形式输出到外存】，就是二进制文件。
//如果要求在外存上以ASCII码的形式存储，则需要在存储前转换。【以ASCII字符的形式存储】的文件就是文本文件。

// 一个数据在内存中是怎么存储的呢？
//【字符】一律以ASCII形式存储，【数值型数据】既可以用ASCII形式存储，也可以用二进制形式存储
//如果有10000，如果以ASCII码形式输出到硬盘，则磁盘中占5个字节（'1','0','0','0','0'，每个字符1字节）；
//             如果以二进制形式输出，则硬盘上只占4个字节（1个整型4字节，十六进制小端输出 00002710）








////  文件缓冲区
//ANSIC标准(C语言标准)采用【缓冲区文件系统】处理的数据文件的，所谓缓冲区文件系统是指系统自动地在内存中为程序的每一个正在使用的文件开辟一块缓冲区。
//【从内存向磁盘输出数据】会先送到内存的缓冲区中，装满缓冲区后才一起送到磁盘上。
//【从磁盘向计算机读入数据】，则从磁盘文件中读取数据输入到内存缓冲区（充满缓冲区），然后从缓冲区逐个地将数据送到程序数据区（程序变量等）.
//缓冲区的大小根据C编译器系统决定








////  文件指针
//缓冲文件系统中，关键的概念是【文件类型指针】，简称【文件指针】
//每个被使用的文件都在内存中开辟了一个相应的【文件信息区】，用来存放文件的相关信息（如文件名字、文件状态以及文件当前的位置等）
//这些信息是保存在一个结构体变量中的，该结构体类型有系统声明，取名【FILE】 

//struct file {
//	 char* ptr;
//	 int cnt;
//	 char* base;
//	 int flag;
//	 int file;
//	 int charbuf;
//	 int bufsiz;
// 	char* tmpfname;
//};

//不同的编译器的FILE类型包括的内容大同小异。
//每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，并填充其中信息。
//一般是通过一个FILE的指针来维护这个结构体，使用起来更加方便。
// 
//例如 FILE* pf -- 文件指针变量
//定义pd是一个指向FILE类型的指针变量，可以是ps指向某个文件的文件信息区（上一个结构体变量），通过文件信息区就能访问该文件。
//也就是说，【通过文件指针变量就能找到与它相关的文件】






















/////////////////////////////  文件的打开和关闭
////文件读写前应该打开文件，使用后应该关闭文件
////写程序的时候，在打开文件同时，都会返回应该FILE*的指针指向该文件，相当于建立了指针和文件的关系。
////ANSIC(标准C语言)规定使用fopen函数来打开文件，fclose来关闭文件。






//////////////////////    fopen() -- 打开文件函数,<stdio.h> 
////file open,打开文件，创建文件信息区(FILE结构体)，返回结构体区的指针(FILE*)
// 
////声明：FILE *fopen( const char *filename, const char *mode );
//
////参数：char *filename -- 文件名
////      char *mode  --  打开方式(下面的表格)
//
////返回值：打开文件成功，会创建一个文件信息区(FILE类型的结构体变量)；打开失败则不创建
////        打开文件成功，返回FILE*类型信息区的指针
////        打开失败，不创建信息区，返回NULL



//  【提示】：下面表格中： r:(读)read  w:(写)write  a:(追加)add  b:(二进制)binary
//  ----------------------------------------------------------------------------------------
//  |文件打开(使用)方式  | 含义                                       | 如果指定文件不存在
//  ----------------------------------------------------------------------------------------
//  |  "r" (只读)        | 为了输入数据，打开一个已保存的文本文件     | 出错
//  |  "w" (只写)        | 为了输出数据，打开一个文本文件             | 建立一个新文件
//  |  "a" (追加)        | 向文本文件尾添加数据                       | 出错
//  |  "rb" (只读)       | 为了输入数据，打开一个二进制文件           | 出错
//  |  "wb" (只写)       | 为了输出数据，打开一个二进制文件           | 建立一个新文件
//  |  "ab" (追加)       | 向二进制文件尾添加数据                     | 出错
//  |  "r+" (读写)       | 为了读和写，打开一个文本文件               | 出错
//  |  "w+" (读写)       | 为了读和写，新建一个文本文件               | 建立一个新文件
//  |  "a+" (读写)       | 打开一个文本文件，在文件结尾进行读写       | 建立一个新文件
//  |  "rb+" (读写)      | 为了读和写，打开一个二进制文件             | 出错
//  |  "wb+" (读写)      | 为了读和写，新建一个二进制文件             | 建立一个新文件
//  |  "ab+" (读写)      | 打开一个二进制文件，在文件结尾读和写       | 建立一个新文件
//  ----------------------------------------------------------------------------------------
// 
// r读：打开当前路径下文件。
// w写：在当前路径新建文件。*注意：打开位置若有同名文件，会销毁旧文件，拿新的覆盖掉
// a追加：打开已有文件，并可以在其之后追加新数据



//int main()
//{
//	////////【fopen打开文件】test.txt
//
//	////【相对路径】，相对于当前代码在哪个路径底下
//	//// . 表示当前路径
//	//// .. 表示上级路径
//	FILE* pf = fopen("test.txt", "r");//文件就在当前文件夹
//	FILE* pf = fopen(".\\test.txt", "r");//文件就在当前文件夹，和上一个一样
//	FILE* pf = fopen("..\\test.txt", "r");//文件在当前路径的上一级路径
//	FILE* pf = fopen("..\\..\\test.txt", "r");//文件在当前路径的上两级路径
//
//	////【绝对路径】，明确的指出了文件的具体路径
//	FILE* pf = fopen("C:\\Users\\lenovo\\source\\repos\\test - 1\\test - 1\\test.txt", "r");//这里\\的目的是，防止\变成转义字符
//	FILE* pf = fopen("C:/Users/lenovo/source/repos/test - 1/test - 1/test.txt", "r");//这里 \\ 和 / 都可以
//
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	return 0;
//}


//注意：当写路径时，/会和下一个字符被当成转义字符，所以要写成 // 
//  默认情况向下的路径中，windows是\,linux和unix下是/ 但在win中没有区别。
// 在WINDOWS里面很多情况下/和\是可以通用的，尤其是在地址栏中。但是，正规的地址表示还是应该用/，比如C：/WINDOWS等。
// 
//  由于 \ 也是转义字符的起始字符。由此， 路径中的 \ 通常需要使用 \\，如果是 / 就不用转义了
//  例如：C中文件操作，c:\\kkk\\dd.txt ；c : / kkk / dd.txt一样










//////////////////////    fclose() -- 关闭文件函数,<stdio.h> 
////关闭文件流 
//
////声明：int fclose( FILE *stream );
//
////参数：指向(结构体)文件信息区的（FALE*类型）指针
//
////返回值：若关文件动作成功则返回0，有错误发生时则返回EOF，并把错误代码存到errno




//////文件的打开和关闭演示
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("test.txt", "r");//打开一个文本文件
//	//FILE* pf = fopen("test1.txt", "w");//创建一个新的文本文件，若同路径下有同名文件，直接摧毁并用新的覆盖
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//打开成功
//	
//	//读文件
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}




