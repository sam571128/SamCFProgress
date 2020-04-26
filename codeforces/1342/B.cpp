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
		string a;
		cin >> a;
		int one = 0;
		int zero = 0;
		for(int i = 0 ;i < a.size();i++){
			if((a[i]-'0')==0) zero++;
			else one++;
		}
		if(one==0||zero==0){cout << a << "\n"; continue;}
		int status = a[0]-'0';
		string ans = "";
		for(int i = 0;i < a.size()*2;i++){
			ans += to_string(status);
			status = (status ? 0 : 1);
		}
		cout << ans << "\n";
	}
}
