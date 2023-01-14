#include <stdio.h>
#include <string.h>
#include "util.h"
#include "semant.h"
#include "errormsg.h"
#include "env.h"
#include "std_functions.h"

		       
struct expty transVar(S_table venv, S_table tenv, A_var v) {
  switch (v->kind) {
    case A_simpleVar: {
      E_enventry x = S_look(venv, v->u.simple);
      if(x && x->kind==E_varEntry) {
	struct expty result = {NULL, x->u.var.ty};
	return result;
      }
      else {
	EM_error(v->pos, "undefined variable %s",
		 S_name(v->u.simple));
	return (struct expty) {NULL, Ty_Nil()};
      }
    }
    case A_fieldVar:  {
      E_enventry x = S_look(venv, v->u.field.var->u.simple);
      Ty_ty recordTy = x->u.var.ty;
      Ty_fieldList record = recordTy->u.record;
      while(record != NULL) {
	Ty_field head = record->head;
	if(head->name == v->u.field.sym) {
	  struct expty result = {NULL, head->ty};
	  return result;
	}
	record = record->tail;
      }
      return (struct expty) {NULL, Ty_Nil()};
    }
    case A_subscriptVar: {
      EM_error(v->pos, "Haven't implemented A_subscriptVar yet");
      return (struct expty) {NULL, Ty_Nil()};
    }
  }
}

Ty_fieldList Ty_fieldListFromAST(S_table tenv, A_fieldList fieldList) {
  if(fieldList == NULL)
    return NULL;
  
  A_field head_field = fieldList->head;

  Ty_ty head_type = tylook(tenv, head_field->typ, head_field->pos);
  S_symbol head_name = head_field->name;
  Ty_field head_ty_field = Ty_Field(head_name, head_type);
  
  Ty_fieldList head_node = Ty_FieldList(head_ty_field, NULL); 
  Ty_fieldList prev = NULL;
  Ty_fieldList newNode = NULL;
  
  while(fieldList->tail != NULL) {
    fieldList = fieldList->tail;
    head_field = fieldList->head;

    head_type = tylook(tenv, head_field->typ, head_field->pos);
    head_name = head_field->name;
    head_ty_field = Ty_Field(head_name, head_type);
    newNode = Ty_FieldList(head_ty_field, NULL);
    if (head_node->tail == NULL) {
      head_node->tail = newNode; 
    }
    else {
      prev->tail = newNode;
    }

    prev = newNode; 
  }
  return head_node; 
}

Ty_ty transTy(S_table tenv, A_ty ty) {
  if(ty->kind == A_arrayTy) {
    Ty_ty type = S_look(tenv, ty->u.name); 
    if(type != NULL)
       return Ty_Array(type);
    else {
      EM_error(ty->pos, "unhandle type of array");
      return NULL;
    }
  }
  else if(ty->kind == A_recordTy) {
    Ty_fieldList fieldList = Ty_fieldListFromAST(tenv, ty->u.record);
    return Ty_Record(fieldList); 
  }
  else if(ty->kind == A_nameTy) {
    S_symbol name = ty->u.name;
    Ty_ty type = S_look(tenv,name);
    if(ty == NULL) {
      EM_error(ty->pos, "unknown type %s", S_name(name));
    }
    return type; 
  }
  else {
    EM_error(ty->pos, "unhandled type kind");
    return NULL;
  }
}


Ty_ty tylook(S_table tenv, S_symbol type_name, int pos) {
  Ty_ty nameTy = S_look(tenv, type_name);
  if (nameTy) {
    return nameTy; 
  }
  else {
    EM_error(pos, "undefined type %s",
	     S_name(type_name));
    return NULL;
  }
}

Ty_tyList makeFormalTyList(S_table tenv, A_fieldList params) {

  if (params == NULL)
    return NULL;
  
  A_field params_head = params->head;
  
  Ty_ty head_type = tylook(tenv, params_head->typ,params_head->pos);
  //Ty_ty nameList_head = Ty_Name(params_head->name, head_type);

  Ty_tyList head = Ty_TyList(head_type, NULL);
  Ty_tyList prev = NULL;
  
  Ty_tyList newNode;
  while(params->tail != NULL) {
    params = params->tail;
    params_head = params->head; 
    head_type = tylook(tenv, params_head->typ, params_head->pos);
    //nameList_head = Ty_Name(params_head->name, head_type);
    newNode = Ty_TyList(head_type, NULL);
    if(head->tail == NULL) {
      head->tail = newNode;
    }
    else {
      prev->tail = newNode;
    }

    prev = newNode;
  }
  return head; 
}
void transDec(S_table venv, S_table tenv, A_dec d) {
  switch(d->kind) {
    case A_varDec: {
      struct expty e = transExp(venv, tenv, d->u.var.init);
      S_enter(venv, d->u.var.var, E_VarEntry(e.ty));
      break;
    }
    case A_typeDec: {
      //Ty_ty nameType = Ty_Name(d->u.type->name, NULL);      
      //S_enter(tenv, d->u.type->name, nameType); 	     
      Ty_ty type = transTy(tenv, d->u.type->ty);
      Ty_ty nameType = S_look(tenv, d->u.type->name); 
      nameType->u.name.ty = type; 
      break;
    }
    case A_functionDec: {
      A_fundec f = d->u.function;

      // If the function has a return type find it in the type symbol table
      Ty_ty resultTy;
      if(f->result) {
	resultTy = S_look(tenv, f->result);
      }
      else {
	resultTy = Ty_Void();
      }
	
      Ty_tyList formalTys = makeFormalTyList(tenv,f->params);
      S_enter(venv, f->name, E_FunEntry(formalTys, resultTy));
      S_beginScope(venv);
      {
	A_fieldList l; Ty_tyList t;
	for(l = f->params, t=formalTys; l; l=l->tail, t =t->tail) {
	  S_enter(venv, l->head->name, E_VarEntry(t->head));
	}
      }
      transExp(venv, tenv, d->u.function->body);
      S_endScope(venv);
      break;
    }
  }
}
  

struct expty call_exp(S_table venv, S_table tenv, A_exp call_exp) {
  S_symbol func = call_exp->u.call.func;
  
  E_enventry fun_entry = S_look(venv, func);
  if(fun_entry && fun_entry->kind == E_funEntry) {
    struct expty result = {NULL, fun_entry->u.fun.result};
    return result;
  }

}

bool detect_cycles(S_table tenv, S_symbol name) {
  Ty_ty tortoise = S_look(tenv, name);
  if(tortoise->kind != Ty_name)
    return 0;
  tortoise = tortoise->u.name.ty;
  Ty_ty hare = S_look(tenv, name);
  if(hare->kind != Ty_name)
    return 0;
  hare = hare->u.name.ty;
  if(hare->kind != Ty_name)
    return 0;
  hare = hare->u.name.ty;
  while (1) {
    if(tortoise->u.name.sym == hare->u.name.sym) {
      return 1; 
    }
    
    if(tortoise->kind != Ty_name)
      return 0;
    tortoise = tortoise->u.name.ty;

    if(hare->kind != Ty_name)
      return 0;
    hare = hare->u.name.ty;
    if(hare->kind != Ty_name)
      return 0;
    hare = hare->u.name.ty; 
  }
}
struct expty transExp(S_table venv, S_table tenv, A_exp a) {
  switch(a->kind) {
    case A_letExp: {
      struct expty exp;
      A_decList d;
      S_beginScope(venv);
      S_beginScope(tenv);
      for (d = a->u.let.decs; d; d=d->tail)  {
	if(d->head->kind == A_typeDec) {
	  Ty_ty nameType = Ty_Name(d->head->u.type->name, NULL); 
	  S_enter(tenv, d->head->u.type->name, nameType); 	  
	}
      }
      for (d = a->u.let.decs; d; d=d->tail) {
	transDec(venv, tenv, d->head);
      }
      for (d = a->u.let.decs; d; d=d->tail) {
	if(d->head->kind == A_typeDec) {
	  if(detect_cycles(tenv, d->head->u.type->name)) {
	    EM_error(a->pos,"Cycle in definition of %s", S_name(d->head->u.type->name)); 
	  }
	    
	}
      }
      A_expList p;
      for(p = a->u.let.body; p != NULL; p = p->tail) {
	exp = transExp(venv, tenv, p->head);
      }

      S_endScope(tenv);
      S_endScope(venv);
      return exp;
    }
    case A_varExp: {
      return transVar(venv, tenv, a->u.var);

    }
    case A_opExp: {
      A_oper  oper = a->u.op.oper;
      struct expty left = transExp(venv, tenv, a->u.op.left);
      struct expty right = transExp(venv, tenv, a->u.op.right);

      if(oper == A_plusOp || oper == A_minusOp || oper == A_timesOp ||
	 oper == A_divideOp) {
	 if(left.ty->kind != Ty_int)
	   EM_error(a->u.op.left->pos, "integer required");
	 if(right.ty->kind != Ty_int)
	   EM_error(a->u.op.right->pos, "integer required");
      }
      if(oper == A_neqOp || oper == A_ltOp ||
	 oper == A_gtOp  || oper == A_geOp || oper == A_andOp ||
	 oper == A_orOp) {
	
	if(left.ty->kind != right.ty->kind)
	  EM_error(a->pos, "Operand types must match"); 
      }
      if(oper == A_eqOp) {
	if(left.ty->kind != right.ty->kind &&
	   left.ty->kind != Ty_nil &&
	   right.ty->kind != Ty_nil)
	  EM_error(a->pos, "Operands of '=' must have same types or be nil"); 
      }
      struct expty result;
      result.exp = NULL;
      result.ty = Ty_Int();
      return result;
    }
    case A_intExp: {
      struct expty result;
      result.exp = NULL;
      result.ty = Ty_Int();
      return result;
    }
    case A_stringExp: {
      struct expty result = {NULL, Ty_String()};
      return result;
    }
    case A_seqExp: {
      A_expList seq = a->u.seq;
      if(seq != NULL) {
	struct expty head = transExp(venv, tenv, seq->head);
	while(seq->tail !=NULL) {
	  seq = seq->tail;
	  head = transExp(venv, tenv, seq->head);	
	}
	return head;
      }
      else {
	struct expty result = {NULL, Ty_Nil()};
	return result;
      }
    }
    case A_recordExp: {
      S_symbol typ = a->u.record.typ;
      A_efieldList fields = a->u.record.fields;

      Ty_fieldList record = NULL; 
      Ty_fieldList p = NULL;
      Ty_fieldList prev = NULL;
      while(fields != NULL) {
	A_efield head  = fields->head;
	struct expty headType = transExp(venv, tenv, head->exp);
	Ty_field head_field = Ty_Field(head->name, headType.ty);
	p = Ty_FieldList(head_field, NULL); 
        if (record == NULL)
	  record = p;
	else
	  prev->tail = p;

	prev = p;
	fields = fields->tail; 
      }
      struct expty result;
      result.exp = NULL;
      result.ty = Ty_Record(record); 
      return result;
    }
    case A_arrayExp: {
      S_symbol typ = a->u.array.typ;
      Ty_ty nameType = S_look(tenv, typ);
      Ty_ty ty = nameType->u.name.ty;
      if(ty && ty->kind == Ty_array) {
	struct expty result = {NULL, ty};
	return result;
      }
      else {
	EM_error(a->pos, "Unknown array type: %s",
		 S_name(typ));
      }
    }
    case A_callExp: {
      return call_exp(venv, tenv, a); 
    }
    case A_assignExp: {
      A_exp exp = a->u.assign.exp;
      transExp(venv, tenv, exp);
      struct expty result = {NULL, Ty_Nil()};
      return result; 
    }
    case A_ifExp: {
      A_exp test = a->u.iff.test;
      A_exp then = a->u.iff.then;
      A_exp elsee = a->u.iff.elsee;

      struct expty test_result = transExp(venv, tenv, test);
      if ( test_result.ty->kind != Ty_int) {
	EM_error(test->pos, "Test condition must have integer type");		 
      }

      struct expty then_result = transExp(venv, tenv, then);

      
      if(elsee) {
	 struct expty elsee_result = transExp(venv, tenv, elsee);
	 if (then_result.ty->kind != elsee_result.ty->kind) {
	   EM_error(a->pos, "Then and Else expressions must have matching type"); 
	 }
      }
      else {
	if (then_result.ty->kind != Ty_nil) {
	  EM_error(a->pos, "Then expression must be of type Nil");
	}
      }
      return then_result; 
    }
    case A_whileExp : {
      A_exp test = a->u.whilee.test;
      A_exp body = a->u.whilee.body;
      
      struct expty test_result = transExp(venv, tenv, test);
      if ( test_result.ty->kind != Ty_int) {
	EM_error(test->pos, "Test condition must have integer type");		 
      }
      
      struct expty body_result = transExp(venv, tenv, body);
      return body_result; 
    }
    case A_forExp: {
      S_beginScope(venv);
      S_symbol var = a->u.forr.var;
      S_enter(venv, var, E_VarEntry(Ty_Int()));
      A_exp body = a->u.forr.body;

      A_exp lo = a->u.forr.lo;
      A_exp hi = a->u.forr.hi;
      struct expty lo_result = transExp(venv, tenv, lo);
      struct expty hi_result = transExp(venv, tenv, hi);
      if(lo_result.ty->kind != Ty_int) {
	EM_error(lo->pos, "For loop lo should be int"); 
      }
      if(hi_result.ty->kind != Ty_int) {
	EM_error(hi->pos, "For loop hi should be int");
      }
      struct expty body_result = transExp(venv, tenv, body);
      return body_result;
      S_endScope(venv); 
    }
    default: {
      struct expty result = {NULL, Ty_Nil()};
      return result;
    }
  }

}

void SEM_transProg(A_exp exp) {
  S_table venv = S_empty();
  S_table tenv = S_empty();
  add_std_functions(venv);
  add_std_types(tenv);
  transExp(venv, tenv, exp);
}


