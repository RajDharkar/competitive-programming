#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        double n;
        cin >> n;
        n = round(n*100)/100; //2 decimal places
        int nearest10 = round(n/10.0)*10; //nearest 10th
        cout << fixed << setprecision(2) << n << " " << nearest10 << endl;
    }
}