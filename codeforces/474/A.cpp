#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

int main(){
	fastio
	string keyb = "qwertyuiopasdfghjkl;zxcvbnm,./";
	string a, b;
	cin >> a >> b;
	for(int i = 0;i < b.size();i++){
		if(a=="R"){
			for(int j = 0;j < keyb.size();j++){
				if(keyb[j]==b[i]){
					cout << keyb[j-1]; 
				}
			}
		}else{
			for(int j = 0;j < keyb.size();j++){
				if(keyb[j]==b[i]){
					cout << keyb[j+1]; 
				}
			}
		}
	}
}
