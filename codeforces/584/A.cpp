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
	int a,b;
	cin >> a >> b;
	if(a==1&&b==10){
		cout << "-1";
		return 0;
	}else if(b==10){
		for(int i = 0;i < a-1;i++){
			cout << "1";
		}
		cout << "0";
		return 0;
	}
	for(int i = 0;i < a;i++){
		cout << b;
	}
}