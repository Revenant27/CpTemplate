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
void fft(vector<cd> &a,bool invert)
{
    ll n=a.size();
    ll lg_n=ceil(log2(n));
    for(ll i=1,x=0;i<n;i++)
    {
        ll bit=1<<n;
        for(;bit&x;bit>>=1)
            x^=bit;
        x^=bit;
        if(i<x)swap(a[i],a[x]);
    }
    for(ll l=2;l<=n;l<<=1)
    {
        double ang=2*PI/l*(invert?-1:1);
        cd wn(cos(ang),sin(ang));
        for(ll i=0;i<n;i+=l)
        {
           cd w(1);
           for(int j=0;2*j<l;j++)
           {
               cd u=a[i+j],v=a[i+j+l/2]*w;
               a[i+j]=u+v,a[i+j+l/2]=u-v;
               w*=wn;
           }
        }
    }
    if(invert)
    {
        for(int i=0;i<n;i++)a[i]/=n;
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
