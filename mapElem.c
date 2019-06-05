#include "mapElem.h"
#include "clinicalData.h"
#include "patient.h"

void mapKeyPrint(MapKey key) {
	printPatient(&key);
}

void mapValuePrint(MapValue value) {
	printClinicalData(&value);
}

/* funcao de comparacao de chaves */
int mapKeyEquals(MapKey key1, MapKey key2) {
	//no caso de MapKey == int. Alterar de acordo
	//com o tipo efetivo
	return (key1.id == key2.id); 
}