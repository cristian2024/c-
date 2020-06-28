#include <iostream>

using namespace std;

int * new_arreglo(int size){
    return new int[size];
}

int * mcd_e(int a, int b){
    
    //primero calculamos cual es el mayor y cual es el menor
    int a_1=(a>b)?a:b;
    int b_1=(a<b)?a:b;
    
    //este sera el arreglo que sera retornado, solo es una variable auxiliar
    /**
     *1era posicion=Maximo comun divisor 
     * 2da posicion= el valor del x correspondiente a la funcion (x*a_1+y*b_1)=MCD(a_1,b_1)
     * 3ra posicion= el valor del y correspondiente a la funcion (x*a_1+y*b_1)=MCD(a_1,b_1)
     */
    int * first=new_arreglo(3);
    
    //los primeros datos que se calculan son siempre los mismos
    int pri[]={a_1,0,1,0};
    int seg[]={b_1,(int)(a_1/b_1),0,1};
    
    //La variable val permite saber si tenemos que cargar los datos en el arreglo pri o en el arreglo seg
    bool val=1;
    while(pri[0]!=0&&seg[0]!=0){
        
        if(val){
            pri[0]=pri[0]%seg[0];
            pri[2]=pri[2]-(seg[1]*seg[2]);
            pri[3]=pri[3]-(seg[1]*seg[3]);
            
            //la posicion 2 del arreglo se carga con una division, pero como siempre llegara el punto de una division por 0, es preferible revisar antes de hacer la operacion
            if(pri[0]!=0&&seg[0]!=0){
                pri[1]=(int)(seg[0]/pri[0]);
            }
            
            //se modifica el booleano para que entre al otro arreglo
            val=0; 
        }else{
            
            seg[0]=seg[0]%pri[0];
            seg[2]=seg[2]-(pri[1]*pri[2]);
            seg[3]=seg[3]-(pri[1]*pri[3]);
            
            //la posicion 2 del arreglo se carga con una division, pero como siempre llegara el punto de una division por 0, es preferible revisar antes de hacer la operacion
            if(seg[0]!=0&&pri[0]!=0){
                seg[1]=(int)(pri[0]/seg[0]);
            }
            
            //se modifica el booleano para que entre al otro arreglo
            val=1;
        }
        
        
    }
    
   
    
    //con estas comparaciones se pretende definir cual fue el ultimo arreglo al que se le editaron los datos, esto con la idea de devolver los valores exactos
    if(val){
        first[0]=pri[0];
        first[1]=pri[2];
        first[2]=pri[3];
        
    }else{
        first[0]=seg[0];
        first[1]=seg[2];
        first[2]=seg[3];
    }
        
    return first;
        
        
    
}

int main(){
    int *r=mcd_e(55,300);
    cout<<r[1];
}
