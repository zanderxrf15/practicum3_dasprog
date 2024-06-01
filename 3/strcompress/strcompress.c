#include <stdio.h>

int D;
char M[10000], alphabet[26]={0};

void Printer();

void Compresser(){
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
               SC-=65;

                alphabet[SC]++;
                j++;
                }
            else if(SC<=122 && SC>=97){
                SC-=97;

                alphabet[SC]++;
                j++;
                }
        }
    Printer();

}

void StartHere(){
    scanf("%s",M);
    Compresser();
}

int main(){
    scanf("%d",&D);
    StartHere();
}

void Printer(){
    for(int i=0; i<26; i++){
        int SC =i;
        if(alphabet[i]==0){
            continue;
        }
        else if(alphabet[i]==1){
            printf("%c", (char)SC+97);
            alphabet[i]=0;
        }
        else{
            printf("[%d%c]", alphabet[i], (char)SC+97);
            alphabet[i]=0;
        }
    }
    D--;
    if(D>0){
        printf("\n");
        StartHere();
    }
}
