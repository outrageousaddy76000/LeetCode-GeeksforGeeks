class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        //for each subarray of length m, check if its repeated k times;
        int i=0,j=m-1;
        while(j<arr.size()){
            int a = i+m;
            int b = j+m;
            int x =k-1;
            //if we find k subarray for the main subarray from i to j we return true;
            while(b<arr.size()){
                //if subarray not equal break
                int check=1;
                for(int k=a;k<=b;k++){
                    if(arr[k]!=arr[i+k-a]){
                        check=0;
                        break;
                    }
                }
                if(!check) break;
                a+=m;
                b+=m;
                x--;
                if(x==0) return true;
            } 
            i++,j++;
            x=k;
        }
        return false;
    }
};