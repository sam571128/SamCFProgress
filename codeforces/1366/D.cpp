#include <bits/stdc++.h>

#define ll long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e7;
bitset<N> isPrime;
vector<int> pf;
vector<int> pr;

void init(){
	pf.resize(N,0);
	isPrime.flip();
	isPrime[0] = isPrime[1] = false;
	for(int i = 2;i < N;i++){
		if(isPrime[i]){
			pr.push_back(i);
			pf[i] = i;
		}
		for(auto p : pr){
			if(1ll*i * p >= N) break;
			pf[p*i] = p;
			isPrime[p*i] = false;
			if(i%p==0) break;
		}
	}
}

int main(){
	fastio
	int n;
	cin >> n;
	int ans1[n+1];
	int ans2[n+1];
	init();
	//cout << "init done\n";
	memset(ans1,-1,sizeof ans1);
	memset(ans2,-1,sizeof ans2);
	for(int i = 1;i <= n;i++){
		int a;
		cin >> a;
		int p = pf[a];
		if(a%p!=0) break;
		int f = a;
		int s = 1;
		while(f%p==0){
			f/=p;
			s*=p;
		} 
		if(f!=1){
			ans1[i] = f;
			ans2[i] = s;
		}
		
	}
	for(int i = 1;i <= n;i++){
		cout << ans1[i] << " ";
	}
	cout << "\n";
	for(int i = 1;i <= n;i++){
		cout << ans2[i] << " ";
	}
}