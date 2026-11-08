class Solution {
public:
    bool isValid(string s) 
    {
        std::stack<char> opening_brackets;
        std::unordered_map<char, char> close_to_open = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(int i = 0; i < s.length(); i++) {

            if(close_to_open.count(s[i])) { //is it a closing bracket? if it isn't push it to stack
                if(opening_brackets.empty() || opening_brackets.top() != close_to_open[s[i]]) {

                    return false; //meaning we encountered a closing character
                    //and the stack is either empty, or the top of the stack is not the right opening character
                    
                }

                opening_brackets.pop();

            } else {

                opening_brackets.push(s[i]);

            }
        }

        return opening_brackets.empty(); 
    }
};
