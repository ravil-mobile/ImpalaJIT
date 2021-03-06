// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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


// First part of user declarations.
#line 23 "parser.yy" // lalr1.cc:404
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>

#include <expression_nodes.h>
#include <compare_nodes.h>
#include <conditional_nodes.h>
#include <assignment_nodes.h>
#include <boolean_nodes.h>
#include <return_nodes.h>
#include <external_function_nodes.h>

#include <driver.h>
#include <scanner.h>

#line 53 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "parser.hh"

// User implementation prologue.
#line 115 "parser.yy" // lalr1.cc:412



/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 77 "parser.cc" // lalr1.cc:412


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
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 59 "parser.yy" // lalr1.cc:479
namespace impalajit {
#line 163 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 28: // function_body

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 416 "parser.cc" // lalr1.cc:614
        break;

      case 29: // return_stmt

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 423 "parser.cc" // lalr1.cc:614
        break;

      case 30: // constant

#line 112 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 430 "parser.cc" // lalr1.cc:614
        break;

      case 31: // variable

#line 112 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 437 "parser.cc" // lalr1.cc:614
        break;

      case 32: // expr_list

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.nodeVector); }
#line 444 "parser.cc" // lalr1.cc:614
        break;

      case 33: // atomexpr

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 451 "parser.cc" // lalr1.cc:614
        break;

      case 34: // unaryexpr

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 458 "parser.cc" // lalr1.cc:614
        break;

      case 35: // mulexpr

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 465 "parser.cc" // lalr1.cc:614
        break;

      case 36: // addexpr

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 472 "parser.cc" // lalr1.cc:614
        break;

      case 37: // expr

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 479 "parser.cc" // lalr1.cc:614
        break;

      case 38: // assignment

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 486 "parser.cc" // lalr1.cc:614
        break;

      case 39: // atomcondition

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 493 "parser.cc" // lalr1.cc:614
        break;

      case 40: // booleanand

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 500 "parser.cc" // lalr1.cc:614
        break;

      case 41: // booleanor

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 507 "parser.cc" // lalr1.cc:614
        break;

      case 42: // if_body

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 514 "parser.cc" // lalr1.cc:614
        break;

      case 43: // else_body

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 521 "parser.cc" // lalr1.cc:614
        break;

      case 44: // ifstmt

#line 113 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.node); }
#line 528 "parser.cc" // lalr1.cc:614
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 67 "parser.yy" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename;
}

#line 666 "parser.cc" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

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
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 130 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.functionContext) = new FunctionContext(*(yystack_[6].value.stringVal), *(yystack_[4].value.stringVector), (yystack_[1].value.node));
			}
#line 778 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 135 "parser.yy" // lalr1.cc:859
    {
				std::vector<std::string>* parameters = new std::vector<std::string>();
				(yylhs.value.stringVector) = parameters;
			}
#line 787 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 141 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.stringVector) = (yystack_[1].value.stringVector);
				(*(yylhs.value.stringVector)).push_back(*(yystack_[0].value.stringVal));
			}
#line 796 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 148 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.stringVector) = (yystack_[2].value.stringVector);
				(*(yylhs.value.stringVector)).push_back(*(yystack_[0].value.stringVal));
			}
#line 805 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 154 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new RootNode();
			}
#line 813 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 160 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 822 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 166 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[1].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[0].value.node));
			}
#line 831 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 172 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 840 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 178 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 849 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 185 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new ReturnNode((yystack_[0].value.node));
			}
#line 857 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 190 "parser.yy" // lalr1.cc:859
    {
		        (yylhs.value.node) = new ConstantNode((yystack_[0].value.doubleVal));
	   		}
#line 865 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 196 "parser.yy" // lalr1.cc:859
    {
	       		(yylhs.value.node) = new VariableNode(*(yystack_[0].value.stringVal));
	   		}
#line 873 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 202 "parser.yy" // lalr1.cc:859
    {
                std::vector<Node*>* params = new std::vector<Node*>();
                params->push_back((yystack_[0].value.node));
                (yylhs.value.nodeVector) = params;
            }
#line 883 "parser.cc" // lalr1.cc:859
    break;

  case 15:
#line 210 "parser.yy" // lalr1.cc:859
    {
                (yylhs.value.nodeVector) = (yystack_[2].value.nodeVector);
                (*(yylhs.value.nodeVector)).push_back((yystack_[0].value.node));
            }
#line 892 "parser.cc" // lalr1.cc:859
    break;

  case 16:
#line 217 "parser.yy" // lalr1.cc:859
    {
	       		(yylhs.value.node) = (yystack_[0].value.node);
		   	}
#line 900 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 222 "parser.yy" // lalr1.cc:859
    {
		       	(yylhs.value.node) = (yystack_[0].value.node);
		   	}
#line 908 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 227 "parser.yy" // lalr1.cc:859
    {
                (yylhs.value.node) = new ExternalFunctionNode(*(yystack_[2].value.stringVal));
            }
#line 916 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 232 "parser.yy" // lalr1.cc:859
    {
		       	(yylhs.value.node) = new ExternalFunctionNode(*(yystack_[3].value.stringVal), *(yystack_[1].value.nodeVector));
		   	}
#line 924 "parser.cc" // lalr1.cc:859
    break;

  case 20:
#line 237 "parser.yy" // lalr1.cc:859
    {
		       	(yylhs.value.node) = (yystack_[1].value.node);
		   	}
#line 932 "parser.cc" // lalr1.cc:859
    break;

  case 21:
#line 243 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[0].value.node);
			}
#line 940 "parser.cc" // lalr1.cc:859
    break;

  case 22:
#line 248 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[0].value.node);
			}
#line 948 "parser.cc" // lalr1.cc:859
    break;

  case 23:
#line 253 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new NegationNode((yystack_[0].value.node));
			}
#line 956 "parser.cc" // lalr1.cc:859
    break;

  case 24:
#line 258 "parser.yy" // lalr1.cc:859
    {
	      		(yylhs.value.node) = (yystack_[0].value.node);
		  	}
#line 964 "parser.cc" // lalr1.cc:859
    break;

  case 25:
#line 263 "parser.yy" // lalr1.cc:859
    {
		      	(yylhs.value.node) = new MultiplicationNode((yystack_[2].value.node), (yystack_[0].value.node));
		  	}
#line 972 "parser.cc" // lalr1.cc:859
    break;

  case 26:
#line 268 "parser.yy" // lalr1.cc:859
    {
		  	    (yylhs.value.node) = new DivisionNode((yystack_[2].value.node), (yystack_[0].value.node));
		  	}
#line 980 "parser.cc" // lalr1.cc:859
    break;

  case 27:
#line 274 "parser.yy" // lalr1.cc:859
    {
	      		(yylhs.value.node) = (yystack_[0].value.node);
		  	}
#line 988 "parser.cc" // lalr1.cc:859
    break;

  case 28:
#line 279 "parser.yy" // lalr1.cc:859
    {
		      	(yylhs.value.node) = new AdditionNode((yystack_[2].value.node), (yystack_[0].value.node));
		  	}
#line 996 "parser.cc" // lalr1.cc:859
    break;

  case 29:
#line 284 "parser.yy" // lalr1.cc:859
    {
		      	(yylhs.value.node) = new SubtractionNode((yystack_[2].value.node), (yystack_[0].value.node));
		  	}
#line 1004 "parser.cc" // lalr1.cc:859
    break;

  case 30:
#line 290 "parser.yy" // lalr1.cc:859
    {
	      		(yylhs.value.node) = (yystack_[0].value.node);
	  		}
#line 1012 "parser.cc" // lalr1.cc:859
    break;

  case 31:
#line 298 "parser.yy" // lalr1.cc:859
    {
		 		(yylhs.value.node) = new AssignmentNode(*(yystack_[2].value.stringVal), (yystack_[0].value.node));
	     	}
#line 1020 "parser.cc" // lalr1.cc:859
    break;

  case 32:
#line 304 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new CompareNode((yystack_[2].value.node), (yystack_[0].value.node), static_cast<CompareOperatorType>((yystack_[1].value.integerVal)));
			}
#line 1028 "parser.cc" // lalr1.cc:859
    break;

  case 33:
#line 309 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[1].value.node);
			}
#line 1036 "parser.cc" // lalr1.cc:859
    break;

  case 34:
#line 315 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[0].value.node);
			}
#line 1044 "parser.cc" // lalr1.cc:859
    break;

  case 35:
#line 320 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new BooleanAndNode();
				((yylhs.value.node)->nodes).push_back((yystack_[2].value.node));
				((yylhs.value.node)->nodes).push_back((yystack_[0].value.node));
			}
#line 1054 "parser.cc" // lalr1.cc:859
    break;

  case 36:
#line 327 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[0].value.node);
			}
#line 1062 "parser.cc" // lalr1.cc:859
    break;

  case 37:
#line 332 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new BooleanOrNode();
				((yylhs.value.node)->nodes).push_back((yystack_[2].value.node));
				((yylhs.value.node)->nodes).push_back((yystack_[0].value.node));
			}
#line 1072 "parser.cc" // lalr1.cc:859
    break;

  case 38:
#line 340 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new IfBodyNode();
			}
#line 1080 "parser.cc" // lalr1.cc:859
    break;

  case 39:
#line 346 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 1089 "parser.cc" // lalr1.cc:859
    break;

  case 40:
#line 352 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[1].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[0].value.node));
			}
#line 1098 "parser.cc" // lalr1.cc:859
    break;

  case 41:
#line 358 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 1107 "parser.cc" // lalr1.cc:859
    break;

  case 42:
#line 364 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 1116 "parser.cc" // lalr1.cc:859
    break;

  case 43:
#line 370 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new ElseBodyNode();
			}
#line 1124 "parser.cc" // lalr1.cc:859
    break;

  case 44:
#line 376 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 1133 "parser.cc" // lalr1.cc:859
    break;

  case 45:
#line 382 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[1].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[0].value.node));
			}
#line 1142 "parser.cc" // lalr1.cc:859
    break;

  case 46:
#line 388 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 1151 "parser.cc" // lalr1.cc:859
    break;

  case 47:
#line 394 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = (yystack_[2].value.node);
				((yylhs.value.node)->nodes).push_back((yystack_[1].value.node));
			}
#line 1160 "parser.cc" // lalr1.cc:859
    break;

  case 48:
#line 402 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new IfStmtNode((yystack_[4].value.node), (yystack_[1].value.node));
			}
#line 1168 "parser.cc" // lalr1.cc:859
    break;

  case 49:
#line 407 "parser.yy" // lalr1.cc:859
    {
				(yylhs.value.node) = new IfElseStmtNode((yystack_[8].value.node), (yystack_[5].value.node), (yystack_[1].value.node));
			}
#line 1176 "parser.cc" // lalr1.cc:859
    break;

  case 50:
#line 413 "parser.yy" // lalr1.cc:859
    {
				driver.setFunctionContext((yystack_[1].value.functionContext));
		  	}
#line 1184 "parser.cc" // lalr1.cc:859
    break;


#line 1188 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -75;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       9,     8,    33,    45,   -75,   -75,   -75,    -4,   -75,    41,
      54,   -75,   -75,     2,   -75,    13,    35,    50,    50,   -75,
      26,    26,    61,   -75,   -75,   -75,   -75,    57,    65,    63,
      70,   -75,    44,    50,    62,    47,   -75,    74,   -75,   -75,
     -75,    50,    50,    50,    50,   -75,   -75,   -75,    17,   -75,
     -75,    62,    82,   -75,    84,    59,   -75,   -75,   -75,    57,
      57,    50,   -75,    -6,    64,    50,    62,    62,    78,   -75,
     -75,   -75,   -75,    84,   -75,    20,    88,    85,    86,    87,
     -75,    80,   -75,   -75,   -75,   -75,    38,   -75,    89,    90,
      91,   -75,   -75,   -75,   -75
  };

  const unsigned char
  Parser::yydefact_[] =
  {
       0,     0,     0,     0,     3,    50,     1,     0,     4,     0,
       0,     5,     6,     0,    12,    13,     0,     0,     0,     2,
       0,     0,     0,    16,    17,    21,    24,    27,    30,     0,
       0,     8,     0,     0,     0,    13,    11,     0,    22,    23,
      10,     0,     0,     0,     0,     7,     9,    18,     0,    14,
      31,     0,     0,    34,    36,     0,    20,    25,    26,    28,
      29,     0,    19,     0,     0,     0,     0,     0,     0,    15,
      33,    32,    35,    37,    38,     0,    48,     0,     0,     0,
      40,     0,    42,    39,    41,    43,     0,    49,     0,     0,
       0,    45,    47,    44,    46
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -75,   -75,   -75,   -75,   -74,   -75,   -75,   -75,    67,    48,
      49,   -75,   -13,   -72,    36,    39,    56,   -75,   -75,   -59,
     -75
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     2,     7,    13,    22,    23,    24,    48,    25,    26,
      27,    28,    52,    30,    53,    54,    55,    75,    86,    31,
       3
  };

  const unsigned char
  Parser::yytable_[] =
  {
      29,    77,     8,    79,    36,    37,    65,    14,    15,     9,
      16,    56,    88,    10,    90,     1,    80,    17,    18,    49,
      50,    19,    20,    21,     4,    14,    15,    91,    16,    32,
      61,    14,    35,     5,    62,    17,    18,    33,    63,    76,
      20,    21,    18,    14,    15,     6,    16,    11,    69,    14,
      35,    34,    71,    17,    18,    14,    35,    87,    20,    21,
      18,    47,    78,    32,    20,    21,    18,    14,    35,    67,
      20,    21,    12,    89,    67,    40,    68,    45,    51,    41,
      42,    70,    20,    21,    46,    43,    44,    38,    39,    57,
      58,    56,    59,    60,    65,    66,    74,    81,    85,    82,
      83,    84,    72,    92,    93,    94,    73,    64
  };

  const unsigned char
  Parser::yycheck_[] =
  {
      13,    75,     6,    75,    17,    18,    12,     5,     6,    13,
       8,    17,    86,    17,    86,     6,    75,    15,    16,    32,
      33,    19,    20,    21,    16,     5,     6,    86,     8,    16,
      13,     5,     6,     0,    17,    15,    16,    24,    51,    19,
      20,    21,    16,     5,     6,     0,     8,     6,    61,     5,
       6,    16,    65,    15,    16,     5,     6,    19,    20,    21,
      16,    17,    75,    16,    20,    21,    16,     5,     6,    10,
      20,    21,    18,    86,    10,    14,    17,    14,    16,    22,
      23,    17,    20,    21,    14,    20,    21,    20,    21,    41,
      42,    17,    43,    44,    12,    11,    18,     9,    18,    14,
      14,    14,    66,    14,    14,    14,    67,    51
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,     6,    26,    45,    16,     0,     0,    27,     6,    13,
      17,     6,    18,    28,     5,     6,     8,    15,    16,    19,
      20,    21,    29,    30,    31,    33,    34,    35,    36,    37,
      38,    44,    16,    24,    16,     6,    37,    37,    33,    33,
      14,    22,    23,    20,    21,    14,    14,    17,    32,    37,
      37,    16,    37,    39,    40,    41,    17,    34,    34,    35,
      35,    13,    17,    37,    41,    12,    11,    10,    17,    37,
      17,    37,    39,    40,    18,    42,    19,    29,    37,    38,
      44,     9,    14,    14,    14,    18,    43,    19,    29,    37,
      38,    44,    14,    14,    14
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,    25,    26,    27,    27,    27,    28,    28,    28,    28,
      28,    29,    30,    31,    32,    32,    33,    33,    33,    33,
      33,    34,    34,    34,    35,    35,    35,    36,    36,    36,
      37,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      42,    42,    42,    43,    43,    43,    43,    43,    44,    44,
      45
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     7,     0,     2,     3,     0,     3,     2,     3,
       3,     2,     1,     1,     1,     3,     1,     1,     3,     4,
       3,     1,     2,     2,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     3,     0,     3,
       2,     3,     3,     0,     3,     2,     3,     3,     7,    11,
       2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"integer\"", "\"double\"", "\"string\"", "\"function\"",
  "\"if block\"", "\"else block\"", "\"|| operator\"", "\"&& operator\"",
  "\"compare operator\"", "\",\"", "\";\"", "\"return value\"", "'('",
  "')'", "'{'", "'}'", "'+'", "'-'", "'*'", "'/'", "'='", "$accept",
  "function", "parameter_list", "function_body", "return_stmt", "constant",
  "variable", "expr_list", "atomexpr", "unaryexpr", "mulexpr", "addexpr",
  "expr", "assignment", "atomcondition", "booleanand", "booleanor",
  "if_body", "else_body", "ifstmt", "start", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  Parser::yyrline_[] =
  {
       0,   129,   129,   134,   140,   147,   153,   159,   165,   171,
     177,   184,   189,   195,   201,   209,   216,   221,   226,   231,
     236,   242,   247,   252,   257,   262,   267,   273,   278,   283,
     289,   297,   303,   308,   314,   319,   326,   331,   339,   345,
     351,   357,   363,   369,   375,   381,   387,   393,   401,   406,
     412
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      16,    17,    22,    20,     2,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,     2,    19,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
    };
    const unsigned int user_token_number_max_ = 270;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 59 "parser.yy" // lalr1.cc:1167
} // impalajit
#line 1672 "parser.cc" // lalr1.cc:1167
#line 417 "parser.yy" // lalr1.cc:1168
 /*** Additional Code ***/


void impalajit::Parser::error(const Parser::location_type& l,
							  const std::string& m)
{
	driver.error(l, m);
}
