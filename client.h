

typedef struct{

            int idClient;
            char nom[20];
            char prenom[20];
            int cin;
            char adresse[25];
            int telephone;

              } client;

typedef struct data_client
{
	client individu;
	struct data_client *suivant;
} liste_client;



liste_client* Recherche_Client(liste_client *l,char *nom,char *prenom)
{


	while(l!=NULL)
		{
			if(strcmp(l->individu.nom,nom)==0 && strcmp(l->individu.prenom,prenom)==0)
				   {return l;}

          l=l->suivant;
		}

 	return NULL;

}


liste_client* Recherche_Client_supp(liste_client *l,char *nom,char *prenom)
{
   if(strcmp(l->individu.nom,nom)==0 && strcmp(l->individu.prenom,prenom)==0)
				   {return l;}


	while(l->suivant!=NULL )
		{
			if(strcmp((l->suivant)->individu.nom,nom)==0 && strcmp((l->suivant)->individu.prenom,prenom)==0)
				   {return l;}

          l=l->suivant;
		}

 	return NULL;

}


void Affiche_Client(liste_client *t)
{

	printf("\n\tNom          : %s",t->individu.nom);
	printf("\t\tPrenom         : %s",t->individu.prenom);
    printf("\n\tId         : %d",t->individu.idClient);
	printf("\n\tCIN          : %d",t->individu.cin);
    printf("\n\tNum telephone: %d",t->individu.telephone);

    printf("\n\tAdresse         : %s",t->individu.adresse);

    printf("\n\n\n");

}




liste_client* Saisie_Client()
{
	client aide_client;
    liste_client *outpt=NULL;

	EnTete();

	outpt=(liste_client*)malloc(sizeof(liste_client));
	//aide_client=(client *)malloc(sizeof(client));

          ///****SAISIE DU CLIENT*****

	printf("\nSaisie les info du client........");

	printf("\n\t\tNom           : ");
	scanf("%s",aide_client.nom);

	printf("\n\t\tPrenom        : ");
	scanf("%s",aide_client.prenom);

	printf("\n\t\tId           : ");
	scanf("%d",&aide_client.idClient);

	printf("\n\t\tN° telephone  : ");
	scanf("%d",&aide_client.telephone);

	printf("\n\t\tNum. CIN      : ");
	scanf("%d",&aide_client.cin);

	printf("\n\t\tAdresse        : ");
	scanf("%s",aide_client.adresse);

	   ///****INITIALISATION DE  DATA_CLIENT****
	outpt->individu=aide_client;
	outpt->suivant=NULL;

	return outpt;
}



liste_client* Inserer_En_Fin_Client(liste_client *l,liste_client *push)
{
	liste_client *aide=NULL;


	if(l==NULL)
	{
		push->suivant=NULL;
		l=push;
		return l;
	}
	else
	{
	    aide=l;
		while(aide->suivant!=NULL)
			aide=aide->suivant;

		aide->suivant=push;
		push->suivant=NULL;
	}

	return l;
}


liste_client* modifier_Client(liste_client *l)
{
	liste_client *modif_client=NULL,*enreg=NULL;
	char nom[20],prenom[20];

	if(l==NULL)
    {
        Alert("Pas de client");
		getch();
    }
	else
	{
		printf("\n\t\tNom    ( \x22 quitter \x22 pour annuler) :  ");
		scanf("%s",nom);

		if(strcmp(nom,"quitter")!=0)
		{
			printf("\n\t\tPrenom ( \x22 quitter \x22 pour annuler) :  ");
			scanf("%s",prenom);
		}

		if( (strcmp(prenom,"quitter") != 0 ) && (strcmp(nom,"quitter") != 0 ) )
		{
			modif_client=Recherche_Client(l,nom,prenom);
            if(modif_client==NULL)
				Alert("Client non trouve");
			else
			{
				enreg=modif_client;
				modif_client=Saisie_Client();
				enreg->individu=modif_client->individu;
				free(modif_client);
				Alert("Client modifie");
				return l;
			}
		}
	}
	Alert("Modification anullee.");
	//getch();

	return l;
}



liste_client* supprimer_Client(liste_client *t)
{
	liste_client *client_supp_avant=NULL,*aide=NULL;
	char nom[20],prenom[20];



	if(t==NULL)
		Alert("Pas de client");
	else
	{
		printf("\n\t\tNom    ( \x22 quitter \x22 pour annuler) :  ");
		scanf("%s",nom);
		if(strcmp(nom,"quitter")!=0)
		{
			printf("\n\t\tPrenom    ( \x22 quitter \x22 pour annuler) :  ");
			scanf("%s",prenom);
		}
		if(strcmp(nom,"quitter")==0 || strcmp(prenom,"quitter")==0 )
        {
            Alert("supprision anullee");
            return t;
        }

			client_supp_avant=Recherche_Client_supp(t,nom,prenom);
			if(client_supp_avant!=NULL)
			{
				if(client_supp_avant->individu.idClient == t->individu.idClient)
				{
					t=t->suivant;
                    free(client_supp_avant);
					Alert("Client supprime");
					return t;
				}

				else
					{
						aide=(client_supp_avant->suivant)->suivant;
                        free(client_supp_avant->suivant);
                        client_supp_avant->suivant=aide;
						Alert("Client supprime");
						return t;
					}
			}
			else
				Alert("Client non trouve");

	}

	return t;

}

liste_client* supprimer_Client(liste_client *t,liste_Contrat **l,liste_vtr *v)
{
	liste_client *client_supp_avant=NULL,*aide=NULL;
	liste_Contrat *help=NULL;
	liste_vtr *help_vtr=NULL;
	char nom[20],prenom[20];



	if(t==NULL)
		Alert("Pas de client");
	else
	{
		printf("\n\t\tNom    ( \x22 quitter \x22 pour annuler) :  ");
		scanf("%s",nom);
		if(strcmp(nom,"quitter")!=0)
		{
			printf("\n\t\tPrenom :  ");
			scanf("%s",prenom);
		}
		if(strcmp(nom,"quitter")==0 || strcmp(prenom,"quitter")==0 )
        {
            Alert("supprision anullee");
            return t;
        }

        client_supp_avant=Recherche_Client_supp(t,nom,prenom);
        if(client_supp_avant!=NULL)
        {
            if(client_supp_avant->individu.idClient == t->individu.idClient)
            {
                help=Rech_Contrat_Id(*l,t->individu.idClient);
            }
            else
               help=Rech_Contrat_Id(*l,client_supp_avant->suivant->individu.idClient);

            if(strcmp(t->individu.nom,nom)==0 && strcmp(t->individu.prenom,prenom)==0 )
            {

               if(help != NULL)
               {
                  Supprimer_Contrat_client(l,help,v);
                  Alert("le client a alloue une voiture");
                  t=t->suivant;
                  free(client_supp_avant);
                  Alert("Client supprime");
                  return t;

               }

               else
               {

                   t=t->suivant;
                   free(client_supp_avant);
                   Alert("Client supprime");
                   return t;
               }

            }

            else
            {
                   if(help != NULL)
                   {
                        Supprimer_Contrat_client(l,help,v);
                        Alert("le client a alloue une voiture");
                        aide=(client_supp_avant->suivant)->suivant;
                        free(client_supp_avant->suivant);
                        client_supp_avant->suivant=aide;
                        Alert("Client supprime");
						return t;
                    }
                        aide=(client_supp_avant->suivant)->suivant;
                        free(client_supp_avant->suivant);
                        client_supp_avant->suivant=aide;
                        Alert("Client supprime");
                        return t;

            }
        }
        else
          Alert("Client non trouve");

	}

	return t;

}





