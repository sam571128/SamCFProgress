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
		int n,k;
		cin >> n >> k;
		vi v;
		for(int i = 0;i < n;i++){
			int a;
			cin >> a;
			v.pb(a);
		}
		vi arr(2*k+1);
		for(int i = 0;i < n/2;i++){
			arr[v[i]+v[n-i-1]]++;
		}
		vi pref(2*k+2,0);
		for(int i = 0; i < n/2;i++){
			int l1 = 1 + v[i]; int l2 = 1 + v[n-i-1];
			int r1 = k + v[i]; int r2 = k + v[n-i-1];	
			assert(max(l1,l2)<=min(r1,r2));
			pref[min(l1,l2)]++;
			pref[max(r1,r2)+1]--;		
		} 
		for(int i = 1;i <= 2*k+1;i++){
			pref[i] += pref[i-1];
		}
		int ans = INT_MAX;
		for(int i = 2;i <= 2*k;i++){
			ans = min(ans,(pref[i]-arr[i])+(n/2-pref[i])*2);
		}
		cout << ans << "\n";
	}
}
