#include <iostream>
using namespace std;

// 函数的定义与使用


// 函数的定义
int function(int a,int b) {  // 定义一个返回int的函数 括号里面为函数需要的参数
	int result = a + b; // 将a + b 的结果赋值给result
	return result;
}

// 无返回值函数的定义
void func() {
	cout << "这是一个无返回值函数" << endl;
}


// 函数的使用
int main() {
	int result = function(10,20); // 定义一个变量来接受函数的返回值
	cout << "函数返回了:" << result << endl;
	func();
	return 0;
}
