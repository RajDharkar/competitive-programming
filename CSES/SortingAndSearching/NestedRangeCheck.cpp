#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

struct Range{
    int l, r, ind;
};


bool cmp(Range a, Range b){
    if(a.l == b.l)return a.r > b.r;
    return a.l < b.l;
}

int main(){
    int n;
    cin >> n;
    vector<Range> ranges(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        ranges[i] = {a, b, i};
    }

    sort(ranges.begin(), ranges.end(), cmp);

    int minr = 2e9;

    vector<int> one(n);
    for(int i = n - 1; i >= 0; i--){
        if(ranges[i].r >= minr){
            one[ranges[i].ind]++;
        }
        minr = min(minr, ranges[i].r);
    }

    int maxr = 0;                   
    vector<int> two(n);
    for(int i = 0; i < n; i++){
        // cout << ranges[i].r << " " << maxr << endl;
        if(ranges[i].r <= maxr){
            two[ranges[i].ind]++;
        }
        maxr = max(maxr, ranges[i].r);
    }

    for(auto a : one){
        cout << a << " ";
    }
    cout << '\n';
    for(auto a : two){
        cout << a << " ";
    }
}


// // struct Line{
// //     int x, ind;
// //     bool isLeft;
// // };

// // bool cmp(Line a, Line b){
// //     return a.x < b.x;

// // }

// // int main(){
// //     int n;
// //     cin >> n;
// //     vector<Line> lines;
// //     for(int i = 0; i < n; i++){
// //         int a, b;
// //         cin >> a >> b;
// //         Line left;
// //         left.x = a;
// //         left.ind = i;
// //         left.isLeft = 1;
// //         Line right;
// //         right.x = b;
// //         right.ind = i;
// //         right.isLeft = 0;
// //         lines.pb(left);
// //         lines.pb(right); 
// //    }
// // //    for(Line a : lines){
// // //        cout << a.isLeft << endl;
// // //    }
// //     sort(all(lines), cmp);

// //     vector<int> one(n);
// //     vector<int> two(n);
// //     set<pair<int, int>> sofar; 
// //     map<int, int> start_pos;   

// //     for(auto &a : lines){
// //         if(a.isLeft){
// //             sofar.insert({a.x, a.ind});
// //             start_pos[a.ind] = a.x;
// //         } else {
// //             if(!sofar.empty() && sofar.begin()->second != a.ind){
// //                 auto earliest = *sofar.begin();
// //                 one[earliest.second] = 1;
// //                 two[a.ind] = 1;
// //             }
// //             sofar.erase({start_pos[a.ind], a.ind});
// //         }
// //     }
// //     for(auto x : one){
// //         cout << x << " ";
// //     }
// //     cout << endl;
// //     for(auto x : two){
// //         cout << x << " ";
// //     }
// // }

