#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define sz(x) (int)(x).size()

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> diff(a+1, 0);
    map<pii, bool> moves;
    for(int i = 0; i < d; i++){
        int p, q;
        cin >> p >> q;
        if(abs(q - p) == 1){
            moves[{min(p, q), max(p, q)}] = false;
        }
        else{
            moves[{min(p, q) + 1, max(p, q) - 1}] = true;
        }
    }

    for(auto it = moves.begin(); it != moves.end(); it++) {
        int p = it->first.first;
        int q = it->first.second;
        if(!moves[{p, q}]){
            continue;
        }
        p--;
        q--;
        diff[p]++;
        diff[q+1]--;
    }
    vector<int> ans;
    int start = 0;
    for(int i = 0; i < a; i++){
        start += diff[i];
        ans.push_back(start);
    }
    for(int i = 0; i < sz(ans); i++){
        cout << c - ans[i] << endl;
    }
}
