#include <iostream>
#include <string>
#include <bitset>
using namespace std;
const string mp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
string s, bins;
int main()
{
    cin>>s;
    for(int i=0;i<s.length();i++)
        bins += bitset<8>(s[i]).to_string();
    while(bins.length()%5) bins.push_back('0');
    for(int i=0;i<bins.length();i+=5)
        cout<<mp[bitset<5>(bins.substr(i, 5)).to_ulong()];
    return 0;
}