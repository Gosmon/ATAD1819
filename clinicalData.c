#include "clinicalData.h"
#include "date.h"
#include "patient.h"

PtClinicalData createClinicalData(float age, float bmi, float glucose, float insulin, float mcp1) {
	
	PtClinicalData newClinicalData = (PtClinicalData) malloc (sizeof(ClinicalData));

	newClinicalData->age = age;
	newClinicalData->bmi = bmi;
	newClinicalData->glucose = glucose;
	newClinicalData->insulin = insulin;
	newClinicalData->mcp1 =mcp1;

	newClinicalData->clinicalDataCount = 0;
	newClinicalData->disease_type = 0;

	return newClinicalData;
}

PtClinicalData changeClinicalData(PtClinicalData _this, float age, float bmi, float glucose, float insulin, float mcp1){
	
	_this->age = (_this->age * _this->clinicalDataCount + age) / _this->clinicalDataCount + 1;
	_this->bmi = (_this->bmi * _this->clinicalDataCount + bmi) / _this->clinicalDataCount + 1;
	_this->glucose = (_this->glucose * _this->clinicalDataCount + glucose) / _this->clinicalDataCount + 1;
	_this->insulin = (_this->insulin * _this->clinicalDataCount + insulin) / _this->clinicalDataCount + 1;
	_this->mcp1 = (_this->mcp1 * _this->clinicalDataCount + mcp1) / _this->clinicalDataCount + 1;

	_this->clinicalDataCount++;

	return _this;
}

void printClinicalData(PtClinicalData _this) {

	printf(" AGE: %.3f, BMI: %.3f, GLUCOSE: %.3f, INSULIN: %.3f, MCP1: %.3f", 
		_this->age, 
		_this->bmi, 
		_this->glucose,
		_this->insulin,
		_this->mcp1);

}
