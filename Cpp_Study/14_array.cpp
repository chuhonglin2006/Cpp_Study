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


	cout << "数组首地址:" << b << endl; // 数组首地址



	// 访问元素 : 下标从0开始 长度为n的数组 合法下标为 0 ~ n-1
	cout << b[0] << endl;
	cout << b[1] << endl;
	b[0] = 0; // 修改数组中的值
	cout << b[0] << endl;

	cout << b[5] << endl; // 越界 可能造成程序崩溃或者其他不可预测的结果


	// 计算数组长度与占用大小
	size_t size = sizeof(b);
	int len = sizeof(b) / sizeof(b[0]);
	cout << "数组b长度为:" << len << endl;
	cout << "数组b占用大小为:" << size << endl;


	// 二维数组
	int m[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	cout << m[1][1] << endl; // 二维数组的访问



	// 遍历数组
	int arr[] = {1,2,3,4,5};

	cout << "while循环遍历数组" << endl;

	// while循环
	int arr_length = sizeof(arr) / sizeof(arr[0]);
	int index = 0;

	while (index < arr_length) {
		cout << arr[index] << endl;
		index++;
	}

	cout << "for循环遍历数组" << endl;

	// for 循环
	for (int i = 0;i < arr_length;i++) {
		cout << arr[i] << endl;
	}


	cout << "遍历二维数组" << endl;


	// 遍历二维数组
	int arr_plus[2][5] = {
		{1,2,3,4,5},
		{6,7,8,9,0}
	};
	int out = sizeof(arr_plus) / sizeof(arr_plus[0]);
	int inside = sizeof(arr_plus[0]) / sizeof(arr_plus[0][0]);

	for (int p = 0;p < out;p++) {
		for (int n = 0;n < inside;n++) {
			cout << arr_plus[p][n] << endl;
		}
	}


















	return 0;
}