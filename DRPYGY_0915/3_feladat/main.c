#include <stdio.h>
#include <stdlib.h>
void filemasolo(char file[], char file2[]);


int main()
{
    char fnev[50];
    char fnev2[50];
    printf("Masolando file: ");
    scanf("%s", fnev);
    printf("Masolat neve: ");
    scanf("%s", fnev2);
    filemasolo(fnev,fnev2);
    return 0;
}

void filemasolo(char file[], char file2[]){
    FILE *fp;
    FILE *fp2;
    char ch;
    fp = fopen(file,"r");
    fp2 = fopen(file2,"w");
    while((ch = getc(fp)) != EOF) {
        putc(ch,fp2);
    }
    fclose(fp2);
    fclose(fp);
}
