#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef pair<string,int> psi;
map<string,int> mp;
psi max(psi a, psi b)
{
    if(a.second>b.second) return a;     // 先以出现次数为标准判断
    else if(a.second<b.second) return b;
    else return a.first<b.first?a:b;    // 若出现次数相等，以字典序小的为准
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        mp[s]++;    // 次数加一
    }
    psi ans("", 0);
    for(auto p : mp)
        ans = max(ans, p);
    cout<<ans.first<<endl;
    return 0;
}