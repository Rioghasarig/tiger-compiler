typedef struct Tr_access_ *Tr_access;
typedef struct Tr_level_* Tr_level; 

Tr_level Tr_outermost(void); 
Tr_level Tr_newLevel(Tr_level parent, Temp_label name); 
