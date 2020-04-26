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
	string a;
	cin >> a;
	if(a=="1"){
		cout << "YES";
		return 0;
	}
	if(a[0]!='1'||(a[1]!='4'&&a[1]!='1')){
		cout << "NO"; return 0;
	}
	for(int i = 2;i < a.size();i++){
		if(a[i]!='4'&&a[i]!='1'){
			cout << "NO"; return 0;
		}
		if(a[i]=='4'&&a[i-1]!='1'){
			if(a[i-1]!='4'){
				cout << "NO"; return 0;
			}
			else if(a[i-2]!='1'){
				cout << "NO";return 0;
			}
		}
	}
	cout << "YES";
}
