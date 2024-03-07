#include "../prototype.h"


void afficherUtilisateur(Utilisateur * u)
{
    printf("l'étudiant est [%d, %s, %s,%s, %s, %d-%d-%d, %d]",
    u->id,u->login,u->password, u->prenom, u->nom, u->date_naiss.j,
     u->date_naiss.m,u->date_naiss.a,u->type);
}

int testMatricule(char matricule[], Apprenant apprenants[], int nbrApp){
    // printf("%s", apprenants[0].mat);
    // printf("%s",matricule);
    for (int i = 0; i < nbrApp; i++)
    {
        // printf("%d", strcmp(apprenants[i].mat, matricule));
        if (!strcmp(apprenants[i].mat, matricule))
        {   
            return apprenants[i].id;
        } 
    }
    return 0;
}

// int testPresence(int idApprenant, Presence presences[], int nbrPres){
//     for (int i = 0; i < nbrPres; i++)
//     {
//         if (idApprenant == presences[i].apprenant.id)
//         {
//             /* code */
//         }
        
//     }
    
// }

// int marquerPresence(Utilisateur utilisateurs[], int nbrUser, Apprenant apprenants[],
//  int nbrApp, Presence presences[], int nbrPrese){



// }