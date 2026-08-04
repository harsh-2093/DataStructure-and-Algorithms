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
    ListNode* rvrs(ListNode*temp)
    {
        if(temp==nullptr)return nullptr;
        if(temp->next==nullptr)
        {
           ListNode* head=temp;
            return head;
        }
        ListNode* head=rvrs(temp->next);
        ListNode*node=head;

        while(node->next!=nullptr)
        {
            node=node->next;
        }
        node->next=temp;
        temp->next=nullptr;
        
        return head;

    }
    ListNode* reverseList(ListNode* head) {
        return rvrs(head);
    }
};