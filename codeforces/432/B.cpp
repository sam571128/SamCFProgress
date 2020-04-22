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
int cnt[100005]; //Count the amounts of away colors
int away_c[100005];
int home[100005];
int away[100005];
int main(){
	fastio
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b;
		away_c[i] = b;
		cnt[a]++;
	}
	for(int i = 0;i < n;i++){
		home[i] += n-1;
		home[i] += cnt[away_c[i]];
		away[i] += 2*(n-1)-home[i];
	}
	for(int i = 0;i < n;i++){
		cout << home[i] << " " << away[i] << "\n";
	}
}
