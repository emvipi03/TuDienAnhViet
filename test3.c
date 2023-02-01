#include <stdio.h>
#include <string.h>

void chuanHoa(char *s) {
int l = strlen(s);
if (s[l-1] == '\n') {
s[l-1] = '\0';
}
}

int main () {
    FILE *evdict;

		printf("=================CHAO MUNG BAN DEN VOI TU DIEN ANH - VIET===================\n");
		printf("\n\n============================================================================\n");
		
	int choice;
	do {
		printf("1. Look up\n");
		printf("2. New word\n");
		printf("3. Edit\n");
		printf("4. Remove\n"); 
		printf("0. Save and Exit\n");
		printf("Your choice: "); 
		scanf("%d", &choice);
		fflush(stdin);

		switch(choice) {
			
			// look up (full key) 
			case 1: {
			    evdict = fopen("D:\\Hai Anh\\Code\\EVdict.txt","r");
			    if (evdict == NULL) {
			    	printf("FILE NOT FOUND!\n");
			    	return 0;
				}

				char find[50], eng[49], vie[99];
				printf("Search for: ");\
				scanf("%s",&find);
				//fgets(find, 50, stdin);
				//chuanHoa(find);
				long check = 0;
				while (fscanf (evdict,"%s%s", &eng, &vie) != EOF) {
					if (strstr(find,eng) != NULL) {
						printf ("%s\n",vie );
						check++;
					}
				} 
				if (check == 0) printf("Word not found.\n");
				break;
			}
			
			case 2: {
				char eng[49], vie[99];
	
			// New word (them vao cuoi) 
			    evdict = fopen("D:\\Hai Anh\\Code\\EVdict.txt","a");
			    if (evdict == NULL) {
			    	printf("FILE NOT FOUND!\n");
			    	return 0;
				}
				printf("Enter word:");
				fflush(stdin);
				gets(eng);
				int length_before = strlen(eng);
				for (int i = length_before ; i < 51 ; i++) eng[i] = ' ';
				
				printf("Enter meanings:");
				fflush(stdin);
				gets(vie);
				length_before = strlen(vie);
				for (int i = length_before ; i < 99; i++) vie[i] = ' ';
				vie[99] = '\n';
				fprintf(evdict,"%s%s", eng, vie );   	
				break;
			}
			
			// Edit  
			case 3: {
				char find[50],eng[50], neweng[49], vie[100], newvie[99];
				int count = 0, check = 0;
				
				evdict = fopen("D:\\Hai Anh\\Code\\EVdict.txt","r+");
				if (evdict == NULL) {
					printf("FILE NOT FOUND!\n");
					return 0;
				}
				printf("Search for: ");
				scanf("%s", &find);
				while (fscanf (evdict,"%s%s", &eng, &vie) != EOF) {
					

					if (strstr(find,eng) != NULL) {
						
						printf("Enter new word:");
						fflush(stdin); 
						gets(neweng);
						int length_before = strlen(neweng);
						for (int i = length_before ; i < 51 ; i++) neweng[i] = ' ';
							
						printf("Enter new meanings:");
						fflush(stdin);
						gets(newvie);
						length_before = strlen(newvie);
						for (int i = length_before ; i < 99; i++) newvie[i] = ' ';
						vie[99] = '\n';

						fseek( evdict , count*151 , SEEK_SET);				
						fprintf(evdict,"%s%s", neweng, newvie );	
						printf("Edit success.\n");
						
						check++;
						break;
					}
					count++;

				} 
				if (check == 0) printf("Checked %d but not found.\n", count);
				
				break;
			} 
			
			// Remove
			case 4: {
				char find[50],eng[50], vie[100];
				int count = 0, check = 0;
				
				evdict = fopen("D:\\Hai Anh\\Code\\EVdict.txt","r+");
				if (evdict == NULL) {
					printf("FILE NOT FOUND!\n");
					return 0;
				}
				printf("Find word to remove: ");
				scanf("%s", &find);
				while (fscanf (evdict,"%s%s", &eng, &vie) != EOF) {
					
					if (strstr(find,eng) != NULL) {

						char space[155];
						for (int i = 0; i < 151; i++) space[i] = ' ';
						fseek( evdict , count*151 + 1 , SEEK_SET);				
						fprintf(evdict,"%s", space);	
						printf("Remove success.\n");
						
						check++;
						break;
					}
					count++;
				} 
				if (check == 0) printf("Word not found.\n");
				break;
			} 
			case 0: return 0;
			default : printf( "ERROR." );
		}
	} while (choice != 0);
	
	
	fclose(evdict);

    return 0;
}
