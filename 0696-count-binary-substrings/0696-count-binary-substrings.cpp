class Solution {
public:
    int answer=0;
    void count (string s){// we push if 0 and pop if 1 and increment answer by 1, this will count all 01 patterns
        stack<int> stk;
        int flag=0;
        for (int i=0; i<s.size(); i++){
            if (s[i]=='0'){
                if (flag==1){// this means last element was popped from the stack and then we
				//push -1 onto the stack signifying that we cannot go beyond -1 and must start afresh 
				//(stack does not have clear())
                    stk.push(-1);
                    flag=0;
                }
                stk.push(i);
            }
            else {
                if (!stk.empty() && stk.top()!=-1){
                    stk.pop();
                    flag=1;
                    answer++;
                }
            }
        }
    }
    
    
    int countBinarySubstrings(string s) {
        if (s.empty())return 1;
        count(s);// counts "00...011...1" pattern
        reverse(s.begin(), s.end());
        count(s);//counts "10" pattern
        return answer;
    }
};