class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    vector<int>ans;

    
    void add(int num) {
        ans.push_back(num);

    }
    
    int getProduct(int k) {
        int n=ans.size()-1;
        int a=1;
        while(k--)
        {
            a*=ans[n--];
        }
        return a;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */