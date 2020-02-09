
ll discrete_log(ll base,ll result,ll md)
{
    ll n=ceil(sqrt(md));
    if(result==1)return 0;
    ll e=1,f=0;
    ll x=1;
    memset(val,-1,sizeof val);
    memset(indx,-1,sizeof indx);
    memset(prevs,-1,sizeof prevs);
    ind=0;
    for(ll d=__gcd(base,md);d!=1;d=__gcd(base,md))
    {
        if(result%d)return __INT64_MAX__;
        result/=d,md/=d;
        e=(e*base/d)%md;
        f++;
        if(result==e)return f;
    }
    for(ll i=0;i<n;i++)x=(x*base)%md;
    ll np=e;
    for(ll i=1;i<=n;i++)
    {
        np=(np*x)%md;
        if(fnd(np)==-1)insrt(np,i);
    }
    ll ans=__INT64_MAX__;
    for(ll i=0;i<n;i++)
    {
        ll y=fnd(result);
        if(y!=-1)ans=min(ans,y*n-i+f);
        result=(result*base)%md;
    }
    return ans;
}
