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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* orig = head;
        ListNode* pre = nullptr;
        ListNode* mid = head;
        while (head != nullptr) {
            head = head->next;
            if (head != nullptr) {
                pre = mid;
                mid = mid->next;
                head = head->next;
            }
        }
        if (pre != nullptr) {
            pre->next = mid->next;
            // delete mid;
            return orig;
        } else {
            return nullptr;
        }
    }
};
