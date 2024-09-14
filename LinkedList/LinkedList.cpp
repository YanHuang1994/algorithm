#include <iostream>
#include "LinkedList.h"
#include <string>

using namespace std;

// --- ListNode Implementation ---

ListNode::ListNode(int val) {
    data = val;
    next = nullptr;
}

// --- LinkedList Implementation ---

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

ListNode* LinkedList::getHead() const {
    return head;
}

void LinkedList::append(int val) {
    ListNode* newNode = new ListNode(val);
    if (!head) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void LinkedList::prepend(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insert(int val, int position) {
    ListNode* newNode = new ListNode(val);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    ListNode* temp = head;
    for (int i = 0; temp != nullptr && i < position - 1; i++) {
        temp = temp->next;
    }
    if (!temp) {
        std::cout << "Position out of bounds" << std::endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void LinkedList::remove(int val) {
    if (!head) return;

    if (head->data == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }

    if (curr) {
        prev->next = curr->next;
        delete curr;
    }
}

bool LinkedList::contains(int val) const {
    ListNode* temp = head;
    while (temp) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool LinkedList::update(int oldVal, int newVal) {
    ListNode* temp = head;
    while (temp) {
        if (temp->data == oldVal) {
            temp->data = newVal;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void LinkedList::display() {
    ListNode* temp = head;
    while (temp) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

void LinkedList::reverse() {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy, *cur = head;

    while (cur && cur->next) {
        ListNode* tmp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = tmp;
    }

    head = dummy->next;
    delete dummy;
}

void LinkedList::sort() {
    if (!head || !head->next) return;
    quickSort();
    return;
}

ListNode* LinkedList::quickSort() {
    partition(head, nullptr);
    return head;  // 返回排序后的链表头部
}

void LinkedList::partition(ListNode* head, ListNode* tail) {
    if (head == tail || head->next == tail) return;

    ListNode* slow = head;
    ListNode* fast = head;
    int pivot = head->data;

    while (fast != tail) {
        if (fast->data < pivot) {
            slow = slow->next;
            int tmp = slow->data;
            slow->data = fast->data;
            fast->data = tmp;
        }
        fast = fast->next;
    }

    head->data = slow->data;
    slow->data = pivot;

    partition(head, slow);
    partition(slow->next, tail);
}