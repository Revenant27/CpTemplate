struct FFT{
    using cd=complex<double>;
    vector<cd> w[2];
    vector<int> r;
    int M=1;
    FFT(int n){
        int u=0;
        while(M<n)M<<=1,u++;
        r.resize(M);
        w[0].resize(M,cd(1));
        w[1].resize(M,cd(1));
        for(int i=1;i<M;i++){
            int l=__builtin_ctz(i);
            r[i]=r[i^(1<<l)]|(1<<(u-l-1));
            double d=2*PI*i/M;
            w[0][i]=cd(cos(d),sin(d));
            w[1][i]=cd(cos(d),-sin(d));
        }
    }
    void fft(vector<cd> &a,bool inv=false){
        for(int i=0;i<M;i++)if(i<r[i])swap(a[i],a[r[i]]);
        for(int len=2;len<=M;len<<=1){
            for(int i=0,inc=M/len;i<M;i+=len){
                for(int j=0,l=0;j<(len>>1);j++,l+=inc){
                    cd u=a[i+j],v=a[i+j+(len>>1)]*w[inv][l];
                    a[i+j]=u+v;
                    a[i+j+(len>>1)]=u-v;
                }
            }
        }
        if(inv){
            for(auto &x:a)x/=M;
        }
    }
    vector<ll> multiply(vector<ll> &a,vector<ll> &b){
//        assert(a.size()+b.size()<=M);
        vector<cd> v1(M),v2(M);
        for(int i=0;i<a.size();i++)v1[i]=a[i];
        for(int i=0;i<b.size();i++)v2[i]=b[i];
        fft(v1);
        fft(v2);
        for(int i=0;i<M;i++)v1[i]*=v2[i];
        fft(v1,1);
        vector<ll> res(M);
        for(int i=0;i<M;i++)res[i]=round(v1[i].real());
        return res;
    }
};

//slow implementation of fft
using cd=complex<double>;
void fft(vector<cd> &a,bool invert)
{
    ll n=a.size();
    if(n==1)return;
    vector<cd> a0,a1;
    for(int i=0;2*i<n;i++)
    {
        a0.push_back(a[2*i]);
        a1.push_back(a[2*i+1]);
    }
    fft(a0,invert);
    fft(a1,invert);
    double ang=2*PI/n*(invert?-1:1);
    cd w(1),wn(cos(ang),sin(ang));
    for(int i=0;2*i<n;i++)
    {
        a[i]=a0[i]+w*a1[i];
        a[i+n/2]=a0[i]-w*a1[i];
        if(invert)a[i]/=2,a[i+n/2]/=2;
        w*=wn;
    }
}

//Works faster
using cd=complex<double>;
void fft(vector<cd> &a, bool invert) {
    int n = a.size();
 
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
 
        if (i < j)
            swap(a[i], a[j]);
    }
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
vector<ll> multiply(vector<ll> &a,vector<ll> &b)
{
    vector<cd> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    ll n=1;
    while(n<a.size()+b.size())n<<=1;
    fa.resize(n),fb.resize(n);
    fft(fa,false),fft(fb,false);
    for(int i=0;i<n;i++)fa[i]*=fb[i];
    fft(fa,true);
    vector<ll> res(n);
    for(int i=0;i<n;i++)
    {
        res[i]=round(fa[i].real());
    }
    return res;
}
