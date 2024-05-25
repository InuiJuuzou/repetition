//целочисленный массив отсортиорованный в порядке неубывания удалить дубликаты на месте так, чтобы каждый уникальный элемент появлялся только 1 раз. Порядок элменетов не изменный. 

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

#pragma execution_character_set("utf-8")

class Solution {
public:
    int removeDuplicatesv1(std::vector<int>& nums) {
        std::unordered_set<int> tmp;
        size_t size_num = nums.size();
        for (int i=0;i<size_num;)
        {
            if (!tmp.empty() && tmp.find(nums[i]) != tmp.end())
            {
                int n = nums[i];
                nums.erase(nums.begin() + i);
               // nums.push_back(n);
                --size_num;
                continue;
            }
            tmp.insert(nums[i]);
            ++i;
        }

        return size_num;
    }
    int removeDuplicatesv2(std::vector<int>& nums) {
        size_t size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            int k = i+1;
            int count = 0;
            if (k >= size)
            {
                break;
            }
            while (k < size && nums[i] == nums[k])
            {
                ++count;
                ++k;
            }
            if (count >1)
            {
                nums.erase(nums.begin() + i, nums.begin() + i + count);
                size -= count;
                continue;
            }
            if (count == 1)
            {
                nums.erase(nums.begin() + i + count);
                --size;
            }

            
        }
        return size;
    }
    //без удаления,двумя указателями
    int removeDuplicates(std::vector<int>& nums) {
        size_t size = nums.size();
        
        int i = 0;//текущий элемент в массиве
        int k = 1;//уникальный элемент
        int count = 1;//количество уникальных элементов как минимум 1 есть всегда

        for (; i < size && k<size; ++i)
        {
            while (k < size)
            {
                if (nums[i] < nums[k])
                {
                    std::swap(nums[i + 1], nums[k]);
                    ++count;
                    break;
                }
                ++k;
            }
            if (k == size - 1 && nums[k]==nums[i])
                break;

        }


        return count;

    }
};

void Test()
{
    Solution s;
    {
        std::vector<int> nums = { 1,1,1,1,1,1 };
        assert(s.removeDuplicates(nums) == 1);
        std::vector<int> answer = { 1 };
        for (int i = 0; i < s.removeDuplicates(nums); ++i)
        {
            assert(answer[i] == nums[i]);
        }
    }
    {
        std::vector<int> nums = { 1};
        assert(s.removeDuplicates(nums) == 1);
    }
    {
        std::vector<int> nums = { 1,2,3 };
        assert(s.removeDuplicates(nums) == 3);

    }
    {
        std::vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
        int count = s.removeDuplicates(nums);
        assert(count == 5);

        std::vector<int> answer = {0,1,2,3,4 };
        for (int i = 0; i < count; ++i)
        {
            assert(answer[i] == nums[i]);
        }
    }
    std::cout << "DONE!" << std::endl;

}

int main()
{
    Test();
   
}