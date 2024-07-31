class Solution {
public:
    string makeGood(string s) {
        std::stack<char> st;

        

        for (char c : s) {

            if (!st.empty() && abs(st.top() - c) == 32) {

                st.pop();

            } else {

                st.push(c);

            }

        }

        

        std::string result;

        while (!st.empty()) {

            result += st.top();

            st.pop();

        }

        

        std::reverse(result.begin(), result.end());

        return result;
    }
};