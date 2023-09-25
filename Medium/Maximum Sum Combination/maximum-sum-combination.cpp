//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {

     sort(A.begin(),A.end());

     sort(B.begin(),B.end());

     

     priority_queue<pair<int,pair<int,int>>> pq;

     set<pair<int,int>> s;

   

     pq.push(make_pair(A[N-1]+B[N-1],make_pair(N-1,N-1)));

     s.insert(make_pair(N-1,N-1));

   

     vector<int>ans;

   

       while(K--){

     

       auto top=pq.top();

       pq.pop();

       ans.push_back(top.first);

     

       int L=top.second.first;

       int R=top.second.second;

     

        if(L>0 && R>0 && s.find(make_pair(L-1,R))==s.end()){

       pq.push(make_pair(A[L-1]+B[R],make_pair(L-1,R)));

       s.insert(make_pair(L-1,R));

     }

       

        if(L>0 && R>0 && s.find(make_pair(L,R-1))==s.end()){

       pq.push(make_pair(A[L]+B[R-1],make_pair(L,R-1)));

       s.insert(make_pair(L,R-1));

     }

}

return ans;

}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends