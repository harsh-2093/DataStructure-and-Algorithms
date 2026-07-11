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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*temp=head;
        ListNode*newhead=new ListNode(-1);
        ListNode*newtemp=newhead;
        while(temp!=nullptr)
        {
            if(temp->val!=val)
            {

            
            ListNode*newnode=new ListNode(temp->val);
            newtemp->next=newnode;   
            newtemp=newtemp->next;
            }

            temp=temp->next;
        }
        return newhead->next;



        
    }
};