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



//To retrieve the neg cycle
void solve()
{
    vector<int> d (n, INF);
    d[v] = 0;
    vector<int> p (n - 1);
    int x;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        cout << "No negative cycle from " << v;
    else
    {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur])
        {
            path.push_back (cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse (path.begin(), path.end());

        cout << "Negative cycle: ";
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] << ' ';
    }
}
