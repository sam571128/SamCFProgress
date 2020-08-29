#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
  
int f[N];
int cnt[N]; 
  
void sieve() 
{ 
    f[1] = 1; 
    for (int i=2; i < N; i++) 
        f[i] = i; 
  
    for (int i=4; i<N; i+=2) 
        f[i] = 2; 
  
    for (int i=3; i*i<N; i++) 
    { 
        if (f[i] == i) 
        { 
            for (int j=i*i; j<N; j+=i) 
  
                if (f[j]==j) 
                    f[j] = i; 
        } 
    } 
} 
bool ok = true;
void F(int x) 
{ 
	vector<int> res;
    while (x != 1) 
    { 
    	res.push_back(f[x]);
        x = x / f[x]; 
    }
   	for(auto p : res){
   		if(cnt[p]){
    		ok = false;
    	}
   	} 
   	for(auto p : res) cnt[p]++;
} 

void solve(){
	sieve();
	int n;
	cin >> n;
	int g;
	cin >> g;
	F(g);
	for(int i = 1, tmp;i < n;i++){
		cin >> tmp;
		g = gcd(g,tmp);
		F(tmp);
	}
	if(ok){
		cout << "pairwise coprime\n";
		return;
	}
	if(g==1){
		cout << "setwise coprime\n";
		return;
	}else{
		cout << "not coprime\n";
		return;
	}
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}