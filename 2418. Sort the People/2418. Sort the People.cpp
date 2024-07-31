class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        // Step 1: Create a vector of pairs (height, name)

        std::vector<std::pair<int, std::string>> people;

        for (int i = 0; i < names.size(); ++i) {

            people.emplace_back(heights[i], names[i]);

        }

        // Step 2: Sort the vector of pairs based on the height in descending order

        std::sort(people.begin(), people.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {

            return a.first > b.first;

        });
       

        // Step 3: Extract the sorted names into a result vector

        std::vector<std::string> sortedNames;

        for (const auto& person : people) {

            sortedNames.push_back(person.second);

        }

        return sortedNames;
    }
};