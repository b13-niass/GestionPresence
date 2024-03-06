#include "prototype.h"
int autoIdEtudiant = 1;
enum niveau{L1 = 1,L2,L3,M1,M2,M3};
enum type{DEVOIR,EXAMEN};
typedef struct
{
    int j, m, a;

} DATE;

typedef struct
{
    int id;
    char mat[11];
    char nom[50];
    char prenom[50];
    DATE dn;

} ETUDIANT;

typedef struct
{
    int id;
    char libelle[50];
    int coef;

} MATIERE;

typedef struct
{
    char libelle[50];
    MATIERE matieres[10];
    ETUDIANT etudiants[100];
    int nbrEtudiant;
    int nbrMatiere;
    enum niveau n;
}CLASSE;

typedef struct
{
    ETUDIANT etudiant;
    MATIERE matiere;
    float note;
    enum type t;

}EVALUATION;
// prototype
void afficherDate(DATE);
DATE saisieDate(void);
int saisirInt(int, int, char[]);
void genererMat(char mat[], ETUDIANT e);
ETUDIANT saisirEtudiant();
void afficherEtudiant(ETUDIANT e);
MATIERE saisirMatiere();
void afficherMatiere(MATIERE m);
CLASSE saisirClasse();
void afficherClasse(CLASSE e);
EVALUATION saisirEvaluation();
void afficherEvaluation(EVALUATION e);
int main()
{

    afficherEtudiant(saisirEtudiant());

    return 0;
}

DATE saisieDate(void)
{
    DATE d;
    puts("Entrez une date [j,m,a]");
   // scanf("%d%d%d", &d.j, &d.m, &d.a);
   d.j = saisirInt(1, 31, "entrez le jour");
   d.m = saisirInt(1, 12, "entrez le mois");
   d.a = saisirInt(1, 2024, "entrez l'année");
    return d;
}
void afficherDate(DATE a)
{
    printf("la date est %d-%d-%d", a.j, a.m, a.a);
}
int saisirInt(int min, int max, char msg[])
{
    int x;
    do
    {
        puts(msg);
        scanf("%d", &x);
    } while (x<min || x>max);

    return x;
}

void genererMat(char m[], ETUDIANT e){
    char iP = e.prenom[0];
    char iN = e.nom[0];
    char id = e.id;
   
    
    if (e.id > 0 && e.id <10)
    {   
      sprintf(m, "MAT-%c%c-000%d",toupper(e.prenom[0]),toupper(e.nom[0]), e.id);
    }
    if (e.id > 9 && e.id < 100)
    {
        sprintf(m, "MAT-%c%c-00%d",toupper(e.prenom[0]),toupper(e.nom[0]), e.id);
    }
    if (e.id > 99 && e.id < 1000)
    {
        sprintf(m, "MAT-%c%c-0%d",toupper(e.prenom[0]),toupper(e.nom[0]), e.id);
    }
    if (e.id > 999 && e.id < 10000)
    {
        sprintf(m, "MAT-%c%c-00%d",toupper(e.prenom[0]),toupper(e.nom[0]), e.id);
    }

    //  printf("%s\n", m);
}

ETUDIANT saisirEtudiant(){
    ETUDIANT e;
    char m[11] = "MAT-";
    e.id = ++autoIdEtudiant;
    puts("Donnez le nom :");
    fgets(e.nom, sizeof(e.nom), stdin);
    puts("Donnez le prénom :");
    fgets(e.prenom, sizeof(e.prenom), stdin);
    genererMat(m, e);
    strcpy(e.mat, m);
    e.dn = saisieDate();
    return e;

}
void afficherEtudiant(ETUDIANT e)
{
    printf("l'étudiant est [%d, %s, %s, %s, %d-%d-%d]",e.id, e.mat, e.prenom, e.nom, e.dn.j, e.dn.m,e.dn.a);
}

MATIERE saisirMatiere(){

}
void afficherMatiere(MATIERE m){

}
CLASSE saisirClasse(){

}
void afficherClasse(CLASSE e){

}
EVALUATION saisirEvaluation(){

}
void afficherEvaluation(EVALUATION e){

}