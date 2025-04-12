#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define pb push_back

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2==0){
            cout << 2025;
            for(int i = n-5; i >= 0; i--){
                cout << 0;
            }
        } else{
            cout << 42025;
            for(int i = n-6; i >= 0; i--){
                cout << 0;
            }
        }
        cout << endl;
    }
}

