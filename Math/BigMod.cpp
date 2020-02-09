

ll fastpow(ll val,ll pwr,ll md=0)
{
    if(pwr==0)return 1;
    if(md){
    if(pwr%2)return (val*fastpow((val*val)%md,pwr/2,md))%md;
    return fastpow((val*val)%md,pwr/2,md);
    }
    else
    {
        if(pwr%2)return val*fastpow(val*val,pwr/2);
        return fastpow(val*val,pwr/2);
    }
}
