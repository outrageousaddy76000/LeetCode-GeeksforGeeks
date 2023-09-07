class Solution {
public:
    bool isvalid(const string& s) {
        // Check if the string is empty
        if (s.empty()) {
            return false;
        }

        int hyphenCount = 0;
        int punctuationCount = 0;

        // Loop through each character in the string
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            // Check if the character is a lowercase letter
            if (islower(c)) {
                // Check if the previous character was a hyphen
                if (i > 0 && s[i - 1] == '-') {
                    hyphenCount++;
                    // Check if there is more than one hyphen
                    if (hyphenCount > 1) {
                        return false;
                    }
                }
            }
            // Check if the character is a hyphen
            else if (c == '-') {
                // Check if the hyphen is not surrounded by lowercase characters
                if (i == 0 || i == s.length() - 1 || !islower(s[i - 1]) || !islower(s[i + 1])) {
                    return false;
                }
            }
            // Check if the character is a punctuation mark
            else if (ispunct(c)) {
                // Check if the punctuation mark is not at the end of the token
                if (i != s.length() - 1) {
                    return false;
                }
                punctuationCount++;
                // Check if there is more than one punctuation mark
                if (punctuationCount > 1) {
                    return false;
                }
            }
            // Check if the character is not a lowercase letter, hyphen, or punctuation
            else {
                return false;
            }
        }

        return true;
    }
    int countValidWords(string sentence) {
        stringstream ss(sentence);
        string word;
        int ans=0;
        while(ss>>word){
            if(isvalid(word)) ans++;
        }
        return ans;
    }
};