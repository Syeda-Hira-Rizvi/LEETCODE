class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
   bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end()) {
            return false;
        }
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        auto it = valToIndex.find(val);
        if (it == valToIndex.end()) {
            return false;
        }
        int lastElement = nums.back();
        nums[it->second] = lastElement;
        valToIndex[lastElement] = it->second;
        nums.pop_back();
        valToIndex.erase(it);
        return true;
    }
    int getRandom() {

        int randomIndex = rand() % nums.size();

        return nums[randomIndex];

    }

private:

    std::vector<int> nums;

    std::unordered_map<int, int> valToIndex;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */