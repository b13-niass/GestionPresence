#include "../prototype.h"

int lireFichierUtilisateurs(Utilisateur utilisateurs[], char *fichier) {
  FILE *fp;
  char ligne[100];
  char login[50], motDePasse[50];
  int id;
  char mat[50];
  char nom[20];
  char prenom[50];
  int jour,mois,annee, type;
  int nbUtilisateurs = 0;

  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne, "%d,%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d", 
    &id, login, motDePasse,nom,prenom,&jour, &mois, &annee , &type);
     utilisateurs[nbUtilisateurs].id = id;
    // strcpy(utilisateurs[nbUtilisateurs].mat, mat);
    strcpy(utilisateurs[nbUtilisateurs].login, login);
    strcpy(utilisateurs[nbUtilisateurs].password, motDePasse);
    strcpy(utilisateurs[nbUtilisateurs].nom, nom);
    strcpy(utilisateurs[nbUtilisateurs].prenom, prenom);
    utilisateurs[nbUtilisateurs].date_naiss.j = jour;
    utilisateurs[nbUtilisateurs].date_naiss.m = mois;
    utilisateurs[nbUtilisateurs].date_naiss.a = annee;
    utilisateurs[nbUtilisateurs].type = type;
    nbUtilisateurs++;
  }

  // Fermeture du fichier
  fclose(fp);

  return nbUtilisateurs;
}

int lireFichierAdmin(Admin admins[], char *fichier) {
  FILE *fp;
  char ligne[100];
  int idAdmin, idUser, nbrAdmin = 0;

  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne,"%d,%d", 
    &idAdmin, &idUser);
     admins[nbrAdmin].id = idAdmin;
     admins[nbrAdmin].u.id = idUser;
    nbrAdmin++;
  }

  // Fermeture du fichier
  fclose(fp);

  return nbrAdmin;
}

int lireFichierAprennant(Apprenant apprenants[], char *fichier) {
  FILE *fp;
  char ligne[100];
  char mat[50];
  int idApprenant, idUser, idPromo, idRef, status, nbrApprenant = 0;

  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne, "%d,%[^,],%d,%d,%d,%d", 
    &idApprenant,mat,&idUser, &idPromo, &idRef, &status);
    apprenants[nbrApprenant].id = idApprenant;
    strcpy(apprenants[nbrApprenant].mat, mat);
    apprenants[nbrApprenant].u.id = idUser;
    apprenants[nbrApprenant].promo.id = idPromo;
    apprenants[nbrApprenant].ref.id = idRef;
    apprenants[nbrApprenant].statut = status;
    nbrApprenant++;
  }

  // Fermeture du fichier
  fclose(fp);

  return nbrApprenant;
}

int lireFichierReferentiel(Referenciel referenciels[], char *fichier) {
  FILE *fp;
  char ligne[100];
  int id, nbrRef = 0;
  char libelle[50];

  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne, "%d,%s", 
    &id,libelle);
    referenciels[nbrRef].id = id;
    strcpy(referenciels[nbrRef].libelle, libelle);
    nbrRef++;
  }

  // Fermeture du fichier
  fclose(fp);

  return nbrRef;
}

int lireFichierPromo(Promotion promos[], char *fichier) {
  FILE *fp;
  char ligne[100];
  int idPromo, j1,m1,a1,j2,m2,a2,nbrPromo= 0;
  char libelle[50];
  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne, "%d,%s,%d,%d,%d,%d,%d,%d", 
    &idPromo,libelle, &j1, &m1,&a1, &j2, &m2,&a2);

    promos[nbrPromo].id = idPromo;
    strcpy(promos[nbrPromo].libelle, libelle);
    promos[nbrPromo].dateDebut.j = j1;
    promos[nbrPromo].dateDebut.m = m1;
    promos[nbrPromo].dateDebut.a = a1;
    promos[nbrPromo].dateFin.j = j2;
    promos[nbrPromo].dateFin.m = m2;
    promos[nbrPromo].dateFin.a = a2;
    nbrPromo++;
  }

  // Fermeture du fichier
  fclose(fp);

  return nbrPromo;
}

int lireFichierPresence(Presence presences[], char *fichier) {
  FILE *fp;
  char ligne[100];
  int idPresence, idApprenant, j, m, a, h, mn, s, nbrPresence = 0;

  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne, "%d,%d,%d,%d,%d,%d,%d,%d", 
    &idPresence,&idApprenant, &j, &m, &a, &h, &mn, &s);
    presences[nbrPresence].id = idPresence;
    presences[nbrPresence].apprenant.id = idApprenant;
    presences[nbrPresence].datePresence.j = j;
    presences[nbrPresence].datePresence.m = m;
    presences[nbrPresence].datePresence.a = a;
    presences[nbrPresence].heure.h = h;
    presences[nbrPresence].heure.mn = mn;
    presences[nbrPresence].heure.s = s;
    nbrPresence++;
  }

  // Fermeture du fichier
  fclose(fp);

  return nbrPresence;
}

int lireFichierPresenceDate(Date dates[], char *fichier) {
  FILE *fp;
  char ligne[100];
  int idPresence, idApprenant, j, m, a, h, mn, s, nbrDate = 0;

  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne, "%d,%d,%d,%d,%d,%d,%d,%d", 
    &idPresence,&idApprenant, &j, &m, &a, &h, &mn, &s);

    // int tailletabDate = sizeof(dates)/sizeof(dates[0]);
    int cpt = 0;
    for (int i = 0; i < nbrDate; i++)
    {
        if (dates[i].a == a && dates[i].m == m && dates[i].j == j)
        {
          cpt = 1;
          break;
        }
        
    }
    if (cpt == 0)
    {
      dates[nbrDate].a = a;
      dates[nbrDate].m = m;
      dates[nbrDate].j = j;
      nbrDate++;
    }
   
  }

  // Fermeture du fichier
  fclose(fp);

  return nbrDate;
}

int lireFichierMessage(Message message[], char *fichier){
  FILE *fp;
  char ligne[100];
  int idApprenant, nbrMessage = 0, statut;
  char sujet[50], texte[150];
  int j,m,a,h,mn,s;
  
  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne, "%d,%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d", 
    &idApprenant, sujet, texte, &j, &m, &a, &h, &mn, &s, &statut);

    
    message[nbrMessage].apprenant.id = idApprenant;
    message[nbrMessage].date_envoi.j = j;
    message[nbrMessage].date_envoi.m = m;
    message[nbrMessage].date_envoi.a = a;
    message[nbrMessage].heure_envoi.h = h;
    message[nbrMessage].heure_envoi.mn = mn;
    message[nbrMessage].heure_envoi.s = s;
    strcpy(message[nbrMessage].sujet, sujet);
    strcpy(message[nbrMessage].texte, texte);
    message[nbrMessage].statut = statut;
    nbrMessage++;
  }

  
  fclose(fp);

  return nbrMessage;


}
void ajouterPresence(Presence nouvellePresence, char *fichier) {
    FILE *fp;
    
    // Open the file in append mode
    fp = fopen(fichier, "a");
    if (fp == NULL) {
        printf("Erreur d'ouverture du fichier %s.\n", fichier);
        return;
    }

    // Write the new presence record to the file
    fprintf(fp, "%d,%d,%d,%d,%d,%d,%d,%d\n",
            nouvellePresence.id, nouvellePresence.apprenant.id,
            nouvellePresence.datePresence.j, nouvellePresence.datePresence.m,
            nouvellePresence.datePresence.a, nouvellePresence.heure.h,
            nouvellePresence.heure.mn, nouvellePresence.heure.s);

    // Close the file
    fclose(fp);
    
}

void genererFichierPresence(Presence presences[], int nbrPresence, 
  Apprenant apprenants[], int nbrApp, Utilisateur users[], int nbrUser, Referenciel refs[], int nbrRef,int idRef, Date date, Date dates[], int nbrDate, char *fichier) {
   char ligne[500],cl;
    FILE *fp;

    fp = fopen(fichier, "w");
    if (fp == NULL) {
        printf("Erreur d'ouverture du fichier %s.\n", fichier);
        return;
    }

for (int indate = 0; indate < nbrDate; indate++)
{
    char dateChaine[20];
    sprintf(dateChaine,"Date: %d - %d - %d \n", dates[indate].j,dates[indate].m, dates[indate].a);

    char ref[50];

    fprintf(fp, "%s", dateChaine);

    fprintf(fp, "+--------------+----------------+---------------+-----------------+-----+-----+------+--------+\n");
    fprintf(fp, "| Matricule    | Prenom         | Nom           | Referentiel     | Date Naissance   | Statut |\n");
    fprintf(fp, "+--------------+----------------+---------------+-----------------+-----+-----+------+--------+\n");

    for (int i = 0; i < nbrApp; i++)
    {
        for (int j = 0; j < nbrUser; j++)
        {
         
           if (apprenants[i].u.id == users[j].id)
           {  
              if (verifierPresenceParDate(apprenants[i].id,presences,nbrPresence, dates[indate]))
              {
                 if (apprenants[i].ref.id == 1)
                {
                  strcpy(ref, refs[0].libelle);
                }

                if (apprenants[i].ref.id == 2)
                {
                  strcpy(ref, refs[1].libelle);
                }

                 if (apprenants[i].ref.id == 3)
                {
                  strcpy(ref, refs[2].libelle);
                }

                  sprintf(ligne, "| %-12s | %-14s | %-13s | %-15s | %-3d-%-3d-%-3d | %-6s |\n", 
                      apprenants[i].mat,
                      users[j].prenom,
                      users[j].nom,
                      ref,
                      users[j].date_naiss.j,
                      users[j].date_naiss.m,
                      users[j].date_naiss.a,
                      "Présent");
                  fputs(ligne, fp);
                  fprintf(fp, "+--------------+----------------+---------------+-----------------+----------------+--------+\n");
                // }
              }
           }
           
        }
    }    

}
    fclose(fp);

    

    printf("\xE2\x9C\x85 Fichier %s généré avec succès.......\n", fichier);

   
}

void genererFichierPresence2(Presence presences[], int nbrPresence, 
  Apprenant apprenants[], int nbrApp, Utilisateur users[], int nbrUser, Referenciel refs[], int nbrRef,int idRef, Date date, char *fichier) {
    char ligne[500],ref[50];
    FILE *fp;
    
    fp = fopen(fichier, "w");
    if (fp == NULL) {
        printf("Erreur d'ouverture du fichier %s.\n", fichier);
        return;
    }

    fprintf(fp, "+--------------+----------------+---------------+-----------------+-----+-----+------+--------+\n");
    fprintf(fp, "| Matricule    | Prenom         | Nom           | Referentiel     | Date Naissance   | Statut |\n");
    fprintf(fp, "+--------------+----------------+---------------+-----------------+-----+-----+------+--------+\n");

    for (int i = 0; i < nbrApp; i++)
    {
        for (int j = 0; j < nbrUser; j++)
        {
         
           if (apprenants[i].u.id == users[j].id)
           {  
              if (verifierPresenceParDate(apprenants[i].id,presences,nbrPresence, date))
              {

                 if (apprenants[i].ref.id == 1)
                {
                  strcpy(ref, refs[0].libelle);
                }

                if (apprenants[i].ref.id == 2)
                {
                  strcpy(ref, refs[1].libelle);
                }

                 if (apprenants[i].ref.id == 3)
                {
                  strcpy(ref, refs[2].libelle);
                }


                //  if (apprenants[i].ref.id == refs[idRef-1].id)
                // {
                  sprintf(ligne, "| %-12s | %-14s | %-13s | %-15s | %-3d-%-3d-%-3d | %-6s |\n", 
                      apprenants[i].mat,
                      users[j].prenom,
                      users[j].nom,
                      ref,
                      users[j].date_naiss.j,
                      users[j].date_naiss.m,
                      users[j].date_naiss.a,
                      "Présent");
                  fputs(ligne, fp);
                  fprintf(fp, "+--------------+----------------+---------------+-----------------+-----+-----+------+--------+\n");
                // }
              }
           }
           
        }
    }
    
    fclose(fp);

    printf("\xE2\x9C\x85 Fichier %s généré avec succès.......\n", fichier);

}


extern void envoiMessageAtous(char sujet[50], char texte[150], char *fichier){

Apprenant apprenants[100];
  int nbrApprenant = lireFichierAprennant(apprenants, "./data/files/apprenant.csv");
  int j,m,a,h,mn,s;

  obtenirDateAujourdhui(&j,&m,&a,&h,&mn,&s);

  FILE *fp;
    
  fp = fopen(fichier, "a");
  if (fp == NULL) {
      printf("Erreur d'ouverture du fichier %s.\n", fichier);
      return;
  }

  for (int i = 0; i < nbrApprenant; i++)
  {
      fprintf(fp, "%d,%s,%s,%d,%d,%d,%d,%d,%d,%d\n",
          apprenants[i].id,
          sujet,
          texte,
          j,
          m,
          a,
          h,
          mn,
          s,
          0
          );
  }

  // Close the file
  fclose(fp);
}


extern void envoiMessageParClasse(char sujet[50], char texte[150], int idReferenciel, char *fichier){
  Apprenant apprenants[100];
  int nbrApprenant = lireFichierAprennant(apprenants, "./data/files/apprenant.csv");
  int j,m,a,h,mn,s;

   obtenirDateAujourdhui(&j,&m,&a,&h,&mn,&s);

  FILE *fp;
    
  fp = fopen(fichier, "a");
  if (fp == NULL) {
      printf("Erreur d'ouverture du fichier %s.\n", fichier);
      return;
  }

  for (int i = 0; i < nbrApprenant; i++)
  {
    if (apprenants[i].ref.id == idReferenciel)
    {
        fprintf(fp, "%d,%s,%s,%d,%d,%d,%d,%d,%d,%d\n",
          apprenants[i].id,
          sujet,
          texte,
          j,
          m,
          a,
          h,
          mn,
          s,
          0
          );
    }
    
  }

  // Close the file
  fclose(fp);
}
extern void envoiMessageParSelection(Apprenant apps[], int nbrApp, char sujet[50], char texte[150],  char *fichier){
  Apprenant apprenants[100];
  int nbrApprenant = lireFichierAprennant(apprenants, "./data/files/apprenant.csv");
  int j,m,a,h,mn,s;

  obtenirDateAujourdhui(&j,&m,&a,&h,&mn,&s);

  FILE *fp;
    
  fp = fopen(fichier, "a");
  if (fp == NULL) {
      printf("Erreur d'ouverture du fichier %s.\n", fichier);
      return;
  }

  for (int i = 0; i < nbrApp; i++)
  {
    for (int j = 0; j < nbrApprenant; j++)
    {
      printf("%d", strcmp(apps[i].mat, apprenants[j].mat));
       if (!strcmp(apps[i].mat, apprenants[j].mat))
       {
           fprintf(fp, "%d,%s,%s,%d,%d,%d,%d,%d,%d,%d\n",
          apprenants[j].id,
          sujet,
          texte,
          j,
          m,
          a,
          h,
          mn,
          s,
          0
          );
       }
       
    }
    
    }

  // Close the file
  fclose(fp);

}

// void fichier(){
//     FILE * file;

//     file = fopen("./data/files/file.csv", "ab+");

//     if (file == NULL)
//     {
//         printf("Error opening file\n");
//     }

//     Student students[TOTAL_STUDENT];

//     students[0].type = 'U';
//     strcpy(students[0].name, "Nageeb");
//     students[0].age = 20;
//     students[0].average = 90;

//     students[1].type = 'U';
//     strcpy(students[1].name, "Mary");
//     students[1].age = 19;
//     students[1].average = 95;

//     students[2].type = 'G';
//     strcpy(students[2].name, "Kulvin");
//     students[2].age = 21;
//     students[2].average = 85;

//     for (int i = 0; i < TOTAL_STUDENT; i++)
//     {
//         fprintf(file, "%c,%s,%d,%.2f\n", 
//         students[i].type,students[i].name, 
//         students[i].age, students[i].average);

//         if (ferror(file)) // 1 si erreur sur derniere fonction sur file
//         {
//             printf("error writing to file\n");
//         }
        
//     }

//     fclose(file);
    
// }

// void lireFichier(){
//     FILE * file;

//     file = fopen("./date/files/file.csv", "r");

//     if (file == NULL)
//     {
//         printf("Error opening file\n");
//     }
    
//     Student students[100];
//     int read = 0;
//     int records = 0;
    
//     do
//     {
//         read = fscanf(file, "%c,%49[^,],%d, %lf\n", 
//         &students[records].type,&students[records].name,
//         &students[records].age, &students[records].average);

        
//         if (read == 4 )
//         {
//             records++;
//         }
        

//     } while (!feof(file));
    
    

// }