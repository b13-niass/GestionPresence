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

int menuApprenant(int nbrMessagesNonLu){
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
        printf("3 - MES MESSAGES (%d) \n", nbrMessagesNonLu);
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
// TODO: FIXME: 
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

int menuListeApprenant(){
    int choixListeApprenant;
    Utilisateur utilisateurs[100];
    Apprenant apprenants[100];
    int nbrUser = lireFichierUtilisateurs(utilisateurs, "./data/files/utilisateurs.csv");
    int nbrApprenant = lireFichierAprennant(apprenants, "./data/files/apprenant.csv");
    char ref[20];
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif

    AfficherMenu("Liste des Apprenants");
    for (int i = 0; i < nbrApprenant; i++)
    {
        
        for (int j = 0; j < nbrUser; j++)
        {
            if (apprenants[i].u.id == utilisateurs[j].id)
            {   getReferentielName(apprenants[i].ref.id,ref);
                printf("%d - %s %s %s %s\n", i+1, 
                apprenants[i].mat, utilisateurs[j].prenom,
                utilisateurs[j].nom, ref);
            }
            
        }

    }
}


int menuSendMessage(){
    int choixSendMessage;

    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif
    // getchar();
    do
    {
        AfficherMenu("Envoyer Message");
        printf("1 - À tous\n");
        printf("2 - À une classe\n");
        printf("3 - Par sélectionr\n");
        printf("4 - Quitter \n");

        printf("Faite un choix ici: \n");
        scanf("%d", &choixSendMessage);

        if (choixSendMessage < 1 || choixSendMessage > 4)
        {
            printf("Faite un choix entre 1, 2, 3 et 4\n");
        }
        
    } while (choixSendMessage <1 || choixSendMessage > 4);

    return choixSendMessage;
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
    int choixMenuAdmin, choixMarquerPresence, choixApprenant, choixMenuGF, idApprenant, choixReferenciel, ChoiMenuSendMessage;
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
                    saisiChainePassword(passwordVerify, "Mot de Pass.... :", "\n \xE2\x9D\x8CMP Obligatoire\n");
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
            do
            {
                ChoiMenuSendMessage = menuSendMessage();
                if (ChoiMenuSendMessage == 1)
                {   
                    Message message = excrireMessage();
                    
                    envoiMessageAtous(message.sujet, message.texte, "./data/files/messages.csv");
                    printf("\xE2\x9C\x85 Message envoyé avec succès.......\n");
                    while ((cl = getchar()) != '\n' && cl != EOF);

                }

                if (ChoiMenuSendMessage == 2)
                {
                    do
                    {
                       choixReferenciel = menuReferenciel();
                        if (choixReferenciel == 1 || choixReferenciel == 2 || choixReferenciel == 3)
                        {
                            Message message = excrireMessage();
                    
                            envoiMessageParClasse(message.sujet, message.texte, choixReferenciel, "./data/files/messages.csv");
                            printf("\xE2\x9C\x85 Message envoyé avec succès.......\n");
                            while ((cl = getchar()) != '\n' && cl != EOF);
                        }
                        

                    } while (choixReferenciel != 4);
                    
                    
                }

                 if (ChoiMenuSendMessage == 3)
                { while ((cl = getchar()) != '\n' && cl != EOF);
                    char input[100];
                    Apprenant apps[100];
                    int k=0;
                    int invalidMat;
                    
                    do
                    {
                        invalidMat = 0;
                        menuListeApprenant();
                        printf("Donner les matricules des apprenant à envoyer des messages\n");
                        printf("Au format [MATXX0000,MATXX0000] / (Q ou q pour quitter):\n");
                        fgets(input, sizeof(input), stdin);

                        if (input[0] == 'q' || input[0] == 'Q')
                        {
                            break;
                        }
                         
                        char *token = strtok(input, ",");
                        while (token != NULL) {
                             
                            char trimmedMatricule[9];
                            sscanf(token, " %9s", trimmedMatricule);

                             
                            if (isValidMatricule(trimmedMatricule)) {
                                 strcpy(apps[k++].mat, trimmedMatricule);
                            } else {
                                printf("Ce matricule n'est pas valide: %s\n", trimmedMatricule);
                                while ((cl = getchar()) != '\n' && cl != EOF);
                                invalidMat = 1;
                            }

                            
                            
                            token = strtok(NULL, ",");
                        }

                        if (invalidMat == 0)
                        {
                            Message message = excrireMessage();
                            envoiMessageParSelection(apps,k,message.sujet,message.texte, "./data/files/messages.csv");

                            printf("\xE2\x9C\x85 Message envoyé avec succès.......\n");
                            while ((cl = getchar()) != '\n' && cl != EOF);
                        }
                        
                       

                    } while (input[0] != 'q' || input[0] != 'Q');
                    
                    
                }
                
                
            } while (ChoiMenuSendMessage != 4);
            
            
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
    Message messages[100];
    int choixMenuApprenant, choixMarquerPresence, choixApprenant, choixMessage;
    int nbrUser = lireFichierUtilisateurs(utilisateurs, "./data/files/utilisateurs.csv");
    int nbrApprenant = lireFichierAprennant(apprenants, "./data/files/apprenant.csv");
    int nbrRef = lireFichierReferentiel(referenciels, "./data/files/referenciel.csv");
    int nbrPresence = lireFichierPresence(presences, "./data/files/presence.csv");
    int nbrMessage = lireFichierMessage(messages, "./data/files/messages.csv");
    int j,m,a,h,mn,s, nbrMessageNonLu = 0;
    Apprenant app;
    char cl;
    int positionM[100], valPosition=0, indiceP = 0;
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
    
    for (int j = 0; j < nbrMessage; j++)
    {
        if (app.id == messages[j].apprenant.id && messages[j].statut == 0)
        {
            nbrMessageNonLu++;
        }
        
    }
    
    // printf("%d", app.id);

    do
    {
        choixMenuApprenant = menuApprenant(nbrMessageNonLu);
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

        if (choixMenuApprenant == 3)
        {
            int numeroMessages = 0;
            char choixQuitterMess;
            do
            {
            
                for (int i = nbrMessage - 1; i >= 0; i--)
                {
                    // printf("%s", messages[i].su jet);
                    valPosition++;
                    if(app.id == messages[i].apprenant.id){
                        // messages[i].statut = 1;
                        positionM[indiceP++] = valPosition;
                        printf("%d -) %s Le %d/%d/%d à %d:%d:%d  %s\n",++numeroMessages,messages[i].sujet, messages[i].date_envoi.j, 
                            messages[i].date_envoi.m,messages[i].date_envoi.a, messages[i].heure_envoi.h,
                            messages[i].heure_envoi.mn, messages[i].heure_envoi.s,
                            messages[i].statut == 1 ? GREEN"Lu"RESET : RED"Non Lu"RESET
                        );
                    }
                }
               
               valPosition = 0; indiceP=0;
                if (numeroMessages == 0)
                {
                    printf("Vous n'avez pas de messages\n");
                }else{
                    int lire;
                    printf("choisir le messages à lire:");
                    scanf("%d",&lire);

                    if (lire <=0 || lire > numeroMessages)
                    {
                        printf("Choix invalide\n");
                        while ((cl = getchar()) != '\n' && cl != EOF);
                    }else{
                    
                        marquerMessageLu(app.id, nbrMessage - positionM[lire-1]+1, "./data/files/messages.csv");
                        lire--;
                        for (int i = nbrMessage - 1; i >= 0; i--)
                        {   
                            if(app.id == messages[i].apprenant.id){
                                
                                if (lire == 0)
                                {
                                    // if (messages[i].statut == 0)
                                    // {
                                        
                                    // }
                                    
                                    printf("Sujet: %s \n", messages[i].sujet);
                                    printf("Texte: %s \n", messages[i].texte);
                                    break;
                                }
                                lire--;
                            }
                        }
                        numeroMessages = 0, lire = 0;
                        while ((cl = getchar()) != '\n' && cl != EOF);
                        getchar();

                    }
                  nbrMessage = lireFichierMessage(messages, "./data/files/messages.csv"); 
                  nbrMessageNonLu = 0;
                  for (int j = 0; j < nbrMessage; j++)
                    {
                        if (app.id == messages[j].apprenant.id && messages[j].statut == 0)
                        {
                            nbrMessageNonLu++;
                        }
                        
                    }     
                }
                printf("voulez-vous quitter ? O(o) ou N(n) : "); 
                choixQuitterMess =  getchar();

                if (choixQuitterMess == 'O' || choixQuitterMess == 'o')
                {
                    break;
                }
                
                
            } while (choixQuitterMess != 'O' || choixQuitterMess != 'o');
            
        }
    } while (choixMenuApprenant != 4);
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif
    if (choixMenuApprenant == 4)
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
             while ((cl = getchar()) != '\n' && cl != EOF);
        }
        log[0] = '\0';
        pass[0] = '\0';      
    }while(resultConnexion == 0 || resultConnexionApp == 0);
}

