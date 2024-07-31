class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        std::unordered_map<int, int> nextGreaterMap;
        std::stack<int> s;
        
        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int current = nums2[i];
            
            // Maintain elements in the stack such that the top is always the next greater element
            while (!s.empty() && s.top() <= current) {
                s.pop();
            }
            
            // If stack is not empty, the top element is the next greater element for current
            nextGreaterMap[current] = s.empty() ? -1 : s.top();
            
            // Push the current element onto the stack
            s.push(current);
        }
            // Prepare the result based on nums1

        std::vector<int> result;

        for (int num : nums1) {

            result.push_back(nextGreaterMap[num]);

        }

        

        return result;
    }
};