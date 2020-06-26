#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "../inc/bst.hpp"

using namespace std;

int main(){

    BST tree;
    int nums[6] = {5, 3, 6, 8, 4, 2};
    for (int num : nums)
    {
        tree.addElem(num);
    }
    
    //BST 的各项功能都已测试过，若想测试其中某个功能，只需替换下面的函数
    tree.remove(6);
    tree.levelorder();
    cout << endl;

    return 0;
}
