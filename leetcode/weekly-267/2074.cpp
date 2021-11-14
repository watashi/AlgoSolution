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
    int length(ListNode* head, int limit) {
        int ret = 0;
        while (ret < limit && head != nullptr) {
            ++ret;
            head = head->next;
        }
        return ret;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* ret = head;
        ListNode* prev = nullptr;
        for (int i = 1; head != nullptr; ++i) {
            if (length(head, i) % 2 == 0) {
                ListNode* const end1 = prev;
                ListNode* const end2 = head;
                for (int j = 0; head != nullptr && j < i; ++j) {
                    auto temp = head->next;
                    head->next = prev;
                    prev = head;
                    head = temp;
                }
                end1->next = prev;
                end2->next = head;
                prev = end2;
            } else {
                for (int j = 0; head != nullptr && j < i; ++j) {
                    prev = head;
                    head = head->next;
                }
            }
        }
        return ret;
    }
};
