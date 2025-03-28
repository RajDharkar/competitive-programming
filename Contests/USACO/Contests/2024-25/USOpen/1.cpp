#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back
int m;

struct Box{
    int x1, y1, x2, y2, i, count=0;
};

bool cmp(Box a, Box b){
    return a.count < b.count;
}

void solve(){
    int n;
    cin >> n;

    vector<Box> boxes;
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        boxes.pb({a, b, c, d, i+1});
    }


    for(int i = 0; i < n; i++){
        Box a = boxes[i];
        for(int j = i+1; j < n; j++){
            Box b = boxes[j];
            b.count += (a.x2 <= b.x1 && a.y2 <= b.x1);
        }
    }
    sort(all(boxes), cmp);

    for(int i = 0; i < sz(boxes); i++){
            
    }
    for(int i = 0; i < n; i++){
        cout << boxes[i].i << " \n"[i==n-1];
    }
    // cout << endl;
}

int main(){
    int t;
    cin >> t >> m;

    while(t--){
        solve();
    }
}

