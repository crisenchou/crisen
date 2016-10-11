#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define true 1;
#define false 0;
#define ENCRYPT 1;
#define DECRYPT 2;

typedef int bool;

struct settings settings;


struct settings {
    int type;
    int pwd;
    char *filename;
};



static void settings_init(void) {
    settings.type = ENCRYPT; 
    settings.pwd = 123456;
    settings.filename = NULL; 
}


//读取文件并加密成串
void  getEncryptString(const char *filename, char *str, int e){
    int i=0;
    int c;
    FILE *fp;
    fp = fopen(filename, "r");
    while((c=getc(fp)) != EOF){
        str[i] = (char)(c ^ e);
        ++i;
    }
    fclose(fp);
}

//覆盖原文件
void coverFile(const char *filename, char *str){
    FILE *fp;
    fp = fopen(filename, "w+");
    fprintf(fp,"%s",str);
    fclose(fp);
}

//加密文件
void encrypt(const char *filename, const int e){
    
    char str[1000];
    getEncryptString(filename, str, e);
    coverFile(filename, str);
    printf("encrypt successful!\n");
}


//解密文件
void decrypt(const char *filename, const int e){
    char str[1000];
    getEncryptString(filename, str, e);
    coverFile(filename, str);
    
    printf("decrypt successful!\n");
}



int main(int argc,char *argv[]){

    int c;
    settings_init();
    /* process arguments */
    while (-1 != (c = getopt(argc, argv,
        "e"  /* encrypt*/
        "d"  /* decrypt*/
        "f:" /* set the file */
        "p:"  /* the encrypt password */
    ))) {
        switch(c){
        case 'e' :
            settings.type = ENCRYPT;
            break;
        case 'd' :
            settings.type = DECRYPT;
            break;
        case 'f' :
            settings.filename = optarg;
            break;
        case 'p' :
            settings.pwd = atoi(optarg);
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
    

    switch(settings.type){
        case 1 : 
            encrypt(settings.filename, settings.pwd);
            break;
        case 2 : 
            decrypt(settings.filename, settings.pwd);
            break;
        default : 
            printf("something wrong\n");
            return 1;
    }
    
}



/*
    1. fprintf 传送格式化输出到一个文件中
    2. fscanf  从一个流中执行格式化输入
    3. clearerr（清除文件流的错误旗标）
    4.fclose（ 关闭文件）
    5.fdopen （将文件描述词转为文件指针）
    6.feof  （ 检查文件流是否读到了文件尾）
    7.fflush（更新缓冲区）
    8.fgetc （由文件中读取一个字符）
    9.fgets  （由文件中读取一字符串）
    10.fileno  （返回文件流所使用的文件描述词）
    12.fputc  （将一指定字符写入文件流中）
    13.fputs  （将一指定的字符串写入文件内）
    14.fread   （从文件流读取数据）
    14.freopen  （ 打开文件）
    15.fseek  （移动文件流的读写位置）
    16.ftell   （取得文件流的读取位置）
    17.fwrite   （将数据写至文件流）
    18.getc  （由文件中读取一个字符）
    19.getchar  （由标准输入设备内读进一字符）
    20.gets   （由标准输入设备内读进一字符串）
    21.mktemp  （产生唯一的临时文件名）
    22.putc  （将一指定字符写入文件中）
    23.putchar   （将指定的字符写到标准输出设备）
    24.rewind  （重设文件流的读写位置为文件开头）
    25.setbuf   （设置文件流的缓冲区）
    26.setbuffer  （ 设置文件流的缓冲区）
    27.setlinebuf   （   设置文件流为线性缓冲区）
    28.setvbuf   （设置文件流的缓冲区）
    29.ungetc   （将指定字符写回文件流中）
*/
/*
    文件的打开操作 fopen 打开一个文件
    文件的关闭操作 fclose 关闭一个文件
    文件的读写操作 fgetc 从文件中读取一个字符
    fputc 写一个字符到文件中去
    fgets 从文件中读取一个字符串
    fputs 写一个字符串到文件中去
    fprintf 往文件中写格式化数据
    fscanf 格式化读取文件中数据
    fread 以二进制形式读取文件中的数据
    fwrite 以二进制形式写数据到文件中去
    getw 以二进制形式读取一个整数
    putw 以二进制形式存贮一个整数
    
    文件状态检查函数 feof 文件结束
    ferror 文件读/写出错
    clearerr 清除文件错误标志
    ftell 了解文件指针的当前位置
    rewind 反绕
    fseek 随机定位
*/
