#ifndef EXOTEST
#define EXOTEST

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>


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
    char email[50];
    Date date_naiss;
    int type;
} Utilisateur;

typedef struct{
    int id;
    Utilisateur u;
}Admin;

typedef struct{
    Utilisateur u;
    Promotion promo;
    Referenciel ref;
}Apprenant; 

#define TOTAL_STUDENT 2

#include "./protos/vue.h"
#include "./protos/admin.h"
#include "./protos/onFile.h"
#include "./protos/controle.h"
#include "./protos/etudiant.h"
#include "./protos/utilisateur.h"


#endif