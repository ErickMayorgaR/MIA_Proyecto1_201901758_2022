// A Bison parser, made by GNU Bison 3.8.2.

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





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 24 "parser.yy"

#include "driver.h"
#include "../Utils/Builder.h"
#include "../Utils/CommandHandler.cpp"
#include <iostream>
#include <vector>

std::vector<parameter> parameters;
struct command x;


#line 58 "parser.tab.cc"


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

#line 6 "parser.yy"
namespace yy {
#line 151 "parser.tab.cc"

  /// Build a parser object.
  class_parser::class_parser (parser_driver& driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  class_parser::~class_parser ()
  {}

  class_parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  class_parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  class_parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  class_parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  class_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  class_parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  class_parser::symbol_kind_type
  class_parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  class_parser::stack_symbol_type::stack_symbol_type ()
  {}

  class_parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_EQUAL: // "tk_EQUAL"
      case symbol_kind::S_FIT: // "_FIT"
      case symbol_kind::S_UNIT: // "_UNIT"
      case symbol_kind::S_PATH: // "_PATH"
      case symbol_kind::S_SIZE: // "_SIZE"
      case symbol_kind::S_TYPE: // "_TYPE"
      case symbol_kind::S_TYPE2: // "_TYPE2"
      case symbol_kind::S_DELETE: // "_DELETE"
      case symbol_kind::S_NAME: // "_NAME"
      case symbol_kind::S_ADD: // "_ADD"
      case symbol_kind::S_ID: // "_ID"
      case symbol_kind::S_FS: // "_FS"
      case symbol_kind::S_LOGIN: // "_login"
      case symbol_kind::S_LOGOUT: // "_logout"
      case symbol_kind::S_MKGRP: // "_MKGRP"
      case symbol_kind::S_RMGRP: // "_RMGRP"
      case symbol_kind::S_MKUSR: // "_MKUSR"
      case symbol_kind::S_RMUSR: // "_RMUSR"
      case symbol_kind::S_CHGRP: // "_CHGRP"
      case symbol_kind::S_USER: // "_USER"
      case symbol_kind::S_PWD: // "_PWD"
      case symbol_kind::S_GRP: // "_GRP"
      case symbol_kind::S_MKFILE: // "_MKFILE"
      case symbol_kind::S_CHOWN: // "_CHOWN"
      case symbol_kind::S_CHMOD: // "_CHMOD"
      case symbol_kind::S_CAT: // "_CAT"
      case symbol_kind::S_RM: // "_RM"
      case symbol_kind::S_EDIT: // "_EDIT"
      case symbol_kind::S_REN: // "_REN"
      case symbol_kind::S_MV: // "_MV"
      case symbol_kind::S_CP: // "_CP"
      case symbol_kind::S_MKDIR: // "_MKDIR"
      case symbol_kind::S_FIND: // "_FIND"
      case symbol_kind::S_LOSS: // "_LOSS"
      case symbol_kind::S_RECOVERY: // "_RECOVERY"
      case symbol_kind::S_R: // "_R"
      case symbol_kind::S_FILEN: // "_FILEN"
      case symbol_kind::S_DEST: // "_DEST"
      case symbol_kind::S_P: // "_P"
      case symbol_kind::S_CONT: // "_CONT"
      case symbol_kind::S_UGO: // "_UGO"
      case symbol_kind::S_STDIN: // "_STDIN"
      case symbol_kind::S_RUTA: // "_RUTA"
      case symbol_kind::S_MKDISK: // "_MKDISK"
      case symbol_kind::S_RMDISK: // "_RMDISK"
      case symbol_kind::S_FDISK: // "_FDISK"
      case symbol_kind::S_MOUNT: // "_MOUNT"
      case symbol_kind::S_UMOUNT: // "_UMOUNT"
      case symbol_kind::S_MKFS: // "_MKFS"
      case symbol_kind::S_STRING_DOUBLE: // "tk_string_d"
      case symbol_kind::S_STRING_SINGLE: // "tk_string_s"
      case symbol_kind::S_PATH_DIR: // "tk_path"
      case symbol_kind::S_RUN_EXEC: // "_exec"
      case symbol_kind::S_RUN_REPORT: // "_rep"
      case symbol_kind::S_IDENTIFICADOR: // "tk_identifier"
      case symbol_kind::S_PATTERN: // "tk_pattern"
      case symbol_kind::S_NUMERO: // "tk_number"
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DATA: // DATA
      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_BOOLEAN_PARAM: // BOOLEAN_PARAM
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

  class_parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_EQUAL: // "tk_EQUAL"
      case symbol_kind::S_FIT: // "_FIT"
      case symbol_kind::S_UNIT: // "_UNIT"
      case symbol_kind::S_PATH: // "_PATH"
      case symbol_kind::S_SIZE: // "_SIZE"
      case symbol_kind::S_TYPE: // "_TYPE"
      case symbol_kind::S_TYPE2: // "_TYPE2"
      case symbol_kind::S_DELETE: // "_DELETE"
      case symbol_kind::S_NAME: // "_NAME"
      case symbol_kind::S_ADD: // "_ADD"
      case symbol_kind::S_ID: // "_ID"
      case symbol_kind::S_FS: // "_FS"
      case symbol_kind::S_LOGIN: // "_login"
      case symbol_kind::S_LOGOUT: // "_logout"
      case symbol_kind::S_MKGRP: // "_MKGRP"
      case symbol_kind::S_RMGRP: // "_RMGRP"
      case symbol_kind::S_MKUSR: // "_MKUSR"
      case symbol_kind::S_RMUSR: // "_RMUSR"
      case symbol_kind::S_CHGRP: // "_CHGRP"
      case symbol_kind::S_USER: // "_USER"
      case symbol_kind::S_PWD: // "_PWD"
      case symbol_kind::S_GRP: // "_GRP"
      case symbol_kind::S_MKFILE: // "_MKFILE"
      case symbol_kind::S_CHOWN: // "_CHOWN"
      case symbol_kind::S_CHMOD: // "_CHMOD"
      case symbol_kind::S_CAT: // "_CAT"
      case symbol_kind::S_RM: // "_RM"
      case symbol_kind::S_EDIT: // "_EDIT"
      case symbol_kind::S_REN: // "_REN"
      case symbol_kind::S_MV: // "_MV"
      case symbol_kind::S_CP: // "_CP"
      case symbol_kind::S_MKDIR: // "_MKDIR"
      case symbol_kind::S_FIND: // "_FIND"
      case symbol_kind::S_LOSS: // "_LOSS"
      case symbol_kind::S_RECOVERY: // "_RECOVERY"
      case symbol_kind::S_R: // "_R"
      case symbol_kind::S_FILEN: // "_FILEN"
      case symbol_kind::S_DEST: // "_DEST"
      case symbol_kind::S_P: // "_P"
      case symbol_kind::S_CONT: // "_CONT"
      case symbol_kind::S_UGO: // "_UGO"
      case symbol_kind::S_STDIN: // "_STDIN"
      case symbol_kind::S_RUTA: // "_RUTA"
      case symbol_kind::S_MKDISK: // "_MKDISK"
      case symbol_kind::S_RMDISK: // "_RMDISK"
      case symbol_kind::S_FDISK: // "_FDISK"
      case symbol_kind::S_MOUNT: // "_MOUNT"
      case symbol_kind::S_UMOUNT: // "_UMOUNT"
      case symbol_kind::S_MKFS: // "_MKFS"
      case symbol_kind::S_STRING_DOUBLE: // "tk_string_d"
      case symbol_kind::S_STRING_SINGLE: // "tk_string_s"
      case symbol_kind::S_PATH_DIR: // "tk_path"
      case symbol_kind::S_RUN_EXEC: // "_exec"
      case symbol_kind::S_RUN_REPORT: // "_rep"
      case symbol_kind::S_IDENTIFICADOR: // "tk_identifier"
      case symbol_kind::S_PATTERN: // "tk_pattern"
      case symbol_kind::S_NUMERO: // "tk_number"
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DATA: // DATA
      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_BOOLEAN_PARAM: // BOOLEAN_PARAM
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  class_parser::stack_symbol_type&
  class_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_EQUAL: // "tk_EQUAL"
      case symbol_kind::S_FIT: // "_FIT"
      case symbol_kind::S_UNIT: // "_UNIT"
      case symbol_kind::S_PATH: // "_PATH"
      case symbol_kind::S_SIZE: // "_SIZE"
      case symbol_kind::S_TYPE: // "_TYPE"
      case symbol_kind::S_TYPE2: // "_TYPE2"
      case symbol_kind::S_DELETE: // "_DELETE"
      case symbol_kind::S_NAME: // "_NAME"
      case symbol_kind::S_ADD: // "_ADD"
      case symbol_kind::S_ID: // "_ID"
      case symbol_kind::S_FS: // "_FS"
      case symbol_kind::S_LOGIN: // "_login"
      case symbol_kind::S_LOGOUT: // "_logout"
      case symbol_kind::S_MKGRP: // "_MKGRP"
      case symbol_kind::S_RMGRP: // "_RMGRP"
      case symbol_kind::S_MKUSR: // "_MKUSR"
      case symbol_kind::S_RMUSR: // "_RMUSR"
      case symbol_kind::S_CHGRP: // "_CHGRP"
      case symbol_kind::S_USER: // "_USER"
      case symbol_kind::S_PWD: // "_PWD"
      case symbol_kind::S_GRP: // "_GRP"
      case symbol_kind::S_MKFILE: // "_MKFILE"
      case symbol_kind::S_CHOWN: // "_CHOWN"
      case symbol_kind::S_CHMOD: // "_CHMOD"
      case symbol_kind::S_CAT: // "_CAT"
      case symbol_kind::S_RM: // "_RM"
      case symbol_kind::S_EDIT: // "_EDIT"
      case symbol_kind::S_REN: // "_REN"
      case symbol_kind::S_MV: // "_MV"
      case symbol_kind::S_CP: // "_CP"
      case symbol_kind::S_MKDIR: // "_MKDIR"
      case symbol_kind::S_FIND: // "_FIND"
      case symbol_kind::S_LOSS: // "_LOSS"
      case symbol_kind::S_RECOVERY: // "_RECOVERY"
      case symbol_kind::S_R: // "_R"
      case symbol_kind::S_FILEN: // "_FILEN"
      case symbol_kind::S_DEST: // "_DEST"
      case symbol_kind::S_P: // "_P"
      case symbol_kind::S_CONT: // "_CONT"
      case symbol_kind::S_UGO: // "_UGO"
      case symbol_kind::S_STDIN: // "_STDIN"
      case symbol_kind::S_RUTA: // "_RUTA"
      case symbol_kind::S_MKDISK: // "_MKDISK"
      case symbol_kind::S_RMDISK: // "_RMDISK"
      case symbol_kind::S_FDISK: // "_FDISK"
      case symbol_kind::S_MOUNT: // "_MOUNT"
      case symbol_kind::S_UMOUNT: // "_UMOUNT"
      case symbol_kind::S_MKFS: // "_MKFS"
      case symbol_kind::S_STRING_DOUBLE: // "tk_string_d"
      case symbol_kind::S_STRING_SINGLE: // "tk_string_s"
      case symbol_kind::S_PATH_DIR: // "tk_path"
      case symbol_kind::S_RUN_EXEC: // "_exec"
      case symbol_kind::S_RUN_REPORT: // "_rep"
      case symbol_kind::S_IDENTIFICADOR: // "tk_identifier"
      case symbol_kind::S_PATTERN: // "tk_pattern"
      case symbol_kind::S_NUMERO: // "tk_number"
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DATA: // DATA
      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_BOOLEAN_PARAM: // BOOLEAN_PARAM
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  class_parser::stack_symbol_type&
  class_parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_EQUAL: // "tk_EQUAL"
      case symbol_kind::S_FIT: // "_FIT"
      case symbol_kind::S_UNIT: // "_UNIT"
      case symbol_kind::S_PATH: // "_PATH"
      case symbol_kind::S_SIZE: // "_SIZE"
      case symbol_kind::S_TYPE: // "_TYPE"
      case symbol_kind::S_TYPE2: // "_TYPE2"
      case symbol_kind::S_DELETE: // "_DELETE"
      case symbol_kind::S_NAME: // "_NAME"
      case symbol_kind::S_ADD: // "_ADD"
      case symbol_kind::S_ID: // "_ID"
      case symbol_kind::S_FS: // "_FS"
      case symbol_kind::S_LOGIN: // "_login"
      case symbol_kind::S_LOGOUT: // "_logout"
      case symbol_kind::S_MKGRP: // "_MKGRP"
      case symbol_kind::S_RMGRP: // "_RMGRP"
      case symbol_kind::S_MKUSR: // "_MKUSR"
      case symbol_kind::S_RMUSR: // "_RMUSR"
      case symbol_kind::S_CHGRP: // "_CHGRP"
      case symbol_kind::S_USER: // "_USER"
      case symbol_kind::S_PWD: // "_PWD"
      case symbol_kind::S_GRP: // "_GRP"
      case symbol_kind::S_MKFILE: // "_MKFILE"
      case symbol_kind::S_CHOWN: // "_CHOWN"
      case symbol_kind::S_CHMOD: // "_CHMOD"
      case symbol_kind::S_CAT: // "_CAT"
      case symbol_kind::S_RM: // "_RM"
      case symbol_kind::S_EDIT: // "_EDIT"
      case symbol_kind::S_REN: // "_REN"
      case symbol_kind::S_MV: // "_MV"
      case symbol_kind::S_CP: // "_CP"
      case symbol_kind::S_MKDIR: // "_MKDIR"
      case symbol_kind::S_FIND: // "_FIND"
      case symbol_kind::S_LOSS: // "_LOSS"
      case symbol_kind::S_RECOVERY: // "_RECOVERY"
      case symbol_kind::S_R: // "_R"
      case symbol_kind::S_FILEN: // "_FILEN"
      case symbol_kind::S_DEST: // "_DEST"
      case symbol_kind::S_P: // "_P"
      case symbol_kind::S_CONT: // "_CONT"
      case symbol_kind::S_UGO: // "_UGO"
      case symbol_kind::S_STDIN: // "_STDIN"
      case symbol_kind::S_RUTA: // "_RUTA"
      case symbol_kind::S_MKDISK: // "_MKDISK"
      case symbol_kind::S_RMDISK: // "_RMDISK"
      case symbol_kind::S_FDISK: // "_FDISK"
      case symbol_kind::S_MOUNT: // "_MOUNT"
      case symbol_kind::S_UMOUNT: // "_UMOUNT"
      case symbol_kind::S_MKFS: // "_MKFS"
      case symbol_kind::S_STRING_DOUBLE: // "tk_string_d"
      case symbol_kind::S_STRING_SINGLE: // "tk_string_s"
      case symbol_kind::S_PATH_DIR: // "tk_path"
      case symbol_kind::S_RUN_EXEC: // "_exec"
      case symbol_kind::S_RUN_REPORT: // "_rep"
      case symbol_kind::S_IDENTIFICADOR: // "tk_identifier"
      case symbol_kind::S_PATTERN: // "tk_pattern"
      case symbol_kind::S_NUMERO: // "tk_number"
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DATA: // DATA
      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_BOOLEAN_PARAM: // BOOLEAN_PARAM
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
  class_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  class_parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  class_parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  class_parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  class_parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  class_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  class_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  class_parser::debug_level_type
  class_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  class_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  class_parser::state_type
  class_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  class_parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  class_parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  class_parser::operator() ()
  {
    return parse ();
  }

  int
  class_parser::parse ()
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
            symbol_type yylookahead (yylex (driver));
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
      case symbol_kind::S_EQUAL: // "tk_EQUAL"
      case symbol_kind::S_FIT: // "_FIT"
      case symbol_kind::S_UNIT: // "_UNIT"
      case symbol_kind::S_PATH: // "_PATH"
      case symbol_kind::S_SIZE: // "_SIZE"
      case symbol_kind::S_TYPE: // "_TYPE"
      case symbol_kind::S_TYPE2: // "_TYPE2"
      case symbol_kind::S_DELETE: // "_DELETE"
      case symbol_kind::S_NAME: // "_NAME"
      case symbol_kind::S_ADD: // "_ADD"
      case symbol_kind::S_ID: // "_ID"
      case symbol_kind::S_FS: // "_FS"
      case symbol_kind::S_LOGIN: // "_login"
      case symbol_kind::S_LOGOUT: // "_logout"
      case symbol_kind::S_MKGRP: // "_MKGRP"
      case symbol_kind::S_RMGRP: // "_RMGRP"
      case symbol_kind::S_MKUSR: // "_MKUSR"
      case symbol_kind::S_RMUSR: // "_RMUSR"
      case symbol_kind::S_CHGRP: // "_CHGRP"
      case symbol_kind::S_USER: // "_USER"
      case symbol_kind::S_PWD: // "_PWD"
      case symbol_kind::S_GRP: // "_GRP"
      case symbol_kind::S_MKFILE: // "_MKFILE"
      case symbol_kind::S_CHOWN: // "_CHOWN"
      case symbol_kind::S_CHMOD: // "_CHMOD"
      case symbol_kind::S_CAT: // "_CAT"
      case symbol_kind::S_RM: // "_RM"
      case symbol_kind::S_EDIT: // "_EDIT"
      case symbol_kind::S_REN: // "_REN"
      case symbol_kind::S_MV: // "_MV"
      case symbol_kind::S_CP: // "_CP"
      case symbol_kind::S_MKDIR: // "_MKDIR"
      case symbol_kind::S_FIND: // "_FIND"
      case symbol_kind::S_LOSS: // "_LOSS"
      case symbol_kind::S_RECOVERY: // "_RECOVERY"
      case symbol_kind::S_R: // "_R"
      case symbol_kind::S_FILEN: // "_FILEN"
      case symbol_kind::S_DEST: // "_DEST"
      case symbol_kind::S_P: // "_P"
      case symbol_kind::S_CONT: // "_CONT"
      case symbol_kind::S_UGO: // "_UGO"
      case symbol_kind::S_STDIN: // "_STDIN"
      case symbol_kind::S_RUTA: // "_RUTA"
      case symbol_kind::S_MKDISK: // "_MKDISK"
      case symbol_kind::S_RMDISK: // "_RMDISK"
      case symbol_kind::S_FDISK: // "_FDISK"
      case symbol_kind::S_MOUNT: // "_MOUNT"
      case symbol_kind::S_UMOUNT: // "_UMOUNT"
      case symbol_kind::S_MKFS: // "_MKFS"
      case symbol_kind::S_STRING_DOUBLE: // "tk_string_d"
      case symbol_kind::S_STRING_SINGLE: // "tk_string_s"
      case symbol_kind::S_PATH_DIR: // "tk_path"
      case symbol_kind::S_RUN_EXEC: // "_exec"
      case symbol_kind::S_RUN_REPORT: // "_rep"
      case symbol_kind::S_IDENTIFICADOR: // "tk_identifier"
      case symbol_kind::S_PATTERN: // "tk_pattern"
      case symbol_kind::S_NUMERO: // "tk_number"
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_DATA: // DATA
      case symbol_kind::S_PARAM: // PARAM
      case symbol_kind::S_BOOLEAN_PARAM: // BOOLEAN_PARAM
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
  case 2: // INICIO: E "eof"
#line 124 "parser.yy"
                  {return CommandHandler(x);}
#line 865 "parser.tab.cc"
    break;

  case 4: // STRING: "tk_string_d"
#line 128 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ().substr(1, yystack_[0].value.as < std::string > ().size() - 2);}
#line 871 "parser.tab.cc"
    break;

  case 5: // STRING: "tk_string_s"
#line 129 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ().substr(1, yystack_[0].value.as < std::string > ().size() - 2);}
#line 877 "parser.tab.cc"
    break;

  case 6: // DATA: STRING
#line 132 "parser.yy"
             {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 883 "parser.tab.cc"
    break;

  case 7: // DATA: "tk_number"
#line 133 "parser.yy"
                  {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 889 "parser.tab.cc"
    break;

  case 8: // DATA: "tk_path"
#line 134 "parser.yy"
                {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 895 "parser.tab.cc"
    break;

  case 9: // DATA: "tk_identifier"
#line 135 "parser.yy"
                      {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 901 "parser.tab.cc"
    break;

  case 10: // DATA: "tk_pattern"
#line 136 "parser.yy"
                   {yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();}
#line 907 "parser.tab.cc"
    break;

  case 16: // EXEC: "_exec" PARAMS
#line 146 "parser.yy"
                     {x = newCommand("__EXEC",parameters);}
#line 913 "parser.tab.cc"
    break;

  case 17: // DISCOS: "_MKDISK" PARAMS
#line 149 "parser.yy"
                         {x = newCommand("__MKDISK",parameters);}
#line 919 "parser.tab.cc"
    break;

  case 18: // DISCOS: "_RMDISK" PARAMS
#line 150 "parser.yy"
                         {x = newCommand("__RMDISK",parameters);}
#line 925 "parser.tab.cc"
    break;

  case 19: // DISCOS: "_FDISK" PARAMS
#line 151 "parser.yy"
                        {x = newCommand("__FDISK",parameters);}
#line 931 "parser.tab.cc"
    break;

  case 20: // DISCOS: "_MOUNT" PARAMS
#line 152 "parser.yy"
                        {x = newCommand("__MOUNT",parameters);}
#line 937 "parser.tab.cc"
    break;

  case 21: // DISCOS: "_UMOUNT" PARAMS
#line 153 "parser.yy"
                         {x = newCommand("__UMOUNT",parameters);}
#line 943 "parser.tab.cc"
    break;

  case 22: // DISCOS: "_MKFS" PARAMS
#line 154 "parser.yy"
                       {x = newCommand("__MKFS",parameters);}
#line 949 "parser.tab.cc"
    break;

  case 23: // ADMIN_USERS_GROUPS: "_login" PARAMS
#line 157 "parser.yy"
                                    {x = newCommand("__LOGIN",parameters);}
#line 955 "parser.tab.cc"
    break;

  case 24: // ADMIN_USERS_GROUPS: "_logout"
#line 158 "parser.yy"
                              {x = newCommand("__LOGOUT",parameters);}
#line 961 "parser.tab.cc"
    break;

  case 25: // ADMIN_USERS_GROUPS: "_MKGRP" PARAMS
#line 159 "parser.yy"
                                    {x = newCommand("__MKGRP",parameters);}
#line 967 "parser.tab.cc"
    break;

  case 26: // ADMIN_USERS_GROUPS: "_RMGRP" PARAMS
#line 160 "parser.yy"
                                    {x = newCommand("__RMGRP",parameters);}
#line 973 "parser.tab.cc"
    break;

  case 27: // ADMIN_USERS_GROUPS: "_MKUSR" PARAMS
#line 161 "parser.yy"
                                    {x = newCommand("__MKUSR",parameters);}
#line 979 "parser.tab.cc"
    break;

  case 28: // ADMIN_USERS_GROUPS: "_RMUSR" PARAMS
#line 162 "parser.yy"
                                    {x = newCommand("__RMUSR",parameters);}
#line 985 "parser.tab.cc"
    break;

  case 29: // ADMIN_USERS_GROUPS: "_CHOWN" PARAMS
#line 163 "parser.yy"
                                    {x = newCommand("__CHOWN",parameters);}
#line 991 "parser.tab.cc"
    break;

  case 30: // ADMIN_USERS_GROUPS: "_CHGRP" PARAMS
#line 164 "parser.yy"
                                    {x = newCommand("__CHGRP",parameters);}
#line 997 "parser.tab.cc"
    break;

  case 31: // FILESYSTEM: "_CHMOD" PARAMS
#line 167 "parser.yy"
                            {x = newCommand("__CHMOD",parameters);}
#line 1003 "parser.tab.cc"
    break;

  case 32: // FILESYSTEM: "_MKFILE" PARAMS
#line 168 "parser.yy"
                               {x = newCommand("__MKFILE",parameters);}
#line 1009 "parser.tab.cc"
    break;

  case 33: // FILESYSTEM: "_CAT" PARAMS
#line 169 "parser.yy"
                            {x = newCommand("__CAT",parameters);}
#line 1015 "parser.tab.cc"
    break;

  case 34: // FILESYSTEM: "_RM" PARAMS
#line 170 "parser.yy"
                           {x = newCommand("__RM",parameters);}
#line 1021 "parser.tab.cc"
    break;

  case 35: // FILESYSTEM: "_EDIT" PARAMS
#line 171 "parser.yy"
                             {x = newCommand("__EDIT",parameters);}
#line 1027 "parser.tab.cc"
    break;

  case 36: // FILESYSTEM: "_MKDIR" PARAMS
#line 172 "parser.yy"
                              {x = newCommand("__MKDIR",parameters);}
#line 1033 "parser.tab.cc"
    break;

  case 37: // FILESYSTEM: "_REN" PARAMS
#line 173 "parser.yy"
                            {x = newCommand("__REN",parameters);}
#line 1039 "parser.tab.cc"
    break;

  case 38: // FILESYSTEM: "_CP" PARAMS
#line 174 "parser.yy"
                           {x = newCommand("__CP",parameters);}
#line 1045 "parser.tab.cc"
    break;

  case 39: // FILESYSTEM: "_MV" PARAMS
#line 175 "parser.yy"
                           {x = newCommand("__MV",parameters);}
#line 1051 "parser.tab.cc"
    break;

  case 40: // FILESYSTEM: "_FIND" PARAMS
#line 176 "parser.yy"
                             {x = newCommand("__FIND",parameters);}
#line 1057 "parser.tab.cc"
    break;

  case 41: // FILESYSTEM: "_LOSS" PARAMS
#line 177 "parser.yy"
                             {x = newCommand("__LOSS",parameters);}
#line 1063 "parser.tab.cc"
    break;

  case 42: // FILESYSTEM: "_RECOVERY" PARAMS
#line 178 "parser.yy"
                                 {x = newCommand("__RECOVERY",parameters);}
#line 1069 "parser.tab.cc"
    break;

  case 43: // REPORT: "_rep" PARAMS
#line 181 "parser.yy"
                      {x = newCommand("__REP",parameters);}
#line 1075 "parser.tab.cc"
    break;

  case 44: // PARAMS: PARAMS PARAM "tk_EQUAL" DATA
#line 184 "parser.yy"
                                     {parameters.push_back({yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()});}
#line 1081 "parser.tab.cc"
    break;

  case 45: // PARAMS: PARAMS BOOLEAN_PARAM
#line 185 "parser.yy"
                             {parameters.push_back({yystack_[0].value.as < std::string > (), "true"});}
#line 1087 "parser.tab.cc"
    break;

  case 46: // PARAMS: PARAM "tk_EQUAL" DATA
#line 186 "parser.yy"
                              {parameters.clear(); parameters.push_back({yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()});}
#line 1093 "parser.tab.cc"
    break;

  case 47: // PARAMS: BOOLEAN_PARAM
#line 187 "parser.yy"
                      {parameters.clear(); parameters.push_back({yystack_[0].value.as < std::string > (), "true"});}
#line 1099 "parser.tab.cc"
    break;

  case 48: // PARAM: "_SIZE"
#line 190 "parser.yy"
               {yylhs.value.as < std::string > () = "__SIZE";}
#line 1105 "parser.tab.cc"
    break;

  case 49: // PARAM: "_FIT"
#line 191 "parser.yy"
               {yylhs.value.as < std::string > () = "__FIT";}
#line 1111 "parser.tab.cc"
    break;

  case 50: // PARAM: "_UNIT"
#line 192 "parser.yy"
                {yylhs.value.as < std::string > () = "__UNIT";}
#line 1117 "parser.tab.cc"
    break;

  case 51: // PARAM: "_PATH"
#line 193 "parser.yy"
                {yylhs.value.as < std::string > () = "__PATH";}
#line 1123 "parser.tab.cc"
    break;

  case 52: // PARAM: "_TYPE"
#line 194 "parser.yy"
                {yylhs.value.as < std::string > () = "__TYPE";}
#line 1129 "parser.tab.cc"
    break;

  case 53: // PARAM: "_TYPE2"
#line 195 "parser.yy"
                 {yylhs.value.as < std::string > () = "__TYPE2";}
#line 1135 "parser.tab.cc"
    break;

  case 54: // PARAM: "_DELETE"
#line 196 "parser.yy"
                  {yylhs.value.as < std::string > () = "__DELETE";}
#line 1141 "parser.tab.cc"
    break;

  case 55: // PARAM: "_NAME"
#line 197 "parser.yy"
                {yylhs.value.as < std::string > () = "__NAME";}
#line 1147 "parser.tab.cc"
    break;

  case 56: // PARAM: "_ADD"
#line 198 "parser.yy"
               {yylhs.value.as < std::string > () = "__ADD";}
#line 1153 "parser.tab.cc"
    break;

  case 57: // PARAM: "_ID"
#line 199 "parser.yy"
              {yylhs.value.as < std::string > () = "__ID";}
#line 1159 "parser.tab.cc"
    break;

  case 58: // PARAM: "_FS"
#line 200 "parser.yy"
              {yylhs.value.as < std::string > () = "__FS";}
#line 1165 "parser.tab.cc"
    break;

  case 59: // PARAM: "_RUTA"
#line 201 "parser.yy"
                {yylhs.value.as < std::string > () = "__RUTA";}
#line 1171 "parser.tab.cc"
    break;

  case 60: // PARAM: "_USER"
#line 202 "parser.yy"
                {yylhs.value.as < std::string > () = "__USER";}
#line 1177 "parser.tab.cc"
    break;

  case 61: // PARAM: "_PWD"
#line 203 "parser.yy"
               {yylhs.value.as < std::string > () = "__PWD";}
#line 1183 "parser.tab.cc"
    break;

  case 62: // PARAM: "_GRP"
#line 204 "parser.yy"
               {yylhs.value.as < std::string > () = "__GRP";}
#line 1189 "parser.tab.cc"
    break;

  case 63: // PARAM: "_UGO"
#line 205 "parser.yy"
               {yylhs.value.as < std::string > () = "__UGO";}
#line 1195 "parser.tab.cc"
    break;

  case 64: // PARAM: "_CONT"
#line 206 "parser.yy"
                {yylhs.value.as < std::string > () = "__CONT";}
#line 1201 "parser.tab.cc"
    break;

  case 65: // PARAM: "_FILEN"
#line 207 "parser.yy"
                 {yylhs.value.as < std::string > () = "__FILEN";}
#line 1207 "parser.tab.cc"
    break;

  case 66: // PARAM: "_DEST"
#line 208 "parser.yy"
                {yylhs.value.as < std::string > () = "__DEST";}
#line 1213 "parser.tab.cc"
    break;

  case 67: // BOOLEAN_PARAM: "_R"
#line 211 "parser.yy"
                    {yylhs.value.as < std::string > () = "__R";}
#line 1219 "parser.tab.cc"
    break;

  case 68: // BOOLEAN_PARAM: "_P"
#line 212 "parser.yy"
                   {yylhs.value.as < std::string > () = "__R";}
#line 1225 "parser.tab.cc"
    break;

  case 69: // BOOLEAN_PARAM: "_STDIN"
#line 213 "parser.yy"
                       {yylhs.value.as < std::string > () = "__STDIN";}
#line 1231 "parser.tab.cc"
    break;


#line 1235 "parser.tab.cc"

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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
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
  class_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  class_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
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

  std::string
  class_parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // class_parser::context.
  class_parser::context::context (const class_parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  class_parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  class_parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  class_parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char class_parser::yypact_ninf_ = -83;

  const signed char class_parser::yytable_ninf_ = -1;

  const signed char
  class_parser::yypact_[] =
  {
       0,   -83,    53,   -83,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
       4,     5,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,    53,
       6,   -83,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,   -83,   -83,
       7,   -83,   -51,   -51,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83
  };

  const signed char
  class_parser::yydefact_[] =
  {
       0,     3,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    12,    13,    14,    15,    49,    50,    51,
      48,    52,    53,    54,    55,    56,    57,    58,    60,    61,
      62,    67,    65,    66,    68,    64,    63,    69,    59,    23,
       0,    47,    25,    26,    27,    28,    30,    32,    29,    31,
      33,    34,    35,    37,    39,    38,    36,    40,    41,    42,
      17,    18,    19,    20,    21,    22,    16,    43,     1,     2,
       0,    45,     0,     0,     4,     5,     8,     9,    10,     7,
       6,    46,    44
  };

  const short
  class_parser::yypgoto_[] =
  {
     -83,   -83,   -83,   -82,   -83,   -83,   -83,   -83,   -83,   -83,
     153,    40,    69
  };

  const signed char
  class_parser::yydefgoto_[] =
  {
       0,    30,   100,   101,    31,    32,    33,    34,    35,    36,
      59,    60,    61
  };

  const signed char
  class_parser::yytable_[] =
  {
       1,    94,    95,    96,    88,    89,    97,    98,    99,    92,
      93,   102,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
      26,    27,     0,     0,     0,    28,    29,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    90,
       0,     0,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,     0,
       0,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
  };

  const signed char
  class_parser::yycheck_[] =
  {
       0,    52,    53,    54,     0,     0,    57,    58,    59,     3,
       3,    93,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    55,    56,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    59,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29
  };

  const signed char
  class_parser::yystos_[] =
  {
       0,     0,    15,    16,    17,    18,    19,    20,    21,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    46,    47,    48,    49,    50,    51,    55,    56,
      61,    64,    65,    66,    67,    68,    69,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    22,    23,
      24,    38,    39,    40,    41,    42,    43,    44,    45,    70,
      71,    72,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,     0,     0,
      71,    72,     3,     3,    52,    53,    54,    57,    58,    59,
      62,    63,    63
  };

  const signed char
  class_parser::yyr1_[] =
  {
       0,    60,    61,    61,    62,    62,    63,    63,    63,    63,
      63,    64,    64,    64,    64,    64,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    69,    70,    70,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72
  };

  const signed char
  class_parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     4,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const class_parser::yytname_[] =
  {
  "\"eof\"", "error", "\"invalid token\"", "\"tk_EQUAL\"", "\"_FIT\"",
  "\"_UNIT\"", "\"_PATH\"", "\"_SIZE\"", "\"_TYPE\"", "\"_TYPE2\"",
  "\"_DELETE\"", "\"_NAME\"", "\"_ADD\"", "\"_ID\"", "\"_FS\"",
  "\"_login\"", "\"_logout\"", "\"_MKGRP\"", "\"_RMGRP\"", "\"_MKUSR\"",
  "\"_RMUSR\"", "\"_CHGRP\"", "\"_USER\"", "\"_PWD\"", "\"_GRP\"",
  "\"_MKFILE\"", "\"_CHOWN\"", "\"_CHMOD\"", "\"_CAT\"", "\"_RM\"",
  "\"_EDIT\"", "\"_REN\"", "\"_MV\"", "\"_CP\"", "\"_MKDIR\"", "\"_FIND\"",
  "\"_LOSS\"", "\"_RECOVERY\"", "\"_R\"", "\"_FILEN\"", "\"_DEST\"",
  "\"_P\"", "\"_CONT\"", "\"_UGO\"", "\"_STDIN\"", "\"_RUTA\"",
  "\"_MKDISK\"", "\"_RMDISK\"", "\"_FDISK\"", "\"_MOUNT\"", "\"_UMOUNT\"",
  "\"_MKFS\"", "\"tk_string_d\"", "\"tk_string_s\"", "\"tk_path\"",
  "\"_exec\"", "\"_rep\"", "\"tk_identifier\"", "\"tk_pattern\"",
  "\"tk_number\"", "$accept", "INICIO", "STRING", "DATA", "E", "EXEC",
  "DISCOS", "ADMIN_USERS_GROUPS", "FILESYSTEM", "REPORT", "PARAMS",
  "PARAM", "BOOLEAN_PARAM", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  class_parser::yyrline_[] =
  {
       0,   124,   124,   125,   128,   129,   132,   133,   134,   135,
     136,   139,   140,   141,   142,   143,   146,   149,   150,   151,
     152,   153,   154,   157,   158,   159,   160,   161,   162,   163,
     164,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   181,   184,   185,   186,   187,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   211,   212,   213
  };

  void
  class_parser::yy_stack_print_ () const
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
  class_parser::yy_reduce_print_ (int yyrule) const
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


#line 6 "parser.yy"
} // yy
#line 1794 "parser.tab.cc"

#line 216 "parser.yy"

void yy::class_parser::error(const location_type& lugar, const std::string& lexema)
{
  std::cout << "ERROR SINTÁCTICO: " << lexema << std::endl;
  exit(EXIT_FAILURE);
}
