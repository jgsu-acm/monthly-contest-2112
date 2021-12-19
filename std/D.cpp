#include <iostream>
using namespace std;
const int maxn = 1e7+5;
int v[maxn], dp[maxn];
int main()
{
    int W, n;
    cin>>W>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)       // 完全背包
        for(int j=v[i];j<=W;j++)
            dp[j]=max(dp[j-v[i]]+v[i],dp[j]);   // 重量与价值相等
    cout<<W-dp[W]<<endl;    // 注意是问剩下多少
    return 0;
}