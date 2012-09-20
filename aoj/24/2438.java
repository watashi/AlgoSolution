import java.io.*;
import java.util.*;

abstract class MappingItem {
    public int indent = 0;

    public MappingItem get(String key) {
        return MappingNull.NULL;
    }

    public String toString() {
        return "no such property";
    }
}

class MappingNull extends MappingItem {
    static MappingNull NULL = new MappingNull();

    private MappingNull() {
    }
}

class MappingString extends MappingItem {
    String value;

    public MappingString(String value) {
        this.value = value;
    }

    public String toString() {
        return "string \"" + value + "\"";
    }
}

class MappingObject extends MappingItem {
    HashMap<String, MappingItem> object = new HashMap<String, MappingItem>();

    public void put(String key, MappingItem value) {
        object.put(key, value);
    }

    public MappingItem get(String key) {
        if (object.containsKey(key)) {
            return object.get(key);
        } else {
            return MappingNull.NULL;
        }
    }

    public String toString() {
        return "object";
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(
                new InputStreamReader(System.in));
        String selector = in.readLine();
        String[] query = selector.split("\\.");

        MappingObject yaml = new MappingObject();
        yaml.indent = -1;
        Stack<MappingObject> s = new Stack<MappingObject>();
        s.push(yaml);

        String str;
        while ((str = in.readLine()) != null) {
            int indent = 0;
            while (indent < str.length() && str.charAt(indent) == ' ') {
                ++indent;
            }
            str = str.substring(indent);
            while (s.peek().indent >= indent) {
                s.pop();
            }
            if (str.indexOf(':') != str.length() - 1) {
                String[] pair = str.split(": ", 2);
                s.peek().put(pair[0], new MappingString(pair[1]));
            } else {
                MappingObject prop = new MappingObject();
                prop.indent = indent;
                s.peek().put(str.substring(0, str.length() - 1), prop);
                s.push(prop);
            }
        }

        MappingItem p = yaml;
        for (int i = 1; i < query.length; ++i) {
            p = p.get(query[i]);
        }
        System.out.println(p);
    }
}

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Submission Date
//#486482 	watashi 	E 	: Accepted 	JAVA 	00:08 sec 	11000 KB 	Sun Sep 16 13:58:51

//Run# 	Author 	Problem 	Status 	Lang 	Time 	Memory 	Code 	Submission Date
//#490464 	watashi 	2438 	: Accepted 	JAVA 	00:08 sec 	11000 KB 	2566 Bytes 	Thu Sep 20 22:19:21
