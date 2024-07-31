class Solution {
    
    private:

    std::unordered_map<std::string, std::string> longToShort;

    std::unordered_map<std::string, std::string> shortToLong;

    const std::string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    

    std::string getRandomString() {

        std::string result;

        for (int i = 0; i < 6; ++i) {

            result += chars[rand() % chars.size()];

        }

        return result;

    }
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.find(longUrl) != longToShort.end()) {

            return "http://tinyurl.com/" + longToShort[longUrl];

        }

        std::string shortUrl;

        do {

            shortUrl = getRandomString();

        } while (shortToLong.find(shortUrl) != shortToLong.end());

        shortToLong[shortUrl] = longUrl;

        longToShort[longUrl] = shortUrl;

        return "http://tinyurl.com/" + shortUrl;

    }
    

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
            
        std::string shortKey = shortUrl.substr(shortUrl.find_last_of("/") + 1);

        return shortToLong[shortKey];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));