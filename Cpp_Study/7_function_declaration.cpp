#include <iostream>
using namespace std;

// 函数的声明


void func();


int main() {
	// 如果一个函数定义在main函数下面时 直接调用函数会报错 此时要在main函数上面声明这个函数
	func();
	return 0;
}


void func() {
	cout << "函数被调用" << endl;
}