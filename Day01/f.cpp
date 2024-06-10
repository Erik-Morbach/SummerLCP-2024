#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
#define INF (1<<30)
#define LINF (1LL<<60)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define lsb(i) (i&(-i))
#define all(z) begin(z), end(z)
#define EPS ((double)(1e-9))
#define MOD 1000000007
const int maxn = 1123456;

int n, m;
ll v[30][30];
bool mark[30][30];
bool dp1Viz[30][30];
bool dp2Viz[30][30];
bool alrow[30];
bool alcol[30];
unordered_map<ll, ll> memo[30][30];
unordered_map<ll, ll> memo2[30][30];

void dp1(int i, int j, ll k){
	if(i>n) return;
	if(j>m) return;
	dp1Viz[i][j] = 1;
	k ^= v[i][j];
	if(i+j >= (n+m)/2){
		mark[i][j] = 1;
		memo[i][j][k]++;
		return;
	}
	dp1(i+1,j,k);
	dp1(i,j+1,k);
}

void dp2(int i, int j, ll k){
	if(i<1) return;
	if(j<1) return;
	dp2Viz[i][j] = 1;
	if(mark[i][j]){
		memo2[i][j][k]++;
		return;
	}
	k ^= v[i][j];
	dp2(i-1,j,k);
	dp2(i,j-1,k);
}


void solve(){
	ll K;
	cin >> n >> m >> K;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> v[i][j];
		}
	}
	dp1(1,1,K);
	dp2(n,m,0);

	ll ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!mark[i][j]) continue;
			for(auto w: memo[i][j]){
				if(memo2[i][j].count(w.x))
					ans += w.y * memo2[i][j][w.x];
			}
		}
	}
	cout << ans << "\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0)->tie(0);
	int t = 1;
	//cin >> t;

	for(int caso=1;caso<=t;caso++){
		solve();
	}
	return 0;
}
