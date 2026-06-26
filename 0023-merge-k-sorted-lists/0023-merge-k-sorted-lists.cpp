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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct Compare {
            bool operator()(ListNode* a, ListNode* b) const {
                return a->val > b->val; 
            }
        };
        priority_queue< ListNode*,vector<ListNode*>,Compare> pq;
        for (auto it : lists) {
            if (it)
                pq.push(it);
        }
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next)
                pq.push(node->next);
        }
        return dummy.next;
    }
};