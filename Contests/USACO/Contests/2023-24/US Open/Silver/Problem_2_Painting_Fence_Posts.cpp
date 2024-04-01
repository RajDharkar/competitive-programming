#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

using namespace std;
bool cmp(pii a, pii b){
  if (a.first!=b.first){
    return a.first<b.first;
  }
  return a.first<b.first;
}
int di(pii a, pii b){
    int x = a.first;
    int y = a.second;
    int x2 = b.first;
    int y2 = b.second;
    return abs(x2 - x) + abs(y2 - y);
}
// Main function
int main() {
    int n, p;
    cin >> n >> p;

    vector<pii> num(n);
    for(int i = 0; i < n; i++){
        cin >> num[i].first >> num[i].second;
    }
    sort(num.begin(), num.end(), cmp);
    vector<int> d = {0};
    for(int i = 0; i < p; i++){
        d.push_back(d[sz(d) - 1] + di(num[i], num[(i+1)%p]));
    }
    int length = d[sz(d) - 1];
    return 0;
}
