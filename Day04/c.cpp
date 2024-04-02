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

double dfs(int v, int p){
	double ans = 0;
	double siz = prox[v].size();
	if(p!=-1) siz--;

	for(int w: prox[v]){
		if(w == p) continue;
		double atu = dfs(w,v);
		/*
		cout << "Goto "<<w <<" with "<< 1/siz << endl;
		cout << "Got "<<fixed<<atu <<endl;*/
		ans += atu/siz;
	}
	return ans + 1;
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

	cout.precision(9);
	cout << fixed << dfs(1, -1) -1 << "\n";
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


