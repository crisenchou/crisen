#include <stdio.h>
#include <string.h>

#define SIZE 4


char* longestCommonPrefix(char** strs, int strsSize) {
    int i,j;
	int flag=0;
    char *prefix;
    for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(strncmp(strs[j],strs[j+1],i) != 0){
				break;
			}
		}
		prefix = strncpy(prefix,strs[0],i);
	}
	
	printf("this dstring is %s",prefix);
    return prefix;
}


int main(){
	char *sting[SIZE] = {"aaa","abc","acc","acd"};
    char *prefix;
    prefix = longestCommonPrefix(sting,SIZE);
	//printf("the prefix is %s",prefix);
	//getche();
}