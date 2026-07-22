class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>left_max_heap;
    priority_queue<int,vector<int>,greater<int>>right_min_heap;
    void addNum(int num) {
        if(left_max_heap.empty())
        {
            left_max_heap.push(num);
        }
        else if(left_max_heap.top()<num)
        {
            right_min_heap.push(num);
            if(right_min_heap.size()>left_max_heap.size())
            {
            int value=right_min_heap.top();
            right_min_heap.pop();
            left_max_heap.push(value);
            }
        }
        else
        {
            left_max_heap.push(num);
            if(left_max_heap.size()>right_min_heap.size()+1)
            {
            int value= left_max_heap.top();
            left_max_heap.pop();
            right_min_heap.push(value);
            }
        }
        
    }
    
    double findMedian() {
        if(left_max_heap.size()==right_min_heap.size())
        {
            int value=left_max_heap.top()+right_min_heap.top();
            return value/2.0;
        }
        else
        {
            return left_max_heap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */