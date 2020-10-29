class Unionfind
{
public:
    vi p,rnk;
    Unionfind(int N){p.assign(N,0);rnk.assign(N,1);for(int i=0;i<N;i++)p[i]=i;}
    int findset(int i){return p[i]=(p[i]==i)?i:findset(p[i]);}
    bool sameset(int i,int j){return findset(i)==findset(j);}
    void unionset(int i,int j)
    {
        int x=findset(i),y=findset(j);
        if(x!=y)
        {
            if(rnk[x]>rnk[y])p[y]=x;
            else p[x]=y,rnk[y]+=(rnk[x]==rnk[y]);
        }
    }
};
