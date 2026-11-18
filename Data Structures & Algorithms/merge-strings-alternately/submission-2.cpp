class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string solution_string = "";
        int counter{0};
        if(word1.length() > word2.length()) {
            counter = word1.length();
        } else if(word2.length() > word1.length()) {
            counter = word2.length();
        } else if(word1.length() == word2.length()) {
            counter = word1.length(); //doesnt really matter
        }
        if(word1.empty() && word2.empty()) {
            return solution_string;
        }
        for(int i = 0; i < counter; i++) {
            if(i < word1.length()) {
                solution_string += word1[i];
            }
            if(i < word2.length()) {
                solution_string += word2[i];
            }
        }
        return solution_string;
    }
};