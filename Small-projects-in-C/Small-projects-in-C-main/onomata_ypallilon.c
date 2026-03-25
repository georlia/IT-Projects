/* Μια εταιρία απασχολεί 5 υπαλλήλους. Να γραφεί πρόγραμμα το οποίο να διαβάζει για κάθε υπάλληλο το ονοματεπώνυμό του και τις ετήσιες αποδοχές του και να τα αποθηκεύει σε κατάλληλους πίνακες.
 Να γίνει πρόγραμμα που να υπολογίζει και να εμφανίζει:
	α) Τα ονόματα των υπαλλήλων με αποδοχές > 20000.
	β) Το όνομα του υπαλλήλου με τις μέγιστες αποδοχές.
	γ) Να εμφανιστούν τα στοιχεία των υπαλλήλων ταξινομημένα ως προς τις αποδοχές. */
	
#include <stdio.h>
# include <string.h>
# define MAXN 5

int main()
{
	char name[MAXN][30];
	char lastname[MAXN][30];
	double salary[MAXN];
	int i,j;
	int maxIndex=0;
	double maxSalary=0;
	for(i=0;i<MAXN;i++)
	{
		printf("Dose onoma ypallilou %d \n",i);
		scanf("%s",name[i]);
		printf("Dose epitheto ypallilou %d \n",i);
		scanf("%s",lastname[i]);
		printf("Dose apodoxes ypallilou %d\n",i);
		scanf("%lf",&salary[i]);
	}
	
	/** proto erotima **/
	for(i=0;i<MAXN;i++)
	{
		if(salary[i]>=2000)
		{
			printf("%s %s \n",name[i],lastname[i]);
		}
	}
	
	/** deytero erotima **/
	maxSalary= salary[0];
	maxIndex=0;
	for(i=0;i<MAXN;i++)
	{
		if(salary[i]>maxSalary)
		{
			maxIndex=i;
			maxSalary=salary[i];
		}
	}
	printf("O ypallilos me tis perisoteres apodoxes %s %s \n",name[maxIndex],lastname[maxIndex]);
	
	/** trito erotima **/
	for(i=0;i<MAXN;i++)
	{
		for(j=0;j<MAXN-1;j++)
		{
			if(salary[j+1]<salary[j])
			{
				char tempName[100];
				char tempLastname[100];
				double t=salary[j];
				salary[j]=salary[j+1];
				salary[j+1]=t;
				
				strcpy(tempName,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],tempName);
				
				strcpy(tempLastname,lastname[j]);
				strcpy(lastname[j],lastname[j+1]);
				strcpy(lastname[j+1],tempLastname);
			}
		}
	}
	for(i=0;i<MAXN;i++)
	{
		printf("%s : %s : %lf \n",name[i],lastname[i],salary[i]);
	}
	return 0;
}
	
	
