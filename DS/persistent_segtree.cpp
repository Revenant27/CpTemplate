struct vert
{
    vert *l,*r;
    ll s;
    vert(ll s=0):s(s){l=NULL,r=NULL;}
};
vert* st[asz];
ll b[asz];
ll f(ll l,ll r)
{
    return l+r;
}
void init(vert* rt,ll ss,ll sf)
{
    if(ss==sf)
    {
        rt->s=b[ss];
        return;
    }
    ll mid=(ss+sf)/2;
    rt->l=new vert;
    rt->r=new vert;
    init(rt->l,ss,mid);
    init(rt->r,mid+1,sf);
    rt->s=f(rt->l->s,rt->r->s);
}
void update(vert* cur,vert* pre,ll ss,ll sf,ll pos,ll val)
{
    if(ss==sf)
    {
        cur->s=pre->s+val;
        return;
    }
    ll mid=(ss+sf)/2;
    if(pos<=mid)
    {
        cur->r=pre->r;
        cur->l=new vert;
        update(cur->l,pre->l,ss,mid,pos,val);
    }
    else
    {
        cur->l=pre->l;
        cur->r=new vert;
        update(cur->r,pre->r,mid+1,sf,pos,val);
    }
    cur->s=f(cur->l->s,cur->r->s);
}
ll query(vert *node,ll ss,ll sf,ll qs,ll qe)
{
    if(qs>sf||qe<ss||qs>qe)return 0;
    if(qs<=ss&&qe>=sf)return node->s;
    ll mid=(ss+sf)/2;
    return f(query(node->l,ss,mid,qs,qe),query(node->r,mid+1,sf,qs,qe));
}
ll solve(ll x,ll y,ll k,ll ind)
{
    ll lo=0,hi=ind;
    while(lo<hi)
    {
        ll mid=(lo+hi)/2;
        ll a=query(st[y],0,ind,0,mid);
        ll b=query(st[x-1],0,ind,0,mid);
        if(a-b<k)lo=mid+1;
        else hi=mid;
    }
    return lo;
}
