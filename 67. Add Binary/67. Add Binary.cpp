class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;

        int j = b.size() - 1;

        int carry = 0;

        string result = "";

        
        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            if (i >= 0) {

                sum += a[i] - '0'; // Convert char to int

                i--;

            }

            if (j >= 0) {

                sum += b[j] - '0'; // Convert char to int

                j--;

            }
         

            result += (sum % 2) + '0'; // Append current digit to result

            carry = sum / 2;           // Compute new carry

        }
 
        reverse(result.begin(), result.end()); // Reverse the result to get the correct order

        return result;
    }
};