#include "../prototype.h"

void disableEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void enableEcho() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

Date saisieDate(void)
{
    Date d;
    puts("Entrez une date [j,m,a]");
    // scanf("%d%d%d", &d.j, &d.m, &d.a);
    d.j = saisirInt(1, 31, "entrez le jour","entrer un jour valide");
    d.m = saisirInt(1, 12, "entrez le mois","entrer un mois valide");
    d.a = saisirInt(1, 2024, "entrez l'année","entrer une annee valide");
    return d;
}

int saisirInt(int min, int max, char msg[],char msgerr[])
{
    int x;
    do
    {
        puts(msg);
        scanf("%d", &x);
        if (x<min || x>max)
        {
           printf("%s\n", msgerr);
        }
        
    } while (x<min || x>max);

    return x;
}

void saisiChaine(char chaine[], char msg[],char msgerr[]){
            char caractere;
            int i = 0, j = 0, nbrEspace = 0;

            while(1){
                printf ("%s ", msg) ;
                caractere = getchar();

                while (caractere != '\n')
                {
                    if (caractere == ' ')
                    {
                        nbrEspace++;
                    }else chaine[i] = caractere; i++;

                    caractere = getchar();
                }
                if (i!=0)
                {
                    if (nbrEspace != strlen(chaine))
                    {
                        break;
                    }
                    
                }
                
                if (nbrEspace > 0 || caractere == '\n')
                {
                 printf("%s", msgerr);                   
                }    
            }
}


void saisiChainePassword(char chaine[], char msg[],char msgerr[]){
            char caractere;
            int i = 0, j = 0, nbrEspace = 0;
            disableEcho(); 
            while(1){
                printf ("%s ", msg) ;
                caractere = getchar();

                while (caractere != '\n')
                {
                    if (caractere == ' ')
                    {
                        nbrEspace++;
                    }else chaine[i] = caractere; i++;

                    caractere = getchar();
                }
                if (i!=0)
                {
                    if (nbrEspace != strlen(chaine))
                    {
                        break;
                    }
                    
                }
                
                if (nbrEspace > 0 || caractere == '\n')
                {
                 printf("%s", msgerr);                   
                }    
            }
        enableEcho();
}


int login(char login[],char pass[], Utilisateur utilisateurs[], int taille, Utilisateur * u){
   
    int type = 0;
    int cpt = 0;

    for (int i = 0; i < taille; i++)
    {
         if (!strcmp(utilisateurs[i].login,login) && !strcmp(utilisateurs[i].password,pass) )
        {
            u->id = utilisateurs[i].id;
            strcpy(u->mat, utilisateurs[i].mat);
            strcpy(u->login, login);
            strcpy(u->password, pass);
            strcpy(u->nom, utilisateurs[i].nom);
            strcpy(u->prenom, utilisateurs[i].prenom);
            u->date_naiss.j = utilisateurs[i].date_naiss.j;
            u->date_naiss.m = utilisateurs[i].date_naiss.m;
            u->date_naiss.a = utilisateurs[i].date_naiss.a;
            u->type = utilisateurs[i].type;
            return 1;
        }
    }
    return 0;
}

void obtenirDateAujourdhui(int *jour, int *mois, int *annee, int * h, int * mn, int * s) {
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    *jour = today->tm_mday;
    *mois = today->tm_mon + 1;
    *annee = today->tm_year + 1900;
    *h = today->tm_hour;
    *mn = today->tm_min;
    *s = today->tm_sec;
}

// void genererMat(char m[], Apprenant e){
//     char iP = e.prenom[0];
//     char iN = e.nom[0];
//     char id = e.id;
   
    
//     if (e.id > 0 && e.id <10)
//     {   
//       sprintf(m, "MAT-%c%c-000%d",toupper(e.prenom[0]),toupper(e.nom[0]), e.id);
//     }
//     if (e.id > 9 && e.id < 100)
//     {
//         sprintf(m, "MAT-%c%c-00%d",toupper(e.prenom[0]),toupper(e.nom[0]), e.id);
//     }
//     if (e.id > 99 && e.id < 1000)
//     {
//         sprintf(m, "MAT-%c%c-0%d",toupper(e.prenom[0]),toupper(e.nom[0]), e.id);
//     }
//     if (e.id > 999 && e.id < 10000)
//     {
//         sprintf(m, "MAT-%c%c-00%d",toupper(e.prenom[0]),toupper(e.nom[0]), e.id);
//     }

//     //  printf("%s\n", m);
// }