class Solution {
public:
    vector<string> result;
    unordered_set<string> st;

    void solve(int i, string currSentence, string s) {
        if(i == s.length()) {
            result.push_back(currSentence);
            return;
        }
        for(int j = i; j < s.length(); j++) {
            string tempword = s.substr(i, j - i + 1);
            if(st.count(tempword)) { // valid word
                string tempsentence = currSentence;
                if(!currSentence.empty()) {
                    currSentence += " ";
                }
                currSentence += tempword; //take tempword
                solve(j + 1, currSentence, s); //Explore
                currSentence = tempsentence; //remove tempword
            }
        }
    }

    vector<string> wordBreak(string s, vector<string> wordDict) {
        for (string word : wordDict) {
            st.insert(word);
        }
        string currSentence = "";
        solve(0, currSentence, s); // Corrected call to solve
        return result;
    }
};