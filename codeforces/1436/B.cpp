#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521};

void solve(){
	int n;
	cin >> n;
	int num = 0;
	for(int i = 0;i < primes.size();i++){
		auto itr = lower_bound(primes.begin(),primes.end(),n);
		while(itr!=primes.end()){
			int tmp = *itr-n+1;
			if(*lower_bound(primes.begin(),primes.end(),tmp)!=tmp){
				num = tmp;
				break;
			}
			itr++;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(i==j) cout << num << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}