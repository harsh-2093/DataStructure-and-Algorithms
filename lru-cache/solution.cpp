class LRUCache {
public:
    struct Node
    {
        int key;
        int value;
        Node*next;
        Node*prev;
        
        Node(int Key,int Value)
        {
            key=Key;
            value=Value;
            next=nullptr;
            prev=nullptr;
        }
    };

    Node*head=nullptr;
    Node*tail=nullptr;
    int capacity=0;
    unordered_map<int,Node*>mpp;
    int cnt=0;


    LRUCache(int Capacity) {
        capacity=Capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end())
        {
            Node*temp=mpp[key];

            if(temp->prev!=nullptr && temp->next!=nullptr)
            {
                Node*back=temp->prev;
                Node*front=temp->next;
                back->next=front;
                front->prev=back;
                tail->next=temp;
                temp->next=nullptr;
                temp->prev=tail;
                tail=tail->next;
                return tail->value;
            }
            else if(temp->prev==nullptr && temp->next!=nullptr)
            {
                head=head->next;
                head->prev=nullptr;
                tail->next=temp;
                temp->next=nullptr;
                temp->prev=tail;
                tail=tail->next;
                return tail->value;
            }
            else
            {
                return tail->value;
            }

        }
        else
        {
            return -1;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(mpp.find(key)!=mpp.end())
        {
            Node*temp=mpp[key];
            temp->value=value;

            if(temp->prev!=nullptr && temp->next!=nullptr)
            {
                Node*back=temp->prev;
                Node*front=temp->next;
                back->next=front;
                front->prev=back;
                tail->next=temp;
                temp->next=nullptr;
                temp->prev=tail;
                tail=tail->next;
            }
            else if(temp->prev==nullptr && temp->next!=nullptr)
            {
                head=head->next;
                head->prev=nullptr;
                tail->next=temp;
                temp->next=nullptr;
                temp->prev=tail;
                tail=tail->next;
            }
            else
            {
                //do nothing
            }

        }
        else{

        if(head==nullptr)
        {
            Node*node=new Node(key,value);
            head=node;
            tail=head;
            mpp.insert({key,node});
            cnt++;
        }
        else
        {
            if(cnt>=capacity)
            {
                if(head->next!=nullptr)
                {
                    mpp.erase(head->key);
                    head=head->next;
                    head->prev=nullptr;
                    Node*node=new Node(key,value);
                    node->prev=tail;
                    tail->next=node;
                    tail=tail->next;
                    mpp.insert({key,node});
                }
                else
                {
                    mpp.erase(head->key);
                   head=nullptr;
                    Node*node=new Node(key,value);
                    head=node;
                    tail=head;
                    mpp.insert({key,node});
                }
    
            }
            else
            {
                Node*node=new Node(key,value);
                node->prev=tail;
                tail->next=node;
                tail=tail->next;
                mpp.insert({key,node});
                cnt++;
            }
            
        }

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */