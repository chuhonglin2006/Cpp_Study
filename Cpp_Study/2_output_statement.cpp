#include <iostream>
using namespace std;
#include <iomanip>

// 输出语句

int main() {
	// 在C++中 使用cout来进行输出

	cout << "Hello" << endl; // endl是一个控制符 表示换行
	cout << "World\n"; // \n是换行符 也能换行

	// cout也能一次性输出多个值 中间使用<<连接
	cout << "Hello" << "World" << endl;


	// 设置下一个输出项的最小宽度为 n,不足时用空格补齐,默认右对齐。
	cout << setw(8) << 123 << endl; // 前面 5 个空格
	cout << setw(8) << "abc" << endl;
	cout << setw(2) << 123 << endl; // 超出宽度不会截断

	cout << left << setw(8) << "abc" << endl; // 左对齐
	cout << right << setw(8) << "abc" << endl; // 右对齐


	// 自定义填充字符
	cout << left << setfill('*') << setw(8) << "abc" << endl;

	return 0;
}