extern int lireFichierUtilisateurs(Utilisateur utilisateurs[], char *fichier);
extern int lireFichierAdmin(Admin admins[], char *fichier);
extern int lireFichierAprennant(Apprenant apprenants[], char *fichier);
extern int lireFichierReferentiel(Referenciel referenciels[], char *fichier);
extern int lireFichierPromo(Promotion promos[], char *fichier);
extern int lireFichierPresence(Presence presences[], char *fichier);
extern int lireFichierPresenceDate(Date dates[], char *fichier);

extern int lireFichierMessage(Message message[], char *fichier);

extern void ajouterPresence(Presence nouvellePresence, char *fichier);

extern void marquerMessageLu(int idApp, int numero, char *fichier);

extern void genererFichierPresence(Presence presences[], int nbrPresence, 
  Apprenant apprenants[], int nbrApp, Utilisateur users[], int nbrUser, Referenciel refs[], int nbrRef,int idRef, Date date,Date dates[], int nbrDate, char *fichier);

extern void genererFichierPresence2(Presence presences[], int nbrPresence, 
  Apprenant apprenants[], int nbrApp, Utilisateur users[], int nbrUser, Referenciel refs[], int nbrRef,int idRef, Date date, char *fichier);

extern void envoiMessageAtous(char sujet[50], char texte[150], char *fichier);
extern void envoiMessageParClasse(char sujet[50], char texte[150], int idReferenciel, char *fichier);
extern void envoiMessageParSelection(Apprenant apprenants[], int nbrApprenant, char sujet[50], char texte[150],  char *fichier);


// extern Utilisateur login(char login[],char pass[]);

// void fichier();