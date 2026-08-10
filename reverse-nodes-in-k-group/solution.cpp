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
    void attachToDummy(ListNode* new_head,ListNode*&tail)
    { 
        while(new_head!=nullptr)
        {
            tail->next=new_head;
            tail=tail->next;
            new_head=new_head->next;
        }
    }
    ListNode* rvrs(ListNode*start,ListNode*end)
    {
        if(start==end)
        {
            start->next=nullptr;
            return start;
        }
        ListNode* head=rvrs(start->next,end);
        start->next->next=start;
        start->next=nullptr;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode();
        ListNode* tail=dummy;

        int cnt=k;
        ListNode*temp=head;
         ListNode* start=nullptr;

        while(temp!=nullptr)
        {
            if(cnt==k)
            {

                start=temp;
                temp=temp->next;
                cnt--;
            }
            else if(cnt==1)
            {
                ListNode*end=temp;
                ListNode*next=temp->next;
                ListNode* new_head=rvrs(start,end);
                attachToDummy(new_head,tail);
                cnt=k;
                temp=next;
                start=temp;
            }
            else
            {
                temp=temp->next;
                cnt--;
            }
        }
        while(start!=nullptr)
        {
            tail->next=start;
            tail=tail->next;
            start=start->next;
        }
        return dummy->next;
    }
};