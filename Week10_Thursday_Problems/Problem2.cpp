#include <iostream>
using namespace std;

// =========================
// Definition of a Linked List Node
// =========================
struct ListNode {
    int val;            // Data stored in the node
    ListNode* next;     // Pointer to the next node

    // Constructor initializes the node with a value and next = nullptr
    ListNode(int x) : val(x), next(nullptr) {}
};

// =========================
// Function: insertAtEnd
// Purpose: Insert a new node at the END of the list
// =========================
void insertAtEnd(ListNode*& head, int value) {
    // Create a new node
    ListNode* newNode = new ListNode(value);

    // CASE 1: If the list is empty, new node becomes head
    if (!head) {
        head = newNode;
        return;
    }

    // CASE 2: Traverse to the last node
    ListNode* current = head;
    while (current->next)
        current = current->next;

    // Attach the new node at the end
    current->next = newNode;

    /*
        Example after inserting 1, then 2:
        head → [1 | next] → [2 | nullptr]
    */
}

// =========================
// Function: filterEven
// Purpose: Return a NEW list that contains only even numbers
// =========================
ListNode* filterEven(ListNode* head) {
    // Dummy node to simplify list building
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;     // Tail pointer to build the new list
    ListNode* current = head;   // Traverse original list

    // Traverse all nodes
    while (current) {
        // Check if current node is EVEN
        if (current->val % 2 == 0) {
            // Add a new node with the even value to the new list
            tail->next = new ListNode(current->val);
            tail = tail->next; // Move tail forward
        }
        current = current->next; // Move to next node
    }

    // Result list starts after dummy
    ListNode* result = dummy->next;
    delete dummy; // Free dummy node
    return result;

    /*
        Example:
        Original: head → [1] → [2] → [3] → [4]
        New list: dummy → [2] → [4]
                   result = dummy->next
    */
}

// =========================
// Function: printEvenNumbers
// Purpose: Print all values in the filtered even list
// =========================
void printEvenNumbers(ListNode* evensNums) {
    cout << "Even numbers: ";
    while (evensNums) {
        cout << evensNums->val << " ";
        evensNums = evensNums->next;
    }
}

// =========================
// MAIN FUNCTION
// =========================
int main() {
    ListNode* head = nullptr;   // Start with an empty list

    // Build the original list: 1 → 2 → 3 → 4
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);

    /*
        Current list:
        head → [1 | next] → [2 | next] → [3 | next] → [4 | nullptr]
    */

    // Filter only even numbers → New list will be [2] → [4]
    ListNode* evens = filterEven(head);

    // Print even numbers
    printEvenNumbers(evens); // Output: Even numbers: 2 4
    cout << endl;

    return 0;
}
