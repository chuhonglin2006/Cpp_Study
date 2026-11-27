#include <iostream>
using namespace std;

// 常量


int main() {
	const int MAX = 100; // 使用const修饰的变量，定义后不能修改,必须在定义时初始化

	#define Pi 3.14159 // 宏常量 预处理阶段的文本替换 没有类型 不受作用域限制

	constexpr int N = 10; // constexpr常量
	// const的初始值可以来自运行时 constexpr必须在编译期算出

	return 0;
}