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
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        ListNode*newhead=new ListNode(0);
        ListNode*newtemp=newhead;

        while(temp1!=nullptr && temp2!=nullptr)
        {
            if(temp1->val <temp2->val ||temp1->val==temp2->val)
            {
                ListNode* z=new ListNode(temp1->val);
                newtemp->next=z;
                temp1=temp1->next;

            }
            else// (temp1->val>temp2->val)
            {
                ListNode*z=new ListNode(temp2->val);
                newtemp->next=z;
                temp2=temp2->next;
            }
            /*
            else
            {
                ListNode*z=new ListNode(temp2->val);
                newtemp->next=z;
                temp1=temp1->next;
                temp2=temp2->next;
            }*/
            newtemp=newtemp->next;
        }
        if(temp1!=nullptr)
        {
            newtemp->next=temp1;
        }
        if(temp2!=nullptr)
        {
            newtemp->next=temp2;
        }
        return newhead->next;
    }
};