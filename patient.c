#include "patient.h"
#include <stdlib.h>
#include <stdio.h>

PtPatient createPatient(int id, Date birthdate, char gender, String hospital, String district) {

	PtPatient newPatient = (PtPatient) malloc (sizeof(Patient));
	newPatient->id = id;
	strcpy_s(newPatient->gender, sizeof(newPatient->gender), gender);
	newPatient->birthdate = birthdate;
	strcpy_s(newPatient->hospital, sizeof(newPatient->hospital), hospital);
	strcpy_s(newPatient->district, sizeof(newPatient->district), district);
	return newPatient;
}

void printPatient(PtPatient _this) {

	printf("ID: %d, BIRTHDATE: %s, GENDER: %c, HOSPITAL: %s, DISTRICT: %s, CLINICAL DATA: %s", 
		_this->id, 
		_this->birthdate,
		_this->gender, 
		_this->hospital,
		_this->district,
		_this->clinicalData);

}

void addClinicalData(PtPatient patient, PtClinicalData clinicalData) {
	patient->clinicalData = *clinicalData;
	clinicalData->clinicalDataCount++;
}