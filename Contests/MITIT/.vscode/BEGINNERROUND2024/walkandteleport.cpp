#include <iostream>
#include <vector>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
using ll = long long;
using namespace std;
int main() {
    int n, a, b; cin >> n >> a >> b;
    vector<int> x(n); repeat (i,n) cin >> x[i];
    ll acc = 0;
    repeat (i,n-1) acc += min<ll>(b, a *(ll) (x[i+1] - x[i]));
    cout << acc << endl;
    return 0;
}