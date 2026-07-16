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
    
    class comp{
        public:
        bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>pq;
        
        for(int i=0;i<lists.size();i++)
        {
            ListNode* temp=lists[i];
            if(temp!=nullptr)
            pq.push(lists[i]);
        }
        ListNode*head=new ListNode();
        ListNode*point=head;

        while(!pq.empty())
        {
            ListNode*temp=pq.top();

            if(temp!=nullptr)
            {
                point->next=temp;
                point=point->next;
                if(temp->next!=nullptr)
                {
                pq.push(temp->next);
                }
            }
            

            pq.pop();

        }

        return head->next;
    }
};