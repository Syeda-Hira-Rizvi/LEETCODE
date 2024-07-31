class MyHashMap {
    
    private:
    struct Node {
        int key;
        int value;
        Node* next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    
    const int size = 10000; // Size of the array
    std::vector<Node*> buckets; // Array of pointers to Node
    
    // Simple hash function
    int hash(int key) {
        return key % size;
    }
    
    // Helper function to find a node with a given key in a chain
    Node* find(Node* head, int key) {
        Node* curr = head;
        while (curr && curr->key != key) {
            curr = curr->next;
        }
        return curr;
    }
    
public:
    
   MyHashMap() {
        buckets.resize(size, nullptr); // Initialize buckets array with nullptr
    }
    
    void put(int key, int value) {
        int index = hash(key);
        if (buckets[index] == nullptr) {
            // If no nodes exist at this index, create new node
            buckets[index] = new Node(key, value);
        } else {
            // If there's already a chain, find if the key exists
            Node* prev = find(buckets[index], key);
            if (prev) {
                // Key found, update its value
                prev->value = value;
            } else {
                // Key not found, insert at the beginning of the chain
                Node* newNode = new Node(key, value);
                newNode->next = buckets[index];
                buckets[index] = newNode;
            }
        
    }
    }
    
    int get(int key) {
        int index = hash(key);
        Node* node = find(buckets[index], key);
        if (node) {
            return node->value;
        } else {
            return -1;
        }
    }
    
    void remove(int key) {
        int index = hash(key);
        Node* head = buckets[index];
        if (!head) {
            return; // No nodes in the chain
        }
        
        if (head->key == key) {
            // Key is at the head of the chain
            buckets[index] = head->next;
            delete head;
        } else {
            // Key could be in the middle or end of the chain
            Node* prev = head;
      while (prev->next && prev->next->key != key) {
                prev = prev->next;
            }
            if (prev->next) {
                // Found the node, remove it
                Node* toDelete = prev->next;
                prev->next = toDelete->next;
                delete toDelete;
            }
        }
    }
    
    ~MyHashMap() {
        // Clean up all allocated nodes
        for (int i = 0; i < size; ++i) {
            Node* curr = buckets[i];
            while (curr) {
                Node* toDelete = curr;
                curr = curr->next;
                delete toDelete;
            }
        }
    }
};     
       
    

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */