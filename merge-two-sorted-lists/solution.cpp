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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=new ListNode();
        ListNode* temp=head;


        while(list1!=nullptr && list2!=nullptr)
        {
            if(list1->val<=list2->val)
            {
                head->next=list1;

                list1=list1->next;
            }
            else
            {
                head->next=list2;
                list2=list2->next;
            }
            head=head->next;

        }
        while(list1!=nullptr)
        {
            head->next=list1;
            head=head->next;
            list1=list1->next; 
        }
        while(list2!=nullptr)
        {
            head->next=list2;
            head=head->next;

            list2=list2->next; 
        }
        return temp->next;
    }
};