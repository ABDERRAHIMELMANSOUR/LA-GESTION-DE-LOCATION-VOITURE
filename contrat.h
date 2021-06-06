typedef struct {char dt[12];} date;


typedef struct{

            float numContrat;
            int idVoiture;
            int idClient;
            date debut;
            date fin;
            int coute;

              } contrat;

typedef struct data_Contrat{
	contrat contra;
	struct data_Contrat *suivant;
} liste_Contrat;

liste_Contrat* Recherche_Contrat(liste_Contrat *l)
{
	liste_Contrat *aide=NULL;
	int Id;
	float num;

	printf("\n\tId de voiture louee   :  ");
	scanf("%d",&Id);
	printf("\n\tNum du contrat        :  ");
	scanf("%f",&num);
	aide=l;
	while(aide!=NULL)
	{
		if(aide->contra.idVoiture == Id)
			if(aide->contra.numContrat == num)
					return aide;

		aide=aide->suivant;

	}

	return NULL;

}

void Affiche_Contrat(liste_Contrat *crt)
{
	EnTete();

	printf("\n\tN\xf8 du contrat   :  %.0f\n------------------------------\n",crt->contra.numContrat);

	printf("\n\n\tId Voiture         :  %d",crt->contra.idVoiture);
	printf("\n\n\tId Client            :  %d",crt->contra.idClient);

	printf("\n\n\tDebut              :  %s",crt->contra.debut.dt);
	printf("\n\n\tFin                :  %s",crt->contra.fin.dt);

	printf("\n\n\tCout location      :   %d TTC",crt->contra.coute);

	printf("\n\n");

   getch();
}


liste_Contrat* saisie_Contrat(liste_vtr *l,liste_client *t)
{
    liste_Contrat *aide=NULL;

	EnTete();
	aide=(liste_Contrat*)malloc(sizeof (liste_Contrat) );
    printf("\n\tsaisir un code contrat :");
    scanf("%f",&aide->contra.numContrat);

	aide->contra.idVoiture=l->vtr.idVoiture;
	aide->contra.idClient=t->individu.idClient;

	printf("\n\tNumero contrat : %.0f",aide->contra.numContrat);

    printf("\n\tDate du debut    :  ");
    scanf("%s",aide->contra.debut.dt);

    printf("\n\tDate retour      :  ");
    scanf("%s",aide->contra.fin.dt);

	printf("\n\tnombre jour      : ");
	scanf("%d",&aide->contra.coute);

	aide->contra.coute=(aide->contra.coute)*(l->vtr.prixJour);
	strcpy(l->vtr.EnLocation,"oui");

	return aide;

}

liste_Contrat* Supprimer_Contrat(liste_Contrat *l,liste_Contrat *supp,liste_vtr *t)
{
	liste_Contrat *parc=NULL;
    liste_vtr *aide=NULL;


	if(supp==l)					///SUPPRIMER EN TETE
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		l=l->suivant;
	    free(supp);
	    return l;
	}


	parc=l;
	while((parc!=NULL)&&(parc->suivant!=supp))
        parc=parc->suivant;

	if(parc->suivant==supp)
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		parc->suivant=supp->suivant;
		free(supp);
	}

	return l;

}



liste_Contrat* Retour_Contrat(liste_Contrat *l,liste_vtr *t)
{
	liste_Contrat *contr=NULL;

	EnTete();

	contr=Recherche_Contrat(l);

	if(contr==NULL)
		{Alert("Contrat non-trouve");return l;}

	else
	{

		printf("\n\tContrat numero   :  %.0f",contr->contra.numContrat);
		printf("\n\tCout    :  %d\n\n",contr->contra.coute);
		l=Supprimer_Contrat(l,contr,t);
        Alert("Contrat supprimer");
	}
	Alert("statut de la voiture est change.");
    return l;

	//getch();
}



liste_Contrat* Modifier_Contrat(liste_Contrat *l)
{
	liste_Contrat *rech=NULL;

	if(l==NULL)
            {
                Alert("Pas de contrat disponible");
                return l;
            }

	rech=Recherche_Contrat(l);

	if(rech==NULL)
            {
                Alert("Contrat non-trouve");
                return l;
            }

     Alert("Contrat trouvee.");
     printf("\n\tDate du debut    :  ");
     scanf("%s",rech->contra.debut.dt);
     printf("\n\tDate retour      :  ");
     scanf("%s",rech->contra.fin.dt);
     Alert("Contrat modifie");
	 return l;

}



liste_Contrat* Rech_Contrat_Id(liste_Contrat *l,int Id)
{
	liste_Contrat *aide=NULL;

	aide=l;
	while(aide!=NULL)
	{
		if(aide->contra.idVoiture == Id)
					return aide;

		aide=aide->suivant;

	}

	return NULL;

}








void Supprimer_Contrat_client(liste_Contrat **l,liste_Contrat *supp,liste_vtr *t)
{
	liste_Contrat *parc=NULL;
    liste_vtr *aide=NULL;


	if(supp==*l)					///SUPPRIMER EN TETE
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		free(aide);
		*l=(*l)->suivant;
	    free(supp);
	    return;
	}


	parc=*l;
	while((parc!=NULL)&&(parc->suivant!=supp))
        parc=parc->suivant;

	if(parc->suivant==supp)
	{
	    aide=Recherche_Voiture(t,supp->contra.idVoiture);
		strcpy(aide->vtr.EnLocation,"non");
		aide=NULL;
		free(aide);
		parc->suivant=supp->suivant;
		free(supp);
	}

	return;

}

