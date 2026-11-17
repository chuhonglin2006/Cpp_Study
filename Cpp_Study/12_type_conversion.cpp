#include <iostream>
using namespace std;

// 类型转换

int main() {
	// 类型转换分为两大类 : 隐式转换、显式转换

	// 隐式转换 : 自动类型转换
	// 不同类型混合运算式 会向 更宽 的类型转换 大致顺序是:
	// int -> long -> long long -> float -> double -> long double
	int  a = 3;
	double b = 2.5;
	cout << a + b << endl; // a先被转换为double
	// 比int小的类型 char short bool 参与运算时 会先提升为 int 类型

	// 赋值时的转换 : 赋值时 右边的值会被转为左边变量类型
	int x = 3.9;
	cout << x << endl;
	bool f = 10; // 非 0 都是true
	cout << f << endl;

	// 由大类型到小类型的转换可能丢失数据这叫 : 窄化转换
	int big = 300;
	char c = big;
	cout << c << endl;

	// 有符号与无符号混合 : 有符号数会被转换为无符号数
	int q = -1;
	unsigned int v = 1;
	cout << (q < v) << endl; // 因为 -1 被转换未来一个很大的整数 以不要拿有符号数和无符号数直接比较



	// 显示转换 : 强制类型转换
	int p = 7,o = 2;
	double r = static_cast<double>(p) / o; // static_cast<类型>(转换的值)
	cout << r << endl;


	return 0;
}