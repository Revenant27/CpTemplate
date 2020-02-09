#define lastone(n) ((n)&(-(n)))
ll bit[asz];
void update(ll ind,ll val)
{
    for(++ind;ind<asz;ind+=lastone(ind))bit[ind]+=val;
}
ll query(ll a)
{
    ll s=0;
    for(++a;a>0;a-=lastone(a))s+=bit[a];
    return s;
}
ll query(ll a,ll b)
{
    return query(b)-query(a-1);
}
