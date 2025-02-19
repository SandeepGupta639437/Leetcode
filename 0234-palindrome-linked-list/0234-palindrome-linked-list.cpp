/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode * temp=head;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        bool found=true;
        while(temp!=NULL)
        {
            if(temp->val!=st.top())
            {
                return false;
            }
            else
            {
                temp=temp->next;
                st.pop();
            }
        }
        return true;
    //       ListNode* slow = head;
    //     ListNode* fast = head;
    //     while (fast && fast->next) {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     ListNode* prev = nullptr;
    //     ListNode* currNode = slow;
    //     while (currNode) {
    //         ListNode* tempNext = currNode->next;
    //         currNode->next = prev;
    //         prev = currNode;
    //         currNode = tempNext;
    //     }

    //     ListNode* left = head;
    //     ListNode* right = prev;
    //     while (right) {
    //         if (left->val != right->val) {
    //             return false;
    //         }
    //         left = left->next;
    //         right = right->next;
    //     }
    //    return true;
     }
};