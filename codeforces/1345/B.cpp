#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

vi v;
void generate(){
	int n = 0;
	while((int)(1.5*pow(n,2)+0.5*n)<=1e9)
		v.push_back((int)(1.5*pow(n,2)+0.5*n)),n++;	
}
int main(){
	fastio
	generate();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans = 0;
		while(*(upper_bound(v.begin(),v.end(),n)-1)!=0){
			n -= *(upper_bound(v.begin(),v.end(),n)-1);
			ans++;
		}
		cout << ans << "\n";
	}
}
