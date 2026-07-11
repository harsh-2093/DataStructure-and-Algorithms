/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;

        Node*temp=head;
        while(temp!=nullptr)
        {
            Node*newnode=new Node(temp->val);
            mp[temp]=newnode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr)
        {
            Node*node=mp[temp];
            node->next=mp[temp->next];
            node->random=mp[temp->random];
            temp=temp->next;
        }
        temp=head;
        return mp[temp];
    }
};