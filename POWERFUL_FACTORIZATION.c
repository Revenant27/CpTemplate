#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000
typedef long long int ll;
typedef pair<ll,ll> ii;
typedef pair<ii,ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define getbit(n,i) (((n)&(1<<(i)))!=0)
#define setbit0(n,i) ((n)&(~(1<<(i))))
#define setbit1(n,i) ((n)|(1<<(i)))
#define togglebit(n,i) ((n)^(1<<(i)))
#define lastone(n) ((n)&(-(n)))
#define read freopen("debug\\in.txt","r",stdin)
#define write freopen("debug\\out.txt","w",stdout)
#define fi first
#define se second
#define getI(a) scanf("%d",&a)
#define getII(a,b) scanf("%d%d",&a,&b)
#define PI (acos(-1))
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL)
//#define mod (1000000007)
#define asz 10000000

    #define EL printf("\n")
    #define pb push_back
    #define FOR(i,l,r) for (int i=l;i<=r;i++)
    #define FORD(i,r,l) for (int i=r;i>=l;i--)

    const int base = 1e9;
    typedef vector<int> BigInt;

    void Set(BigInt &a) {
        while (a.size() > 1 && a.back() == 0) a.pop_back();
    }

    void Print(BigInt a) {
        Set(a);
        printf("%d", (a.size() == 0) ? 0 : a.back());
        FORD(i,a.size()-2,0) printf("%09d", a[i]);
    }

    BigInt Integer(string s) {
        BigInt ans;
        if (s[0] == '-') return ans;
        if (s.size() == 0) {ans.pb(0); return ans;}
        while (s.size()%9 != 0) s = '0'+s;
        for (int i=0;i<s.size();i+=9) {
            int v = 0;
            for (int j=i;j<i+9;j++) v = v*10+(s[j]-'0');
            ans.insert(ans.begin(),v);
        }
        Set(ans);
        return ans;
    }

    BigInt Integer(char c[]) {
        string s = "";
        FOR(i,0,strlen(c)-1) s = s + c[i];
        return Integer(s);
    }

    BigInt Integer(ll x) {
        string s = "";
        while (x > 0) s = char(x%10+'0') + s, x /= 10;
        return Integer(s);
    }

    BigInt Integer(int x) {
        return Integer((ll) x);
    }

    istream& operator >> (istream &in, BigInt &a) {
        string s;
        getline(cin, s);
        a = Integer(s);
        return in;
    }

    ostream& operator << (ostream &out, BigInt a) {
        Print(a);
        return out;
    }

    bool operator < (BigInt a, BigInt b) {
        Set(a);
        Set(b);
        if (a.size() != b.size()) return (a.size() < b.size());
        FORD(i,a.size()-1,0)
            if (a[i] != b[i]) return (a[i] < b[i]);
        return false;
    }

    bool operator > (BigInt a, BigInt b) {
        return (b < a);
    }

    bool operator == (BigInt a, BigInt b) {
        return (!(a < b) && !(b < a));
    }

    bool operator <= (BigInt a, BigInt b) {
        return (a < b || a == b);
    }

    bool operator >= (BigInt a, BigInt b) {
        return (b < a || b == a);
    }

    bool operator < (BigInt a, int b) {
        return (a < Integer(b));
    }

    bool operator > (BigInt a, int b) {
        return (a > Integer(b));
    }

    bool operator == (BigInt a, int b) {
        return (a == Integer(b));
    }

    bool operator >= (BigInt a, int b) {
        return (a >= Integer(b));
    }

    bool operator <= (BigInt a, int b) {
        return (a <= Integer(b));
    }

    BigInt max(BigInt a, BigInt b) {
        if (a > b) return a;
        return b;
    }

    BigInt min(BigInt a, BigInt b) {
        if (a < b) return a;
        return b;
    }

    BigInt operator + (BigInt a, BigInt b) {
        Set(a);
        Set(b);
        BigInt ans;
        int carry = 0;
        FOR(i,0,max(a.size(), b.size())-1) {
            if (i < a.size()) carry += a[i];
            if (i < b.size()) carry += b[i];
            ans.pb(carry%base);
            carry /= base;
        }
        if (carry) ans.pb(carry);
        Set(ans);
        return ans;
    }

    BigInt operator + (BigInt a, int b) {
        return a + Integer(b);
    }

    BigInt operator ++ (BigInt &a) { // ++a
        a = a + 1;
        return a;
    }

    void operator += (BigInt &a, BigInt b) {
        a = a + b;
    }

    void operator += (BigInt &a, int b) {
        a = a + b;
    }

    BigInt operator - (BigInt a, BigInt b) {
        Set(a);
        Set(b);
        BigInt ans;
        int carry = 0;
        FOR(i,0,a.size()-1) {
            carry += a[i] - (i < b.size() ? b[i] : 0);
            if (carry < 0) ans.pb(carry+base), carry = -1;
            else ans.pb(carry), carry = 0;
        }
        Set(ans);
        return ans;
    }

    BigInt operator - (BigInt a, int b) {
        return a - Integer(b);
    }

    void operator -- (BigInt &a) { // --a
        a = a - 1;
    }

    void operator -= (BigInt &a, BigInt b) {
        a = a + b;
    }

    void operator -= (BigInt &a, int b) {
        a = a - b;
    }

    BigInt operator * (BigInt a, BigInt b) {
        Set(a);
        Set(b);
        BigInt ans;
        ans.assign(a.size()+b.size(), 0);
        FOR(i,0,a.size()-1) {
            ll carry = 0ll;
            for (int j=0;j<b.size() || carry > 0;j++) {
                ll s = ans[i+j] + carry + (ll)a[i]*(j<b.size()?(ll)b[j]:0ll);
                ans[i+j] = s%base;
                carry = s/base;
            }
        }
        Set(ans);
        return ans;
    }

    BigInt operator * (BigInt a, int b) {
        return a * Integer(b);
    }

    void operator *= (BigInt &a, BigInt b) {
        a = a * b;
    }

    void operator *= (BigInt &a, int b) {
        a = a * b;
    }



    BigInt operator / (BigInt a, BigInt b) {
        Set(a);
        Set(b);
        if (b == Integer(0)) return Integer("-1");
        BigInt ans, cur;
        FORD(i,a.size()-1,0) {
            cur.insert(cur.begin(), a[i]);
            int x = 0, L = 0, R = base;
            while (L <= R) {
                int mid = (L+R)>>1;
                if (b*Integer(mid) > cur) {
                    x = mid;
                    R = mid-1;
                }
                else
                    L = mid+1;
            }
            cur = cur - Integer(x-1)*b;
            ans.insert(ans.begin(),x-1);
        }
        Set(ans);
        return ans;
    }

    BigInt operator / (BigInt a, int b) {
        Set(a);
        BigInt ans;
        ll cur = 0ll;
        FORD(i,a.size()-1,0) {
            cur = (cur*(ll)base + (ll)a[i]);
            ans.insert(ans.begin(),cur/b);
            cur %= b;
        }
        Set(ans);
        return ans;
    }

    void operator /= (BigInt &a, BigInt b) {
        a = a / b;
    }

    void operator /= (BigInt &a, int b) {
        a = a / b;
    }

    BigInt operator % (BigInt a, BigInt b) {
        Set(a);
        Set(b);
        if (b == Integer(0)) return Integer("-1");
        BigInt ans;
        FORD(i,a.size()-1,0) {
            ans.insert(ans.begin(), a[i]);
            int x = 0, L = 0, R = base;
            while (L <= R) {
                int mid = (L+R)>>1;
                if (b*Integer(mid) > ans) {
                    x = mid;
                    R = mid-1;
                }
                else
                    L = mid+1;
            }
            ans = ans - Integer(x-1)*b;
        }
        Set(ans);
        return ans;
    }

    int operator % (BigInt a, int b) {
        Set(a);
        if (b == 0) return -1;
        int ans = 0;
        FORD(i,a.size()-1,0)
            ans = (ans*(base%b) + a[i]%b)%b;
        return ans;
    }

    void operator %= (BigInt &a, BigInt b) {
        a = a % b;
    }

    void operator %= (BigInt &a, int b) {
        a = a % Integer(b);
    }

    BigInt gcd(BigInt a, BigInt b) {
        Set(a);
        Set(b);
        while (b > Integer(0)) {
            BigInt r = a%b;
            a = b;
            b = r;
        }
        Set(a);
        return a;
    }

    BigInt lcm(BigInt a, BigInt b) {
        return (a*b/gcd(a,b));
    }


    BigInt sqrt(BigInt a) {
        BigInt x0 = a, x1 = (a+1)/2;
        while (x1 < x0) {
            x0 = x1;
            x1 = (x1+a/x1)/2;
        }
        return x0;
    }

    BigInt pow(BigInt a, BigInt b) {
        if (b == Integer(0)) return Integer(1);
        BigInt tmp = pow(a, b/2);
        if (b%2 == 0) return tmp * tmp;
        return tmp * tmp * a;
    }

    BigInt pow(BigInt a, int b) {
        return pow(a,(Integer(b)));
    }

    int log(int n, BigInt a) { // log_n(a)
        Set(a);
        int ans = 0;
        while (a > Integer(1)) {
            ans++;
            a /= n;
        }
        return ans;
    }
    BigInt abs(BigInt x)
    {
        if(x<0)return Integer(0)-x;
        return x;
    }

//long long mult(long long a, long long b, long long mod) {
//    long long result = 0;
//    while (b) {
//        if (b & 1)
//            result = (result + a) % mod;
//        a = (a + a) % mod;
//        b >>= 1;
//    }
//    return result;
//}
BigInt f(BigInt a,BigInt c,BigInt mod)
{
    return (a*a+c)%mod;
}

BigInt brent(BigInt n, BigInt x0, BigInt c) {
    BigInt x = x0;
    BigInt g = Integer(1);
    BigInt q = Integer(1);
    BigInt xs, y;
    if(n==1)return n;
    int m = 128;
    int l = 1;
    while (g == 1) {
        y = x;
        for (int i = 1; i < l; i++)
            x = f(x, c, n);
        int k = 0;
        while (k < l && g == 1) {
            xs = x;
            for (int i = 0; i < m && i < l - k; i++) {
                x = f(x, c, n);
                q = (q* abs(y - x))%n;
            }
            g = gcd(q, n);
            k += m;
        }
        l *= 2;
    }
    if (g == n) {
        do {
            xs = f(xs, c, n);
            g = gcd(abs(xs - y), n);
        } while (g == 1);
    }
    return g;
}

BigInt fastpow(BigInt val,BigInt pwr,BigInt md)
{
    if(pwr==0)return Integer(1);
    if(pwr%2)return (val*fastpow((val*val)%md,pwr/2,md))%md;
    return fastpow((val*val)%md,pwr/2,md);
}

bool probablyPrimeFermat(BigInt n, int iter=20) {
    if (n < Integer(4))
        return n == Integer(2) || n == Integer(3);
    for (int i = 0; i < iter; i++) {
        BigInt a = Integer(rand()) % (n - 3)+2;
        if (fastpow(a, n - 1, n) != Integer(1))
            return false;
    }
    return true;
}

bitset<asz> bs(0);
ll prime[asz];
ll prime_ind=0;

// seive to generate all prime

void seive()
{
    bs[0]=bs[1]=1;
    for(ll i=2;i<asz;i++)
    {
        if(bs[i])continue;
        for(ll j=i*i;j<asz;j+=i)bs[j]=1;
        prime[prime_ind]=i;
        prime_ind++;
    }
}

void solve(map<BigInt,ll> &mp,BigInt n)
{
    for(int i=0;i<prime_ind;i++)
    {
        while(n%prime[i]==0)
        {
            mp[Integer(prime[i])]++;
            n/=prime[i];
        }
    }
    while(n>1)
    {
        BigInt x=brent(n,Integer(1+rand()%5),Integer(1+rand()%5));
        if(probablyPrimeFermat(x))
        {
            while(n%x==0)
            {
                mp[x]++;
                n/=x;
            }
        }
        else solve(mp,x),n/=x;
    }
}

int main()
{
    fastread;
    ll T=1;
//    cin>>T;
seive();
    for(ll qq=1;1;qq++)
    {

        BigInt n;
        cin>>n;
        if(n==1)
        {
            cout<<"1^1"<<endl;
            continue;
        }
        if(n==0)break;
        map<BigInt,ll> mp;
        solve(mp,n);
        for(auto &x:mp)
        {
            cout<<x.fi;
            fflush(stdout);
            printf("^%lld ",x.se);
            fflush(stdout);
        }
        cout<<endl;

    }
}
