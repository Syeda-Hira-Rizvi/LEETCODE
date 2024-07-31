class Solution {
public:
    double average(vector<int>& salary) {
        // Edge case: If the salary array has less than 3 elements, return 0.0

        if(salary.size() < 3) return 0.0;
        

        int minSalary = INT_MAX, maxSalary = INT_MIN;

        int sum = 0;
        

        // Calculate the total sum and find the min and max salaries

        for(int s : salary) {

            sum += s;

            if(s < minSalary) minSalary = s;

            if(s > maxSalary) maxSalary = s;

        }
        

        // Subtract the minimum and maximum salaries from the total sum

        sum -= (minSalary + maxSalary);
        

        // Calculate the average by dividing by the number of elements excluding the min and max

        double averageSalary = (double)sum / (salary.size() - 2);
      

        return averageSalary;
    }
};