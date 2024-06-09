#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class Solution {
private:
    std::unordered_map<char, std::string> CreationKeyboard() {
        std::string litters = "abcdefghijklmnopqrstuvwxyz";
        std::unordered_map<char, std::string> keyboard;

        int index = 0;
        for (char c = '2'; c <= '9'; ++c)
        {
            std::string str = "";
            if (c == '7' || c == '9')
            {
                str = litters.substr(index, 4);
                index += 4;
                keyboard[c] = str;
                continue;
            }
            str = litters.substr(index, 3);
            index += 3;
            keyboard[c] = str;
        }

        return keyboard;
    }
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        
        if (digits.empty())
        {
            return result;
        }
        
        //---------------------------------------------------
        //Формирование клавиатуры
        std::unordered_map<char, std::string> keyboard = CreationKeyboard();
        //------------------------------------------------

       
        return result;
    }
};

int main()
{
    using namespace std;
    Solution s;
    s.letterCombinations("23");
}