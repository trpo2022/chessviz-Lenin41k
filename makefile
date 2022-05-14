CC=gcc
CFLAGS=-Wall -Wextra
CPPFLAGS=-MMD

.PHONY: clean

bin/chessviz: obj/src/chessviz/main.o obj/lib/libchessviz.a
	$(CC) $(CFLAGS) -o $@ $^

obj/src/chessviz/main.o: src/chessviz/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/lib/libchessviz.a: obj/src/libchessviz/chessviz.o obj/src/chessviz/int_switch_char.o
	ar rcs $@ $^

obj/src/libchessviz/chessviz.o: src/libchessviz/chessviz.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

obj/src/chessviz/int_switch_char.o: src/chessviz/int_switch_char.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

clean:
	rm -rf ./obj/src/*/*.o
	rm -rf ./obj/src/*/*.d

-include int_switch_char.d chessviz.d main.d