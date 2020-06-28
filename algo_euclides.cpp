#include <iostream>

using namespace std;

int mcd_e(int a, int b){
    
    int a_1=(a>b)?a:b;
    int b_1=(a<b)?a:b;
    
    int pri[]={a_1,0,1,0};
    int seg[]={b_1,(int)(a_1/b_1),0,1};
    
    int aux[4];
    
    bool val=1;
    while(pri[0]!=0&&seg[0]!=0){
        
        if(val){
           
            pri[0]=pri[0]%seg[0];
            pri[2]=pri[2]-(seg[1]*seg[2]);
            pri[3]=pri[3]-(seg[1]*seg[3]);
            
            if(pri[0]!=0&&seg[0]!=0){
                pri[1]=(int)(seg[0]/pri[0]);
            }
            
            val=0; 
        }else{
            
            seg[0]=seg[0]%pri[0];
            seg[2]=seg[2]-(pri[1]*pri[2]);
            seg[3]=seg[3]-(pri[1]*pri[3]);
            
            if(seg[0]!=0&&pri[0]!=0){
                
                seg[1]=(int)(pri[0]/seg[0]);
            }
            
            val=1;
        }
        
        
    }
    
   
    
    
    if(val){
        cout<<pri[0]<<"   x:"<<pri[2]<<"("<<a_1<<")"<<"   y:"<<pri[3]<<"("<<b_1<<")";
    }else{
        cout<<seg[0]<<"   x:"<<seg[2]<<"("<<a_1<<")"<<"   y:"<<seg[3]<<"("<<b_1<<")";
    }
        
    return 1;
        
        
    
}

int main(){
}