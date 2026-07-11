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
    ListNode*rotate_right(ListNode*&head,int k)
    {
        ListNode*prev=nullptr;
        while(k--)
        {
            prev=head;
            head=head->next;
        }
        prev->next=nullptr;
        return head;
    }


    ListNode*make_circular(ListNode*&head,int k)
    {
        ListNode*temp=head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next=head;
        head=rotate_right(head,k);
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
       ///
       if(head==nullptr)return nullptr;
        ListNode*temp=head;
        int n=0;
        while(temp!=nullptr)
        {
            n++;
            temp=temp->next;
        }
        k=k%n;
        k=n-k;
        ///
        head=make_circular(head,k);



        return head;
        
    }
};