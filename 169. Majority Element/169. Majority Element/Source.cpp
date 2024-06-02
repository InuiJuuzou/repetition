#include<vector>
#include<iostream>
#include<cassert>
#include<unordered_map>
#include<random>

class Solution {
private:

public:
    //мое решение 2
    int majorityElementv1(std::vector<int>& nums) {
        std::unordered_map<int, int> counter;
        size_t size = nums.size();
        for (const int n : nums)
        {
            ++counter[n];
            if (counter[n] > size/2)
            {
                return n;
            }
        }

        return 1;
    }

    //мой вариант
    int majorityElement(std::vector<int>& nums)
    {
        std::unordered_map<int, int> counter;
        size_t size = nums.size();
        for (const int n : nums)
        {
            ++counter[n];
        }
        int max = counter[nums[0]];
        int answer = nums[0];
        for (auto c : counter)
        {
            if (c.second > max)
            {
                max = c.second;
                answer = c.first;
            }
        }

        return answer;
    }

    //вероятностный подход
    int majorityElementVer(std::vector<int>& nums)
    {
        size_t half_size = nums.size() / 2;

        std::random_device random_device;//источник энтроприи
        std::mt19937 generator(random_device());//Генератор случайных чисел
        std::uniform_int_distribution<> distribition(0, nums.size() - 1);// Равномерное распределение

        while (true)
        {
            int random_index = distribition(generator);//получаем рандомный индекс
            int count_n = 0;

            for (const int& n : nums)
            {
                if (n == nums[random_index])
                {
                    ++count_n;
                }
            }

            if (count_n > half_size)
            {
                return nums[random_index];
            }
        }
    }
    //Алгоритм большенства голосов Бойера-Мура
    int majorityElementBM(std::vector<int>& nums)
    {
        size_t size = nums.size();
        int max_n = nums[0];
        int count = 1;

        for (int i = 1; i < size; ++i)
        {
            if (count == 0)
            {
                max_n = nums[i];
                count = 1;
                continue;
            }

            if (max_n == nums[i])
            {
                ++count;

            }
            else if (max_n != nums[i])
            {
                --count;
            }

        }

        return max_n;
    }
};

void Test()
{
    Solution s;
    //обычные
    {
        std::vector<int> nums = { 2,2,1,1,1,2,2 };
        assert(s.majorityElement(nums) == 2);
    }
    {
        std::vector<int> nums = { 2,2,1,1,1,2,2 };
        assert(s.majorityElementv1(nums) == 2);
    }
    {
        std::vector<int> nums = { 3,2,3 };
        assert(s.majorityElement(nums) == 3);
    }
    //вероятностный
    {
        std::vector<int> nums = { 2,2,1,1,1,2,2 };
        assert(s.majorityElementVer(nums) == 2);
    }
    {
        std::vector<int> nums = { 3,2,3 };
        assert(s.majorityElementVer(nums) == 3);
    }
    //Бойера-Мура
    {
        std::vector<int> nums = { 2,2,1,1,1,2,2 };
        assert(s.majorityElementBM(nums) == 2);
    }
    {
        std::vector<int> nums = { 3,2,3 };
        assert(s.majorityElementBM(nums) == 3);
    }
    {
        std::vector<int> nums = { 1,3,1,1,4,1,1,5,1,1,6,2,2 };
        assert(s.majorityElementBM(nums) == 1);
    }
    std::cout << "DON!";

}

int main()
{
    Test();
}