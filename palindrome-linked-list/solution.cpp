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
    ListNode* rvrs(ListNode*&start)
    {
        ListNode*temp=start;
        ListNode*prev=nullptr;
        while(temp!=nullptr)
        {
            ListNode*front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        ListNode*start=nullptr;

        while(fast!=nullptr&&fast->next!=nullptr)
        {

            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast==nullptr)
        {
            
            start=rvrs(slow);
            
        }
        else
        {
            slow=slow->next;
            start=rvrs(slow);

        }
        ListNode*temp=head;
        while(start!=nullptr)
        {
            if(start->val!=temp->val)
            {
                return false;
            }
            start=start->next;
            temp=temp->next;
        }

    
        return true;
        
    }
};