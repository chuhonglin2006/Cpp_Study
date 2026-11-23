#include <iostream>
#include <string>
using namespace std;


// 函数进阶 重载 默认参数 内联函数 递归


// 函数重载 允许多个函数使用相同的名称 但是参数必须不同
void print_func(int num) {
	cout << "整数:" << num << endl;
}

void print_func(double num) {
	cout << "浮点数:" << num << endl;
}

void print_func(string str) {
	cout << "字符串:" << str << endl;
}



// 函数的默认参数  默认参数就是在定义函数时，为参数指定一个默认值
void print_str(string str = "Null") { // 如果某个参数设置了默认值 那么它后面的参数也必须设置默认值
	cout << str << endl;
}



// 内联函数  建议编译器将函数调用处替换成函数体代码 从而减少函数调用开销
inline int add(int a,int b) {
	return a + b;
}



// 递归 函数自己调用自己
void test(int num) {
	cout << "Hello" << endl;
	num--;
	if (num == 0) {
		cout << "递归结束" << endl;
		return;
	}
	test(num); // 函数会不断调用自己  没有停止条件 会一直递归 最终可能导致栈溢出
}



int main() {
	// 函数重载调用
	print_func(1);
	print_func(1.0);
	print_func("1");

	// 函数的默认参数
	print_str("Hello");
	print_str(); // 当不填参数时 使用默认参数

	// 内联函数
	cout << add(10,20) << endl;
	// 编译器可能将 add(10, 20); 直接按照类似 10 + 20; 的方式展开 减少了一定开销
	// inline 并不意味着编译器必须将函数展开 它只是向编译器提出内联建议 最终是否展开由编译器决定

	// 递归
	test(10);

	return 0;
}