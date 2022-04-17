CC=gcc
CFLAGS=-Wall -Wextra
CPPFLAGS=-MMD

chessviz: obj/src/chessviz/main.o libchessviz.a obj/src/chessviz/int_switch_char.o
	$(CC) $(CFLAGS) -o $@ $^

obj/src/chessviz/main.o: src/chessviz/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

libchessviz.a: obj/src/libchessviz/chessviz.o
	ar rcs $@ $^

obj/src/libchessviz/chessviz.o: src/libchessviz/chessviz.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/src/chessviz/int_switch_char.o: src/chessviz/int_switch_char.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

-include chessviz.d chessviz.d