class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Early return if sizes do not match

        if (s.size() != t.size()) {

            return false;

        }

        // Arrays to store last seen positions

        int last_seen_s[256] = {0};

        int last_seen_t[256] = {0};

        for (int i = 0; i < s.size(); ++i) {

            char char_s = s[i];

            char char_t = t[i];

            // Check if last seen positions match

            if (last_seen_s[char_s] != last_seen_t[char_t]) {

                return false;

            }

            // Update the last seen positions (use i+1 to avoid conflict with default 0)

            last_seen_s[char_s] = i + 1;

            last_seen_t[char_t] = i + 1;

        }
       return true;
    }
};