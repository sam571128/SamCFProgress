#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int check(char c, int ones,int twos,int threes){
	if(c=='1') if(1<ones){ones--;return true; } else{return false;}
	if(c=='2') if(1<twos){twos--;return true; } else{return false;}
	if(c=='3') if(1<threes){threes--;return true;} else{return false;}
	return false;
}
int main(){
	fastio 
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int len = INT_MAX;
		int a[] = {-1,-1,-1};
		for(int i = 0; i < s.size();i++){
			a[s[i]-'0'-1] = i;
			if(a[0]!=-1&&a[1]!=-1&&a[2]!=-1) len = min(max({a[0],a[1],a[2]})-min({a[0],a[1],a[2]})+1,len);
		}
		cout << "\n";
		cout << (len==INT_MAX? 0 : len) << "\n";
		
	}
	cerr << "Time : " << (double) clock() / (double) CLOCKS_PER_SEC << "s\n";

}