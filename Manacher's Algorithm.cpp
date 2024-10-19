class Solution {
public:
    string longestPalindrome(string s) 
    {
        string polindrome;
        int strLen = (2*s.size()) + 3;
        char* newStr = new char[strLen];

        newStr[0] = '@';
        newStr[strLen-1] = '$';

        int counterForMainString = 0;
        for (int i = 1; i < strLen - 1;) //did not include i=0 and i=strLen-1 because they are used earlier
        {
            newStr[i++] = '#';
            newStr[i++] = s[counterForMainString++];
        }

        int maxLen = 0;
        int start = 0;
        int maxRight = 0;
        int center = 0;
        int* p = new int[strLen](); //Initialize zero for all, otherwise it will give segmentation error
        
        for(int i = 1; i < strLen - 1; i++)
        {
            if (i < maxRight)
            {
                p[i] = min(maxRight - i, p[2 * center - i]); //i is radius in this case
            }

            // Expanding along the center
            while (newStr[i + p[i] + 1] == newStr[i - p[i] - 1])
            {
                p[i]++;
            }

            // Updating center and its bound
            if (i + p[i] > maxRight)
            {
                center = i;
                maxRight = i + p[i];
            }

            // Updating ans
            if (p[i] > maxLen)
            {
                start = (i - p[i] - 1) / 2;
                maxLen = p[i];
            }
        }

        polindrome = s.substr(start, maxLen);
        delete[] newStr;
        delete[] p;
        
        return polindrome;
    }
};
