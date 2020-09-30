    #include <bits/stdc++.h>
     
    #define int long long
    #define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     
    using namespace std;
     
    void solve(){
    	int n,k;
    	cin >> n >> k;
    	set<int> s;
    	for(int i = 0, tmp;i < n;i++){
    		cin >> tmp;
    		s.insert(tmp);
    	}
    	if(k==1){
    		if(s.size()==1){
    			cout << 1 << "\n";
    		}else{
    			cout << -1 << "\n";
    		}
    		return;
    	}
    	cout << max((int)1,((int)s.size()-1)/(k-1)+(((int)s.size()-1)%(k-1)>0)) << "\n";
    }
     
    signed main(){
    	fastio
    	int t = 1;
    	cin >> t;
    	while(t--) solve();
    }