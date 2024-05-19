//целочисленный массив отсортиорованный в пор€дке неубывани€ удалить дубликаты на месте так, чтобы каждый уникальный элемент по€вл€лс€ только 1 раз. ѕор€док элменетов не изменный. 

#include <iostream>
#include <vector>
#include <unordered_set>

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
    //без удалени€,двум€ указател€ми
    int removeDuplicates(std::vector<int>& nums) {
    
    }
};

int main()
{
    Solution s;
    std::vector<int> nums= {1,1 };
    std::cout << s.removeDuplicatesv2(nums)<<std::endl;
    for (int n : nums)
    {
        std::cout << n << " ";
    }

}