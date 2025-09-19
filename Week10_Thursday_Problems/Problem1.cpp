#include <iostream>
using namespace std;

// =========================
// Definition of a Node
// =========================
struct ListNode {
    int val;            // Stores the data (the number)
    ListNode* next;     // Pointer to the next node in the list

    // Constructor initializes the node with a value and sets next to nullptr
    ListNode(int x) : val(x), next(nullptr) {}
};

// =========================
// Function: insertAtEnd
// Purpose: Insert a new node at the END of the list
// =========================
void insertAtEnd(ListNode*& head, int value) {
    // Create a new node with the given value
    ListNode* newNode = new ListNode(value);

    // CASE 1: If the list is empty, make the new node the head
    if (!head) {
        head = newNode;
        return;
    }

    // CASE 2: Otherwise, traverse to the end of the list
    ListNode* current = head;
    while (current->next) {
        current = current->next;
    }

    // Link the last node to the new node
    current->next = newNode;

    /*
        Example after inserting 10, then 20:
        head → [10 | next] → [20 | nullptr]
    */
}

// =========================
// Function: sumList
// Purpose: Traverse the list and return the sum of all node values
// =========================
int sumList(ListNode* head) {
    int sum = 0;                // Start with sum = 0
    ListNode* current = head;   // Begin from the head node

    // Traverse through all nodes
    while (current) {
        sum += current->val;    // Add the node's value to sum
        current = current->next; // Move to the next node
    }

    /*
        Example:
        List:  [5] → [10] → [20]
        sum = 5 + 10 + 20 = 35
    */

    return sum;
}

// =========================
// MAIN FUNCTION
// =========================
int main() {
    ListNode* head = nullptr;   // Start with an empty list
    char newNum = 'y';          // To check if the user wants to continue
    int number = 0;             // Number input by the user

    // Keep asking for numbers until the user says no
    do {
        cout << "Enter a number? ";
        cin >> number;

        // Insert the number into the linked list
        insertAtEnd(head, number);

        /*
            Example if user entered: 3, then 7, then 12
            Step 1: head → [3 | nullptr]
            Step 2: head → [3 | next] → [7 | nullptr]
            Step 3: head → [3 | next] → [7 | next] → [12 | nullptr]
        */

        cout << "Do you want to add another number? (y/n): ";
        cin >> newNum;

    } while (newNum == 'y' || newNum == 'Y');

    // Print the sum of all values in the list
    cout << "Sum of elements: " << sumList(head) << endl;

    return 0;
}
