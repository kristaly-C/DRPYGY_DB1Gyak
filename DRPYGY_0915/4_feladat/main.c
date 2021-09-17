#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Kocsi {
   char  rendszam[6];
   int   ar;
   char  tipus[30];
};

void kereses(int n);

int main()
{

    int sorszam = 0;
    printf("Add meg a rekord sorszamat(0 az elso elem): ");
    scanf("%d",&sorszam);
    kereses(sorszam);
    return 0;
}

void kereses(int n){
    struct Kocsi kocsi;
    FILE *fptr;

    if((fptr = fopen("binaris.bin","rb")) == NULL){
        printf("ERROR! can not open");
        exit(1);
    }

    int darab=0;
    bool talalat = false;
    printf("\n%d.rekord keresese\n",n);

    fseek(fptr,sizeof(struct Kocsi), SEEK_END);
    int vege = ftell(fptr)-sizeof(struct Kocsi)*2;
    fseek(fptr,sizeof(struct Kocsi)*n, SEEK_SET);
    if(ftell(fptr) <= vege){
        fread(&kocsi,sizeof(struct Kocsi),1,fptr);
        printf("Adatok\nRendszam: %s\nTipus: %s\nAr: %d\n",kocsi.rendszam,kocsi.tipus,kocsi.ar);
    }else{
        printf("Nincs ennyi elem a listaban");
    }
    fclose(fptr);
}
