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
        vector<int>nodes;
        ListNode head(0);
        ListNode* point = &head;
        for(auto it : lists){
            
            while(it){
                nodes.push_back(it->val);
                it = it->next;
            }
        }
        sort(nodes.begin(),nodes.end());
        for(int x : nodes){
            point->next = new ListNode(x);
            point = point->next;
        }

        return head.next;
    }
};
