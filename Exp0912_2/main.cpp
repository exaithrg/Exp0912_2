#include<iostream>
#include<cstdlib>

#include"header.h"
#include"header.h"

//一般情况下<>代表系统的库
//而""代表的是自己的库
//顺序一般是系统-第三方-我们自己的-当前工程的

//#include "3rdpart.h"
//#include "curproject.h"
//#include "main.h"

//尽量不要把命名空间内的所有东西全都调用起来
//因此下面的那句话尽量不要使用，它破坏了命名空间的意义
//using namespace std;

using std::cin;
using std::cout;
using std::endl;


//F5	调试
//Ctrl+S	保存
//Ctrl+C	加速
//Ctrl+V	加速
//Ctrl+X	整行删除（剪切）
//要习惯性的少量开发少量运行
//要确保每次编译运行的代码改动要小
//这样可以快速定位问题
//Ctrl+F10	运行程序到当前光标所在行
//要习惯性的在二元运算符左右打空格
//断点
//Shift + F5	停止
//F10	step over逐过程（不进函数体，直接下去）
//F11	step in逐语句（如果有函数，那么进到函数里面步进）
//有时候想看整片的内存区域
//调试可以看内存
//低位在前高位在后，小端方式存储
//自动补全：ord+右箭头
//按住Ctrl移动光标可以按词移动
//按住Ctrl+BackSpace可以按词删除
//监视 内存 调用堆栈
//连接符为\还是/忘了
//for中用++i而不是i++

//对偶编程的习惯，左括号+右括号，再去填中间
//写完malloc，立马就要把free写好

//在C++中，false是一个必错的逻辑。

int main() {
	system("color 4F");
	//code here
	int x;

	//关于cpp里面的namespace，也就是命名空间
	//主要是多人共同编程时怕重名

	//	>>	表示流式输入
	//	<<	表示流式输出
	//scanf是个二元的东西，不大好。因为它要求二者的小心匹配。
	//语言要专注到特殊的地方，而不是精力分散的开销——Python

	cin >> x;
	//endl会根据不同的电脑系统来决定换行的方式
	cout << x << endl;

	//end

	if (false && x == 0) {	//特殊的注释方法
		x = 1;
	}

	//多行注释的方法
	//不要使用多行注释
	//而且下面这种方法，改成if 1，就可以非常好的打开注释

#if 0
	哈哈哈哈
		卧槽这个注释方式太爽了
		就是这个Tab有点烦
		卧槽太爽了
#endif

		//大家在编程的时候，有时候格式会很乱，东一行西一行的
		//全选，按住Ctrl，再连按KF

		system("pause");
	return 0;
}

//Shortcut Keys		快捷键
//Reference：http ://www.dofactory.com/reference/visual-studio-shortcuts
//Alt					激活按字母键选择菜单的功能，如按F为文件菜单
//Alt + Shift			英文锁死
//Alt + Tab				Windows系统换窗口
//Alt + Shift + 箭头		矩形选定区域
//Alt + 上下箭头		调换两行的相对位置
//Ctrl + Tab			程序内部换选项卡
//Ctrl + 上下箭头		在不改变光标位置的情况下滑动窗口
//Ctrl + 左右箭头		智能加速左右的移动
//insert				光标变黑块
//Shift + 箭头			普通选定区域
//Tab / Shift + Tab		正反向移动选定区域
//Win + Ctrl + D			创建新桌面
//Win + Ctrl + 方向键		快速切换桌面
//Win + Ctrl + Fn + F4		关闭当前桌面，但不丢失应用程序。
//Win + D				显示桌面可逆
//Win + L				锁定电脑不断网
//Win + M				显示桌面不可逆
//Win + R				运行
//Win + Tab				桌面间的切换
//Win + X				调出快捷菜单，主要是任务管理器
//Win + 箭头			各种分屏，还可以切换窗口大小

//再讲引用
//传引用调用
//哪怕只是读取某个变量，有时候还是会用引用，引用的效率更高，而且安全
//引用的效率和指针一样
//也就是说，哪怕是个非常大的结构体，用引用只是传指针，所以就很快很舒服
//传值和传引用安全性差不多

//既要效率，又不要你改，那么就直接
//void func (const TYPE &f)
//如果要返回TYPE类型，意味着把func内部的一个东西返回
//就会有一个传参开销。
//TYPE result
//会有一个问题

//下面这种方式切不可使用
//TYPE &func(const TYPE &f){
//	TYPE f;
//	return f;
//}
//返回之后f已经崩了，啥也没了

//又想效率高的话怎么整呢


#if 0
zashu
dalfj
hhh
怎么肥死小老弟
哪里来的tab啊
#endif