#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    vector<pii> rabbits(n);
    rabbits.push_back({-1e9, 0});
    for (ll i = 0; i < n; i++)
    {
        string type;
        ll position;
        cin >> type >> position;
        rabbits[i].first = position;
        if (type == "S")
        {
            rabbits[i].second = 1;
        }
    }
    rabbits.push_back({1e9, 0});
    sort(rabbits.begin(), rabbits.end());
    // cout << a << " " << b << endl;
    // for (pii rabbitTest : rabbits)
    // {
    //     cout << rabbitTest.first << " " << rabbitTest.second << endl;
    // }
    ll startingRabbit = 0;
    for (ll i = 1; i < n + 1; i++)
    {
        if (rabbits[i].first > a)
        {
            startingRabbit = i - 1;
            break;
        }
    }
    ll endingRabbit = n - 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (rabbits[i].first < b)
        {
            endingRabbit = i + 1;
            break;
        }
    } 
   // cout << startingRabbit << " " << endingRabbit << " Positions \n";
    ll answer = 0;
    for (ll i = startingRabbit; i < endingRabbit - 1; i++)
    {
        ll x = rabbits[i].first;
        ll y = rabbits[i + 1].first;

        if ((y - x) % 2 == 0)
        {
            ll left = x;
            ll right = (x + y) / 2 - 1;
            bool f = false;
            if(left < a){
                left = a;
                f = true;
                if(right < a){
                    right = a; //hence negating any points given
                }
                if(right == a){
                    //something might need to be done here however I am not sure
                }
            }
            bool l = false;
            if(right > b){
                right = b;
                l = true;
                if(left > a){
                    left = b;
                }
                if(left == b){

                }
            }
            if (rabbits[i].second == 1 && left <= right)
            {
                answer += right - left;
            }
            if (rabbits[i].second == 1 || rabbits[i + 1].second == 1)
            {
                answer++;
            }
            left = (x + y) / 2 + 1;
            right = rabbits[i + 1].second;
            //cout << left << " " << right << "LR" << endl;
            f = false;
            if(left < a){
                left = a;
                f = true;
                if(right < a){
                    right = a; //hence negating any points given
                }
                if(right == a){
                    //something might need to be done here however I am not sure
                }
            }
            l = false;
            if(right > b){
                right = b;
                l = true;
                if(left > a){
                    left = b;
                }
                if(left == b){

                }
            }
            if (rabbits[i + 1].second == 1 && left <= right)
            {
                answer += right - left;
               //cout << answer << "ANSWER";
            }
        }
        else
        {
            ll left = x;
            ll right = (x + y) / 2;
            bool f = false;
            if(left < a){
                left = a;
                f = true;
                if(right < a){
                    right = a; //hence negating any points given
                }
                if(right == a){
                    //something might need to be done here however I am not sure
                }
            }
            bool l = false;
            if(right > b){
                right = b;
                l = true;
                if(left > a){
                    left = b;
                }
                if(left == b){

                }
            }
            if (rabbits[i].second == 1 && left <= right)
            {
                answer += right - left;
            }
            left = y - (y - x) / 2;
            right = y;
          //  cout << left << " " << right << "LR" << endl;
            f = false;
            if(left < a){
                left = a;
                f = true;
                if(right < a){
                    right = a; //hence negating any points given
                }
                if(right == a){
                    //something might need to be done here however I am not sure
                }
            }
            l = false;
            if(right > b){
                right = b;
                l = true;
                if(left > a){
                    left = b;
                }
                if(left == b){

                }
            }
            if (rabbits[i + 1].second == 1 && left <= right)
            {
                answer += right - left;
               // cout << answer << "ANSWER";
            }
        }
    }
    ll otherAnswer = 0;
    for(ll i = 0; i <= n; i++){
        if(rabbits[i].first >= a && rabbits[i].first <= b && rabbits[i].second == 1){
            otherAnswer++;
        }
    }
    cout << answer + otherAnswer << endl;
}