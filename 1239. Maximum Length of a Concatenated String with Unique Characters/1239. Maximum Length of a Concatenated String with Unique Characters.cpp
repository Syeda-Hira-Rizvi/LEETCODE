class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> filteredArr;

        for (const string& s : arr) {

            if (isUnique(s)) {

                filteredArr.push_back(s);

            }

        }

        return backtrack(filteredArr, 0, 0);

    }

private:

    bool isUnique(const string& s) {

        vector<bool> charSet(26, false);

        for (char c : s) {

            if (charSet[c - 'a']) {

                return false;

            }

            charSet[c - 'a'] = true;

        }

        return true;

    }
    int backtrack(const vector<string>& arr, int index, int bitmask) {

        if (index == arr.size()) {

            return __builtin_popcount(bitmask);

        }

        int maxLength = backtrack(arr, index + 1, bitmask);

        

        int newBitmask = getBitmask(arr[index]);

        if ((bitmask & newBitmask) == 0) {

            maxLength = max(maxLength, backtrack(arr, index + 1, bitmask | newBitmask));

        }

        

        return maxLength;

    }

    int getBitmask(const string& s) {

        int bitmask = 0;

        for (char c : s) {

            bitmask |= (1 << (c - 'a'));

        }

        return bitmask;
    }
};