struct vertex{
    int link,len;
    map<char,int> next;
    vertex(){
        link=-1,len=0;
    }
};
vertex sa[asz*2];
int last=0,sz=1;
void add_char(char c){
    int cur=sz++;
    sa[cur].len=sa[last].len+1;
    int u=last;
    while(u!=-1&&sa[u].next.count(c)==0){
        sa[u].next[c]=cur;
        u=sa[u].link;
    }
    if(u==-1)
        sa[cur].link=0;
    else{
        int v=sa[u].next[c];
        if(sa[u].len==sa[v].len-1)
            sa[cur].link=v;
        else{
            int nw=sz++;
            sa[nw].link=sa[v].link;
            sa[nw].len=sa[u].len+1;
            sa[nw].next=sa[v].next;
            while(u!=-1&&sa[u].next[c]==v){
                sa[u].next[c]=nw;
                u=sa[u].link;
            }
            sa[v].link=sa[cur].link=nw;
        }
    }
    last=cur;
}
