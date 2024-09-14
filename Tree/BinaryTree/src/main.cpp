#include "../include/BinaryTree.h"
#include "../include/BinarySearchTree.h"
#include <iostream>

using namespace std;

BinaryTree createCopy(const BinaryTree &original) {
    return BinaryTree(original); // Assuming the BinaryTree class has a copy constructor
}

void displayOrders(const BinaryTree &tree) {
    BinaryTree copy = createCopy(tree);

    cout << "Preorder: ";
    copy.displayPreorder();

    cout << "Preorder Interative: ";
    copy.displayPreorderIterative();

    cout << "Inorder: ";
    copy.displayInorder();

    cout << "Inorder Interative: ";
    copy.displayInorderIterative();

    cout << "Postorder: ";
    copy.displayPostorder();

    cout << "Postorder Interative: ";
    copy.displayPostorderIterative();
}

void displayLevelOrder(const BinaryTree &tree) {
    BinaryTree copy = createCopy(tree);
    cout << "LevelOrder: ";
    copy.displayLevelOrder();
    cout << endl;
}

void findData(const BinaryTree &tree, int value) {
    BinaryTree copy = createCopy(tree);
    cout << "Find " << value << ": " << (copy.find(value) ? "Found" : "Not Found") << endl;
}

void updateData(const BinaryTree &tree, int oldVal, int newVal) {
    BinaryTree copy = createCopy(tree);
    copy.update(oldVal, newVal);
    cout << "After update " << oldVal << " to " << newVal << ", LevelOrder: ";
    copy.displayLevelOrder();
    cout << endl;
}

void displayPathSum(const BinaryTree &tree, int targetSum) {
    BinaryTree copy = createCopy(tree);
    cout << "Paths sum: ";
    copy.displayPathSum(targetSum);
    cout << endl;
}

void testBinaryTree() {
    cout << "======= Testing BinaryTree =======\n";
    BinaryTree tree;

    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(1);

    displayOrders(tree);
    displayLevelOrder(tree);
    findData(tree, 4);
    findData(tree, 8);
    updateData(tree, 4, 40);
    displayLevelOrder(tree);
    displayPathSum(tree, 8);
}

void testBinarySearchTree() {
    cout << "======= Testing BinarySearchTree =======\n";
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    displayOrders(bst);
    displayLevelOrder(bst);
    findData(bst, 40);
    findData(bst, 10);
    updateData(bst, 40, 45);
    displayLevelOrder(bst);
    displayPathSum(bst, 100);
}

int main() {
    testBinaryTree();
    testBinarySearchTree();
    return 0;
}
