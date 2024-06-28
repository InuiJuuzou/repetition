#include<iostream>
#include <string>
#include <cassert>

using namespace std;

#pragma execution_character_set("utf-8")

class Solution {
public:
    //мое решение
    int strStrMy(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;

        int index = -1;
        int i = 0;//индекс для проода по needle
        for (int k = 0 ; k < haystack.size() ; ++k)
        {
            if (haystack[k] == needle[i])
            {
                if (i == 0)
                {
                    index = k;
                }
                ++i;
                continue;
            }
            if (i == needle.size()) break;
            index != -1 ? k = index  : k = k;
           // k = index + 1;
            index = -1;
            i = 0;
        }
        if (i < needle.size()) return -1;
        return index;
    }
    //подсмотренное решение
    int strStr(string haystack, string needle) {
        size_t size = needle.size();
        for (int i = 0; i < haystack.size(); ++i)
        {
            string str = haystack.substr(i, size);
            if (str == needle)
            {
                return i;
            }
        }
        return -1;
    }
};

void Test()
{
    Solution s;
    {
        string  haystack = "sadbutsad", needle = "sad";
        assert(s.strStr(haystack, needle) == 0);
        cout << "Test 1 - ok" << endl;
    }
    {
        string haystack = "leetcode", needle = "leeto";
        assert(s.strStr(haystack, needle) == -1);
        cout << "Test 2 - ok" << endl;
    }
    {
        string haystack = "aaa", needle = "aaaa";
        assert(s.strStr(haystack, needle) == -1);
        cout << "Test 3 - ok" << endl;
    }
    {
        string haystack = "mississippi", needle = "issip";
        assert(s.strStr(haystack, needle) == 4);
        cout << "Test 4 - ok" << endl;
    }
    {
        string haystack = "mississippi", needle = "issipi";
        assert(s.strStr(haystack, needle) == -1);
        cout << "Test 5 - ok" << endl;
    }
    {
        string haystack = "ippi", needle = "pi";
        assert(s.strStr(haystack, needle) == 2);
        cout << "Test 6 - ok" << endl;
    }
    cout << "DONE\n";
}

int main()
{
    Test();
}