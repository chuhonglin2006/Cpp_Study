#include <iostream>
using namespace std;

// 第二章练习

// 1.编写一个小程序，要求用户使用一个整数指出自己的身高(cm)转化为m
void cm_to_m() {
	const int conversion_factor = 100;
	double height;
	cout << "请输入身高(cm):";
	cin >> height;
	double height_m = height / conversion_factor;
	cout << "你的身高为:" << height_m << "m" << endl;
}

// 2.BMI计算
void bmi() {
	double weight;
	double height;
	cout << "请输入身高(cm):";
	cin >> height;
	cout << "请输入体重(kg):";
	cin >> weight;
	double result = weight / (height * height / 10000);
	cout << "你的BMI是:" << result << endl;
}

// 3.编写一个程序 输入时分秒 然后输出一共有多少小时
void timeToHours() {
	double hours;
	double minutes;
	double seconds;
	cout << "请输入时:"; cin >> hours;
	cout << "请输入分:"; cin >> minutes;
	cout << "请输入秒:"; cin >> seconds;
	double result = hours + minutes / 60.0 + seconds / 3600.0;
	cout << "结果是:" << result << "小时" << endl;
}

// 4.编写一个程序 输入国家人口数量和全球人口数量 输出国家人口数量占全球人口的百分比
void func() {
	long long country_people_number;
	long long global_people_number;
	cout << "请输入国家人口数量:"; cin >> country_people_number;
	cout << "请输入全球人口数量:"; cin >> global_people_number;
	double result = static_cast<double>(country_people_number) / global_people_number * 100;
	cout << "人口占比:" << result << "%" << endl;
}


int main() {
	cm_to_m();
	bmi();
	timeToHours();
	func();

	return 0;
}