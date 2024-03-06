#include "../prototype.h"

int menuAdmin(){
    int choixMenuAdmin;

    #ifdef _WIN32
    system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif

    do
    {
        printf("1 - GESTION DES ÉTUDIANTS\n");
        printf("2 - GÉNÉRATION DE FICHIERS\n");
        printf("3 - MARQUER LES PRÉSENCES \n");
        printf("4 - ENVOYER UN MESSAGE \n");
        printf("5 - Quitter \n");

        printf("Faite un choix: \n");
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

void AfficherMenu(char msg[]) {
    printf("\n******************************\n");
    printf("    %s            \n", msg);
    printf("******************************\n");
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
        if (u.type == 1)
        {
            menuAdmin();
        }
        if (u.type == 2)
        {
            menuApprenant();
        }
    }while(resultConnexion == 0);
}

