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

int verifierPresenceParDate(int idApprenant, Presence presences[], int nbrPresence, Date date){

    for (int i = 0; i < nbrPresence; i++)
    {
        if (presences[i].apprenant.id == idApprenant && date.j == presences[i].datePresence.j && date.m == presences[i].datePresence.m
        && presences[i].datePresence.a == date.a)
        {
            return 1;
        }
        
    }
    return 0;
}


Heure heurePresence(int idApprenant, Presence presences[], int nbrPresence){
    Heure heu;
    int j,m,a,h,mn,s;
    obtenirDateAujourdhui(&j,&m,&a,&h,&mn,&s);

        for (int i = 0; i < nbrPresence; i++)
        {
            if (presences[i].apprenant.id == idApprenant && j == presences[i].datePresence.j && m == presences[i].datePresence.m
        && presences[i].datePresence.a == a)
            {
                heu.h = presences[i].heure.h;
                heu.mn = presences[i].heure.mn;
                heu.s = presences[i].heure.s;
                break;
            }
            
        }
        
    return heu;
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
        AfficherMenu("Menu Admin");
        printf("1 - GESTION DES ÉTUDIANTS\n");
        printf("2 - GÉNÉRATION DE FICHIERS\n");
        printf("3 - MARQUER LES PRÉSENCES \n");
        printf("4 - ENVOYER UN MESSAGE \n");
        printf("5 - Deconnection \n");

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
        AfficherMenu("Menu Apprenant");
        printf("1 - MARQUER MA PRÉSENCE\n");
        printf("2 - NOMBRE DE MINUTES D’ABSENCE\n");
        printf("3 - MES MESSAGES (0) \n");
        printf("4 - Déconnexion \n");

        printf("Faite un choix: \n");
        scanf("%d", &choixMenuApprenant);

        if (choixMenuApprenant < 1 || choixMenuApprenant > 4)
        {
            printf("Faite un choix entre 1, 2, 3 et 4\n");
        }
        
    } while (choixMenuApprenant <1 || choixMenuApprenant > 4);

    return choixMenuApprenant;
}

int menuGenererFichier(){
    int choixMenuGF;
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif

    do
    {
        AfficherMenu("Generer Fichier Presence");
        printf("1 - Toutes les dates\n");
        printf("2 - À une date\n");
        printf("3 - Quitter \n");

        printf("Faite un choix: \n");
        scanf("%d", &choixMenuGF);

        if (choixMenuGF < 1 || choixMenuGF > 3)
        {
            printf("Faite un choix entre 1, 2 et 3\n");
        }
        
    } while (choixMenuGF <1 || choixMenuGF > 3);

    return choixMenuGF;
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

int menuReferenciel(){
    int choixReferenciel;
    Referenciel referenciels[100];
    int nbrRef = lireFichierReferentiel(referenciels, "./data/files/referenciel.csv");
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif

    do
    {
        AfficherMenu("Référentiel");
        for (int i = 0; i < nbrRef; i++)
        {
            printf("%d - %s\n", i+1,referenciels[i].libelle);
        }
        
        
        // printf("2 - Ref Dig\n");
        // printf("3 - Dev Data\n");
        printf("4 - Quitter \n");

        printf("Faite un choix: \n");
        scanf("%d", &choixReferenciel);

        if (choixReferenciel < 1 || choixReferenciel > 4)
        {
            printf("Faite un choix entre 1, 2, 3 et 4\n");
        }
        
    } while (choixReferenciel <1 || choixReferenciel > 4);

    return choixReferenciel;
}


void AfficherMenu(char msg[]) {
    printf("\n******************************\n");
    printf("    %s            \n", msg);
    printf("******************************\n");
}


void traitementAdmin(int * result, Utilisateur * user){
    
    Utilisateur utilisateurs[100];
    Apprenant apprenants[100];
    Presence presences[100];
    Referenciel referenciels[100], ref;
    Date dates[100];
    int choixMenuAdmin, choixMarquerPresence, choixApprenant, choixMenuGF, idApprenant, choixReferenciel;
    int nbrUser = lireFichierUtilisateurs(utilisateurs, "./data/files/utilisateurs.csv");
    int nbrApprenant = lireFichierAprennant(apprenants, "./data/files/apprenant.csv");
    int nbrRef = lireFichierReferentiel(referenciels, "./data/files/referenciel.csv");
    int nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
    int nbrDate = lireFichierPresenceDate(dates, "./data/files/presence.csv");
    char matricule[50], passwordVerify[6], cl;
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
            do
            {
                // choixReferenciel = menuReferenciel();
                // if (choixReferenciel == 1)
                // {
                //      do
                    {

                        choixMenuGF = menuGenererFichier();

                        if (choixMenuGF == 1)
                        {
                                Date d = obtenirDateAujourdhui2();
                                Heure h = obtenirHeure();
                                char dateHeureStr[50];
                                char nomFichier [150];

                                sprintf(dateHeureStr, "%04d%02d%02d_%02d%02d%02d",
                                d.a, d.m, d.j, h.h, h.mn, h.s);

                                // sprintf(nomFichier, "./data/files/fichier_presence_%s.csv", dateHeureStr);
                                sprintf(nomFichier, "./data/files/fichier_presence_all_%d.csv", choixReferenciel);
                                
                                // int c;
                                // while ((c = getchar()) != '\n' && c != EOF);
                                genererFichierPresence(presences, nbrPresence, 
                                    apprenants, nbrApprenant , utilisateurs, nbrUser,
                                    referenciels, nbrRef, choixReferenciel, d, dates, nbrDate, nomFichier);
                                    // pause();
                                    sleep(2);
                                    continue;
                                // getchar();
                                // pause();
                        }

                        if (choixMenuGF == 2)
                        {
                            Date d;
                                while ((cl = getchar()) != '\n' && cl != EOF);
                            saisirDate(&d, "Saisir la date", "La saisie n'est pas valide");

                            if (d.j!=0 && d.m!=0 && d.a!=0)
                            {
                                    // Date d = obtenirDateAujourdhui2();
                                    Heure h = obtenirHeure();
                                    char dateHeureStr[50];
                                    char nomFichier [150];

                                    sprintf(dateHeureStr, "%04d%02d%02d_%02d%02d%02d",
                                    d.a, d.m, d.j, h.h, h.mn, h.s);

                                    sprintf(nomFichier, "./data/files/fichier_presence_date.csv");
                                 
                                    
                                    genererFichierPresence2(presences, nbrPresence, 
                                        apprenants, nbrApprenant , utilisateurs, nbrUser,
                                        referenciels, nbrRef, choixReferenciel, d, nomFichier);
                                    
                                    sleep(2);
                                    continue;
                                        
                            }else{
                                printf("Cette date n'est pas valide\n");
                                // fflush(stdout);
                                while ((cl = getchar()) != '\n' && cl != EOF);
                                // getchar();
                            }
                                
                            // fflush(stdout);
                            // while ((cl = getchar()) != '\n' && cl != EOF);
                            // getchar();
                            // pause();

                        }

                    } while (choixMenuGF != 3);
              
            } while (choixReferenciel != 4);
            
            
          
           
        }
        
        if(choixMenuAdmin == 3)
        {
              do
            {
                    // getchar();
                    while ((cl = getchar()) != '\n' && cl != EOF);
                saisiChaine(matricule, "Donner le matricule (Q: pour quitter):", "");

                if (matricule[0] == 'q' || matricule[0] == 'Q')
                {
                    saisiChainePassword(passwordVerify, "Mot de Pass.... :", "\xE2\x9D\x8CMP Obligatoire\n");
                        // printf("%s", passwordVerify);
                        // printf("%d", strcmp("12345", passwordVerify));
                        if (!strcmp("12345", passwordVerify))
                        {
                            break;
                        }else{
                            printf("\n \xE2\x9D\x8CMot de passe invalide!!\n");
                        }
                        // while ((cl = getchar()) != '\n' && cl != EOF);
                }
                

                if (matricule[0] != 'q' && matricule[0] != 'Q')
                {
                  
                    idApprenant = testMatricule(matricule, apprenants, nbrApprenant);
                    printf("%d", idApprenant);
                    if (idApprenant)
                    {
                        if (!verifierPresence(idApprenant, presences, nbrPresence))
                        {
                            Presence presence;
                            presence.apprenant.id = idApprenant;
                            presence.datePresence.a = a;
                            presence.datePresence.m = m;
                            presence.datePresence.j = j;
                            presence.heure.h = h;
                            presence.heure.mn = mn;
                            presence.heure.s = s;
                            presence.id = presences[nbrPresence-1].id + 1;
                            ajouterPresence(presence, "./data/files/presence.csv");
                            nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
                            // printf("%d", nbrPresence);
                            printf("\xE2\x9C\x85 Vous êtes maintenant présent\n");
                        }else{
                            Heure heure_p = heurePresence(idApprenant,presences,nbrPresence);
                            printf("\xE2\x9C\x85  Cette apprenant est déjà présent\n %d:%d:%d",heure_p.h,heure_p.mn,heure_p.s);
                        }
                        
                    }else{
                        printf("\xE2\x9D\x8C Ce matricule n'est pas valide\n");
                    }

                }
                
                } while (1);
            
        }
        
        if(choixMenuAdmin == 4)
        {
            
        }
    } while (choixMenuAdmin != 5);
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif
    if (choixMenuAdmin == 5)
    {
        *result = 0;
    }
    
}

void traitementApprenant(int * result, Utilisateur * user){
    Utilisateur utilisateurs[100];
    Apprenant apprenants[100];
    Presence presences[100];
    Referenciel referenciels[100], ref;
    int choixMenuApprenant, choixMarquerPresence, choixApprenant;
    int nbrUser = lireFichierUtilisateurs(utilisateurs, "./data/files/utilisateurs.csv");
    int nbrApprenant = lireFichierAprennant(apprenants, "./data/files/apprenant.csv");
    int nbrRef = lireFichierReferentiel(referenciels, "./data/files/referenciel.csv");
    int nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
    int j,m,a,h,mn,s;
    Apprenant app;
    char cl;
    obtenirDateAujourdhui(&j,&m,&a,&h,&mn,&s);

    for (int i = 0; i < nbrApprenant; i++)
    {
        if (user->id == apprenants[i].u.id)
        {
            app.id = apprenants[i].id;
            app.promo.id = apprenants[i].promo.id;
            app.ref.id = apprenants[i].ref.id;
            app.statut = apprenants[i].statut;
            app.u.id = apprenants[i].u.id;
            break;
        }
        
    }
    
    printf("%d", app.id);

    do
    {
        choixMenuApprenant = menuApprenant();
        if (choixMenuApprenant == 1)
        {
            
            if (verifierPresence(app.id, presences, nbrPresence))
            {
                printf("\xE2\x9C\x85 Vous-êtes Déjà présent !!!! ");
                // while ((cl = getchar()) != '\n' && cl != EOF);
                getchar();
                // pause();
            }else{
                Presence presence;
                presence.apprenant.id = app.id;
                presence.datePresence.a = a;
                presence.datePresence.m = m;
                presence.datePresence.j = j;
                presence.heure.h = h;
                presence.heure.mn = mn;
                presence.heure.s = s;
                presence.id = presences[nbrPresence-1].id + 1;
                ajouterPresence(presence, "./data/files/presence.csv");
                nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
                // printf("%d", nbrPresence);
                printf("\xE2\x9C\x85 Vous êtes maintenant présent\n");
            }
            
        }

        if (choixMenuApprenant == 2)
        {
            
        }
    } while (choixMenuApprenant != 5);
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif
    if (choixMenuApprenant == 5)
    {
        *result = 0;
    }


}

int vueLogin(){
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif

    char log[20];
    char pass[20];
    int nbUtilisateursFichier;
    int resultConnexion = 1, resultConnexionApp = 1;
    Utilisateur utilisateurs[100];
    Utilisateur u;
    char cl;

    do{
       
        AfficherMenu("Menu De connexion");
        saisiChaine(log, "Login:","Veuillez saisir un login\n");
        saisiChainePassword(pass, "Mot de passe :","Veuillez saisir un Mot de passe\n");
        // printf("%s", log);
        // printf("%s", pass);
        nbUtilisateursFichier = lireFichierUtilisateurs(utilisateurs,"./data/files/utilisateurs.csv");
        if (nbUtilisateursFichier == -1) {
            return 1;
        }
        // printf("%d", nbUtilisateursFichier);

        resultConnexion = login(log, pass, utilisateurs, nbUtilisateursFichier, &u);
        resultConnexionApp = login(log, pass, utilisateurs, nbUtilisateursFichier, &u);
       
        // afficherUtilisateur(&u);
        // printf("%d", u.type);
        // printf("%d", nbUtilisateursFichier);

       if (u.type == 1)
        {   
            traitementAdmin(&resultConnexion, &u);
             while ((cl = getchar()) != '\n' && cl != EOF);
        }
        if (u.type == 2)
        {
            traitementApprenant(&resultConnexionApp, &u);
        }
        log[0] = '\0';
        pass[0] = '\0';      
    }while(resultConnexion == 0 || resultConnexionApp == 0);
}

