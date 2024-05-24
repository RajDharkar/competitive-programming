#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = int(s.size());
  int m = int(t.size());
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    while (ptr < m && t[ptr] != s[i]) {
      ptr += 1;
    }
    assert(ptr < m);
    ptr += 1;
    cout << ptr << " \n"[i == n - 1];
  }
  return 0;
}