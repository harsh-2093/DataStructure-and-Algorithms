/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*>st;
        ListNode*temp=head;
        ListNode*result=nullptr;
        while(temp!=nullptr)
        {
            if(st.find(temp)!=st.end())
            {
                result=temp->next;
                return temp;
            }
            st.insert(temp);
            temp=temp->next;
        }
        return nullptr;
        
    }
};