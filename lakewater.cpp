//https://techdevguide.withgoogle.com/paths/advanced/volume-of-water/#!
#include<iostream>
#include<vector>
#include <climits>
using namespace std;
int LakeWater(vector<int> height)
{
    if(height.size()==0)
        return 0;
    vector<int> left(height.size(),INT_MIN);
    vector<int> right(height.size(),INT_MIN);
    int maxl = height[0];
    int maxr = height[height.size()-1];
    for (int i =1;i<height.size();i++)
    {
        left[i]=maxl;
        maxl = max(maxl, height[i]);
    }
    for (int i =height.size()-2;i>=0;i--)
    {
        right[i]=maxr;
        maxr = max(maxr, height[i]);
    }

    int sum=0;
    for(int i =1;i<height.size();i++)
    {   
        if (left[i]==INT_MIN || right[i]==INT_MIN)
            continue;
        int what = min(left[i], right[i])-height[i];
        if(what>=0)
            sum+=what;
    }
    return sum;
}

int main()
{
    std::cout<<LakeWater({1,3,2,4,1,3,1,4,5,2,2,1,4,2,2});
    
    return 0;
}
