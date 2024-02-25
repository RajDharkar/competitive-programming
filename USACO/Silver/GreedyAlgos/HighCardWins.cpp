#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> bessie;
vector<int> elsie;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    setIO("highcard");
    int n;
    cin >> n;
    bool cards[2*n];
    for(int i = 0; i < n; i++){
        int index;
        cin >> index;
        elsie.push_back(index);
        cards[index-1] = true;
    }
    for(int i = 0; i < 2*n; i++){
        if(!cards[i]){
            bessie.push_back(1+i);
        }
    }
    sort(bessie.begin(), bessie.end());
    sort(elsie.begin(), elsie.end());
    // for(int i = 0; i < n; i++){
    //     cout << bessie[i] << " " << elsie[i] << '\n';
    // }
    int ans = 0;
    int bessieP = 0;
    int elsieP = 0;
    while(bessieP < n && elsieP < n){//notice that as elsies counter goes up, and when it gets to the end, 
        if(bessie[bessieP] > elsie[elsieP]){
            elsieP++;
            ans++;
        }
        bessieP++;
        //heres a better way to write it than above
        // if(bessie[bessieP] > elsie[elsieP]){
        //     bessieP++;
        //     elsieP++;
        //     ans++;
        // }
        // else{
        //     bessieP++;
        // }
    }
    cout << ans << '\n';
}
