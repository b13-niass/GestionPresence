#include "../prototype.h"

int lireFichierUtilisateurs(Utilisateur utilisateurs[], char *fichier) {
  FILE *fp;
  char ligne[100];
  char login[50], motDePasse[50];
  int type;
  int nbUtilisateurs = 0;

  fp = fopen(fichier, "r");
  if (fp == NULL) {
    printf("Erreur d'ouverture du fichier %s.\n", fichier);
    return -1;
  }

  while (fgets(ligne, sizeof(ligne), fp)) {
    sscanf(ligne, "%[^,],%[^,],%d", login, motDePasse,&type);
    strcpy(utilisateurs[nbUtilisateurs].login, login);
    strcpy(utilisateurs[nbUtilisateurs].password, motDePasse);
    utilisateurs[nbUtilisateurs].type = type;

    nbUtilisateurs++;
  }

  // Fermeture du fichier
  fclose(fp);

  return nbUtilisateurs;
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