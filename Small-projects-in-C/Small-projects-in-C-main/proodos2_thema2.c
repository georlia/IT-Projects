/*Να γραφεί συνάρτηση void concatCapitals(char a[],char b[],char dest[]). Η συνάρτηση αυτή δέχεται ως είσοδο δύο αλφαριθμητικά a και b και αντιγράφει τα κεφαλαία γράμματα που περιέχουν στο αλφαριθμητικό dest. 
Τα κεφαλαία γράμματα από το a θα μπουν πρώτα και στην συνέχεια τα κεφαλαία γράμματα από το b. Προσοχή στην σωστή τοποθέτηση του συμβόλου ‘\0’ στο αλφαριθμητικό dest.  
Να δείξετε μια χρήση της παραπάνω συνάρτησης μέσα από την main() συνάρτηση.*/

# include <stdio.h>
# include <string.h>
# include <ctype.h>

void concatCapitals(char a[],char b[],char dest[])
{
	int count=0;
	int i;
	for(i=0;i<strlen(a);i++)
	{
		if(isupper(a[i])) 
		{
			dest[count]=a[i];
			count++;
		}
	}
	for(i=0;i<strlen(b);i++)
	{
		if(isupper(b[i]))
		{
			dest[count]=b[i];
			count++;
		}
	}
	dest[count]='\0';
}

int main()
{
	char x1[100]="This1222IsATest";
	char x2[100]="abbbXXXyyyZ";
	char dest[200];
	concatCapitals(x1,x2,dest);
	printf("Dest: %s\n",dest);
	return 0;
}
