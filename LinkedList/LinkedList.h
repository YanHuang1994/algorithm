#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @class ListNode
 * @brief This class represents a node in the linked list.
 *
 * A ListNode object stores an integer data value and a pointer to the next node
 * in the list. This class is used as the basic element in the LinkedList class.
 */
class ListNode {
public:
    int data;               ///< The data stored in the node.
    ListNode* next;         ///< Pointer to the next node in the list.

    /**
     * @brief Constructs a ListNode with a given value.
     * 
     * This constructor initializes a node with the provided data value
     * and sets the next pointer to nullptr.
     * 
     * @param val The integer value to be stored in the node.
     */
    ListNode(int val);

    /**
     * @brief Constructs a ListNode with a given value and next node pointer.
     * 
     * This constructor initializes a node with the provided data value
     * and sets the next pointer to point to the provided next node.
     * 
     * @param x The integer value to be stored in the node.
     * @param nextNode The pointer to the next node in the list.
     */
    ListNode(int x, ListNode* nextNode);
};

/**
 * @class LinkedList
 * @brief This class implements a singly linked list.
 *
 * The LinkedList class provides a variety of methods to manipulate a singly linked list,
 * including adding, removing, updating, searching, and sorting elements. The list consists 
 * of ListNode objects, each storing an integer value and a pointer to the next node.
 */
class LinkedList {
private:
    ListNode* head;  ///< Pointer to the first node (head) of the linked list.

public:
    /**
     * @brief Constructs an empty LinkedList.
     *
     * Initializes the list with no elements (head is set to nullptr).
     */
    LinkedList();

    /**
     * @brief Destructor that deallocates the memory used by the list.
     *
     * This destructor ensures that all nodes in the list are deleted,
     * preventing memory leaks.
     */
    ~LinkedList();

    /**
     * @brief Gets the head node of the linked list.
     * 
     * This function is useful for accessing the start of the list,
     * typically for iteration or copying purposes.
     * 
     * @return ListNode* Pointer to the head node of the list.
     */
    ListNode* getHead() const;

    /**
     * @brief Adds a new node with a given value to the end of the list.
     *
     * This method traverses the list to the last node and appends
     * a new node containing the specified value.
     * 
     * @param val The integer value to append to the list.
     */
    void append(int val);

    /**
     * @brief Adds a new node with a given value to the start of the list.
     *
     * This method inserts a new node at the beginning of the list,
     * making the new node the head of the list.
     * 
     * @param val The integer value to prepend to the list.
     */
    void prepend(int val);

    /**
     * @brief Inserts a new node with a given value at a specified position.
     *
     * This method inserts a node at a given 0-based index in the list.
     * If the index is 0, the node is inserted at the head.
     * 
     * @param val The integer value to insert into the list.
     * @param position The 0-based index where the node should be inserted.
     * @throws std::out_of_range If the position is out of bounds of the list size.
     */
    void insert(int val, int position);

    /**
     * @brief Removes the first node that contains a specific value.
     *
     * This method traverses the list, finds the first occurrence of the node
     * with the specified value, and removes it from the list.
     * 
     * @param val The integer value to remove from the list.
     */
    void remove(int val);

    /**
     * @brief Checks if a given value exists in the list.
     * 
     * This method traverses the list and returns `true` if the value
     * is found in any node. Otherwise, it returns `false`.
     * 
     * @param val The integer value to search for in the list.
     * @return true If the value is found in the list.
     * @return false If the value is not found in the list.
     */
    bool contains(int val) const;

    /**
     * @brief Updates the first occurrence of a value in the list.
     * 
     * This method traverses the list and updates the first node
     * that contains the specified `oldVal` to the new value `newVal`.
     * 
     * @param oldVal The value to be updated.
     * @param newVal The new value to replace `oldVal`.
     * @return true If the update was successful (i.e., `oldVal` was found).
     * @return false If the update was unsuccessful (i.e., `oldVal` was not found).
     */
    bool update(int oldVal, int newVal);

    /**
     * @brief Displays all the values in the linked list.
     *
     * This method traverses the list and prints the data values
     * of all the nodes in the list, in order from head to tail.
     */
    void display();

    /**
     * @brief Reverses the order of nodes in the linked list.
     *
     * This method reverses the list in place by reversing the
     * next pointers of the nodes, so that the last node becomes the head.
     */
    void reverse();

    /**
     * @brief Sorts the linked list in ascending order.
     *
     * This method sorts the list using a quicksort algorithm,
     * rearranging the nodes in non-decreasing order.
     */
    void sort();

private:
    /**
     * @brief Helper function to perform quicksort on the linked list.
     *
     * This method sorts the linked list using a quicksort algorithm.
     * It is called recursively to sort the partitions of the list.
     * 
     * @return ListNode* Pointer to the new head of the sorted list.
     */
    ListNode* quickSort();

    /**
     * @brief Helper function to partition the linked list for quicksort.
     * 
     * This function partitions the linked list into two parts around a pivot.
     * Nodes smaller than the pivot are moved to the left of the pivot, and nodes
     * greater than or equal to the pivot are moved to the right.
     * 
     * @param head Pointer to the start of the partition.
     * @param tail Pointer to the end of the partition.
     */
    void partition(ListNode* head, ListNode* tail);
};

#endif
