#include <stdio.h>

int D;
char M[1000000];

int Fibonacci(int n){
    if (n<=2)return 1;
    return Fibonacci(n-1)+Fibonacci(n-2);
}

int Simplify(int big){
    if(big>=26){
        return big%26;
    }
    else{
        return big;
    }
}

void encrypting();

void decrypting();

void StartHere(){
    int SN, ind;
    scanf("%d", &ind);
    if (ind==0){
        encrypting();
    }
    else if(ind==1){
        decrypting();
    }
    else{
        printf("Mode is not valid!");
    }
}

int main(){
    scanf("%d",&D);
    StartHere();

}

void decrypting(){
    int SN;
    scanf("%d %[^\n]s", &SN, M);
    SN=Fibonacci(SN);
    SN=Simplify(SN);
    int j=0, SC;
    while(M[j]!='\0'){
            SC= M[j];

            if(SC>=48 && SC<=57){
                j++;
                continue;
            }
            else if(SC==32){
                j++;
                continue;
            }
            if(SC<=90 && SC>=65){
               SC-=SN;

                if(SC>90 || SC<65){
                    SC+=26;
                }

                M[j]=(char)(SC);
                j++;
                }
            else if(SC<=122 && SC>=97){
                SC-=SN;

                if(SC>122 || SC<97){
                    SC+=26;
                }
                M[j]=(char)(SC);
                j++;
                }
        }
        printf("\n%s", M);
        D--;
        if(D>0)StartHere();
}

void encrypting(){
    int SN;
    scanf("%d %[^\n]s", &SN, M);
    SN=Fibonacci(SN);
    SN=Simplify(SN);
    int j=0, SC;
    while(M[j]!='\0'){
            SC = M[j];

            if(SC>=48 && SC<=57){
                j++;
                continue;
            }
            else if(SC==32){
                j++;
                continue;
            }
            if(SC<=90 && SC>=65){
               SC+=SN;

                if(SC>90 || SC<65){
                    SC-=26;
                }

                M[j]=(char)(SC);
                j++;
                }
            else if(SC<=122 && SC>=97){
                SC+=SN;

                if(SC>122 || SC<97){
                    SC-=26;
                }
                M[j]=(char)(SC);
                j++;
                }
        }
        printf("\n%s", M);
        D--;
        if(D>0)StartHere();
}
