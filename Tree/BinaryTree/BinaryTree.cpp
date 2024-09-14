#include "BinaryTree.h"
using namespace std;

TreeNode::TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(const BinaryTree& other) {
    root = copyTree(other.root);
}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

TreeNode* BinaryTree::copyTree(const TreeNode* node) {
    if (!node) return nullptr;

    TreeNode* newNode = new TreeNode(node->value);
    newNode->left = copyTree(node->left);
    newNode->right = copyTree(node->right);

    return newNode;
}

void BinaryTree::insert(int value) {
    if (!root) {
        root = new TreeNode(value);
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if (!current->left) {
            current->left = new TreeNode(value);
            break;
        } else {
            q.push(current->left);
        }

        if (!current->right) {
            current->right = new TreeNode(value);
            break;
        } else {
            q.push(current->right);
        }
    }
}

bool BinaryTree::find(int value) {
    if (!root) return false;
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current->value == value) return true;
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }

    return false;
}

void BinaryTree::update(int oldVal, int newVal) {
    if (!root) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current->value == oldVal) {
            current->value = newVal;
            return;
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void BinaryTree::preorder(TreeNode* node, vector<int>& ret) {
    if (!node) return;
    ret.push_back(node->value);
    preorder(node->left, ret);
    preorder(node->right, ret);
    return;
}

vector<int> BinaryTree::preorderIterative(TreeNode* root) {
    vector<int> ret;
    if (!root) return ret;
    stack<TreeNode* > s;
    TreeNode* cur = root;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            ret.push_back(cur->value);
            cur = cur->left;
        }
        TreeNode* top = s.top();
        s.pop();
        cur = top->right;
    }

    return ret;
}

void BinaryTree::inorder(TreeNode* node, vector<int>& ret) {
    if (!node) return;
    inorder(node->left, ret);
    ret.push_back(node->value);
    inorder(node->right, ret);
    return;
}

vector<int> BinaryTree::inorderIterative(TreeNode* node) {
    vector<int> ret;
    if (node == NULL)
        return ret;
    stack<TreeNode *> s;
    TreeNode *cur = node;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        TreeNode *top = s.top();
        s.pop();
        ret.push_back(top->value);
        cur = top->right;
    }
    return ret;
}

void BinaryTree::postorder(TreeNode* node, vector<int>& ret) {
    if (!node) return;
    postorder(node->left, ret);
    postorder(node->right, ret);
    ret.push_back(node->value);
    return;
}

vector<int> BinaryTree::postorderIterative(TreeNode* root) {
    vector<int> ret;
    if (!root) return ret;
    TreeNode* cur = root, *last = nullptr;
    stack<TreeNode* > s;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        TreeNode* top = s.top();
        if (!top->right || top->right == last) {
            ret.push_back(top->value);
            s.pop();
            last = top;
        }
        else cur = top->right;
    }
    return ret;
}

vector<int> BinaryTree::levelOrder(TreeNode* node) const {
    vector<int> ret;
    if (!node) return ret;

    std::queue<TreeNode*> q;
    q.push(node);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        ret.push_back(current->value);
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    return ret;
}

TreeNode* BinaryTree::getRoot() {
    return root;
}

void BinaryTree::displayPreorder() {
    vector<int> ret;
    preorder(root, ret);
    for(int val : ret) {
        cout << val << " ";
    }
    cout << endl;
}

void BinaryTree::displayPreorderIterative() {
    vector<int> ret = preorderIterative(root);
    for(int val : ret) {
        cout << val << " ";
    }
    cout << endl;
}

void BinaryTree::displayInorder() {
    vector<int> ret;
    inorder(root, ret);
    for(int val : ret) {
        cout << val << " ";
    }
    cout << endl;
}

void BinaryTree::displayInorderIterative() {
    vector<int> ret = inorderIterative(root);
    for(int val : ret) {
        cout << val << " ";
    }
    cout << endl;
}

void BinaryTree::displayPostorder() {
    vector<int> ret;
    postorder(root, ret);
    for(int val : ret) {
        cout << val << " ";
    }
    cout << endl;
}

void BinaryTree::displayPostorderIterative() {
    vector<int> ret = postorderIterative(root);
    for(int val : ret) {
        cout << val << " ";
    }
    cout << endl;
}

void BinaryTree::displayLevelOrder() {
    vector<int> ret = levelOrder(root);
    for(int val : ret) {
        cout << val << " ";
    }
    cout << endl;
}

void BinaryTree::displayPathSum(int targetSum) {
    vector<vector<int> > paths = pathSum(root, targetSum);

    for (size_t i = 0; i < paths.size(); ++i) {
        cout << "[ ";
        for (size_t j = 0; j < paths[i].size(); ++j) {
            std::cout << paths[i][j];
            if (j != paths[i].size() - 1) std::cout << ", ";
        }
        cout << " ]";
        if (i != paths.size() - 1) std::cout << ", ";
    }
    cout << " ]\n";
    cout << endl;
}

vector<vector<int>> BinaryTree::pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> paths;
    vector<int> path;
    if (!root) return paths;
    dfsPaths(root, targetSum, path, paths);

    return paths;
}

void BinaryTree::dfsPaths(TreeNode* node, int targetSum, vector<int>& path, vector<vector<int>>& paths) {
    if (!node) return;
    path.push_back(node->value);
    if (!node->left && !node->right && targetSum == node->value) {
        paths.push_back(path);
    }
    dfsPaths(node->left, targetSum - node->value, path, paths);
    dfsPaths(node->right, targetSum - node->value, path, paths);
    path.pop_back();
}

bool BinaryTree::isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (p && q && p->value == q->value) return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return false;
}

int BinaryTree::maxDepth(TreeNode* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return max(l+1, r+1);
}

int BinaryTree::minDepth(TreeNode* root) {
    if(!root) return 0;
    int l = minDepth(root->left), r = minDepth(root->right);
    return (min(l, r) ? min(l, r) : max(l, r)) + 1;
}

bool BinaryTree::isBalanced(TreeNode* root) {
    if (!root) return true;
    int left = depth(root->left);
    int right = depth(root->right);

    return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int BinaryTree::depth(TreeNode* root) {
    if (!root) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
}