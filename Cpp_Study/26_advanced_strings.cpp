#include <iostream>
#include <string>
#include <limits>
using namespace std;


// 字符串进阶  字符串定义 输入输出 拼接 查找 替换 删除 截取 遍历和常见字符串处理


int main() {

	// 定义字符串
	string str_1 = "Hello";
	string str_2; // 空字符串

	str_1 = "C++"; // 可以直接通过赋值修改
	cout << str_1 << endl;

	// 获取字符串长度
	cout << str_1.length() << endl;
	cout << str_1.size() << endl;
	// 这里的长度是字符串中存储的char数量对于UTF-8中文字符串一个汉字通常占3个字节因此不一定等于汉字个数
	string str_cn = "你好";
	cout << str_cn.length() << endl;

	// 判断字符串是否为空
	if (str_2.empty()) {  //  empty() 返回值是 bool 类型
		cout << "字符串为空" << endl;
	}

	// 清空字符串
	str_1.clear();
	if (str_1.empty()) {
		cout << "字符串已清空" << endl;
	}

	// 字符串的输入
	// string str_in;
	// cout << "请输入字符串:"; getline(cin,str_in); // cin >> 遇到空格 制表符或换行符就会停止读取
	// cout << str_in << endl;
	// // 如果前面使用了 cin 后面又使用 getline 可能会出现getline读取到换行符的问题、
	// int age; string name;
	// cout << "请输入age:"; cin >> age;
	// cout << "请输入name:";
	// cin.ignore(numeric_limits<streamsize>::max(),'\n'); // 清除输入缓冲区中剩余的内容直到换行符
	// getline(cin,name);
	// cout << name << ":" << age << endl;

	// 字符串的拼接
	// 使用 +
	string str_a = "Hello",str_b = "C++";
	string result = str_a + " " + str_b;
	cout << result << endl;
	// 使用 +=  会修改原字符串
	str_a += " * ";
	str_a += "World";
	cout << str_a << endl;
	// 使用 append 会修改原字符串
	str_b.append(" is best language");
	cout << str_b << endl;

	// 字符串访问与修改
	string str_3 = "Hello";

	// 通过下标访问
	cout << str_3[0] << str_3[1] << str_3[2] << str_3[3] << endl;
	// 使用at访问
	cout << str_3.at(0) << str_3.at(1) << str_3.at(2) << str_3.at(3) << endl;

	// 修改指定位置的字符
	str_3[0] = 'N'; // 因为修改的为字符 所以要使用单引号
	cout << str_3 << endl;

	// 获取开头和末尾的字符
	cout << str_3.front() << endl;
	cout << str_3.back() << endl;

	// 字符查找
	cout << str_3.find('l') << endl; // 返回从左到右第一个下标
	// 查找不存在的内容
	size_t pos = str_3.find("C++");
	if (pos == string::npos) { // string::npos 表示没有找到
		cout << "未找到" << endl;
	}

	// 字符串截取
	string str_4 = "Hello World";

	string result_4 = str_4.substr(0,5); // 下标从0开始 到5结束 不指定第二个参数 就从起始位置截取到末尾
	cout << result_4 << endl;

	// 字符串的删除
	str_4.erase(0,6); // 下标从0开始 到5 全部删除
	cout << str_4 << endl;

	// 字符串插入
	str_4.insert(5," C++"); // 从指定位置插入
	cout << str_4 << endl;

	// 字符串替换
	str_4.replace(6,3,"Python");// 起始位置 替换长度 替换内容
	cout << str_4 << endl;





	return 0;
}