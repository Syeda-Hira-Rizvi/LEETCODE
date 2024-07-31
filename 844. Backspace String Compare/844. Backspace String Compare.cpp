class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return buildString(s) == buildString(t);
    }
    
private:
    std::string buildString(const std::string& str) {
        std::stack<char> stk;
        for (char ch : str) {
            if (ch == '#') {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else {
                stk.push(ch);
            }
        }
        std::string result;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
};