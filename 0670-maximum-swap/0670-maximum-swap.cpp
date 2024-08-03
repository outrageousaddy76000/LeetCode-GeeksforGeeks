class Solution {
public:
    int maximumSwap(int num) {
        //swap max digit with first digit, if not same, else move to the next digit
        vector <int> v;
        while(num>0){
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(),v.end());
        vector <int> a = v;
        sort(a.rbegin(),a.rend());
        for(int i=0;i<a.size();i++){
            if(a[i]!=v[i]){
                //make v[i]=a[i], if there are multiple v[i]==a[i], pick the last one
                for(int j=v.size()-1;j>i;j--){
                    if(v[j]==a[i]){
                        v[j]=v[i];
                        v[i]=a[i];
                        break;
                    }
                }
                break;
            }
        }
        //create the number
        for(int i=0;i<v.size();i++){
            num = num*10+v[i];
        }
        return num;
    }
};