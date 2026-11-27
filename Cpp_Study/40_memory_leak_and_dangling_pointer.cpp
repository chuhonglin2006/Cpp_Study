#include <iostream>
using namespace std;


// 内存泄露与悬空指针


// 内存泄露
void func_1() {
	// 1.忘记delete
	int* p = new int(10);
	cout << *p << endl;
} // 函数结束时 p被销毁 但是堆上的int 没释放 再也没人能找到这个p

void func_2() {
	// 2.指针被覆盖 丢失地址
	int* p = new int(10);
	// p = nwe int(20); // 第一块内存的地址丢失了
	delete p; // 只释放 了第二块
}

void func_3() {
	// 3.提前return 跳过了delete
	int* p = new int(10);
	if (true) {
		return;
	}
	delete p; // 上面直接返回了 未执行
}
// 程序运行越久，占用内存越多
// 严重时耗尽内存，程序变慢或崩溃


// 悬空指针
void func_4() {
	// 1.delete后继续使用
	int* p = new int(10);
	delete p;
	*p = 20; // p还保留着旧地址 但是内存已经归还系统 行为未定义
}

int* func_5() {
	// 2.返回局部变量的地址
	int x = 5; // 放在栈上的
	return &x; // x在函数结束时销毁 返回的地址无效
}

void func_6() {
	// 3.多个指针指向同一块内存
	int* a = new int(10);
	int* b = a;
	delete a;
	a = nullptr;
	cout << *b; // b变为悬空指针了 但是它并不知道a已经释放了
}
// 行为不可预测：可能崩溃，可能读到乱码，也可能"看起来正常"

















