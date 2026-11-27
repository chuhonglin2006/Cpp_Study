#include <iostream>
using namespace std;

// 变量的定义和使用

int main() {
	// 定义一个int类型的变量
	int number_1;
	// 给变量赋值
	// ReSharper disable once CppJoinDeclarationAndAssignment
	number_1 = 10;

	// 变量在定义时也能赋值
	// ReSharper disable once CppLocalVariableMayBeConst
	int number_2 = 20;

	// 变量有很多不同的类型 根据不同类型使用不同的关键字来定义


	// 使用定义的变量
	cout << "number_1的值是:" << number_1 << endl;
	cout << "number_2的值是:" << number_2 << endl;

	return 0;
}