//https://codingbat.com/prob/p189576
#include <iostream>
#include <vector>
#include <algorithm>
int MaxSpan(std::vector<int> nums)
{
    int ans = 1;
    for (int i=0; i<nums.size(); i++)
    {
        for (int j = nums.size()-1; ; j--)
        {
            if (nums[i]==nums[j])
            {
                ans = std::max(ans, j-i+1);
                break;
            }
        }
    }
    return ans;
}
int main()
{
    std::cout<<MaxSpan({1, 2, 1, 1, 3})<<"\n";
    std::cout<<MaxSpan({1, 4, 2, 1, 4, 1, 4})<<"\n";
    std::cout<<MaxSpan({1, 4, 2, 1, 4, 4, 4})<<"\n";
    return 0;   
}