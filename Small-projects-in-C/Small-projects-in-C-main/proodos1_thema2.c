/* Να γραφεί συνάρτηση void copyDigits(char source[],char dest[]). Η συνάρτηση αυτή αντιγράφει μόνον τα αριθμητικά σύμβολα που περιέχονται στο αλφαριθμητικό source στο αλφαριθμητικό dest. 
Προσοχή στην σωστή τοποθέτηση του συμβόλου ‘\0’ στο αλφαριθμητικό dest.  Να δείξετε μια χρήση της παραπάνω συνάρτησης μέσα από την main() συνάρτηση. */

# include <stdio.h>
# include <string.h>
# include <ctype.h>

void copyDigits(char source[],char dest[])
{
	int count=0;
	int i;
	for(i=0;i<strlen(source);i++)
	{
		if(isdigit(source[i])) 
		{
			dest[count]=source[i];
			count++;
		}
	}
	dest[count]='\0';
}

int main()
{
	char x[100]="Thisis111Test23a";
	char dest[100];
	copyDigits(x,dest);
	printf("Dest %s \n",dest);
	return 0;
}
