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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*head=new ListNode(-1);
        ListNode*temp=head;
        int carry=0;
        while(l1!=nullptr&&l2!=nullptr)
        {
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            ListNode*newnode=new ListNode(sum%10);
            temp->next=newnode;

            l1=l1->next;
            l2=l2->next;
            temp=temp->next;
        }
        while(l1!=nullptr)
        {
            int sum=l1->val+carry;
            carry=sum/10;
            ListNode*newnode=new ListNode(sum%10);
            temp->next=newnode;
            l1=l1->next;
            temp=temp->next;

            
        }
        while(l2!=nullptr)
        {
            int sum=l2->val+carry;
            carry=sum/10;
            ListNode*newnode=new ListNode(sum%10);
            temp->next=newnode;
            l2=l2->next;
            temp=temp->next;

            
        }
        if(carry)
        {
            ListNode*newnode=new ListNode(carry);
            temp->next=newnode;
        }
        return head->next;
        
    }
};