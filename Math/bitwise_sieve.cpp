int bs[(asz+63)/64];
ll prime[asz];
ll prime_ind=0;

bool isprime(ll x)
{
    if(x==2||x==3)return true;
    if(x%2==0||x%3==0)return false;
    return !(bs[x/64] & (1 << ((x >> 1) & 31)));
}
void make_comp(ll x)
{
    bs[x/64] |= (1 << ((x >> 1) & 31));
}
void sieve()
{
    ll k=2;
    prime[prime_ind++]=2;
    prime[prime_ind++]=3;
    for(ll i=5;i<asz;i+=k,k=6-k)
    {
        if(isprime(i)){

            prime[prime_ind++]=i;
            ll r;
                if(i%6==1)r=4;
        else r=2;
            if((long long)i*i<asz)for(ll j=i*i;j<asz;j+=r*i,r=6-r)make_comp(j);
        }
    }
}

