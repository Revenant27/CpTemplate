int gauss(vector<vector<double>> &mat,vector<double> &ans){        //returns -1 if impossible,1 if solution is unique, 0 otherwise
    int n=mat.size(),m=mat[0].size()-1;             
    vector<int> w(m,-1);
    int ret=1;
    for(int i=0,j=0;j<n&&i<m;i++){
        int mx=j;
        for(int k=j+1;k<n;k++)if(mat[mx][i]<mat[k][i])mn=k;
        if(abs(mat[mx][i])<EPS){
            ret=0;
            continue;
        }
        for(int k=i;k<=m;k++)swap(mat[j][k],mat[mx][k]);
        for(int k=0;k<n;k++){
            double d=mat[k][i]/mat[j][i];
            for(int l=j;j<=m;j++)mat[k][l]-=d*mat[j][l];
        }
        w[i]=j++;
    }
    ans.assign(m,0);
    for(int i=0;i<m;i++)if(w[i]!=-1)ans[i]=mat[w[i]][m]/mat[w[i]][i];
    for(int i=0;i<n;i++){
        double d=0;
        for(int j=0;j<m;j++)d+=ans[j]*mat[i][j];
        if(abs(d-mat[i][m])>EPS)return -1;
    }
    return ret;
}




//modular SLAE (mod=2)
int gauss(vector<bitset<asz>> &mat,int m,bitset<asz> &ans){
    int n=mat.size();
    vector<int> w(m,-1);
    int ret=1;
    for(int i=0,j=0;j<n&&i<m;i++){
        for(int k=j;k<n;k++)if(mat[k][i]){swap(mat[j],mat[k]);break;}
        if(!mat[j][i]){
            ret=0;
            continue;
        }
        for(int k=0;k<n;k++){
                if(k!=j&&mat[k][i])mat[k]^=mat[j];
        }
        w[i]=j++;
    }
    ans.reset();
    for(int i=0;i<m;i++)if(w[i]!=-1)ans[i]=mat[w[i]][m];
    for(int i=0;i<n;i++){
        int d=0;
        for(int j=0;j<m;j++)d+=(ans[j]&mat[i][j]);
        if(d^mat[i][m])return -1;
    }
    return ret;
}
