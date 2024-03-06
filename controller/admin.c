#include "../prototype.h"


void afficherUtilisateur(Utilisateur * u)
{
    printf("l'étudiant est [%d, %s, %s, %s,%s, %s, %d-%d-%d, %d]",
    u->id, u->mat,u->login,u->password, u->prenom, u->nom, u->date_naiss.j,
     u->date_naiss.m,u->date_naiss.a,u->type);
}