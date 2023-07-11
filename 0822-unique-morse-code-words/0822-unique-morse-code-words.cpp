class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set <string> s;
        unordered_map<char, std::string> m;

        // Morse code mappings
        string morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        // Characters to map
        char characters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

        // Add the Morse code mappings to the unordered_map
        for (int i = 0; i < 26; i++) {
            m[characters[i]] = morseCodes[i];
        }
        for(int i=0;i<words.size();i++){
            string a="";
            for(int j=0;j<words[i].size();j++){
                a+=m[toupper(words[i][j])];
            }
            s.insert(a);
        }
        return s.size();
    }
};