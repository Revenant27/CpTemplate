//ALL String data structure

ll sa[asz],rnk[asz];
priority_queue<ii,vector<ii>,greater<ii>> rad_sort[asz];
void create_sa(string &s)
{
    ll n=s.size();
    s+='$';
    for(int i=0;i<=n;i++)sa[i]=i,rnk[i]=s[i];
    for(int k=1;k<=25;k<<=1)
    {
        for(int i=0;i<=n;i++)
        {
            rad_sort[rnk[sa[i]]].push(ii((sa[i]+k)>n?0:rnk[sa[i]+k],sa[i]));
        }
        ll t=0,r=-1;
        ii a=ii(-1,-1);
        for(int i=0;i<=max(n,125);i++)
        {
            while(!rad_sort[i].empty())
            {
                sa[t++]=rad_sort[i].top().se;
                if(ii(i,rad_sort[i].top().fi)!=a)r++;
                rnk[sa[t-1]]=r;
                a=ii(i,rad_sort[i].top().fi);
                rad_sort[i].pop();
            }
        }
    }
    s.pop_back();
}
//sa
ll sa[asz],rnk[asz];
ll cnt[asz],ind[asz];
void cnt_sort(ll n,ll k)
{
    memset(cnt,0,sizeof cnt);
    for(int i=0;i<=n;i++)cnt[(i+k>n?0:rnk[i+k])]++;
    for(int i=0,s=0;i<=max(n,(ll)255);i++){int t=cnt[i];cnt[i]=s,s+=t;}
    for(int i=0;i<=n;i++)ind[cnt[(sa[i]+k>n?0:rnk[sa[i]+k])]++]=sa[i];
    for(int i=0;i<=n;i++)sa[i]=ind[i];
}
void create_sa(string &s)
{
    ll n=s.size();
    s+='$';
    for(int i=0;i<=n;i++)sa[i]=i,rnk[i]=s[i];
    for(int k=1;k<=n;k<<=1)
    {
        cnt_sort(n,k);
        cnt_sort(n,0);
        ll r=0;
        ind[sa[0]]=r;
        for(int i=1;i<=n;i++)
        {
            ind[sa[i]]=(rnk[sa[i-1]]==rnk[sa[i]]&&(sa[i-1]+k>n?0:rnk[sa[i-1]+k])==(sa[i]+k>n?0:rnk[sa[i]+k])?r:++r);
        }
        for(int i=0;i<=n;i++)rnk[i]=ind[i];
    }
    s.pop_back();
}

ii strmatch_with_sa(string &s,string &t)
{
    ll n=s.size(),m=t.size();
    ll lo=0,hi=n;
    while(lo<hi)
    {
        ll mid=(lo+hi)/2;
        if(s.compare(sa[mid],m,t)>=0)hi=mid;
        else lo=mid+1;
    }
    if(s.compare(sa[lo],m,t))return ii(-1,-1);
    ii ans;
    ans.fi=lo;
    lo=0,hi=n;
    while(lo<hi)
    {
        ll mid=(lo+hi+1)/2;
        if(s.compare(sa[mid],m,t)<=0)lo=mid;
        else hi=mid-1;
    }
    ans.se=lo;
    return ans;
}

ll LCP[asz],PLCP[asz],phi[asz];
void compute_lcp(string &s)
{
    create_sa(s);
    s+='$';
    phi[sa[0]]=-1;
    for(int i=1;i<s.size();i++)phi[sa[i]]=sa[i-1];
    for(int i=0;i<s.size();i++)
    {
        if(phi[i]==-1)
        {
            PLCP[i]=0;
            continue;
        }
        PLCP[i]=max((ll)0,PLCP[i-1]-1);
        while(PLCP[i]+i<s.size()&&s[PLCP[i]+i]==s[phi[i]+PLCP[i]])PLCP[i]++;
    }
    for(int i=0;i<s.size();i++)LCP[i]=PLCP[sa[i]];
    s.pop_back();
}
