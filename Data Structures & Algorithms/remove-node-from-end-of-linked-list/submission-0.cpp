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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != nullptr){
            temp = temp->next;
            cnt++;
        }
        
        int res = cnt - n;
        if(res==0){
            ListNode* delNode = head;
            ListNode* ans = head->next;
            delete (delNode);

            return ans;
        }

        temp = head;
        while(res > 1){
            temp = temp->next;
            res--;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete (delNode);

        return head;
    }
};
