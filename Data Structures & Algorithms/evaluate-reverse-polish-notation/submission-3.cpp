class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        std::stack<int> my_stack;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int val1 = my_stack.top();
                my_stack.pop();
                int val2 = my_stack.top();
                my_stack.pop();
                int sum = val1 + val2;
                my_stack.push(sum);
            } else if(tokens[i] == "-") {
                int val1 = my_stack.top();
                my_stack.pop();
                int val2 = my_stack.top();
                my_stack.pop();
                int diff = val2 - val1;
                my_stack.push(diff);
            } else if(tokens[i] == "*") {
                int val1 = my_stack.top();
                my_stack.pop();
                int val2 = my_stack.top();
                my_stack.pop();
                int product = val1 * val2;
                my_stack.push(product);
            } else if(tokens[i] == "/") {
                int val1 = my_stack.top();
                my_stack.pop();
                int val2 = my_stack.top();
                my_stack.pop(); 
                int quotient = val2 / val1;
                my_stack.push(quotient);
            } else {
                my_stack.push(std::stoi(tokens[i]));
            }
        }

        return my_stack.top();

    }
};
