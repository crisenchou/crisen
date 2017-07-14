#include <stdio.h>
#include <string.h>

#define SIZE 4


char* longestCommonPrefix(char** strs, int strsSize) {
    char *first = strs[0];
    int i,j,length = strlen(first);
    char temp;
    char *prefix;
    
    printf("%d,%d",length,strsSize);
    
    for(i=0;i<length;i++){
        temp = first[0];
        printf("%c",temp);
        for(j=0;j<strsSize;j++){
            //if(temp != strs[j][i]){
                //break;
            //}
        }
        //prefix[0] = temp;
    }
    prefix[0] = 'a';
    //printf("%c",prefix);
    return prefix;
}


int main(){
	char *sting[SIZE] = {"aaa","abc","acc","acd"};
    char *prefix;
    prefix = longestCommonPrefix(sting,SIZE);
	//printf("the prefix is %s",prefix);
	getche();
}