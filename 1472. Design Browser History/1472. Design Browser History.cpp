class BrowserHistory {
private:
    std::vector<std::string> history;
    int currentIndex;
public:
    BrowserHistory(string homepage) {
         history.push_back(homepage);
        currentIndex = 0;
    }
    
    void visit(string url) {
         // When visiting a new URL, all forward history is cleared
        history.resize(currentIndex + 1);
        history.push_back(url);
        currentIndex++;
    }
    
    string back(int steps) {
         // Move back at most `steps` steps
        currentIndex = std::max(0, currentIndex - steps);
        return history[currentIndex];
    }
    
    string forward(int steps) {
        // Move forward at most `steps` steps
        currentIndex = std::min((int)history.size() - 1, currentIndex + steps);
        return history[currentIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
 