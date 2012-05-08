f=data/${1:-0}
shift
java -jar Drawer.jar -dump $f.dump -res $f.gif $*
eog $f.gif
