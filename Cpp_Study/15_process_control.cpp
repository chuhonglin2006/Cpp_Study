#include <iostream>
using namespace std;

// 流程控制语句

int main() {

	// 选择语句 if、else if、else
	int score;
	cout << "请输入成绩:"; cin >> score;
	if (score >= 90) {
		cout << "优秀" << endl;
	} else if (score >= 60) {
		cout << "及格" << endl;
	} else {
		cout << "不及格" << endl;
	}


	// switch case 语句 适合对整型/字符/枚举做多分支等值判断
	int day;
	cout << "请输入周几:"; cin >> day;
	switch (day) {
		case 1:
			cout << "周一" << endl;
			break; // 每次case完了要break 避免穿透
		case 2:
			cout << "周二" << endl;
			break;
		case 3:
			cout << "周三" << endl;
			break;
		case 4:
			cout << "周四" << endl;
			break;
		case 5:
			cout << "周五" << endl;
			break;
		case 6:
			cout << "周六" << endl;
			break;
		case 7:
			cout << "周日" << endl;
			break;
		default:
			cout << "错误的日期" << endl;
			break;
	}
	// case 后必须是整型常量表达式,不能是 double、string 或变量
	// 忘写 break 会 穿透,继续执行下一个 case
	// default 可选,处理没有匹配的情况
	// case 中如果要定义变量,需要加花括号


	// go to语句 : 与条件跳转代码
	// go to 标记 : 执行到goto 时直接跳到标记

	cout << "1" << endl;
	cout << "2" << endl;

	goto FLAG; // 直接跳转到标记

	cout << "3" << endl;
	cout << "4" << endl;

	FLAG:

	cout << "5" << endl;


	return 0;
}