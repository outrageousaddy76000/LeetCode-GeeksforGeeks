class ProductOfNumbers {
public:
    vector <int> nums;
    ProductOfNumbers() {
        nums.clear();    
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod=1;
        int cnt=0;
        for(int i=nums.size()-1;i>=0;i--){
            prod*=nums[i];
            cnt++;
            if(cnt==k) break;
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */