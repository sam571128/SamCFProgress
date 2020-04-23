#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define pf pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vll v;
		for(int i = 0;i < n;i++){
			ll int a;
			cin >> a;
			v.pb(a);
		}
		int signs = 0;
		vll arr(n,INT_MIN);
		arr[0] = v[0];
		for(int i = 1;i < v.size();i++){
			if(!((v[i]>=0)^(v[i-1]<0))){
				signs++;
			}
			arr[signs] = max(arr[signs],v[i]);
		}
		ll int sum = 0;
		for(int i = 0;i < v.size();i++){
			if(arr[i]!=INT_MIN)sum += arr[i];
		}
		cout << sum << "\n";
	} 
}
