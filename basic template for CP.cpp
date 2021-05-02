#include<bits/stdc++.h>
using namespace std;
#define int                      long long
#define ll                       long long
typedef vector<int>              vi;
typedef pair<int,int>            pii;
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
#define   gcd(a,b)                __gcd(a,b)
#define   lcm(a,b)               (a/gcd(a,b))*b

//sorting the pair in ascending order with respect to second element
bool sortBySec(const pair<int,int> &a,const pair<int,int> &b) { return (a.second < b.second);}
bool prime(int n) {if (n < 2) return false;for (int x = 2; x*x <= n; x++) {if (n%x == 0) return false;}return true;}
bool isPerfectSquare(long double x){if (x >= 0) {long long sr = sqrt(x);return (sr * sr == x);}return false;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int > vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
string decimalToBinary(int n){ string s = bitset<64> (n).to_string();const auto loc1 = s.find('1'); if(loc1 != string::npos)return s.substr(loc1);return "0";}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int  gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int  expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m


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
    // cin>>t;
    while(t--){
  solve();
    }   
     return 0;
}
