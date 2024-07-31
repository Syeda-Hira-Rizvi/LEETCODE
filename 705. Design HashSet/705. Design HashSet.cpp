class MyHashSet {
     private:
    static const int BUCKET_COUNT = 1000; // You can choose a larger number for better distribution
    std::vector<std::list<int>> buckets;

    int hashFunction(int key) {
        return key % BUCKET_COUNT;
    }
      
public:
    MyHashSet() : buckets(BUCKET_COUNT) {}
    
    
    void add(int key) {
         int bucketIndex = hashFunction(key);
        auto& bucket = buckets[bucketIndex];
        for (const int& k : bucket) {
            if (k == key) return; // Key already present
        }
        bucket.push_back(key); // Add key if not present
    }
    
    void remove(int key) {
        int bucketIndex = hashFunction(key);
        auto& bucket = buckets[bucketIndex];
        bucket.remove(key); // Remove the key if present, does nothing if key is not found
    }
    
    bool contains(int key) {
         int bucketIndex = hashFunction(key);
        const auto& bucket = buckets[bucketIndex];
        for (const int& k : bucket) {
            if (k == key) return true; // Key found
        }
        return false; // Key not found
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */