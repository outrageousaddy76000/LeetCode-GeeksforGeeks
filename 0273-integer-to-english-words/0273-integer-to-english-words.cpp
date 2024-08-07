class Solution {
public:
    string numberToWords(int num) {
        unordered_map<int,string> extra{
            {1,"Thousand"},{2,"Million"},{3,"Billion"}
        };
        unordered_map<int, string> ones{
            {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
            {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}
        };

        unordered_map<int, string> teens{
            {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
            {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"},
            {18, "Eighteen"}, {19, "Nineteen"}
        };

        unordered_map<int, string> tens{
            {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"},
            {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}
        };
        vector <int> digits;
        if(num==0) return "Zero";
        else
        while(num>0){
            digits.push_back(num%10);
            num/=10;
        }
        //take 3 at a time
        string ans="";
        vector <string> converted;
        int cnt=0;
        for(int i=0;i<digits.size();i+=3){
            if(cnt>0){
                //if(all 3 are 0 dont push)
                if(digits[i] || (i+1<digits.size() && digits[i+1]) || (i+2<digits.size() && digits[i+2]))
                    converted.push_back(extra[cnt]);
            }
            // Check for up to 3 digits
            if (i + 1 >= digits.size()) {
                // No tens place or hundreds place
                converted.push_back(ones[digits[i]]);
            } 
            else if (i + 2 >= digits.size()) {
                // No hundreds place
                if (digits[i + 1] == 1) {
                    converted.push_back(teens[digits[i] + 10*digits[i+1]]);
                } 
                else {
                    if(digits[i]!=0)
                    converted.push_back(ones[digits[i]]);
                    converted.push_back(tens[digits[i + 1]]);
                }
            } 
            else {
                // All three places
                if (digits[i + 1] == 1) {
                    converted.push_back(teens[digits[i] + 10*digits[i+1]]);
                    if(digits[i+2]!=0){
                        converted.push_back("Hundred");
                        converted.push_back(ones[digits[i + 2]]);
                    }
                } 
                else {
                    if(digits[i]!=0) converted.push_back(ones[digits[i]]);
                    if(digits[i+1]!=0) converted.push_back(tens[digits[i + 1]]);
                    if(digits[i+2]!=0){
                        converted.push_back("Hundred");
                        converted.push_back(ones[digits[i + 2]]);
                    }
                }
            }
            cnt++;
        }
        cout<<converted.size();
        for(int i=converted.size()-1;i>=0;i--) ans+=converted[i]+" ";
        ans.pop_back();
        return ans;
    }
};