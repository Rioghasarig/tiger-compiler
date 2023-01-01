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
	return (struct expty) {NULL, Ty_Int()};
      }
    }
    case A_fieldVar:  {
      EM_error(v->pos, "Haven't implemented A_fieldVar yet");
      return (struct expty) {NULL, Ty_Nil()};
    }
    case A_subscriptVar: {
      EM_error(v->pos, "Haven't implemented A_subscriptVar yet");
      return (struct expty) {NULL, Ty_Nil()};
    }
  }
}

Ty_ty transTy(A_ty ty) {
  if(ty->kind == A_arrayTy) {
    if(strcmp(ty->u.array->name, "int") == 0)
       return Ty_Array(Ty_Int()); 
  }

  return NULL;
}

Ty_ty tylook(S_table tenv, S_symbol name, int pos) {
  Ty_ty nameTy = S_look(tenv, name);
  if (nameTy) {
    return nameTy; 
  }
  else {
    EM_error(pos, "undefined variable %s",
	     S_name(name));
    return NULL;
  }
}

Ty_tyList makeFormalTyList(S_table tenv, A_fieldList params) {

  
  A_field params_head = params->head;
  
  Ty_ty head_type = tylook(tenv, params_head->typ,params_head->pos);
  Ty_ty nameList_head = Ty_Name(params_head->name, head_type);

  Ty_tyList head = Ty_TyList(nameList_head, NULL);
  Ty_tyList prev = NULL;
  
  Ty_tyList newNode;
  while(params->tail != NULL) {
    params = params->tail;
    params_head = params->head; 
    head_type = tylook(tenv, params_head->typ, params_head->pos);
    nameList_head = Ty_Name(params_head->name, head_type);
    newNode = Ty_TyList(nameList_head, NULL);
    if(head->tail = NULL) {
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
      S_enter(tenv, d->u.type->name,
		     transTy(d->u.type->ty));
      break;
    }
    case A_functionDec: {
      A_fundec f = d->u.function;
      Ty_ty resultTy = S_look(tenv, f->result);
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

struct expty transExp(S_table venv, S_table tenv, A_exp a) {
  switch(a->kind) {
    case A_letExp: {
      struct expty exp;
      A_decList d;
      S_beginScope(venv);
      S_beginScope(tenv);
      for (d = a->u.let.decs; d; d=d->tail) {
	transDec(venv, tenv, d->head);	
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
      if (oper == A_plusOp) {
	if(left.ty->kind != Ty_int)
	  EM_error(a->u.op.left->pos, "integer required");
	if(right.ty->kind != Ty_int)
	  EM_error(a->u.op.right->pos, "integer required");
	struct expty result;
	result.exp = NULL;
	result.ty = Ty_Int();
	return result;
	}
	break;
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
      struct expty head = transExp(venv, tenv, seq->head);
      while(seq->tail !=NULL) {
	seq = seq->tail;
	head = transExp(venv, tenv, seq->head);	
      }
      return head;
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
      Ty_ty ty = S_look(tenv, typ);
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
      struct expty elsee_result = transExp(venv, tenv, elsee);
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
      A_exp body = a->u.forr.body;
      struct expty body_result = transExp(venv, tenv, body);
      return body_result; 
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
  transExp(venv, tenv, exp);
}


