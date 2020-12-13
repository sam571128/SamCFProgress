#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> primes;
bitset<N> isprime;
void init(){
	isprime.flip();
	for(int i = 2;i < N;i++){
		if(isprime[i]){
			primes.push_back(i);
			for(int j = i*i;j < N; j+=i)
				isprime[j] = 0;
		}
	}
}

bool checkPrime(int x){
	if(x < N) return isprime[x];
	else{
		for(auto p : primes){
			if(p > x) return true;
			if(x%p==0) return false;
		}
		return true;
	}
}

int solve(int x, int y){
	if(y==0) return 0;
	if(checkPrime(x)) return y%x+y/x;
	int ans = 0;
	int z = gcd(x,y);
	while(z==1){
		ans++;
		y--;
		z = gcd(x,y);
	}
	x/=z;
	y/=z;
	return ans+solve(x,y);
}

signed main(){
	fastio
	init();
	int x,y;
	cin >> x >> y;
	cout << solve(x,y) << "\n";
}