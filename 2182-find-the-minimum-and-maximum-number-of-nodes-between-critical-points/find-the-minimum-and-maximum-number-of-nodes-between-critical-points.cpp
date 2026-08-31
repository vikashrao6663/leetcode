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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1;
        int mn = INT_MAX;

        ListNode* prev = head;
        ListNode* cur = head->next;

        int idx = 1;

        while (cur->next) {
            if ((cur->val > prev->val && cur->val > cur->next->val) ||
                (cur->val < prev->val && cur->val < cur->next->val)) {

                if (first == -1) {
                    first = idx;
                } else {
                    mn = min(mn, idx - last);
                }

                last = idx;
            }

            prev = cur;
            cur = cur->next;
            idx++;
        }

        if (first == -1 || first == last)
            return {-1, -1};

        return {mn, last - first};
    }
};