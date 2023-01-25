#include "temp.h"
typedef struct Tr_access_ *Tr_access;
typedef struct Tr_accessList_  *Tr_accessList; 
typedef struct Tr_level_ *Tr_level; 

Tr_accessList Tr_AccessList(Tr_access head, Tr_accessList tail); 

Tr_level Tr_outermost(void); 
Tr_level Tr_newLevel(Tr_level parent, Temp_label name); 
Tr_access Tr_allocLocal(Tr_level level); 