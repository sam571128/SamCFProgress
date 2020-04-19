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
typedef vector< pair<int,int> > vpi;

int win[100005];
int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		memset(win,0,100005);
		for(int i = 1;i <=a;i++){
			int temp;
			cin >> temp;
			win[temp]=1;
		}
		int i;
		for(i = 1;b!=0||win[i];i++){
			if(!win[i])
				b--;
		}
		cout << i-1 << "\n";
	}
}
