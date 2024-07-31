class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       // Start with the first position

    int insertPosition = 0;

    for (int i = 0; i < nums.size(); i++) {

        // Fill all non-zero numbers

        if (nums[i] != 0) {

            nums[insertPosition] = nums[i];

            insertPosition++;

        }

    }

    while (insertPosition < nums.size()) {

        nums[insertPosition++] = 0;

    } 
    }
};