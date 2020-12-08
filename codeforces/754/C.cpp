#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<string> splitWords(string s){
	vector<string> ans;
	string tmp = "";
	for(auto c : s){
		if(isalpha(c)||isdigit(c)){
			tmp+=c;
		}else{
			if(!tmp.empty()) ans.push_back(tmp);
			tmp.clear();
		}
	}
	if(!tmp.empty()) ans.push_back(tmp);
	return ans;
}

void solve(){
	int n;
	cin >> n;
	map<string,int> m;
	string names[n+1];
	for(int i = 1;i <= n;i++){
		string s;
		cin >> s;
		m[s] = i;
		names[i] = s;
	}
	int k;
	cin >> k;
	vector<string> messages;
	int can[k][n+1] = {};
	int ans[k];
	string tmp;
	getline(cin,tmp);
	for(int i = 0;i < k;i++){
		getline(cin,tmp);
		string sss; 
		for(int j = 0;j < tmp.size();j++){
			if(tmp[j]==':'){
				sss = tmp.substr(0,j);
				messages.push_back(tmp.substr(j+1,tmp.size()-(j+1)));
				break;
			}
		}
		vector<string> words = splitWords(messages.back());
		for(auto w : words){
			can[i][m[w]] = 1;
		}
		if(m[sss]){
			for(int j = 1;j <= n;j++){
				if(j!=m[sss]) can[i][j] = 1;
			}
		}
		ans[i] = m[sss];
	}
	vector<vector<int>> dp(k,vector<int>(n+1,-1));
	for(int i = 1;i <= n;i++) if(!can[0][i]) dp[0][i] = 0;
	for(int i = 0;i < k-1;i++){
		for(int j = 1;j <= n;j++){
			if(dp[i][j]==-1) continue;
			for(int a = 1; a <= n;a++){
				if(j==a) continue;
				if(!can[i+1][a]){
					dp[i+1][a] = j;
				}
			}
		}
	}
	int idx = k-1, pos = -1;
	for(int i = 1;i <= n;i++){
		if(dp[idx][i]!=-1){
			pos = i;
			break;
		}
	}
	if(pos==-1){
		cout << "Impossible\n";
		return;
	}
	while(~idx){
		ans[idx] = pos;
		pos = dp[idx][pos];
		idx--;
	}
	for(int i = 0;i < k;i++){
		cout << names[ans[i]] << ":" << messages[i] << "\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}