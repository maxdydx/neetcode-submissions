class Solution {
public:

    bool validPalindrome(string s) 
    {

        if(isPalindrome_helper(s)) {
            return true;
        }
        for(int i = 0; i < s.length(); i++) {
            std::string t = s;
            t.erase(i, 1);
            if(isPalindrome_helper(t)) {
                return true;
            } else {
                continue;
            }
        }
        return false;
    }
    private:
    bool isPalindrome_helper(std::string s) {
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