#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
int main() {
    //setIO("backforth");
    vector<int> fac1;
    vector<int> fac2;
    int num1[10];
    int num2[10];
    for(int i = 0; i < 10; i++){
        cin >> num1[i];
        fac1.push_back(num1[i]);
    }
    for(int i = 0; i < 10; i++){
        cin >> num2[i];
        fac2.push_back(num2[i]);
    }
    set<int> answers;
    int cap1 = 1000;
    int cap2 = 1000;
    int a1, a2, a3, a4 = 0;
    for(int a = 0; a < fac1.size(); a++){ //tuesday bucket size
        cap1 = 1000;
        cap2 = 1000;
        fac1.erase(fac1.begin(), fac1.end());
        fac2.erase(fac2.begin(), fac2.end());
        for(int i = 0; i < 10; i++){
            fac1.push_back(num1[i]);
            fac2.push_back(num2[i]);
        }
        cap1-=fac1[a];
        cap2+=fac1[a];
        fac2.push_back(fac1[a]);
        fac1.erase(fac1.begin() + a);
        for(int b = 0; b < fac2.size(); b++){ //wednesday bucket size
            cap2-=fac2[b];
            cap1+=fac2[b];
            fac1.push_back(fac2[b]);
            fac2.erase(fac2.begin() + b);
            for(int c = 0; c < fac1.size(); c++){ //thursday bucket size
                cap1-=fac1[c];
                cap2+=fac1[c];
                fac2.push_back(fac1[c]);
                fac1.erase(fac1.begin() + c);
                for(int d = 0; d < fac2.size(); d++){ //friday bucket size
                    cap2-=fac2[d];
                    cap1+=fac2[d];
                    answers.insert(cap1);
                }
            }
        }
    }
    // cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
    cout << answers.size();
    for(int element : answers){
       cout << element << " ";
    }
}
