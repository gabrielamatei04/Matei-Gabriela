//Matei Gabriela Florentina Luana Grupa 164
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<inttypes.h>
#define NUME_MAX 50
#define GRUPA_SANGE 4

struct fisa
{
    char nume[NUME_MAX];
    char prenume[NUME_MAX];
    char CNP[14];
    char grupa_sange[GRUPA_SANGE];
    int varsta;
    int greutate;
};

enum OP
{
    CITIRE_FISIER=0,
    CREATI_FISA,
    ACTUALIZEAZA_DATE,
    AFISARE_DATE,
    SELECTEAZA_FISA,
    STERGETI_FISA,
    ALEGERE_FISA,
    IESITI_FISA
};

enum UPDATE
{
    Numele=1,
    Prenumele,
    CNP,
    Grupa,
    Varsta,
    Greutate
};


void OP_MENIU()
{
    printf("ALEGETI UNA DINTRE URMATOARELE OPTIUNI\n");
    printf("----------------------------------------\n");
    printf("0.Citirea fiselor din fisier.\n");
    printf("1.Creati fisa unui donator.\n");
    printf("2.Schimbati datele din fisa unui donator existent.\n");
    printf("3.Afisati datele din fisele donatorilor.\n");
    printf("4.Selecteaza fisa unui pacient dupa CNP.\n");
    printf("5.Stergeti fisa unui pacient.\n");
    printf("6.Alegeti donatori pentru transfuzie.\n");
    printf("----------------------------------------\n");
}

void creati_fisa(struct fisa *date)
{ int a=1, b=1;
    FILE *fise;
    printf("CREATI FISA UNUI DONATOR");
    fise=fopen("fise.txt", "a");
    printf("\n");
    printf("Nume:");
    scanf("%s", date->nume);
    fprintf(fise, "%s\n", date->nume);
    printf("Prenume:");
    scanf("%s", date->prenume);
    fprintf(fise, "%s\n", date->prenume);
while(a==1){
    printf("CNP:");
    scanf("%s", date->CNP);
    if(strlen(date->CNP) != 13)
    {
        printf("CNP-ul introdus este gresit. Incercati din nou. ");
        printf("\n");
        a=1;
    }
    else a=0; }
    fprintf(fise, "%s\n", date->CNP);
    while(b==1){
    printf("Grupa sanguina:");
    scanf("%s", date->grupa_sange);
    if (strcmp("O1", date->grupa_sange)!=0 && strcmp("A2", date->grupa_sange)!=0 && strcmp("B3", date->grupa_sange)!=0 && strcmp("AB4", date->grupa_sange)!=0)
    {
        printf("Nu exista aceasta grupa de sange. Incercati din nou. ");
        printf("\n");
        b=1;
    }
    else b=0; }
    fprintf(fise, "%s\n", date->grupa_sange);
    printf("Varsta:");
    scanf("%d", &date->varsta);
    if(date->varsta < 18)
    {
        printf("Persoanele care nu au indeplinit varsta de 18 ani, nu pot dona. Va multumim pentru intelegere! ");
        return ;
    }
    fprintf(fise, "%d\n", date->varsta);
    printf("Greutate:");
    scanf("%d", &date->greutate);
    if(date->greutate <50)
    {
        printf("Nu se recomanda persoanelor avand greutatea sub 50kg sa doneze. Va multumim pentru intelegere! ");
        return ;
    }
    fprintf(fise, "%d\n", date->greutate);
    fclose(fise);
}

void adauga_fisa(int *n, struct fisa fisa_noua, struct fisa **baza_date)
{
    struct fisa *baza_date_nou;
    if(*n==0)
    {
        (*n)++;
        *baza_date = (struct fisa *)malloc(sizeof(struct fisa));
        (*baza_date)[0] = fisa_noua;
    }
    else (*n)++;
    baza_date_nou = (struct fisa *)realloc(*baza_date, (*n)*sizeof(struct fisa));
    if(baza_date_nou == NULL)
    {
        printf("Ati depasit limita de fise!");
        return ;
    }
    else
    {
        *baza_date = baza_date_nou;
        (*baza_date)[(*n) - 1] = fisa_noua;
    }
}


void actualizati_date(int n, struct fisa *baza_date)
{
    char CNP_[14], gasit = 0;
    printf("Introduceti CNP-ul donatorlui.");
    scanf("%s",CNP_);
    for(int i = 0; i < n; i++)
    {
        if(strcmp(baza_date[i].CNP, CNP_)==0)
        {
            gasit = 1;
            printf("Ce date din fisa donatorului vreti sa actualizati?");
            printf("\n");
            printf("----------------------------------------------------\n");
            printf("1.Nume: %s",baza_date[i].nume);
            printf("\n");
            printf("2.Prenume: %s",baza_date[i].prenume);
            printf("\n");
            printf("3.CNP: %s",baza_date[i].CNP);
            printf("\n");
            printf("4.Grupa de sange: %s",baza_date[i].grupa_sange);
            printf("\n");
            printf("5.Varsta: %d",baza_date[i].varsta);
            printf("\n");
            printf("6.Greutaate: %d",baza_date[i].greutate);
            printf("\n");
            printf("----------------------------------------------------\n");
            enum UPDATE;
            int update;
            scanf("%d",&update);
            switch(update)
            { int a=1;
            case Numele:
                printf("Numele donatorului este:");
                scanf("%s", baza_date[i].nume);
                break;
            case Prenumele:
                printf("Prenumele donatorului este:");
                scanf("%s", baza_date[i].prenume);
                break;
            case CNP:
                while(a==1){
                printf("CNP-ul donatorului este:");
                scanf("%s", baza_date[i].CNP);
                if(strlen(baza_date[i].CNP) != 13)
                {
                    printf("CNP-ul introdus este gresit. Incercati din nou. ");
                    printf("\n");
                    a=1;
                }
                else a=0; }
                break;
            case Grupa:
                while(a==1)
                {
                    printf("Grupa de sange a donatorului este:");
                    scanf("%s", baza_date[i].grupa_sange);
                    if (strcmp("O1", baza_date[i].grupa_sange)!=0 && strcmp("A2",  baza_date[i].grupa_sange)!=0 && strcmp("B3",  baza_date[i].grupa_sange)!=0 && strcmp("AB4",  baza_date[i].grupa_sange)!=0)
                    {
                        printf("Nu exista aceasta grupa de sange. Incercati din nou. ");
                        printf("\n");
                        a=1;
                    }
                    else a=0; }
                    break;

            case Varsta:
                printf("Varsta donatorului este:");
                scanf("%d",&baza_date[i].varsta);
                if(baza_date[i].varsta < 18)
                {
                    printf("Persoanele cu varsta de sub 18 ani nu pot dona sange. Va multumim pentru intelegere! ");
                    printf("\n");
                    //stergere_date(*baza_date,n);
                    return ;
                }
                break;
            case Greutate:
                printf("Greutatea donatorului este:");
                scanf("%d",&baza_date[i].greutate);
                if(baza_date[i].greutate < 50)
                {
                    printf("Nu se recomanda persoanelor avand greutatea sub 50kg sa doneze. Va multumim pentru intelegere! ");
                    printf("\n");
                    //stergere_date(*baza_date,n);
                    return ;
                }
                break;
            }
        }

        FILE *f=fopen("fise.txt", "w");
        for(int j = 0; j < n; j++)
        {
            fprintf(f,"%s",baza_date[j].nume);
            fprintf(f, "%s",baza_date[j].prenume);
            fprintf(f, "%s",baza_date[j].CNP);
            fprintf(f, "%s",baza_date[j].grupa_sange);
            fprintf(f, "%d",baza_date[j].varsta);
            fprintf(f, "%d",baza_date[j].greutate);
            fprintf(f,"\n");
        }
        fclose(f);
    }
    if(gasit == 0) printf("Fisa donatorului nu exista!\n");
}

void afisare_date(struct fisa *baza_date, int n)
{
    if(n==0) printf("NU EXISTA DONATORI.");
    else
    {
        printf("FISELE DONATORILOR\n");
        for(int i=0; i<n; i++)
        {
            printf("Nume: %s", baza_date[i].nume);
            printf("\n");
            printf("Prenume: %s", baza_date[i].prenume);
            printf("\n");
            printf("CNP: %s", baza_date[i].CNP);
            printf("\n");
            printf("Grupa de sange: %s", baza_date[i].grupa_sange);
            printf("\n");
            printf("Varsta: %d", baza_date[i].varsta);
            printf("\n");
            printf("Greutate: %d", baza_date[i].greutate);
            printf("\n");
            printf("-------------------------------------------");
            printf("\n");
        }
        puts("\n");
    }
}

void alegere_donatori(int n, struct fisa *baza_date)
{
    char grupa[4];
    int ok=0;
    while(c==1){
    printf("Grupa care are nevoie de transfuzie este: ");
    scanf("%s", grupa);
    if (strcmp("O1", grupa)!=0 && strcmp("A2", grupa)!=0 && strcmp("B3", grupa)!=0 && strcmp("AB4", grupa)!=0)
    {
        printf("Nu exista aceasta grupa de sange. Incercati din nou. ");
        c=1;
    } else c=0}
    if(strcmp(grupa, "O1")==0)
    {
        ok=1;
        for(int i=0; i<n; i++)
        {
            if(strcmp(baza_date[i].grupa_sange, grupa)==0)
            {
                printf("Nume: %s", baza_date[i].nume);
                printf("\n");
                printf("Prenume: %s", baza_date[i].prenume);
                printf("\n");
                printf("CNP: %s", baza_date[i].CNP);
                printf("\n");
                printf("Grupa de sange: %s", baza_date[i].grupa_sange);
                printf("\n");
                printf("Varsta: %d", baza_date[i].varsta);
                printf("\n");
                printf("Greutate: %d", baza_date[i].greutate);
                printf("\n");
                printf("-------------------------------------------");
                printf("\n");

            }
        }
    }
    if(strcmp(grupa, "A2")==0)
    {
        ok=1;
        for(int i=0; i<n; i++)
        {
            if(strcmp(baza_date[i].grupa_sange, grupa)==0 || strcmp(baza_date[i].grupa_sange, "O1")==0)
            {
                printf("Nume: %s", baza_date[i].nume);
                printf("\n");
                printf("Prenume: %s", baza_date[i].prenume);
                printf("\n");
                printf("CNP: %s", baza_date[i].CNP);
                printf("\n");
                printf("Grupa de sange: %s", baza_date[i].grupa_sange);
                printf("\n");
                printf("Varsta: %d", baza_date[i].varsta);
                printf("\n");
                printf("Greutate: %d", baza_date[i].greutate);
                printf("\n");
                printf("-------------------------------------------");
                printf("\n");

            }
        }
    }

    if(strcmp(grupa, "B3")==0)
    {
        ok=1;
        for(int i=0; i<n; i++)
        {
            if(strcmp(baza_date[i].grupa_sange, grupa)==0 || strcmp(baza_date[i].grupa_sange, "O1")==0)
            {
                printf("Nume: %s", baza_date[i].nume);
                printf("\n");
                printf("Prenume: %s", baza_date[i].prenume);
                printf("\n");
                printf("CNP: %s", baza_date[i].CNP);
                printf("\n");
                printf("Grupa de sange: %s", baza_date[i].grupa_sange);
                printf("\n");
                printf("Varsta: %d", baza_date[i].varsta);
                printf("\n");
                printf("Greutate: %d", baza_date[i].greutate);
                printf("\n");
                printf("-------------------------------------------");
                printf("\n");

            }
        }
    }
    if(strcmp(grupa, "AB4")==0)
    {
        ok=1;
        for(int i=0; i<n; i++)
        {
            if(strcmp(baza_date[i].grupa_sange, grupa)==0 || strcmp(baza_date[i].grupa_sange, "A2")==0 || strcmp(baza_date[i].grupa_sange, "B3")==0 || strcmp(baza_date[i].grupa_sange, "O1")==0)
            {
                printf("Nume: %s", baza_date[i].nume);
                printf("\n");
                printf("Prenume: %s", baza_date[i].prenume);
                printf("\n");
                printf("CNP: %s", baza_date[i].CNP);
                printf("\n");
                printf("Grupa de sange: %s", baza_date[i].grupa_sange);
                printf("\n");
                printf("Varsta: %d", baza_date[i].varsta);
                printf("\n");
                printf("Greutate: %d", baza_date[i].greutate);
                printf("\n");
                printf("-------------------------------------------");
                printf("\n");

            }
        }
    }
    if(ok==0) printf("Nu au fost gasiti donatori compatibili. ");
}

void selecteaza_donator(int n, struct fisa *baza_date)
{ int d=1;
    char CNP_[14];
    while(d==1){
    printf("CNP-ul donatorului cautat este: ");
    scanf("%s", CNP_);
    for(int i=0; i<n; i++)
    {
        if(strcmp(baza_date[i].CNP, CNP_)==0)
        { d=0;
            printf("\n");
            printf("Nume:%s",baza_date[i].nume);
            printf("\n");
            printf("Prenume:%s",baza_date[i].prenume);
            printf("\n");
            printf("CNP:%s",baza_date[i].CNP);
            printf("\n");
            printf("Grupa de sange:%s",baza_date[i].grupa_sange);
            printf("\n");
            printf("Varsta:%d",baza_date[i].varsta);
            printf("\n");
            printf("Greutate:%d",baza_date[i].greutate);
            break;
        }
        else
        {
            printf("CNP-ul adaugat este gresit. Nu a fost gasit niciun donator cu acest CNP in baza noastra de date. Va rugam reincercati.");
            printf("\n");
            d==1;

        }
    }
}

void stergere_date( struct fisa *baza_date, int *n)
{
    int i, ok=0;
    char CNP_[14];
    printf("Introduceti CNP-ul donatorului al carei fise vreti sa o stergeti: ");
    scanf("%s", CNP_);
    for(i = 0; i < *n; i++)
        if(strcmp(baza_date[i].CNP,CNP_)==0)
        {
            ok=1;
            for(int j=i; j<(*n) - 1; j++) (baza_date)[j]=(baza_date)[j+1];

            (*n)--;
            for(int j = 0; j < *n; j++)
            {
                printf("Nume: %s\n",baza_date[j].nume);
                printf("Prenume: %s\n",baza_date[j].prenume);
                printf("CNP: %s\n",baza_date[j].CNP);
                printf("Grupa de sange: %s\n",baza_date[j].grupa_sange);
                printf("Varsta: %d\n",baza_date[j].varsta);
                printf("Greutate: %d\n",baza_date[j].greutate);
            }

            FILE *f = fopen("fise.txt", "w");
            for(int j=0; j<*n; j++)
            {
                fprintf(f,"%s\n",baza_date[j].nume);
                fprintf(f, "%s\n",baza_date[j].prenume);
                fprintf(f, "%s",baza_date[j].CNP);
                fprintf(f,"\n");
                fprintf(f, "%s\n",baza_date[j].grupa_sange);
                fprintf(f, "%d",baza_date[j].varsta);
                fprintf(f,"\n");
                fprintf(f, "%d",baza_date[j].greutate);
                fprintf(f,"\n");
            }
            fclose(f);
            break;
        }
    if(ok==1) printf("Fisa stersa, au rama %d fise!", *n);
    else printf("Nu exista fisa cu acest CNP. Incercati din nou. ");
}


void citire_fise(int *n, struct fisa **baza_date)
{
    FILE *f=fopen("fise.txt", "r");
    if(f==NULL)
    {
        printf("Eroare la citirea fisierului!");
        return ;
    }
    else
    {
        printf("Fisier deschis pentru citire...\n");
        *n=0;
        *baza_date=NULL;
        struct fisa date;
        while( fscanf(f,"%s", date.nume)==1)
        {
            fscanf(f, "%s",date.prenume);
            fscanf(f, "%s",&date.CNP);
            fscanf(f, "%s",date.grupa_sange);
            fscanf(f, "%d",&date.varsta);
            fscanf(f, "%d",&date.greutate);
            adauga_fisa(n, date, baza_date);
        }
    }

    fclose(f);
}


int meniu(int *n, struct fisa **baza_date)
{
    int open;
    struct fisa fisa_noua;
    OP_MENIU();
    enum OP;
    int op;
    scanf("%d",&op);
    switch (op)
    {
    case CITIRE_FISIER:
        citire_fise(n, baza_date);
        break;
    case CREATI_FISA:
        creati_fisa(&fisa_noua);
        adauga_fisa(n,fisa_noua,baza_date);
        break;
    case ACTUALIZEAZA_DATE:
        actualizati_date(*n,*baza_date);
        break;
    case AFISARE_DATE:
        afisare_date(*baza_date, *n);
        break;
    case SELECTEAZA_FISA:
        selecteaza_donator(*n, *baza_date);
        break;
    case STERGETI_FISA:
        stergere_date(*baza_date,n);
        break;
    case ALEGERE_FISA:
        alegere_donatori(*n, *baza_date);
        break;
    case IESITI_FISA:
        exit(0);
        break;
    }
    puts("\n");
    printf("Apasati tasta 0 si enter pentru a reveni in meniul principal.");
    scanf("%d",&open);
    return open;
}

int main()
{
    struct fisa *baza_date;
    struct fisa date_p;
    int n=0;
    int open=1;
    while(open==1) meniu(&n,&baza_date);

    return 0;
}
