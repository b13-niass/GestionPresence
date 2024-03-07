extern int vueLogin();
extern int menuAdmin();
extern int menuApprenant();
extern int menuMarquerPresence();
extern void AfficherMenu(char msg[]);
extern void traitementAdmin(int * result, Utilisateur * u);
extern void traitementApprenant(int * result, Utilisateur * u);
extern Heure heurePresence(int idApprenant, Presence presences[], int nbrPresence);