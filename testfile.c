#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main() {
	FILE *f;
	f = fopen("Testfile.txt", "r");
	if (f == NULL) {
		printf("Loi tao file");
		return 0; 
	} 
	int n;
	fscanf(f, "%d", &n);
	printf("so n: %d", n); 
	fclose(f); 
    return 0;
}

