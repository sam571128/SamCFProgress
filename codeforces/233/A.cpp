#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;

int main(){
	fastio
	int a;
	cin >> a;
	if(a%2){
		cout << -1;
		return 0;
	}
	for(int i = 1;i <=a;i++){
		if(i%2){
			cout << i+1 << " ";
		}else{
			cout << i-1 << " ";
		}
	}
}
