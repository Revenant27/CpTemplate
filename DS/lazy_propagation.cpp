ll st[4*asz];
ll lz[4*asz];
ll ara[asz];
ll f(ll l,ll r)
{
    return l+r;
}
void propagate(int node,int ss,int sf)
{
    if(lz[node]==0)return;
    st[node]+=(sf-ss+1)*lz[node];
    if(ss!=sf)
    {
        lz[2*node]+=lz[node];
        lz[2*node+1]+=lz[node];
    }
    lz[node]=0;
}
void init(int node,int ss,int sf)
{
    if(ss==sf)
    {
        st[node]=ara[ss];
        return;
    }
    int mid=(ss+sf)>>1;
    init(2*node,ss,mid);
    init(2*node+1,mid+1,sf);
    st[node]=f(st[2*node],st[2*node+1]);
}
void update(int node,int ss,int sf,int qs,int qe,ll val)
{
    propagate(node,ss,sf);
    if(qs>sf||qe<ss||sf<ss)return;
    if(qs<=ss&&qe>=sf)
    {
        lz[node]+=val;
        propagate(node,ss,sf);
        return;
    }
    int mid=(ss+sf)>>1;
    update(2*node,ss,mid,qs,qe,val);
    update(2*node+1,mid+1,sf,qs,qe,val);
    st[node]=f(st[2*node],st[2*node+1]);
}

ll query(int node,int ss,int sf,int qs,int qe)
{
    propagate(node,ss,sf);
    if(qs>sf||qe<ss||sf<ss)return 0;
    if(qs<=ss&&qe>=sf)return st[node];
    int mid=(ss+sf)>>1;
    return f(query(2*node,ss,mid,qs,qe),query(2*node+1,mid+1,sf,qs,qe));
}
