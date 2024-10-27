class Solution {
public:
    int myAtoi(string s) {
        int i = 0, size = s.size();
        int sign = 1;
        int result = 0;

        // Skip leading whitespaces
        while (i < size && s[i] == ' ')
        {
            ++i;
        }

        if (i < size && (s[i] == '+' || s[i] == '-')) 
        {
            sign = (s[i] == '-') ? -1 : 1;
            ++i;
        }

        // Convert digits to integer
        while (i < size && s[i] >= '0' && s[i] <= '9') 
        {
            int digit = s[i] - '0';

            // Check for overflow/underflow before updating result
            if (result > (INT_MAX - digit) / 10) 
            {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            ++i;
        }

        return result * sign;
    }
};
