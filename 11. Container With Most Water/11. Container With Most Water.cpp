class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;  // Starting pointer at the beginning

        int right = height.size() - 1;  // Starting pointer at the end

        int max_area = 0;  // Variable to store the maximum area found

        

        while (left < right) {

            // Calculate the width and height for the current pair of pointers

            int width = right - left;

            int container_height = std::min(height[left], height[right]);

            int current_area = width * container_height;

            

            // Update the maximum area if the current area is larger

            max_area = std::max(max_area, current_area);

            

            // Move the pointer that points to the shorter line inward

            if (height[left] < height[right]) {

                left++;

            } else {

                right--;

            }

        }

        

        return max_area;
    }
};