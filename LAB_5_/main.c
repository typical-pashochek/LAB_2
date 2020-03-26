#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include "String.h"
#include "LAB_5_func.h"


int main(int argc, char* argv[]) {
	//SetConsoleCP(1251);                
	//SetConsoleOutputCP(1251); 
	setlocale(LC_ALL, "rus");
	FILE* filenames;
	fopen_s(&filenames, "filenames.txt", "r");
	char* fileName;
	if (argc == 2) {
		fileName = argv[1];
		puts(argv[1]);
	}
	else if (filenames != NULL) {
		int len = 0;
		while (!feof(filenames)) {
			len += 1;
			fgetc(filenames);
		}
		fseek(filenames, 0, SEEK_SET);
		fileName = (char*)malloc((len + 1) * sizeof(char));
		fgets(fileName, len, filenames);
		puts(fileName);
		fclose(filenames);

	}
	else {
		//printf("Defolt\n");
		fileName = "book.txt";
		puts(fileName);
	}
	
	FILE* text;
	fopen_s(&text, fileName, "r");
	if (text == NULL) {
		printf("File doesn't exist.\n");
		system("pause");
		exit(1);
	}
	char** textMass;
	int rowsCount = 0;
	TextIntoMass(&(textMass), &text, &rowsCount);
	Ordering(&(textMass), &rowsCount);
	for (int i = 0; i < rowsCount; i++) {
		printf("%s", textMass[i]);
	}
	FreeMass(&textMass, rowsCount);
	system("pause");
	return 0;
}