#ifndef __BWT_SUFFIXARRAYTESTCHAR_H
#define __BWT_SUFFIXARRAYTESTCHAR_H

#include <x10rt.h>


namespace x10 { namespace lang { 
template<class TPMGL(T)> class Rail;
} } 
namespace x10 { namespace lang { 
class String;
} } 
namespace x10 { namespace lang { 
class Math;
} } 
namespace bwt { 
class SuffixArrayChar;
} 
namespace x10 { namespace io { 
class Printer;
} } 
namespace x10 { namespace io { 
class Console;
} } 
namespace x10 { namespace lang { 
class Any;
} } 
namespace x10 { namespace compiler { 
class Synthetic;
} } 

namespace bwt { 

class SuffixArrayTestChar : public ::x10::lang::X10Class   {
    public:
    RTT_H_DECLS_CLASS
    
    static x10_boolean isPerm(::x10::lang::Rail< x10_long >* sa, x10_long n);
    static x10_boolean sleq(::x10::lang::Rail< x10_byte >* s1, ::x10::lang::Rail< x10_byte >* s2,
                            x10_long c1, x10_long c2);
    static x10_boolean isSorted(::x10::lang::Rail< x10_long >* sa,
                                ::x10::lang::Rail< x10_byte >* s,
                                x10_long n);
    static void main(::x10::lang::Rail< ::x10::lang::String* >* args);
    virtual ::bwt::SuffixArrayTestChar* bwt__SuffixArrayTestChar____this__bwt__SuffixArrayTestChar(
      );
    void _constructor();
    
    static ::bwt::SuffixArrayTestChar* _make();
    
    virtual void __fieldInitializers_bwt_SuffixArrayTestChar(
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
#endif // BWT_SUFFIXARRAYTESTCHAR_H

namespace bwt { 
class SuffixArrayTestChar;
} 

#ifndef BWT_SUFFIXARRAYTESTCHAR_H_NODEPS
#define BWT_SUFFIXARRAYTESTCHAR_H_NODEPS
#ifndef BWT_SUFFIXARRAYTESTCHAR_H_GENERICS
#define BWT_SUFFIXARRAYTESTCHAR_H_GENERICS
#endif // BWT_SUFFIXARRAYTESTCHAR_H_GENERICS
#endif // __BWT_SUFFIXARRAYTESTCHAR_H_NODEPS
