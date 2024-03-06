extern int lireFichierUtilisateurs(Utilisateur utilisateurs[], char *fichier);
extern int lireFichierAdmin(Admin admins[], char *fichier);
extern int lireFichierAprennant(Apprenant apprenants[], char *fichier);
extern int lireFichierReferentiel(Referenciel referenciels[], char *fichier);
extern int lireFichierPromo(Promotion promos[], char *fichier);
extern int lireFichierPresence(Presence presences[], char *fichier);
extern void ajouterPresence(Presence nouvellePresence, char *fichier);

// extern Utilisateur login(char login[],char pass[]);

// void fichier();