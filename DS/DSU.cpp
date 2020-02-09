class Unionfind
{
public:
    vi p,rnk;
    Unionfind(int N){p.assign(N,0);rnk.assign(N,1);for(int i=0;i<N;i++)p[i]=i;}
    int findset(int i){return (p[i]==i)?i:findset(p[i]);}
    bool sameset(int i,int j){return findset(i)==findset(j);}
    void unionset(int i,int j)
    {
        if(!sameset(i,j))
        {
            int x=findset(i),y=findset(j);
            if(rnk[x]>rnk[y])p[y]=x,rnk[x]+=rnk[y],rnk[y]=0;
            else {p[x]=y;rnk[y]+=rnk[x],rnk[x]=0;}
        }
    }
};
