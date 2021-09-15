#include <stdio.h>
#include <stdlib.h>
void pelda_1(char fnev[]);

int main(){
    char fnev[50];
    printf("Filenev: ");
    scanf("%s", fnev);
    pelda_1(fnev);
    upperCase(fnev);
    return 0;
}

void pelda_1(char fnev[]){
    printf("Uzenet: ");
    FILE *fp;
    char ch;
    fp = fopen(fnev,"w");
    while((ch = getchar()) != '#'){
            putc(ch, fp);
    }
    fclose(fp);

    fp = fopen(fnev, "r");
    while((ch = getc(fp)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp);
    printf("\n--Elso blokk vege--\n");
}

void upperCase(char fnev[]){
    FILE *fp;
    char ch;
    int meret = 0;
    fp = fopen(fnev, "r");
    while((ch = getc(fp)) != EOF){
        meret++;
    }

    char uzenet[meret];
    int le = 0;

    fclose(fp);
    fp = fopen(fnev,"r");

    while((ch = getc(fp)) != EOF){
        uzenet[le] = ch;
        le++;
    }
    fclose(fp);
    char upUzenet[meret-1]; ///meret-1 mert az első karakter egy sortörés amit levágtam

    le = 1;
    while(le < meret){
        upUzenet[le-1] = (toupper(uzenet[le]));
        le++;
    }

    fp = fopen(fnev , "w");
    for(int i=0;i<meret-1;i++){
        putc(upUzenet[i],fp);
    }
    fclose(fp);

}
