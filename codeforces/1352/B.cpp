#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define push push_back
#define pop pop_front
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
		int a,b;
		cin >> a >> b;
		if(a==b){
			cout << "YES\n";
			for(int i = 0;i < b;i++){
				cout << 1 << " ";
			}
			cout << "\n";
			continue;
		}
		if(a%2!=0){
			if(b%2==1){
				if(b>a){
					cout << "NO\n";
				}else{
					cout << "YES\n";
					for(int i = 0;i < b-1;i++){
						cout << 1 << " ";
					}
					cout << a-(b-1)*1 << "\n";
				}
				continue;
			}
			else{
				cout << "NO\n";
				continue;
			}
		}
		if(b%2==1){
			if(b*2>a){
				cout << "NO\n";
			}else{
				cout << "YES\n";
				for(int i = 0;i < b-1;i++){
					cout << 2 << " ";
				}
				cout << a-(b-1)*2 << "\n";
			}
		}else{
			if(b>a){
				cout << "NO\n";
			}else{
				cout << "YES\n";
				for(int i = 0;i < b-1;i++){
					cout << 1 << " ";
				}
				cout << a-(b-1)*1 << "\n";
			}
		}
	}
}
