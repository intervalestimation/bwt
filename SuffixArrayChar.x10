package bwt;
import x10.io.Console;
import x10.util.RailBuilder;
import x10.array.Array;

import x10.compiler.Native;
import x10.compiler.NativeCPPInclude;

@NativeCPPInclude("parallel_radix_sort.h")

public class SuffixArrayChar {
  val string: Rail[Byte];
  val n: Long;
  val n0: Long;
  val n1: Long;
  val n2: Long;
  val k: Long;
  val n02: Long;
  var R: Rail[Long];
  var SA12: Rail[Long];
  var SA: Rail[Byte];
  var SA0: Rail[Long];
  var c:Rail[Long];
  var name: Long;
  val num_threads: Byte;
 
  def this(input: Rail[Byte], charsize: Long, threads: Byte){
    string = input;
    k = charsize;
    n = input.size - 3;
    n0 = (n + 2) / 3;
    n1 = (n + 1) / 3;
    n2 = n / 3;
    n02 = n0 + n2;
    num_threads = threads;
  }

  @Native("c++", "parallel_radix_sort::SortPairsByte((#1)->raw, (#2)->raw, #3, #4, #5)")
  native def sortPairs(keys: Rail[Byte], values: Rail[Long], num_elems: ULong, num_threads: Int, offset: Byte): void;

  @Native("c++", "parallel_radix_sort::SortPairsByteThree((#1)->raw, (#2)->raw, #3, #4)")
  native def sortPairsThree(keys: Rail[Byte], values: Rail[Long], num_elems: ULong, num_threads: Int): void;

  // a[0..nt-1] to b[0..nt-1] with keys in 0..k from *(string+rOffs)
/*
  def radixPass(a: Rail[Long], b: Rail[Long], rOffs: Byte, nt: Long) {
    for(i in 0..k) {c(i) = 0;}
    for(i in 0..(nt-1)) {
      c(string(a(i) + rOffs)) += 1;
    }
    var sum:Long = 0;
    for(i in 0..k) {
      val t = c(i);
      c(i) = sum;
      sum += t;
    }
    for(i in 0..(nt-1)) {
      b(c(string(a(i) + rOffs))) = a(i);
      c((string(a(i) + rOffs))) += 1;
    }
  }
*/
  def run(): Rail[Byte] {
    //Console.ERR.println("Start Constructuring Char Sample");
    this.constructSample();
    //Console.ERR.println("Start Sort Char Sample");
    this.sortSample();
    //Console.ERR.println("Start Sort Char NonSample");
    this.sortNonSample();
    return this.SA;
  }
/*
  def bwtable(): Rail[Byte] {
    val bwt: RailBuilder[Byte] = new RailBuilder[Byte]();
    for(i in 0..(n-1)){
      if(SA(i) != 0y){
        bwt.add(string(SA(i) - 1));
      }
    }
    return bwt.result();
  }
*/
  def bwt(pos: Long): Byte {
    if(pos != 0){
      return string(pos - 1);
    } else {
      return 0y;
    }
  }

  def constructSample() {
    finish {
      async R = new Rail[Long](n02+3);
      SA12 = new Rail[Long](n02+3);
      SA12(n02) = 0;
      SA12(n02+1) = 0;
      SA12(n02+2) = 0;
      var j:Long = 0;
      for(i in 0..(n + n0 - n1 - 1)) {
        if (i % 3 != 0){
          SA12(j) = i;
          j += 1;
        } 
      }
    }
  }
/*
  def constructSampleR() {
    finish {
      async c = new Rail[Long](k+1);
      async SA0 = new Rail[Long](n0);
      async {R = new Rail[Long](n02+3);
      R(n02) = 0;
      R(n02+1) = 0;
      R(n02+2) = 0;
      var j:Long = 0;
      for(i in 0..(n + n0 - n1 - 1)) {
        if (i % 3 != 0){
          R(j) = i;
          j += 1;
        } 
      }
    }
    SA12 = new Rail[Long](n02+3);
    SA12(n02) = 0;
    SA12(n02+1) = 0;
    SA12(n02+2) = 0;
    }
    //Console.ERR.println("Malloc End");
  }
*/
  def sortSample() {
    val size = n02 as ULong;
    sortPairsThree(string, SA12, size, num_threads);
    Console.ERR.printf("Ended 3rd Radix Sort %ld\n", n02);

    //radixPass(R, SA12, 2y, n02);
    //radixPass(SA12, R, 1y, n02);
    //radixPass(R, SA12, 0y, n02);
    /*
    val size = n02 as ULong;
    val num_threads = 11 as Int;
    sortPairs(string, SA12, size, num_threads, 2y);
    //Console.ERR.println("Ended 1st Radix Sort");
    sortPairs(string, SA12, size, num_threads, 1y);
    //Console.ERR.println("Ended 2nd Radix Sort");
    sortPairs(string, SA12, size, num_threads, 0y);
    //Console.ERR.printf("Ended 3rd Radix Sort %ld\n", n02);
    */
    name = 0;
    var c0:Byte = -1y;
    var c1:Byte = -1y;
    var c2:Byte = -1y;
    for (i in 0..(n02 - 1)){
      if (string(SA12(i)) != c0 || string(SA12(i)+1) != c1 || string(SA12(i)+2) != c2) {
        name += 1;
        c0 = string(SA12(i));
        c1 = string(SA12(i)+1);
        c2 = string(SA12(i)+2);
      }
    
      if (SA12(i)%3 == 1) {
        R(SA12(i)/3) = name;
      } else {
        R(SA12(i)/3 + n0) = name;
      }
    }

    //Console.ERR.println("Ended Sort Sample");
  }

  def sortNonSample() {
    if (name < n02) {
      //SA12 = new Rail[Long](R.size + 3);
      var bwa:SuffixArray = new SuffixArray(R, name, SA12, num_threads);
      bwa.run();
      bwa = null;
      //Console.ERR.println("Ended BWA run");
      finish {
        async {for(i in 0..(n02-1)) { R(SA12(i)) = i + 1; }} //futurize
        async SA = new Rail[Byte](n+3);
        SA0 = new Rail[Long](n0);
        var m:Long = 0; 
        for(i in 0..(n02-1)) {
          if(SA12(i) < n0) {
            //R0B.add(3 * SA12(i));
            SA0(m) = 3 * SA12(i);
            m+= 1;
          }      
        }
        val size = n0 as ULong;
        //Console.ERR.println("Start SortPairs Char");
        sortPairs(string, SA0, size, num_threads, 0y);
      }
    } else {
      finish for(i in 0..(n02-1)) async { SA12(R(i) - 1) = i; }
      finish {
        async SA = new Rail[Byte](n+3);
        SA0 = new Rail[Long](n0);
        var m:Long = 0; 
        for(i in 0..(n02-1)) {
          if(SA12(i) < n0) {
            //R0B.add(3 * SA12(i));
            SA0(m) = 3 * SA12(i);
            m += 1;
          }  
        }
        val size = n0 as ULong;
        //Console.ERR.println("Start SortPairs Char");
        sortPairs(string, SA0, size, num_threads, 0y);
      }
    }

    Console.ERR.println("Start Merge Final");

    if (SA0.size > num_threads){
      var p_lb:Long = 0; //n0
      var t_lb:Long = n0 - n1;  //n02
      var p_ub:Long = n0-1;
      var t_ub:Long = n02-1;
      val closure = (val t1: Long, val p1: long) => {
        val i = getI(t1);
        val j = SA0(p1);
        if(SA12(t1) < n0 && leq(string(i), R(SA12(t1) + n0), string(j), R(j/3)) ||
           SA12(t1) >= n0 && leq(string(i), string(i+1), R(SA12(t1) - n0 + 1), string(j), string(j+1), R(j/3 + n0))
          ){ // suffix from SA12 is smaller
          return true;
        } else {
          return false;
        }
      };

      val binary_search = (var t_lb:Long, var t_ub:Long, var p_ub:Long, var p_lb:Long):Rail[Long] => {
        var t_mid:Long = (t_lb + t_ub)/2;
        var p_mid:Long = (p_lb + p_ub)/2;
        while(t_ub - t_lb > 1 || p_ub - p_lb > 1){
         if(closure(t_mid, p_mid)){
           t_lb = t_mid;
           p_ub = p_mid;
         } else {
           t_ub = t_mid;
           p_lb = p_mid;
         }
           t_mid = (t_lb + t_ub)/2;
           p_mid = (p_lb + p_ub)/2;
        }
        val lb = new Rail[Long]([t_lb, p_lb]);
        return lb;
      };

      val lb = binary_search(t_lb, t_ub, p_ub, p_lb);
      val lbl:Rail[Long];
      val lbr:Rail[Long];
      val lbll:Rail[Long];
      val lblr:Rail[Long];
      val lbrl:Rail[Long];
      val lbrr:Rail[Long];
      finish {
        async { lbl = binary_search(t_lb, lb(0), lb(1), p_lb);
            finish {
                async { lbll = binary_search(t_lb, lbl(0), lbl(1), p_lb);}
                lblr = binary_search(lbl(0), lb(0), lb(1), lbl(1));}
            }
        lbr = binary_search(lb(0),t_ub,p_ub, lb(1));
        finish {
            async { lbrr = binary_search(lbr(0),t_ub,p_ub, lbr(1));}
            lbrl = binary_search(lb(0), lbr(0), lbr(1), lb(1));
        }
      }

      val split = 7;
      val midl = (n%3==1) ? lbl(0) + lbl(1)-1 :lbl(0) + lbl(1);
      val mid = (n%3==1) ? lb(0) + lb(1)-1 :lb(0) + lb(1);
      val midr = (n%3==1) ? lbr(0) + lbr(1)-1 :lbr(0) + lbr(1);
      val midll = (n%3==1) ? lbll(0) + lbll(1)-1 :lbll(0) + lbll(1);
      val midrl = (n%3==1) ? lbrl(0) + lbrl(1)-1 :lbrl(0) + lbrl(1);
      val midlr = (n%3==1) ? lblr(0) + lblr(1)-1 :lblr(0) + lblr(1);
      val midrr = (n%3==1) ? lbrr(0) + lbrr(1)-1 :lbrr(0) + lbrr(1);

      val krail = new Rail[Long]([-1, midll-1, midl-1, midlr-1, mid-1, midrl-1, midr-1, midrr-1]);
      val nrail = new Rail[Long]([midl+1, midl+1, midlr+1, mid + 1, midrl+1, midr+1, midrr+1, n]);
      val prail = new Rail[Long]([0, lbll(1), lbl(1), lblr(1), lb(1), lbrl(1), lbr(1), lbrr(1)]);
      val trail = new Rail[Long]([n0-n1, lbll(0), lbl(0), lblr(0), lb(0), lbrl(0), lbr(0) ,lbrr(0)]);

      finish for (l in 0..split) async {
        var k:Long = krail(l);
        var t:Long = trail(l);
        var p:Long = prail(l); 
        while(k < nrail(l)) {
          k += 1;
          val i = getI(t);
          val j = SA0(p);
          //// different compares for mod 1 and mod 2 suffixes
          if(SA12(t) < n0 && leq(string(i), R(SA12(t) + n0), string(j), R(j/3)) ||
             SA12(t) >= n0 && leq(string(i), string(i+1), R(SA12(t) - n0 + 1), string(j), string(j+1), R(j/3 + n0))
            ){ // suffix from SA12 is smaller
            if(!(l != 0 && k <= krail(l)+1)){
              SA(k) = bwt(i);
            }
            t += 1;
            if(t == n02) {
              k += 1;
              for(q in 0..(n0-p-1)){
                SA(k) = bwt(SA0(p));
                p += 1;
                k += 1;
              }
            }
          } else { // suffix from SA0 is smaller
            if(!(l != 0 && k <= krail(l)+1)){
              SA(k) = bwt(j);
            }
            p += 1;
            if(p == n0) {
              k += 1;
              for(q in 0..(n02-t-1)){
                SA(k) = bwt(getI(t));
                t += 1;
                k += 1;
              }
            }
          }
        }
      }
    } else {
      var p:Long = 0; 
      var t:Long = n0 - n1;
      var k:Long = -1;
      while(k < n) {
        k += 1;
        val i = getI(t);
        val j = SA0(p);
        //// different compares for mod 1 and mod 2 suffixes
        if(SA12(t) < n0 && leq(string(i), R(SA12(t) + n0), string(j), R(j/3)) ||
           SA12(t) >= n0 && leq(string(i), string(i+1), R(SA12(t) - n0 + 1), string(j), string(j+1), R(j/3 + n0))
          ){ // suffix from SA12 is smaller
          SA(k) = bwt(i); 
          t += 1;
          if(t == n02) {
            k += 1;
            for(q in 0..(n0-p-1)){
              SA(k) = bwt(SA0(p));
              p += 1;
              k += 1;
            }
          }
        } else { // suffix from SA0 is smaller
          SA(k) = bwt(j);
          p += 1;
          if(p == n0) {
            k += 1;
            for(q in 0..(n02-t-1)){
              SA(k) = bwt(getI(t));
              t += 1;
              k += 1;
            }
          }
        }
      }
    }
  }

  private def leq(a1: Long, a2: Long, b1: Long, b2: Long):Boolean {
    return (a1 < b1 || a1 == b1 && a2 <= b2 );
  }

  private def leq(a1: Long, a2: Long, a3: Long, b1: Long, b2: Long, b3: Long):Boolean {
    return (a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
  }

  private def getI(t: Long):Long {
    if(SA12(t) < n0){
      return SA12(t) * 3 + 1; 
    } else {
      return (SA12(t) - n0) * 3 + 2;
    }
  }
/*
  public static def main(args: Rail[String]):void {
    val bwa = new SuffixArrayChar([1y,4y,1y,1y,4y,1y,2y,3y,1y,4y,1y,1y,4y,1y,1y,0y,0y,0y,0y], 5);
    val sa = bwa.run();
    for (i in 0..(sa.size-1)){
      Console.OUT.println(sa(i));
    }
  }
*/
}
