#include <iostream>
#include <limits>
#include <string>
using namespace std;

// 文本输入

int main() {

	// cin 按空白分隔符读取
	// int n; double d; string s;
	// cin >> n >> d >> s;
	// cout << n << " " << d << " " << s << endl;
	/*
	自动根据变量类型解析，不用写 %d 之类的格式符
	读取时会自动跳过前导空白（空格、制表符、换行）
	读 string 时遇到空白就停止，所以 Hello World 只会读到 Hello
	读 string 不会越界，字符串会自动扩容
	 */

	// getline 读取一整行
	// string line;
	// getline(cin,line);  // 读到换行符为止，能读带空格的文本 后面还可以添加一个字符参数 用于指定分隔符
	// cout << line << endl;
	/*
	 * 换行符会被读走并丢弃，不会存进 line
	 * 返回流对象，可直接用于循环条件：
	 */

	// cin >> n 只读走数字，换行符留在缓冲区，下一个 getline 会直接读到一个空行
	// int n;string line;
	// cin >> n;
	// cin >> ws; // 跳过前导空白 可以解决这个问题
	// getline(cin,line);
	// cout << n << " " << line << endl;


	// 读取单个字符
	// char c; char d;
	// d = cin.get(); // 不跳过空白，空格和换行也会读到
	// cin >> c; // 跳过空白，读第一个非空白字符
	// cout << c << " " << d << endl;
	//
	// // cin.get()也能返回int 用来判断EOF
	// int ch;
	// while ((ch = cin.get()) != EOF) {
	// 	cout.put(ch); // 输出一个字符
	// }


	// 检查输入是否成功
	int n;
	while (!(cin >> n)) {
		cout << "输入有误" << endl;
		cin.clear(); // 清除错误标志
		cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 丢掉错误输入
	}
	cout << n << endl;;













	return 0;
}