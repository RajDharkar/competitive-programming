#include <bits/stdc++.h>
#define ii pair<int, int>
#define fi first
#define se second
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using ll = long long;
const int nx=1e5+5;
int t, n, a[nx];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i = 1; i <= n; i++)
            cin>>a[i];
        if(n==1)
        {
            cout<<"YES\n";
            continue;
        }
        sort(a+1, a+n+1);
        if(a[1]!=a[2])
        {
            cout<<"YES\n";
            continue;
        }
        bool ok=0;
        for(int i = 3; i <= n; i++)
            ok|=(a[i]>a[1] && a[i]%a[1]!=0);
        if(ok)
            cout<<"YES\n";
        else cout<<"NO\n";
    }
}