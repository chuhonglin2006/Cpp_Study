#include <iostream>
#include <set>
#include <string>
using namespace std;

// multiset : 多重集合
// 允许重复:同一个值可以插入多次
// 自动排序:默认从小到大(底层同样是红黑树)
// 增删查都是 O(log n)

int main() {
    // 创建一个multiset
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    ms.insert(5);
    ms.insert(5); // 允许重复插入

    for (int x : ms) {
        cout << x << " ";
    }
    cout << endl;


    // 与set区别
    ms.clear(); // 清空
    // 1.insert永远成功
    auto it = ms.insert(3); // 返回迭代器
    ms.insert(3); // 再次插入 照样能成功

    // 2.count 能大于1
    ms.clear();
    ms.insert({1,1,1,1}); // 一次性插入多个
    cout << ms.count(1) << endl;

    // 3.find查找
    ms.clear();
    // find 返回的是其中一个匹配元素的迭代器(在 C++ 标准里不保证是哪一个,实际上通常是第一个,但不要依赖这一点)
    ms.insert({1,2,2,3});
    auto ite = ms.find(2);
    if (ite != ms.end()) {
        cout << *ite << endl;
    }

    // 4.删除
    ms.clear();
    ms.insert({1,2,2,2,3});
    ms.erase(2); // 按值删除 会删除所有值为2的元素
    for (int x : ms) {cout << x << " ";}
    cout << endl;
    // 只删除一个 传迭代器
    ms.erase(ms.find(1)); // 只删除一个


    // lower_bound / upper_bound / equal_range
    ms.clear();
    ms.insert({10,20,20,20,30});

    auto lo = ms.lower_bound(20); // 第一个 >= 20的元素
    auto up = ms.upper_bound(20); // 第一个 > 20的元素
    cout << distance(lo,up) << endl; // 获取两个区间内元素的数量

    // 一次性拿到第一个20到最后一个20的区间
    auto range = ms.equal_range(20); // 返回 pair<lower_bound, upper_bound>
    cout << *(range.first) << endl;
    cout << *(range.second) << endl; // second 是第一个 > 20的元素 所以为30


    // 自定义结构 自定义结构体时同样要重载 <,不过 multiset 不会因为"相等"而丢元素:
    struct Student {
        string name;
        int score;

        bool operator < (const Student& other) const {
            return score < other.score;
        }
    };

    multiset<Student> mstu;
    mstu.insert({"小明", 90});
    mstu.insert({"小红", 85});
    mstu.insert({"小刚", 90});   // 和小明分数相同,但仍然保留

    for (auto& st : mstu) {
        cout << st.name << ":" << st.score << endl;
    }

    // 元素不能修改 和 set 一样,元素是 const 的,要改就先删后插
    ms.clear();
    ms.insert({1, 2, 2, 3});
    ms.erase(ms.find(2)); // 删除一个2
    ms.insert(10); // 插入一个10

    // 获取最大值 最小值
    ms.clear();
    ms.insert({5,3,5,1});
    cout << *(ms.begin()) << endl; // 因为set会自动排序 所以能使用获取第一个元素与最后一个元素来获取
    cout << *(ms.rbegin()) << endl;

    return 0;
}
