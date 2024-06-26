extern int vueLogin();
extern int menuAdmin();
extern int menuApprenant(int nbrMessagesNonLu);
extern int menuMarquerPresence();
extern void AfficherMenu(char msg[]);
extern void traitementAdmin(int * result, Utilisateur * u);
extern void traitementApprenant(int * result, Utilisateur * u);
extern Heure heurePresence(int idApprenant, Presence presences[], int nbrPresence);
extern int menuGenererFichier();
extern int verifierPresence(int idApprenant, Presence presences[], int nbrPresence);
extern int verifierPresenceParDate(int idApprenant, Presence presences[], int nbrPresence, Date date);
extern int menuReferenciel();

extern int verifierPresenceParDategetHeure(int idApprenant, Presence presences[], int nbrPresence, Date date, Heure * heure);
extern int verifierAbsenceParDate(int idApprenant, Presence presences[], int nbrPresence, Date date);
extern int verifierRetardParDate(int idApprenant, Presence presences[], int nbrPresence, Date date, int * nbMinuteRetard);
extern int verifierRetardParMois(int idApprenant, Presence presences[], int nbrPresence, Date date, int * nbMinuteRetard);