#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		deque<int> v;
		while(n--){
			int a;
			cin >> a;
			v.pb(a);
		}
		int move = 1;
		int eaten = -1;
		int ans1 = 0;
		int ans2 = 0;
		while(v.size()){
			int sum = 0;
			if(move%2==1){
				if(eaten == -1){
					sum+=v[0];
					v.pf();
				}else{
					while(sum<=eaten){
						if(v.size()==0) break;
						sum+=v[0];
						v.pf();
					}
				}
				ans1 += sum;
			}else{
				while(sum<=eaten){
					if(v.size()==0) break;
					sum+=v[v.size()-1];
					v.pop_back();
				}
				ans2 += sum;
			}
			if(v.size()==0){
				cout << move << " " << ans1 << " " << ans2 << "\n";
			}
			eaten = sum;
			move++;
		}
	}
	
}
