//целочисленный массив отсортиорованный в пор€дке неубывани€ удалить дубликаты на месте так, чтобы каждый уникальный элемент по€вл€лс€ только 1 раз. ѕор€док элменетов не изменный. 

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
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
};

int main()
{
    Solution s;
    std::vector<int> nums= {1,1,1,2,2,3,3,4 };
    std::cout << s.removeDuplicates(nums)<<std::endl;
    for (int n : nums)
    {
        std::cout << n << " ";
    }

}