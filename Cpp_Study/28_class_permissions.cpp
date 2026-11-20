#include <iostream>
using namespace std;



// 类的权限控制


class Account {
public: // 公有 : 全部都可以访问
	void withdraw_money(double number) {
		if (number <= 0) {
			cout << "请输入正确的金额" << endl;
		} else if (number > money) {
			cout << "余额不足" << endl;
		} else {
			money -= number;
			cout << "余额:" << money << endl;
		}
	}

private: // 私有 : 只有类内部能访问
	double money = 100;

};

/* 三种访问权限:
	关键字	  类内部	派生类 类外部
	public	    ✅	 ✅	   ✅
	protected	✅	 ✅	   ❌
	private		✅ 	 ❌	   ❌
 */
// class 默认 private struct 默认 public 这是二者唯一区别



int main() {
	Account a;
	a.withdraw_money(10);
	a.withdraw_money(90);
	return 0;
}






















