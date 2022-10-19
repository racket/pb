/* scheme.h for Chez Scheme Version 9.9.9-pre-release.10 (pb) */

/* Do not edit this file.  It is automatically generated and */
/* specifically tailored to the version of Chez Scheme named */
/* above.  Always be certain that you have the correct scheme.h */
/* for the version of Chez Scheme you are using. */

/* Warning: Some macros may evaluate arguments more than once. */

#if !defined(_LARGEFILE64_SOURCE) && !defined(FEATURE_WINDOWS)
# define _LARGEFILE64_SOURCE
#endif
#include <stdint.h>

/* Specify declaration of exports. */
#ifdef _WIN32
#  if __cplusplus
#    ifdef SCHEME_IMPORT
#      define EXPORT extern "C" __declspec (dllimport)
#    elif SCHEME_STATIC
#      define EXPORT extern "C"
#    else
#      define EXPORT extern "C" __declspec (dllexport)
#    endif
#  else
#    ifdef SCHEME_IMPORT
#      define EXPORT extern __declspec (dllimport)
#    elif SCHEME_STATIC
#      define EXPORT extern
#    else
#      define EXPORT extern __declspec (dllexport)
#    endif
#  endif
#else
#  if __cplusplus
#    define EXPORT extern "C"
#  else
#    define EXPORT extern
#  endif
#endif

/* Chez Scheme Version and machine type */
#define VERSION "9.9.9-pre-release.10"
#define MACHINE_TYPE "pb"

/* All Scheme objects are of type ptr.  Type iptr and */
/* uptr are signed and unsigned ints of the same size */
/* as a ptr */
typedef uint64_t ptr;
typedef int64_t iptr;
typedef uint64_t uptr;
typedef ptr xptr;

/* The `uptr` and `ptr` types are the same width, but `ptr` */
/* can be either an integer type or a pointer type; it may */
/* be larger than a pointer type. */
/* Use `TO_VOIDP` to get from the `uptr`/`ptr` world to the */
/* C pointer worlds, and use `TO_PTR` to go the other way. */
#ifdef PORTABLE_BYTECODE
# define TO_VOIDP(p) ((void *)(intptr_t)(p))
# define TO_PTR(p) ((ptr)(intptr_t)(p))
#else
# define TO_VOIDP(p) ((void *)(p))
# define TO_PTR(p) ((ptr)(p))
#endif

/* String elements are 32-bit tagged char objects */
typedef uint32_t string_char;

/* Bytevector elements are 8-bit unsigned "octets" */
typedef unsigned char octet;

/* Type predicates */
#define Sfixnump(x) (((uptr)(x)&0x7)==0x0)
#define Scharp(x) (((uptr)(x)&0xFF)==0x16)
#define Snullp(x) ((uptr)(x)==0x26)
#define Seof_objectp(x) ((uptr)(x)==0x36)
#define Sbwp_objectp(x) ((uptr)(x)==0x4E)
#define Sbooleanp(x) (((uptr)(x)&0xF7)==0x6)
#define Spairp(x) (((uptr)(x)&0x7)==0x1)
#define Ssymbolp(x) (((uptr)(x)&0x7)==0x3)
#define Sprocedurep(x) (((uptr)(x)&0x7)==0x5)
#define Sflonump(x) (((uptr)(x)&0x7)==0x2)
#define Svectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x7)==0x0))
#define Sfxvectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0xF)==0x3))
#define Sflvectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0xF)==0xB))
#define Sbytevectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x3)==0x1))
#define Sstringp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x7)==0x2))
#define Sstencil_vectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x3F)==0xE))
#define Ssystem_stencil_vectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x3F)==0x2E))
#define Sany_stencil_vectorp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x1F)==0xE))
#define Sbignump(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x1F)==0x6))
#define Sboxp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0xFF)==0x1E))
#define Sinexactnump(x) ((((uptr)(x)&0x7)==0x7) &&\
    ((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))==0x36))
#define Sexactnump(x) ((((uptr)(x)&0x7)==0x7) &&\
    ((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))==0x56))
#define Sratnump(x) ((((uptr)(x)&0x7)==0x7) &&\
    ((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))==0x16))
#define Sinputportp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x1FF)==0x1DE))
#define Soutputportp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x2FF)==0x2DE))
#define Srecordp(x) ((((uptr)(x)&0x7)==0x7) &&\
    (((uptr)((*((ptr *)TO_VOIDP((uptr)(x)+1))))&0x7)==0x7))

/* Accessors */
#define Sfixnum_value(x) ((iptr)(x)/8)
#define Schar_value(x) ((string_char)((uptr)(x)>>8))
#define Sboolean_value(x) ((x) != Sfalse)
#define Scar(x) (*((ptr *)TO_VOIDP((uptr)(x)+7)))
#define Scdr(x) (*((ptr *)TO_VOIDP((uptr)(x)+15)))
#define Sflonum_value(x) (*((double *)TO_VOIDP((uptr)(x)+6)))
#define Svector_length(x) ((iptr)((uptr)(*((iptr *)TO_VOIDP((uptr)(x)+1)))>>4))
#define Svector_ref(x,i) (((ptr *)TO_VOIDP((uptr)(x)+9))[i])
#define Sfxvector_length(x) ((iptr)((uptr)(*((iptr *)TO_VOIDP((uptr)(x)+1)))>>4))
#define Sfxvector_ref(x,i) (((ptr *)TO_VOIDP((uptr)(x)+9))[i])
#define Sflvector_length(x) ((iptr)((uptr)(*((iptr *)TO_VOIDP((uptr)(x)+1)))>>4))
#define Sflvector_ref(x,i) (((double *)TO_VOIDP((uptr)(x)+9))[i])
#define Sbytevector_length(x) ((iptr)((uptr)(*((iptr *)TO_VOIDP((uptr)(x)+1)))>>3))
#define Sbytevector_u8_ref(x,i) (((octet *)TO_VOIDP((uptr)(x)+9))[i])
/* Warning: Sbytevector_data(x) returns a pointer into x. */
#define Sbytevector_data(x) &Sbytevector_u8_ref(x,0)
#define Sstring_length(x) ((iptr)((uptr)(*((iptr *)TO_VOIDP((uptr)(x)+1)))>>4))
#define Sstring_ref(x,i) Schar_value(((string_char *)TO_VOIDP((uptr)(x)+9))[i])
#define Sunbox(x) (*((ptr *)TO_VOIDP((uptr)(x)+9)))
#define Sstencil_vector_length(x) Spopcount(((uptr)(*((iptr *)TO_VOIDP((uptr)(x)+1))))>>6)
#define Sstencil_vector_ref(x,i) (((ptr *)TO_VOIDP((uptr)(x)+9))[i])
EXPORT iptr Sinteger_value(ptr);
#define Sunsigned_value(x) (uptr)Sinteger_value(x)
EXPORT int32_t Sinteger32_value(ptr);
#define Sunsigned32_value(x) (uint32_t)Sinteger32_value(x)
EXPORT int64_t Sinteger64_value(ptr);
#define Sunsigned64_value(x) (uint64_t)Sinteger64_value(x)

/* Mutators */
EXPORT void Sset_box(ptr, ptr);
EXPORT void Sset_car(ptr, ptr);
EXPORT void Sset_cdr(ptr, ptr);
#define Sstring_set(x,i,c) ((void)((((string_char *)TO_VOIDP((uptr)(x)+9))[i]) = (string_char)(uptr)Schar(c)))
#define Sfxvector_set(x,i,n) ((void)(Sfxvector_ref(x,i) = (n)))
#define Sflvector_set(x,i,n) ((void)(Sflvector_ref(x,i) = (n)))
#define Sbytevector_u8_set(x,i,n) ((void)(Sbytevector_u8_ref(x,i) = (n)))
EXPORT void Svector_set(ptr, iptr, ptr);

/* Constructors */
#define Sfixnum(x) ((ptr)(uptr)((x)*8))
#define Schar(x) ((ptr)(uptr)((x)<<8|0x16))
#define Snil ((ptr)0x26)
#define Strue ((ptr)0xE)
#define Sfalse ((ptr)0x6)
#define Sboolean(x) ((x)?Strue:Sfalse)
#define Sbwp_object ((ptr)0x4E)
#define Seof_object ((ptr)0x36)
#define Svoid ((ptr)0x2E)
EXPORT ptr Scons(ptr, ptr);
EXPORT ptr Sstring_to_symbol(const char *);
EXPORT ptr Ssymbol_to_string(ptr);
EXPORT ptr Sflonum(double);
EXPORT ptr Smake_vector(iptr, ptr);
EXPORT ptr Smake_fxvector(iptr, ptr);
EXPORT ptr Smake_flvector(iptr, ptr);
EXPORT ptr Smake_bytevector(iptr, int);
EXPORT ptr Smake_string(iptr, int);
EXPORT ptr Smake_uninitialized_string(iptr);
EXPORT ptr Sstring(const char *);
EXPORT ptr Sstring_of_length(const char *, iptr);
EXPORT ptr Sstring_utf8(const char*, iptr);
EXPORT ptr Sbox(ptr);
EXPORT ptr Sinteger(iptr);
EXPORT ptr Sunsigned(uptr);
EXPORT ptr Sinteger32(int32_t);
EXPORT ptr Sunsigned32(uint32_t);
EXPORT ptr Sinteger64(int64_t);
EXPORT ptr Sunsigned64(uint64_t);

/* Records */
#define Srecord_uniform_ref(x,i) (((ptr *)TO_VOIDP((uptr)(x)+9))[i])
EXPORT ptr Srecord_type(ptr);
EXPORT ptr Srecord_type_parent(ptr);
EXPORT int Srecord_type_uniformp(ptr);
EXPORT uptr Srecord_type_size(ptr);

/* Miscellaneous */
EXPORT ptr Stop_level_value(ptr);
EXPORT void Sset_top_level_value(ptr, ptr);
EXPORT void Slock_object(ptr);
EXPORT void Sunlock_object(ptr);
EXPORT int Slocked_objectp(ptr);
EXPORT void Sforeign_symbol(const char *, void *);
EXPORT void Sregister_symbol(const char *, void *);

/* Support for calls into Scheme */
EXPORT ptr Scall0(ptr);
EXPORT ptr Scall1(ptr, ptr);
EXPORT ptr Scall2(ptr, ptr, ptr);
EXPORT ptr Scall3(ptr, ptr, ptr, ptr);
EXPORT void Sinitframe(iptr);
EXPORT void Sput_arg(iptr, ptr);
EXPORT ptr Scall(ptr, iptr);
#define Sforeign_callable_entry_point(x) TO_PTR(Svector_ref(x, 2))
EXPORT ptr Sforeign_callable_code_object(void*);

/* Customization support. */
EXPORT const char * Skernel_version(void);
EXPORT void Sretain_static_relocation(void);
EXPORT void Sset_verbose(int);
EXPORT void Sscheme_init(void (*)(void));
EXPORT void Sregister_boot_file(const char *);
EXPORT void Sregister_boot_direct_file(const char *);
EXPORT void Sregister_boot_file_fd(const char *, int fd);
EXPORT void Sregister_boot_file_fd_region(const char *, int fd, iptr offset, iptr len, int close_after);
EXPORT void Sregister_heap_file(const char *);
EXPORT void Scompact_heap(void);
EXPORT void Ssave_heap(const char *, int);
EXPORT void Sbuild_heap(const char *, void (*)(void));
EXPORT void Senable_expeditor(const char *);
EXPORT int Sscheme_start(int, const char *[]);
EXPORT int Sscheme_script(const char *, int, const char *[]);
EXPORT int Sscheme_program(const char *, int, const char *[]);
EXPORT void Sscheme_deinit(void);
EXPORT void Sscheme_register_signal_registerer(void (*f)(int));
EXPORT void Sregister_pbchunks(void **, int, int);

/* Windows support. */
#if defined(FEATURE_WINDOWS)
#include <wchar.h>
EXPORT char * Sgetenv(const char *);
EXPORT wchar_t * Sutf8_to_wide(const char *);
EXPORT char * Swide_to_utf8(const wchar_t *);
#endif

/* Features. */

/* C call prototypes. */
#include <stdint.h>
typedef void (*pb_void_t)();
typedef void (*pb_void_uptr_t)(uptr);
typedef void (*pb_void_int32_t)(int32_t);
typedef void (*pb_void_uint32_t)(uint32_t);
typedef void (*pb_void_voids_t)(void*);
typedef void (*pb_void_uptr_uint32_t)(uptr, uint32_t);
typedef void (*pb_void_int32_uptr_t)(int32_t, uptr);
typedef void (*pb_void_int32_int32_t)(int32_t, int32_t);
typedef void (*pb_void_uint32_uint32_t)(uint32_t, uint32_t);
typedef void (*pb_void_uptr_uptr_t)(uptr, uptr);
typedef void (*pb_void_int32_voids_t)(int32_t, void*);
typedef void (*pb_void_uptr_voids_t)(uptr, void*);
typedef void (*pb_void_voids_voids_t)(void*, void*);
typedef void (*pb_void_uptr_uptr_uptr_t)(uptr, uptr, uptr);
typedef void (*pb_void_uptr_uptr_uptr_uptr_uptr_t)(uptr, uptr, uptr, uptr, uptr);
typedef int32_t (*pb_int32_t)();
typedef int32_t (*pb_int32_int32_t)(int32_t);
typedef int32_t (*pb_int32_uptr_t)(uptr);
typedef int32_t (*pb_int32_voids_t)(void*);
typedef int32_t (*pb_int32_int32_uptr_t)(int32_t, uptr);
typedef int32_t (*pb_int32_uptr_int32_t)(uptr, int32_t);
typedef int32_t (*pb_int32_uptr_uptr_t)(uptr, uptr);
typedef int32_t (*pb_int32_int32_int32_t)(int32_t, int32_t);
typedef int32_t (*pb_int32_int32_voids_t)(int32_t, void*);
typedef int32_t (*pb_int32_voids_int32_t)(void*, int32_t);
typedef int32_t (*pb_int32_double_double_double_double_double_double_t)(double, double, double, double, double, double);
typedef int32_t (*pb_int32_voids_voids_voids_voids_uptr_t)(void*, void*, void*, void*, uptr);
typedef uint32_t (*pb_uint32_t)();
typedef double (*pb_double_double_t)(double);
typedef double (*pb_double_uptr_t)(uptr);
typedef double (*pb_double_double_double_t)(double, double);
typedef int32_t (*pb_int32_uptr_uptr_uptr_uptr_uptr_t)(uptr, uptr, uptr, uptr, uptr);
typedef int32_t (*pb_int32_uptr_uptr_uptr_t)(uptr, uptr, uptr);
typedef uptr (*pb_uptr_t)();
typedef uptr (*pb_uptr_uptr_t)(uptr);
typedef uptr (*pb_uptr_int32_t)(int32_t);
typedef uptr (*pb_uptr_voids_t)(void*);
typedef uptr (*pb_uptr_uptr_uptr_t)(uptr, uptr);
typedef uptr (*pb_uptr_uptr_int32_t)(uptr, int32_t);
typedef uptr (*pb_uptr_int32_uptr_t)(int32_t, uptr);
typedef uptr (*pb_uptr_uptr_int64_t)(uptr, int64_t);
typedef uptr (*pb_uptr_uptr_voids_t)(uptr, void*);
typedef uptr (*pb_uptr_voids_uptr_t)(void*, uptr);
typedef uptr (*pb_uptr_voids_int32_t)(void*, int32_t);
typedef uptr (*pb_uptr_voids_voids_t)(void*, void*);
typedef uptr (*pb_uptr_uptr_int32_int32_t)(uptr, int32_t, int32_t);
typedef uptr (*pb_uptr_uptr_uptr_int32_t)(uptr, uptr, int32_t);
typedef uptr (*pb_uptr_uptr_uptr_uptr_t)(uptr, uptr, uptr);
typedef uptr (*pb_uptr_int32_int32_uptr_t)(int32_t, int32_t, uptr);
typedef uptr (*pb_uptr_voids_int32_int32_t)(void*, int32_t, int32_t);
typedef uptr (*pb_uptr_voids_uptr_uptr_t)(void*, uptr, uptr);
typedef uptr (*pb_uptr_int32_uptr_uptr_uptr_t)(int32_t, uptr, uptr, uptr);
typedef uptr (*pb_uptr_int32_int32_uptr_uptr_t)(int32_t, int32_t, uptr, uptr);
typedef uptr (*pb_uptr_int32_voids_uptr_uptr_t)(int32_t, void*, uptr, uptr);
typedef uptr (*pb_uptr_uptr_uptr_uptr_uptr_t)(uptr, uptr, uptr, uptr);
typedef uptr (*pb_uptr_int32_int32_int32_uptr_t)(int32_t, int32_t, int32_t, uptr);
typedef uptr (*pb_uptr_uptr_voids_uptr_uptr_t)(uptr, void*, uptr, uptr);
typedef uptr (*pb_uptr_uptr_uptr_uptr_uptr_int32_t)(uptr, uptr, uptr, uptr, int32_t);
typedef uptr (*pb_uptr_uptr_uptr_uptr_uptr_uptr_t)(uptr, uptr, uptr, uptr, uptr);
typedef uptr (*pb_uptr_voids_voids_voids_voids_uptr_t)(void*, void*, void*, void*, uptr);
typedef uptr (*pb_uptr_uptr_int32_uptr_uptr_uptr_uptr_t)(uptr, int32_t, uptr, uptr, uptr, uptr);
typedef uptr (*pb_uptr_uptr_uptr_uptr_uptr_uptr_uptr_t)(uptr, uptr, uptr, uptr, uptr, uptr);
typedef uptr (*pb_uptr_uptr_uptr_uptr_uptr_uptr_uptr_int32_t)(uptr, uptr, uptr, uptr, uptr, uptr, int32_t);
typedef uptr (*pb_uptr_uptr_uptr_uptr_uptr_uptr_uptr_uptr_t)(uptr, uptr, uptr, uptr, uptr, uptr, uptr);
typedef uptr (*pb_uptr_double_double_double_double_double_double_t)(double, double, double, double, double, double);
typedef void* (*pb_voids_t)();
typedef void* (*pb_voids_uptr_t)(uptr);

/* Locking macros. */
#define INITLOCK(addr) (*((long *) addr) = 0)
#define UNLOCK(addr) (*((long *) addr) = 0)
#define SPINLOCK(addr) (*((long *) addr) = 1)
#define LOCKED_INCR(addr, res) (res = ((*(uptr*)addr)++ == -1))
#define LOCKED_DECR(addr, res) (res = ((*(uptr*)addr)-- == 1))
