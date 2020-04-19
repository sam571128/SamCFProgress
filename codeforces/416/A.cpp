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

int main(){
	fastio
	int n;
	cin >> n;
	int ma = 2*1e9; bool includema = false;
	int mi = -2*1e9; bool includemi = false;
	while(n--){
		string a,c;
		int b;
		cin >> a >> b >> c;
		if(a=="<"){
			if(c=="Y"){
				if(b <= ma){
					ma = b;
					includema = false;
				}
			}else{
				if(b >= mi){
					mi = b;
					includemi = true;
				}
			}
		}else if(a==">"){
			if(c=="N"){
				if(b <= ma){
					ma = b;
					includema = true;
				}
			}else{
				if(b >= mi){
					mi = b;
					includemi = false;
				}
			}
		}else if(a=="<="){
			if(c=="Y"){
				if(b <= ma){
					ma = b;
					includema = true;
				}
			}else{
				if(b >= mi){
					mi = b;
					includemi = false;
				}
			}
		}else if(a==">="){
			if(c=="N"){
				if(b <= ma){
					ma = b;
					includema = false;
				}
			}else{
				if(b >= mi){
					mi = b;
					includemi = true;
				}
			}
		}
	}
	for(int i = mi;i <= ma;i++){
		if(includemi && includema){
			if(i>=mi&&i<=ma){
				cout << i;
				return 0;
			}
		}
		else if(includemi){
			if(i>=mi&&i<ma){
				cout << i;
				return 0;
			}
		}else{
			if(i>mi&&i<ma){
				cout << i;
				return 0;
			}
		}
	}
	cout << "Impossible";
		return 0;
}
