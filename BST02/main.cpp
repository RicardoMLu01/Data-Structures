#include <iostream>
#include "../inc/heap_test.hpp"
#include <ctime>
#include <random>
#include <vector>

using namespace std;

int main() {

    BinaryHeap<int> heap1;
    vector<int> vec;
	default_random_engine e(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<int> u(0,100);

    cout << "测试插入数据：　" << endl;
    cout << "====原始数据为：　";
    for (int i = 0; i < 15;++i)
    {
        int tmp = u(e);
        cout << tmp << " ";
        heap1.insert(tmp);
        vec.push_back(tmp);
    }
	BinaryHeap<int> heap2(vec);
    cout << "此时有：　" << heap1.getSize() << "个元素，其中最小值为：　" << heap1.findMin() << endl;
    cout << "测试拷贝构造函数：　" << endl;
    BinaryHeap<int> heap3(heap1);

    cout << "==== 通过取最小值，获得从小到大的排序 =====" << endl;
    cout << "heap1:" << endl;
#if 1
	while (!heap1.isEmpty())
	{
		int tmp = 0;
		heap1.deleteMin(tmp);
		cout << tmp << " ";
	}
	cout << endl;
	cout << "heap2:" << endl;
	while (!heap2.isEmpty())
	{
		int tmp = 0;
		heap2.deleteMin(tmp);
		cout << tmp << " ";
	}
	cout << endl;
	cout << "heap3:" << endl;
	while (!heap3.isEmpty())
	{
		int tmp = 0;
		heap3.deleteMin(tmp);
		cout << tmp << " ";
	}
	cout << endl;

#endif
    return 0;
}
