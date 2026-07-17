class Solution {
public:
    // Function to reverse a linked list
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return nullptr;

        // Step 1: Reverse the linked list
        head = reverse(head);

        // Step 2: Remove the nth node from the beginning (which is nth from the end originally)
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 1; i < n && curr; i++) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) return reverse(head); // If n is out of bounds, return original list

        if (prev) {
            prev->next = curr->next;
        } else {
            head = curr->next; // If removing the first node
        }

        delete curr; // Free memory

        // Step 3: Reverse the list back to original order
        return reverse(head);
    }
};