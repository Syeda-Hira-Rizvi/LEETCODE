class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
       int left = 0;

        int right = arr.size() - 1;

        

        while (left < right) {

            int mid = left + (right - left) / 2;

            
            if (arr[mid] < arr[mid + 1]) {

                // We are in the increasing part of the mountain

                left = mid + 1;

            } else {

                // We are in the decreasing part of the mountain

                right = mid;

            }

        }
      

        // At this point, left == right, which is the peak index

        return left; 
    }
};s