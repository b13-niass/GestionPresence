#ifndef EXOTEST
#define EXOTEST
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

typedef struct
{
    int h, mn, s;
} Heure;

typedef struct
{
    int j, m, a;
} Date;

typedef struct{
    int id;
    char libelle[50];
    Date dateDebut;
    Date dateFin;
} Promotion;

typedef struct{
    int id;
    char libelle[50];
} Referenciel;

typedef struct{
    int id;
    char mat[50];
    char login[20];
    char password[20];
    char nom[20];
    char prenom[50];
    Date date_naiss;
    int type;
} Utilisateur;

typedef struct{
    int id;
    Utilisateur u;
}Admin;

typedef struct{
    int id;
    Utilisateur u;
    Promotion promo;
    Referenciel ref;
    int statut;
}Apprenant; 

typedef struct{
    int id;
    Apprenant apprenant;
    Date datePresence;
    Heure heure;
}Presence; 

#define TOTAL_STUDENT 2

#include "./protos/vue.h"
#include "./protos/admin.h"
#include "./protos/onFile.h"
#include "./protos/controle.h"
#include "./protos/etudiant.h"
#include "./protos/utilisateur.h"


#endif