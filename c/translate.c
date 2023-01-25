#include "translate.h"
#include "frame.h"
#include "temp.h"
#include "util.h"

struct Tr_access_ {
  Tr_level level;
  F_access access;
};

struct Tr_level_ {
  Tr_level parent;
  Temp_label name;
  F_frame frame; 
};

Tr_level Tr_outermost(void) {
    static Tr_level outer = NULL; 
    if(outer == NULL) {
        outer = checked_malloc(sizeof(*outer));
        outer->parent = NULL; 
        outer->name = Temp_namedlabel("outer");
        outer->frame = NULL; 
    }
    return outer; 
}

Tr_level Tr_newLevel(Tr_level parent, Temp_label name) {
    Tr_level newLevel = checked_malloc(sizeof(*newLevel)); 
    
    newLevel->parent = parent; 
    newLevel->name  = name; 
    F_frame frame = F_newFrame(name); 
    newLevel->frame = frame; 
    return newLevel; 
}

Tr_access Tr_allocLocal(Tr_level level) {
    Tr_access access = checked_malloc(sizeof(*access));
    F_access f_access = F_allocLocal(level->frame); 
    access->access = f_access; 
    access->level = level; 
    return access; 
}