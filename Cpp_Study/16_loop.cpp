#include <iostream>
using namespace std;

// 循环语句

int main() {

	// while循环 先判断 后执行
	int i = 1,sum = 0;
	while (i <= 100) {
		sum += i;
		i++;
	}
	cout << "1到100的和是:" << sum << endl;

	// for循环
	for (int index = 0;index < 5;index++) {
		cout << "第" << index << "次循环" << endl;
	}

	// do-while循环 先执行 后判断 至少执行一次
	int n;
	do {
		cout << "请输入一个大于10的数:"; cin >> n;
	} while (n <= 10);
	cout << "你输入的是:" << n << endl;


	// break:跳出当前层循环或 switch
	// continue:跳过本次循环剩余部分,进入下一次


	// 范围for循环  范围 for 更简洁,也避免了下标越界、i < n 写错等问题。
	int arr[] = {1,2,3,4,5};
	for (int x : arr) {
		cout << x << endl;
	}

	return 0;
}