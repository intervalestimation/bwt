/*************************************************/
/* START of SuffixArraySimple */
#include <bwt/SuffixArraySimple.h>

#include <x10/lang/Long.h>
#include <x10/lang/Rail.h>
#include <x10/lang/Byte.h>
#include <x10/lang/Boolean.h>
#include <x10/io/Printer.h>
#include <x10/io/Console.h>
#include <x10/lang/Any.h>
#include <x10/util/RailBuilder.h>
#include <x10/compiler/Synthetic.h>
#include <x10/lang/String.h>

//#line 6 "SuffixArraySimple.x10"

//#line 7 "SuffixArraySimple.x10"

//#line 8 "SuffixArraySimple.x10"

//#line 9 "SuffixArraySimple.x10"

//#line 10 "SuffixArraySimple.x10"

//#line 11 "SuffixArraySimple.x10"

//#line 12 "SuffixArraySimple.x10"

//#line 13 "SuffixArraySimple.x10"

//#line 14 "SuffixArraySimple.x10"

//#line 15 "SuffixArraySimple.x10"

//#line 17 "SuffixArraySimple.x10"
void bwt::SuffixArraySimple::_constructor(::x10::lang::Rail< x10_long >* input,
                                          x10_long charsize) {
    
    //#line 5 "SuffixArraySimple.x10"
    ::bwt::SuffixArraySimple* this__11991 = this;
    ::x10aux::nullCheck(this__11991)->FMGL(R) = (::x10aux::class_cast_unchecked< ::x10::lang::Rail< x10_long >*>(reinterpret_cast< ::x10::lang::NullType*>(X10_NULL)));
    ::x10aux::nullCheck(this__11991)->FMGL(SA12) = (::x10aux::class_cast_unchecked< ::x10::lang::Rail< x10_long >*>(reinterpret_cast< ::x10::lang::NullType*>(X10_NULL)));
    ::x10aux::nullCheck(this__11991)->FMGL(SA) = (::x10aux::class_cast_unchecked< ::x10::lang::Rail< x10_long >*>(reinterpret_cast< ::x10::lang::NullType*>(X10_NULL)));
    
    //#line 18 "SuffixArraySimple.x10"
    this->FMGL(string) = input;
    
    //#line 19 "SuffixArraySimple.x10"
    this->FMGL(k) = charsize;
    
    //#line 20 "SuffixArraySimple.x10"
    this->FMGL(n) = (((x10_long)(::x10aux::nullCheck(input)->FMGL(size))) - (((x10_long)3ll)));
    
    //#line 21 "SuffixArraySimple.x10"
    this->FMGL(n0) = ((((this->FMGL(n)) + (((x10_long)2ll)))) / ::x10aux::zeroCheck(((x10_long)3ll)));
    
    //#line 22 "SuffixArraySimple.x10"
    this->FMGL(n1) = ((((this->FMGL(n)) + (((x10_long)1ll)))) / ::x10aux::zeroCheck(((x10_long)3ll)));
    
    //#line 23 "SuffixArraySimple.x10"
    this->FMGL(n2) = ((this->FMGL(n)) / ::x10aux::zeroCheck(((x10_long)3ll)));
    
    //#line 24 "SuffixArraySimple.x10"
    this->FMGL(n02) = ((this->FMGL(n0)) + (this->FMGL(n2)));
}
::bwt::SuffixArraySimple* bwt::SuffixArraySimple::_make(::x10::lang::Rail< x10_long >* input,
                                                        x10_long charsize)
{
    ::bwt::SuffixArraySimple* this_ = new (::x10aux::alloc_z< ::bwt::SuffixArraySimple>()) ::bwt::SuffixArraySimple();
    this_->_constructor(input, charsize);
    return this_;
}



//#line 28 "SuffixArraySimple.x10"
void bwt::SuffixArraySimple::radixPass(::x10::lang::Rail< x10_long >* a,
                                       ::x10::lang::Rail< x10_long >* b,
                                       x10_byte rOffs, x10_long nt) {
    
    //#line 29 "SuffixArraySimple.x10"
    ::x10::lang::Rail< x10_long >* c = ::x10::lang::Rail< x10_long >::_make(((this->FMGL(k)) + (((x10_long)1ll))));
    
    //#line 30 "SuffixArraySimple.x10"
    x10_long i__10002max__11999 = this->FMGL(k);
    {
        x10_long i__12000;
        for (i__12000 = ((x10_long)0ll); ((i__12000) <= (i__10002max__11999));
             i__12000 = ((i__12000) + (((x10_long)1ll)))) {
            ::x10aux::nullCheck(c)->x10::lang::Rail< x10_long >::__set(
              i__12000, ((x10_long)0ll));
        }
    }
    
    //#line 31 "SuffixArraySimple.x10"
    x10_long i__10018max__12002 = ((nt) - (((x10_long)1ll)));
    {
        x10_long i__12003;
        for (i__12003 = ((x10_long)0ll); ((i__12003) <= (i__10018max__12002));
             i__12003 = ((i__12003) + (((x10_long)1ll)))) {
            
            //#line 32 "SuffixArraySimple.x10"
            x10_long i__11993 = ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                  ((::x10aux::nullCheck(a)->x10::lang::Rail< x10_long >::__apply(
                                      i__12003)) + (((x10_long)(rOffs)))));
            x10_long r__11994 = ((::x10aux::nullCheck(c)->x10::lang::Rail< x10_long >::__apply(
                                    i__11993)) + (((x10_long)1ll)));
            ::x10aux::nullCheck(c)->x10::lang::Rail< x10_long >::__set(
              i__11993, r__11994);
        }
    }
    
    //#line 34 "SuffixArraySimple.x10"
    x10_long sum = ((x10_long)0ll);
    
    //#line 35 "SuffixArraySimple.x10"
    x10_long i__10034max__12005 = this->FMGL(k);
    {
        x10_long i__12006;
        for (i__12006 = ((x10_long)0ll); ((i__12006) <= (i__10034max__12005));
             i__12006 = ((i__12006) + (((x10_long)1ll))))
        {
            
            //#line 36 "SuffixArraySimple.x10"
            x10_long t__11995 = ::x10aux::nullCheck(c)->x10::lang::Rail< x10_long >::__apply(
                                  i__12006);
            
            //#line 37 "SuffixArraySimple.x10"
            ::x10aux::nullCheck(c)->x10::lang::Rail< x10_long >::__set(
              i__12006, sum);
            
            //#line 38 "SuffixArraySimple.x10"
            sum = ((sum) + (t__11995));
        }
    }
    
    //#line 40 "SuffixArraySimple.x10"
    x10_long i__10050max__12008 = ((nt) - (((x10_long)1ll)));
    {
        x10_long i__12009;
        for (i__12009 = ((x10_long)0ll); ((i__12009) <= (i__10050max__12008));
             i__12009 = ((i__12009) + (((x10_long)1ll))))
        {
            
            //#line 41 "SuffixArraySimple.x10"
            ::x10aux::nullCheck(b)->x10::lang::Rail< x10_long >::__set(
              ::x10aux::nullCheck(c)->x10::lang::Rail< x10_long >::__apply(
                ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                  ((::x10aux::nullCheck(a)->x10::lang::Rail< x10_long >::__apply(
                      i__12009)) + (((x10_long)(rOffs)))))),
              ::x10aux::nullCheck(a)->x10::lang::Rail< x10_long >::__apply(
                i__12009));
            
            //#line 42 "SuffixArraySimple.x10"
            x10_long i__11997 = ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                  ((::x10aux::nullCheck(a)->x10::lang::Rail< x10_long >::__apply(
                                      i__12009)) + (((x10_long)(rOffs)))));
            x10_long r__11998 = ((::x10aux::nullCheck(c)->x10::lang::Rail< x10_long >::__apply(
                                    i__11997)) + (((x10_long)1ll)));
            ::x10aux::nullCheck(c)->x10::lang::Rail< x10_long >::__set(
              i__11997, r__11998);
        }
    }
    
}

//#line 46 "SuffixArraySimple.x10"
::x10::lang::Rail< x10_long >* bwt::SuffixArraySimple::run(
  ) {
    
    //#line 47 "SuffixArraySimple.x10"
    this->constructSample();
    
    //#line 48 "SuffixArraySimple.x10"
    this->sortSample();
    
    //#line 49 "SuffixArraySimple.x10"
    this->sortNonSample();
    
    //#line 50 "SuffixArraySimple.x10"
    return this->FMGL(SA);
    
}

//#line 53 "SuffixArraySimple.x10"
void bwt::SuffixArraySimple::constructSample() {
    
    //#line 54 "SuffixArraySimple.x10"
    this->FMGL(R) = ::x10::lang::Rail< x10_long >::_make(((this->FMGL(n02)) + (((x10_long)3ll))));
    
    //#line 55 "SuffixArraySimple.x10"
    ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__set(
      this->FMGL(n02), ((x10_long)0ll));
    
    //#line 56 "SuffixArraySimple.x10"
    ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__set(
      ((this->FMGL(n02)) + (((x10_long)1ll))), ((x10_long)0ll));
    
    //#line 57 "SuffixArraySimple.x10"
    ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__set(
      ((this->FMGL(n02)) + (((x10_long)2ll))), ((x10_long)0ll));
    
    //#line 58 "SuffixArraySimple.x10"
    x10_long j = ((x10_long)0ll);
    
    //#line 59 "SuffixArraySimple.x10"
    x10_long i__10066max__12011 = ((((((this->FMGL(n)) + (this->FMGL(n0)))) - (this->FMGL(n1)))) - (((x10_long)1ll)));
    {
        x10_long i__12012;
        for (i__12012 = ((x10_long)0ll); ((i__12012) <= (i__10066max__12011));
             i__12012 = ((i__12012) + (((x10_long)1ll))))
        {
            
            //#line 60 "SuffixArraySimple.x10"
            if ((!::x10aux::struct_equals(((i__12012) % ::x10aux::zeroCheck(((x10_long)3ll))),
                                          ((x10_long)0ll))))
            {
                
                //#line 61 "SuffixArraySimple.x10"
                ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__set(
                  j, i__12012);
                
                //#line 62 "SuffixArraySimple.x10"
                j = ((j) + (((x10_long)1ll)));
            }
            
        }
    }
    
    //#line 65 "SuffixArraySimple.x10"
    this->FMGL(SA12) = ::x10::lang::Rail< x10_long >::_make(((this->FMGL(n02)) + (((x10_long)3ll))));
    
    //#line 66 "SuffixArraySimple.x10"
    ::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__set(
      this->FMGL(n02), ((x10_long)0ll));
    
    //#line 67 "SuffixArraySimple.x10"
    ::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__set(
      ((this->FMGL(n02)) + (((x10_long)1ll))), ((x10_long)0ll));
    
    //#line 68 "SuffixArraySimple.x10"
    ::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__set(
      ((this->FMGL(n02)) + (((x10_long)2ll))), ((x10_long)0ll));
}

//#line 71 "SuffixArraySimple.x10"
void bwt::SuffixArraySimple::sortSample() {
    
    //#line 72 "SuffixArraySimple.x10"
    this->radixPass(this->FMGL(R), this->FMGL(SA12), ((x10_byte)2),
                    this->FMGL(n02));
    
    //#line 73 "SuffixArraySimple.x10"
    this->radixPass(this->FMGL(SA12), this->FMGL(R), ((x10_byte)1),
                    this->FMGL(n02));
    
    //#line 74 "SuffixArraySimple.x10"
    this->radixPass(this->FMGL(R), this->FMGL(SA12), ((x10_byte)0),
                    this->FMGL(n02));
    
    //#line 76 "SuffixArraySimple.x10"
    x10_long name = ((x10_long)0ll);
    
    //#line 77 "SuffixArraySimple.x10"
    x10_long c0 = ((x10_long)-1ll);
    
    //#line 78 "SuffixArraySimple.x10"
    x10_long c1 = ((x10_long)-1ll);
    
    //#line 79 "SuffixArraySimple.x10"
    x10_long c2 = ((x10_long)-1ll);
    
    //#line 80 "SuffixArraySimple.x10"
    x10_long i__10082max__12020 = ((this->FMGL(n02)) - (((x10_long)1ll)));
    {
        x10_long i__12021;
        for (i__12021 = ((x10_long)0ll); ((i__12021) <= (i__10082max__12020));
             i__12021 = ((i__12021) + (((x10_long)1ll))))
        {
            
            //#line 81 "SuffixArraySimple.x10"
            if ((((!::x10aux::struct_equals(::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                              ::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                                                i__12021)),
                                            c0)) || (!::x10aux::struct_equals(::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                                                                ((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                                                                                    i__12021)) + (((x10_long)1ll)))),
                                                                              c1))) ||
                (!::x10aux::struct_equals(::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                            ((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                                                i__12021)) + (((x10_long)2ll)))),
                                          c2)))) {
                
                //#line 82 "SuffixArraySimple.x10"
                name = ((name) + (((x10_long)1ll)));
                
                //#line 83 "SuffixArraySimple.x10"
                c0 = ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                       ::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                         i__12021));
                
                //#line 84 "SuffixArraySimple.x10"
                c1 = ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                       ((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                           i__12021)) + (((x10_long)1ll))));
                
                //#line 85 "SuffixArraySimple.x10"
                c2 = ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                       ((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                           i__12021)) + (((x10_long)2ll))));
            }
            
            //#line 88 "SuffixArraySimple.x10"
            if ((::x10aux::struct_equals(((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                                             i__12021)) % ::x10aux::zeroCheck(((x10_long)3ll))),
                                         ((x10_long)1ll))))
            {
                
                //#line 89 "SuffixArraySimple.x10"
                ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__set(
                  ((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                      i__12021)) / ::x10aux::zeroCheck(((x10_long)3ll))),
                  name);
            } else {
                
                //#line 91 "SuffixArraySimple.x10"
                ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__set(
                  ((((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                        i__12021)) / ::x10aux::zeroCheck(((x10_long)3ll)))) + (this->FMGL(n0))),
                  name);
            }
            
        }
    }
    
    //#line 95 "SuffixArraySimple.x10"
    if (((name) < (this->FMGL(n02)))) {
        
        //#line 96 "SuffixArraySimple.x10"
        ::x10::io::Console::FMGL(ERR__get)()->x10::io::Printer::println(
          reinterpret_cast< ::x10::lang::Any*>((&::bwt::SuffixArraySimple_Strings::sl__12958)));
        
        //#line 97 "SuffixArraySimple.x10"
        ::bwt::SuffixArraySimple* bwa =  (new (::x10aux::alloc_z< ::bwt::SuffixArraySimple>()) ::bwt::SuffixArraySimple());
        (bwa)->::bwt::SuffixArraySimple::_constructor(this->FMGL(R),
                                                      name);
        
        //#line 98 "SuffixArraySimple.x10"
        this->FMGL(SA12) = bwa->run();
        
        //#line 100 "SuffixArraySimple.x10"
        x10_long i__10098max__12014 = ((this->FMGL(n02)) - (((x10_long)1ll)));
        {
            x10_long i__12015;
            for (i__12015 = ((x10_long)0ll); ((i__12015) <= (i__10098max__12014));
                 i__12015 = ((i__12015) + (((x10_long)1ll))))
            {
                ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__set(
                  ::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                    i__12015), ((i__12015) + (((x10_long)1ll))));
            }
        }
        
    } else {
        
        //#line 102 "SuffixArraySimple.x10"
        x10_long i__10114max__12017 = ((this->FMGL(n02)) - (((x10_long)1ll)));
        {
            x10_long i__12018;
            for (i__12018 = ((x10_long)0ll); ((i__12018) <= (i__10114max__12017));
                 i__12018 = ((i__12018) + (((x10_long)1ll))))
            {
                ::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__set(
                  ((::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__apply(
                      i__12018)) - (((x10_long)1ll))), i__12018);
            }
        }
        
    }
    
}

//#line 106 "SuffixArraySimple.x10"
void bwt::SuffixArraySimple::sortNonSample() {
    
    //#line 107 "SuffixArraySimple.x10"
    ::x10::util::RailBuilder<x10_long>* R0B =  (new (::x10aux::alloc_z< ::x10::util::RailBuilder<x10_long> >()) ::x10::util::RailBuilder<x10_long>());
    (R0B)->::x10::util::RailBuilder<x10_long>::_constructor();
    
    //#line 108 "SuffixArraySimple.x10"
    x10_long i__10130max__12029 = ((this->FMGL(n02)) - (((x10_long)1ll)));
    {
        x10_long i__12030;
        for (i__12030 = ((x10_long)0ll); ((i__12030) <= (i__10130max__12029));
             i__12030 = ((i__12030) + (((x10_long)1ll))))
        {
            
            //#line 109 "SuffixArraySimple.x10"
            if (((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                    i__12030)) < (this->FMGL(n0)))) {
                
                //#line 110 "SuffixArraySimple.x10"
                reinterpret_cast< ::x10::util::RailBuilder<x10_long>*>(R0B->add(
                                                                         ((((x10_long)3ll)) * (::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                                                                                                 i__12030)))));
            }
            
        }
    }
    
    //#line 113 "SuffixArraySimple.x10"
    ::x10::lang::Rail< x10_long >* R0 = R0B->result();
    
    //#line 114 "SuffixArraySimple.x10"
    ::x10::lang::Rail< x10_long >* SA0 = ::x10::lang::Rail< x10_long >::_make(this->FMGL(n0));
    
    //#line 115 "SuffixArraySimple.x10"
    this->FMGL(SA) = ::x10::lang::Rail< x10_long >::_make(((this->FMGL(n)) + (((x10_long)3ll))));
    
    //#line 116 "SuffixArraySimple.x10"
    this->radixPass(R0, SA0, ((x10_byte)0), this->FMGL(n0));
    
    //#line 119 "SuffixArraySimple.x10"
    x10_long p = ((x10_long)0ll);
    
    //#line 120 "SuffixArraySimple.x10"
    x10_long t = ((this->FMGL(n0)) - (this->FMGL(n1)));
    
    //#line 121 "SuffixArraySimple.x10"
    x10_long k = ((x10_long)-1ll);
    
    //#line 122 "SuffixArraySimple.x10"
    while (((k) < (this->FMGL(n)))) {
        
        //#line 123 "SuffixArraySimple.x10"
        k = ((k) + (((x10_long)1ll)));
        
        //#line 124 "SuffixArraySimple.x10"
        x10_long i = this->getI(t);
        
        //#line 125 "SuffixArraySimple.x10"
        x10_long j = SA0->x10::lang::Rail< x10_long >::__apply(
                       p);
        
        //#line 127 "SuffixArraySimple.x10"
        if (((((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                  t)) < (this->FMGL(n0))) && (__extension__ ({
                x10_long a__11979 = ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                      i);
                x10_long a__11980 = ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__apply(
                                      ((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                                          t)) + (this->FMGL(n0))));
                x10_long b__11981 = ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                      j);
                x10_long b__11982 = ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__apply(
                                      ((j) / ::x10aux::zeroCheck(((x10_long)3ll))));
                (((a__11979) < (b__11981)) || ((::x10aux::struct_equals(a__11979,
                                                                        b__11981)) &&
                ((a__11980) <= (b__11982))));
            }))
            ) || (((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                      t)) >= (this->FMGL(n0))) && this->leq(
                                                    ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                                      i),
                                                    ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                                      ((i) + (((x10_long)1ll)))),
                                                    ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__apply(
                                                      ((((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                                                            t)) - (this->FMGL(n0)))) + (((x10_long)1ll)))),
                                                    ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                                      j),
                                                    ::x10aux::nullCheck(this->FMGL(string))->x10::lang::Rail< x10_long >::__apply(
                                                      ((j) + (((x10_long)1ll)))),
                                                    ::x10aux::nullCheck(this->FMGL(R))->x10::lang::Rail< x10_long >::__apply(
                                                      ((((j) / ::x10aux::zeroCheck(((x10_long)3ll)))) + (this->FMGL(n0))))))))
        {
            
            //#line 130 "SuffixArraySimple.x10"
            ::x10aux::nullCheck(this->FMGL(SA))->x10::lang::Rail< x10_long >::__set(
              k, i);
            
            //#line 131 "SuffixArraySimple.x10"
            t = ((t) + (((x10_long)1ll)));
            
            //#line 132 "SuffixArraySimple.x10"
            if ((::x10aux::struct_equals(t, this->FMGL(n02))))
            {
                
                //#line 133 "SuffixArraySimple.x10"
                k = ((k) + (((x10_long)1ll)));
                
                //#line 134 "SuffixArraySimple.x10"
                x10_long i__10146max__12023 = ((((this->FMGL(n0)) - (p))) - (((x10_long)1ll)));
                {
                    x10_long i__12024;
                    for (i__12024 = ((x10_long)0ll); ((i__12024) <= (i__10146max__12023));
                         i__12024 = ((i__12024) + (((x10_long)1ll))))
                    {
                        
                        //#line 135 "SuffixArraySimple.x10"
                        ::x10aux::nullCheck(this->FMGL(SA))->x10::lang::Rail< x10_long >::__set(
                          k, SA0->x10::lang::Rail< x10_long >::__apply(
                               p));
                        
                        //#line 136 "SuffixArraySimple.x10"
                        p = ((p) + (((x10_long)1ll)));
                        
                        //#line 137 "SuffixArraySimple.x10"
                        k = ((k) + (((x10_long)1ll)));
                    }
                }
                
            }
            
        } else {
            
            //#line 141 "SuffixArraySimple.x10"
            ::x10aux::nullCheck(this->FMGL(SA))->x10::lang::Rail< x10_long >::__set(
              k, j);
            
            //#line 142 "SuffixArraySimple.x10"
            p = ((p) + (((x10_long)1ll)));
            
            //#line 143 "SuffixArraySimple.x10"
            if ((::x10aux::struct_equals(p, this->FMGL(n0))))
            {
                
                //#line 144 "SuffixArraySimple.x10"
                k = ((k) + (((x10_long)1ll)));
                
                //#line 145 "SuffixArraySimple.x10"
                x10_long i__10162max__12026 = ((((this->FMGL(n02)) - (t))) - (((x10_long)1ll)));
                {
                    x10_long i__12027;
                    for (i__12027 = ((x10_long)0ll); ((i__12027) <= (i__10162max__12026));
                         i__12027 = ((i__12027) + (((x10_long)1ll))))
                    {
                        
                        //#line 146 "SuffixArraySimple.x10"
                        ::x10aux::nullCheck(this->FMGL(SA))->x10::lang::Rail< x10_long >::__set(
                          k, this->getI(t));
                        
                        //#line 147 "SuffixArraySimple.x10"
                        t = ((t) + (((x10_long)1ll)));
                        
                        //#line 148 "SuffixArraySimple.x10"
                        k = ((k) + (((x10_long)1ll)));
                    }
                }
                
            }
            
        }
        
    }
    
}

//#line 155 "SuffixArraySimple.x10"
x10_boolean bwt::SuffixArraySimple::leq(x10_long a1, x10_long a2,
                                        x10_long b1, x10_long b2) {
    
    //#line 156 "SuffixArraySimple.x10"
    return (((a1) < (b1)) || ((::x10aux::struct_equals(a1,
                                                       b1)) &&
    ((a2) <= (b2))));
    
}

//#line 159 "SuffixArraySimple.x10"
x10_boolean bwt::SuffixArraySimple::leq(x10_long a1, x10_long a2,
                                        x10_long a3, x10_long b1,
                                        x10_long b2, x10_long b3) {
    
    //#line 160 "SuffixArraySimple.x10"
    return (((a1) < (b1)) || ((::x10aux::struct_equals(a1,
                                                       b1)) &&
    ((((a2) < (b2)) || ((::x10aux::struct_equals(a2, b2)) &&
     ((a3) <= (b3)))))));
    
}

//#line 163 "SuffixArraySimple.x10"
x10_long bwt::SuffixArraySimple::getI(x10_long t) {
    
    //#line 164 "SuffixArraySimple.x10"
    if (((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
            t)) < (this->FMGL(n0)))) {
        
        //#line 165 "SuffixArraySimple.x10"
        return ((((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                     t)) * (((x10_long)3ll)))) + (((x10_long)1ll)));
        
    } else {
        
        //#line 167 "SuffixArraySimple.x10"
        return ((((((::x10aux::nullCheck(this->FMGL(SA12))->x10::lang::Rail< x10_long >::__apply(
                       t)) - (this->FMGL(n0)))) * (((x10_long)3ll)))) + (((x10_long)2ll)));
        
    }
    
}

//#line 5 "SuffixArraySimple.x10"
::bwt::SuffixArraySimple* bwt::SuffixArraySimple::bwt__SuffixArraySimple____this__bwt__SuffixArraySimple(
  ) {
    return this;
    
}
void bwt::SuffixArraySimple::__fieldInitializers_bwt_SuffixArraySimple(
  ) {
    this->FMGL(R) = (::x10aux::class_cast_unchecked< ::x10::lang::Rail< x10_long >*>(reinterpret_cast< ::x10::lang::NullType*>(X10_NULL)));
    this->FMGL(SA12) = (::x10aux::class_cast_unchecked< ::x10::lang::Rail< x10_long >*>(reinterpret_cast< ::x10::lang::NullType*>(X10_NULL)));
    this->FMGL(SA) = (::x10aux::class_cast_unchecked< ::x10::lang::Rail< x10_long >*>(reinterpret_cast< ::x10::lang::NullType*>(X10_NULL)));
}
const ::x10aux::serialization_id_t bwt::SuffixArraySimple::_serialization_id = 
    ::x10aux::DeserializationDispatcher::addDeserializer(::bwt::SuffixArraySimple::_deserializer);

void bwt::SuffixArraySimple::_serialize_body(::x10aux::serialization_buffer& buf) {
    buf.write(this->FMGL(string));
    buf.write(this->FMGL(n));
    buf.write(this->FMGL(n0));
    buf.write(this->FMGL(n1));
    buf.write(this->FMGL(n2));
    buf.write(this->FMGL(k));
    buf.write(this->FMGL(n02));
    buf.write(this->FMGL(R));
    buf.write(this->FMGL(SA12));
    buf.write(this->FMGL(SA));
    
}

::x10::lang::Reference* ::bwt::SuffixArraySimple::_deserializer(::x10aux::deserialization_buffer& buf) {
    ::bwt::SuffixArraySimple* this_ = new (::x10aux::alloc_z< ::bwt::SuffixArraySimple>()) ::bwt::SuffixArraySimple();
    buf.record_reference(this_);
    this_->_deserialize_body(buf);
    return this_;
}

void bwt::SuffixArraySimple::_deserialize_body(::x10aux::deserialization_buffer& buf) {
    FMGL(string) = buf.read< ::x10::lang::Rail< x10_long >*>();
    FMGL(n) = buf.read<x10_long>();
    FMGL(n0) = buf.read<x10_long>();
    FMGL(n1) = buf.read<x10_long>();
    FMGL(n2) = buf.read<x10_long>();
    FMGL(k) = buf.read<x10_long>();
    FMGL(n02) = buf.read<x10_long>();
    FMGL(R) = buf.read< ::x10::lang::Rail< x10_long >*>();
    FMGL(SA12) = buf.read< ::x10::lang::Rail< x10_long >*>();
    FMGL(SA) = buf.read< ::x10::lang::Rail< x10_long >*>();
}

::x10aux::RuntimeType bwt::SuffixArraySimple::rtt;
void bwt::SuffixArraySimple::_initRTT() {
    if (rtt.initStageOne(&rtt)) return;
    const ::x10aux::RuntimeType** parents = NULL; 
    rtt.initStageTwo("bwt.SuffixArraySimple",::x10aux::RuntimeType::class_kind, 0, parents, 0, NULL, NULL);
}

::x10::lang::String bwt::SuffixArraySimple_Strings::sl__12958("Start Sort Recursively");

/* END of SuffixArraySimple */
/*************************************************/