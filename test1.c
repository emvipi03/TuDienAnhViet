#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

struct word {
	char tu[50];
	char nghia[50];
};
 
int main() {
	printf("=================CHAO MUNG BAN DEN VOI TU DIEN ANH - VIET===================\n"); 
	int n;
	printf("Nhap so tu: "); 
	scanf("%d", &n);
	struct word p[500];
	for (int i = 0; i < n; i++) {
		printf("Nhap tu thu %d\n", i+1);
		//	fgets(p[i].tu, sizeof(p[i].tu)+1, stdin);
		//	fgets(p[i].nghia, sizeof(p[i].nghia)+1, stdin);
		getchar();
		printf("+Tu: "); 
		scanf("%[^\n]s", &p[i].tu);
		getchar();
		printf("+Nghia cua tu: "); 
		scanf("%[^\n]s", &p[i].nghia);
	}
	int luachon;
	do {
		printf("\n\n"); 
		printf("1. Tra tu (full keyword)\n");
		printf("2. Them tu\n");
		printf("3. Sua tu\n");
		printf("4. Xoa tu\n"); 
		printf("0. Thoat\n");
		printf("Nhap lua chon: "); 
		scanf("%d", &luachon);
		switch(luachon) {
			
			// tra tu (full key) 
			case 1: {
				printf("Nhap tu can tra: ");
				char s[50];
				getchar();
				scanf("%[^\n]s", &s); 
				int check = 0; 
				
				for (int i = 0; i < n; i++) {
					if (strcmp(s, p[i].tu) == 0) {
						printf("\nNghia la: %s", p[i].nghia);
						check = 1;
						break; 
					}
				}
				if (check == 0) printf("Khong tim thay tu!!!"); 
				break;
			}
			
			// them tu (them vao cuoi) 
			case 2: {
				char newWord[50];
				char mean[50];
				
				printf("Nhap tu can them: ");
				getchar();
				scanf("%[^\n]s", &newWord);
				
				printf("Nghia cua tu: ");
				getchar();
				scanf("%[^\n]s", &mean);
				
				strcpy(p[n].tu, newWord);
				strcpy(p[n].nghia, mean);
				n++;
				break;
			}
			
			// sua tu  
			case 3: {
				char s[50]; 
				printf("Nhap tu can sua: ");
				getchar();
				scanf("%[^\n]s", &s);
				
				for (int i = 0; i < n; i++) {
					// sua tu tieng anh 
					if (strcmp(s, p[i].tu) == 0) {
						printf("Tu ban dau la: %s\nNghia la: %s\n", p[i].tu, p[i].nghia); 
						printf("Nhap tu thay the: ");
						char s2[50];
						getchar();
						scanf("%[^\n]s", &s2);
						strcpy(p[i].tu, s2); 
					} 
					// sua nghia 
					if (strcmp(s, p[i].nghia) == 0) {
						printf("Tu ban dau la: %s\nNghia la: %s\n", p[i].tu, p[i].nghia); 
						printf("Nhap tu thay the: ");
						char s2[50];
						getchar();
						scanf("%[^\n]s", &s2);
						strcpy(p[i].nghia, s2); 
					} 
					
				} 
				break;
			} 
			
			// xoa tu
			case 4: {
				char s[50];
				int index = 0; 
				printf("Nhap tu can xoa: ");
				getchar();
				scanf("%[^\n]s", &s);
				for (int i = 0; i < n; i++) {
					if (strcmp(s,p[i].tu) == 0) {
						index = i;
						break; 
					} 
					if (strcmp(s,p[i].nghia) == 0) {
						index = i; 
						break; 
					} 
				} 
				n--; 
				for (int i = index; i < n; i++) {
					strcpy(p[i].tu, p[i+1].tu);
					strcpy(p[i].nghia, p[i+1].nghia); 
				} 
				break;
			} 
		}
	} while (luachon != 0);
	return 0;
}

