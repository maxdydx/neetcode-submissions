class Solution {
public:
    bool isPalindrome(string s) {
        //we first need to filter
        if(s.empty()) { //empty string is a palindrome
            return true;
        }

        std::erase_if(s, [](unsigned char my_char) {
            return !std::isalnum(my_char);
        });
        for(char& c : s) {
            c = std::tolower(static_cast<unsigned char>(c));
        }


        std::string t = s;
        std::reverse(t.begin(), t.end());
        return s == t;
    }

};
    
