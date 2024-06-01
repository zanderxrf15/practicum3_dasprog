#include <stdio.h>

int sequence(int n){
    if(n<=2){return 0;}
    else if(n<=4){return 1;}
    else if(n<=10){return sequence(n-1)+ sequence(n-2)+sequence(n-3);}
    return sequence(n-1)+ sequence(n-2);
}

int main(){
    int input, t;
    scanf("%d", &t);
    for(int i=0; i<t;i++){
        scanf("%d", &input);
        printf("%d\n", sequence(input));
    }

}
