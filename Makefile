CFLAGS 	:= $(shell pkg-config --cflags libpinyin)
LIBS 	:= $(shell pkg-config --libs libpinyin)
DATADIR := $(shell pkg-config --variable=pkgdatadir libpinyin)

test_pinyin_parse_functions.out: test_pinyin_parse_functions.c
	g++ -D SYSTEM_CONF=\"$(DATADIR)/data\" $(CFLAGS) $(LIBS) test_pinyin_parse_functions.c -o test_pinyin_parse_functions.out
