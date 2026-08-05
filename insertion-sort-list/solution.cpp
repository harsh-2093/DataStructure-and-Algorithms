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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy=new ListNode();
        ListNode* curr=head;

        while(curr!=nullptr)
        {
            ListNode* nextNode=curr->next;

            if(dummy->next==nullptr)
            {
                dummy->next=curr;
                curr->next=nullptr;
            }
            else
            {
                ListNode* Temp=dummy;

                while(Temp->next!=nullptr && Temp->next->val <= curr->val)
                {
                    Temp=Temp->next;
                }
                curr->next=Temp->next;
                Temp->next=curr;
            }

            curr=nextNode;
            
        }
        return dummy->next;
    }
};