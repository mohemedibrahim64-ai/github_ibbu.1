#include <stdio.h>
int main(){
    int a;
    int b;
    char c;
    scanf ("%d",&a);
    scanf (" %c",&c);
    scanf ("%d",&b);
    if(c=='+'){
        printf("%d",a+b);
    }
    if(c=='-'){
        printf("%d",a-b);
    }
    if(c=='*'){
        printf("%d",a*b);
    }

}