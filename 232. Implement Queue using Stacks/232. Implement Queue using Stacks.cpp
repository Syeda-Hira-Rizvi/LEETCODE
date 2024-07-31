class MyQueue {
public:
    // Constructor to initialize the queue object

    MyQueue() { 

        // No specific initialization needed for the stacks

    }

    

    // Method to push element x to the back of the queue.

    void push(int x) {

        stack1.push(x);  // Push the element onto stack1

    }

    

    // Method to remove the element from the front of the queue and return that element.

    int pop() {

        // If stack2 is empty, transfer elements from stack1 to stack2

        if (stack2.empty()) {

            while (!stack1.empty()) {

                stack2.push(stack1.top());  // Move element from stack1 to stack2

                stack1.pop();  // Remove the element from stack1

            }

        }
        
        // The top of stack2 is the front of the queue
        int frontElement = stack2.top();  
        stack2.pop();  // Remove the element from stack2
        return frontElement;  // Return the removed element
    }
    
    // Method to get the front element of the queue without removing it.
    int peek() {
        // If stack2 is empty, transfer elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());  // Move element from stack1 to stack2
                stack1.pop();  // Remove the element from stack1
            }
        }
        return stack2.top();  // Return the top element of stack2, which is the front of the queue
    }
    
    // Method to check whether the queue is empty.
    bool empty() {
        // The queue is empty if both stacks are empty
        return stack1.empty() && stack2.empty();
    }

private:
    // Two stacks to manage the queue elements
    std::stack<int> stack1;  // Stack for push operations
    std::stack<int> stack2;  // Stack for pop and peek operations
};

 

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */