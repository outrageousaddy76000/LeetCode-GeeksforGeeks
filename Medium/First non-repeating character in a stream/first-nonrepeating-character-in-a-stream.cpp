//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    queue <char> q;
		    vector <int> freq(26);
		    string ans="";
		    for(int i=0;i<s.size();i++){
		        freq[s[i]-'a']++;
		        if(freq[s[i]-'a']==1) q.push(s[i]);
		        while(q.size() && freq[q.front()-'a']>1){
		            q.pop();
		        }
		        if(q.empty()) ans+='#';
		        else ans+=q.front();
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends