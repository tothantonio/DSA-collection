#include <iostream>
#include <string>

using namespace std;

class Solution
{
private:
    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    string reverseVowels(string s)
        //Time: O(n) - lenght of s
    {
        int i = 0, j = s.length() - 1;

        while (i < j)
        {
            while (i < j && !isVowel(s[i]))
            {
                i++;
            }

            while (i < j && !isVowel(s[j]))
            {
                j--;
            }

            if (i < j)
            {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;

                i++;
                j--;
            }
        }
        return s;
    }
};

int main()
{

    Solution s;
    string str = "leetcode";

    cout << s.reverseVowels(str) << endl;
    return 0;
}