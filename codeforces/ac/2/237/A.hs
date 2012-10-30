import Data.List
main=interact$show.maximum.map length.group.lines
