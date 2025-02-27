#include<bits/stdc++.h>

using namespace std;

struct person{
    string name, data;
};

int main(){
    int t;
    cin >> t;
    while(t--){
        string x;
        cin >> x;
        int k = int(x.size());
        int n;
        cin >> n;
        vector<person> arr(n);
        for(person& a : arr){
            string s;
            cin >> s;
            a.name=s.substr(0, s.find("="));
            a.data=s.substr(s.find("=")+1);
            // cout << a.name << " " << a.data << endl;
        }
        int ans = -1;
        vector<string> z;
        for(person a : arr){
            int m = int(a.data.size());
            vector<vector<int>> dp(k+1, vector<int>(m+1, 0));
            for(int i = 1; i <= k; i++){
                for(int j = 1; j <= m; j++){
                    if(x[i-1] == a.data[j-1]){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }else{
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    }
                }
            }
            int lcs = dp[k][m];
            if(lcs>ans){
                ans=lcs;
                z.clear();
                z.push_back(a.name);
            }
            else if(lcs==ans){
                // cout<<"here"<<endl;
                z.push_back(a.name);
            }
        }
        sort(z.begin(), z.end());
        int i = 0;
        for(string y : z){
            if(i>0){
                cout << ",";
            }
            cout << y;
            i++;
        }
        cout << endl;
    }
}