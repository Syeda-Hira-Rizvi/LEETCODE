class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();

        int n = num2.size();

        std::vector<int> result(m + n, 0);

        // Reverse the strings to simulate manual multiplication from right to left

        std::reverse(num1.begin(), num1.end());

        std::reverse(num2.begin(), num2.end());

        // Multiply each digit and add the results to the result vector

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {

                result[i + j] += (num1[i] - '0') * (num2[j] - '0');

                result[i + j + 1] += result[i + j] / 10; // carry

                result[i + j] %= 10; // current digit

            }

        }

        // Find the position of the most significant non-zero digit

        int pos = m + n - 1;

        while (pos > 0 && result[pos] == 0) {

            --pos;

        }
        // Convert the result vector back to a string

        std::string product;

        for (int i = pos; i >= 0; --i) {

            product += (result[i] + '0');

        }

        return product;
    }
};