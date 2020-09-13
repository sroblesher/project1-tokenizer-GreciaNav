tokenizer: tokenizer.o uimain.o 
	cc -o tokenizer tokenizer.o uimain.o

clean:
	rm -f *.o tokenizer

tokenizer.o: tokenizer.h tokenizer.c

uimain.o: uimain.c tokenizer.h

