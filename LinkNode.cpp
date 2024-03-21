#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            // Calculate sum and carry
            int total = val1 + val2 + carry;
            carry = total / 10;
            int digit = total % 10;

            // Create new node with the digit
            current->next = new ListNode(digit);
            current = current->next;

            // Move to next nodes
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};

// Helper function to print the linked list
void printLinkedList(ListNode* node) {
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "None" << endl;
}

int main() {
    // Creating linked lists
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Adding the numbers represented by linked lists
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Printing the result
    printLinkedList(result);

    return 0;
}
