extern Date saisieDate(void);
extern void disableEcho();
extern void enableEcho();
extern int saisirInt(int min, int max, char msg[],char msgerr[]);
extern void saisiChaine(char chaine[], char msg[],char msgerr[]);
extern int login(char login[],char pass[], Utilisateur utilisateurs[], int taille, Utilisateur * u);
extern void saisiChainePassword(char chaine[], char msg[],char msgerr[]);
extern void obtenirDateAujourdhui(int *jour, int *mois, int *annee, int * h, int * mn, int * s);