class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        //array of integers (ASTEROIDS!)
        //the absolute value represents the size
        //sign represents direction (+ or -)
        //+ is right, - is left
        //each asteroid have the same speed = modulus(velocity_vector);
        //
        /*
        for(int i = 0; i < asteroids.size(); i++) 
        {
            if(i == asteroids.size() - 1) {
                //do this later
                if((asteroids[i] < 0) && asteroids[i-1] > 0) {
                    if(std::abs(asteroids[i]) == std::abs(asteroids[i-1])) {
                        asteroids.erase(asteroids.begin() + i);
                        asteroids.erase(asteroids.begin() + i - 1);
                    } else {
                        if(std::abs(asteroids[i]) < std::abs(asteroids[i-1])) {
                            asteroids.erase(asteroids.begin() + i);
                        } else {
                            asteroids.erase(asteroids.begin() + i - 1);
                        }
                    }
                }
            } else { //meaning we have two proper asteroids to inspect
            //i dont want seg faults
                int some_asteroid = asteroids[i];
                int some_other_asteroid = asteroids[i + 1];
                if((some_asteroid > 0) && (some_other_asteroid < 0)) {
                    if(std::abs(some_asteroid) == std::abs(some_other_asteroid)) {
                        asteroids.erase(asteroids.begin() + i);
                        asteroids.erase(asteroids.begin() + i);
                    } else if(std::abs(some_asteroid) > std::abs(some_other_asteroid)) {
                        asteroids.erase(asteroids.begin() + i + 1);
                    } else {
                        asteroids.erase(asteroids.begin() + i);
                    }
                } else {
                    continue;
                }

            }
            return asteroids;
        }

        */
        std::stack<int> my_stack;
        vector<int> solution_vec;
        my_stack.push(asteroids[0]);
        int i = 1;
        while(i < asteroids.size()) {
            int curr_asteroid = asteroids[i];
            int magnitude = std::abs(curr_asteroid);
            bool going_left = curr_asteroid < 0;
            bool going_right = curr_asteroid > 0;

            if(my_stack.empty()) {
                my_stack.push(curr_asteroid);
                i++;
                continue;
            }
            
            int other_asteroid = my_stack.top();
            int other_magnitude = std::abs(other_asteroid);
            bool other_going_left = other_asteroid < 0;
            bool other_going_right = other_asteroid > 0;

            
            if(going_left && other_going_right) {
                if(magnitude == other_magnitude) {
                    my_stack.pop();
                    i++;
                    continue;
                } else if(magnitude > other_magnitude) {
                    my_stack.pop();
                    continue;
                } else {
                    i++;
                    continue;
                }
            } else if((going_right && other_going_right) || (going_left && other_going_left)) {
                my_stack.push(curr_asteroid);
                i++;
                continue;
            } else if(going_right && other_going_left) {
                my_stack.push(curr_asteroid);
                i++;
                continue;
            }

        }

        while(!my_stack.empty()) {
            int val = my_stack.top();
            my_stack.pop();
            solution_vec.push_back(val);
        }
        std::reverse(solution_vec.begin(), solution_vec.end());
        return solution_vec;

    }
};