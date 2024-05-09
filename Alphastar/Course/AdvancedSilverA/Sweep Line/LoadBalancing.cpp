#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pii;

#define sz(x) int((x).size())

int main() {
	int n;
	cin >> n;

	vector<pii> states;
	for(int i = 0; i < n; i++){
	    int a, b;
	    cin >> a >> b;
	    states.push_back({a, b}); 
	}
    sort(states.begin(), states.end());
    
	int ans = n;
	for(int i = 0; i < n; i++){
	    int line = states[i].s;
	    vector<pii> below;
	    vector<pii> above;
	    for(int j = 0; j < n; j++){
	        if(states[j].s <= line){
	            below.push_back(states[j]);
	        }
	        else{
	            above.push_back(states[j]);
	        }
	    }
	    
	    int belowIndex = 0;
	    int aboveIndex = 0;
	    while(belowIndex < sz(below) && aboveIndex < sz(above)){
	        int xBorder = 1e9;
	        
	        if(belowIndex < sz(below)){
	            xBorder = min(xBorder, below[belowIndex].f);
	        }
	        if(aboveIndex < sz(above)){
	            xBorder = min(xBorder, above[aboveIndex].f);
	        }
	        while(belowIndex < sz(below) && below[belowIndex].f == xBorder){
	            belowIndex++;
	        }
	        while(aboveIndex < sz(above) && above[aboveIndex].f == xBorder){
	            aboveIndex++;
	        } 
	        ans = min(ans, max(max(belowIndex, sz(below) - belowIndex), max(aboveIndex, sz(above) - aboveIndex)));
	    }
	    
	}
	cout << ans << endl;
}