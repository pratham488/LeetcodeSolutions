class Solution {
public:
    int lengthOfLastWord(string s) {
        // Find the index of the last character that isn't a space
        int end = s.find_last_not_of(' ');
        
        // Find the index of the space right before the last word
        int start = s.find_last_of(' ', end);
        
        // The length is the difference between the two indices
        return end - start;
    }
};