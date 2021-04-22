//SHUBHAM SHASTRI  BASIC CODE FOR CP
#include<bits/stdc++.h>
using namespace std;
#define int                      long long
#define ll                       long long
typedef vector<int>              vi;
typedef pair<int,int>            pi;
typedef map<int ,int>            mii;
typedef map<char,int>            mci;
#define rep(i, a, b)             for(int i = a; i < (b); ++i)
#define rrep(i, n)               for(int i=n-1;i>=0;i--)
#define sz(x)                    (int)(x).size()
#define uniq(v)                  (v).erase(unique(all(v)),(v).end())
#define trav(a, x)               for(auto& a : x)
#define all(x)                   x.begin(), x.end()
#define endl                    "\n"
#define fi                       first                
#define se                       second            
#define pb                       push_back            
#define mp                       make_pair 
#define SQ(a)                    (a)*(a)   
#define mem1(a)                  memset(a,-1,sizeof(a))
#define mem0(a)                  memset(a,0,sizeof(a))  
#define   gcd(a,b)               __gcd(a,b)
#define   lcm(a,b)               (a/gcd(a,b))*b

//DEBUG

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

time spent(){ 
	clock_t begin = clock();
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
}

// segment tree

void build(int a[], int v, int tl, int tr){
	if(tl == tr){
		t[v] = a[tl];
	}
	else{
		int tm = (tl+tr) >> 1;
		build(a, v << 1, tl, tm);
		build(a, (v << 1)+1, tm+1, tr);
		t[v] = t[v << 1] + t[(v << 1) + 1];
	}
}
ll sum(int v, int tl, int tr, int l, int r){
	if(l > r){
		return 0;
	}
	if(tl == l && tr == r){
		return t[v];
	}
	int tm = (tl + tr) >> 1;
	return sum(v << 1, tl, tm, l, min(tm, r)) + sum((v << 1)+1, tm + 1, tr, max(l, tm+1), r);
}
void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		t[v] = val;
	}
	else{
		int tm = (tl+tr) >> 1;
		if(pos <= tm){
			update(v << 1, tl, tm, pos, val);
		}
		else{
			update((v << 1) + 1, tm+1, tr, pos, val);
		}
		t[v] = t[v << 1] + t[(v << 1)+1];
	}
}


//Dinics max flow ALGO
struct edge{
	int from, to, cap, flow;
};
vector <int> g[MAX];
vector <edge> e;
int source, sink, level[MAX], ptr[MAX];

void add_edge(int from, int to, int cap){
	edge e1 = {from, to, cap, 0};
	edge e2 = {to, from, 0, 0};
	g[from].push_back(e.size());
	e.push_back(e1);
	g[to].push_back(e.size());
	e.push_back(e2);
}
//BFS
int bfs(){
	memset(level, -1, sizeof(level));
	level[source] = 0;
	queue <int> q;
	q.push(source);
	int v;
	while(!q.empty()){
		v = q.front();
		q.pop();
		if(v == sink){
			return 1;
		}
		for(auto i : g[v]){
		int to = e[i].to;
			if(level[to] == -1 && e[i].flow < e[i].cap){
				level[to] = level[v] + 1;
				q.push(to);
			}
		}
	}
	return 0;
}
//DFS
int dfs(int v, int flow){
	if(flow <= 0)
		return 0;
	if(v == sink)
		return flow;
	for(; ptr[v] < g[v].size(); ++ptr[v]){
		int id = g[v][ptr[v]], to = e[id].to;
		if(level[to] != level[v] + 1)
			continue;
		int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
		if(pushed){
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
int dinic(){
	int flow = 0, val;
	while(bfs()){
		memset(ptr, 0, sizeof(ptr));
		while(val = dfs(source, INF)){
			flow += val;
		}
	}
	return flow;
}

// Z - Algorithm
void getZarr(string &str){
	int n = str.length();
	int L, R, k; 
	L = R = 0;
	for(int i = 1; i < n; ++i){
		if (i > R){
			L = R = i;
			while (R<n && str[R-L] == str[R])
				R++;
			Z[i] = R-L;
			R--;
		}
		else{
			k = i-L;
			if (Z[k] < R-i+1)
				Z[i] = Z[k];
			else{
				L = i;
				while (R<n && str[R-L] == str[R])
					R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
}

//sorting the pair in ascending order with respect to second element
bool sortBySec(const pair<int,int> &a,const pair<int,int> &b) { return (a.second < b.second);}
//showing no is prime or not complexity high
bool prime(int n) {if (n < 2) return false;for (int x = 2; x*x <= n; x++) {if (n%x == 0) return false;}return true;}
bool isPerfectSquare(long double x){if (x >= 0) {long long sr = sqrt(x);return (sr * sr == x);}return false;}
//gives us prime no upto n in a vector
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int > vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
// converts decimal to binary
string decimalToBinary(int n){ string s = bitset<64> (n).to_string();const auto loc1 = s.find('1'); if(loc1 != string::npos)return s.substr(loc1);return "0";}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int  gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int  expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;


void solve(){
 
 
 



}
signed main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
  solve();
    }   
     return 0;
}