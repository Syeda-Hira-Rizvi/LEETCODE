class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Initialize a queue to store the students' preferences

        std::queue<int> studentQueue;

        // Push each student's preference into the queue

        for (int student : students) {

            studentQueue.push(student);

        }

        

        // Initialize the index for sandwiches and a count for unmatched attempts

        int i = 0;

        int count = 0;

        // Continue processing until the queue of students is empty

        while (!studentQueue.empty()) {

            // Check if the front student matches the top sandwich

            if (studentQueue.front() == sandwiches[i]) {

                // Student takes the sandwich, so remove the student and move to the next sandwich

                studentQueue.pop();

                i++;

                // Reset the unmatched count because a student took a sandwich

                count = 0;

            } else {
                // If the student doesn't take the sandwich, move them to the end of the queue
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                // Increment the unmatched count
                count++;
            }
            
            // Check if all students have cycled through without taking the top sandwich
            if (count == studentQueue.size()) {
                // If true, return the number of students left in the queue
                return count;
            }
        }
        
        // If we exit the loop, it means all students got their sandwiches
        return 0;
    }
};