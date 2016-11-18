#include <stdio.h>


void LeftShiftOne(char *s, int n);

void LeftRotateString(char *s, int n, int m);





int main(){
    char s[] = "crisen";
    LeftRotateString(s, 4, 2);
    
    printf("the string is %s",s);
}




void LeftRotateString(char* s, int n, int m){
    while(m--){
        LeftShiftOne(s, n);
    }
}



void LeftShiftOne(char* s, int n){
    char t = s[0];
    int i;
    for(i=1; i<n; i++)
        s[i-1] = s[i];
    s[n-1]=t;
}

