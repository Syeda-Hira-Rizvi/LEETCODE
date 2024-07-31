class Solution {
public:
    string removeDuplicates(string s) {
        std::stack<char> st;

        

        for (char c : s) {

            if (!st.empty() && st.top() == c) {

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