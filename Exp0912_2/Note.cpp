#include<iostream>
#include<cstdlib>
int Learn0919(void) {

	// 关于const的用法

	//局部变量的定义
	const int x = 0;
	//const 表示变量赋值后不可变。

	//定义常数
	static const int max_number = 80;
	//这个有编译器参与，define没有，所以这个容易查错

	enum {
		PROC_PKG_FLAG1 = 0,	//控制初始值
		PROC_PKG_FLAG2,	//控制初始值
		//以下自动+1
	};

	//指向的东西不能改变
	int a;
	const int *ptr = &a;
	a = 3;

	//指针本身不能改变
	int *const ptr = &a;

	//编译器只在乎你是否尝试改变，不在乎是否改变有意义
	//
	const int * const ptr = &a;

	//加上typedef之后Student就成了一个类型了。
	//age和ssss位于的内存区域在哪里？没有，不占内存。
	//仅仅是说明Student类型的内存组织方式
	typedef struct
	{
		int age;	// =偏移地址=0
		int ssss;	// =偏移地址=4
	}Student;

	//开始占空间。
	//位置严格取决于数组空间。
	Student aaaaa;

	const Student s;
	//下一句错误。
	//s.age = 3;

	int(*funcptr)(int, int);	//函数指针，增强灵活性
	//减少依赖 与 僵化
	//这种操作叫做依赖转置

	//方便的定义函数指针的方法：加typedef
	typedef int(*FuncPtr)(int, int);
	FuncPtr funcptr;
	//这就叫“函数指针类型”
	//typedef会让人写的很舒服

	//如何读typedef
	typedef int * IntPtr;
	//盖掉typedef，IntPtr叫做整型指针
	//FuncPtr就叫做函数指针


	//整型的一个引用.导致y是tt的别名，二者完全一致
	int tt;
	int &y = tt;

	//引用的底层来讲，地址一样
	//因此类似int &y;


	//传指针调用
	//不够安全，因为函数要求给指针，就要做好指针不合法的准备
	//传引用就很舒服。底层实现和指针是一样的，效率和指针一样，安全性和值一样

	//高效传参而且保证参数不变。
	void swap(const int &x, const int &y);
	//还有一个好处，就是可以兼容const TYPE
		
}


//传引用调用有个问题
int add(int &x, int &y) {
	return x + y;
}

//类似add(1,2)会出错
//权限只能缩小，不可以不可以不可以扩大
//编译器不可以接收权限扩大的转换
//那么add(1,2)怎么搞？写一个针对整型的版本。
//只要不对原量操作，就加const。例如add函数，考虑加const以适应add(1,2)
//可维护性。没有必要维护两个版本
//const利用，常量字符串

int add2(const char *str);

//尽量不使用的函数：
void ConstToInt() {
	const int xx = 3;
	//const_cast<int>(xx) = 3;
}

//另一个效率考虑：引用返回？
int &add3(int x, int y) {
	int temp = x + y;
	return temp;
}
//表示返回的值和temp是一个东西。
//这就涉及到一个问题：这个空间在哪里呢
//这个莫得名字的东西和temp空间一致
//temp的空间在栈上，用完就返回回去没了
//所以直接完蛋。不可以用。


//那么有什么方式呢
int &add4(int x, int y) {
	int temp = x + y;
	return temp;
}
//用：全局变量，或者static int temp，表示地址静态。
//或者，add(int x,int y,int &temp);

//这都是多少年的老操作了


const int xa = 3;
int add_0926(int &xa, int &y);	//xa会报错，因为const
//改法：
int add_1(const int &xa, int &y);
//或者：
int add_2(int x, int y);

//20190926新内容
//new delete

int Lesson0926(void) {
	int n = 5;	//example
	int* p1 = (int*)malloc(sizeof(int));
	free(p1);
	//new和delete不需要自己算
	int *p2 = new int;
	int *p3 = new int[n];
	delete p2;
	//---------------------反人类的分割线-----------------------------------
	delete[]p3;	//很反人类的设计，必须要高度关注。为什么不能像free一样呢
	//---------------------反人类的分割线-----------------------------------
	//类的构造和析构
	//自动初始化，以及自动的善后
	//new具有这种功能，而malloc和free则没有
	//delete就是一个垃圾回收机制
	//这次作业考虑使用new
	//默认传参：&	默认内存分配（在堆上）：new & delete
	//数组的访问时间复杂度是O(1)，链表则是O(n)
	//链表的增加删除结点，是O(1)
	//

	//同名函数，重载：参数不同（不能仅按返回值区分）
	//对于函数形参来说，变量名字没用，变量类型才有用
	//因此声明时可以不指出函数形参的名字

	//供需关系

	//WWWWWWWeraaaaaaaaa！
	//489848948984893212333222355321233322321156652532132632531465235465423

	//函数的默认值
	//方向：从右往左。
	//例如 void function(int i, int j)，要么j有默认，要么ij有默认，要么都没有默认
	//默认值的分析顺序为从右往左

	//内联函数（重要）
	//inline. 专门用来修饰函数。
}

//内联函数是指在定义函数定义时的东西。
//内联函数的作用是 建议 编译程序把该函数的函数体展开到调用点，以提高函数调用的效率
//具体做不做要看编译器心情
//内联不会出编译错误，也不会在运行中出bug
//内联函数具有文件作用域（（（（（（什么意思呢））））））

//比下面这种宏定义要爽
#define max(a,b) a>b?a:b
#define maxkh(a,b) (((a)>(b))?(a):(b))
//后者在max(x+1,y*2)上还会出问题，因为x+1会做两次。
void inlinetest(){
	//注意，调用函数会有各种压栈出栈之类的操作，加了非常多东西
	//因此有时候需要用宏直接展开
	int x, y, z;
	10 + max(x, y) + z;
	//宏的操作是字符串的简单替换。
	//直接替换会导致比较10+x是不是大于y。（操作符优先级问题）
	//解决方案：加大量的括号
}


//凑行数
//凑满200行结束

namespace A
{
	int x = 1;
	void f() {
		printf("lll");
	}
}
namespace B
	//花括号可以跨文件
{
	int x = 0;
	void f(int x) {
		x = 3;
	}
}