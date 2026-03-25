/** 
Να γραφεί ένα πρόγραμμα που να ζητάει ένα αλφαριθμητικό από τον χρήστη (μέχρι 50 χαρακτήρων) και στην συνέχεια να υπολογίζει και να εμφανίζει:
Α) Τον αριθμό των κενών.
Β) Τον αριθμό των κεφαλαίων γράμματών.
Γ) Τον αριθμό των πεζών γράμματών.
Δ) Το αριθμό των ψηφίων (0-9).
**/
# include <stdio.h>
# include <string.h>

int main()
{
	char protasi[51];
	int count1=0,count2=0,count3=0,count4=0;
	int i;
	printf("Dose protasi \n");
	gets(protasi);
	for(i=0;i<strlen(protasi);i++)
	{
		if(protasi[i]==' ') count1++;
		if(protasi[i]>='A' && protasi[i]<='Z') count2++;
		if(protasi[i]>='a' && protasi[i]<='z') count3++;
		if(protasi[i]>='0' && protasi[i]<='9') count4++;
	}
	printf("%d %d %d %d \n",count1,count2,count3,count4);
	return 0;
}
