#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string s;
	cin >> s;
	int tmp = 0;
	int arr[(int)1e6+5];
	memset(arr,0,sizeof arr);
	for(int i = 0;i < s.size();i++){
		if(s[i]=='-') tmp--;
		else tmp++;
		if(tmp<0) if(!arr[-tmp]) arr[-tmp] = i+1;
	}
	//cout << '\n';
	//for(auto x : arr) cout << x  << " ";
	//cout << "\n";
	ll res = 0;
	for(int i = 0;i < 1e8;i++){
		if(arr[i+1]) res += arr[i+1];
		else{
			res += s.size();
			break;
		}
	}
	cout << res << "\n";
	
	/*for(int init = 0;init < check;init++){
	    int cur = init;
	    bool ok = true;
	    for(int i = 0; i < s.size();i++){
	        res++;
	        if(s[i] == '+')
	            cur = cur + 1;
	        else
	            cur = cur - 1;
	        if(cur < 0){
	            ok = false;
	            break;
	        }
	    }
	    if(ok)
	        break;
	}
	cout << res << "\n";*/
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}