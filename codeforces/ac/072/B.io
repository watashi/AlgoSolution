ini := Map clone
section := ""
ini atPut(section, Map clone)

n := File standardInput readLine asNumber
File standardInput readLines foreach(line,
	line = line asMutable strip
	if (line containsSeq(";"), continue)
	if (line containsSeq("["),
		section = line strip("[") strip("]") strip
		ini atIfAbsentPut(section, Map clone),
		
		kv := line split("=")
		key := kv at(0) asMutable strip
		value := kv at(1) asMutable strip
		ini at(section) atPut(key, value)
	)
)
ini keys sort foreach(section,
	if (section size > 0, ("[" .. section .. "]") println)
	subini := ini at(section)
	subini keys sort foreach(key,
		value = subini at(key)
		(key .. "=" .. value) println
	)
)
