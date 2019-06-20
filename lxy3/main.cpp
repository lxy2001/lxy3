#include <iostream>
#include <fstream>
using namespace std;
struct student{
    char num[10];
    char xueyuan[10];
    char xingming[10];
};
struct fenshu{
    char x;
    int fen[8]={0};
};
struct zuida{
    int e;
    int max;
};
struct zuixiao{
    int w;
    int min;
};
struct pingjun{
    int pj;
};
struct zuihou{
    int pj;
};
struct shuchu{
    int t;
};
int main (){
    int n=4,y=0;
    student m[n];
    fenshu f[n];
    zuida a[n];
    zuixiao b[n];
    pingjun c[n];
    zuihou cc[n];
    shuchu ss[n];
    ofstream in("/Users/s20181106279/Desktop/成绩.txt");
    ifstream outf("/Users/s20181106279/Desktop/ggg.txt");
    ifstream out("/Users/s20181106279/Desktop/eee.txt");
    if(out.is_open()){
        for(int i=0;i<n;i++){
            out>>m[i].num>>m[i].xueyuan>>m[i].xingming;
        }
        out.close();
    }
    if(outf.is_open()){
        for(int i=0;i<n;i++){
            outf>>f[n].x;
            for(int j=0;j<7;j++){
                outf>>f[i].fen[j];
            }
        }
        outf.close();
    }
    for(int i=0;i<n;i++){
        a[i].max=f[i].fen[0];
        a[i].e=0;
        b[i].min=f[i].fen[0];
        b[i].w=0;
        for(int j=1;j<7;j++){
            if(a[i].max<f[i].fen[j]){
                a[i].max=f[i].fen[j];
                a[i].e=j;
            }
            if(b[i].min>f[i].fen[j]){
                b[i].min=f[i].fen[j];
                b[i].w=j;
            }
        }
        double v=0;
        for(int k=0;k<7;k++){
            if(k!=a[i].e&&k!=b[i].w){
                v=v+f[i].fen[k];
            }
        }
        c[y].pj=v*1.0/5;
        cc[y].pj=v*1.0/5;
        y++;
    }
    double gg;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(cc[j].pj<cc[j+1].pj){
                gg=cc[j].pj;
                cc[j].pj=cc[j+1].pj;
                cc[j+1].pj=gg;
            }
        }
    }
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(cc[i].pj==c[j].pj){
                ss[i].t=j;
            }
        }
    }
    if(in.is_open())
    {
        for(int i=0;i<7;i++){
            in<<m[ss[i].t].num<<" "<<m[ss[i].t].xueyuan<<" "<<m[ss[i].t].xingming
            <<" "<<"paiming:"<<i+1<<" "<<"pingjunfen:"<<cc[i].pj<<endl;
        }
        in.close();
    }
    return 0;
    
}

