#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        size_t size = nums.size();

        if (size == 1) return;

        //int min_index = nums[0] == 0? 1:0;
        int min_index = 0;
        int max_index = size - 1;

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == 0)
            {
                std::swap(nums[i], nums[min_index]);
                ++min_index;
            }
            if (nums[i] == 2 && i<size/2)
            {
                
                std::swap(nums[i], nums[max_index]);
                --max_index;
            }
        }
    }
};

void Test()
{
    Solution s;
    {
        std::vector<int> nums = { 2,0,2,1,1,0 };
        s.sortColors(nums);
        std::vector<int> answer = { 0,0,1,1,2,2 };
        assert(nums == answer);
    }
    {
        std::vector<int> nums = { 2,0,1 };
        s.sortColors(nums);
        std::vector<int> answer = { 0,1,2 };
        assert(nums == answer);
    }
    {
        std::vector<int> nums = { 0 };
        s.sortColors(nums);
        std::vector<int> answer = { 0 };
        assert(nums == answer);

    }
    {
        std::vector<int> nums = { 0,0 };
        s.sortColors(nums);
        std::vector<int> answer = { 0,0 };
        assert(nums == answer);
    }
    {
        std::vector<int> nums = { 0,2,1 };
        s.sortColors(nums);
        std::vector<int> answer = { 0,1,2 };
        assert(nums == answer);
    }

}

int main()
{
    Solution s;
    std::vector<int> nums = { 0,2,1 };
    s.sortColors(nums);

    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << " ";
    }
    //Test();
}
