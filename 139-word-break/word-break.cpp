#include <unordered_set>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[301];

    bool solve(int idx, string s) {
        if(idx == n) {
            return true;
        }
        if(t[idx] != -1) {
            return t[idx];
        }
        for(int i = 1; i <= n - idx; i++) {
            string temp = s.substr(idx, i);
            if(st.find(temp) != st.end() && solve(idx + i, s)) {
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t));
        for(string &word: wordDict) {
            st.insert(word);
        }
        return solve(0, s);
    }
};