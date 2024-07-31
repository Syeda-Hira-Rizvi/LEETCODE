class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) { 

    // Calculate the frequency of each number

   int count[102] = {0}; //this will initialize all elements to 0. static array initialization,  used when size is fixed.
        
    for (int num : nums) {

      count[num]++;

    }

    int totalCount = 0;

    // Caclulate total number of pairs possible

    for (int i : count) {

      totalCount += ((i) * (i-1))/2;

    }

    return totalCount;   
    }
};