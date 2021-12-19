#include <iostream>
using namespace std;
const int maxn = 2e5+5;
int mp[maxn<<1];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x]=i;     // 存下坐标
    }
    int ans = 0;
    for(int k=3;k<=2*n-1;k++)   // 枚举 i+j 的值
    {
        for(int i=1;i*i<k;i++)  // 分解因子
        {
            if(k%i) continue;
            int j = k/i;
            if(mp[i]&&mp[j]&&mp[i]+mp[j]==k)    // 若满足条件（存在且坐标和等于枚举出的结果）则答案加一
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}