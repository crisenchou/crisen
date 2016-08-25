#include <stdio.h>

//输入一个字符串 并输出 并将连续的空格转换成单个
void inputString()
{
	char c,lastc='a';
	c = getchar();
	while(c != EOF){
		if(c!=' '){
			putchar(c);
			lastc = c;
			c = getchar();
		}else{
			if(lastc!=' '){
				putchar(c);
			}
			lastc =c;
			c = getchar();
		}
	}
}
int main()
{
	inputString();
	getche();
}