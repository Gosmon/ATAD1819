#pragma once

#include "clinicalData.h"
#include "patient.h"

/* definicao do tipo da chave */
typedef Patient MapKey;
/* definicao do tipo do valor*/
typedef ClinicalData MapValue;

void mapKeyPrint(MapKey key);
void mapValuePrint(MapValue value);

/* funcao de comparacao de chaves */
int mapKeyEquals(MapKey key1, MapKey key2);
