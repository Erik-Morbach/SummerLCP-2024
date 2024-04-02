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

int prox[maxn];
bool vizi[maxn];

bool dfs(int v, int dest){
	//cout << v << endl;
	if(v == dest) return true;
	if(vizi[v]) return false;
	vizi[v] = 1;
	return dfs(prox[v], dest);
}

void solve(){
	int n, t;
	cin >> n >>t;
	for(int i=1;i< n;i++){
		int x;
		cin >> x;
		prox[i] = i + x;
	}

	bool ans = dfs(1, t);
	if(ans) cout << "YES\n";
	else cout << "NO\n";
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


