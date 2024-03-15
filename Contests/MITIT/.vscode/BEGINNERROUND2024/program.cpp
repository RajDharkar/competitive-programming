#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 10e9 + 7;
// ios_base::sync_with_stdio(false); cin.tie(0);
typedef pair<int, int> pii;
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
int main() {
    ll max2 = 0;
    ll a = 0;
    for(int i = 1; i < 10000; i++){
        ll num = pow(10,i);
        a = 0;
        while(!isPrime(num+a)){
            a++;
        }
        max2 = max(a, max2);
    }
    cout << max2;
}
