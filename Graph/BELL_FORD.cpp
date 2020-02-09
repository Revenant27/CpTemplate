vii adj[asz];
bool bell_ford(vi &dis,ll ind)
{
    dis[ind]=0;
    ll n=dis.size();
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(auto x:adj[j])
            {
                dis[x.fi]=min(dis[x.fi],dis[j]+x.se);
            }
        }
    }
    bool neg_cycle=false;
    for(int j=0;j<n;j++)
    {
        for(auto x:adj[j])
        {
            if(dis[x.fi]>dis[j]+x.se)dis[x.fi]=dis[j]+x.se,neg_cycle=true;
        }
    }
    return neg_cycle;
}
