#include <memory>
using namespace std;

// 堆与栈

// 栈（stack）系统自动管理的内存 用来放局部变量 函数结束自动回收
// 堆（heap）程序员手动申请 手动释放的内存 生命周期由你控制



void func() {
	int a = 10; // 栈：局部变量，func 结束自动销毁
	int* p = new int(20);  // 堆：new 出来的，p 本身在栈上，指向的 int 在堆上
	delete p; // 手动释放  p 这个指针变量本身在栈上，它指向的那块内存在堆上
	p = nullptr; // 置空
}

/* 什么时候用堆 :
 * 1.对象需要比当前函数活的久
 * 2.数据很大
 * 3.大小运行时才知道
 * 4.通过基类的指针或引用 去访问派生类对象
 */

// 智能指针
// 尽量不要手写 new/delete 用智能指针让堆内存也能 自动回收
auto p = make_unique<int>(20); // 堆上的 int p 离开作用域时自动 delete

