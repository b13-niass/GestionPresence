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

int testSiAnneeBissextile(int annee){

    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
            return 1;
    } else {
        return 0;
    }

}

int calculNbrJourMois(int mois, int annee){
    int nbrJour;

        if (mois == 2)
        {
            if (testSiAnneeBissextile(annee))
            {
                nbrJour = 29;
            }else{
                nbrJour = 28;
            }
        }else if (mois == 4 || mois == 6 || mois == 9 || mois == 11 )
        {
            nbrJour = 30;
        }else{
            nbrJour = 31;
        }

    return nbrJour;
}


int testSiDateValide(int annee, int mois, int jour){
    int validite;
    int nbrJours = calculNbrJourMois(mois, annee);
    // printf("%d", nbrJours);
    if (annee > 0)
    {
        if (0 < mois && mois < 13)
        {
            if (1 <= jour && jour <= nbrJours)
            {
                validite = 1;
            }else{
                validite = 0;
            }
            
        }else{
            validite = 0;
        }
        
    }else{
        validite = 0;
    }

    return validite;
}


Date saisieDate(void)
{
    Date d;
    d.j = 0;
    d.m = 0;
    d.a = 0;
    int j, m, a;
    puts("Entrez une date [j,m,a]");
    // scanf("%d%d%d", &d.j, &d.m, &d.a);


    j = saisirIntDate(1, 31, "entrez le jour","entrer un jour valide");
    m = saisirIntDate(1, 12, "entrez le mois","entrer un mois valide");
    a = saisirIntDate(1, 2024, "entrez l'année","entrer une annee valide");
    
    if(testSiDateValide(a, m, j)){
        d.j = j;
        d.m = m;
        d.a = a;
        return d;
    }else{
        return d;
    }

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

int saisirIntDate(int min, int max, char msg[],char msgerr[])
{
    int x;
    char input[100]; 
    do
    {
         printf("%s: ", msg);
        scanf("%s", input);

        // Tente de convertir la chaîne en un entier
        if (sscanf(input, "%d", &x) != 1 || x < min || x > max) {
            printf("%s\n", msgerr);
        }

        
    } while (x<min || x>max);

    return x;
}


int saisirDate(Date *date, char msg[], char msgerr[]) {
    char input[20];  // ajustez la taille selon vos besoins
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    do {
        printf("Entrez la date (format : jour/mois/annee) : ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Erreur de lecture.\n");
            return -1;
        }

        size_t length = strlen(input);
        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        if (sscanf(input, "%d/%d/%d", &date->j, &date->m, &date->a) != 3 || !testSiDateValide(date->a, date->m, date->j) 
        || (date->j > today->tm_mday && date->m >= today->tm_mon + 1 && date->a >= today->tm_year + 1900)) {
            printf("Date invalide. Veuillez réessayer.\n");
        } 
        // (date->j > today->tm_mday && date->m > today->tm_mon + 1 && date->a > today->tm_year + 1900)
    } while (!testSiDateValide(date->a, date->m, date->j) 
        || (date->j > today->tm_mday && date->m >= today->tm_mon + 1 && date->a >= today->tm_year + 1900));

    return 1;  // Succès
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
            chaine[i] = '\0';
        // printf("%s", chaine);
}

void saisiMessage(char chaine[], size_t size, char msg[], char msgerr[]) {
    printf("%s", msg);

    fgets(chaine, size, stdin);

    size_t len = strlen(chaine);
    if (len > 0 && chaine[len - 1] == '\n') {
        chaine[len - 1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    if (chaine[0] == '\0' || strchr(chaine, ' ') == NULL) {
        printf("%s", msgerr);
        saisiChaine(chaine, msg, msgerr);
    }
}

void saisiChainePassword(char chaine[], char msg[],char msgerr[]){
            char caractere;
            struct termios oldt, newt;
            int i = 0, j = 0, nbrEspace = 0;

            // Turn off echoing
            

            // Read password character by character
            // printf("Enter password: ");
            // while ((caractere = getchar()) != '\n') {
            //     putchar('*');
            //     chaine[i] = caractere;
            // }

            // Restore terminal settings
           


            while(1){
                tcgetattr(STDIN_FILENO, &oldt);
                newt = oldt;
                newt.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
                tcsetattr(STDIN_FILENO, TCSANOW, &newt);
                
                printf ("%s ", msg);
                caractere = getchar();
                putchar('*');
                while (caractere != '\n')
                {
                    if (caractere == ' ')
                    {
                        nbrEspace++;
                    }else chaine[i] = caractere; i++;

                    caractere = getchar();
                    putchar('*');

                }
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
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

                 chaine[i] = '\0';
            }

            
       
}


int login(char login[],char pass[], Utilisateur utilisateurs[], int taille, Utilisateur * u){
   
    int type = 0;
    int cpt = 0;

    for (int i = 0; i < taille; i++)
    {
         if (!strcmp(utilisateurs[i].login,login) && !strcmp(utilisateurs[i].password,pass) )
        {
            u->id = utilisateurs[i].id;
            // strcpy(u->mat, utilisateurs[i].mat);
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

Heure obtenirHeure() {
    Heure h;
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    h.h = today->tm_hour;
    h.mn = today->tm_min;
    h.s = today->tm_sec;
    
    return h;
}

Date obtenirDateAujourdhui2() {
    Date d;
    time_t t = time(NULL);
    struct tm *today = localtime(&t);

    d.j = today->tm_mday;
    d.m = today->tm_mon + 1;
    d.a = today->tm_year + 1900;

    return d;
}

Message excrireMessage(){
    Message message;
    char sujet[50];
    char texte[150];
    char cl;
    while ((cl = getchar()) != '\n' && cl != EOF);
    saisiMessage(sujet, sizeof(sujet) ,"Le sujet: ", "Ce champ est Obligatoire\n");
    saisiMessage(texte, sizeof(texte),"Le texte: ", "Ce champ est Obligatoire\n");

    strcpy(message.sujet, sujet);
    strcpy(message.texte, texte);
    
    return message;
}

void getReferentielName(int idRef, char chaine[]){
    if (idRef == 1)
    {
        strcpy(chaine, "Dev-Web");
    }
    if (idRef == 2)
    {
        strcpy(chaine, "Ref-Digital");
    }
    if (idRef == 3)
    {
        strcpy(chaine, "Dev-Data");
    }
    
}

int isValidMatricule(char matricule[]) {
     
    size_t len = strlen(matricule);
    if (len != 9) {
        return 0;  
    }
 
    if (!(isalpha(matricule[0]) && isalpha(matricule[1]) &&
          isalpha(matricule[2]) && isalpha(matricule[3]) &&
          isalpha(matricule[4]) && isdigit(matricule[5]) &&
          isdigit(matricule[6]) && isdigit(matricule[7]) &&
          isdigit(matricule[8]))) {
        return 0;  
    }

    return 1;  
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