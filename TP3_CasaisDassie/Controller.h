int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* nextId);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* nextId);
int controller_addPassenger(LinkedList* pArrayListPassenger, int* nextId);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_listPassengers(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


