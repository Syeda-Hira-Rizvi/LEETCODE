class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = std::numeric_limits<int>::max(); // Initialize to a large number

        int max_profit = 0;

        

        for (int price : prices) {

            if (price < min_price) {

                min_price = price; // Update minimum price encountered so far

            } else {

                int potential_profit = price - min_price;

                if (potential_profit > max_profit) {

                    max_profit = potential_profit; // Update maximum profit if better profit found

                }

            }

        }
 

        return max_profit;
    }
};