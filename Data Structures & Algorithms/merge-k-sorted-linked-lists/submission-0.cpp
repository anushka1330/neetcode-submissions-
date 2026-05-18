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
        vector<int> v;

        for(auto l : lists) {
            while(l) {
                v.push_back(l->val);
                l = l->next;
            }
        }

        sort(v.begin(), v.end());

        ListNode *dummy = new ListNode(0), *t = dummy;

        for(int x : v) {
            t->next = new ListNode(x);
            t = t->next;
        }

        return dummy->next;
    }
};
