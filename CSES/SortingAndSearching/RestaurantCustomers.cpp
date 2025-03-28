#include <bits/stdc++.h>

using namespace std;

#define pb push_back
struct Line{
    int x, i;
    bool isLeft;
};

bool cmp(Line a, Line b){
    return a.x < b.x;
}

int main(){
    int n;
    cin >> n;
    vector<Line> bar;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        Line ter;
        ter.x = a;
        ter.i = i;
        ter.isLeft = true; 

        Line terd;
        terd.x = b;
        terd.i = i;
        terd.isLeft = false;

        bar.pb(ter);
        bar.pb(terd);
    }

    sort(bar.begin(), bar.end(), cmp);

    set<int> swpl;
    int ans = 0;
    for(int j = 0; j < 2*n; j++){
        Line k = bar[j];
        if(swpl.count(k.i)){
            swpl.erase(k.i);
        } else{
            swpl.insert(k.i);
        }
        ans = max(ans, int(swpl.size()));
    }

    cout << ans << endl;
}