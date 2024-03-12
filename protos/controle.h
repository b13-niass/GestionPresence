extern Date saisieDate(void);
extern void disableEcho();
extern void enableEcho();
extern int saisirInt(int min, int max, char msg[],char msgerr[]);
extern void saisiChaine(char chaine[], char msg[],char msgerr[]);
extern int login(char login[],char pass[], Utilisateur utilisateurs[], int taille, Utilisateur * u);
extern void saisiChainePassword(char chaine[], char msg[],char msgerr[]);
extern void saisiChainePasswordQuitter(char chaine[], char msg[],char msgerr[]);
extern void saisiChainePasswordOther(char chaine[], char msg[], char msgerr[]);
extern void obtenirDateAujourdhui(int *jour, int *mois, int *annee, int * h, int * mn, int * s);
extern Date obtenirDateAujourdhui2();
extern Heure obtenirHeure();

extern int testSiAnneeBissextile(int annee);
extern int testSiDateValide(int annee, int mois, int jour);
extern int calculNbrJourMois(int mois, int annee);
extern int saisirIntDate(int min, int max, char msg[],char msgerr[]);
extern int saisirDate(Date *date, char msg[], char msgerr[]);

extern Message excrireMessage();
extern void getReferentielName(int idRef, char chaine[]);
extern int isValidMatricule(char matricule[]);

extern int saisirHeureMinute(Heure *heure, char msg[], char msgerr[]);
extern void saisirMoisAnnee(Date *date, char msg[], char msgerr[]);