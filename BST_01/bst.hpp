/**
 * @file bst.hpp
 * @brief 声明 BST 的类
 * @author 年少无妨
 * @version v1
 * @date 2020-06-21
 */

#ifndef __BST__
#define __BST__

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>


typedef int Element;
struct TreeNode
{
    Element val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};


class BST
{
public:

    BST();
    ~BST();
    int getSize();
    bool isEmpty();

    void addElem(Element e);
    TreeNode *addElem(TreeNode *node, Element e);

    bool searchElem(Element e);
    bool searchElem(TreeNode *node, Element e);

    void preorder();
    void inorder();
    void postorder();
    void preorder(TreeNode *node);
    void inorder(TreeNode *node);  
    void postorder(TreeNode *node);

    void preorderNR();
    void inorderNR();
    void postorderNR();
    void preorderNR(TreeNode *node);
    void inorderNR(TreeNode *node);
    void postorderNR(TreeNode *node);

    int getDepth(TreeNode *root);
    void levelorder();
    void levelorder(TreeNode *node);

    Element minimum();
    TreeNode *minimum(TreeNode *node);
    Element maximum();
    TreeNode *maximum(TreeNode *node);
    Element removeMin();
    TreeNode *removeMin(TreeNode *node);
    Element removeMax();
    TreeNode *removeMax(TreeNode *node);
    void remove(Element e);
    TreeNode *remove(TreeNode *node, Element e);


private:
    TreeNode *root;
    int size;
};
#endif
