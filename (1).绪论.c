#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>






////目录：
//
////  1.数据结构的研究内容
////  2.基本概念和术语
////  3.抽象数据类型的表示和实现
////  4.算法和算法分析




















//////////////////////////////////////////////     1.1 数据结构的研究内容


//////计算机解决问题的步骤
//// 1.抽象为数学模型 -> 2.设计算法 -> 3.编程、调试、运行
// 
//////抽象为数学模型实质：
//// 分析问题 -> 提取操作对象 -> 找出操作对象间的关系 -> 用数学语言描述
////              (        数       据       结       构        )






//////有些问题无法用数学公式或方程来描述，是“非数值计算”的程序设计问题
//////描述非数值计算的数学模型不是数学方程，而是诸如“表”、“树”和“图”之类的具有逻辑关系的数据。
// 表：一对一
// 树：一对多
// 图：多对多
// 
////【数据结构】是研究【非数值计算】的程序设计中计算机的【操作对象】以及他们之间的【关系】和【操作】的学科。


























//////////////////////////////////////////////     1.2 基本概念和术语




///////////////////////////////////////    【数据相关的概念】

////////// 1.【数据】(Data)
// 
////·数据：能输入计算机且能被计算机处理的各种符号的集合
//
////·数据包含【数值型数据】和【非数值型数据】
/// 数值型数据：整数、实数
/// 非数值型数据：文字、图像、图形、声音等
//// 二者区别是能否进行算术运算
//
////·数据由数据元素组成




////////// 2.【数据元素】(Data Element)
//
////·数据元素：是数据的基本单位，在计算机程序中通常作为应该整体来考虑和处理
////   与数据的关系：集合与集合的个体 
//
////·数据元素也称为元素，或称为记录(表)、节点(树)或顶点(图)
//
////·一个【数据元素】可以由若干个【数据项组成】




////////// 3.【数据项】(Data Ltem)
//
////·数据项：构成数据元素的不可分割的最小单位
//
////·数据 > 数据元素 > 数据项
//// 例：学生表 > 个人纪录 > 姓名、学号




////////// 4.【数据对象】(Data Object)
//
////·数据对象：是【性质相同的数据元素的集合】，是数据的一个子集
////    与数据的关系：集合与集合的子集 
// 
//// 例如：
////     整数数据对象是集合N={0,1,2...}
////     字母字符数据对象是集合C={'A','B','C'...}
////     学生表也可看作数据对象










///////////////////////////////////////    【数据结构】


////////// 【数据结构】
//
////·数据元素不是孤立存在的，它们之间存在某种关系，【数据元素相互之间的关系称为“结构”】
//
////·数据结构是指【相互之间存在一种或多种特定关系】的数据元素集合
////  或者说，数据结构是带结构的数据元素的集合






//////// 【数据结构包括以下三个方面的内容】
//
//// 1.数据元素之间的逻辑关系，也称为【逻辑结构】
//// 2.数据元素及其关系在计算机内存中的表示（又称为映像），称为数据结构的【物理结构】或数据的【存储结构】
//// 3.数据的【运算和实现】，即对数据元素可以施加的操作以及这些操作在相应的存储结构上的实现。



//////// 数据结构是的两个层次
//
////【逻辑结构】
//// 描述元素之间的逻辑关系
//// 与数据的存储无关，独立于计算机
//// 是从具体问题中抽象出来的数学模型
//
////【物理结构（存储结构）】
//// 数据元素及其关系在计算机存储器中的结构（存储方式）
//// 是数据结构在计算机中的表示
//
// 
////【逻辑结构与存储结构的关系】：
//// 存储结构是逻辑关系的映像与元素本身的映像
//// 逻辑结构是数据结构的抽象，存储结构是数据结构的实现
//// 两者综合起来建立了数据元素之间的结构关系










///////////////////////////////////////    【逻辑结构的种类】


////// 【划分方法一】
// 
////（1）线性结构
////   有且仅有一个开始和一个终端点， 并且所有的结点都最多只有一个直接前驱和一个直接后继。 
////   例如：线性表、栈、队列、串
// 
////（2）非线性结构
////   一个借点可能有多个直接前驱和直接后继
////   例如：树、图




////// 【划分方法二】
//
////（1）集合结构
////   结构中的数据元素除了【同属于一个集合的关系】外，无任何其他关系
//
////（2）线性结构
////   结构中的数据元素之间存在这【一对一】的线性关系
//
////（3）树形结构
////   结构中的数据元素之间存在着【一对多】的层次关系
//
////（4）图形结构（网状结构）
////   结构中的数据元素之间存在着【多对多】的任意关系









///////////////////////////////////////    【存储结构的种类】

//////// 【四种基本的存储结构】
////·顺序存储结构
////·链式存储结构
////·引索存储结构
////·离散存储结构




////// 1.【顺序存储结构】
//
//// 用一组【连续的存储单元】依次存储数据元素，数据元素之间的逻辑关系由元素的存储位置来表示
//// 例如：C语言中用数组来实现顺序存储结构



////// 2.【链式存储结构】
//
//// 用一组【任意的存储单元】存储数据元素，数据元素之间的逻辑关系用【指针】来表示
// 
//// 例如：C语言中用指针来实现链式存储结构
//// 【存储这个元素本身的同时存储下一个元素的地址；若无下一个元素，地址则存空指针】



////// 3.【索引存储结构】
//
//// 在存储结点信息的同时，还建立附加的【索引表】
//// 索引表中的每一项称为一个【索引项】
//// 【索引项的一般形式】为：（关键字，地址）
//// 关键字是能【唯一识别】一个节点的那些数据项
//// 若每个节点都有一个索引项，则该索引表称之为稠密索引，若一组结点在索引表中只对应一个索引项，则该索引表称之为稀疏索引



////// 4.【散列存储结构】
//
////根据结点的关键字直接计算出该结点的存储地址










///////////////////////////////////////    【数据类型和抽象数据类型】

////使用高级程序设计语言编写程序时，必须对程序中出现的每个变量、常量或表达式，明确它们所属的【数据类型】
//// 例如，C语言中：
////     提供int,char,float,double等基本数据类型
////     数组、结构体、共用体、枚举等构造数据类型
////     还有指针、空(void)类型
////     用户也可以typedef自己定义数据类型
//
// 
////·一些基本数据结构可以用数据类型来实现，如数组、字符串等；
////·另一些常用的数据结构，如栈、队列、树、图等，不能直接用数据类型来表示。





////////// 【数据类型】
//
////高级语言中数据类型明显地或隐含地【规定了在程序执行期间变量和表达式的所有可能的取值范围】，以及这些数值范围上运行进行的操作。
////例如：
////    C语言定义的int类型，表示的i就是[-2^32 , 2^32-1],在这个整数集上可进行+、-、*、/、%等操作
//
// 
////【数据类型】
//// 定义：数据类型是一组性质相同的【值的集合】以及定义于这个值集合上的【一组操作】的总称 
////  数据类型 = 值的集合 + 值集合上的一组操作 
// 
// 
//// 数据类型的作用
//// 1.约束变量或常量的取值范围
//// 2.约束变量或常量的操作








////////// 【抽象数据类型】（Abstract Data Type = ADT）
//
////抽象数据类型是指：一个数学模型 以及 定义在此数学模型上的一组操作
//// 由用户定义，从问题抽象出【数据类型】（逻辑结构）
//// 还包括定义在数据模型上的一组【抽象运算】（相关操作）
//// 不考虑计算机内的具体存储结构与运算的具体实现算法
//
//
// 
//// 抽象数据类型的【形式定义】：
//// 
////·抽象数据类型可用 (D ,S ,P) 三元组表示
//// 其中：D 是数据对象
////       S 是数据对象(D)间的关系的集合
////       P 是对数据对象(D)的基本操作的集合
//
// 
//
//// 一个抽象数据类型的【定义格式】如下：
//// 
//// ADT 抽象数据类型名
//// {
////     数据对象：<数据对象的定义>
////     数据关系：<数据关系的定义>
////     基本操作：<基本操作的定义>
//// }ADT 抽象数据类型名
//// 
////   其中：数据对象、数据关系的定义用伪代码描述
////         基本操作的定义格式为： 基本操作名 +（参数列表）
////                                初始条件 ：<初始条件描述>
////                                操作结果 ：<操作结果描述>
//
//
//////【基本操作】定义格式说明：
////// 参数表：赋值参数（只为操作提供输入值）
//////         引用参数（以&打头，除可提供输入值外，还将返回结果）
//////
////// 初始条件：描述操作执行之前数据结构和参数应满足的条件，若不满足，操作失败，返回相应出错信息。
//////           若初始条件为空，则省略之。
//////
////// 操作结果：说明操作正常完成之后，数据结构的变化状况和返回的结果。  




//////// 综上，抽象数据类型（ADT）定义形式如下：
////
////ADT 抽象数据类型名
////{
////   Data
////    数据对象的定义
////    数据元素之间逻辑关系的定义
////   Operation
////    操作1 
////      初始条件
////      操作结果描述
////    操作2
////      ......
////    操作n
////      ......
//// }ADT 抽象数据类型名





/////// 实例1：抽象类型【圆】
//ADT Circle
//{
//   数据对象：D = {r,x,y | r,x,y 均为实数}
//   数据关系：R = {<r,x,y>|r是半径,<x,y>是圆心坐标}
//   基本操作：
//   Circle(&C,r,x,y)
//         操作结果：构造一个圆
//   double Area(C)
//         初始条件：圆已存在
//         操作结果：计算面积
//   double Circumference(C)
//         初始条件：圆已存在
//         操作结果：计算周长
//   ...... 
//} ADT Circle





/////// 实例2：抽象类型【复数】
//ADT Complex
//{
//   D = {r1,r2 | r1 r2都是实数}
//   S = {<r1,r2> | r1是实部, r2是虚部}
//   assign(&C,v1,v2)
//     初始条件：空的复数C已存在
//     操作结果：构造复数C，r1,r2分别被赋以参数v1,v2的值
//   destory(&C)
//     初始条件：复数C已存在
//     操作结果：复数C被销毁
//   GetReal(C,&realPart)
//     初始条件：复数C已存在
//     操作结果：用realPart返回复数C是实部值
//   GetLmag(C,&lmagPart)
//     初始条件：复数C已存在
//     操作结果：用lmagPart返回复数C是虚部值
//   ......
//} ADT Complex
//


























//////////////////////////////////////////////     1.3 抽象数据类型的表示和实现



////// 我们在上面已经知道了抽象数据类型的格式，如下所示
//
////ADT 抽象数据类型名
////{
////   Data
////    数据对象的定义
////    数据元素之间逻辑关系的定义
////   Operation
////    操作1 
////      初始条件
////      操作结果描述
////    操作2
////      ......
////    操作n
////      ......
//// }ADT 抽象数据类型名




////// 我们这里用【C语言】实现抽象数据类型
//// 即用已有数据类型定义描述它的存储结构，用函数定义它的操作。
//
////抽象数据类型可用通过固有的数据类型（整型、浮点型...）来实现表示，
////即利用处理器中已存在的数据类型来说明新的结构，用已经实现的操作来组合新的操作。







/////// 实例：抽象类型【复数】的C语言实现


//////// 【框架构思】如下：
// 
//ADT Complex
//{
//   D = {r1,r2 | r1 r2都是实数}
//   S = {<r1,r2> | r1是实部, r2是虚部}
//   assign(&C,v1,v2)
//     初始条件：空的复数C已存在
//     操作结果：构造复数C，r1,r2分别被赋以参数v1,v2的值
//   destory(&C)
//     初始条件：复数C已存在
//     操作结果：复数C被销毁
//   GetReal(C,&realPart)
//     初始条件：复数C已存在
//     操作结果：用realPart返回复数C是实部值
//   GetLmag(C,&lmagPart)
//     初始条件：复数C已存在
//     操作结果：用lmagPart返回复数C是虚部值
//   ......
//} ADT Complex



//////// 【C语言实现抽象类型】复数如下：
//
//typedef struct Complex//含实部虚部的复数结构体
//{
//	float realpart;
//	float imagpart;
//}Complex;
//
//void assign(Complex* C, float real, float imag)//将实部虚部传入复数结构体中的函数
//{
//	C->realpart = real;
//	C->imagpart = imag;
//}
//
//void destory(Complex* C)//复数归零的函数
//{
//	C->realpart = 0;
//	C->imagpart = 0;
//}
//
//void GetReal(Complex C, float* real)//把实部赋给real
//{
//	*real = C.realpart;
//}
//
//void GetLmag(Complex C, float* imag)//把虚部赋给imag
//{
//	*imag = C.imagpart;
//}
//
////...
//
//int main()
//{
//	Complex A = { 0 };//创建一个复数A（结构体）
//	assign(&A, 2, 1);//复数A 实部赋值为2，虚部赋值为1
//	//......
//	float a, b;
//	GetReal(A, &a);//复数的实部存给a
//	GetLmag(A, &b);//复数的虚部存给b
//	printf("%f %f", a, b);
//	return 0;
//}
//
////// 我们可用看出，C语言的抽象类型就是通过定义变量和定义众多函数实现
////// 我们自己写抽象类型的时候，最好把函数的实现封装到独立的.c文件，声明封装到独立的.h文件中，这样当我们调用自定义的抽象1类型，只需引头文件即可。


























//////////////////////////////////////////////     1.4 算法和算法分析


//////  算法的定义：
//////  是对特定问题求解方法和步骤的一种描述，它是指令的有限序列。其中每个指令表示一个或多个操作
// 
//// 简而言之，算法就是解决问题的方法和步骤
//// Step 1 ...
//// Step 2 ...
//// Step 3 ...



////// 算法与程序：
//
////·【算法】是解决问题的一种方法或一个过程，考虑如何将输入转换成输出，一个问题可以有多种算法。
////·【程序】是用某种程序设计语言对算法的具体实现
//
//// 程序 = 数据结构 + 算法
//// 数据结构通过算法实现操作；算法根据数据结构设计程序



////// 【算法特性】
//
//// 1.有穷性
//// 2.确定性：每条已经有切实的含义，无二义性，任何条件只有一条执行路径，相同的输入只能得到相同的输出
//// 3.可行性
//// 4.输入：有零个或多个输入
//// 5.输出：洋浦一个或多个输出


////// 【算法要求】
//
//// 1.正确性：不含错误一切合法输入设计都能算出满足的结果，且对应精心选择的、典型、苛刻、带有刁难性的输入都要输出正确的结果。
//// 2.可读性
//// 3.健壮性（鲁棒性）：输入非法设计时，不产生不可预料的结果。出错时，不应终端程序的执行，而是返回一个表示错误或错误性质的值。
//// 4.高效性



















////////////// 【算法的效率】
//
//// 1.时间效率：算法所消耗的时间（相对时间）
//// 2.空间效率：算法执行过程中所消耗的空间
// 
//// 时间效率和空间效率有时是矛盾的






////// 时间效率的【两种度量方法】：
//// 1.事后统计
////       将算法实现，测算时间和空间开销。
////       缺点：编写实现消耗时间精力；所得结果依赖于计算机硬件环境等因素，掩盖算法本身的优劣。      
//// 2.事前分析
////       对算法所消耗资源的一种估算方法。



////// 事前分析方法：
//// 一个算法的运行时间大致等于计算机执行一种简单的操作（如赋值、比较、移动等）所需要的时间与操作次数的乘积。
////  【算法运行时间 = 一个简单操作所需时间 * 简单操作次数】   
// 
////·也即算法中每条语句执行时间之和
////  【算法运行时间 = Σ每条语句执行次数 * 该语句执行一次所需的时间】
////  【算法运行时间 = Σ每条语句频度 * 该语句执行一次所需的时间】  // 每条语句执行次数 = 语句频度
//
// 
//// 每条语句执行一次的时间随机器而异，与算法无关，所以假设每条语执行时间均为【单位时间】。
//// 算法运行时间讨论时，单位时间消掉，只讨论执行次数（Σ语句频度）即可。



////// 例：
//
//#define n 100
//int main()
//{
//	int i, j, k;
//	int a[n][n] = { 0 };
//	int b[n][n] = { 0 };
//	int c[n][n] = { 0 };
//
//	for (i = 1; i <= n; i++)//第一个for：条件成立n次，但是还有一次判断条件不成立，该语句执行n+1次
//	{
//		for (j = 1; j <= n; j++)//第二个for：循环n次，每次循环执行n+1次，该语句执行n*(n+1)次
//		{
//			c[i][j] = 0;  // 执行n*n次
//			for (k = 0; k < n; k++)//第三个for：循环n*n次，每次循环执行n+1次，该语句执行n*n*(n+1)次
//			{
//				c[i][j] = c[i][j] + a[i][k] * b[k][j];// 执行n*n*n次
//			}
//		}
//	}
//	return 0;
//}
//
////// 我们把算法所耗费的时间定义为该算法中每条语句的频度之和，则上面算法(之看中间三个循环)时间消耗 T(n) 为：
////// T(n) = n+1 + n*(n+1) + n*n + n*n*(n+1) + n*n*n
////// 化简得：T(n) = 2*n*n*n + 3*n*n + 2*n + 1






////////////////////////////////////  【 时间复杂度 】
//
// 
// 
//////// 上面我们把每条语句频数一一数出来，太过复杂
/////·为了方便比较不同算法的时间效率，我们仅【比较它们的数量级】
// 
////   例如：T1(n)=10n^2 , T2(n)=5n^3
////   数量级小的T1比较好
// 
// 
////// 【渐近时间复杂度】
////// 若某个辅助函数f(n)，使得当n趋近于无穷大时，T(n)/f(n)的极限值为【不等于0的常数】，则称f(n)是T(n)的同数量级函数。
////// 记作【T(n) = O(f(n))】，称O(f(n))为【算法的渐近时间复杂度】(O是数量级的符号order)，简称【时间复杂度】



///// 【时间复杂度】的例子：
//
//// 求解矩阵相乘问题，算法耗费时间：T(n) = 2*n^3 + 3*n^2 + 2*n + 1
//// 当 n->∞时，T(n)/n^3 = 2
//// 这表示当n充分大时，T(n)与n^3是同数量级(同阶)，引入"O"记号
//// 【  T(n) = O(n^3)  】
//// 这就是该算法的渐进时间复杂度



////// 总结：
//////// 一般情况下，不必计算所有的操作执行次数，而是考虑算法中【基本语句】重复执行的次数，它是问题规模n的某个函数，用T(n)表示。
//////// 时间量记作【T(n) = O(f(n))】
//////// 表示随之n的增大，算法执行的时间的增长率和f(n)增长率相同，即渐近时间复杂度
//
// 
// P.S.
//   【基本语句】，即算法中执行次数最多，运行时间贡献最大的语句 
//   【n】：n越大算法执行时间越长，
//          排序：n为记录数
//          矩阵：n为矩阵的阶数
//          多项式：n为多项式的项数
//          集合：n为元素个数
//          数：n为结点个数
//          图：n为图的顶点数或边数









//////// 【分析算法时间复杂度的方法】
//// 定理1.1（找最高次数）
//// 若 f(n) = C1*n^m + C2*n^(m-1) + ... + C3*n + C4  是m次多项式
//// 则 T(n) = O(n^m) 
//
// 
//
/////// 计算时间复杂度步骤：
//// 1.找出语句频数最大的那条语句视为基本语句
//// 2.计算基本语句的频数得到问题规模n的某个函数f(n)
//// 3.取其数量级用符号"O"表示




 

///////////////////下面是计算时间复杂度的题目

//////// 例1：
// 
//#define n 100
//int main()
//{
//	int x = 0, y = 0, i, j, k;
//
//	for (i = 0; i < n; i++)
//	{
//		x++;
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)//判断语句1
//		{
//			y++;//赋值语句2
//		}
//	}
//
//	return 0;
//}
//
////// 判断语句1 和 赋值语句2 是执行次数最多(嵌套层次最深)的语句
////// 显然数量级为n^2
////// T(n) = O(n^2)





//////// 例2：
//
//#define n 100
//#define m 200
//int main()
//{
//	int i, j, sum = 0;
//	for (i = 0; i < m; i++)
//	{
//		for (j = 0; j < n; j++)//语句1
//		{
//			sum++;//语句2
//		}
//	}
//	return 0;
//}
//
////// 语句1 和 语句2 执行次数最多
////// 执行次数为 m*n
////// T(n) = O(m*n)





//////// 例3：
//
//#define n 100
//int main()
//{
//	int i, j, k, x=0;
//
//	for (i = 1; i < n; i++)
//		for (j = 1; j <= i; j++)
//			for (k = 1; k <= j; k++)//语句1
//				x += 1;//语句2  
//
//	return 0;
//}
//
////// 语句1 和 语句2 执行次数最多
//// 
////// 这种情况直接看不出来，需要从里往外求和 (多个Σ，从右往左一层层算)
//////              n    i    j        n    i        n                n
////// 执行次数为  Σ * Σ * Σ * 1 = Σ * Σ * j = Σ * i(i+1)/2 = Σ * (i^2+i)/2 = [n(n+1)(2n+1)/6 + n(n+1)/2]/2 = ...
//////             i=1  j=1  k=1      i=1  j=1      i=1              i=1
////
////// 可以看出数量级是n都三次方 
////// T(n) = O(n^3)





//////// 例4：
//
//#define n 100
//int main()
//{
//	int i = 1;
//	while (i <= n)
//		i *= 2;
//	
//	return 0;
//}
//
////// 设执行了x次，则i的值为2^x
////// 2^x <= n 成立，左右取对数，所以 x <= log2n 
////// 即 f(n) <= log2n ，f(n)表示关于次数的函数
////// 取最大值 f(n) = log2n
//// 
////// T(n) = O(log2n)








//////  ·请注意：有的情况下，算法中基本操作重复执行的次数还随问题的【输入数据集】不同而不同
//
// 
////// 例如：
////// 顺序查找，在数组a[i]中查找值等于e的元素，返回其所在的位置。
////// 
//////for(i=0;i<n;i++)
//////  if(a[i]==e)return i+1; //找到，则返回是第几个元素
//////return 0;
//////
////// 上面例子中：
////// 最好情况：1次
////// 最坏情况：n次
////// 平均次数为n/2
////// 平均时间复杂度为：O(n) //--是数量级，所以没有二分之一
//
// 
//
// 
// 
////// 【最好时间复杂度】：指在最好情况下，算法的时间复杂度
////// 【最坏时间复杂度】：指在最坏情况下，算法的时间复杂度
////// 【平均时间复杂度】：指所有可能输入实例在等概率出现的情况下，算法的期望运行时间
////
//////·一般总是考虑在最坏情况下的时间复杂度，以保证算法运行的时间不会比它更长






////// ·对于复杂的算法，可以将它分成几个容易估算的部分，然后利用"O"的加法法则和乘法法则，计算算法的时间复杂度：
// 
//// 【加法法则】：
////            T(n) = T1(n) + T2(n) = O(F(n)) + O(g(n)) = O(max(f(n), g(n))) 
// 
//// 【乘法法则】：
////            T(n) = T1(n) * T2(n) = O(F(n)) * O(g(n)) = O(f(n)* g(n)) 





////// ·当n取到很大是，不同类型数量级时间复杂度的算法在所需时间上非常悬殊
// 
//// 时间复杂度T(n)按数量级递增顺序为
//// 复杂度低 -----------------------------------------------------> 复杂度高
//// |常数阶 |对数阶   |线性阶 |线性对数阶 |平方阶 |立方阶 |K次方阶 |指数阶 |
//// |O(1)   |O(log2n) |O(n)   |O(n*log2n) |O(n^2) |O(n^3) |O(n^k)  |O(2^n) |


















////////////////////////////////////  【 空间复杂度 】
//
//
////// 空间复杂度：算法所需存储空间的量度
////// 记作：S(n) = O(f(n))
////// 其中n为问题的规模（或大小）
//
// 
////·算法要占据的空间
////  1.算法本身要占据空间：输入/输出，指令，常数，变量等
////  2.算法要使用的【辅助空间】




//////  【例】将一维数组a中的n个数逆序存放到原数组中

//// 算法1：
//for (i = 0; i < n / 2; i++)
//{
//	t = a[i];
//	a[i] = a[n - i - 1];
//	a[n - i - 1] = t;
//}
//// 用一个中间变量t实现逆序 
//// S(n) = O(1)


//// 算法2：
//for (i = 0; i < n / 2; i++)
//	b[i] = a[n - i - 1];
//for (i = 0; i < n / 2; i++)
//	a[i] = b[i];
// 
//// 创建新数组b实现逆序
//// S(n) = O(n) 


