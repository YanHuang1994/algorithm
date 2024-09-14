#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val);
};

class BinaryTree {
private:
    void destroyTree(TreeNode* node);
    TreeNode* root;
    TreeNode* copyTree(const TreeNode* node);
    void preorder(TreeNode* node, vector<int>& ret);
    vector<int> preorderIterative(TreeNode* node);
    void inorder(TreeNode* node, vector<int>& ret);
    vector<int> inorderIterative(TreeNode* node);
    void postorder(TreeNode* node, vector<int>& ret);
    vector<int> postorderIterative(TreeNode* node);
    vector<int> levelOrder(TreeNode* node) const;

    void dfsPaths(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& paths);

    int depth(TreeNode* root);

public:
    BinaryTree();
    BinaryTree(const BinaryTree& other);
    virtual ~BinaryTree();
    virtual void insert(int value);
    bool find(int value);
    virtual void update(int oldVal, int newVal);
    void displayPreorder();
    void displayPreorderIterative();
    void displayInorder();
    void displayInorderIterative();
    void displayPostorder();
    void displayPostorderIterative();
    void displayLevelOrder();
    TreeNode* getRoot();

    void displayPathSum(int targetSum);
    //Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum.
    vector<vector<int>> pathSum(TreeNode* root, int targetSum);
    bool isSameTree(TreeNode* p, TreeNode* q);
    int maxDepth(TreeNode* root);
    int minDepth(TreeNode* root);
    bool isBalanced(TreeNode* root);

protected:
    void setRootNode(TreeNode* node) { root = node; }
};
