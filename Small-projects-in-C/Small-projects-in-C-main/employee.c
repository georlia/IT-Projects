/*Για τους 8 υπαλλήλους μιας επιχείρησης δίνονται τα εξής στοιχεία: κωδικός (ακέραιος 100-999), ηλικία και μηνιαίες αποδοχές κάθε υπαλλήλου. Να γραφεί πρόγραμμα το οποίο θα διαβάζει
τα στοιχεία των υπαλλήλων και θα τα αποθηκεύει σε κατάλληλους πίνακες, και στην συνέχεια θα υπολογίζει και θα εμφανίζει:
Τον κωδικό και την ηλικία των υπαλλήλων που έχουν μηνιαίες αποδοχές μεγαλύτερες από το μέσο όρο αποδοχών όλων των υπαλλήλων, καθώς και πόσοι είναι αυτοί οι υπάλληλοι.
Τον κωδικό και τις μηνιαίες αποδοχές των υπαλλήλων με ηλικία μικρότερη από 35 έτη και πόσοι είναι αυτοί οι υπάλληλοι.
Επιπλέον να εμφανίζει την λίστα των υπαλλήλων (κωδικό, ηλικία, μηνιαίες αποδοχές) ταξινομημένη με βάση τον κωδικό.*/

# include <stdio.h>
# define MAXN 8

int readCode()
{
		int code;
		do
		{
			printf("Dose kodiko \n");
			scanf("%d",&code);
		}while(code<100 || code>999);
		return code;
}

int readAge()
{
	int age;
	do
	{
		printf("Dose ilikia \n");
		scanf("%d",&age);
	}while(age<=18);
	return age;
}

double readSalary()
{
	double salary;
	do
	{
		printf("Dose mistho \n");
		scanf("%lf",&salary);
	}while(salary<=0.0);
	return salary;
}
/** ypologizei ton meso oro enos dekadikou pinaka n stoixeion **/
double averageArray(double x[],int n)
{
	double sum = 0.0;
	int i;
	for(i=0;i<n;i++) sum=sum+x[i];
	sum=sum/n;
	return sum;
}


int main()
{
	int code[MAXN];
	int age[MAXN];
	double salary[MAXN];
	int i,j;
	double avg;
	int count1=0,count2=0;
	for(i=0;i<MAXN;i++)
	{
		printf("Ypallilos %d \n",i);
		code[i]=readCode();
		age[i]=readAge();
		salary[i]=readSalary();
	}
	
	/** Proto erotima **/
	count1=0;
	avg=averageArray(salary,MAXN);
	for(i=0;i<MAXN;i++)
	{
		if(salary[i]>=avg)
		{
			printf("Ypallilos me polles apodoxes %d kai me ilikia %d \n",code[i],age[i]);
			count1++;
		}
	}
	printf("Ypalliloi me polles apodoxes %d \n",count1);
	
	/** Deytero erotima **/
	count2=0;
	for(i=0;i<MAXN;i++)
	{
		if(age[i]<=35)
		{
			printf("Neos ypallilos o %d me apodoxes %lf \n",code[i],salary[i]);
			count2++;
		}
	}
	printf("Oi neoi ypalliloi einai %d \n",count2);

	for(i=0;i<MAXN;i++)
	{
		for(j=0;j<MAXN-1;j++)
		{
			if(code[j+1]<code[j])
			{
				int tempage;
				double tempsalary;
				
				int tempcode=code[j];
				code[j]=code[j+1];
				code[j+1]=tempcode;
				
				tempage=age[j];
				age[j]=age[j+1];
				age[j+1]=tempage;
				
				tempsalary=salary[j];
				salary[j]=salary[j+1];
				salary[j+1]=tempsalary;
			}
		}
	}	
	for(i=0;i<MAXN;i++)
	{
		printf("Code: %4d Age: %4d Salary: %8.2lf \n",code[i],age[i],salary[i]);
	}
	return 0;
}
