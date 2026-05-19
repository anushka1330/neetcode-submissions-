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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode *cur = head;
        int cnt = 0;

        while(cur && cnt < k) {
            cur = cur->next;
            cnt++;
        }

        if(cnt < k) return head;

        ListNode *prev = NULL, *next = NULL;
        cur = head;
        cnt = 0;

        while(cur && cnt < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }

        head->next = reverseKGroup(cur, k);

        return prev;
    }
};