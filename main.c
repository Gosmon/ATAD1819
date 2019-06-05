/* PROJETO  ATAD 2018-19
* Identificacao dos Alunos:
*
*      Numero: 160221039 | Nome: Hugo Ferreira
*      Numero: 180221022 | Nome: Carlos Emanuel Martins
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "list.h"
#include "map.h"

typedef char String[256];

/* definicao de prototipos de funcoes, definidas depois do main() */
int equalsStringIgnoreCase(char str1[], char str2[]);
void printCommandsMenu();
char** split(char* string, int nFields, const* delim);
void load(PtList list, PtMap map);
void clear(PtList list, PtMap map);
void show();
void quit();
void sort();
void avg();
PtList averageClinicalData(PtList patients);
void norm();
PtList normalizeClinicalData(PtList patients);
void queue();
void checkDistrict();
void loadT();
void normT();
int calculateAge(Date clinicalDate, Date birthdate);

/*
* Descrição do Programa
*/
int main(int argc, char** argv) {

	/* declaracao de variaveis */
	PtList list = listCreate(0);
	PtMap map = mapCreate(0);

	/* interpretador de comandos */
	String command;
	int quit = 0;

	setlocale(LC_ALL, "PT");
	while (!quit) {
		
		printCommandsMenu();
		fgets(command, sizeof(command), stdin);
		/* descartar 'newline'. Utilizar esta técnica sempre que for lida uma
		* string para ser utilizada, e.g., nome de ficheiro, chave, etc.. */
		command[strlen(command) - 1] = '\0';

		if (equalsStringIgnoreCase(command, "QUIT")) {
			quit = 1; /* vai provocar a saída do interpretador */				
		}
		else if (equalsStringIgnoreCase(command, "LOAD")) {
			/* invocação da função responsável pela respetiva
			funcionalidade. Remover printf seguinte após implementação */
			load(list, map);
		}
		else if (equalsStringIgnoreCase(command, "CLEAR")) {
			printf("Comando CLEAR nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "SHOW")) {
			printf("Comando SHOW nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "SORT")) {
			printf("Comando SORT nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "AVG")) {
			printf("Comando AVG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "NORM")) {
			printf("Comando NORM nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "QUEUE")) {
			printf("Comando QUEUE nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "CHECKDISTRICT")) {
			printf("Comando CHECKDISTRICT nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "LOADT")) {
			printf("Comando MFOULG nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "NORMT")) {
			printf("Comando NORMT nao implementado.\n");
		}
		else if (equalsStringIgnoreCase(command, "NEURALNET")) {
			printf("Comando NEURALNET nao implementado.\n");
		}
		else {
			printf("Comando não encontrado.\n");
		}
	}

	/* libertar memória e apresentar mensagem de saída. */

	return (EXIT_SUCCESS);
}

int equalsStringIgnoreCase(char str1[], char str2[]) {
	/* Apenas faz uma comparacao utilizando o strcmp.
	* Necessita de modificacao para obter uma comparacao
	* 'case insensitive' */
	return (strcmp(str1, str2) == 0);
}

void printCommandsMenu() {
	printf("\n===================================================================================");
	printf("\n                          PROJECT: Patients and Clinical Data                      ");
	printf("\n===================================================================================");
	printf("\nA. Info about players (LOAD, SHOW, CLEAR).");
	printf("\nB. Aggregated info about patients and clinical data (SORT, AVG, NORM, QUEUE, CHECKDISTRICT).");
	printf("\nC. Advanced indicator (LOADT, NORMT, NEURALNET)");
	printf("\nD. Exit (QUIT)\n\n");
	printf("COMMAND> ");
}


char** split(char* string, int nFields, const* delim) {
	char** tokens = malloc(sizeof(char*) * nFields);

	int index = 0;
	char* next_token = NULL;

	char* token = (char*)strtok_s(string, delim, &next_token);

	while (token) {
		tokens[index++] = token;
		token = strtok_s(NULL, delim, &next_token);
	}
	return tokens;
}

void load(PtList list, PtMap map) {

	String filename[20];
	String filename2[20];

	printf("Insira o nome do ficheiro com os dados dos pacientes: ");
	scanf_s("%s", &filename, sizeof(filename));

	printf("Insira o nome do ficheiro com os dados clinicos dos pacientes: ");
	scanf_s("%s", &filename2, sizeof(filename2));

	FILE* f;
	FILE* f2;

	int error = fopen_s(&f, filename, "r"); //open the file in read mode

	if (error) {
		printf("An error occurred... It was not possible to open the file %s ...\n", filename);
		return;
	}

	int error2 = fopen_s(&f2, filename2, "r");

	if (error2) {
		printf("An error occurred... It was not possible to open the file %s ...\n", filename2);
		return;
	}


	char nextLine[1024];
	int countPatients = 0;//patients count
	int countClinicalDatas = 0; //clinicalDatas count
	PtPatient patients = (PtPatient)malloc(sizeof(Patient));
	PtClinicalData clinicalDatas = (PtClinicalData)malloc(sizeof(ClinicalData));

	while (fgets(nextLine, sizeof(nextLine), f)) {
		if (strlen(nextLine) < 1)
			continue;
		char** tokens = split(nextLine, 5, ";");
		char** tokens2 = split(tokens[1], 3, "/");
		int id = tokens[0];

		PtDate birthdate = dateCreate(atoi(tokens2[0]), atoi(tokens2[1]), atoi(tokens2[2]));
		PtPatient patient = createPatient(id, *birthdate, tokens[2], tokens[3], tokens[4]);
		countPatients++;

		char nextLine2[1024];

		while (fgets(nextLine2, sizeof(nextLine2), f2)) {
			if (strlen(nextLine2))
				continue;
			char** tokens = split(nextLine2, 6, ";");
			char** tokens2 = split(tokens[1], 3, "/");

			PtClinicalData clinicalData = (PtClinicalData)malloc(sizeof(ClinicalData));

			if (tokens[0] == patient->id) {
				PtDate clinicalDate = dateCreate(atoi(tokens2[0]), atoi(tokens2[1]), atoi(tokens2[2]));
				
				if (&patient->clinicalData == NULL) { //se nao existir uma clinical data com aquele id ele cria uma nova 
					clinicalData = createClinicalData(calculateAge(*birthdate, *clinicalDate), atof(tokens[2]), atof(tokens[3]), atof(tokens[4]), atof(tokens[5]));
					addClinicalData(*patient, *clinicalData);
					countClinicalDatas++;
				}
				else { //se ja existir altera o existente
					clinicalData = changeClinicalData(&patient->clinicalData, calculateAge(*birthdate, *clinicalDate), atof(tokens[2]), atof(tokens[3]), atof(tokens[4]), atof(tokens[5]));
					countClinicalDatas++;
				}

			}

			clinicalDatas[countClinicalDatas++] = *clinicalData;
			clinicalDatas = (PtClinicalData)realloc(clinicalDatas, (countClinicalDatas + 1) * sizeof(ClinicalData));

			free(tokens);
			free(tokens2);

		}

		patients[countPatients++] = *patient;
		patients = (Patient*)realloc(patients, (countPatients + 1) * sizeof(Patient));

		free(tokens);
		free(tokens2);//release of the memory alocated in function split

	}

	for (int i = 0; i < countPatients; i++) {
		printPatient(&patients[i]);
	}

	for (int i = 0; i < countClinicalDatas; i++) {
		printClinicalData(&clinicalDatas[i]);
	}

	printf("n\n\%d patients were read from %s file and %d clinical datas were read from the %s file!\n", countPatients, filename, countClinicalDatas, filename2);
	fclose(f);
}

void clear(PtList list, PtMap map) {
	if (listIsEmpty(list) == 1 || mapIsEmpty(map) == 1) {
		printf("NAO EXISTEM CACHES PARA LIMPAR!");
		return;
	}


	listClear(list);
	mapClear(map);
	printf("CACHES IMPORTADAS LIMPAS");
}

void show() {
	
}

void quit() {

}

void sort() {

}

void avg() {

}

PtList averageClinicalData(PtList patients) {

}

void norm() {

}

PtList normalizeClinicalData(PtList patients) {

}

void queue() {

}

void checkDistrict() {

}

void loadT() {

}

void normT() {

}

int calculateAge(Date clinicalDate, Date birthdate) {
	int age;

	if (birthdate.day > clinicalDate.day)
	{
		clinicalDate.month = clinicalDate.month - 1;
		clinicalDate.day = clinicalDate.day + 30;
	}
	if (birthdate.month > clinicalDate.month)
	{
		clinicalDate.year = clinicalDate.year - 1;
		clinicalDate.month = clinicalDate.month + 12;
	}
	if (birthdate.year > clinicalDate.year)
	{
		return;
	}
	
	age = clinicalDate.year - birthdate.year;
	
	return age;

}

