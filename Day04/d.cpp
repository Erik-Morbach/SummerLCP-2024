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

int st[maxn][maxp];

void solve(){
	memset(st,0,sizeof(st));
	int n, q;
	cin >> n >> q;
	for(int i=2;i<=n;i++)
		cin >> st[i][0];

	for(int k=1;k<maxp;k++)
		for(int i=0;i<=n;i++)
			st[i][k] = st[st[i][k-1]][k-1];

	for(int i=0;i<q;i++){
		int x,k;
		cin >> x >> k;

		for(int p=0;p<maxp;p++){
			if(k & (1<<p)){
				x = st[x][p];
			}
		}
		cout << (!x?-1:x) << "\n";
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


