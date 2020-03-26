#include "LAB_5_func.h"

void TextIntoMass(char*** mass, FILE** Text, int* rowsCount) {
	char symbol;
	symbol = fgetc(*Text);
	int rows = 2;
	while (!feof(*Text)) {
		if (symbol == '\n') {
			rows += 1;
		}
		symbol = fgetc(*Text);
	}
	//printf("rows = %d\n", rows);
	*rowsCount = rows;
	fseek(*Text, 0, SEEK_SET);
	(*mass) = (char**)malloc(rows * sizeof(char*));
	for (int i = 0; i < rows; i++) {
		int count = 0;
		symbol = fgetc(*Text);
		while (symbol != '\n' && !feof(*Text)) {
			count += 1;
			symbol = fgetc(*Text);
		}
		if (symbol == '\n') {
			fseek(*Text, -(count + 2), SEEK_CUR);
		}
		else {
			fseek(*Text, -(count), SEEK_CUR);
		}
		(*mass)[i] = (char*)malloc((count + 2) * sizeof(char));
		fgets((*mass)[i], count + 1, *Text);
		fgetc(*Text);
		(*mass)[i][count + 1] = 0;
	}
}

void Ordering(char*** mass, int* n) {
	for (int i = 0; i < *n - 1; i++) {
		for (int j = 0; j < *n - i - 1; j++) {
			if (length((*mass)[j]) > length((*mass)[j + 1])) {
				char* str;
				/*StrCopy(&str, &(*mass)[j]);
				StrCopy(&(*mass)[j], &(*mass)[j + 1]);
				StrCopy(&(*mass)[j + 1], &str);*/
				str = (*mass)[j];
				(*mass)[j] = (*mass)[j + 1];
				(*mass)[j + 1] = str;
			}
		}
	}

}

void FreeMass(char*** mass, int n) {
	for (int i = 0; i < n; i++) {
		free((*mass)[i]);
	}
	free((*mass));
}