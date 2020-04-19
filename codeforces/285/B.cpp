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
	int n,s,t;
	cin >> n >> s >> t;
	int arr[n+1];
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	int times = 0;
	while(s!=t&&times<n){
		s = arr[s];
		times++;
	}
	if(s==t){
		cout << times;
	}else{
		cout << -1;
	}
}
