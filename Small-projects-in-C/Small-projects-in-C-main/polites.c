/* Μια εταιρεία έχει 5 πωλητές που διακινούν τα προϊόντα της και διατηρεί τις πωλήσεις κάθε πωλητή ανά δίμηνο για ένα έτος. Να δοθεί γραφεί πρόγραμμα που να υπολογίζει και να εμφανίζει:
Α) τις συγκεντρωτικές πωλήσεις της εταιρείας για το έτος
Β) τον μέσο όρο διμηνιαίων πωλήσεων της εταιρείας
Γ) τον καλύτερο πωλητή, και τη διαφορά πωλήσεων του καλύτερου και του χειρότερου πωλητή
Δ) το δίμηνο που η εταιρεία είχε τις περισσότερες πωλήσεις*/

# include <stdio.h>
# define POLITES 5
# define DIMINA  6

int main()
{
	int poliseis[POLITES][DIMINA]={{1, 4, 5,  8,2,1},
		                           {4, 9, 12,10,3,1},
		                           {10,19,18, 1,1,1},
		                           {5, 4,  3, 9,2,1},
		                           {1, 2,  3, 1,1,1}};
	int totalSum=0;
	double averagePerDimino[DIMINA];
	int poliseisAnaPoliti[POLITES];
	int kalyterosPolitis=0;
	int xeiroterosPolitis=0;
	int maxpoliseis=0;
	int minpoliseis=0;
	int kalyteroDimino=0;
	
	int i,j;	                           
	/** proto erotima synolikes poliseis **/	                           
	for(i=0;i<POLITES;i++)
	{
		for(j=0;j<DIMINA;j++)
		{
			totalSum=totalSum+poliseis[i][j];
		}
	}
	printf("Synolikes poliseis %d \n",totalSum);
	
	/** deytero erotima mesoi oroi diminon **/
	for(j=0;j<DIMINA;j++)
	{
		averagePerDimino[j]=0.0;
		for(i=0;i<POLITES;i++)
		{
			averagePerDimino[j]=averagePerDimino[j]+poliseis[i][j];
		}
		averagePerDimino[j]/=POLITES;
		printf("Mesos oros poliseon to dimino %4d einai %8.2lf \n",j,averagePerDimino[j]);
	}
	
	/** trito erotima  poliseis ana politi **/
	kalyterosPolitis=0;
	xeiroterosPolitis=0;
	
	for(i=0;i<POLITES;i++)
	{
		poliseisAnaPoliti[i]=0;
		for(j=0;j<DIMINA;j++)
		{
			poliseisAnaPoliti[i]+=poliseis[i][j];
		}
		if(i==0 || poliseisAnaPoliti[i]>maxpoliseis)
		{
			maxpoliseis=poliseisAnaPoliti[i];
			kalyterosPolitis=i;
		}
		
		if(i==0 || poliseisAnaPoliti[i]<minpoliseis)
		{
			minpoliseis=poliseisAnaPoliti[i];
			xeiroterosPolitis=i;
		}
		
	}
	printf("O kalyteros politis einai o %d \n",kalyterosPolitis);
	printf("O xeiroteros politis einai o %d \n",xeiroterosPolitis);
	printf("I diafora ton poliseon einai %d \n",maxpoliseis-minpoliseis);

    /** tetarto erotima -> kalytero dimino **/
    kalyteroDimino=0;
    maxpoliseis=averagePerDimino[0];
    for(j=0;j<DIMINA;j++)
    {
		if(averagePerDimino[j]>maxpoliseis)
		{
			maxpoliseis=averagePerDimino[j];
			kalyteroDimino=j;
		}
	}
	printf("To kalytero dimino itan to %d \n",kalyteroDimino);
	return 0;
}
