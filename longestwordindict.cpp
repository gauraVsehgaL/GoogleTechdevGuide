//https://techdevguide.withgoogle.com/paths/foundational/find-longest-word-in-dictionary-that-subsequence-of-given-string/#!
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include<algorithm>
#include <climits>
using namespace std;
string find_longest_word_in_string(string letters, std::vector<string> words)
{
    std::map<char, vector<int>> mapping;
    for(int i=0; i<letters.length(); i++)
        mapping[letters[i]].push_back(i);
    
    std::sort(words.begin(), words.end(), [](auto &word1, auto &word2){return word1.length() >= word2.length();});
    
    int prev=INT_MIN;
    bool broke;
    for(auto &word : words)
    {
        broke = false;
        for (auto &letter : word)
        {
            auto it = std::lower_bound(mapping[letter].begin(), mapping[letter].end(), prev);
            if (it==mapping[letter].end() || it-1 == mapping[letter].end())
            {
                broke = true;
                break;
            }
            prev = *(it-1);
        }
        if (!broke)
            return word;
    }
    
    return "";
}
int main()
{
    string letters = "abppplee";
    std::vector<string> words{"able", "ale", "apple", "bale", "kangaroo"};
    std::cout<<find_longest_word_in_string(letters, words);
}