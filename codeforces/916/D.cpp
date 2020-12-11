#include <bits/stdc++.h>
#include <bits/extc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
using namespace __gnu_pbds;

gp_hash_table<string,int> m;

const int N = 1e9+7;
struct node{
	int lc = 0, rc = 0, val = 0;
} t[(int)7e6+5];

struct trie{
	int nxt[26] = {};
	int val;
} tr[(int)2e6+5];


int cnt = 2, cnt2 = 1;
vector<int> v, v2;

void update(int lst, int &idx, int l, int r, int pos, int val){
	idx = cnt++;
	t[idx] = t[lst];
	if(l==r){
		t[idx].val += val;
	}
	else{
		int mid = l+r>>1;
		if(pos <= mid) update(t[lst].lc,t[idx].lc,l,mid,pos,val);
		else update(t[lst].rc,t[idx].rc,mid+1,r,pos,val);
		t[idx].val = t[t[idx].lc].val+t[t[idx].rc].val;
	}
	//cout << l << " " << r << " " << t[idx].val << "\n";
}

int query(int idx, int ql, int qr, int l, int r){
	if(ql > r || qr < l) return 0;
	if(idx == 0) return 0;
	if(ql <= l && qr >= r) return t[idx].val;
	int mid = l+r>>1;
	return query(t[idx].lc,ql,qr,l,mid)+query(t[idx].rc,ql,qr,mid+1,r);
}

void updatet(int lst, int &idx, string s, int val, int pos = 0){
	idx = cnt2++;
	tr[idx] = tr[lst];
	if(pos==s.size()){
		tr[idx].val = val;
	}else{
		updatet(tr[lst].nxt[s[pos]-'a'],tr[idx].nxt[s[pos]-'a'],s,val,pos+1);
	}
}

int queryt(int idx, string s, int pos = 0){
	if(pos==s.size()){
		return tr[idx].val;
	}else{
		return queryt(tr[idx].nxt[s[pos]-'a'],s,pos+1);		
	}
}

signed main(){
    //fastio
    int q;
    cin >> q;
    v.push_back(1);
    v2.push_back(0);
    for(int i = 0;i < q;i++){
        string s;
        cin >> s;
        if(s[0]=='s'){
            string a;
            int x;
            cin >> a >> x;
            int idx, idx2, idx3;
            int tmp = queryt(v2[i],a);
        	if(tmp) update(v[i],idx,0,N,tmp,-1);
        	else update(v[i],idx,0,N,tmp,0);
            updatet(v2[i],idx3,a,x);
            update(idx,idx2,0,N,x,1);
            v.push_back(idx2);
            v2.push_back(idx3);
        }else if(s[0]=='r'){
            string a;
            cin >> a;
            int idx,idx3;
            int tmp = queryt(v2[i],a);
        	if(tmp) update(v[i],idx,0,N,tmp,-1);
        	else update(v[i],idx,0,N,tmp,0);
            updatet(v2[i],idx3,a,0);
            v.push_back(idx);
            v2.push_back(idx3);
        }else if(s[0]=='q'){
            string a;
            cin >> a;
            int tmp = queryt(v2[i],a);
            if(!tmp) cout << -1 << endl;
            else{
            	cout << query(v[i],0,tmp-1,0,N) << endl;
            }
            t[cnt++] = t[v[i]];
            tr[cnt2++] = tr[v2[i]];
            v.push_back(cnt-1);
            v2.push_back(cnt2-1);
        }else if(s[0]=='u'){
            int d;
            cin >> d;
            int idx = v[i-d];
            int idx3 = v2[i-d];
            v.push_back(idx);
            v2.push_back(idx3);
        }
    }
}