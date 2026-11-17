#include <iostream>
using namespace std;

// 算术运算符

int main() {
	int number_1 = 10;
	int number_2 = 20;
	cout << number_1 + number_2 << endl; // + 加
	cout << number_1 - number_2 << endl; // - 减
	cout << number_1 * number_2 << endl; // * 乘
	cout << number_1 / number_2 << endl; // / 除
	cout << number_1 % number_2 << endl; // % 取余
	cout << number_1++ << endl; // ++ 自增
	cout << number_1-- << endl; // -- 自减

	// 除法 : 两边都是整数 结果就是整数 小数部分直接舍弃 有一个小数结果才是小数
	cout << "两边都是整数:" << 5 / 3 << endl;
	cout << "有一个小数:" << 5 / 3.0 << endl;

	// 取余 : 只能用于整数 小数会报错 结果的符号与被除数一致
	cout << 10 % 3 << endl;
	cout << -10 % 3 << endl;

	// 自增自减 : 前置 ++a 先加1再使用值 后置 a++ 先使用值再加1
	int a = 5;
	int b = ++a; // a先变成6 b=6
	cout << a << " " << b << endl;

	int c = 5;
	int d = c++; // d先拿到5 c再变为6
	cout << c << " " << d << endl;

	// 优先级 : ++ -- > * / % > + - 同级从左到右 小括号可以改变优先级

	return 0;
}