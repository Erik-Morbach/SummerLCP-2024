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
const int maxn = 312345;
const int mod = 998244353;

vector<int> prox[maxn];

ii dfs(int v, int p){
	ii ans = {0,v};
	for(int w:prox[v]){
		if(w==p) continue;
		ii atu = dfs(w,v);
		if(atu.x > ans.x){
			ans = atu;
		}
	}
	ans.x++;//Me adiciono na parada
	return ans;
}

void solve(){
	int n;
	cin >> n;
	for(int i=1;i<n;i++){
		int a,b;
		cin >> a >> b;
		prox[a].push_back(b);
		prox[b].push_back(a);
	}

	ii tes = dfs(1, -1);
	tes = dfs(tes.y, -1);
	tes.x--;
	cout << (tes.x*3) << "\n";
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

