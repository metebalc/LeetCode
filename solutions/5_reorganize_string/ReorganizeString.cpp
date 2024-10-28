class Solution {
public:
    string reorganizeString(string s) {
        
        std::vector<int> amountOfRepetative;
        std::vector<char> sortedString(s.begin(), s.end());
        std::sort(sortedString.begin(), sortedString.end());
        int counterForRepetition = 1;

        //Checks for the max repetition to compare with the sum
        for (int i = 1; i < sortedString.size(); ++i)
        {
            if (sortedString[i] == sortedString[i-1])
            {
                ++counterForRepetition;
            }
            else
            {
                amountOfRepetative.push_back(counterForRepetition);
                counterForRepetition = 1;
            }
        }
        amountOfRepetative.push_back(counterForRepetition);

        int sum = 0;
        for (int i = 0; i < amountOfRepetative.size(); ++i)
        {
            sum += amountOfRepetative[i];
        }

        for (int i = 0; i < amountOfRepetative.size(); ++i)
        {
            if (amountOfRepetative[i] > sum - amountOfRepetative[i] + 1)
            {
                return "";
            }
        }

        //Checks from left to right and swaps
        for (int i = 1; i < s.size() - 1; ++i)
        {
            if (s[i] == s[i-1] && s[i] != s[i+1])
            {
                char temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;

                i = 0;
            }
        }

        //Checks from right to left and swaps
        for (int i = s.size() - 2; i > 0; --i)
        {
            if (s[i] == s[i+1] && s[i] != s[i-1])
            {
                char temp = s[i];
                s[i] = s[i-1];
                s[i-1] = temp;

                i = s.size() - 1;
            }
        } 

        return s;
    }
};
