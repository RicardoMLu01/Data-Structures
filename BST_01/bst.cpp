/**
 * @file bst.cpp
 * @brief  BST 类的定义
 * @author 年少无妨
 * @version v1
 * @date 2020-06-21
 */

#include "iostream"
#include "../inc/bst.hpp"
#include <stack>
#include <queue>
#include <vector>


BST::BST()
{
    root = NULL;
    size = 0;
}

BST::~BST()
{

}

int BST::getSize()
{
    return size;
}

bool BST::isEmpty()
{
    return size == 0;
}

void BST::addElem(Element e)
{
    root = addElem(root, e);
}

TreeNode* BST::addElem(TreeNode* node,Element e)
{
    if(node==NULL)
    {
        TreeNode *ptr = new TreeNode(e);
        size++;
        return ptr;
    }
           
    if (e < node->val)
        node->left = addElem(node->left, e);
    else if(e > node->val)
        node->right = addElem(node->right, e);

    return node;
}

bool BST::searchElem(Element e)
{
    return searchElem(root, e);
}

bool BST::searchElem(TreeNode *node, Element e)
{
    if(node==NULL)
        return false;
    if(node->val<e)
        return searchElem(node->left, e);
    else
        return searchElem(node->right, e);
}

void BST::preorder()
{
    preorder(root);
}

void BST::preorder(TreeNode *node)
{
    if(node==NULL)
        return;
    std::cout << node->val << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::inorder()
{
    inorder(root);
}

void BST::inorder(TreeNode *node)
{
    if(node==NULL)
        return;
    inorder(node->left);
    std::cout << node->val << " ";
    inorder(node->right);
}

void BST::postorder()
{
    postorder(root);
}

void BST::postorder(TreeNode *node)
{
    if(node==NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->val << " ";
}

void BST::preorderNR()
{
    preorderNR(root);
}

//前序遍历非递归实现
void BST::preorderNR(TreeNode *node)
{
    if(node==NULL)
        return;
    std::stack<TreeNode *> st;
    TreeNode *p = node;
    while (!st.empty() || p)
    {
        while(p)
        {
            std::cout << p->val << " ";
            st.push(p->right);
            p = p->left;
        }
        p = st.top();
        st.pop();
    }
}

void BST::inorderNR()
{
    inorderNR(root);
}

//中序遍历非递归实现
void BST::inorderNR(TreeNode *node)
{
    if(node==NULL)
        return;
    std::stack<TreeNode *> st;
    TreeNode *p = node;
    while(!st.empty() || p)
    {
        while(p)
        {
            st.push(p);
            p = p->left;
        }
        p = st.top();
        std::cout << p->val << " ";
        st.pop();        
        p = p->right;
    }
}

void BST::postorderNR()
{
    postorderNR(root);
}

//后序遍历非递归实现
void BST::postorderNR(TreeNode *node)
{
    if(node==NULL)
        return;
    std::stack<TreeNode *> st;
    std::vector<Element> vec;
    TreeNode *p = node;
    while (!st.empty() || p)
    {
        while(p)
        {
            vec.push_back(p->val);
            st.push(p->left);
            p = p->right;
        }
        p = st.top();
        st.pop();
    }
    reverse(vec.begin(), vec.end());
    for(auto num : vec)
    {
        std::cout << num << " ";
    }
}

int BST::getDepth(TreeNode *root)
{
    if(root==NULL)
        return 0;
    int ld = getDepth(root->left);
    int rd = getDepth(root->right);

    return ld > rd ? (ld + 1) : (rd + 1);
}

void BST::levelorder()
{
    levelorder(root);
}

void BST::levelorder(TreeNode *node)
{
    if(node==NULL)
        return;
    std::queue<TreeNode *> que;
    TreeNode *p = node;
    que.push(p);
    while(!que.empty())
    {
        int num = que.size();
        while(num--)
        {
            TreeNode *cur = que.front();
            que.pop();
            if(!cur)
                continue;
            std::cout << cur->val << " ";
            if(cur->left)
                que.push(cur->left);
            if(cur->right)
                que.push(cur->right);
        }
    }
}

TreeNode* BST::minimum(TreeNode *node)
{
    if(node->left==NULL)
        return node;
    return minimum(node->left);
}


Element BST::minimum()
{
    assert(size > 0);
    return minimum(root)->val;
}

TreeNode* BST::maximum(TreeNode *node)
{
    if(node->right==NULL)
        return node;
    return maximum(node->right);
}


Element BST::maximum()
{
    assert(size > 0);
    return maximum(root)->val;
}


TreeNode* BST::removeMin(TreeNode *node)
{
    if(node->left==NULL)
    {
        TreeNode *rightNode = node->right;
        delete node;
        size--;
        return rightNode;
    }
    node->left = removeMin(node->left);
    return node;
}

Element BST::removeMin()
{
    Element ret = minimum();
    root = removeMin(root);
    return ret;
}

TreeNode* BST::removeMax(TreeNode *node)
{
    if(node->right==NULL)
    {
        TreeNode *leftNode = node->left;
        delete node;
        size--;
        return leftNode;
    }
    node->right = removeMax(node->right);
    return node;
}


Element BST::removeMax()
{
    Element ret = maximum();
    root = removeMax(root);
    return ret;
}

//移除 BST 任一节点
TreeNode* BST::remove(TreeNode *node, Element e)
{
    if(node==NULL)
        return NULL;
    
    if(node->val>e)
    {
        node->left = remove(node->left, e);
        return node;
    }
    else if(node->val<e)
    {
        node->right = remove(node->right, e);
        return node;
    }
    else
    {
        if(node->left==NULL)
        {
            TreeNode *rightNode = node->right;
            delete node;
            size--;
            return rightNode;
        }

        if(node->right==NULL)
        {
            TreeNode *leftNode = node->left;
            delete node;
            size--;
            return leftNode;
        }

        TreeNode *successor = minimum(node->right);
        successor->right = removeMin(node->right);
        successor->left = node->left;
        node->left = node->right = NULL;
        delete node;
        return successor;
    }
}


void BST::remove(Element e)
{
    root = remove(root, e);
}



