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


	// 复合赋值运算符
	int y = 10;
	y += 5; // 等同于 y = y + 5
	y -= 3; // 等同于 y = y - 3
	y *= 2; // 等同于 y = y * 3
	cout << y << endl;


	// 关系运算符 ==、!=、<、>、<=、>=,结果类型是 bool
	int q = 10;
	int w = 20;
	cout << "q是否等于w:" << (q == w) << endl;
	cout << "q是否大于w:" << (q > w) << endl;
	cout << "q是否小于w:" << (q < w) << endl;


	// 逻辑运算符 &&、||、!,结果是 bool  也可以用替代记号 : and、or、not
	int number_ = 10;
	int number__ = 20;
	int number___ = 30;

	cout << (number_ > number__ and number_ > number___) << endl;;
	cout << (number_ > number__ or number_ > number___) << endl;;
	cout << (not (number_ > number__)) << endl;;


	// 三目运算符 条件表达式 ? 表达式1 : 表达式2
	// 条件为真，结果是表达式1；条件为假，结果是表达式2。它是 if-else 的表达式版本，有返回值。
	int h = 5,j = 8;
	int max = (h > j) ? h : j;


	// 位运算符 位运算直接对整数的二进制位进行操作
	int r = 12;
	int u = 8;
	// 按位与&  a 和 b 的二进制中、处在同一位置的那两个比特都是1结果才是1
	int result = r & u;
	cout << result << endl;

	// 按位或| 有一位是1结果就是1
	int result_2 = r | u;
	cout << result_2 << endl;

	// 按位或^ 两位结果不同为1 相同为0
	int result_3  = r ^ u;
	cout << result_3 << endl;

	// 按位取反 ~ 0变1 1变0
	int result_4 = ~ r;
	cout << result_4 << endl;


	return 0;
}