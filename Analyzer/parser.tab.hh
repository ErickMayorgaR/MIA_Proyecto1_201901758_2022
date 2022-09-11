// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 11 "parser.yy"

#include <string>
#include <stdio.h>

class parser_driver;

#line 56 "parser.tab.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 6 "parser.yy"
namespace yy {
#line 197 "parser.tab.hh"




  /// A Bison parser.
  class class_parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "tk_EQUAL"
      // "_FIT"
      // "_UNIT"
      // "_PATH"
      // "_SIZE"
      // "_TYPE"
      // "_TYPE2"
      // "_DELETE"
      // "_NAME"
      // "_ADD"
      // "_ID"
      // "_FS"
      // "_login"
      // "_logout"
      // "_MKGRP"
      // "_RMGRP"
      // "_MKUSR"
      // "_RMUSR"
      // "_CHGRP"
      // "_USER"
      // "_PWD"
      // "_GRP"
      // "_MKFILE"
      // "_CHOWN"
      // "_CHMOD"
      // "_CAT"
      // "_RM"
      // "_EDIT"
      // "_REN"
      // "_MV"
      // "_CP"
      // "_MKDIR"
      // "_FIND"
      // "_LOSS"
      // "_RECOVERY"
      // "_R"
      // "_FILEN"
      // "_DEST"
      // "_P"
      // "_CONT"
      // "_UGO"
      // "_STDIN"
      // "_RUTA"
      // "_MKDISK"
      // "_RMDISK"
      // "_FDISK"
      // "_MOUNT"
      // "_UMOUNT"
      // "_MKFS"
      // "tk_string_d"
      // "tk_string_s"
      // "tk_path"
      // "_exec"
      // "_rep"
      // "tk_identifier"
      // "tk_pattern"
      // "tk_number"
      // STRING
      // DATA
      // PARAM
      // BOOLEAN_PARAM
      char dummy1[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOK_YYEMPTY = -2,
    TOK_FIN = 0,                   // "eof"
    TOK_YYerror = 256,             // error
    TOK_YYUNDEF = 257,             // "invalid token"
    TOK_EQUAL = 258,               // "tk_EQUAL"
    TOK_FIT = 259,                 // "_FIT"
    TOK_UNIT = 260,                // "_UNIT"
    TOK_PATH = 261,                // "_PATH"
    TOK_SIZE = 262,                // "_SIZE"
    TOK_TYPE = 263,                // "_TYPE"
    TOK_TYPE2 = 264,               // "_TYPE2"
    TOK_DELETE = 265,              // "_DELETE"
    TOK_NAME = 266,                // "_NAME"
    TOK_ADD = 267,                 // "_ADD"
    TOK_ID = 268,                  // "_ID"
    TOK_FS = 269,                  // "_FS"
    TOK_LOGIN = 270,               // "_login"
    TOK_LOGOUT = 271,              // "_logout"
    TOK_MKGRP = 272,               // "_MKGRP"
    TOK_RMGRP = 273,               // "_RMGRP"
    TOK_MKUSR = 274,               // "_MKUSR"
    TOK_RMUSR = 275,               // "_RMUSR"
    TOK_CHGRP = 276,               // "_CHGRP"
    TOK_USER = 277,                // "_USER"
    TOK_PWD = 278,                 // "_PWD"
    TOK_GRP = 279,                 // "_GRP"
    TOK_MKFILE = 280,              // "_MKFILE"
    TOK_CHOWN = 281,               // "_CHOWN"
    TOK_CHMOD = 282,               // "_CHMOD"
    TOK_CAT = 283,                 // "_CAT"
    TOK_RM = 284,                  // "_RM"
    TOK_EDIT = 285,                // "_EDIT"
    TOK_REN = 286,                 // "_REN"
    TOK_MV = 287,                  // "_MV"
    TOK_CP = 288,                  // "_CP"
    TOK_MKDIR = 289,               // "_MKDIR"
    TOK_FIND = 290,                // "_FIND"
    TOK_LOSS = 291,                // "_LOSS"
    TOK_RECOVERY = 292,            // "_RECOVERY"
    TOK_R = 293,                   // "_R"
    TOK_FILEN = 294,               // "_FILEN"
    TOK_DEST = 295,                // "_DEST"
    TOK_P = 296,                   // "_P"
    TOK_CONT = 297,                // "_CONT"
    TOK_UGO = 298,                 // "_UGO"
    TOK_STDIN = 299,               // "_STDIN"
    TOK_RUTA = 300,                // "_RUTA"
    TOK_MKDISK = 301,              // "_MKDISK"
    TOK_RMDISK = 302,              // "_RMDISK"
    TOK_FDISK = 303,               // "_FDISK"
    TOK_MOUNT = 304,               // "_MOUNT"
    TOK_UMOUNT = 305,              // "_UMOUNT"
    TOK_MKFS = 306,                // "_MKFS"
    TOK_STRING_DOUBLE = 307,       // "tk_string_d"
    TOK_STRING_SINGLE = 308,       // "tk_string_s"
    TOK_PATH_DIR = 309,            // "tk_path"
    TOK_RUN_EXEC = 310,            // "_exec"
    TOK_RUN_REPORT = 311,          // "_rep"
    TOK_IDENTIFICADOR = 312,       // "tk_identifier"
    TOK_PATTERN = 313,             // "tk_pattern"
    TOK_NUMERO = 314               // "tk_number"
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 60, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "eof"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_EQUAL = 3,                             // "tk_EQUAL"
        S_FIT = 4,                               // "_FIT"
        S_UNIT = 5,                              // "_UNIT"
        S_PATH = 6,                              // "_PATH"
        S_SIZE = 7,                              // "_SIZE"
        S_TYPE = 8,                              // "_TYPE"
        S_TYPE2 = 9,                             // "_TYPE2"
        S_DELETE = 10,                           // "_DELETE"
        S_NAME = 11,                             // "_NAME"
        S_ADD = 12,                              // "_ADD"
        S_ID = 13,                               // "_ID"
        S_FS = 14,                               // "_FS"
        S_LOGIN = 15,                            // "_login"
        S_LOGOUT = 16,                           // "_logout"
        S_MKGRP = 17,                            // "_MKGRP"
        S_RMGRP = 18,                            // "_RMGRP"
        S_MKUSR = 19,                            // "_MKUSR"
        S_RMUSR = 20,                            // "_RMUSR"
        S_CHGRP = 21,                            // "_CHGRP"
        S_USER = 22,                             // "_USER"
        S_PWD = 23,                              // "_PWD"
        S_GRP = 24,                              // "_GRP"
        S_MKFILE = 25,                           // "_MKFILE"
        S_CHOWN = 26,                            // "_CHOWN"
        S_CHMOD = 27,                            // "_CHMOD"
        S_CAT = 28,                              // "_CAT"
        S_RM = 29,                               // "_RM"
        S_EDIT = 30,                             // "_EDIT"
        S_REN = 31,                              // "_REN"
        S_MV = 32,                               // "_MV"
        S_CP = 33,                               // "_CP"
        S_MKDIR = 34,                            // "_MKDIR"
        S_FIND = 35,                             // "_FIND"
        S_LOSS = 36,                             // "_LOSS"
        S_RECOVERY = 37,                         // "_RECOVERY"
        S_R = 38,                                // "_R"
        S_FILEN = 39,                            // "_FILEN"
        S_DEST = 40,                             // "_DEST"
        S_P = 41,                                // "_P"
        S_CONT = 42,                             // "_CONT"
        S_UGO = 43,                              // "_UGO"
        S_STDIN = 44,                            // "_STDIN"
        S_RUTA = 45,                             // "_RUTA"
        S_MKDISK = 46,                           // "_MKDISK"
        S_RMDISK = 47,                           // "_RMDISK"
        S_FDISK = 48,                            // "_FDISK"
        S_MOUNT = 49,                            // "_MOUNT"
        S_UMOUNT = 50,                           // "_UMOUNT"
        S_MKFS = 51,                             // "_MKFS"
        S_STRING_DOUBLE = 52,                    // "tk_string_d"
        S_STRING_SINGLE = 53,                    // "tk_string_s"
        S_PATH_DIR = 54,                         // "tk_path"
        S_RUN_EXEC = 55,                         // "_exec"
        S_RUN_REPORT = 56,                       // "_rep"
        S_IDENTIFICADOR = 57,                    // "tk_identifier"
        S_PATTERN = 58,                          // "tk_pattern"
        S_NUMERO = 59,                           // "tk_number"
        S_YYACCEPT = 60,                         // $accept
        S_INICIO = 61,                           // INICIO
        S_STRING = 62,                           // STRING
        S_DATA = 63,                             // DATA
        S_E = 64,                                // E
        S_EXEC = 65,                             // EXEC
        S_DISCOS = 66,                           // DISCOS
        S_ADMIN_USERS_GROUPS = 67,               // ADMIN_USERS_GROUPS
        S_FILESYSTEM = 68,                       // FILESYSTEM
        S_REPORT = 69,                           // REPORT
        S_PARAMS = 70,                           // PARAMS
        S_PARAM = 71,                            // PARAM
        S_BOOLEAN_PARAM = 72                     // BOOLEAN_PARAM
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return class_parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::TOK_FIN
                   || (token::TOK_YYerror <= tok && tok <= token::TOK_YYUNDEF));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::TOK_EQUAL <= tok && tok <= token::TOK_NUMERO));
#endif
      }
    };

    /// Build a parser object.
    class_parser (parser_driver& driver_yyarg);
    virtual ~class_parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    class_parser (const class_parser&) = delete;
    /// Non copyable.
    class_parser& operator= (const class_parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIN (location_type l)
      {
        return symbol_type (token::TOK_FIN, std::move (l));
      }
#else
      static
      symbol_type
      make_FIN (const location_type& l)
      {
        return symbol_type (token::TOK_FIN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::TOK_YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::TOK_YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::TOK_YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::TOK_YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EQUAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EQUAL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EQUAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNIT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_UNIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UNIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_UNIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATH (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PATH, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PATH (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PATH, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_SIZE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_SIZE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_SIZE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TYPE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TYPE2 (std::string v, location_type l)
      {
        return symbol_type (token::TOK_TYPE2, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TYPE2 (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_TYPE2, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DELETE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DELETE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DELETE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DELETE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (std::string v, location_type l)
      {
        return symbol_type (token::TOK_NAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NAME (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_NAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ADD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ADD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ADD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::TOK_ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGIN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LOGIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOGIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LOGIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGOUT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LOGOUT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOGOUT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LOGOUT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKGRP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKGRP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKGRP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKGRP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMGRP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RMGRP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMGRP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RMGRP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKUSR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKUSR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKUSR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKUSR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMUSR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RMUSR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMUSR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RMUSR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHGRP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHGRP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHGRP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHGRP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_USER (std::string v, location_type l)
      {
        return symbol_type (token::TOK_USER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_USER (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_USER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PWD (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PWD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PWD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PWD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GRP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_GRP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_GRP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_GRP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKFILE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKFILE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKFILE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKFILE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHOWN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHOWN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHOWN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHOWN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CHMOD (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CHMOD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CHMOD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CHMOD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CAT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RM (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RM, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RM (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RM, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EDIT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_EDIT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EDIT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_EDIT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_REN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_REN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MV (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MV, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MV (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MV, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CP (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CP (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKDIR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKDIR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKDIR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKDIR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FIND (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FIND, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FIND (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FIND, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOSS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_LOSS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LOSS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_LOSS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RECOVERY (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RECOVERY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RECOVERY (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RECOVERY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_R (std::string v, location_type l)
      {
        return symbol_type (token::TOK_R, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_R (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_R, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FILEN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FILEN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FILEN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FILEN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DEST (std::string v, location_type l)
      {
        return symbol_type (token::TOK_DEST, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DEST (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_DEST, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_P (std::string v, location_type l)
      {
        return symbol_type (token::TOK_P, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_P (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_P, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_CONT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_CONT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_CONT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UGO (std::string v, location_type l)
      {
        return symbol_type (token::TOK_UGO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UGO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_UGO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STDIN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STDIN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STDIN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STDIN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RUTA (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RUTA, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RUTA (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RUTA, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKDISK (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKDISK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKDISK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKDISK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RMDISK (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RMDISK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RMDISK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RMDISK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FDISK (std::string v, location_type l)
      {
        return symbol_type (token::TOK_FDISK, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FDISK (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_FDISK, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOUNT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MOUNT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MOUNT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MOUNT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMOUNT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_UMOUNT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_UMOUNT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_UMOUNT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MKFS (std::string v, location_type l)
      {
        return symbol_type (token::TOK_MKFS, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_MKFS (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_MKFS, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_DOUBLE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRING_DOUBLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_DOUBLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING_DOUBLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING_SINGLE (std::string v, location_type l)
      {
        return symbol_type (token::TOK_STRING_SINGLE, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING_SINGLE (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_STRING_SINGLE, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATH_DIR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PATH_DIR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PATH_DIR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PATH_DIR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RUN_EXEC (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RUN_EXEC, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RUN_EXEC (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RUN_EXEC, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RUN_REPORT (std::string v, location_type l)
      {
        return symbol_type (token::TOK_RUN_REPORT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RUN_REPORT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_RUN_REPORT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFICADOR (std::string v, location_type l)
      {
        return symbol_type (token::TOK_IDENTIFICADOR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_IDENTIFICADOR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_IDENTIFICADOR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATTERN (std::string v, location_type l)
      {
        return symbol_type (token::TOK_PATTERN, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_PATTERN (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_PATTERN, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMERO (std::string v, location_type l)
      {
        return symbol_type (token::TOK_NUMERO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMERO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TOK_NUMERO, v, l);
      }
#endif


    class context
    {
    public:
      context (const class_parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const class_parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    class_parser (const class_parser&);
    /// Non copyable.
    class_parser& operator= (const class_parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef signed char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const signed char yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const signed char yytable_[];

    static const signed char yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const unsigned char yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 182,     ///< Last index in yytable_.
      yynnts_ = 13,  ///< Number of nonterminal symbols.
      yyfinal_ = 88 ///< Termination state number.
    };


    // User arguments.
    parser_driver& driver;

  };

  inline
  class_parser::symbol_kind_type
  class_parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
    };
    // Last valid token kind.
    const int code_max = 314;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  class_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  class_parser::symbol_kind_type
  class_parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  class_parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  class_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  class_parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  class_parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  class_parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  class_parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  class_parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  class_parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  class_parser::symbol_kind_type
  class_parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  class_parser::symbol_kind_type
  class_parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 6 "parser.yy"
} // yy
#line 2594 "parser.tab.hh"




#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
