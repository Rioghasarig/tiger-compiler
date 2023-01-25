#include "frame.h"
#include "util.h"
#include "temp.h"

struct F_frame_ {
    Temp_label name; 
    F_accessList accessList; 
};

struct F_access_
    {int offset;};

F_frame F_newFrame(Temp_label name) {
    F_frame p = checked_malloc(sizeof(*p)); 
    p->name = name; 
    return p; 
}

Temp_label F_name(F_frame f) {
    return f->name; 
}

static F_access InFrame(int offset) {
    F_access p = checked_malloc(sizeof(*p));
    p->offset = offset; 
    return p; 
}

F_access F_allocLocal(F_frame f) {
    int offset = 4; 
    if(f->accessList == NULL) {
        f->accessList = checked_malloc(sizeof(*f->accessList));
        F_access h = InFrame(offset);
        f->accessList->head = h; 
        return h; 
    }
    else {
        F_accessList accessList = f->accessList; 
        offset += accessList->head->offset; 
        while(accessList->tail != NULL) {
            offset += accessList->head->offset; 
            accessList = accessList->tail; 
        }
        F_access h = InFrame(offset);
        accessList->tail = checked_malloc(sizeof(*accessList)); 
        accessList->tail->head = h; 
        return h; 
    }
}
