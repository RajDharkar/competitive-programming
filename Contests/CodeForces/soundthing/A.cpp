#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        // cout << k << endl;
        vector<int> arr(k-2);
        for(auto &x : arr)cin >> x;
        bool works = 1;
        for(int i = 1; i < k-3; i++){
            if(!arr[i] && arr[i-1] && arr[i+1]){
                works = false;
                //cout << i << endl;
            }
        }
        if(k-2<=2)works=1;
        cout << (works ? "YES" : "NO") << endl;
    }
}