/*************************************************/
/* START of Bwt */
#include <bwt/Bwt.h>

#include <x10/lang/Rail.h>
#include <x10/lang/Byte.h>
#include <x10/lang/Int.h>
#include <x10/lang/Long.h>
#include <x10/util/Timer.h>
#include <bwt/SuffixArrayChar.h>
#include <x10/io/Printer.h>
#include <x10/io/Console.h>
#include <x10/lang/Any.h>
#include <x10/lang/Boolean.h>
#include <x10/lang/String.h>
#include <x10/util/RailBuilder.h>
#include <x10/util/StringBuilder.h>
#include <x10/io/File.h>
#include <x10/lang/Iterator.h>
#include <x10/io/ReaderIterator.h>
#include <x10/compiler/Native.h>
#include <x10/compiler/Synthetic.h>
#include <x10/compiler/NativeCPPInclude.h>
#include <x10/compiler/NativeCPPCompilationUnit.h>
#include <x10/lang/String.h>

//#line 73 "Bwt.x10"
void bwt::Bwt::_constructor(::x10::lang::Rail< x10_byte >* string, x10_int k) {
    
    //#line 74 "Bwt.x10"
    x10_long time = ::x10::lang::RuntimeNatives::currentTimeMillis();
    
    //#line 75 "Bwt.x10"
    ::bwt::SuffixArrayChar* SAC =  (new (::x10aux::alloc_z< ::bwt::SuffixArrayChar>()) ::bwt::SuffixArrayChar());
    (SAC)->::bwt::SuffixArrayChar::_constructor(string, ((x10_long)(k)));
    
    //#line 76 "Bwt.x10"
    ::x10::lang::Rail< x10_long >* sa = SAC->run();
    
    //#line 77 "Bwt.x10"
    x10_long difftime = ((::x10::lang::RuntimeNatives::currentTimeMillis()) - (time));
    
    //#line 78 "Bwt.x10"
    ::x10::io::Console::FMGL(ERR__get)()->printf((&::bwt::Bwt_Strings::sl__5737),
                                                 ::x10aux::class_cast_unchecked< ::x10::lang::Any*>(difftime));
    
    //#line 79 "Bwt.x10"
    x10_long j = (((x10_long)(::x10aux::nullCheck(sa)->FMGL(size))) - (((x10_long)1ll)));
    
    //#line 80 "Bwt.x10"
    if (((j) > (((x10_long)15ll)))) {
        j = ((x10_long)15ll);
    }
    
    //#line 81 "Bwt.x10"
    {
        x10_long i__4917;
        for (i__4917 = ((x10_long)0ll); ((i__4917) <= (j)); i__4917 =
                                                              ((i__4917) + (((x10_long)1ll))))
        {
            
            //#line 82 "Bwt.x10"
            ::x10::io::Console::FMGL(OUT__get)()->x10::io::Printer::println(
              ::x10aux::class_cast_unchecked< ::x10::lang::Any*>(::x10aux::nullCheck(sa)->x10::lang::Rail< x10_long >::__apply(
                                                                   i__4917)));
        }
    }
    
}
::bwt::Bwt* bwt::Bwt::_make(::x10::lang::Rail< x10_byte >* string,
                            x10_int k) {
    ::bwt::Bwt* this_ = new (::x10aux::alloc_z< ::bwt::Bwt>()) ::bwt::Bwt();
    this_->_constructor(string, k);
    return this_;
}



//#line 86 "Bwt.x10"
::x10::lang::Rail< x10_long >* bwt::Bwt::strToRail(::x10::lang::String* input,
                                                   x10_boolean isDigit) {
    
    //#line 87 "Bwt.x10"
    ::x10::util::RailBuilder<x10_long>* strBuilder =  (new (::x10aux::alloc_z< ::x10::util::RailBuilder<x10_long> >()) ::x10::util::RailBuilder<x10_long>());
    (strBuilder)->::x10::util::RailBuilder<x10_long>::_constructor(
      ((x10_long)(::x10aux::nullCheck(input)->x10::lang::String::length())));
    
    //#line 88 "Bwt.x10"
    ::x10::lang::Rail< x10_byte >* inputBytes = ::x10aux::nullCheck(input)->x10::lang::String::bytes();
    
    //#line 89 "Bwt.x10"
    x10_int length = ::x10aux::nullCheck(input)->x10::lang::String::length();
    
    //#line 91 "Bwt.x10"
    x10_long i__3508max__4921 = ((((x10_long)(length))) - (((x10_long)1ll)));
    {
        x10_long i__4922;
        for (i__4922 = ((x10_long)0ll); ((i__4922) <= (i__3508max__4921));
             i__4922 = ((i__4922) + (((x10_long)1ll)))) {
            
            //#line 92 "Bwt.x10"
            x10_byte c__4919 = ::x10aux::nullCheck(inputBytes)->x10::lang::Rail< x10_byte >::__apply(
                                 i__4922);
            
            //#line 93 "Bwt.x10"
            x10_long base__4920;
            
            //#line 94 "Bwt.x10"
            if (isDigit) {
                
                //#line 95 "Bwt.x10"
                base__4920 = ((((x10_long)(c__4919))) - (((x10_long)47ll)));
            } else {
                
                //#line 98 "Bwt.x10"
                base__4920 = ((((((x10_long)(((x10_byte) ((((x10_byte) ((c__4919) >> (0x7 & (x10_int)(((x10_long)2ll)))))) ^ (((x10_byte) ((c__4919) >> (0x7 & (x10_int)(((x10_long)1ll))))))))))) & (((x10_long)19ll)))) % ::x10aux::zeroCheck(((x10_long)5ll)));
            }
            
            //#line 100 "Bwt.x10"
            if ((::x10aux::struct_equals(((i__4922) % ::x10aux::zeroCheck(((x10_long)1048576ll))),
                                         ((x10_long)0ll))))
            {
                
                //#line 101 "Bwt.x10"
                ::x10::io::Console::FMGL(ERR__get)()->printf(
                  (&::bwt::Bwt_Strings::sl__5738), ::x10aux::class_cast_unchecked< ::x10::lang::Any*>(((i__4922) / ::x10aux::zeroCheck(((x10_long)1048576ll)))));
            }
            
            //#line 103 "Bwt.x10"
            reinterpret_cast< ::x10::util::RailBuilder<x10_long>*>(strBuilder->add(
                                                                     base__4920));
        }
    }
    
    //#line 105 "Bwt.x10"
    reinterpret_cast< ::x10::util::RailBuilder<x10_long>*>(strBuilder->add(
                                                             ((x10_long)0ll)));
    
    //#line 106 "Bwt.x10"
    return strBuilder->result();
    
}

//#line 109 "Bwt.x10"
::x10::lang::String* bwt::Bwt::fileioImproved(::x10::lang::String* filename) {
    
    //#line 110 "Bwt.x10"
    ::x10::util::StringBuilder* strBuilder =  (new (::x10aux::alloc_z< ::x10::util::StringBuilder>()) ::x10::util::StringBuilder());
    (strBuilder)->::x10::util::StringBuilder::_constructor();
    
    //#line 111 "Bwt.x10"
    ::x10::io::File* input =  (new (::x10aux::alloc_z< ::x10::io::File>()) ::x10::io::File());
    (input)->::x10::io::File::_constructor(filename);
    
    //#line 112 "Bwt.x10"
    x10_long j = ((x10_long)1ll);
    
    //#line 113 "Bwt.x10"
    {
        ::x10::lang::Iterator< ::x10::lang::String*>* c__3524;
        for (c__3524 = ::x10aux::nullCheck(input->lines())->iterator();
             ::x10::lang::Iterator< ::x10::lang::String*>::hasNext(::x10aux::nullCheck(c__3524));
             ) {
            ::x10::lang::String* c = ::x10::lang::Iterator< ::x10::lang::String*>::next(::x10aux::nullCheck(c__3524));
            
            //#line 114 "Bwt.x10"
            strBuilder->addString(c);
            
            //#line 115 "Bwt.x10"
            if ((::x10aux::struct_equals(((j) % ::x10aux::zeroCheck(((x10_long)1048576ll))),
                                         ((x10_long)0ll))))
            {
                
                //#line 116 "Bwt.x10"
                ::x10::io::Console::FMGL(ERR__get)()->printf(
                  (&::bwt::Bwt_Strings::sl__5739), ::x10aux::class_cast_unchecked< ::x10::lang::Any*>(((j) / ::x10aux::zeroCheck(((x10_long)1048576ll)))));
            }
            
            //#line 118 "Bwt.x10"
            j = ((j) + (((x10_long)1ll)));
        }
    }
    
    //#line 120 "Bwt.x10"
    ::x10::lang::String* string = strBuilder->result();
    
    //#line 121 "Bwt.x10"
    return string;
    
}

//#line 124 "Bwt.x10"

//#line 127 "Bwt.x10"

//#line 130 "Bwt.x10"

//#line 133 "Bwt.x10"
::x10::lang::Rail< x10_long >* bwt::Bwt::fileio(::x10::lang::String* filename) {
    
    //#line 134 "Bwt.x10"
    ::x10::util::RailBuilder<x10_long>* strBuilder =  (new (::x10aux::alloc_z< ::x10::util::RailBuilder<x10_long> >()) ::x10::util::RailBuilder<x10_long>());
    (strBuilder)->::x10::util::RailBuilder<x10_long>::_constructor();
    
    //#line 135 "Bwt.x10"
    ::x10::io::File* input =  (new (::x10aux::alloc_z< ::x10::io::File>()) ::x10::io::File());
    (input)->::x10::io::File::_constructor(filename);
    
    //#line 136 "Bwt.x10"
    x10_long j = ((x10_long)1ll);
    
    //#line 137 "Bwt.x10"
    {
        ::x10::lang::Iterator<x10_byte>* c__3526;
        for (c__3526 = ::x10aux::nullCheck(input->bytes())->iterator();
             ::x10::lang::Iterator<x10_byte>::hasNext(::x10aux::nullCheck(c__3526));
             ) {
            x10_byte c = ::x10::lang::Iterator<x10_byte>::next(::x10aux::nullCheck(c__3526));
            
            //#line 139 "Bwt.x10"
            x10_long base = ((((((x10_long)(((x10_byte) ((((x10_byte) ((c) >> (0x7 & (x10_int)(((x10_long)2ll)))))) ^ (((x10_byte) ((c) >> (0x7 & (x10_int)(((x10_long)1ll))))))))))) & (((x10_long)19ll)))) % ::x10aux::zeroCheck(((x10_long)5ll)));
            
            //#line 140 "Bwt.x10"
            reinterpret_cast< ::x10::util::RailBuilder<x10_long>*>(strBuilder->add(
                                                                     base));
            
            //#line 141 "Bwt.x10"
            if ((::x10aux::struct_equals(((j) % ::x10aux::zeroCheck(((x10_long)1048576ll))),
                                         ((x10_long)0ll))))
            {
                
                //#line 142 "Bwt.x10"
                ::x10::io::Console::FMGL(ERR__get)()->printf(
                  (&::bwt::Bwt_Strings::sl__5738), ::x10aux::class_cast_unchecked< ::x10::lang::Any*>(((j) / ::x10aux::zeroCheck(((x10_long)1048576ll)))));
            }
            
            //#line 144 "Bwt.x10"
            j = ((j) + (((x10_long)1ll)));
        }
    }
    
    //#line 146 "Bwt.x10"
    {
        x10_long i__4924;
        for (i__4924 = ((x10_long)0ll); ((i__4924) <= (((x10_long)2ll)));
             i__4924 = ((i__4924) + (((x10_long)1ll)))) {
            
            //#line 147 "Bwt.x10"
            reinterpret_cast< ::x10::util::RailBuilder<x10_long>*>(strBuilder->add(
                                                                     ((x10_long)0ll)));
        }
    }
    
    //#line 149 "Bwt.x10"
    ::x10::lang::Rail< x10_long >* string = strBuilder->result();
    
    //#line 150 "Bwt.x10"
    return string;
    
}

//#line 153 "Bwt.x10"
void bwt::Bwt::main(::x10::lang::Rail< ::x10::lang::String* >* args) {
    
    //#line 155 "Bwt.x10"
    x10_int N = ::x10::lang::IntNatives::parseInt(::x10aux::nullCheck(args)->x10::lang::Rail< ::x10::lang::String* >::__apply(
                                                    ((x10_long)0ll)));
    
    //#line 156 "Bwt.x10"
    x10_long length = ((::x10::lang::LongNatives::parseLong(::x10aux::nullCheck(args)->x10::lang::Rail< ::x10::lang::String* >::__apply(
                                                              ((x10_long)1ll)))) + (((x10_long)3ll)));
    
    //#line 157 "Bwt.x10"
    ::x10::lang::String* file = ::x10aux::nullCheck(args)->x10::lang::Rail< ::x10::lang::String* >::__apply(
                                  ((x10_long)2ll));
    
    //#line 158 "Bwt.x10"
    ::x10::io::Console::FMGL(ERR__get)()->x10::io::Printer::println(
      reinterpret_cast< ::x10::lang::Any*>((&::bwt::Bwt_Strings::sl__5740)));
    
    //#line 160 "Bwt.x10"
    ::x10::lang::Rail< x10_byte >* e = ::x10::lang::Rail< x10_byte >::_make(length);
    
    //#line 161 "Bwt.x10"
    ::x10::io::Console::FMGL(ERR__get)()->x10::io::Printer::println(
      reinterpret_cast< ::x10::lang::Any*>((&::bwt::Bwt_Strings::sl__5741)));
    
    //#line 162 "Bwt.x10"
    input_fgets_char((file)->c_str(), (e)->raw);;
    
    //#line 163 "Bwt.x10"
    ::x10::io::Console::FMGL(ERR__get)()->x10::io::Printer::println(
      reinterpret_cast< ::x10::lang::Any*>((&::bwt::Bwt_Strings::sl__5742)));
    
    //#line 164 "Bwt.x10"
    ::bwt::Bwt* bwa =  (new (::x10aux::alloc_z< ::bwt::Bwt>()) ::bwt::Bwt());
    (bwa)->::bwt::Bwt::_constructor(e, N);
    
}

//#line 12 "Bwt.x10"
::bwt::Bwt* bwt::Bwt::bwt__Bwt____this__bwt__Bwt() {
    return this;
    
}
void bwt::Bwt::__fieldInitializers_bwt_Bwt() {
 
}
const ::x10aux::serialization_id_t bwt::Bwt::_serialization_id = 
    ::x10aux::DeserializationDispatcher::addDeserializer(::bwt::Bwt::_deserializer);

void bwt::Bwt::_serialize_body(::x10aux::serialization_buffer& buf) {
    
}

::x10::lang::Reference* ::bwt::Bwt::_deserializer(::x10aux::deserialization_buffer& buf) {
    ::bwt::Bwt* this_ = new (::x10aux::alloc_z< ::bwt::Bwt>()) ::bwt::Bwt();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

void bwt::Bwt::_deserialize_body(::x10aux::deserialization_buffer& buf) {
    
}

::x10aux::RuntimeType bwt::Bwt::rtt;
void bwt::Bwt::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const ::x10aux::RuntimeType** parents = NULL; 
    rtt.initStageTwo("bwt.Bwt",::x10aux::RuntimeType::class_kind, 0, parents, 0, NULL, NULL);
}

::x10::lang::String bwt::Bwt_Strings::sl__5737("Elapsed time: %ld millitime.\n");
::x10::lang::String bwt::Bwt_Strings::sl__5741("End Malloc");
::x10::lang::String bwt::Bwt_Strings::sl__5739("%ld MLine loaded.\n");
::x10::lang::String bwt::Bwt_Strings::sl__5738("%ld MB loaded.\n");
::x10::lang::String bwt::Bwt_Strings::sl__5742("Files has read");
::x10::lang::String bwt::Bwt_Strings::sl__5740("Start Malloc");

/* END of Bwt */
/*************************************************/
