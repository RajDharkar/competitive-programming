#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> intervals;
int main(){
    intervals.push_back(-1);
    ll k = 9;
    for(int i = 1; i <= 18; i++){
        intervals.push_back(k);
        k*=10;
        k/=i;
        k*=(i+1);
    }
    // for(auto x/ : intervals)cout << x << endl;
    // cout << endl;


    //9 90 
    int t;
    cin >> t;
    // cout << t << endl;
    // cin.ignore();
    for(int i=1;i<=t;i++){

        // cout << "HERH" << endl;
        ll num;
        cin >> num;
        // num = i;
        // cout << x << endl;
        ll sum = 0;
        ll ans = 0;
        for(ll i = 1; i <= 18; i++){
            sum += intervals[i];
            if(sum>=num){
                ans = i;
                break;
            }
        }
        // cout << ans << endl;
        sum-=intervals[ans];
        sum++;
        // cout << sum << " " << ans << endl;
        // cout << sum << endl;
        ll diff = (num- sum);
        // cout << diff << endl;
        // cout << pow(10, ans-1) << " " << diff/ans << endl;
        ll number = (ll)(pow(10, ans-1))+(diff/ans);
        // cout << number << endl;
        // return 
        //  cout << num << endl;
        string a = to_string(number);
        // cout << ans << " " << num << " " << sum << " " << num % ans << endl;
        // cout << (num-sum) % ans << endl;
        // cout << a << endl;
        // cout << a << endl;
        // cout << 
        // cout << (num-sum)%ans << endl;
        // cout << a[(num-sum)%ans] << " " << findDigit(num) << endl;
        cout << a[(num-sum)%ans] << endl;        
    }
}