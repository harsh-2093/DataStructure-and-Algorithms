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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode*temp=head;
        ListNode*prev=head;

        while(temp!=nullptr){

            if(temp->val!=prev->val)
            {
                prev->next=temp;
                prev=prev->next;
            }
            temp=temp->next;
        }
        prev->next=nullptr;
        return head;
    }
};