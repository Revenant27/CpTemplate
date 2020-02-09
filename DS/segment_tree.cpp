// SEGMENT TREE
ll st[4*asz];
ll ara[asz];
ll f(ll l,ll r)
{
    return l+r;
}
void init(ll node,ll ss,ll sf)
{
    if(ss==sf)
    {
        st[node]=ara[ss];
        return;
    }
    ll mid=(ss+sf)/2;
    init(2*node,ss,mid);
    init(2*node+1,mid+1,sf);
    st[node]=f(st[2*node],st[2*node+1]);
}
//adds value
void update(ll node,ll ss,ll sf,ll pos,ll val)
{
    if(ss==sf)
    {
        st[node]+=val;
        return;
    }
    ll mid=(ss+sf)/2;
    if(pos<=mid)update(2*node,ss,mid,pos,val);
    else update(2*node+1,mid+1,sf,pos,val);
    st[node]=f(st[2*node],st[2*node+1]);
}
ll query(ll node,ll ss,ll sf,ll qs,ll qe)
{
    if(qs>sf||qe<ss||sf<ss)return 0;
    if(qs<=ss&&qe>=sf)return st[node];
    ll mid=(ss+sf)/2;
    return f(query(2*node,ss,mid,qs,qe),query(2*node+1,mid+1,sf,qs,qe));
}

