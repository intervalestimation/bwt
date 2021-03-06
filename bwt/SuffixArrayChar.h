#ifndef __BWT_SUFFIXARRAYCHAR_H
#define __BWT_SUFFIXARRAYCHAR_H

#include <x10rt.h>

#include "parallel_radix_sort.h"

#define X10_LANG_BYTE_H_NODEPS
#include <x10/lang/Byte.h>
#undef X10_LANG_BYTE_H_NODEPS
#define X10_LANG_LONG_H_NODEPS
#include <x10/lang/Long.h>
#undef X10_LANG_LONG_H_NODEPS
#define X10_LANG_LONG_H_NODEPS
#include <x10/lang/Long.h>
#undef X10_LANG_LONG_H_NODEPS
#define X10_LANG_BYTE_H_NODEPS
#include <x10/lang/Byte.h>
#undef X10_LANG_BYTE_H_NODEPS
namespace x10 { namespace lang { 
template<class TPMGL(T)> class Rail;
} } 
namespace x10 { namespace compiler { 
class Native;
} } 
namespace x10 { namespace xrx { 
class Runtime;
} } 
namespace x10 { namespace xrx { 
class FinishState;
} } 
namespace x10 { namespace lang { 
class VoidFun_0_0;
} } 
namespace x10 { namespace compiler { 
class AsyncClosure;
} } 
namespace x10 { namespace lang { 
class CheckedThrowable;
} } 
namespace x10 { namespace io { 
class Printer;
} } 
namespace x10 { namespace io { 
class Console;
} } 
namespace x10 { namespace lang { 
class Any;
} } 
namespace bwt { 
class SuffixArray;
} 
namespace x10 { namespace lang { 
class Unsafe;
} } 
namespace x10 { namespace compiler { 
class Synthetic;
} } 
namespace x10 { namespace compiler { 
class NativeCPPInclude;
} } 

namespace bwt { 

class SuffixArrayChar_Strings {
  public:
    static ::x10::lang::String sl__15264;
    static ::x10::lang::String sl__15265;
};

class SuffixArrayChar : public ::x10::lang::X10Class   {
    public:
    RTT_H_DECLS_CLASS
    
    ::x10::lang::Rail< x10_byte >* FMGL(string);
    
    x10_long FMGL(n);
    
    x10_long FMGL(n0);
    
    x10_long FMGL(n1);
    
    x10_long FMGL(n2);
    
    x10_long FMGL(k);
    
    x10_long FMGL(n02);
    
    ::x10::lang::Rail< x10_long >* FMGL(R);
    
    ::x10::lang::Rail< x10_long >* FMGL(SA12);
    
    ::x10::lang::Rail< x10_byte >* FMGL(SA);
    
    ::x10::lang::Rail< x10_long >* FMGL(SA0);
    
    ::x10::lang::Rail< x10_long >* FMGL(c);
    
    x10_long FMGL(name);
    
    x10_byte FMGL(num_threads);
    
    void _constructor(::x10::lang::Rail< x10_byte >* input, x10_long charsize,
                      x10_byte threads);
    
    static ::bwt::SuffixArrayChar* _make(::x10::lang::Rail< x10_byte >* input,
                                         x10_long charsize, x10_byte threads);
    
    virtual void sortPairs(::x10::lang::Rail< x10_byte >* keys, ::x10::lang::Rail< x10_long >* values,
                           x10_ulong num_elems, x10_int num_threads,
                           x10_byte offset);
    virtual void sortPairsThree(::x10::lang::Rail< x10_byte >* keys,
                                ::x10::lang::Rail< x10_long >* values,
                                x10_ulong num_elems, x10_int num_threads);
    virtual ::x10::lang::Rail< x10_byte >* run();
    virtual x10_byte bwt(x10_long pos);
    virtual void constructSample();
    virtual void sortSample();
    virtual void sortNonSample();
    x10_boolean leq(x10_long a1, x10_long a2, x10_long b1, x10_long b2);
    x10_boolean leq(x10_long a1, x10_long a2, x10_long a3, x10_long b1,
                    x10_long b2, x10_long b3);
    x10_long getI(x10_long t);
    virtual ::bwt::SuffixArrayChar* bwt__SuffixArrayChar____this__bwt__SuffixArrayChar(
      );
    virtual void __fieldInitializers_bwt_SuffixArrayChar(
      );
    
    // Serialization
    public: static const ::x10aux::serialization_id_t _serialization_id;
    
    public: virtual ::x10aux::serialization_id_t _get_serialization_id() {
         return _serialization_id;
    }
    
    public: virtual void _serialize_body(::x10aux::serialization_buffer& buf);
    
    public: static ::x10::lang::Reference* _deserializer(::x10aux::deserialization_buffer& buf);
    
    public: void _deserialize_body(::x10aux::deserialization_buffer& buf);
    
};


} 
#endif // BWT_SUFFIXARRAYCHAR_H

namespace bwt { 
class SuffixArrayChar;
} 

#ifndef BWT_SUFFIXARRAYCHAR_H_NODEPS
#define BWT_SUFFIXARRAYCHAR_H_NODEPS
#ifndef BWT_SUFFIXARRAYCHAR_H_GENERICS
#define BWT_SUFFIXARRAYCHAR_H_GENERICS
#endif // BWT_SUFFIXARRAYCHAR_H_GENERICS
#endif // __BWT_SUFFIXARRAYCHAR_H_NODEPS
