// A Bison parser, made by GNU Bison 3.8.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "tiger.yy"

#include <stdio.h>
#include "util.h"
#include "errormsg.h"
#include "ast.h"

AST::ExpressionPtr absyn_root; 

#line 50 "tiger.tab.cc"


#include "tiger.tab.hh"


// Unqualified %code blocks.
#line 34 "tiger.yy"

# include "driver.hh"

#line 61 "tiger.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 153 "tiger.tab.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_arithmetic_exp: // arithmetic_exp
      case symbol_kind::S_comparison_exp: // comparison_exp
      case symbol_kind::S_boolean_exp: // boolean_exp
        value.YY_MOVE_OR_COPY< AST::BinOpExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.YY_MOVE_OR_COPY< AST::CallExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_args: // function_args
      case symbol_kind::S_function_args_tail: // function_args_tail
        value.YY_MOVE_OR_COPY< AST::ExpressionList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
        value.YY_MOVE_OR_COPY< AST::ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_sequence: // expression_sequence
      case symbol_kind::S_exp_seq_tail: // exp_seq_tail
        value.YY_MOVE_OR_COPY< AST::ExpressionSequencePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_extension: // field_extension
        value.YY_MOVE_OR_COPY< AST::FieldVariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        value.YY_MOVE_OR_COPY< AST::SubscriptVariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_negation_exp: // negation_exp
        value.YY_MOVE_OR_COPY< AST::UnOpExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.YY_MOVE_OR_COPY< AST::VariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_record_field: // record_field
        value.YY_MOVE_OR_COPY< AST::efield > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_record_list: // record_list
      case symbol_kind::S_record_list_extension: // record_list_extension
        value.YY_MOVE_OR_COPY< AST::efieldList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_arithmetic_exp: // arithmetic_exp
      case symbol_kind::S_comparison_exp: // comparison_exp
      case symbol_kind::S_boolean_exp: // boolean_exp
        value.move< AST::BinOpExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< AST::CallExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_function_args: // function_args
      case symbol_kind::S_function_args_tail: // function_args_tail
        value.move< AST::ExpressionList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_exp: // exp
        value.move< AST::ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_sequence: // expression_sequence
      case symbol_kind::S_exp_seq_tail: // exp_seq_tail
        value.move< AST::ExpressionSequencePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_extension: // field_extension
        value.move< AST::FieldVariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        value.move< AST::SubscriptVariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_negation_exp: // negation_exp
        value.move< AST::UnOpExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< AST::VariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_record_field: // record_field
        value.move< AST::efield > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_record_list: // record_list
      case symbol_kind::S_record_list_extension: // record_list_extension
        value.move< AST::efieldList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_arithmetic_exp: // arithmetic_exp
      case symbol_kind::S_comparison_exp: // comparison_exp
      case symbol_kind::S_boolean_exp: // boolean_exp
        value.copy< AST::BinOpExpressionPtr > (that.value);
        break;

      case symbol_kind::S_function_call: // function_call
        value.copy< AST::CallExpressionPtr > (that.value);
        break;

      case symbol_kind::S_function_args: // function_args
      case symbol_kind::S_function_args_tail: // function_args_tail
        value.copy< AST::ExpressionList > (that.value);
        break;

      case symbol_kind::S_exp: // exp
        value.copy< AST::ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_expression_sequence: // expression_sequence
      case symbol_kind::S_exp_seq_tail: // exp_seq_tail
        value.copy< AST::ExpressionSequencePtr > (that.value);
        break;

      case symbol_kind::S_field_extension: // field_extension
        value.copy< AST::FieldVariablePtr > (that.value);
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        value.copy< AST::SubscriptVariablePtr > (that.value);
        break;

      case symbol_kind::S_negation_exp: // negation_exp
        value.copy< AST::UnOpExpressionPtr > (that.value);
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.copy< AST::VariablePtr > (that.value);
        break;

      case symbol_kind::S_record_field: // record_field
        value.copy< AST::efield > (that.value);
        break;

      case symbol_kind::S_record_list: // record_list
      case symbol_kind::S_record_list_extension: // record_list_extension
        value.copy< AST::efieldList > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_arithmetic_exp: // arithmetic_exp
      case symbol_kind::S_comparison_exp: // comparison_exp
      case symbol_kind::S_boolean_exp: // boolean_exp
        value.move< AST::BinOpExpressionPtr > (that.value);
        break;

      case symbol_kind::S_function_call: // function_call
        value.move< AST::CallExpressionPtr > (that.value);
        break;

      case symbol_kind::S_function_args: // function_args
      case symbol_kind::S_function_args_tail: // function_args_tail
        value.move< AST::ExpressionList > (that.value);
        break;

      case symbol_kind::S_exp: // exp
        value.move< AST::ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_expression_sequence: // expression_sequence
      case symbol_kind::S_exp_seq_tail: // exp_seq_tail
        value.move< AST::ExpressionSequencePtr > (that.value);
        break;

      case symbol_kind::S_field_extension: // field_extension
        value.move< AST::FieldVariablePtr > (that.value);
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        value.move< AST::SubscriptVariablePtr > (that.value);
        break;

      case symbol_kind::S_negation_exp: // negation_exp
        value.move< AST::UnOpExpressionPtr > (that.value);
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< AST::VariablePtr > (that.value);
        break;

      case symbol_kind::S_record_field: // record_field
        value.move< AST::efield > (that.value);
        break;

      case symbol_kind::S_record_list: // record_list
      case symbol_kind::S_record_list_extension: // record_list_extension
        value.move< AST::efieldList > (that.value);
        break;

      case symbol_kind::S_INT: // INT
        value.move< int > (that.value);
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_arithmetic_exp: // arithmetic_exp
      case symbol_kind::S_comparison_exp: // comparison_exp
      case symbol_kind::S_boolean_exp: // boolean_exp
        yylhs.value.emplace< AST::BinOpExpressionPtr > ();
        break;

      case symbol_kind::S_function_call: // function_call
        yylhs.value.emplace< AST::CallExpressionPtr > ();
        break;

      case symbol_kind::S_function_args: // function_args
      case symbol_kind::S_function_args_tail: // function_args_tail
        yylhs.value.emplace< AST::ExpressionList > ();
        break;

      case symbol_kind::S_exp: // exp
        yylhs.value.emplace< AST::ExpressionPtr > ();
        break;

      case symbol_kind::S_expression_sequence: // expression_sequence
      case symbol_kind::S_exp_seq_tail: // exp_seq_tail
        yylhs.value.emplace< AST::ExpressionSequencePtr > ();
        break;

      case symbol_kind::S_field_extension: // field_extension
        yylhs.value.emplace< AST::FieldVariablePtr > ();
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        yylhs.value.emplace< AST::SubscriptVariablePtr > ();
        break;

      case symbol_kind::S_negation_exp: // negation_exp
        yylhs.value.emplace< AST::UnOpExpressionPtr > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        yylhs.value.emplace< AST::VariablePtr > ();
        break;

      case symbol_kind::S_record_field: // record_field
        yylhs.value.emplace< AST::efield > ();
        break;

      case symbol_kind::S_record_list: // record_list
      case symbol_kind::S_record_list_extension: // record_list_extension
        yylhs.value.emplace< AST::efieldList > ();
        break;

      case symbol_kind::S_INT: // INT
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: exp
#line 82 "tiger.yy"
             {absyn_root = yystack_[0].value.as < AST::ExpressionPtr > ();}
#line 837 "tiger.tab.cc"
    break;

  case 3: // exp: INT
#line 84 "tiger.yy"
         {yylhs.value.as < AST::ExpressionPtr > () = AST::IntExpression::Node(drv.location.begin.line, yystack_[0].value.as < int > ());}
#line 843 "tiger.tab.cc"
    break;

  case 5: // exp: NIL
#line 86 "tiger.yy"
         {yylhs.value.as < AST::ExpressionPtr > () = AST::NilExpression::Node(drv.location.begin.line);}
#line 849 "tiger.tab.cc"
    break;

  case 6: // exp: STRING
#line 87 "tiger.yy"
            {yylhs.value.as < AST::ExpressionPtr > () = AST::StringExpression::Node(drv.location.begin.line, yystack_[0].value.as < std::string > ());}
#line 855 "tiger.tab.cc"
    break;

  case 7: // exp: BREAK
#line 88 "tiger.yy"
           {yylhs.value.as < AST::ExpressionPtr > () = AST::BreakStatement::Node(drv.location.begin.line);}
#line 861 "tiger.tab.cc"
    break;

  case 8: // exp: LPAREN expression_sequence RPAREN
#line 89 "tiger.yy"
                                       {yylhs.value.as < AST::ExpressionPtr > () = (AST::ExpressionPtr)yystack_[1].value.as < AST::ExpressionSequencePtr > ();}
#line 867 "tiger.tab.cc"
    break;

  case 9: // exp: function_call
#line 90 "tiger.yy"
                   {yylhs.value.as < AST::ExpressionPtr > () = (AST::ExpressionPtr)yystack_[0].value.as < AST::CallExpressionPtr > ();}
#line 873 "tiger.tab.cc"
    break;

  case 10: // exp: arithmetic_exp
#line 91 "tiger.yy"
                     {yylhs.value.as < AST::ExpressionPtr > () = (AST::ExpressionPtr)yystack_[0].value.as < AST::BinOpExpressionPtr > ();}
#line 879 "tiger.tab.cc"
    break;

  case 21: // expression_sequence: %empty
#line 103 "tiger.yy"
                     {yylhs.value.as < AST::ExpressionSequencePtr > () = AST::ExpressionSequence::Node(drv.location.begin.line);}
#line 885 "tiger.tab.cc"
    break;

  case 22: // expression_sequence: exp exp_seq_tail
#line 104 "tiger.yy"
                                      {yystack_[0].value.as < AST::ExpressionSequencePtr > ()->push_front(yystack_[1].value.as < AST::ExpressionPtr > ()); yylhs.value.as < AST::ExpressionSequencePtr > () = yystack_[0].value.as < AST::ExpressionSequencePtr > ();}
#line 891 "tiger.tab.cc"
    break;

  case 23: // exp_seq_tail: %empty
#line 106 "tiger.yy"
                         {yylhs.value.as < AST::ExpressionSequencePtr > () = AST::ExpressionSequence::Node(drv.location.begin.line);}
#line 897 "tiger.tab.cc"
    break;

  case 24: // exp_seq_tail: SEMICOLON exp exp_seq_tail
#line 107 "tiger.yy"
                                          {yystack_[0].value.as < AST::ExpressionSequencePtr > ()->push_front(yystack_[1].value.as < AST::ExpressionPtr > ()); yylhs.value.as < AST::ExpressionSequencePtr > () = yystack_[0].value.as < AST::ExpressionSequencePtr > ();}
#line 903 "tiger.tab.cc"
    break;

  case 25: // function_call: ID LPAREN function_args RPAREN
#line 110 "tiger.yy"
  {yylhs.value.as < AST::CallExpressionPtr > () = AST::CallExpression::Node(drv.location.begin.line, AST::Symbol::Gen(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < AST::ExpressionList > ());}
#line 909 "tiger.tab.cc"
    break;

  case 26: // function_args: %empty
#line 112 "tiger.yy"
                           {yylhs.value.as < AST::ExpressionList > () = AST::ExpressionList();}
#line 915 "tiger.tab.cc"
    break;

  case 27: // function_args: exp function_args_tail
#line 113 "tiger.yy"
                                      {yystack_[0].value.as < AST::ExpressionList > ().push_front(yystack_[1].value.as < AST::ExpressionPtr > ()); yylhs.value.as < AST::ExpressionList > () = std::move(yystack_[0].value.as < AST::ExpressionList > ());}
#line 921 "tiger.tab.cc"
    break;

  case 28: // function_args_tail: %empty
#line 115 "tiger.yy"
                               {yylhs.value.as < AST::ExpressionList > () = AST::ExpressionList();}
#line 927 "tiger.tab.cc"
    break;

  case 29: // function_args_tail: COMMA exp function_args_tail
#line 116 "tiger.yy"
                                                 {yystack_[0].value.as < AST::ExpressionList > ().push_back(yystack_[1].value.as < AST::ExpressionPtr > ()); yylhs.value.as < AST::ExpressionList > () = std::move(yystack_[0].value.as < AST::ExpressionList > ());}
#line 933 "tiger.tab.cc"
    break;

  case 30: // arithmetic_exp: exp PLUS exp
#line 120 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::plusOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 941 "tiger.tab.cc"
    break;

  case 31: // arithmetic_exp: exp MINUS exp
#line 124 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::minusOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 949 "tiger.tab.cc"
    break;

  case 32: // arithmetic_exp: exp TIMES exp
#line 128 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::timesOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 957 "tiger.tab.cc"
    break;

  case 33: // arithmetic_exp: exp DIVIDE exp
#line 132 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::divideOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 965 "tiger.tab.cc"
    break;

  case 34: // negation_exp: MINUS exp
#line 136 "tiger.yy"
                                     {yylhs.value.as < AST::UnOpExpressionPtr > () = AST::UnOpExpression::Node(drv.location.begin.line,
                                                        AST::UnOpExpression::negationOp, yystack_[0].value.as < AST::ExpressionPtr > ()); }
#line 972 "tiger.tab.cc"
    break;

  case 35: // comparison_exp: exp EQ exp
#line 140 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::eqOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 980 "tiger.tab.cc"
    break;

  case 36: // comparison_exp: exp NEQ exp
#line 144 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::neqOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 988 "tiger.tab.cc"
    break;

  case 37: // comparison_exp: exp GT exp
#line 148 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::gtOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 996 "tiger.tab.cc"
    break;

  case 38: // comparison_exp: exp GE exp
#line 152 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::geOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 1004 "tiger.tab.cc"
    break;

  case 39: // comparison_exp: exp LT exp
#line 156 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::ltOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 1012 "tiger.tab.cc"
    break;

  case 40: // comparison_exp: exp LE exp
#line 160 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::leOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 1020 "tiger.tab.cc"
    break;

  case 41: // boolean_exp: exp AND exp
#line 164 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::andOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 1028 "tiger.tab.cc"
    break;

  case 42: // boolean_exp: exp OR exp
#line 168 "tiger.yy"
  {yylhs.value.as < AST::BinOpExpressionPtr > () = AST::BinOpExpression::Node(drv.location.begin.line, 
                                    AST::BinOpExpression::orOp, 
                                    yystack_[2].value.as < AST::ExpressionPtr > (),yystack_[0].value.as < AST::ExpressionPtr > ());}
#line 1036 "tiger.tab.cc"
    break;

  case 44: // record_list: record_field record_list_extension
#line 176 "tiger.yy"
  {yystack_[0].value.as < AST::efieldList > ().push_front(yystack_[1].value.as < AST::efield > ()); yylhs.value.as < AST::efieldList > () = std::move(yystack_[0].value.as < AST::efieldList > ());}
#line 1042 "tiger.tab.cc"
    break;

  case 45: // record_list_extension: %empty
#line 178 "tiger.yy"
                       {yylhs.value.as < AST::efieldList > () = AST::efieldList();}
#line 1048 "tiger.tab.cc"
    break;

  case 46: // record_list_extension: COMMA record_field record_list_extension
#line 180 "tiger.yy"
  {yystack_[0].value.as < AST::efieldList > ().push_front(yystack_[1].value.as < AST::efield > ()); yylhs.value.as < AST::efieldList > () = std::move(yystack_[0].value.as < AST::efieldList > ());}
#line 1054 "tiger.tab.cc"
    break;

  case 47: // record_field: ID EQ exp
#line 182 "tiger.yy"
                        {yylhs.value.as < AST::efield > () = AST::efield{AST::Symbol::Gen(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < AST::ExpressionPtr > ()};}
#line 1060 "tiger.tab.cc"
    break;

  case 72: // lvalue: ID
#line 223 "tiger.yy"
           {yylhs.value.as < AST::VariablePtr > () = AST::SimpleVariable::Node(0, AST::Symbol::Gen(yystack_[0].value.as < std::string > ()));}
#line 1066 "tiger.tab.cc"
    break;

  case 73: // lvalue: ID field_extension
#line 224 "tiger.yy"
                           {yylhs.value.as < AST::VariablePtr > () = AST::SimpleVariable::Node(0, AST::Symbol::Gen(yystack_[1].value.as < std::string > ())); yystack_[0].value.as < AST::FieldVariablePtr > ()->set_var(yylhs.value.as < AST::VariablePtr > ());}
#line 1072 "tiger.tab.cc"
    break;

  case 74: // lvalue: ID subscript_extension
#line 225 "tiger.yy"
                               {yylhs.value.as < AST::VariablePtr > () = AST::SimpleVariable::Node(0, AST::Symbol::Gen(yystack_[1].value.as < std::string > ())); yystack_[0].value.as < AST::SubscriptVariablePtr > ()->set_var(yylhs.value.as < AST::VariablePtr > ());}
#line 1078 "tiger.tab.cc"
    break;

  case 75: // field_extension: DOT ID
#line 227 "tiger.yy"
                         {yylhs.value.as < AST::FieldVariablePtr > () = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen(yystack_[0].value.as < std::string > ())); }
#line 1084 "tiger.tab.cc"
    break;

  case 76: // field_extension: DOT ID field_extension
#line 228 "tiger.yy"
                                        {yylhs.value.as < AST::FieldVariablePtr > () = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen(yystack_[1].value.as < std::string > ())); yystack_[0].value.as < AST::FieldVariablePtr > ()->set_var(yylhs.value.as < AST::FieldVariablePtr > ());}
#line 1090 "tiger.tab.cc"
    break;

  case 77: // field_extension: DOT ID subscript_extension
#line 229 "tiger.yy"
                                            {yylhs.value.as < AST::FieldVariablePtr > () = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen(yystack_[1].value.as < std::string > ())); yystack_[0].value.as < AST::SubscriptVariablePtr > ()->set_var(yylhs.value.as < AST::FieldVariablePtr > ());}
#line 1096 "tiger.tab.cc"
    break;

  case 78: // subscript_extension: LBRACK exp RBRACK
#line 231 "tiger.yy"
                                        {yylhs.value.as < AST::SubscriptVariablePtr > () = AST::SubscriptVariable::PartialNode(0, yystack_[1].value.as < AST::ExpressionPtr > ());}
#line 1102 "tiger.tab.cc"
    break;

  case 79: // subscript_extension: LBRACK exp RBRACK field_extension
#line 232 "tiger.yy"
                                                       {yylhs.value.as < AST::SubscriptVariablePtr > () = AST::SubscriptVariable::PartialNode(0,yystack_[2].value.as < AST::ExpressionPtr > ()); yystack_[0].value.as < AST::FieldVariablePtr > ()->set_var(yylhs.value.as < AST::SubscriptVariablePtr > ());}
#line 1108 "tiger.tab.cc"
    break;

  case 80: // subscript_extension: LBRACK exp RBRACK subscript_extension
#line 233 "tiger.yy"
                                                           {yylhs.value.as < AST::SubscriptVariablePtr > () = AST::SubscriptVariable::PartialNode(0,yystack_[2].value.as < AST::ExpressionPtr > ()); yystack_[0].value.as < AST::SubscriptVariablePtr > ()->set_var(yylhs.value.as < AST::SubscriptVariablePtr > ());}
#line 1114 "tiger.tab.cc"
    break;


#line 1118 "tiger.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char parser::yypact_ninf_ = -43;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       5,    21,   -43,   -43,     5,     5,     5,     5,    -2,    18,
     -43,   -43,    20,   254,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,    -4,     5,     5,    22,
      26,   -43,   -43,   161,    23,   -43,   210,   107,    12,    28,
      40,    41,     7,    18,   -43,   -43,   -43,   -43,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,    58,    55,   226,    46,    53,    80,     4,     5,   -43,
     -43,     5,     5,     5,    78,    -5,    68,     5,   -43,    -1,
      -1,   -43,   -43,   278,   278,   278,   278,   278,   278,   266,
     288,   254,     5,   -43,   -43,     1,     5,   -43,    22,   -43,
       5,   -43,   -43,   161,   193,   254,   173,    86,    87,     5,
       8,    52,    58,     5,   -43,   -43,   254,    80,   242,   -43,
       5,     5,    88,    83,    66,   254,   -43,    86,    57,   -43,
     -43,   -43,   278,   -43,     4,   254,   140,    95,     6,     5,
      85,    98,     5,    96,   100,     5,   254,   -43,   -43,   254,
     101,   -43,    90,   254,    99,     5,   102,   254,    96,   -43
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    72,     6,     3,    21,     0,     0,     0,     0,    55,
       7,     5,     0,     2,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     4,    26,     0,     0,
       0,    73,    74,    23,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    55,    57,    58,    59,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,    45,    75,     0,    22,
       8,     0,     0,     0,     0,     0,     0,    21,    56,    30,
      31,    32,    33,    35,    36,    39,    40,    37,    38,    41,
      42,    49,     0,    27,    25,    78,     0,    43,     0,    44,
       0,    76,    77,    23,    51,    52,     0,    64,     0,     0,
       0,     0,    28,     0,    79,    80,    47,    45,     0,    24,
       0,     0,     0,     0,     0,    68,    61,    64,     0,    60,
      54,    29,    48,    46,    78,    50,     0,     0,     0,     0,
       0,     0,     0,    66,     0,     0,    69,    62,    63,    53,
       0,    65,     0,    70,     0,     0,     0,    71,    66,    67
  };

  const signed char
  parser::yypgoto_[] =
  {
     -43,   -43,     0,    30,     9,   -43,   -43,    10,   -43,   -43,
     -43,   -43,   -43,   -43,    -9,    13,   -43,   -43,   -43,   -43,
     -43,   -43,    71,   -43,   -43,   -43,   -12,   -42,   -43,   -43,
     -43,     2,     3
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    12,    33,    34,    69,    14,    62,    93,    15,    16,
      17,    18,    19,    65,    99,    66,    20,    21,    22,    23,
      24,    25,    42,    43,    44,   129,   123,   151,    45,    46,
      26,   114,   115
  };

  const short
  parser::yytable_[] =
  {
      13,    38,   108,    31,    32,    35,    36,    37,     1,     2,
       3,   126,   100,   144,     4,   100,    30,    50,    51,    30,
      47,   127,     5,   109,    60,    64,   145,    61,    63,    67,
      27,    74,    28,    70,    29,     6,    30,   128,     7,     8,
      73,   113,     9,    75,    76,    77,    10,    11,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    39,    40,    41,    92,    94,    96,    97,   103,   101,
     102,   104,   105,   106,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    98,   107,   110,   122,
     124,   130,   112,   138,   139,   137,   116,   141,   143,   147,
     118,   148,   150,   152,   154,   158,   156,   111,   133,   125,
     155,   117,   119,   132,    78,   140,   159,     0,     0,     0,
     135,   136,   131,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,   146,
       0,     0,   149,    72,     0,   153,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   157,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,    68,
       0,     0,     0,     0,     0,     0,   142,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,   121,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,   120,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    95,     0,
       0,    71,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   134,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,    59,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57
  };

  const short
  parser::yycheck_[] =
  {
       0,     3,     7,     1,     1,     5,     6,     7,     3,     4,
       5,     3,    11,     7,     9,    11,    15,    18,    19,    15,
       0,    13,    17,    28,    28,     3,    20,    27,    28,     3,
       9,     3,    11,    10,    13,    30,    15,    29,    33,    34,
      28,    40,    37,     3,     3,    38,    41,    42,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    43,    44,    45,     6,    10,    20,    14,    68,    67,
      67,    71,    72,    73,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     6,     9,    20,     3,
       3,    39,    92,    10,    28,     7,    96,    40,     3,    14,
     100,     3,     6,     3,     3,     3,     7,    77,   117,   109,
      20,    98,   103,   113,    43,   127,   158,    -1,    -1,    -1,
     120,   121,   112,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,   139,
      -1,    -1,   142,    36,    -1,   145,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    12,    -1,
      -1,    31,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    12,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     9,    17,    30,    33,    34,    37,
      41,    42,    48,    49,    52,    55,    56,    57,    58,    59,
      63,    64,    65,    66,    67,    68,    77,     9,    11,    13,
      15,    78,    79,    49,    50,    49,    49,    49,     3,    43,
      44,    45,    69,    70,    71,    75,    76,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    49,    53,    49,     3,    60,    62,     3,     8,    51,
      10,    31,    36,    28,     3,     3,     3,    38,    69,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,     6,    54,    10,    12,    20,    14,     6,    61,
      11,    78,    79,    49,    49,    49,    49,     9,     7,    28,
      20,    50,    49,    40,    78,    79,    49,    62,    49,    51,
      32,    35,     3,    73,     3,    49,     3,    13,    29,    72,
      39,    54,    49,    61,    12,    49,    49,     7,    10,    28,
      73,    40,    36,     3,     7,    20,    49,    14,     3,    49,
       6,    74,     3,    49,     3,    20,     7,    49,     3,    74
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    53,    53,    54,    54,
      55,    55,    55,    55,    56,    57,    57,    57,    57,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    63,    64,
      65,    65,    66,    67,    68,    69,    69,    70,    70,    70,
      71,    72,    72,    72,    73,    73,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    78,    78,    78,    79,    79,
      79
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     3,     4,     0,     2,     0,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     2,     0,     3,     3,     6,     3,
       6,     4,     4,     8,     5,     0,     2,     1,     1,     1,
       4,     1,     3,     3,     0,     4,     0,     5,     4,     6,
       7,     9,     1,     2,     2,     2,     3,     3,     3,     4,
       4
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "ID", "STRING", "INT",
  "COMMA", "COLON", "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK",
  "LBRACE", "RBRACE", "DOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "EQ",
  "NEQ", "LT", "LE", "GT", "GE", "AND", "OR", "ASSIGN", "ARRAY", "IF",
  "THEN", "ELSE", "WHILE", "FOR", "TO", "DO", "LET", "IN", "END", "OF",
  "BREAK", "NIL", "FUNCTION", "VAR", "TYPE", "UMINUS", "$accept",
  "program", "exp", "expression_sequence", "exp_seq_tail", "function_call",
  "function_args", "function_args_tail", "arithmetic_exp", "negation_exp",
  "comparison_exp", "boolean_exp", "record_creation", "record_list",
  "record_list_extension", "record_field", "array_creation",
  "assignment_exp", "if_statement", "while_loop", "for_loop",
  "let_statement", "declaration_sequence", "declaration",
  "type_declaration", "type", "type_fields", "type_fields_extension",
  "variable_declaration", "function_declaration", "lvalue",
  "field_extension", "subscript_extension", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    82,    82,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   103,   104,   106,   107,   109,   112,   113,   115,   116,
     119,   123,   127,   131,   136,   139,   143,   147,   151,   155,
     159,   163,   167,   173,   175,   178,   179,   182,   184,   186,
     188,   190,   192,   194,   196,   198,   199,   201,   202,   203,
     205,   207,   208,   209,   211,   212,   214,   215,   217,   218,
     220,   221,   223,   224,   225,   227,   228,   229,   231,   232,
     233
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1568 "tiger.tab.cc"

#line 234 "tiger.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
