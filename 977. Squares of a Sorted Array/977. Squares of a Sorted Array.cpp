class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> result(nums.size());
        
        // Squaring all elements
        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        
        int head = 0;
        int tail = nums.size() - 1;
        
        // Setting them at the right positions in the result array
        for(int pos = nums.size() - 1; pos >= 0; pos--) {  // Loop should go to 0
            if(nums[head] > nums[tail]) {
                result[pos] = nums[head];
                head++;
            } else {
                result[pos] = nums[tail];
                tail--;
            }
        }
        
        return result;
    }
};
