#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

// 数据类型


int main() {
	// C++中数据基本类型分为: 整型、字符型、布尔型、浮点型


	// 整型
	short s = 100; // 短整型
	int i = 10000; // 整型 最常用
	long l = 100000L; // 长整型
	long long ll = 1000000000; // 长长整型
	unsigned int u = 400000000U; // 无符号整型
	cout << sizeof(short) << " " << sizeof(int) << " "
	 << sizeof(long) << " " << sizeof(long long) << endl;
	// sizeof(long) 在 Windows 下是 4，在 Linux/macOS 64 位下是 8


	// 字符型
	char c1 = 'A'; // char使用单引号包围
	char c2 = 65; // ASCII码表对应的整数 也是 A
	cout << c1 << endl;
	cout << c2 << endl;
	cout << static_cast<int>(c1) << endl;
	// 常用转义字符
	// '\n' 换行  '\t' 制表  '\\' 反斜杠  '\'' 单引号  '\"' 双引号  '\0' 空字符

	// 字符与整数可以互相运算
	char ch = 'a';
	ch = ch - 32; // 转换为 A
	cout << ch << endl;
	int digit = '7' - '0';
	cout << digit << endl; // 将字符数组转为整数


	// 布尔型
	bool b1 = true;
	bool b2 = false;
	// bool 类型只有两个值
	cout << b1 << endl; // 1为真
	cout << b2 << endl; // 0为假


	// 浮点型
	float f = 3.14f;
	double d = 3.1415; // 最常用浮点型
	long double ld = 3.14L; // 长小数型
	double e = 1.5e3; // 科学计数法
	// 浮点数的精度有限 不能直接比较
	double a = 0.1 + 0.2;
	cout << (a == 0.3) << endl;

	// 浮点数的精度控制
	double pi = 3.14159265;
	cout << setprecision(3) << pi << endl; // 保留3位有效数字 四舍五入
	cout << setprecision(2) << 1234.5678 << endl; // 位数不够时改用科学计数
	cout << setprecision(10) << 1.5 << endl; // 末尾的 0 不补

	cout << fixed << pi << endl; // 让浮点数以定点小数形式输出,不使用科学计数法 默认保留 6 位小数

	cout << fixed << setprecision(2) << pi << endl; // fixed + setprecision(n) 结果会四舍五入,位数不够会补0


	// 内置类型 String
	string str = "Hello";
	str += " C++"; // 可以对string后面追加内容
	cout << str << endl;
	cout << str.length() << endl; // 获取string长度
	cout << str.size() << endl; // 获取string长度

	return 0;
}