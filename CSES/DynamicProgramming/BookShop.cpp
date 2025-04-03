#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pint;

int dp[1001][100001];

int main(){
    // cout << 13 << endl;
    int n, x;
    cin >> n >> x;
    vector<pint> ppl(n); //cost, pages
    for(auto& [a, b] : ppl){
        cin >> a;
    }
    for(auto &[a, b] : ppl){
        cin >> b;
    }

    //dp[i][j] = max(dp[i][j], dp[i][j - cost] + pages)

    int book = 0;
    for(auto &[cost, pages] : ppl){
        // cout << cost << " " << pages << endl;                                                                           
        book++;
        for(int j = 0; j <= x; j++){
            // if(cost == 12)cout << j << endl;
            if(j - cost >= 0){
                // if(cost == 5) {cout << j << endl;}
                // cout << dp[book][j - cost] << " ";
                dp[book][j] = max(dp[book-1][j], dp[book-1][j - cost] + pages); //we can't use the same book twice so book-1 doesn't work
            } else {
                dp[book][j] = dp[book-1][j];
            }
        }
    }
    // for(int i = 0; i <= book; i++){
    //     for(int j = 0; j <= x; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[book][x];
}