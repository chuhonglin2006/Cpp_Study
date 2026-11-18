#include <iostream>
#include <string>
using namespace std;

// 枚举


// 输出枚举
enum class Numbers {zero,one,two};
string toStr(Numbers b) {
	switch (b) {
		case Numbers::zero:
			return "0";
		case Numbers::one:
			return "1";
		case Numbers::two:
			return "2";
	}
	return "Unknown";
}


int main() {

	// 传统枚举
	enum Color {red,green,blue}; // 0,1,2
	Color c = red;
	cout << c << endl; // 隐身转换为 int

	// enum Light {red,yellow}; // 编译错误 red重名 名字泄露到外层作用域


	// 增强型枚举 推荐
	enum class Number_1 {zero,one,two};
	enum class Number_2 {zero,one,two,three}; // 不冲突 成员名不会污染外层，也就不会重名

	Number_1 a = Number_1::one; // 访问必须带作用域
	int n = static_cast<int>(a); // 不能隐式转换
	cout << n << endl;


	cout << toStr(Numbers::two) << endl; // 输出枚举

	return 0;
}