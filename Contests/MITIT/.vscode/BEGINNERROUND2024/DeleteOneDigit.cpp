#include <bits/stdc++.h>
using namespace std;
void solve(){
         string N;
         cin >> N;
         int sum = 0;
         int onecount = 0;
         int twocount = 0;
         int length = N.length();
         for(int i = 0; i < length; i++){
             if(N[i]=='1'){
                onecount++;
             }
             else if(N[i] == '2'){
                twocount++;
             }
             sum+=N[i] - '0';
         }
         if(onecount == 0){
            cout << N << " " << "2" << endl;
            return;
         }
         int remby3 = sum%3;
         if(remby3 == 0){
            cout << N << " " << 3 << endl;
            return;
         }
         if(twocount == 0){
            if(length%2 == 0){
                cout << N << " 11" << endl;
                return;
            }
            else{
                for(int i = 0; i < length - 1; i++){
                    cout << N[i];
                }
                cout << " 11" << endl;
            }
            return;
         }
         if(remby3 == 1){
            bool first = true;
            for(int i = 0; i < length; i++){
                if(N[i] == '1' && first){
                    first = false;
                }
                else
                {
                    cout << N[i];
                }
            }
            cout << " 3" << endl;
            return;
         }
          if(remby3 == 2){
            bool first = true;
            for(int i = 0; i < length; i++){
                if(N[i] == '2' && first){
                    first = false;
                }
                else
                {
                    cout << N[i];
                }
            }
            cout << " 3" << endl;
            return;
         }
}
int main() {
    int T; cin >> T;
    while(T--){
         solve();
    }
}