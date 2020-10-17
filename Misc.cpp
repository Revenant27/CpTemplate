mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


//factorial inverse (Linear)
invf[0]=invf[1]=1;
for(int i=2;i<asz;i++)invf[i]=(mod-(mod/i)*invf[mod%i]%mod)%mod;
