#pragma once 
#include "date.h"
#include "clinicalData.h"

typedef char String[256];

typedef struct patient {

	int id; /*N�mero que identifica um paciente */
	Date birthdate; /*Data de nascimento*/
	char gender; /*G�nero (M ou F)*/
	String hospital; /*Nome do hospital de referencia do paciente*/
	String district; /*Distrito onde pertence o hospital*/
	ClinicalData clinicalData; /*Dados cl�nicos do doente (m�dias)*/

} Patient;

typedef Patient* PtPatient;

PtPatient createPatient(int id, Date birthdate, char gender, String hospital, String district);
void printPatient(PtPatient _this);
void addClinicalData(Patient patient, ClinicalData clinicalData);