#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push emplace_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int a;
	cin >> a;
	string b;
	cin >> b;
	int s = b.size();
	int sumz = 0;
	int sumo = 0;
	for(auto i : b){
		if(i=='0'){
			sumz++;
		}else{
			sumo++;
		}
	}
	cout << abs(sumz-sumo);
}