#include <bits/stdc++.h>
#include <cmath>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
#define intma(ma) int ma = INT_MIN;
#define intmi(mi) int mi = INT_MAX;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int a;
	cin >> a;
	if(a>=0){
		cout << a;
		return 0;
	}else if(a==-10){
		cout << 0;
		return 0;
	}
	cout << max(a/10,a/100*10+a%10);
}