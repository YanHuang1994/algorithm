#include "LinkedList.h"
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

LinkedList createCopy(const LinkedList &original) {
    LinkedList copy;
    ListNode *current = original.getHead();
    while (current != nullptr) {
        copy.append(current->data);
        current = current->next;
    }
    return copy;
}

void benchmarkAppend(LinkedList &list, int numElements) {
    cout << "Starting append benchmark for " << numElements << " elements..." << endl;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        int value = rand() % 100;
        cout << "Appending value: " << value << endl;
        list.append(value);  // Appending random data
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to append " << numElements << " elements: " << duration.count() << " ms" << endl;
    cout << "Append operation completed." << endl;

    // 打印原始链表内容
    cout << "Original Linked List after appending " << numElements << " elements:" << endl;
    list.display();
}

void benchmarkRemove(LinkedList &list, int numElements) {
    cout << "Starting remove benchmark for " << numElements / 10 << " elements..." << endl;
    LinkedList copy = createCopy(list);
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements / 10; ++i) {
        int value = rand() % 100;
        cout << "Attempting to remove value: " << value << endl;
        copy.remove(value);  // Randomly removing elements
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to remove " << numElements / 10 << " elements: " << duration.count() << " ms" << endl;
    cout << "Remove operation completed." << endl;
}

void benchmarkSearch(const LinkedList &list, int numElements) {
    cout << "Starting search benchmark for " << numElements / 10 << " elements..." << endl;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements / 10; ++i) {
        int value = rand() % 100;
        bool found = list.contains(value);
        cout << "Searching for value: " << value << ". Found: " << (found ? "Yes" : "No") << endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to search " << numElements / 10 << " elements: " << duration.count() << " ms" << endl;
    cout << "Search operation completed." << endl;
}

void benchmarkUpdate(LinkedList &list, int numElements) {
    cout << "Starting update benchmark for " << numElements / 10 << " elements..." << endl;
    LinkedList copy = createCopy(list);
    auto start = high_resolution_clock::now();
    for (int i = 0; i < numElements / 10; ++i) {
        int oldVal = rand() % 100;
        int newVal = rand() % 100;
        cout << "Updating value " << oldVal << " to " << newVal << endl;
        copy.update(oldVal, newVal);  // Updating random elements
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to update " << numElements / 10 << " elements: " << duration.count() << " ms" << endl;
    cout << "Update operation completed." << endl;
}

void benchmarkReverse(LinkedList &list, int numElements) {
    cout << "Starting reverse benchmark for list of " << numElements << " elements..." << endl;
    LinkedList copy = createCopy(list);
    auto start = high_resolution_clock::now();
    copy.reverse();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to reverse list of " << numElements << " elements: " << duration.count() << " ms" << endl;
    cout << "Reverse operation completed." << endl;

    // 打印反转后的链表内容
    cout << "Reversed Linked List:" << endl;
    copy.display();
}

void benchmarkSort(LinkedList &list, int numElements) {
    cout << "Starting sort benchmark for list of " << numElements << " elements..." << endl;
    LinkedList copy = createCopy(list);
    auto start = high_resolution_clock::now();
    copy.sort();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Time taken to sort list of " << numElements << " elements: " << duration.count() << " ms" << endl;
    cout << "Sort operation completed." << endl;

    // 打印排序后的链表内容
    cout << "Sorted Linked List:" << endl;
    copy.display();
}

void runBenchmark(int numElements) {
    cout << "\n=====================================================" << endl;
    cout << "Benchmark for " << numElements << " elements:" << endl;
    cout << "=====================================================" << endl;

    LinkedList list;
    benchmarkAppend(list, numElements);  // 插入数据后打印链表
    benchmarkReverse(list, numElements); // 打印反转后的链表
    benchmarkSort(list, numElements);    // 打印排序后的链表

    cout << "=====================================================\n" << endl;
}

int main() {
    srand(time(0));

    // Benchmark with different sizes
    runBenchmark(10);
    //runBenchmark(100);
    //runBenchmark(1000);

    return 0;
}
