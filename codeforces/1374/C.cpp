#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	stack<char> s;
	for(int i = 0; i < n;i++){
		char tmp;
		cin >> tmp;
		if(tmp==')'){
			if(!s.empty()&&s.top()=='('){
				s.pop();
			}else{
				s.push(tmp);
			}
		}else{
			s.push(tmp);
		}
	}
	char tmp = ' ';
	int ans = 0;
	while(!s.empty()){
		if(tmp==' ') tmp = s.top(),s.pop(),ans++;
		else{
			if(tmp==s.top()) ans++,s.pop();
			else break;
		}
	}
	cout << ans << '\n';
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}