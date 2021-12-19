#include <iostream>
#include <list>
using namespace std;
const int maxn = 1e5+5;
list<int> ls;
list<int>::iterator pos[maxn];  // 记录某数的位置(迭代器)
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        ls.push_back(x);
        pos[x] = --ls.end();    // 记录位置，注意 end() 是最后一个数的下一位
    }
    for(int i=n;i>=1;i--)
    {
        auto f = pos[i], s = pos[i];
        ++s;    // 让 s 变为 f 的下一个位置
        if(f!=ls.end()&&s!=ls.end())    // 如果两个数都存在，那么输出并删除
        {
            cout<<i<<' '<<*s<<' ';
            pos[i] = pos[*s] = ls.end();
            ls.erase(f); ls.erase(s);
        }
    }
    return 0;
}