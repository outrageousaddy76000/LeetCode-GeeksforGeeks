//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        vector <int> v(3);
        for(int i=0;i<N;i++){
            if(bills[i]==5) v[0]++;
            else if(bills[i]==10) v[1]++;
            else v[2]++;
            int change = bills[i]-5;
            if(change!=0){
                if(change==5){
                    if(v[0]==0) return false;
                    else v[0]--;
                }
                else{
                    if(v[1]>0){
                        v[1]--;
                        if(v[0]>0) v[0]--;
                        else return false;
                    }
                    else{
                        if(v[0]<3) return false;
                        else v[0]-=3;
                    }
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends