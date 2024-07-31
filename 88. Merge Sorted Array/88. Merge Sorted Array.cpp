class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; // Pointer for nums1

        int j = n - 1; // Pointer for nums2

        int k = m + n - 1; // Pointer for merged array in nums1

        // Merge in reverse order

        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {

                nums1[k] = nums1[i];

                i--;

            } else {

                nums1[k] = nums2[j];

                j--;

            }

            k--;

        }

        // If nums2 is not exhausted

        while (j >= 0) {

            nums1[k] = nums2[j];

            k--;

            j--;

        }
        // No need to check for remaining nums1 elements because they are already in place
    }
};