/*  stdlib.h

    Definitions for common types, variables, and functions.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __STDLIB_H
#define __STDLIB_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef _DIV_T
#define _DIV_T
typedef struct {
        int     quot;
        int     rem;
} div_t;
#endif

#ifndef _LDIV_T
#define _LDIV_T
typedef struct {
        long    quot;
        long    rem;
} ldiv_t;
#endif

#ifndef _WCHAR_T
#define _WCHAR_T
typedef char wchar_t;
#endif

/* Old typedef 
*/
typedef void _Cdecl (* atexit_t)(void);

/* Maximum value returned by "rand" function
*/
#define RAND_MAX 0x7FFFU

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MB_CUR_MAX 1

#ifdef __cplusplus
extern "C" {
#endif

void        _Cdecl abort(void);
int         _Cdecl __abs__(int);
#ifdef __cplusplus
inline int _Cdecl  abs(int __x) { return __abs__(__x); }
#else
int         _CType abs(int __x);
#  define abs(x)   __abs__(x)
#endif
int         _Cdecl atexit(void (_Cdecl *__func)(void));
double      _Cdecl atof(const char *__s);
int         _CType atoi(const char *__s);
long        _CType atol(const char *__s);
void * _CType bsearch(const void *__key, const void *__base,
               size_t __nelem, size_t __width,
               int (_CType *fcmp)(const void *,
               const void *));
void * _Cdecl calloc(size_t __nitems, size_t __size);
div_t       _Cdecl div(int __numer, int __denom);
void        _Cdecl exit(int __status);
void        _Cdecl free(void *__block);
char * _CType getenv(const char *__name);
long        _Cdecl labs(long __x);
ldiv_t      _Cdecl ldiv(long __numer, long __denom);
void * _Cdecl malloc(size_t __size);
int         _Cdecl mblen(const char *__s, size_t __n);
size_t      _Cdecl mbstowcs(wchar_t *__pwcs, const char *__s,
            size_t __n);
int     _Cdecl mbtowc(wchar_t *__pwc, const char *__s, size_t __n);
void    _CType qsort(void *__base, size_t __nelem, size_t __width,
        int _CType (*__fcmp)(const void *, const void *));
int     _Cdecl rand(void);
void *_Cdecl realloc(void *__block, size_t __size);
void    _Cdecl srand(unsigned __seed);
double  _Cdecl strtod(const char *__s, char **__endptr);
long    _Cdecl strtol(const char *__s, char **__endptr,
              int __radix);
long double _Cdecl _strtold(const char *__s, char **__endptr);
unsigned long _Cdecl strtoul(const char *__s, char **__endptr,
                 int __radix);
int     _Cdecl system(const char *__command);
size_t  _Cdecl wcstombs(char *__s, const wchar_t *__pwcs,
            size_t __n);
int     _Cdecl wctomb(char *__s, wchar_t __wc);

#ifdef __cplusplus
}
#endif

#if !__STDC__

/* Variables */

extern  int   _Cdecl _doserrno;
extern  int   _Cdecl errno;

/*
  These 2 constants are defined in MS's stdlib.h.  Rather than defining them
  all the time and invading the ANSI programmers name space we'll only make
  them visible when __STDC__ is *off*.  Anybody using these constants ain't
  writing standard C anyway!
*/
#define DOS_MODE  0
#define OS2_MODE  1

extern  unsigned        _Cdecl _psp;

extern  char          **_Cdecl environ;
extern  int             _Cdecl _fmode;
extern  unsigned char   _Cdecl _osmajor;
extern  unsigned char   _Cdecl _osminor;
extern  unsigned int    _Cdecl _version;

extern  char           *_Cdecl sys_errlist[];
extern  int             _Cdecl sys_nerr;

/* Constants for MSC pathname functions */

#define _MAX_PATH       80
#define _MAX_DRIVE      3
#define _MAX_DIR        66
#define _MAX_FNAME      9
#define _MAX_EXT        5

#ifdef __cplusplus
inline int _Cdecl random(int __num)
                 { return(int)(((long)rand()*__num)/(RAND_MAX+1)); }
/* need prototype of time() for C++ randomize() */
extern "C" long _Cdecl time(long *);  
inline void _Cdecl randomize(void) { srand((unsigned) time(NULL)); }
inline int  _Cdecl atoi(const char *__s) { return (int) atol(__s); }
#else
#define random(num)(int)(((long)rand()*(num))/(RAND_MAX+1))
#define randomize()     srand((unsigned)time(NULL))
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#define atoi(s)     ((int) atol(s))
#endif

#ifdef __cplusplus
extern "C" {
#endif

long double _Cdecl _atold(const char *__s);
char   *_Cdecl ecvt(double __value, int __ndig, int *__dec,
             int *__sign);
void    _Cdecl _exit(int __status);
char   *_Cdecl fcvt(double __value, int __ndig, int *__dec,
            int *__sign);
char * _CType _fullpath( char *__buf,
                  const char *__path,
                  size_t __maxlen );
char   *_Cdecl gcvt(double __value, int __ndec, char *__buf);
char   *_CType itoa(int __value, char *__string, int __radix);
void   *_Cdecl lfind(const void *__key, const void *__base,
         size_t *__num, size_t __width,
         int _Cdecl(*__fcmp)(const void *, const void *));

unsigned long _Cdecl _lrotl(unsigned long __val, int __count);
unsigned long _Cdecl _lrotr(unsigned long __val, int __count);

void   *_Cdecl lsearch(const void *__key, void *__base,
         size_t *__num, size_t __width,
         int _Cdecl(*__fcmp)(const void *, const void *));
char * _CType ltoa(long __value, char *__string, int __radix);
void _Cdecl _makepath( char *__path,
                  const char *__drive,
                  const char *__dir,
                  const char *__name,
                  const char *__ext );
int     _Cdecl putenv(const char *__name);

unsigned    _Cdecl _rotl(unsigned __value, int __count);
unsigned    _Cdecl _rotr(unsigned __value, int __count);

unsigned    _Cdecl __rotl__(unsigned __value, int __count);     /* intrinsic */
unsigned    _Cdecl __rotr__(unsigned __value, int __count);     /* intrinsic */

void        _Cdecl _searchenv(const char *__file,
                  const char *__varname,
                  char *__pathname);
void _Cdecl _splitpath( const char *__path,
                   char *__drive,
                   char *__dir,
                   char *__name,
                   char *__ext );
void    _Cdecl swab(char *__from, char *__to, int __nbytes);
char *_CType ultoa(unsigned long __value, char *__string,
              int __radix);


#ifdef __cplusplus
}
#endif

#endif  /* !__STDC__ */

#endif  /* __STDLIB_H */

/*  stdio.h

    Definitions for stream input/output.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __STDIO_H
#define __STDIO_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

/* Definition of the file position type
*/
typedef long    fpos_t;


/* Definition of the control structure for streams
*/
typedef struct  {
        int             level;          /* fill/empty level of buffer */
        unsigned        flags;          /* File status flags          */
        char            fd;             /* File descriptor            */
        unsigned char   hold;           /* Ungetc char if no buffer   */
        int             bsize;          /* Buffer size                */
        unsigned char   *buffer;   /* Data transfer buffer       */
        unsigned char   *curp;     /* Current active pointer     */
        unsigned        istemp;         /* Temporary file indicator   */
        short           token;          /* Used for validity checking */
}       FILE;                           /* This is the FILE object    */

/* Bufferisation type to be used as 3rd argument for "setvbuf" function
*/
#define _IOFBF  0
#define _IOLBF  1
#define _IONBF  2

/*  "flags" bits definitions
*/
#define _F_RDWR 0x0003                  /* Read/write flag       */
#define _F_READ 0x0001                  /* Read only file        */
#define _F_WRIT 0x0002                  /* Write only file       */
#define _F_BUF  0x0004                  /* Malloc'ed Buffer data */
#define _F_LBUF 0x0008                  /* line-buffered file    */
#define _F_ERR  0x0010                  /* Error indicator       */
#define _F_EOF  0x0020                  /* EOF indicator         */
#define _F_BIN  0x0040                  /* Binary file indicator */
#define _F_IN   0x0080                  /* Data is incoming      */
#define _F_OUT  0x0100                  /* Data is outgoing      */
#define _F_TERM 0x0200                  /* File is a terminal    */

/* End-of-file constant definition
*/
#define EOF (-1)            /* End of file indicator */

/* Number of files that can be open simultaneously
*/
#if __STDC__
#define FOPEN_MAX 18        /* Able to have 18 files (20 - stdaux & stdprn) */
#else
#define FOPEN_MAX 20        /* Able to have 20 files */
#define SYS_OPEN  20
#endif

#define FILENAME_MAX 80

/* Default buffer size use by "setbuf" function
*/
#define BUFSIZ  512         /* Buffer size for stdio */

/* Size of an arry large enough to hold a temporary file name string
*/
#define L_ctermid   5       /* CON: plus null byte */
#define P_tmpdir    ""      /* temporary directory */
#define L_tmpnam    13      /* tmpnam buffer size */

/* Constants to be used as 3rd argument for "fseek" function
*/
#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

/* Number of unique file names that shall be generated by "tmpnam" function
*/
#define TMP_MAX     0xFFFF

/* Standard I/O predefined streams
*/

#if !defined( _RTLDLL )
extern  FILE    _Cdecl _streams[];
extern  unsigned    _Cdecl _nfile;

#define stdin   (&_streams[0])
#define stdout  (&_streams[1])
#define stderr  (&_streams[2])

#if !__STDC__
#define stdaux  (&_streams[3])
#define stdprn  (&_streams[4])
#endif

#else

#ifdef __cplusplus
extern "C" {
#endif
FILE far * far __getStream(int);
#ifdef __cplusplus
}
#endif

#define stdin   __getStream(0)
#define stdout  __getStream(1)
#define stderr  __getStream(2)
#define stdaux  __getStream(3)
#define stdprn  __getStream(4)

#endif

#ifdef __cplusplus
extern "C" {
#endif
void    _Cdecl clearerr(FILE *__stream);
int     _Cdecl fclose(FILE *__stream);
int     _Cdecl fflush(FILE *__stream);
int     _Cdecl fgetc(FILE *__stream);
int     _Cdecl fgetpos(FILE *__stream, fpos_t *__pos);
char   *_Cdecl fgets(char *__s, int __n, FILE *__stream);
FILE   *_Cdecl fopen(const char *__path, const char *__mode);
int     _Cdecl fprintf(FILE *__stream, const char *__format, ...);
int     _Cdecl fputc(int __c, FILE *__stream);
int     _Cdecl fputs(const char *__s, FILE *__stream);
size_t  _Cdecl fread(void *__ptr, size_t __size, size_t __n,
                     FILE *__stream);
FILE   *_Cdecl freopen(const char *__path, const char *__mode,
                            FILE *__stream);
int     _Cdecl fscanf(FILE *__stream, const char *__format, ...);
int     _Cdecl fseek(FILE *__stream, long __offset, int __whence);
int     _Cdecl fsetpos(FILE *__stream, const fpos_t *__pos);
long    _Cdecl ftell(FILE *__stream);
size_t  _Cdecl fwrite(const void *__ptr, size_t __size, size_t __n,
                      FILE *__stream);
char   *_Cdecl gets(char *__s);
void    _Cdecl perror(const char *__s);
int     _Cdecl printf(const char *__format, ...);
int     _Cdecl puts(const char *__s);
int     _CType remove(const char *__path);
int     _CType rename(const char *__oldname,const char *__newname);
void    _Cdecl rewind(FILE *__stream);
int     _Cdecl scanf(const char *__format, ...);
void    _Cdecl setbuf(FILE *__stream, char *__buf);
int     _Cdecl setvbuf(FILE *__stream, char *__buf,
                       int __type, size_t __size);
int     _Cdecl sprintf(char *__buffer, const char *__format, ...);
int     _Cdecl sscanf(const char *__buffer,
                      const char *__format, ...);
char   *_Cdecl strerror(int __errnum);
FILE   *_Cdecl tmpfile(void);
char   *_Cdecl tmpnam(char *__s);
int     _Cdecl ungetc(int __c, FILE *__stream);
int     _Cdecl vfprintf(FILE *__stream, const char *__format,
                        void *__arglist);
int     _Cdecl vfscanf(FILE *__stream, const char *__format,
                        void *__arglist);
int     _CType vprintf(const char *__format, void *__arglist);
int     _Cdecl vscanf(const char *__format, void *__arglist);
int     _Cdecl vsprintf(char *__buffer, const char *__format,
                        void *__arglist);
int     _Cdecl vsscanf(const char *__buffer, const char *__format,
                        void *__arglist);
int     _CType unlink(const char *__path);
int     _Cdecl getc(FILE *__fp);

int     _Cdecl getchar(void);
int     _Cdecl putchar(const int __c);

int     _Cdecl putc(const int __c, FILE *__fp);
int     _Cdecl feof(FILE *__fp);
int     _Cdecl ferror(FILE *__fp);


#if !__STDC__
int     _Cdecl fcloseall(void);
FILE   *_Cdecl fdopen(int __handle, char *__type);
int     _Cdecl fgetchar(void);
int     _Cdecl flushall(void);
int     _Cdecl fputchar(int __c);
FILE   * _Cdecl _fsopen (const char *__path, const char *__mode,
                  int __shflag);
int     _Cdecl getw(FILE *__stream);
int     _Cdecl putw(int __w, FILE *__stream);
int     _Cdecl rmtmp(void);
char   * _Cdecl _strerror(const char *__s);
char   * _Cdecl tempnam(char *__dir, char *__pfx);

#define fileno(f)       ((f)->fd)
#endif

int      _Cdecl _fgetc(FILE *__stream);           /* used by getc() macro */
int      _Cdecl _fputc(char __c, FILE *__stream); /* used by putc() macro */

#ifdef  __cplusplus
}
#endif

/*  The following macros provide for common functions */

#define ferror(f)   ((f)->flags & _F_ERR)
#define feof(f)     ((f)->flags & _F_EOF)

#define getc(f) \
  ((--((f)->level) >= 0) ? (unsigned char)(*(f)->curp++) : \
    _fgetc (f))

#define putc(c,f) \
  ((++((f)->level) < 0) ? (unsigned char)(*(f)->curp++=(c)) : \
    _fputc ((c),f))

#define getchar()  getc(stdin)
#define putchar(c) putc((c), stdout)

#define ungetc(c,f) ungetc((c),f)   /* traditionally a macro */

#endif

/*  dos.h

    Defines structs, unions, macros, and functions for dealing
    with MSDOS and the Intel iAPX86 microprocessor family.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/
#ifndef __DOS_H
#define __DOS_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

extern  int _Cdecl  errno;
extern  int _Cdecl  _doserrno;

/* Variables */
extern  int const _Cdecl _8087;
extern  int       _Cdecl _argc;
extern  char    **_Cdecl _argv;
extern  char    **_Cdecl  environ;

extern  unsigned      _Cdecl _psp;
extern  unsigned      _Cdecl _heaplen;
extern  unsigned char _Cdecl _osmajor;
extern  unsigned char _Cdecl _osminor;
extern  unsigned      _Cdecl _stklen;
extern  unsigned      _Cdecl _fpstklen;
extern  unsigned      _Cdecl _version;
extern  unsigned      _Cdecl _osversion;      /* MSC name for _version */

#define FA_NORMAL   0x00        /* Normal file, no attributes */
#define FA_RDONLY   0x01        /* Read only attribute */
#define FA_HIDDEN   0x02        /* Hidden file */
#define FA_SYSTEM   0x04        /* System file */
#define FA_LABEL    0x08        /* Volume label */
#define FA_DIREC    0x10        /* Directory */
#define FA_ARCH     0x20        /* Archive */

/* MSC names for file attributes */

#define _A_NORMAL   0x00        /* Normal file, no attributes */
#define _A_RDONLY   0x01        /* Read only attribute */
#define _A_HIDDEN   0x02        /* Hidden file */
#define _A_SYSTEM   0x04        /* System file */
#define _A_VOLID    0x08        /* Volume label */
#define _A_SUBDIR   0x10        /* Directory */
#define _A_ARCH     0x20        /* Archive */

#define NFDS    20          /* Maximum number of fds */

struct  fcb {
    char    fcb_drive;      /* 0 = default, 1 = A, 2 = B */
    char    fcb_name[8];    /* File name */
    char    fcb_ext[3];     /* File extension */
    short   fcb_curblk;     /* Current block number */
    short   fcb_recsize;    /* Logical record size in bytes */
    long    fcb_filsize;    /* File size in bytes */
    short   fcb_date;       /* Date file was last written */
    char    fcb_resv[10];   /* Reserved for DOS */
    char    fcb_currec;     /* Current record in block */
    long    fcb_random;     /* Random record number */
};

struct  xfcb    {
    char        xfcb_flag;  /* Contains 0xff to indicate xfcb */
    char        xfcb_resv[5];/* Reserved for DOS */
    char        xfcb_attr;  /* Search attribute */
    struct  fcb xfcb_fcb;   /* The standard fcb */
};

struct  COUNTRY {
    int co_date;
    char    co_curr[5];
    char    co_thsep[2];
    char    co_desep[2];
    char    co_dtsep[2];
    char    co_tmsep[2];
    char    co_currstyle;
    char    co_digits;
    char    co_time;
    long    co_case;
    char    co_dasep[2];
    char    co_fill[10];
};

#if defined(__MSC) && !defined(__cplusplus)
struct  DOSERROR {
        int     exterror;
        char    class;
        char    action;
        char    locus;
};
#else
struct  DOSERROR {
        int     de_exterror;
        char    de_class;
        char    de_action;
        char    de_locus;
};
#endif  /* __MSC and not C++ */

struct  dfree   {
    unsigned df_avail;
    unsigned df_total;
    unsigned df_bsec;
    unsigned df_sclus;
};

struct diskfree_t {
    unsigned total_clusters;
    unsigned avail_clusters;
    unsigned sectors_per_cluster;
    unsigned bytes_per_sector;
};

struct  fatinfo {
    char     fi_sclus;
    char     fi_fatid;
    unsigned fi_nclus;
    int      fi_bysec;
};

struct  devhdr  {
    long        dh_next;        /* Next device pointer */
    short       dh_attr;        /* Attributes */
    unsigned short  dh_strat;   /* Driver strategy routine */
    unsigned short  dh_inter;   /* Driver interrupt routine */
    char        dh_name[8];     /* Device name */
};

struct  time    {
    unsigned char   ti_min;     /* Minutes */
    unsigned char   ti_hour;    /* Hours */
    unsigned char   ti_hund;    /* Hundredths of seconds */
    unsigned char   ti_sec;     /* Seconds */
};

struct dostime_t {
    unsigned char hour;         /* Hours */
    unsigned char minute;       /* Minutes */
    unsigned char second;       /* Seconds */
    unsigned char hsecond;      /* Hundredths of seconds */
};

struct  date    {
    int     da_year;        /* Year - 1980 */
    char        da_day;     /* Day of the month */
    char        da_mon;     /* Month (1 = Jan) */
};

struct dosdate_t {
    unsigned char day;      /* 1-31 */
    unsigned char month;    /* 1-12 */
    unsigned int  year;     /* 1980 - 2099 */
    unsigned char dayofweek;/* 0 - 6 (0=Sunday) */
};

#ifndef _REG_DEFS
#define _REG_DEFS

struct WORDREGS {
    unsigned int    ax, bx, cx, dx, si, di, cflag, flags;
};

struct BYTEREGS {
    unsigned char   al, ah, bl, bh, cl, ch, dl, dh;
};

union   REGS    {
    struct  WORDREGS x;
    struct  BYTEREGS h;
};

struct  SREGS   {
    unsigned int    es;
    unsigned int    cs;
    unsigned int    ss;
    unsigned int    ds;
};

struct  REGPACK {
    unsigned    r_ax, r_bx, r_cx, r_dx;
    unsigned    r_bp, r_si, r_di, r_ds, r_es, r_flags;
};

#endif  /* _REG_DEFS */

typedef struct {
    char    ds_drive;          /* do not change    */
    char    ds_pattern [13];   /*  these fields,       */
    char    ds_reserved [7];   /*   Microsoft reserved */
    char    ds_attrib;
    short   ds_time;
    short   ds_date;
    long    ds_size;
    char    ds_nameZ [13];     /* result of the search, asciiz */
}   dosSearchInfo;  /* used with DOS functions 4E, 4F   */


#ifndef _FFBLK_DEF
#define _FFBLK_DEF
struct  ffblk   {
    char        ff_reserved[21];
    char        ff_attrib;
    unsigned    ff_ftime;
    unsigned    ff_fdate;
    long        ff_fsize;
    char        ff_name[13];
};
#endif  /* _FFBLK_DEF */

/* The MSC find_t structure corresponds exactly to the ffblk structure */
struct find_t {
    char     reserved[21];      /* Microsoft reserved - do not change */
    char     attrib;            /* attribute byte for matched file */
    unsigned wr_time;           /* time of last write to file */
    unsigned wr_date;           /* date of last write to file */
    long     size;              /* size of file */
    char     name[13];          /* asciiz name of matched file */
};

/* axret values for _hardresume() */

#define _HARDERR_IGNORE 0   /* ignore error */
#define _HARDERR_RETRY  1   /* retry the operation */
#define _HARDERR_ABORT  2   /* abort program */
#define _HARDERR_FAIL   3   /* fail the operation */

#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

#ifdef __cplusplus
extern "C" {
#endif

int         _Cdecl absread( int __drive, int __nsects, long __lsect,
                            void *__buffer );
int         _Cdecl abswrite( int __drive, int __nsects, long __lsect,
                             void *__buffer );
int         _Cdecl allocmem( unsigned __size, unsigned *__segp );
int         _CType bdos( int __dosfun, unsigned __dosdx, unsigned __dosal );
int         _CType bdosptr( int __dosfun, void *__argument, unsigned __dosal );
struct COUNTRY *_Cdecl country( int __xcode, struct COUNTRY *__cp);
void        _Cdecl ctrlbrk( int _Cdecl( *handler )( void ));
void        _CType delay( unsigned __milliseconds );
void        _Cdecl disable( void );
int         _Cdecl dosexterr( struct DOSERROR *__eblkp );
long        _Cdecl dostounix( struct date *__d, struct time *__t );

unsigned    _Cdecl _dos_allocmem( unsigned __size, unsigned *__segp );
unsigned    _Cdecl _dos_close ( int __fd );
unsigned    _Cdecl _dos_creat( const char *__pathP, unsigned __attr, 
                    int *__fd );
unsigned    _Cdecl _dos_creatnew( const char *__pathP, unsigned __attr,
                    int *__fd );
unsigned    _Cdecl _dos_findfirst( const char *__path,
                    unsigned __attrib,
                    struct find_t *__finfo );
unsigned    _Cdecl _dos_findnext( struct find_t *__finfo );
unsigned    _Cdecl _dos_freemem( unsigned __segx );
void        _Cdecl _dos_getdate( struct dosdate_t *__datep );
unsigned    _Cdecl _dos_getdiskfree( unsigned __drive,
                      struct diskfree_t *__dtable);
void        _Cdecl _dos_getdrive( unsigned *__drive );
unsigned    _Cdecl _dos_getfileattr( const char *__filename,
                      unsigned *__attrib );
unsigned    _Cdecl _dos_getftime( int __fd, unsigned *__date,
                   unsigned *__time );
void        _Cdecl _dos_gettime( struct dostime_t *__timep );
void        _Cdecl _dos_keep(unsigned char __status, unsigned __size);
unsigned    _Cdecl _dos_open( const char *__pathP, unsigned __oflag,
                   int *__fd );
unsigned    _Cdecl _dos_read( int __fd, void far *__buf, unsigned __len,
                   unsigned *__nread );
unsigned    _Cdecl _dos_setblock( unsigned __size, unsigned __segx,
                   unsigned *__maxp );
unsigned    _Cdecl _dos_setdate( struct dosdate_t *__datep );
void        _Cdecl _dos_setdrive( unsigned __drive, unsigned *__ndrives );
unsigned    _Cdecl _dos_setfileattr( const char *__filename,
                      unsigned __attrib);
unsigned    _Cdecl _dos_setftime( int __fd, unsigned __date, unsigned __time );
unsigned    _Cdecl _dos_settime( struct dostime_t *__timep );
unsigned    _Cdecl _dos_write( int __fd, void far *__buf, unsigned __len,
                unsigned *__nread );

void        __emit__( unsigned char __byte, ...);
void        _Cdecl enable( void );

int         _Cdecl freemem( unsigned __segx );
int         _Cdecl getcbrk( void );
void        _CType getdate( struct date *__datep );
void        _Cdecl getdfree( unsigned char __drive,
                    struct dfree *__dtable );
int         _Cdecl _getdrive( void );
void        _Cdecl getfat( unsigned char __drive,
                    struct fatinfo *__dtable );
void        _Cdecl getfatd( struct fatinfo *__dtable );
unsigned    _Cdecl getpsp( void );
int         _Cdecl getswitchar( void );
void        _CType gettime( struct time *__timep );
int         _Cdecl getverify( void );

#ifdef __cplusplus
void        _Cdecl _harderr( void _Cdecl (far *__fptr)( unsigned __deverr,
                             unsigned __doserr, unsigned far *__hdr) );
#else
void        _Cdecl _harderr( void _Cdecl (far *__fptr)( ) );
#endif
void        _Cdecl _hardresume( int __axret );
void        _Cdecl _hardretn( int __retn );

#ifdef __cplusplus
void        _CType harderr( int _Cdecl( *__handler )( int __errval, int __ax, 
                            int __bp, int __si) );
#else
void        _CType harderr( int _Cdecl( *__handler )( ) );
#endif
void        _CType hardresume( int __axret );
void        _CType hardretn( int __retn );

#ifndef _PORT_DEFS
int         _Cdecl inp( unsigned __portid );
unsigned    _Cdecl inpw( unsigned __portid );
#endif

int         _Cdecl inport( int __portid );
#ifndef _PORT_DEFS
unsigned char _Cdecl inportb( int __portid );
#endif
int         _Cdecl int86( int __intno,
                          union REGS *__inregs,
                          union REGS *__outregs );
int         _Cdecl int86x( int __intno,
                           union REGS *__inregs,
                           union REGS *__outregs,
                           struct SREGS *__segregs );
int         _Cdecl intdos( union REGS *__inregs,
                           union REGS *__outregs );
int         _Cdecl intdosx( union REGS *__inregs,
                                     union REGS *__outregs,
                                     struct SREGS *__segregs );
void        _Cdecl intr( int __intno, struct REGPACK *__preg );

void        _Cdecl keep( unsigned char __status, unsigned __size );
void        _Cdecl nosound( void );

#ifndef _PORT_DEFS
int         _Cdecl outp( unsigned __portid, int __value );
unsigned    _Cdecl outpw( unsigned __portid, unsigned __value );
#endif

void        _Cdecl outport( int __portid, int __value );
#ifndef _PORT_DEFS
void        _Cdecl outportb( int __portid, unsigned char __value );
#endif
char * _Cdecl parsfnm( const char *__cmdline,
                       struct fcb *__fcb, int __opt );
int         _Cdecl peek( unsigned __segment, unsigned __offset );
char        _Cdecl peekb( unsigned __segment, unsigned __offset );
void        _Cdecl poke( unsigned __segment, unsigned __offset, int __value);
void        _Cdecl pokeb( unsigned __segment,
                          unsigned __offset, char __value );
int         _Cdecl randbrd( struct fcb *__fcb, int __rcnt );
int         _Cdecl randbwr( struct fcb *__fcb, int __rcnt );
void        _Cdecl segread( struct SREGS *__segp );
int         _Cdecl setblock( unsigned __segx, unsigned __newsize );
int         _Cdecl setcbrk( int __cbrkvalue );
void        _Cdecl setdate( struct date *__datep );
void        _Cdecl setswitchar( char __ch );
void        _Cdecl settime( struct time *__timep );
void        _Cdecl setverify( int __value );
void        _Cdecl sleep( unsigned __seconds );
void        _Cdecl sound( unsigned __frequency );
void        _Cdecl unixtodos( long __time, struct date *__d,
                              struct time *__t );
int         _CType unlink( const char *__path );

    /* These are in-line functions.  These prototypes just clean up
       some syntax checks and code generation.
     */

void        _Cdecl          __cli__( void );
void        _Cdecl          __sti__( void );
void        _Cdecl          __int__( int __interruptnum );

#define disable( ) __emit__( (char )( 0xfa ) )
#define _disable( ) __emit__( (char )( 0xfa ) ) /* MSC name */
#define enable( )  __emit__( (char )( 0xfb ) )
#define _enable( )  __emit__( (char )( 0xfb ) ) /* MSC name */

#define geninterrupt( i ) __int__( i )      /* Interrupt instruction */

#ifndef _PORT_DEFS
#define _PORT_DEFS

unsigned char _Cdecl    __inportb__( int __portid );
unsigned int _Cdecl     __inportw__( int __portid );
void        _Cdecl      __outportb__( int __portid, unsigned char __value );
void        _Cdecl      __outportw__( int __portid, unsigned int __value );

#define inportb         __inportb__
#define outportb        __outportb__

/* MSC-compatible macros for port I/O */
#define inp( portid )      __inportb__( portid )
#define outp( portid,v )  (__outportb__( portid,v ), (int)_AL)
#define inpw( portid )     __inportw__( portid )
#define outpw( portid,v ) (__outportw__( portid,v ), (unsigned)_AX)

#endif  /* _PORT_DEFS */

#if !__STDC__

extern  unsigned    _Cdecl  _ovrbuffer;
int cdecl far _OvrInitEms( unsigned __emsHandle, unsigned __emsFirst,
                           unsigned __emsPages );
int cdecl far _OvrInitExt( unsigned long __extStart,
                           unsigned long __extLength );

char far *cdecl getdta( void );
void      cdecl setdta( char far *__dta );

#define MK_FP( seg,ofs )( (void _seg * )( seg ) +( void near * )( ofs ))
#define FP_SEG( fp )( (unsigned )( void _seg * )( void far * )( fp ))
#define FP_OFF( fp )( (unsigned )( fp ))

#ifdef __cplusplus
void        _Cdecl _chain_intr ( void interrupt (far *__target)( ... ));
void interrupt( far * _Cdecl _dos_getvect( unsigned __interruptno ))( ... );
void interrupt( far * _CType getvect( int __interruptno ))( ... );
void        _Cdecl _dos_setvect( unsigned __interruptno,
                                 void interrupt( far *__isr )( ... ));
void        _CType setvect( int __interruptno,
                            void interrupt( far *__isr )( ... ));
int  inline _Cdecl peek( unsigned __segment, unsigned __offset )  
                  { return( *( (int  far* )MK_FP( __segment, __offset )) ); }
char inline _Cdecl peekb( unsigned __segment, unsigned __offset ) 
                  { return( *( (char far* )MK_FP( __segment, __offset )) ); }
void inline _Cdecl poke( unsigned __segment, unsigned __offset, int __value )  
               {( *( (int  far* )MK_FP( __segment, __offset )) = __value ); }
void inline _Cdecl pokeb( unsigned __segment, unsigned __offset, char __value )   
               {( *( (char far* )MK_FP( __segment, __offset )) = __value ); }
#else
void        _Cdecl _chain_intr ( void interrupt (far *__target)( ));
void interrupt( far * _Cdecl _dos_getvect( unsigned __interruptno ))( );
void interrupt( far * _CType getvect( int __interruptno ))( );
void        _Cdecl _dos_setvect( unsigned __interruptno,
                void interrupt( far *__isr )( ));
void        _CType setvect( int __interruptno,
                void interrupt( far *__isr )( ) );
#define peek( a,b )( *( (int  far* )MK_FP( (a ),( b )) ))
#define peekb( a,b )( *( (char far* )MK_FP( (a ),( b )) ))
#define poke( a,b,c )( *( (int  far* )MK_FP( (a ),( b )) ) =( int )( c ))
#define pokeb( a,b,c )( *( (char far* )MK_FP( (a ),( b )) ) =( char )( c ))
#endif  /* __cplusplus */

#endif  /* !__STDC__ */


#ifdef __cplusplus
}
#endif

#endif  /* __DOS_H */


/*  conio.h

    Direct MSDOS console input/output.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined(__CONIO_H)
#define __CONIO_H

#if !defined(__DEFS_H)
#include <_defs.h>
#endif

#define _NOCURSOR      0
#define _SOLIDCURSOR   1
#define _NORMALCURSOR  2

struct text_info {
    unsigned char winleft;
    unsigned char wintop;
    unsigned char winright;
    unsigned char winbottom;
    unsigned char attribute;
    unsigned char normattr;
    unsigned char currmode;
    unsigned char screenheight;
    unsigned char screenwidth;
    unsigned char curx;
    unsigned char cury;
};

enum text_modes { LASTMODE=-1, BW40=0, C40, BW80, C80, MONO=7, C4350=64 };

#if !defined(__COLORS)
#define __COLORS

enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};
#endif

#define BLINK       128 /* blink bit */

extern   int _Cdecl directvideo;
extern   int _Cdecl _wscroll;

#ifdef __cplusplus
extern "C" {
#endif

void        _Cdecl clreol( void );
void        _Cdecl clrscr( void );
void        _Cdecl gotoxy( int __x, int __y );
int         _Cdecl wherex( void );
int         _Cdecl wherey( void );
int         _Cdecl getch( void );
int         _Cdecl getche( void );
int         _Cdecl kbhit( void );
int         _Cdecl putch( int __c );

#ifndef _PORT_DEFS
int         _Cdecl inp( unsigned __portid );
unsigned    _Cdecl inpw( unsigned __portid );
int         _Cdecl outp( unsigned __portid, int __value );
unsigned    _Cdecl outpw( unsigned __portid, unsigned __value );
unsigned char _Cdecl inportb( int __portid );
void        _Cdecl outportb( int __portid, unsigned char __value );
#endif  /* !_PORT_DEFS */

int         _Cdecl inport( int __portid );
void        _Cdecl outport( int __portid, int __value );

void        _Cdecl delline( void );
int         _Cdecl gettext( int __left, int __top,
                            int __right, int __bottom,
                            void *__destin);
void        _Cdecl gettextinfo (struct text_info *__r );
void        _Cdecl highvideo( void );
void        _Cdecl insline( void );
void        _Cdecl lowvideo( void );
int         _Cdecl movetext( int __left, int __top,
                             int __right, int __bottom,
                             int __destleft, int __desttop );
void        _Cdecl normvideo( void );
int         _Cdecl puttext( int __left, int __top,
                            int __right, int __bottom,
                            void *__source );
void        _Cdecl textattr( int __newattr );
void        _Cdecl textbackground( int __newcolor );
void        _Cdecl textcolor( int __newcolor );
void        _Cdecl textmode( int __newmode );
void        _Cdecl window( int __left, int __top, int __right, int __bottom);

void        _Cdecl _setcursortype( int __cur_t );
char * _Cdecl cgets( char *__str );
int         _Cdecl cprintf( const char *__format, ... );
int         _Cdecl cputs( const char *__str );
int         _Cdecl cscanf( const char *__format, ... );
char * _Cdecl getpass( const char *__prompt );
int         _Cdecl ungetch( int __ch );

#ifndef _PORT_DEFS
#define _PORT_DEFS

    /* These are in-line functions.  These prototypes just clean up
       some syntax checks and code generation.
     */
unsigned char _Cdecl    __inportb__( int __portid );
unsigned int _Cdecl     __inportw__( int __portid );
void        _Cdecl      __outportb__( int __portid, unsigned char __value );
void        _Cdecl      __outportw__( int __portid, unsigned int __value );

#define inportb         __inportb__
#define inportw         __inportw__
#define outportb        __outportb__
#define outportw        __outportw__

#define inp( portid )      __inportb__( portid )
#define outp( portid,v )  (__outportb__( portid,v ), (int)_AL)
#define inpw( portid )     __inportw__( portid )
#define outpw( portid,v ) (__outportw__( portid,v ), (unsigned)_AX)

#endif  /* _PORT_DEFS */

#ifdef __cplusplus
}
#endif

#endif  /* __CONIO_H */


/*  graphics.h

    Definitions for Graphics Package.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined(__GRAPHICS_H)
#define __GRAPHICS_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

enum graphics_errors {      /* graphresult error return codes */
    grOk                =   0,
    grNoInitGraph       =  -1,
    grNotDetected       =  -2,
    grFileNotFound      =  -3,
    grInvalidDriver     =  -4,
    grNoLoadMem         =  -5,
    grNoScanMem         =  -6,
    grNoFloodMem        =  -7,
    grFontNotFound      =  -8,
    grNoFontMem         =  -9,
    grInvalidMode       = -10,
    grError             = -11,   /* generic error */
    grIOerror           = -12,
    grInvalidFont       = -13,
    grInvalidFontNum    = -14,
    grInvalidVersion    = -18
};

enum graphics_drivers {     /* define graphics drivers */
    DETECT,         /* requests autodetection */
    CGA, MCGA, EGA, EGA64, EGAMONO, IBM8514,    /* 1 - 6 */
    HERCMONO, ATT400, VGA, PC3270,          /* 7 - 10 */
    CURRENT_DRIVER = -1
};

enum graphics_modes {       /* graphics modes for each driver */
    CGAC0      = 0,  /* 320x200 palette 0; 1 page   */
    CGAC1      = 1,  /* 320x200 palette 1; 1 page   */
    CGAC2      = 2,  /* 320x200 palette 2: 1 page   */
    CGAC3      = 3,  /* 320x200 palette 3; 1 page   */
    CGAHI      = 4,  /* 640x200 1 page          */
    MCGAC0     = 0,  /* 320x200 palette 0; 1 page   */
    MCGAC1     = 1,  /* 320x200 palette 1; 1 page   */
    MCGAC2     = 2,  /* 320x200 palette 2; 1 page   */
    MCGAC3     = 3,  /* 320x200 palette 3; 1 page   */
    MCGAMED    = 4,  /* 640x200 1 page          */
    MCGAHI     = 5,  /* 640x480 1 page          */
    EGALO      = 0,  /* 640x200 16 color 4 pages    */
    EGAHI      = 1,  /* 640x350 16 color 2 pages    */
    EGA64LO    = 0,  /* 640x200 16 color 1 page     */
    EGA64HI    = 1,  /* 640x350 4 color  1 page     */
    EGAMONOHI  = 0,  /* 640x350 64K on card, 1 page - 256K on card, 4 pages */
    HERCMONOHI = 0,  /* 720x348 2 pages         */
    ATT400C0   = 0,  /* 320x200 palette 0; 1 page   */
    ATT400C1   = 1,  /* 320x200 palette 1; 1 page   */
    ATT400C2   = 2,  /* 320x200 palette 2; 1 page   */
    ATT400C3   = 3,  /* 320x200 palette 3; 1 page   */
    ATT400MED  = 4,  /* 640x200 1 page          */
    ATT400HI   = 5,  /* 640x400 1 page          */
    VGALO      = 0,  /* 640x200 16 color 4 pages    */
    VGAMED     = 1,  /* 640x350 16 color 2 pages    */
    VGAHI      = 2,  /* 640x480 16 color 1 page     */
    PC3270HI   = 0,  /* 720x350 1 page          */
    IBM8514LO  = 0,  /* 640x480 256 colors      */
    IBM8514HI  = 1   /*1024x768 256 colors      */
};

/* Colors for setpalette and setallpalette */

#if !defined(__COLORS)
#define __COLORS

enum COLORS {
    BLACK,          /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,       /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};
#endif

enum CGA_COLORS {
    CGA_LIGHTGREEN     = 1,     /* Palette C0 Color Names   */
    CGA_LIGHTRED       = 2,
    CGA_YELLOW         = 3,

    CGA_LIGHTCYAN      = 1,     /* Palette C1 Color Names   */
    CGA_LIGHTMAGENTA   = 2,
    CGA_WHITE          = 3,

    CGA_GREEN          = 1,     /* Palette C2 Color Names   */
    CGA_RED            = 2,
    CGA_BROWN          = 3,

    CGA_CYAN           = 1,     /* Palette C3 Color Names   */
    CGA_MAGENTA        = 2,
    CGA_LIGHTGRAY      = 3
};


enum EGA_COLORS {
    EGA_BLACK        =  0,      /* dark colors */
    EGA_BLUE         =  1,
    EGA_GREEN        =  2,
    EGA_CYAN         =  3,
    EGA_RED          =  4,
    EGA_MAGENTA      =  5,
    EGA_BROWN        =  20,
    EGA_LIGHTGRAY    =  7,
    EGA_DARKGRAY     =  56,     /* light colors */
    EGA_LIGHTBLUE    =  57,
    EGA_LIGHTGREEN   =  58,
    EGA_LIGHTCYAN    =  59,
    EGA_LIGHTRED     =  60,
    EGA_LIGHTMAGENTA =  61,
    EGA_YELLOW       =  62,
    EGA_WHITE        =  63
};

enum line_styles {      /* Line styles for get/setlinestyle */
    SOLID_LINE   = 0,
    DOTTED_LINE  = 1,
    CENTER_LINE  = 2,
    DASHED_LINE  = 3,
    USERBIT_LINE = 4,   /* User defined line style */
};

enum line_widths {      /* Line widths for get/setlinestyle */
    NORM_WIDTH  = 1,
    THICK_WIDTH = 3,
};

enum font_names {
    DEFAULT_FONT        = 0,    /* 8x8 bit mapped font */
    TRIPLEX_FONT        = 1,    /* "Stroked" fonts */
    SMALL_FONT          = 2,
    SANS_SERIF_FONT     = 3,
    GOTHIC_FONT         = 4,
    SCRIPT_FONT         = 5,        
    SIMPLEX_FONT        = 6,       
    TRIPLEX_SCR_FONT    = 7,
    COMPLEX_FONT        = 8,       
    EUROPEAN_FONT       = 9,  
    BOLD_FONT           = 10      
};

#define HORIZ_DIR   0   /* left to right */
#define VERT_DIR    1   /* bottom to top */

#define USER_CHAR_SIZE  0   /* user-defined char size */

enum fill_patterns {    /* Fill patterns for get/setfillstyle */
    EMPTY_FILL,         /* fills area in background color */
    SOLID_FILL,         /* fills area in solid fill color */
    LINE_FILL,          /* --- fill */
    LTSLASH_FILL,       /* /// fill */
    SLASH_FILL,         /* /// fill with thick lines */
    BKSLASH_FILL,       /* \\\ fill with thick lines */
    LTBKSLASH_FILL,     /* \\\ fill */
    HATCH_FILL,         /* light hatch fill */
    XHATCH_FILL,        /* heavy cross hatch fill */
    INTERLEAVE_FILL,    /* interleaving line fill */
    WIDE_DOT_FILL,      /* Widely spaced dot fill */
    CLOSE_DOT_FILL,     /* Closely spaced dot fill */
    USER_FILL           /* user defined fill */
};

enum putimage_ops {     /* BitBlt operators for putimage */
    COPY_PUT,           /* MOV */
    XOR_PUT,            /* XOR */
    OR_PUT,             /* OR  */
    AND_PUT,            /* AND */
    NOT_PUT             /* NOT */
};

enum text_just {        /* Horizontal and vertical justification
                           for settextjustify */
    LEFT_TEXT   = 0,
    CENTER_TEXT = 1,
    RIGHT_TEXT  = 2,

    BOTTOM_TEXT = 0,
     /* CENTER_TEXT = 1,  already defined above */
    TOP_TEXT    = 2
};


#define MAXCOLORS 15

struct palettetype {
    unsigned char size;
    signed char colors[MAXCOLORS+1];
};

struct linesettingstype {
    int linestyle;
    unsigned upattern;
    int thickness;
};

struct textsettingstype {
    int font;
    int direction;
    int charsize;
    int horiz;
    int vert;
};

struct fillsettingstype {
    int pattern;
    int color;
};

struct pointtype {
    int x, y;
};

struct viewporttype {
    int left, top, right, bottom;
    int clip;
};

struct arccoordstype {
    int x, y;
    int xstart, ystart, xend, yend;
};

#ifdef __cplusplus
extern "C" {
#endif
void       far _Cdecl arc(int __x, int __y, int __stangle, int __endangle,
              int __radius);
void       far _Cdecl bar(int __left, int __top, int __right, int __bottom);
void       far _Cdecl bar3d(int __left, int __top, int __right, int __bottom,
                int __depth, int __topflag);
void       far _Cdecl circle(int __x, int __y, int __radius);
void       far _Cdecl cleardevice(void);
void       far _Cdecl clearviewport(void);
void       far _Cdecl closegraph(void);
void       far _Cdecl detectgraph(int far *__graphdriver,int far *__graphmode);
void       far _Cdecl drawpoly(int __numpoints, const int far *__polypoints);
void       far _Cdecl ellipse(int __x, int __y, int __stangle, int __endangle,
                  int __xradius, int __yradius);
void       far _Cdecl fillellipse( int __x, int __y, int __xradius, int __yradius );
void       far _Cdecl fillpoly(int __numpoints, const int far *__polypoints);
void       far _Cdecl floodfill(int __x, int __y, int __border);
void       far _Cdecl getarccoords(struct arccoordstype far *__arccoords);
void       far _Cdecl getaspectratio(int far *__xasp, int far *__yasp);
int    far _Cdecl getbkcolor(void);
int    far _Cdecl getcolor(void);
struct palettetype far * far _Cdecl getdefaultpalette( void );
char *     far _Cdecl getdrivername( void );
void       far _Cdecl getfillpattern(char far *__pattern);
void       far _Cdecl getfillsettings(struct fillsettingstype far *__fillinfo);
int    far _Cdecl getgraphmode(void);
void       far _Cdecl getimage(int __left, int __top, int __right, int __bottom,
                   void far *__bitmap);
void       far _Cdecl getlinesettings(struct linesettingstype far *__lineinfo);
int    far _Cdecl getmaxcolor(void);
int    far _Cdecl getmaxmode(void);
int    far _Cdecl getmaxx(void);
int    far _Cdecl getmaxy(void);
char *     far _Cdecl getmodename( int __mode_number );
void       far _Cdecl getmoderange(int __graphdriver, int far *__lomode,
                   int far *__himode);
unsigned   far _Cdecl getpixel(int __x, int __y);
void       far _Cdecl getpalette(struct palettetype far *__palette);
int    far _Cdecl getpalettesize( void );
void       far _Cdecl gettextsettings(struct textsettingstype far *__texttypeinfo);
void       far _Cdecl getviewsettings(struct viewporttype far *__viewport);
int    far _Cdecl getx(void);
int    far _Cdecl gety(void);
void       far _Cdecl graphdefaults(void);
char *     far _Cdecl grapherrormsg(int __errorcode);
void       far _Cdecl _graphfreemem(void far *__ptr, unsigned __size);
void far * far _Cdecl _graphgetmem(unsigned __size);
int    far _Cdecl graphresult(void);
unsigned   far _Cdecl imagesize(int __left, int __top, int __right, int __bottom);
void       far _Cdecl initgraph(int  far *__graphdriver,
                int  far *__graphmode,
                const char far *__pathtodriver);
int    far _Cdecl installuserdriver( const char far *__name,
                int huge (*detect)(void) );
int    far _Cdecl installuserfont( const char far *__name );
void       far _Cdecl line(int __x1, int __y1, int __x2, int __y2);
void       far _Cdecl linerel(int __dx, int __dy);
void       far _Cdecl lineto(int __x, int __y);
void       far _Cdecl moverel(int __dx, int __dy);
void       far _Cdecl moveto(int __x, int __y);
void       far _Cdecl outtext(const char far *__textstring);
void       far _Cdecl outtextxy(int __x, int __y, const char far *__textstring);
void       far _Cdecl pieslice(int __x, int __y, int __stangle, int __endangle,
                   int __radius);
void       far _Cdecl putimage(int __left, int __top, const void far *__bitmap,
                int __op);
void       far _Cdecl putpixel(int __x, int __y, int __color);
void       far _Cdecl rectangle(int __left, int __top, int __right, int __bottom);
void       far _Cdecl restorecrtmode(void);
void       far _Cdecl sector( int __X, int __Y, int __StAngle, int __EndAngle,
                  int __XRadius, int __YRadius );
void       far _Cdecl setactivepage(int __page);
void       far _Cdecl setallpalette(const struct palettetype far *__palette);
void       far _Cdecl setaspectratio( int __xasp, int __yasp );
void       far _Cdecl setbkcolor(int __color);
void       far _Cdecl setcolor(int __color);
void       far _Cdecl setfillpattern(const char far *__upattern, int __color);
void       far _Cdecl setfillstyle(int __pattern, int __color);
unsigned   far _Cdecl setgraphbufsize(unsigned __bufsize);
void       far _Cdecl setgraphmode(int __mode);
void       far _Cdecl setlinestyle(int __linestyle, unsigned __upattern,
                   int __thickness);
void       far _Cdecl setpalette(int __colornum, int __color);
void       far _Cdecl setrgbpalette(int __colornum,
                    int __red, int __green, int __blue);
void       far _Cdecl settextjustify(int __horiz, int __vert);
void       far _Cdecl settextstyle(int __font, int __direction, int __charsize);
void       far _Cdecl setusercharsize(int __multx, int __divx,
                      int __multy, int __divy);
void       far _Cdecl setviewport(int __left, int __top, int __right, int __bottom,
                  int __clip);
void       far _Cdecl setvisualpage(int __page);
void       far _Cdecl setwritemode( int __mode );
int    far _Cdecl textheight(const char far *__textstring);
int    far _Cdecl textwidth(const char far *__textstring);

/***** graphics drivers *****/

int        _Cdecl registerbgidriver(void (*driver)(void));
int    far _Cdecl registerfarbgidriver(void far *__driver);

/* !!        These "functions" are NOT user-callable          !! */
/* !! They are there just so you can link in graphics drivers !! */

void           _Cdecl CGA_driver(void);
void           _Cdecl EGAVGA_driver(void);
void           _Cdecl IBM8514_driver(void);
void           _Cdecl Herc_driver(void);
void           _Cdecl ATT_driver(void);
void           _Cdecl PC3270_driver(void);

extern int far _Cdecl CGA_driver_far[];
extern int far _Cdecl EGAVGA_driver_far[];
extern int far _Cdecl IBM8514_driver_far[];
extern int far _Cdecl Herc_driver_far[];
extern int far _Cdecl ATT_driver_far[];
extern int far _Cdecl PC3270_driver_far[];


/***** graphics fonts *****/

int        _Cdecl registerbgifont(void (*font)(void));
int    far _Cdecl registerfarbgifont(void far *__font);

/* !!   These "functions" are NOT user-callable,   !! */
/* !! they are there just so you can link in fonts !! */

void           _Cdecl   triplex_font(void);
void           _Cdecl     small_font(void);
void           _Cdecl sansserif_font(void);
void           _Cdecl    gothic_font(void);

extern int far _Cdecl   triplex_font_far[];
extern int far _Cdecl     small_font_far[];
extern int far _Cdecl sansserif_font_far[];
extern int far _Cdecl    gothic_font_far[];

#ifdef __cplusplus
}
#endif

#endif

/*  math.h

    Definitions for the math floating point package.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef  __MATH_H
#define  __MATH_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#define HUGE_VAL    _huge_dble
extern double _Cdecl _huge_dble;
#define _LHUGE_VAL   _huge_ldble
extern long double _Cdecl _huge_ldble;

#ifdef __cplusplus
extern "C" {
#endif
double  _Cdecl acos  (double __x);
double  _Cdecl asin  (double __x);
double  _Cdecl atan  (double __x);
double  _Cdecl atan2 (double __y, double __x);
double  _Cdecl ceil  (double __x);
double  _Cdecl cos   (double __x);
double  _Cdecl cosh  (double __x);
double  _Cdecl exp   (double __x);
double  _Cdecl fabs  (double __x);
double  _Cdecl __fabs__  (double __x);          /* Intrinsic */
double  _Cdecl floor (double __x);
double  _Cdecl fmod  (double __x, double __y);
double  _Cdecl frexp (double __x, int *__exponent);
double  _Cdecl ldexp (double __x, int __exponent);
double  _Cdecl log   (double __x);
double  _Cdecl log10 (double __x);
double  _Cdecl modf  (double __x, double *__ipart);
double  _Cdecl pow   (double __x, double __y);
double  _Cdecl sin   (double __x);
double  _Cdecl sinh  (double __x);
double  _Cdecl sqrt  (double __x);
double  _Cdecl tan   (double __x);
double  _Cdecl tanh  (double __x);

long double _Cdecl acosl  (long double __x);
long double _Cdecl asinl  (long double __x);
long double _Cdecl atan2l (long double __x, long double __y);
long double _Cdecl atanl  (long double __x);
long double _Cdecl ceill  (long double __x);
long double _Cdecl coshl  (long double __x);
long double _Cdecl cosl   (long double __x);
long double _Cdecl expl   (long double __x);
long double _Cdecl fabsl  (long double __x);
long double _Cdecl floorl (long double __x);
long double _Cdecl fmodl  (long double __x, long double __y);
long double _Cdecl frexpl (long double __x, int *__exponent);
long double _Cdecl ldexpl (long double __x, int __exponent);
long double _Cdecl log10l (long double __x);
long double _Cdecl logl   (long double __x);
long double _Cdecl modfl  (long double __x, long double *__ipart);
long double _Cdecl powl   (long double __x, long double __y);
long double _Cdecl sinhl  (long double __x);
long double _Cdecl sinl   (long double __x);
long double _Cdecl sqrtl  (long double __x);
long double _Cdecl tanhl  (long double __x);
long double _Cdecl tanl   (long double __x);

typedef enum
{
    DOMAIN = 1,    /* argument domain error -- log (-1)        */
    SING,          /* argument singularity  -- pow (0,-2))     */
    OVERFLOW,      /* overflow range error  -- exp (1000)      */
    UNDERFLOW,     /* underflow range error -- exp (-1000)     */
    TLOSS,         /* total loss of significance -- sin(10e70) */
    PLOSS,         /* partial loss of signif. -- not used      */
    STACKFAULT     /* floating point unit stack overflow       */
}   _mexcep;

#ifdef __cplusplus
}
#endif


#if !__STDC__

struct  exception 
{
    int type;
    char   *name;
    double  arg1, arg2, retval;
};

struct  _exceptionl
{
    int type;
    char   *name;
    long double  arg1, arg2, retval;
};

#ifdef __cplusplus
extern "C" {
#endif
int     _Cdecl abs   (int __x);
double  _Cdecl atof  (const char *__s);
double  _Cdecl hypot (double __x, double __y);
long    _Cdecl labs  (long __x);
int     _Cdecl matherr (struct exception *__e);
double  _Cdecl poly  (double __x, int __degree, double *__coeffs);
double  _Cdecl pow10 (int __p);
int     _Cdecl _matherrl (struct _exceptionl *__e);

long double _Cdecl _atold (const char *__s);
long double _Cdecl hypotl (long double __x, long double __y);
long double _Cdecl polyl  (long double __x, int __degree, long double *__coeffs);
long double _Cdecl pow10l (int __p);

#ifdef __cplusplus
    /* use class complex instead of cabs in C++ */
#else
struct complex      /* as used by "cabs" function */
{
    double  x, y;
};

struct _complexl    /* as used by "cabsl" function */
{
    long double  x, y;
};

#define cabs(z)     (hypot  ((z).x, (z).y))
#define cabsl(z)    (hypotl ((z).x, (z).y))
#endif

#ifdef __cplusplus
}
#endif

/* Constants rounded for 21 decimals. */
#define M_E         2.71828182845904523536
#define M_LOG2E     1.44269504088896340736
#define M_LOG10E    0.434294481903251827651
#define M_LN2       0.693147180559945309417
#define M_LN10      2.30258509299404568402
#define M_PI        3.14159265358979323846
#define M_PI_2      1.57079632679489661923
#define M_PI_4      0.785398163397448309616
#define M_1_PI      0.318309886183790671538
#define M_2_PI      0.636619772367581343076
#define M_1_SQRTPI  0.564189583547756286948
#define M_2_SQRTPI  1.12837916709551257390
#define M_SQRT2     1.41421356237309504880
#define M_SQRT_2    0.707106781186547524401

#define EDOM    33      /* Math argument */
#define ERANGE  34      /* Result too large */

#endif  /* !__STDC__ */

#endif
