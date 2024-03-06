#include "../prototype.h"

int verifierPresence(int idApprenant, Presence presences[], int nbrPresence){
    int j,m,a,h,mn,s;
    obtenirDateAujourdhui(&j,&m,&a,&h,&mn,&s);
    for (int i = 0; i < nbrPresence; i++)
    {
        if (presences[i].apprenant.id == idApprenant && j == presences[i].datePresence.j && m == presences[i].datePresence.m
        && presences[i].datePresence.a == a )
        {
            return 1;
        }
        
    }
    return 0;
}

int menuAdmin(){
    int choixMenuAdmin;

    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif
    // getchar();
    do
    {
        printf("1 - GESTION DES ÉTUDIANTS\n");
        printf("2 - GÉNÉRATION DE FICHIERS\n");
        printf("3 - MARQUER LES PRÉSENCES \n");
        printf("4 - ENVOYER UN MESSAGE \n");
        printf("5 - Quitter \n");

        printf("Faite un choix ici: \n");
        scanf("%d", &choixMenuAdmin);

        if (choixMenuAdmin < 1 || choixMenuAdmin > 4)
        {
            printf("Faite un choix entre 1, 2, 3 et 4\n");
        }
        
    } while (choixMenuAdmin <1 || choixMenuAdmin > 5);

    return choixMenuAdmin;
}

int menuApprenant(){
    int choixMenuApprenant;
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif

    do
    {
        printf("1 - MARQUER MA PRÉSENCE\n");
        printf("2 - NOMBRE DE MINUTES D’ABSENCE\n");
        printf("3 - MES MESSAGES (0) \n");
        printf("4 - Quitter \n");

        printf("Faite un choix: \n");
        scanf("%d", &choixMenuApprenant);

        if (choixMenuApprenant < 1 || choixMenuApprenant > 4)
        {
            printf("Faite un choix entre 1, 2, 3 et 4\n");
        }
        
    } while (choixMenuApprenant <1 || choixMenuApprenant > 4);

    return choixMenuApprenant;
}

int menuMarquerPresence(){
    int choixMarquerPresence;
    Referenciel referenciels[100];
    int nbrRef = lireFichierReferentiel(referenciels, "./data/files/referenciel.csv");
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif

    do
    {
        for (int i = 0; i < nbrRef; i++)
        {
            printf("%d - %s\n", i+1,referenciels[i].libelle);
        }
        
        
        // printf("2 - Ref Dig\n");
        // printf("3 - Dev Data\n");
        printf("4 - Quitter \n");

        printf("Faite un choix: \n");
        scanf("%d", &choixMarquerPresence);

        if (choixMarquerPresence < 1 || choixMarquerPresence > 4)
        {
            printf("Faite un choix entre 1, 2, 3 et 4\n");
        }
        
    } while (choixMarquerPresence <1 || choixMarquerPresence > 4);

    return choixMarquerPresence;
}


void AfficherMenu(char msg[]) {
    printf("\n******************************\n");
    printf("    %s            \n", msg);
    printf("******************************\n");
}

void traitementAdmin(){
    Utilisateur utilisateurs[100];
    Apprenant apprenants[100];
    Presence presences[100];
    Referenciel referenciels[100], ref;
    int choixMenuAdmin, choixMarquerPresence, choixApprenant;
    int nbrUser = lireFichierUtilisateurs(utilisateurs, "./data/files/utilisateurs.csv");
    int nbrApprenant = lireFichierAprennant(apprenants, "./data/files/apprenant.csv");
    int nbrRef = lireFichierReferentiel(referenciels, "./data/files/referenciel.csv");
    int nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
    int j,m,a,h,mn,s;
    obtenirDateAujourdhui(&j,&m,&a,&h,&mn,&s);

    do
    {
        choixMenuAdmin = menuAdmin();
        if (choixMenuAdmin == 1)
        {
          
          
          
        }

        if (choixMenuAdmin == 2)
        {
            
        }
        
        if(choixMenuAdmin == 3)
        {
              do
            {
                 choixMarquerPresence = menuMarquerPresence();
                 int cpt = 1;
                 printf("liste des Apprenants pour ce Référentiel\n");
                 if (choixMarquerPresence == 1)
                 { 
                    
                    do
                    {    
                        for (int i = 0; i < nbrApprenant; i++)
                        {
                            for (int j = 0; j < nbrUser; j++)
                            {
                               
                                if (utilisateurs[j].id == apprenants[i].u.id && apprenants[i].ref.id == 1)
                                {
                                    printf("%d) %s %s ", apprenants[i].id, utilisateurs[j].prenom, utilisateurs[j].nom );
                                   
                                    if (verifierPresence(apprenants[i].id, presences, nbrPresence))
                                    {  
                                        printf(GREEN"Present\n"RESET);
                                    }else{
                                        printf(RED"absent\n"RESET);
                                    }
                                    // cpt++;
                                    break;

                                }
                                
                            }
                            
                        }
                        printf("0) Quitter \n");
                        printf("Choisir un Apprenant pour marquer la présence : \n");
                        scanf("%d", &choixApprenant);
                        
                        if (choixApprenant <= nbrApprenant && choixApprenant >= 1 )
                        {
                            if (!verifierPresence(choixApprenant, presences, nbrPresence))
                            {
                                Presence presence;
                                presence.apprenant.id = choixApprenant;
                                presence.datePresence.a = a;
                                presence.datePresence.m = m;
                                presence.datePresence.j = j;
                                presence.heure.h = h;
                                presence.heure.mn = mn;
                                presence.heure.s = s;
                                presence.id = 2;
                                ajouterPresence(presence, "./data/files/presence.csv");
                                nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
                                // printf("%d", nbrPresence);
                            }else{
                                printf("Cette apprenant est déjà présent\n");
                            }
                            
                        }
                        

                    } while (choixApprenant <= nbrApprenant && choixApprenant > 0);
                   
                 }

                 if (choixMarquerPresence == 2)
                 {
                    do
                    {    
                        for (int i = 0; i < nbrApprenant; i++)
                        {
                            for (int j = 0; j < nbrUser; j++)
                            {
                               
                                if (utilisateurs[j].id == apprenants[i].u.id && apprenants[i].ref.id == 2)
                                {
                                    printf("%d) %s %s ", apprenants[i].id, utilisateurs[j].prenom, utilisateurs[j].nom );
                                   
                                    if (verifierPresence(apprenants[i].id, presences, nbrPresence))
                                    {  
                                        printf(GREEN"Present\n"RESET);
                                    }else{
                                        printf(RED"absent\n"RESET);
                                    }
                                    // cpt++;
                                    break;

                                }
                                
                            }
                            
                        }
                        printf("0) Quitter \n");
                        printf("Choisir un Apprenant pour marquer la présence : \n");
                        scanf("%d", &choixApprenant);
                        
                        if (choixApprenant <= nbrApprenant && choixApprenant >= 1 )
                        {
                            if (!verifierPresence(choixApprenant, presences, nbrPresence))
                            {
                                Presence presence;
                                presence.apprenant.id = choixApprenant;
                                presence.datePresence.a = a;
                                presence.datePresence.m = m;
                                presence.datePresence.j = j;
                                presence.heure.h = h;
                                presence.heure.mn = mn;
                                presence.heure.s = s;
                                presence.id = 3;
                                ajouterPresence(presence, "./data/files/presence.csv");
                                nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
                                // printf("%d", nbrPresence);
                            }else{
                                printf("Cette apprenant est déjà présent\n");
                            }
                            
                        }
                        

                    } while (choixApprenant <= nbrApprenant && choixApprenant > 0);
                   
                 }

                 if (choixMarquerPresence == 3)
                 {
                    do
                    {    
                        for (int i = 0; i < nbrApprenant; i++)
                        {
                            for (int j = 0; j < nbrUser; j++)
                            {
                               
                                if (utilisateurs[j].id == apprenants[i].u.id && apprenants[i].ref.id == 3)
                                {
                                    printf("%d) %s %s ", apprenants[i].id, utilisateurs[j].prenom, utilisateurs[j].nom );
                                   
                                    if (verifierPresence(apprenants[i].id, presences, nbrPresence))
                                    {  
                                        printf(GREEN"Present\n"RESET);
                                    }else{
                                        printf(RED"absent\n"RESET);
                                    }
                                    // cpt++;
                                    break;

                                }
                                
                            }
                            
                        }
                        printf("0) Quitter \n");
                        printf("Choisir un Apprenant pour marquer la présence : \n");
                        scanf("%d", &choixApprenant);
                        
                        if (choixApprenant <= nbrApprenant && choixApprenant >= 1 )
                        {
                            if (!verifierPresence(choixApprenant, presences, nbrPresence))
                            {
                                Presence presence;
                                presence.apprenant.id = choixApprenant;
                                presence.datePresence.a = a;
                                presence.datePresence.m = m;
                                presence.datePresence.j = j;
                                presence.heure.h = h;
                                presence.heure.mn = mn;
                                presence.heure.s = s;
                                presence.id = 4;
                                ajouterPresence(presence, "./data/files/presence.csv");
                                nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
                                // printf("%d", nbrPresence);
                            }else{
                                printf("Cette apprenant est déjà présent\n");
                            }
                            
                        }
                        

                    } while (choixApprenant <= nbrApprenant && choixApprenant > 0);
                   
                 }
                 

            } while (choixMarquerPresence != 4);
            
        }
        
        if(choixMenuAdmin == 4)
        {
            
        }
    } while (choixMenuAdmin != 5);
    
}

void traitementApprenant(){

}

int vueLogin(){
    char log[20];
    char pass[20];
    int nbUtilisateursFichier;
    int resultConnexion;
    Utilisateur utilisateurs[100];
    Utilisateur u;

    do{
        AfficherMenu("Menu De connexion");
        saisiChaine(log, "Login:","Veuillez saisir un login\n");
        saisiChainePassword(pass, "Mot de passe :","Veuillez saisir un Mot de passe\n");

        nbUtilisateursFichier = lireFichierUtilisateurs(utilisateurs,"./data/files/utilisateurs.csv");
        if (nbUtilisateursFichier == -1) {
            return 1;
        }
        // printf("%d", nbUtilisateursFichier);

        resultConnexion = login(log, pass, utilisateurs, nbUtilisateursFichier, &u);
       
        // afficherUtilisateur(&u);
        // printf("%s", u.mat);
       if (u.type == 1)
        {   
            traitementAdmin();
        }
        if (u.type == 2)
        {
            traitementApprenant();
        }
    }while(resultConnexion == 0);
}

