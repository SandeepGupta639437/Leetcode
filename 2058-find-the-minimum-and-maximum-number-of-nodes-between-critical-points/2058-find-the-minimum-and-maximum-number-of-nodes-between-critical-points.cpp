class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        int firstCriticalPos = -1;
        int prevCriticalPos = -1;
        int currCriticalPos = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int mini = INT_MAX;
        int maxi = -1;

        while (curr->next != nullptr) {

            // Local minima
            bool isCritical = (prev->val > curr->val && curr->val < curr->next->val);

            // Local maxima
            isCritical = isCritical || (prev->val < curr->val && curr->val > curr->next->val);

            if (isCritical) {
                // We already found a previous critical point
                if (prevCriticalPos != -1) {
                    mini = min( mini, currCriticalPos - prevCriticalPos);
                }

                // First critical point
                if (firstCriticalPos == -1) {
                    firstCriticalPos = currCriticalPos;
                }

                prevCriticalPos = currCriticalPos;
            }

            prev = curr;
            curr = curr->next;
            currCriticalPos++;
        }

        // bss ek yaa 0 critical points mile hai to distance possible hi nhi hai
        if (firstCriticalPos == -1 || firstCriticalPos == prevCriticalPos) {
            return {-1, -1};
        }

        // Maximum distance = last - first
        maxi = prevCriticalPos - firstCriticalPos;

        return {mini, maxi};
    }
};