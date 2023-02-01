#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void chuanHoa(char *s) {
	int l = strlen(s);
	if (s[l-1] == '\n') {
		s[l-1] = '\0';
	}
}

void lower(char *s) {
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
}

int main() {
	typedef struct word {
		char tu[50];
		char nghia[50];
	} word;

	struct word tuDien[1000];

	int n = 0;
	FILE *f;
	f = fopen("TuDienAnhViet.txt","r");

	if (f == NULL) {
		printf("Doc file that bai");
	} else {
		int i = 0;
		while (!feof(f)) {
			n++;
			fgets(tuDien[i].tu, 50, f);
			fgets(tuDien[i].nghia,50,f);
			i++;

		}
		for (int i = 0; i < n; i++) {
			chuanHoa(tuDien[i].tu);
			lower(tuDien[i].tu);
			chuanHoa(tuDien[i].nghia);
			lower(tuDien[i].nghia);
		}

	}

	printf("=================CHAO MUNG BAN DEN VOI TU DIEN ANH - VIET===================\n");


	int luachon;
	do {
		printf("\n\n============================================================================\n");
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
				chuanHoa(s);
				lower(s);
				int check = 0;

				for (int i = 0; i < n; i++) {
					if (strcmp(s, tuDien[i].tu) == 0) {
						printf("\nNghia la: %s", tuDien[i].nghia);
						check = 1;
						break;
					}
				}
				if (check == 0) printf("Khong tim thay tu!!!\a");
				break;
			}

			// them tu (them vao cuoi)
			case 2: {
				char newWord[50];
				char mean[50];

				printf("Nhap tu can them: ");
				getchar();
				scanf("%[^\n]s", &newWord);
				chuanHoa(newWord);
				lower(newWord);
				printf("Nghia cua tu: ");
				getchar();
				scanf("%[^\n]s", &mean);
				chuanHoa(mean);
				lower(mean);

				strcpy(tuDien[n].tu, newWord);
				strcpy(tuDien[n].nghia, mean);
				FILE *f;
				f = fopen("TuDienAnhViet.txt", "w");
				n++;
				for  (int i = 0; i < n-1; i++) {
					fputs(tuDien[i].tu, f);
					fputs("\n", f);
					fputs(tuDien[i].nghia, f);
					fputs("\n", f);
				}
				fputs(tuDien[n-1].tu, f);
				fputs("\n",f);
				fputs(tuDien[n-1].nghia,f);
				fclose(f);
				
				break;
			}

			// sua tu
			case 3: {
				char s[50];
				printf("Nhap tu can sua: ");
				getchar();
				scanf("%[^\n]s", &s);
				chuanHoa(s);
				lower(s);
				FILE *f;
				f = fopen("TuDienAnhViet.txt", "w+");
				for (int i = 0; i < n; i++) {
					// sua tu tieng anh
					if (strcmp(s, tuDien[i].tu) == 0) {
						printf("Tu ban dau la: %s\nNghia la: %s\n", tuDien[i].tu, tuDien[i].nghia);
						printf("Nhap tu thay the: ");
						char s2[50];
						getchar();
						scanf("%[^\n]s", &s2);
						chuanHoa(s2);
						strcpy(tuDien[i].tu, s2);
						for  (int i = 0; i < n-1; i++) {
							fputs(tuDien[i].tu, f);
							fputs("\n", f);
							fputs(tuDien[i].nghia, f);
							fputs("\n", f);
						}
						fputs(tuDien[n-1].tu, f);
						fputs("\n",f);
						fputs(tuDien[n-1].nghia,f);
					}
					// sua nghia
					if (strcmp(s, tuDien[i].nghia) == 0) {
						printf("Tu ban dau la: %s\nNghia la: %s\n", tuDien[i].tu, tuDien[i].nghia);
						printf("Nhap tu thay the: ");
						char s2[50];
						getchar();
						scanf("%[^\n]s", &s2);
						chuanHoa(s2);
						strcpy(tuDien[i].nghia, s2);
						for  (int i = 0; i < n-1; i++) {
							fputs(tuDien[i].tu, f);
							fputs("\n", f);
							fputs(tuDien[i].nghia, f);
							fputs("\n", f);
						}
						fputs(tuDien[n-1].tu, f);
						fputs("\n",f);
						fputs(tuDien[n-1].nghia,f);
					}

				}
				fclose(f);
				
				break;
			}

			// xoa tu
			case 4: {
				char s[50];
				int index = -1;
				printf("Nhap tu can xoa: ");
				getchar();
				scanf("%[^\n]s", &s);
				chuanHoa(s);
				lower(s);
				for (int i = 0; i < n; i++) {
					if (strcmp(s,tuDien[i].tu) == 0) {
						index = i;
						break;
					}
					if (strcmp(s,tuDien[i].nghia) == 0) {
						index = i;
						break;
					}
				}
				FILE *f;
				f = fopen("TuDienAnhViet.txt", "w");
				if (index != -1) {
					n--;
					for (int i = index; i < n; i++) {
						strcpy(tuDien[i].tu, tuDien[i+1].tu);
						strcpy(tuDien[i].nghia, tuDien[i+1].nghia);
					}
					for  (int i = 0; i < n-1; i++) {
						fputs(tuDien[i].tu, f);
						fputs("\n", f);
						fputs(tuDien[i].nghia, f);
						fputs("\n", f);
					}
					fputs(tuDien[n-1].tu, f);
					fputs("\n",f);
					fputs(tuDien[n-1].nghia,f);
				} else {
					printf("Khong thay tu de xoa!!!\a");
				}
				fclose(f);
				
				break;

			}
			default : {
				printf("Nhap dung lua chon!!!");
				break;
			}
		}
	} while (luachon != 0);
	return 0;


	return 0;
}

