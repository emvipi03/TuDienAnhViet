#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

typedef struct word {
	char tu[50];
	char nghia[50];
} word;

// ham chuanhoa va ham lower de dinh dang tu ghi vao file va xuat ra file.
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

struct word tuDien[1000];
int n; // so tu

void docDuLieu() {
	n = 0;
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
	fclose(f);

}


int main() {
	printf("=================CHAO MUNG BAN DEN VOI TU DIEN ANH - VIET===================\n");

	docDuLieu();

	int luachon;
	do {
		printf("\n\n============================================================================\n");
		printf("1. Tra tu (full keyword)\n");
		printf("2. Them tu\n");
		printf("3. Sua tu\n");
		printf("4. Xoa tu\n");
		printf("5. Tra tu (tung ki tu)\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon: ");
		scanf("%d", &luachon);
		switch(luachon) {

				// tra tu (full key)
			case 1: {
				printf("\n=====THUC HIEN TRA TU=====\n");
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
				printf("\n=====THUC HIEN THEM TU=====\n");
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
				if (f == NULL) {
					printf("Doc file that bai");
				} else {
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
					docDuLieu();
					printf("DA THEM TU!!!");
				}
				break;
			}

			// sua tu
			case 3: {
				printf("\n=====THUC HIEN SUA TU=====\n");
				int check = 0;
				char s[50];
				printf("Nhap tu can sua: ");
				getchar();
				scanf("%[^\n]s", &s);
				chuanHoa(s);
				lower(s);
				for (int i = 0; i < n; i++) {
					// sua tu tieng anh
					if (strcmp(s, tuDien[i].tu) == 0) {
						printf("Lua chon thay doi phan TU TIENG ANH\n");
						printf("Tu ban dau la: %s\nNghia la: %s\n", tuDien[i].tu, tuDien[i].nghia);
						printf("Nhap tu thay the: ");
						char s2[50];
						getchar();
						scanf("%[^\n]s", &s2);
						chuanHoa(s2);
						strcpy(tuDien[i].tu, s2);
						FILE *f;
						f = fopen("TuDienAnhViet.txt", "w");
						if (f == NULL) {
							printf("Doc file that bai");
						} else {
							for  (int j = 0; j < n-1; j++) {
								fputs(tuDien[j].tu, f);
								fputs("\n", f);
								fputs(tuDien[j].nghia, f);
								fputs("\n", f);
							}
							fputs(tuDien[n-1].tu, f);
							fputs("\n",f);
							fputs(tuDien[n-1].nghia,f);
							fclose(f);
							docDuLieu();
							check ++;
							printf("DA SUA TU!!!");
						}
					} else {
						// sua nghia
						if (strcmp(s, tuDien[i].nghia) == 0) {
							printf("Lua chon thay doi phan NGHIA\n");
							printf("Tu ban dau la: %s\nNghia la: %s\n", tuDien[i].tu, tuDien[i].nghia);
							printf("Nhap tu thay the: ");
							char s2[50];
							getchar();
							scanf("%[^\n]s", &s2);
							chuanHoa(s2);
							strcpy(tuDien[i].nghia, s2);
							FILE *f;
							f = fopen("TuDienAnhViet.txt", "w");
							if (f == NULL) {
								printf("Doc file that bai");
							} else {
								for  (int j = 0; j < n-1; j++) {
									fputs(tuDien[j].tu, f);
									fputs("\n", f);
									fputs(tuDien[j].nghia, f);
									fputs("\n", f);
								}
								fputs(tuDien[n-1].tu, f);
								fputs("\n",f);
								fputs(tuDien[n-1].nghia,f);
								fclose(f);
								docDuLieu();
								check ++;
								printf("DA SUA TU!!!");
							}
						}
					}
				}
				if (check == 0) printf("KHONG TIM THAY TU DE SUA!!!\a");
				break;
			}

			// xoa tu
			case 4: {
				printf("=====THUC HIEN XOA TU=====\n");
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
				if (index != -1) {
					n--;
					for (int i = index; i < n; i++) {
						strcpy(tuDien[i].tu, tuDien[i+1].tu);
						strcpy(tuDien[i].nghia, tuDien[i+1].nghia);
					}
					FILE *f;
					f = fopen("TuDienAnhViet.txt", "w");
					if (f == NULL) {
						printf("Doc file that bai");
					} else {
						for  (int i = 0; i < n-1; i++) {
							fputs(tuDien[i].tu, f);
							fputs("\n", f);
							fputs(tuDien[i].nghia, f);
							fputs("\n", f);
						}
						fputs(tuDien[n-1].tu, f);
						fputs("\n",f);
						fputs(tuDien[n-1].nghia,f);
						printf("DA XOA TU!!!");
						fclose(f);
						docDuLieu();
					}
				} else {
					printf("Khong thay tu de xoa!!!\a");
				}
				break;
			}
			case 5: {
				printf("\n=====THUC HIEN TRA TU TUNG KI TU=====\n");
				printf("Nhap ki tu: ");
				char s[50];
				getchar();
				scanf("%[^\n]s", &s);
				chuanHoa(s);
				lower(s);
				int check = 0;
				
				char *a;
				for (int i = 0; i < n; i++) {
					a = strstr(tuDien[i].tu,s);
					if(a != NULL) {
						printf("Tu: %s\tNghia: %s\n\n", tuDien[i].tu,tuDien[i].nghia);
						check = 1;
					}
				}
				if (check == 0) printf("Khong thay tu");
				break;
			}
			default : {
				printf("Nhap dung lua chon!!!\a");
				break;
			}
		}
	} while (luachon != 0);
	return 0;
}

