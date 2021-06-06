#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include <voiture.h>
#include <client.h>
#include <contrat.h>
#include <menu.h>
#include <save.h>


int main()
{

    char nom[20],prenom[20],nom1[20];

	liste_vtr *les_voitures=NULL,*une_voiture=NULL,*status_car=NULL;
	liste_client *les_clients=NULL,*un_client=NULL;
	liste_Contrat *les_contrats=NULL,*un_contrat=NULL;
	int choix_principal=0,choix_second=0,choix,tmp;


    les_voitures=chargement_Voiture("voiture.txt");
	les_clients=chargement_Client("client.txt");
	les_contrats=chargement_Contrat("contrat.txt");




while((choix_second!=27)&&(choix_principal!=9))
{
    choix_principal=MenuPrincipal();
    switch(choix_principal)
  {

    case 1:

        while(choix_second!=27)
		{
		    choix_second=MenuLocation();


			if(choix_second==49)
			{
               printf("\n\n\t\t\tUn contrat(1)\ttous contrats(2)\n\t\t\t\t\t");
               choix=getch();
                if(choix==49)
				{
					un_contrat=Recherche_Contrat(les_contrats);
					if(un_contrat==NULL)
						Alert("Contrat non-trouvee");
					else
						Affiche_Contrat(un_contrat);
				}

				if(choix==50)
				{
					un_contrat=les_contrats;
					if(un_contrat==NULL)
						Alert("Pas De Contrat");
					else
                    {
                        while(un_contrat!=NULL)
                        {
                          Affiche_Contrat(un_contrat);
                          un_contrat=un_contrat->suivant;
                        }
                    }
                    getch();
				}
			}
			if(choix_second==50)
			{

				printf("\n\n\t\tvous etes deja un client oui(o)/non(n) : ");
				do
				{
                    choix=getch();
				}while((choix!=111)&&(choix!=110));


                if(choix==111)
				{
					EnTete();

					printf("\n\n\tverefication de vos info...");
					printf("\n\n\t\tNom       : ");
					scanf("%s",nom1);
					printf("\n\n\t\tPrenom    : ");
					scanf("%s",prenom);
					printf("\n\n\t\tNom Voiture: ");
					scanf("%s",nom);
					status_car=Recherche_Voiture_Libre(les_voitures,nom);
					if(status_car != NULL )
                    {
                        Alert("Voiture Libre");
                        un_client=Recherche_Client(les_clients,nom1,prenom);
                        if(un_client==NULL)
                        {
                           Alert("Client non-trouve\n\n\t\t\t\tsaisir ses information");
                           getch();
                           un_client=Saisie_Client();
                           les_clients=Inserer_En_Fin_Client(les_clients,un_client);
                           un_contrat=saisie_Contrat(status_car,un_client);
                           un_contrat->suivant=les_contrats;
                           les_contrats=un_contrat;
                           Alert("Location effectuee");
                        }
                        else
                        {
                           Alert("Client trouve");
                           un_contrat=saisie_Contrat(status_car,un_client);
                           un_contrat->suivant=les_contrats;
                           les_contrats=un_contrat;
                           Alert("Location effectuee");
                        }
                    }
                    else
                    {
                           Alert("Voiture n est pas disponible");

                    }
			     }

			     if(choix==110 )
                 {
                    EnTete();
                    printf("\n\n\t\tNom Voiture: ");
                    scanf("%s",nom);
                    status_car=Recherche_Voiture_Libre(les_voitures,nom);
                    if(status_car != NULL )
                    {
                           Alert("saisir les information du client");
                           un_client=Saisie_Client();
                           les_clients=Inserer_En_Fin_Client(les_clients,un_client);
                           un_contrat=saisie_Contrat(status_car,un_client);
                           un_contrat->suivant=les_contrats;
                           les_contrats=un_contrat;
                           Alert("Location effectuee");

                    }
                    else
                    {
                           Alert("Voiture n est pas disponible");
                    }
                 }
			}

			if(choix_second==51)
				  les_contrats=Retour_Contrat(les_contrats,les_voitures);


			if(choix_second==52)
				  les_contrats=Modifier_Contrat(les_contrats);


			if(choix_second==53)
			{
				  un_contrat=Recherche_Contrat(les_contrats);
				  if(un_contrat==NULL)
                  Alert("Contrat non-trouvee");
				  else
                  {
					    les_contrats=Supprimer_Contrat(les_contrats,un_contrat,les_voitures);
					    Alert("Contrat supprimer");
				  }
			}

			if(choix_second==57)
				  choix_second=27;
		}

        Sauvgarde(1,&les_voitures,&les_clients,&les_contrats);
        choix_second=0;
        break;




    case 2:


        while(choix_second!=27)
        {
			choix_second=MenuGestionVoiture();
			if(choix_second==49)
			{
			       printf("\n\n\t\t\tUne Voiture(1)\tTous les Voitures(2)\n\t\t\t\t\t");
                   if(getch()==49)
                   {
                         EnTete();
						 printf("\n\n\t\tVoiture recherchee...");
						 printf("\n\n\t\tId de voiture   :  ");
						 scanf("%d",&tmp);
                         une_voiture=Recherche_Voiture(les_voitures,tmp);
						 if(une_voiture == NULL)
							 Alert("Voiture non-trouvee");
						 else
                         {
                             Alert("Voiture trouvee");
                             Affiche_voiture(une_voiture);
                         }
					}
					if(getch()==50)
					{
                         une_voiture=les_voitures;
					     if(une_voiture == NULL)
							 Alert("Pas De Voiture");
                         else
                         {
                                EnTete();
                                while(une_voiture !=NULL)
                                {
                                    Affiche_voiture(une_voiture);
                                    une_voiture=une_voiture->suivant;
                                }
                         }
                         getch();
                    }
               }

               if(choix_second==50)
			   {
					 printf("\n\n\t\tVoiture (1)\t\tplusieurs Voitures (2)\n\t\t");
                     do
                      {
                       choix=getch();
                      }while( (choix!=49) && (choix!=50) );

                     if(choix==49)
                     {
                            une_voiture=Saisie_info_Voiture();
                            les_voitures=inserer_en_fin(les_voitures,une_voiture);
                            Alert("voiture enregistrer");
                     }


                     if(choix==50)
                     {
                            printf("\n\n\t\tsaisr le nombre des Voiture : ");
                            scanf("%d",&tmp);
                            int i=0;
                            while(i<tmp)
                            {
                                une_voiture=Saisie_info_Voiture();
                                les_voitures=inserer_en_fin(les_voitures,une_voiture);
                                i++;
                            }
                            Alert("enregistrement Voiture effectuer");
                     }
			   }


			   if(choix_second==51)
				     les_voitures=Modifier_info_Voiture(les_voitures);


               if(choix_second==52)
			         les_voitures=Supprimer_Voiture(les_voitures);


			   if(choix_second==57)
                     choix_second=27;
		}

		Sauvgarde(2,&les_voitures,&les_clients,&les_contrats);
		choix_second=0;
		break;

    	case 3:



		while(choix_second!=27)
		{
			choix_second=MenuGestionClient();

            if(choix_second==49)
			{

                printf("\n\n\t\t\tUn client(1)\t\tTous clients(2)\n\n\t\t\t\t\t");
				choix=getch();
				if(choix==49)
				    {
                            EnTete();
                            printf("\n\n\tClient ....");
                            printf("\n\t\tNom          : ");
                            scanf("%s",nom);
                            printf("\n\t\tPrenom       : ");
                            scanf("%s",prenom);
                            un_client=Recherche_Client(les_clients,nom,prenom);
                            if(un_client==NULL)
                                 {
                                    Alert("Client non-trouver");
                                 }
                            else
                                 {
                                    Alert("Client trouver");
                                    Affiche_Client(un_client);
                                 }
                            getch();
				    }


				if(choix==50)
				{
                            un_client=les_clients;
                            if(un_client==NULL)
                               Alert("Pas de Client");
                             else{
                                    EnTete();
                                    while(un_client!=NULL)
                                        {
                                           Affiche_Client(un_client);
                                           un_client=un_client->suivant;
                                        }
                                     getch();
					             }
				}
			}



			if(choix_second==50)
			  {

                 un_client=Saisie_Client();
                 les_clients=Inserer_En_Fin_Client(les_clients,un_client);

			  }


			if(choix_second==51)
			  {
				 les_clients=modifier_Client(les_clients);
			  }


			if(choix_second==52)
			  {
				les_clients=supprimer_Client(les_clients);
			  }


			if(choix_second==57)
		       {
				 choix_second=27;
               }
		}


        Sauvgarde(3,&les_voitures,&les_clients,&les_contrats);
		choix_second=0;

		break;


		case 9:
		   break;

}
}


Sauvgarde(0,&les_voitures,&les_clients,&les_contrats);
return 0;




}
