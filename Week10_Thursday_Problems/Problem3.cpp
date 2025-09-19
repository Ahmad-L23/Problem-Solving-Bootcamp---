#include <iostream>
#include <climits>  // For INT_MIN (smallest possible integer)
using namespace std;

// =========================
// Definition of a Node
// =========================
struct ListNode {
    int val;            // Data stored in the node
    ListNode* next;     // Pointer to the next node

    // Constructor initializes node with value x, next = nullptr
    ListNode(int x) : val(x), next(nullptr) {}
};

// =========================
// Function: insertAtEnd
// Purpose: Insert a new node at the END of the list
// =========================
void insertAtEnd(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value); // Create a new node

    // CASE 1: If list is empty, new node becomes the head
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
        Example after inserting 5, 9:
        head → [5 | next] → [9 | nullptr]
    */
}

// =========================
// Function: maxList
// Purpose: Find the maximum value in the linked list
// =========================
int maxList(ListNode* head) {
    if (!head) // If the list is empty
        return INT_MIN; // Return the smallest integer as "no max"

    int maxVal = head->val;     // Assume the first node is the maximum
    ListNode* current = head->next; // Start checking from the second node

    // Traverse through the list
    while (current) {
        if (current->val > maxVal)  // Update if current value is greater
            maxVal = current->val;

        current = current->next;    // Move to the next node
    }

    return maxVal; // Return the maximum value found

    /*
        Example with list: [5] → [9] → [2] → [7]
        Step 1: maxVal = 5
        Step 2: Compare 9 > 5 → maxVal = 9
        Step 3: Compare 2 > 9 → false → maxVal stays 9
        Step 4: Compare 7 > 9 → false → maxVal stays 9
        Final Answer = 9
    */
}

// =========================
// MAIN FUNCTION
// =========================
int main() {
    ListNode* head = nullptr; // Start with an empty list

    // Build the linked list: 5 → 9 → 2 → 7
    insertAtEnd(head, 5);
    insertAtEnd(head, 9);
    insertAtEnd(head, 2);
    insertAtEnd(head, 7);

    /*
        Current list:
        head → [5 | next] → [9 | next] → [2 | next] → [7 | nullptr]
    */

    // Find and print the maximum value
    cout << "Maximum value: " << maxList(head) << endl; // Output: 9

    return 0;
}
