vector<pair<int,int>> adj[200005];
bool spfa(int s,int n,vector<int> &dis)
{
    dis.assign(n+1,1000000000);
    dis[s]=0;
    queue<int> q;
    q.push(s);
    vector<bool> taken(n+1,0);
    vector<int> cnt(n+1,0);
    taken[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        taken[u]=0;
        for(auto x:adj[u])
        {
            if(dis[u]+x.second<dis[x.first])
            {
                dis[x.first]=dis[u]+x.second;
                if(!taken[x.first])
                {
                    q.push(x.first);
                    taken[x.first]=1;
                    cnt[x.first]++;
                    if(cnt[x.first]>n)
                        return true;
                }
            }
        }
    }
    return false;
}
