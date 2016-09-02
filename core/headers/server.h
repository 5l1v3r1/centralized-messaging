#ifndef __SERVEUR_H__
#define __SERVEUR_H__

/* Initialisation.
 * Creation du serveur.
 * renvoie 1 si �a c'est bien pass� 0 sinon
 */
int Initialisation();

/* Initialisation.
 * Creation du serveur en pr�cisant le service ou num�ro de port.
 * renvoie 1 si �a c'est bien pass� 0 sinon
 */
int InitialisationAvecService(char *service);


/* Attends qu'un client se connecte.
 * renvoie 1 si �a c'est bien pass� 0 sinon
 */
int AttenteClient();

/* Recoit un message envoye par le client.
 * retourne le message ou NULL en cas d'erreur.
 * Note : il faut liberer la memoire apres traitement.
 */
char *Reception();

/* Envoie un message au client.
 * Attention, le message doit etre termine par \n
 * renvoie 1 si �a c'est bien pass� 0 sinon
 */
int Emission(char *message);

/* Recoit des donnees envoyees par le client.
 * renvoie le nombre d'octets re�us, 0 si la connexion est ferm�e,
 * un nombre n�gatif en cas d'erreur
 */
int ReceptionBinaire(char *donnees, size_t tailleMax);

/* Envoie des donn�es au client en pr�cisant leur taille.
 * renvoie le nombre d'octets envoy�s, 0 si la connexion est ferm�e,
 * un nombre n�gatif en cas d'erreur
 */
int EmissionBinaire(char *donnees, size_t taille);


/* Ferme la connexion avec le client.
 */
void TerminaisonClient();

/* Arrete le serveur.
 */
void Terminaison();

/* Fonction permettant au serveur d'afficher la liste des mails pr�sents dans la bo�te aux lettres
 * du client de nom d'utilisateur login.
 */
void send_mails_list(char *login);

/* Fonction permettant au serveur de supprimer le mail de numero number, saisit par le client.
 */
void delete_mail(char *login, int number);

/* Pour l'utilisation des dossiers 
 * Envoyer au client le nombre de mails pr�sents dans sa boite mail.
 */
int count_mails(char *login);

/*Cr�er une Mailbox au login pass� en param�tre
 */
int register_user(char login[1024], char password[512]);

/* Verifie si le login/password saisit est correct*/
int authentication(char login[1024], char password[512]);

/* Envoyer au client le mail de num�ro [number_mail] au destinataire de login plac� en param�tre, consultation
 */
void read_mail(int number_mail, char* login);

/* Fonction qui stocke un mail dans le dossier Mailbox/login_dest.
 */ 
int send_mail(char* login_dest, char* login, char* object, char* message);

void extract_mail_info(char* request, size_t request_length, char* login_dest, char* object, char* message);

void extract_login_password(char* request, size_t request_length, char* login, char* password);

int extract_mail_number(char* request, size_t request_length);

#endif
