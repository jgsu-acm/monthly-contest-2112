#include <iostream>
using namespace std;
const int maxn = 1e5+5;
const int mod = 998244353;
typedef long long ll;
int a[maxn];
ll qpow(ll x,ll p,ll mod)
{
    ll res=1;
    for(;p;p>>=1,x=x*x%mod)
        if(p&1) res=res*x%mod;
    return res;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    ll p=1, q=0;
    for(int i=n-1;i>=0;i--)
    {
        swap(p,q);
        p += a[i]*q;
        p %= mod;
    }
    cout<<(p*qpow(q, mod-2, mod)%mod+mod)%mod<<endl;
    return 0;
}