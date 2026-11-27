#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

// set : 集合
// 元素唯一:重复插入会被忽略
// 自动排序:默认从小到大(底层是红黑树)
// 增删查都是 O(log n)

int main() {
    // 创建一个set
    set<int>s;
    s.insert(1); // 插入元素
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(1); // 重复插入 会被忽略

    // 遍历set
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;


    // 常用操作
    set<int>s_2 = {4,2,1,5,7}; // 初始化 会按照从大到小排序
    s_2.insert(9); // 插入
    s_2.erase(2); // 按值删除
    cout << s_2.count(4) << endl; // 判断是否存在
    cout << s_2.empty() << endl; // 判断是否为空
    cout << s_2.size() << endl; // 获取元素个数
    s_2.clear(); // 清空




    set<int>s_3 = {1,3,5,7};

    // 查找元素
    auto it = s_3.find(5);
    if (it != s_3.end()) {
        cout << *it << endl;
    } else {
        cout << "未找到" << endl;
    }

    // 判断是否插入成功
    auto result = s_3.insert(2);
    if (result.second) { // insert 返回一个 pair<迭代器, bool> second就是哪个bool值
        cout << "插入成功" << endl;
    } else {
        cout << "已存在 插入失败" << endl;
    }


    // ower_bound / upper_bound(set 的强项) 因为元素有序 可以快速找 边界
    set<int>s_4 = {10,20,30,40,50};
    auto a = s_4.lower_bound((25)); // 查找第一个 >= 25的元素
    auto b = s_4.upper_bound(30); // 查找第一个 > 30 的元素
    cout << *a << " " << *b << endl;


    // 自定义排序
    // 从小到大
    set<int>ss = {3,1,6,7,4,2,8};
    for (int x : ss) cout << x << " "; // 默认从小到大

    cout << endl;

    // 从大到小
    set<int,greater<>>sss = {3,1,6,7,4,2,8};
    for (int x : sss) cout << x << " ";
    cout << endl;


    // 自定义数据
    struct Student {
        string name;
        int score;

        // set 需要知道怎么比较元素,所以要重载 < 或写比较器
        bool operator < (const Student& other) const  {
            if (score != other.score) {
                return score < other.score; // 比较规则
            }
            return name < other.name;
        }
    };
    set<Student> students;
    students.insert({"小明",90});
    students.insert({"小红",95});
    students.insert({"小刚",90});
    // 遍历这个set
    for (const Student& s1 : students) {
        cout << s1.name << ":" << s1.score << endl;
    }

    // set中的元素不能修改
    set<int>ssss = {1,2,3};
    // *ssss.begin() = 10; // 编译错误

    // 正确做法 先删除 后插入
    ssss.erase(1);
    ssss.insert(10);

    for (int i : ssss) {
        cout << i << " ";
    }

    cout << endl;

    // 与vector结合 一行去重 + 排序
    vector<int> v = {5, 3, 5, 1, 3, 2, 1};
    set<int> sv(v.begin(), v.end());
    for (int x : sv) cout << x << " ";
    
    return 0;
}