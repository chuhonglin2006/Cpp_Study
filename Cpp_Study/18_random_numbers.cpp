#include <iostream>
#include <random>
using namespace std;


// 随机数



int main() {

	random_device rd; // 真随机种子来源
	mt19937 gen(rd()); // 梅森旋转算法引擎


	uniform_int_distribution a(1, 1000); // 生成1~1000内的随机数
	cout << a(gen) << endl;


	uniform_real_distribution b(0.0,1.0); // 生成范围内的浮点数
	cout << b(gen) << endl;


	return 0;
}