
//2 sat
set<ll> adj[2][asz];
ll vis[asz],comp[asz],sat[asz];
vi ts;
void dfs(ll ind,ll r,ll d=-1)
{
    vis[ind]=1;
    if(r)comp[ind]=d;
    for(auto x:adj[r][ind])
        if(vis[x]==0)dfs(x,r,d);
    if(!r)ts.push_back(ind);
}
bool solve_2_sat(ll n)
{
    for(int i=0; i<n; i++)if(vis[i]==0)dfs(i,0);
    memset(vis,0,sizeof vis);
    ll com=0;
    while(!ts.empty())
    {
        if(vis[ts.back()]==0)dfs(ts.back(),1,com++);
        ts.pop_back();
    }
    for(int i=0; i<n; i+=2)
    {
        if(comp[i]==comp[i+1])return false;
        sat[i/2]=comp[i]>comp[i+1];
    }
    return true;
}
