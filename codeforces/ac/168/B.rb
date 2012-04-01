puts gets(p).gsub(/(^(?! *#).*\n)+/){$&.gsub(/\s/, '') + "\n"}
