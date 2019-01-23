//https://techdevguide.withgoogle.com/paths/advanced/compress-decompression/#!
#include<iostream>
using namespace std;
#include<map>
#include <string>
#include <stack>
#include <algorithm>
string Decompress(string str)
{    
    stack<char> st;
    string ans;
    for(auto &i:str)
    {
        if (i!=']')
            st.push(i);
        else
        {
            string what;
            while(st.top() != '[')
            {
                what.push_back(st.top());
                st.pop();
            }
            std::reverse(what.begin(), what.end());
            st.pop();
            int count = 0;
            while(!st.empty() && st.top() >= '0' && st.top() <= '9')
            {
                count = count * 10 + st.top() -'0';
                st.pop();
            }
            if (count==0)
                count=1;
            string temp;
            while(count--)
                temp.append(what);
            for(int i = 0;i<temp.length();i++)
            st.push(temp[i]);
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    std::reverse(ans.begin() ,ans.end());
    return ans;
}

int main()
{
    std::cout<<Decompress("1[ee3[k]]")<<"\n";
    std::cout<<Decompress("3[abc]4[ab]c")<<"\n";
    std::cout<<Decompress("2[3[a]b]")<<"\n";
    return 0;
}