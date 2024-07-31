class Solution {
public:
    string reverseVowels(string s) {
        
        // Define the vowels

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        
        // Two pointers initialization

        int left = 0, right = s.size() - 1;

        while (left < right) {

            // Move the left pointer until we find a vowel

            while (left < right && vowels.find(s[left]) == vowels.end()) {

                left++;

            }

            // Move the right pointer until we find a vowel

            while (left < right && vowels.find(s[right]) == vowels.end()) {

                right--;
    }
            
            // Swap the vowels

            if (left < right) {

                swap(s[left], s[right]);

                left++;

                right--;

            }

        }
    
        return s;
        }
            
};