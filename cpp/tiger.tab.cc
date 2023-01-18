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
      case symbol_kind::S_exp: // exp
        value.YY_MOVE_OR_COPY< AST::ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_extension: // field_extension
        value.YY_MOVE_OR_COPY< AST::FieldVariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        value.YY_MOVE_OR_COPY< AST::SubscriptVariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.YY_MOVE_OR_COPY< AST::VariablePtr > (YY_MOVE (that.value));
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
      case symbol_kind::S_exp: // exp
        value.move< AST::ExpressionPtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_field_extension: // field_extension
        value.move< AST::FieldVariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        value.move< AST::SubscriptVariablePtr > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< AST::VariablePtr > (YY_MOVE (that.value));
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
      case symbol_kind::S_exp: // exp
        value.copy< AST::ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_field_extension: // field_extension
        value.copy< AST::FieldVariablePtr > (that.value);
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        value.copy< AST::SubscriptVariablePtr > (that.value);
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.copy< AST::VariablePtr > (that.value);
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
      case symbol_kind::S_exp: // exp
        value.move< AST::ExpressionPtr > (that.value);
        break;

      case symbol_kind::S_field_extension: // field_extension
        value.move< AST::FieldVariablePtr > (that.value);
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        value.move< AST::SubscriptVariablePtr > (that.value);
        break;

      case symbol_kind::S_lvalue: // lvalue
        value.move< AST::VariablePtr > (that.value);
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
      case symbol_kind::S_exp: // exp
        yylhs.value.emplace< AST::ExpressionPtr > ();
        break;

      case symbol_kind::S_field_extension: // field_extension
        yylhs.value.emplace< AST::FieldVariablePtr > ();
        break;

      case symbol_kind::S_subscript_extension: // subscript_extension
        yylhs.value.emplace< AST::SubscriptVariablePtr > ();
        break;

      case symbol_kind::S_lvalue: // lvalue
        yylhs.value.emplace< AST::VariablePtr > ();
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
#line 74 "tiger.yy"
             {absyn_root = yystack_[0].value.as < AST::ExpressionPtr > ();}
#line 672 "tiger.tab.cc"
    break;

  case 3: // exp: INT
#line 76 "tiger.yy"
         {yylhs.value.as < AST::ExpressionPtr > () = AST::IntExpression::Node(drv.location.begin.line, yystack_[0].value.as < int > ());}
#line 678 "tiger.tab.cc"
    break;

  case 71: // lvalue: ID
#line 176 "tiger.yy"
           {yylhs.value.as < AST::VariablePtr > () = AST::SimpleVariable::Node(0, AST::Symbol::Gen(yystack_[0].value.as < std::string > ()));}
#line 684 "tiger.tab.cc"
    break;

  case 72: // lvalue: ID field_extension
#line 177 "tiger.yy"
                           {yylhs.value.as < AST::VariablePtr > () = AST::SimpleVariable::Node(0, AST::Symbol::Gen(yystack_[1].value.as < std::string > ())); yystack_[0].value.as < AST::FieldVariablePtr > ()->set_var(yylhs.value.as < AST::VariablePtr > ());}
#line 690 "tiger.tab.cc"
    break;

  case 73: // lvalue: ID subscript_extension
#line 178 "tiger.yy"
                               {yylhs.value.as < AST::VariablePtr > () = AST::SimpleVariable::Node(0, AST::Symbol::Gen(yystack_[1].value.as < std::string > ())); yystack_[0].value.as < AST::SubscriptVariablePtr > ()->set_var(yylhs.value.as < AST::VariablePtr > ());}
#line 696 "tiger.tab.cc"
    break;

  case 74: // field_extension: DOT ID
#line 180 "tiger.yy"
                         {yylhs.value.as < AST::FieldVariablePtr > () = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen(yystack_[0].value.as < std::string > ())); }
#line 702 "tiger.tab.cc"
    break;

  case 75: // field_extension: DOT ID field_extension
#line 181 "tiger.yy"
                                        {yylhs.value.as < AST::FieldVariablePtr > () = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen(yystack_[1].value.as < std::string > ())); yystack_[0].value.as < AST::FieldVariablePtr > ()->set_var(yylhs.value.as < AST::FieldVariablePtr > ());}
#line 708 "tiger.tab.cc"
    break;

  case 76: // field_extension: DOT ID subscript_extension
#line 182 "tiger.yy"
                                            {yylhs.value.as < AST::FieldVariablePtr > () = AST::FieldVariable::PartialNode(0, AST::Symbol::Gen(yystack_[1].value.as < std::string > ())); yystack_[0].value.as < AST::SubscriptVariablePtr > ()->set_var(yylhs.value.as < AST::FieldVariablePtr > ());}
#line 714 "tiger.tab.cc"
    break;

  case 77: // subscript_extension: LBRACK exp RBRACK
#line 184 "tiger.yy"
                                        {yylhs.value.as < AST::SubscriptVariablePtr > () = AST::SubscriptVariable::PartialNode(0, yystack_[1].value.as < AST::ExpressionPtr > ());}
#line 720 "tiger.tab.cc"
    break;

  case 78: // subscript_extension: LBRACK exp RBRACK field_extension
#line 185 "tiger.yy"
                                                       {yylhs.value.as < AST::SubscriptVariablePtr > () = AST::SubscriptVariable::PartialNode(0,yystack_[2].value.as < AST::ExpressionPtr > ()); yystack_[0].value.as < AST::FieldVariablePtr > ()->set_var(yylhs.value.as < AST::SubscriptVariablePtr > ());}
#line 726 "tiger.tab.cc"
    break;

  case 79: // subscript_extension: LBRACK exp RBRACK subscript_extension
#line 186 "tiger.yy"
                                                           {yylhs.value.as < AST::SubscriptVariablePtr > () = AST::SubscriptVariable::PartialNode(0,yystack_[2].value.as < AST::ExpressionPtr > ()); yystack_[0].value.as < AST::SubscriptVariablePtr > ()->set_var(yylhs.value.as < AST::SubscriptVariablePtr > ());}
#line 732 "tiger.tab.cc"
    break;


#line 736 "tiger.tab.cc"

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









  const signed char parser::yypact_ninf_ = -40;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
       5,    21,   -40,   -40,     5,     5,     5,     5,    -2,    42,
     -40,   -40,    20,   275,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -40,   -40,    -4,     5,     5,    22,
      26,   -40,   -40,   182,    23,   -40,   231,   140,    12,    28,
      40,    41,     7,    42,   -40,   -40,   -40,   -40,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
       5,    57,    51,   247,    44,    48,     4,     5,   -40,   -40,
       5,     5,     5,    56,    -5,    46,     5,   -40,    -1,    -1,
     -40,   -40,   299,   299,   299,   299,   299,   299,   287,   309,
     275,     5,   -40,   -40,     1,     5,   -40,     5,   -40,   -40,
     182,   214,   275,   194,    85,    86,     5,     8,    53,    57,
       5,   -40,   -40,   102,   263,   -40,     5,     5,    83,    84,
      65,   275,   -40,    85,    58,   -40,   -40,   -40,   299,    93,
     -40,     4,   275,   161,    96,     6,     5,    87,    97,    82,
       5,    98,   100,     5,   275,   -40,   -40,     5,   275,   104,
     -40,    89,   275,   102,   105,     5,   -40,   108,   275,    98,
     -40
  };

  const signed char
  parser::yydefact_[] =
  {
       0,    71,     6,     3,    21,     0,     0,     0,     0,    54,
       7,     5,     0,     2,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     4,    26,     0,     0,
       0,    72,    73,    23,     0,    34,     0,     0,     0,     0,
       0,     0,     0,    54,    56,    57,    58,     1,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,     0,     0,     0,    74,     0,    22,     8,
       0,     0,     0,     0,     0,     0,    21,    55,    30,    31,
      32,    33,    35,    36,    39,    40,    37,    38,    41,    42,
      48,     0,    27,    25,    77,     0,    43,     0,    75,    76,
      23,    50,    51,     0,    63,     0,     0,     0,     0,    28,
       0,    78,    79,    45,     0,    24,     0,     0,     0,     0,
       0,    67,    60,    63,     0,    59,    53,    29,    47,     0,
      44,    77,    49,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,    68,    61,    62,     0,    52,     0,
      64,     0,    69,    45,     0,     0,    46,     0,    70,    65,
      66
  };

  const signed char
  parser::yypgoto_[] =
  {
     -40,   -40,     0,    29,    13,   -40,   -40,    24,   -40,   -40,
     -40,   -40,   -40,   -40,   -39,   -40,   -40,   -40,   -40,   -40,
     -40,    72,   -40,   -40,   -40,     9,   -29,   -40,   -40,   -40,
       2,     3
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,    12,    33,    34,    68,    14,    62,    92,    15,    16,
      17,    18,    19,    65,   130,    20,    21,    22,    23,    24,
      25,    42,    43,    44,   125,   119,   150,    45,    46,    26,
     111,   112
  };

  const short
  parser::yytable_[] =
  {
      13,    38,   105,    31,    32,    35,    36,    37,     1,     2,
       3,   122,    97,   142,     4,    97,    30,    50,    51,    30,
      47,   123,     5,   106,    60,    64,   143,    61,    63,    66,
      27,    73,    28,    69,    29,     6,    30,   124,     7,     8,
      72,   110,     9,    74,    75,    76,    10,    11,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    93,    96,    91,    95,   104,   107,   100,    98,    99,
     101,   102,   103,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    39,    40,    41,   118,   120,
     134,   109,   126,   136,   135,   113,   139,   114,   138,   141,
     146,   145,   147,   151,   149,   108,   121,   154,   129,   155,
     128,   159,   157,   115,   156,    77,   132,   133,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
     160,     0,   137,   127,     0,     0,   144,     0,     0,     0,
     148,     0,     0,   152,     0,     0,     0,   153,     0,     0,
       0,     0,     0,     0,     0,   158,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,    71,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     0,
      67,     0,     0,     0,     0,     0,     0,   140,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,     0,   117,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     0,     0,     0,     0,   116,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    94,
       0,     0,    70,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,   131,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,    59,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57
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
      60,    10,    14,     6,    20,     9,    20,    67,    66,    66,
      70,    71,    72,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    43,    44,    45,     3,     3,
       7,    91,    39,    28,    10,    95,     3,    97,    40,     3,
       3,    14,    20,     3,     6,    76,   106,     3,     6,    20,
     110,     3,     7,   100,   153,    43,   116,   117,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     159,    -1,   123,   109,    -1,    -1,   136,    -1,    -1,    -1,
     140,    -1,    -1,   143,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    36,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    32,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    12,
      -1,    -1,    31,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    12,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     9,    17,    30,    33,    34,    37,
      41,    42,    48,    49,    52,    55,    56,    57,    58,    59,
      62,    63,    64,    65,    66,    67,    76,     9,    11,    13,
      15,    77,    78,    49,    50,    49,    49,    49,     3,    43,
      44,    45,    68,    69,    70,    74,    75,     0,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    49,    53,    49,     3,    60,     3,     8,    51,    10,
      31,    36,    28,     3,     3,     3,    38,    68,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,     6,    54,    10,    12,    20,    14,    11,    77,    78,
      49,    49,    49,    49,     9,     7,    28,    20,    50,    49,
      40,    77,    78,    49,    49,    51,    32,    35,     3,    72,
       3,    49,     3,    13,    29,    71,    39,    54,    49,     6,
      61,    12,    49,    49,     7,    10,    28,    72,    40,     3,
      36,     3,     7,    20,    49,    14,     3,    20,    49,     6,
      73,     3,    49,    49,     3,    20,    61,     7,    49,     3,
      73
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    53,    53,    54,    54,
      55,    55,    55,    55,    56,    57,    57,    57,    57,    57,
      57,    58,    58,    59,    60,    61,    61,    62,    63,    64,
      64,    65,    66,    67,    68,    68,    69,    69,    69,    70,
      71,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    77,    77,    77,    78,    78,    78
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     3,     4,     0,     2,     0,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     0,     5,     6,     3,     6,
       4,     4,     8,     5,     0,     2,     1,     1,     1,     4,
       1,     3,     3,     0,     4,     0,     5,     4,     6,     7,
       9,     1,     2,     2,     2,     3,     3,     3,     4,     4
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
  "record_list_extension", "array_creation", "assignment_exp",
  "if_statement", "while_loop", "for_loop", "let_statement",
  "declaration_sequence", "declaration", "type_declaration", "type",
  "type_fields", "type_fields_extension", "variable_declaration",
  "function_declaration", "lvalue", "field_extension",
  "subscript_extension", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    74,    74,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    95,    96,    98,    99,   101,   103,   104,   106,   107,
     110,   111,   112,   113,   115,   117,   118,   119,   120,   121,
     122,   124,   125,   128,   130,   132,   133,   136,   139,   141,
     143,   145,   147,   149,   151,   152,   154,   155,   156,   158,
     160,   161,   162,   164,   165,   167,   168,   170,   171,   173,
     174,   176,   177,   178,   180,   181,   182,   184,   185,   186
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
#line 1190 "tiger.tab.cc"

#line 187 "tiger.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
