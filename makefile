CC=gcc
CFLAGS=-Wall -Wextra
CPPFLAGS=-MMD

chessviz: obj/src/chessviz/main.o bin/libchessviz.a
	$(CC) $(CFLAGS) -o $@ $^

obj/src/chessviz/main.o: src/chessviz/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

bin/libchessviz.a: obj/src/libchessviz/chessviz.o obj/src/chessviz/int_switch_char.o
	ar rcs $@ $^

obj/src/libchessviz/chessviz.o: src/libchessviz/chessviz.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/src/chessviz/int_switch_char.o: src/chessviz/int_switch_char.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clear: obj/src/chessviz/*.o
	rm -f obj/src/*chessviz/*.o

-include int_switch_char.d chessviz.d main.d