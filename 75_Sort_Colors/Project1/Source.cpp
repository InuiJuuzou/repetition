#include <iostream>
#include <vector>
#include <cassert>

class Solution {
public:
    //попытка первая не рабочая
    void sortColorsv1(std::vector<int>& nums) {
        size_t size = nums.size();

        if (size == 1) return;

        int min_index = 0;
        int max_index = size - 1;

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == 0)
            {
                std::swap(nums[i], nums[min_index]);
                ++min_index;
            }
            if (nums[i] == 2 && i < size / 2)
            {

                std::swap(nums[i], nums[max_index]);
                --max_index;
            }
        }
    }
    //попытка вторая
    void sortColorsv2(std::vector<int>& nums) {
        size_t size = nums.size();
        if (size == 1) return;
        int min_index = 0;
        int max_index = size - 1;
        //проходим в прямом порядке
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == 0)
            {
                std::swap(nums[i], nums[min_index]);
                ++min_index;
            }
        }
        //проходим в обратном порядке
        for (int k = size - 1; k >= 0; --k)
        {
            if (nums[k] == 2)
            {
                std::swap(nums[k], nums[max_index]);
                --max_index;
            }
        }

    
    }

    //сортировку подсчетом(подсказка 1)
    void sortColors(std::vector<int>& nums)
    {
        std::vector<int> temp_counter = { 0,0,0 };

        size_t size = nums.size();
        //подсчет количества элементов от 0 до 2 в массиве
        for (int i = 0; i < size; ++i)
        {
            ++temp_counter[nums[i]];
        }
        int pos = 0;
        for (int i = 0; i < 3; ++i)
        {
            for (int k = 0; k < temp_counter[i]; ++k)
            {
                nums[pos] = i;
                ++pos;
            }
        }
    }
};

void Test()
{
    Solution s;
    {
        std::vector<int> nums = { 0,2,2,0,1,1 };
        s.sortColors(nums);
        std::vector<int> answer = { 0,0,1,1,2,2 };
        assert(nums == answer);
    }
    {
        std::vector<int> nums = { 0,0,0};
        s.sortColors(nums);
        std::vector<int> answer = { 0,0,0 };
        assert(nums == answer);
    }
    {
        std::vector<int> nums = { 1,1 };
        s.sortColors(nums);
        std::vector<int> answer = { 1,1 };
        assert(nums == answer);
    }
    {
        std::vector<int> nums = { 0,2,1 };
        s.sortColors(nums);
        std::vector<int> answer = { 0,1,2 };
        assert(nums == answer);
    }
    {
        std::vector<int> nums = { 2,2,2,2 };
        s.sortColors(nums);
        std::vector<int> answer = { 2,2,2,2 };
        assert(nums == answer);
    }
    {
        std::vector<int> nums = { 0 };
        s.sortColors(nums);
        std::vector<int> answer = { 0 };
        assert(nums == answer);
    }
    std::cout << "DONE!" << std::endl;
}

int main()
{
    //Test();
    Solution s;
    std::vector<int> nums = { 1,0,2 };
    s.sortColorsv2(nums);

    for (int i = 0; i < nums.size(); ++i)
    {
        std::cout << nums[i] << " ";
    }

}