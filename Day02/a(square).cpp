#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define INF (1<<30)
#define LINF (1LL<<61)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
const int maxn = 212345;
const int maxp = 20;
const int mod = 998244353;

namespace sq{
	int n;
	int B;
	ll values[maxn];
	ll buck[maxn];

	void setup(int n){
		memset(values, 0, sizeof(values));
		memset(buck, 0, sizeof(buck));
		B = sqrt(n);
		sq::n = n;
	}
	void set(int i, int value){
		buck[i/B] -= values[i];
		buck[i/B] += (values[i] = value);
	}

	ll query(int l, int r){
		int bL = l/B;
		int bR = r/B;
		ll response = 0;
		if(bL == bR){
			for(int i=l;i<=r;i++) response += values[i];
			return response;
		}

		for(int i=bL+1;i < bR;i++) response += buck[i];
		while(l/B == bL) response += values[l++];
		while(r/B == bR) response += values[r--];
		return response;
	}
}

void solve(){
	int n,q;
	cin >> n >> q;
	sq::setup(n);
	for(int i=0;i<n;i++){
		int v;
		cin >> v;
		sq::set(i, v);
	}
	for(int i=0;i<q;i++){
		int l,r;
		cin >> l >> r;
		--l; --r;
		cout << sq::query(l, r) << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}


