class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int> st;
        int number = 0;
        int result = 0;
        int sign = 1;

        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            } else if(s[i] == '+') {
                result += number * sign; // Use += to accumulate the result
                number = 0;
                sign = 1;
            } else if(s[i] == '-') {
                result += number * sign; // Use += to accumulate the result
                number = 0;
                sign = -1;
            } else if (s[i] == '(') {
                // Push the result and sign for later use
                st.push(result);
                st.push(sign);
                // Reset result and sign for new sub-expression
                result = 0;
                sign = 1;
            } else if(s[i] == ')') {
                result += number * sign; // Update result with current number
                number = 0;
                int stack_sign = st.top(); st.pop();
                int last_result = st.top(); st.pop();
                result = last_result + stack_sign * result;
            }
        }
        
        // Final update to result
        result += number * sign;
        
        return result;
    }
};
