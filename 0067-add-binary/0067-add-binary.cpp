#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        
        // Loop runs until both strings are exhausted and no carry remains
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            
            // Subtracting '0' converts the character to an integer value
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            
            // Append the binary digit (0 or 1) to the result
            result += to_string(sum % 2);
            
            // Calculate the carry for the next bit position
            carry = sum / 2;
        }
        
        // The result is built backwards, so reverse it
        reverse(result.begin(), result.end());
        
        return result;
    }
};