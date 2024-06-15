#include <iostream>
#include <vector>
#include <string>



class Solution {
private:
    void add_capital_letter(std::vector<std::string>& result)
    {

    }
    
    void add_small_letter(std::vector<std::string>& result)
    {

    }
public:
    std::vector<std::string> letterCasePermutation(std::string s) 
    {
        if (s.empty())
            return {};

        std::vector<std::string> result;

        for (char& c : s)
        {
            //letter
            if ((c >= 'a' && c <= 'z'))
            {
                if (result.empty())
                {
                    std::string str ="";
                    str += c;
                    result.push_back(str);
                    str = "";
                    str += std::toupper(c);
                    result.push_back(str);
                    continue;
                }

                size_t size = result.size();
                //удваиваем набор
                for (size_t i = 0; i < size; ++i)
                {
                    result.push_back(result[i]);
                }
                //Добавляем маленькие буквы к половине и большие к второй
                for (size_t i = 0; i < result.size(); ++i)
                {
                    if (i < result.size() / 2)
                    {
                        result[i] += c;
                    }
                    else
                    {
                        result[i] += std::toupper(c);
                    }
                }
            }
            else if ((c >= 'A' && c <= 'Z'))
            {
                if (result.empty())
                {
                    std::string str = "";
                    str += c;
                    result.push_back(str);
                    str = "";
                    str += std::tolower(c);
                    result.push_back(str);
                    continue;
                }

                size_t size = result.size();
                //удваиваем набор
                for (size_t i = 0; i < size; ++i)
                {
                    result.push_back(result[i]);
                }
                //Добавляем маленькие буквы к половине и большие к второй
                for (size_t i = 0; i < result.size(); ++i)
                {
                    if (i < result.size() / 2)
                    {
                        result[i] += c;
                    }
                    else
                    {
                        result[i] += std::tolower(c);
                    }
                }
            }
            //number
            else
            {
                if (result.empty())
                {
                    std::string tmp = "";
                    tmp += c;
                    result.push_back(tmp);
                    continue;
                }
                for (int i =0; i< result.size();++i)
                {
                    result[i] += c;
                }
            }

        }
        return result;
    }
};

using namespace std;
int main()
{
    Solution s;
    string str = "a1b2";
    vector<string> result = s.letterCasePermutation(str);

    for (auto& r : result)
    {
        cout << r << " ";
    }

}