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
    ListNode* Reverse(ListNode*&head)
    {
        ListNode*temp=head;
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

    ListNode* get_k_node(ListNode*&head,int k)
    {
        ListNode*temp=head;
        k=k-1;
        while(k--)
        {
            if(temp==nullptr)
            {
                return nullptr;
            }
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*next=nullptr;
        ListNode*prev=nullptr;

        while(temp!=nullptr)
        {
            ListNode*Knode=get_k_node(temp,k);
            if(Knode==nullptr)
            {
                if(prev!=nullptr)
                {
                    prev->next=temp;
                }
                break;
            }

            next= Knode->next;
            Knode->next=nullptr;

            Reverse(temp);

            if(temp==head)
            {
                head=Knode;
            }
            else
            {
                prev->next=Knode;
            }
            prev=temp;
            temp=next;
        }
        return head;
        
    }
};