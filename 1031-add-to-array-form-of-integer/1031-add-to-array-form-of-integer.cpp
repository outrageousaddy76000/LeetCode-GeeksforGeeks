class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int i=0;
        int carry=0;
        while(k>0){
            int sumeach = k%10;
            if(i==num.size()){
                int sum = sumeach+carry;
                carry=sum/10;
                num.push_back(sum%10);
            }
            else{
                int sum = num[i]+sumeach+carry;
                carry=sum/10;
                num[i]=sum%10;
            }
            i++;
            k/=10;
        }
        while(i!=num.size()){
            int sum=num[i]+carry;
            num[i]=sum%10;
            carry=sum/10;
            i++;
        }
        if(carry) num.push_back(carry);
        reverse(num.begin(),num.end());
        return num;
    }
};