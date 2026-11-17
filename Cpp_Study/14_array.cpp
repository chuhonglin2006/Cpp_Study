#include <iostream>
using namespace std;

// 数组


int main() {
	// 数组是一组相同类型 连续存放的变量 通过下标访问

	// 数组的定义与初始化
	int a[5]; // 定义一个长度为5的数组 未初始化 元素值是随机的
	int b[5] = {1,2,3,4,5}; // 完全初始化
	int c[5] = {1,2}; // 剩余补 0
	int d[5] = {}; // 全部为0
	int e[] = {1,2,3}; // 自动推导长度



	// 访问元素 : 下标从0开始 长度为n的数组 合法下标为 0 ~ n-1
	cout << b[0] << endl;
	cout << b[1] << endl;
	b[0] = 0; // 修改数组中的值
	cout << b[0] << endl;

	cout << b[5] << endl; // 越界 可能造成程序崩溃或者其他不可预测的结果


	// 计算数组长度
	int length = size(b);
	int len = sizeof(b) / sizeof(b[0]);
	cout << "数组b长度为:" << len << endl;
	cout << "数组b长度为:" << length << endl;


	// 二维数组
	int m[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << m[1][1] << endl; // 二维数组的访问


	// 字符数组 C语言风格
	char s1[] = "Hello";
	cout << s1 << endl; // 末尾会自动加上 \0 实际长度为6


	return 0;
}