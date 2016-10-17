#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <string.h>


int main(int argc,char *argv[])
{

    int c;
    char *p;
    /* process arguments */
    while (-1 != (c = getopt(argc, argv,
          "a:"  /* add the two number */
          "m:"  /* minus the tow number */
        ))) {
            switch(c){
                case 'a' :
                    printf("%s\n",optarg);
                    p = strchr(optarg,',');
                    break;
                case ':' :
                    printf("missing value");
                    break;
                case '?' :
                    printf("illegal params");
                    break;
                default : 
                    printf("illegal params");
                    return 1;
            }
        }
    return 0;
}
