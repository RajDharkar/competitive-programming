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
        vector<int> arr(n);
        for(auto &x : arr)cin >> x;
        set<int> factors;
        ll missing = 0;
        ll wrong = -1;
        for(int i=0; i < n; i++){
            if(i>0){
                bool found = 0;
                int num = arr[i];
                while (num % 2 == 0) {
                    if(factors.count(2)){
                        found=1;
                        break;
                    }
                    num /= 2;
                }
                for (int i = 3; i * i <= num; i += 2) {
                    while (num % i == 0) {
                        if(factors.count(i)){
                            found=1;
                            break;
                        }
                        num /= i;
                    }
                }
                if (num > 1) { 
                    if(factors.count(num)){
                        found=1;
                    }
                }
                missing += !found;
                if(!found){
                    wrong = arr[i];
                }
            }

            int num = arr[i];
            while (num % 2 == 0) {
                factors.insert(2);
                num /= 2;
            }
            for (int i = 3; i * i <= num; i += 2) {
                while (num % i == 0) {
                    factors.insert(i);
                    num /= i;
                }
            }
            if (num > 1) { 
                factors.insert(num);
            }
        }

        if(missing > 1){
            cout << "";
        }

    }
}

