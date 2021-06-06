
void  en_train(char *msg)
{
	int i;

	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t%s",msg);
	for(i=0;i<6;i++)
	{
		Sleep(130);
		printf(".");
	}

}

/*void free_Voiture(liste_vtr *t)
{
  if(t == NULL)
        return;
  free_Voiture(t->suivant);
  free(t);

}

void free_client(liste_client *t)
{
  if(t == NULL)
        return;
  free_client(t->suivant);
  free(t);

}
void free_contrat(liste_Contrat *t)
{
  if(t == NULL)
        return;
  free_contrat(t->suivant);
  free(t);

}*/

void free_Voiture(liste_vtr **t)
{
    liste_vtr *ptr;
    if (*t == NULL)
           return;
    while (*t != NULL)
    {
       ptr = *t;
       *t = (*t)->suivant;
       free(ptr);
    }


}

void free_client(liste_client **t)
{
    liste_client *ptr;
    if (*t == NULL)
           return;
    while (*t != NULL)
    {
       ptr = *t;
       *t = (*t)->suivant;
       free(ptr);
    }


}

void free_contrat(liste_Contrat **t)
{
    liste_Contrat *ptr;
    if (*t == NULL)
           return;
    while (*t != NULL)
    {
       ptr = *t;
       *t = (*t)->suivant;
       free(ptr);
    }


}

liste_vtr* chargement_Voiture(char *nom)
{
	FILE* stock;
	liste_vtr *charge=NULL,*outpt=NULL;
	liste_vtr *p=NULL;
	voiture voit;
	stock=fopen(nom,"r");

	if(stock!=NULL)
	{
		while(fread(&voit,sizeof(voiture),1,stock))
		{
			charge=(liste_vtr*)malloc(sizeof(liste_vtr));
			charge->vtr=voit;
			charge->suivant=NULL;

			if (outpt==NULL)
				outpt=charge;
			else
			{
				p=outpt;
				while(p->suivant!=NULL)
					p=p->suivant;
				p->suivant=charge;
			}
		}
      fclose(stock);
	}

	en_train("Chargement des voitures");
	return outpt;
}


liste_client* chargement_Client(char *nom)
{
	FILE *fp;
	client person;
	liste_client *charge=NULL,*outpt=NULL,*p=NULL;

	fp=fopen(nom,"r");

	if(fp!=NULL)
	{
		while(fread(&person,sizeof(client),1,fp))
		{
			charge=(liste_client*)malloc(sizeof(liste_client));
			charge->individu=person;
			charge->suivant=NULL;

			if (outpt==NULL)
				outpt=charge;
			else
			{
				p=outpt;
				while(p->suivant!=NULL)
					p=p->suivant;
				p->suivant=charge;
			}
		}

     fclose(fp);
	}

	en_train("Chargement des clients...");

	return outpt;
}


liste_Contrat* chargement_Contrat(char *nom)
{
	FILE* fp;
	contrat cont;
	liste_Contrat *charge=NULL,*p=NULL,*outpt=NULL;

	fp=fopen(nom,"r");

	if(fp!=NULL)
	{
		while(fread(&cont,sizeof(contrat),1,fp))
		{
			charge=(liste_Contrat*)malloc(sizeof(liste_Contrat));
			charge->contra=cont;
			charge->suivant=NULL;
			if(outpt==NULL)
				{outpt=charge;}
			else
			{
				p=outpt;
				while(p->suivant!=NULL)
					p=p->suivant;
				p->suivant=charge;
			}
		}
	  fclose(fp);
	}

	en_train("Chargement des contrats");

	return outpt;
}






void sauvgarde_Voiture(liste_vtr *l,char nom[25])
{
	FILE* stock;
	liste_vtr *sauv=NULL;


	stock=fopen(nom,"w");
	sauv=l;

	while(sauv!=NULL)
	{
		fwrite(&sauv->vtr,sizeof(voiture),1,stock);
		sauv=sauv->suivant;
	}

	fclose(stock);


	en_train("Sauvgarde des Voitures");
}


void sauvgarde_Client(liste_client *l,char *nom)
{
	FILE *fp;

	fp=fopen(nom,"w");

	while(l!=NULL)
	{
		fwrite(&l->individu,sizeof(client),1,fp);
		l=l->suivant;
	}

	fclose(fp);

	en_train("Sauvgarde des clients");
}


void Sauvgarde_Contrat(liste_Contrat *l,char *nom)
{
	FILE *fp;

	fp=fopen(nom,"w");

	while(l!=NULL)
	{
		fwrite(&l->contra,sizeof(contrat),1,fp);
		l=l->suivant;
	}


	fclose(fp);


	en_train("Sauvgarde des contrats");

}


void Sauvgarde(int verif,liste_vtr **lesvoitures,liste_client **lesclients,liste_Contrat **lescontrats)
{
	int tmp;

	if(verif==0)
	{
		do
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\n                    \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                    \xb3     Sauvgarder les changements ?     \xb3");
			printf("\n                    \xb3          oui(o)    non(n)            \xb3");
			printf("\n                    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			tmp=getch();

			if(tmp==111)
			{
				sauvgarde_Voiture(*lesvoitures,"voiture.txt");
				sauvgarde_Client(*lesclients,"client.txt");
				Sauvgarde_Contrat(*lescontrats,"contrat.txt");
				free_Voiture(lesvoitures);
				free_client(lesclients);
				free_contrat(lescontrats);
			}
			if(tmp==110)
				Alert("Pas de sauvgarde");
		}while((tmp!=111)&&(tmp!=110));
	}

	if(verif==1)
	{
		do
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\n                    \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                    \xb3     Sauvgarder les changements       \xb3");
			printf("\n                    \xb3     effectuer sur les contrat ?      \xb3");
			printf("\n                    \xb3          oui(o)    non(n)            \xb3");
			printf("\n                    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			tmp=getch();

			if(tmp==111)
            {
                sauvgarde_Voiture(*lesvoitures,"voiture.txt");
				sauvgarde_Client(*lesclients,"client.txt");
				Sauvgarde_Contrat(*lescontrats,"contrat.txt");
                //en_train("Sauvgarde des Voitures et des clients");

            }
			if(tmp==110)
            {
                 free_client(lesclients);
                 *lesclients=chargement_Client("client.txt");
                 free_contrat(lescontrats);
                 *lescontrats=chargement_Contrat("contrat.txt");
                 free_Voiture(lesvoitures);
                 *lesvoitures=chargement_Voiture("voiture.txt");
                 Alert("Pas de sauvgarde");
            }

		}while((tmp!=111)&&(tmp!=110));
	}

	if(verif==2)
	{
		do
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\n                    \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                    \xb3     Sauvgarder les changements       \xb3");
			printf("\n                    \xb3     effectuer sur les voitures ?     \xb3");
			printf("\n                    \xb3          oui(o)    non(n)            \xb3");
			printf("\n                    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			tmp=getch();

			if(tmp==111)
			{
                sauvgarde_Voiture(*lesvoitures,"voiture.txt");
                //en_train("Sauvgarde des Voitures");
			}
			if(tmp==110)
            {
                 free_Voiture(lesvoitures);
                 *lesvoitures=chargement_Voiture("voiture.txt");
                 Alert("Pas de sauvgarde");
            }

		}while((tmp!=111)&&(tmp!=110));
	}

	if(verif==3)
	{
		do
		{
			system("cls");
			printf("\n\n\n\n\n\n");
			printf("\n                    \xda\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xbf");
			printf("\n                    \xb3     Sauvgarder les changements       \xb3");
			printf("\n                    \xb3     effectuer sur les clients ?      \xb3");
			printf("\n                    \xb3          oui(o)    non(n)            \xb3");
			printf("\n                    \xc0\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xc4\xd9");
			tmp=getch();

			if(tmp==111)
			{
				sauvgarde_Voiture(*lesvoitures,"voiture.txt");
				sauvgarde_Client(*lesclients,"client.txt");
				Sauvgarde_Contrat(*lescontrats,"contrat.txt");
				//en_train("Sauvgarde des Clients");
			}
			if(tmp==110)
            {
                free_client(lesclients);
                free_contrat(lescontrats);
                free_Voiture(lesvoitures);
                *lescontrats=chargement_Contrat("contrat.txt");
                *lesvoitures=chargement_Voiture("voiture.txt");
                *lesclients=chargement_Client("client.txt");
                Alert("Pas de sauvgarde");
            }
		}while((tmp!=111)&&(tmp!=110));
	}

}







