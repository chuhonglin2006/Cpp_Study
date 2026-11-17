#include <iostream>
#include <string>
using namespace std;

// 在计算机中每种不同类型的数据占用的大小也不同

int main() {
	// ReSharper disable once CppLocalVariableMayBeConst
	int a = 10;
	double b = 0.1;
	string c = "abc";
	char d = 'a';

	// 这里定义了3个最基本的类型 整数 小数 字符串 字符

	// 使用sizeof函数可以查看占用字节大小

	cout << "int占用:" << sizeof(a) << "字节" << endl;
	cout << "double占用:" << sizeof(b) << "字节" << endl;
	cout << "char占用:" << sizeof(d) << "字节" << endl;


	return 0;
}