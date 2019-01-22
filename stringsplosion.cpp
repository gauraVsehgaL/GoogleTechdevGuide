//https://codingbat.com/prob/p117334

#include <iostream>

std::string StringSplosion(std::string str)
{
    std::string ans;
    for (auto i=0; i<=str.length(); i++)
        ans.append(str.substr(0,i));
    return ans;
}
int main()
{
    std::cout<<StringSplosion("Code");
    return 0;   
}