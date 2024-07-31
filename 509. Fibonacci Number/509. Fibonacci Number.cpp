class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0; // Base case for F(0)

        if (n == 1) return 1; // Base case for F(1)

        
        int a = 0; // F(0)

        int b = 1; // F(1)

        int c; // This will store the Fibonacci number

        

        for (int i = 2; i <= n; ++i) {

            c = a + b; // F(n) = F(n-1) + F(n-2)

            a = b; // Move to the next pair

            b = c; // Move to the next pair

        }

        return c; // F(n)
    }
};