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
        int dist = numeric_limits<int>::max();
        int index = 0, ifst = -1, ipre = -1;
        auto prev = head->val;
        head = head->next;
        while (head->next != nullptr) {
            auto next = head->next->val;
            ++index;
            if ((head->val > prev && head->val > next) || (head->val < prev && head->val < next)) {
                if (ifst == -1) {
                    ifst = ipre = index;
                } else {
                    dist = min(dist, index - ipre);
                    ipre = index;
                }
            }
            prev = head->val;
            head = head->next;
        }
        if (ifst == ipre) {
            return vector<int>{-1, -1};
        } else {
            return vector<int>{dist, ipre - ifst};
        }
    }
};
