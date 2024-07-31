class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, bool> jewelMap;

        // Fill the hashmap with jewels

        for (char jewel : jewels) {

            jewelMap[jewel] = true;

        }

        int count = 0;

        // Check each stone if it is a jewel

        for (char stone : stones) {

            if (jewelMap.find(stone) != jewelMap.end()) {

                count++;

            }

        }

        return count;
    }
};