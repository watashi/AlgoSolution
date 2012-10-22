// SGU552. Database optimization
import java.io.*;
import java.util.*;

class SmartBitSet {
  static final int THRESHOLD = 256;

  HashSet<Integer> hs;
  BitSet bs;

  SmartBitSet() {
    hs = new HashSet<Integer>();
    bs = null;
  }

  void useHashSet() {
    if (hs == null) {
      hs = new HashSet<Integer>();
      for (int i = bs.nextSetBit(0); i >= 0; i = bs.nextSetBit(i + 1)) {
        hs.add(i);
      }
      bs = null;
    }
  }

  void useBitSet() {
    if (bs == null) {
      bs = new BitSet();
      for (int i: hs) {
        bs.set(i);
      }
      hs = null;
    }
  }

  void add(Integer i) {
    if (hs != null) {
      hs.add(i);
      if (hs.size() > THRESHOLD) {
        useBitSet();
      }
    } else {
      bs.set(i);
    }
  }

  boolean isEmpty() {
    if (hs != null) {
      return hs.isEmpty();
    } else {
      return bs.isEmpty();
    }
  }

  int size() {
    if (hs != null) {
      return hs.size();
    } else {
      return bs.cardinality();
    }
  }

  SmartBitSet intersect(SmartBitSet o) {
    SmartBitSet ret = new SmartBitSet();
    if (o.hs != null && (hs == null || hs.size() > o.hs.size())) {
      ret = o.intersect(this);
    } else if (hs == null) {
      ret.hs = null;
      ret.bs = (BitSet)bs.clone();
      ret.bs.and(o.bs);
      if (ret.bs.cardinality() < THRESHOLD) {
        ret.useHashSet();
      }
      return ret;
    } else if (o.hs == null) {
      for (int i: hs) {
        if (o.bs.get(i)) {
          ret.add(i);
        }
      }
    } else {
      for (int i: hs) {
        if (o.hs.contains(i)) {
          ret.add(i);
        }
      }
    }
    return ret;
  }
}

public class Solution {
  static final SmartBitSet EMPTY = new SmartBitSet();

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(in.readLine());
    HashMap<String, SmartBitSet> map = new HashMap<String, SmartBitSet>(n);
    for (int i = 0; i < n; ++i) {
      String prop[] = in.readLine().split(" ");
      for (int j = 1; j < prop.length; ++j) {
        if (!map.containsKey(prop[j])) {
          map.put(prop[j], new SmartBitSet());
        }
        map.get(prop[j]).add(i);
      }
    }

    int m = Integer.parseInt(in.readLine());
    for (int i = 0; i < m; ++i) {
      String prop[] = in.readLine().split(" ");
      SmartBitSet ans = map.get(prop[1]);
      if (ans == null) {
        ans = EMPTY;
      }
      for (int j = 2; j < prop.length && !ans.isEmpty(); ++j) {
        SmartBitSet set = map.get(prop[j]);
        ans = ans.intersect(set != null ? set : EMPTY);
      }
      System.out.println(ans.size());
    }
  }
}

// THRESHOLD = 218, 256, 512

// ID: 	Date'n'Time: 	Name: 	Task: 	.Ext: 	Status: 	Time: 	Memory:
// 1379907	22.10.12 21:48	watashi	552 	.JAVA	Accepted 	4512 ms	84780 kb
// 1375225	22.10.12 19:30	watashi	K 	.JAVA	Accepted	5121 ms	84784 kb
// 1375187	22.10.12 19:25	watashi	K 	.JAVA	Time Limit Exceeded on test 37	6051 ms	84776 kb
