class Solution {
public:
    bool isHappy(int n) {
        auto sumOfSquares = [](int num) {

            int sum = 0;

            while (num > 0) {

                int digit = num % 10;

                sum += digit * digit;

                num /= 10;

            }

            return sum;

        };

        

        int slow = n;

        int fast = sumOfSquares(n);

        

        while (fast != 1 && slow != fast) {

            slow = sumOfSquares(slow);

            fast = sumOfSquares(sumOfSquares(fast));

        }

        

        return fast == 1;

    
    }
};