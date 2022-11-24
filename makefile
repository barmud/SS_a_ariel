C=gcc
AR=ar
FLAGS = -Wall -g
M = -lm

all: mains maindloop maindrec loops recursives recursived loopd

mains: libclassrec.a main.o
	$(C) $(FLAGS) main.o ./libclassrec.a -o mains $(M)
maindloop: libclassloops.so main.o
	$(C) $(FLAGS) main.o ./libclassloops.so -o maindloop $(M)
maindrec: libclassrec.so main.o
	$(C) $(FLAGS) main.o ./libclassrec.so -o maindrec $(M)

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o


libclassrec.so: basicClassification.c advancedClassificationRecursion.c
	$(C) $(FLAGS) -fPIC -shared -o ./libclassrec.so basicClassification.c advancedClassificationRecursion.c
libclassloops.so: basicClassification.c advancedClassificationLoop.c
	$(C) $(FLAGS) -fPIC -shared -o ./libclassloops.so basicClassification.c advancedClassificationLoop.c

loops: libclassloops.a
recursives:libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so

main.o: main.c NumClass.h
	$(C) $(FLAGS) -c main.c

	
basicClassification.o : basicClassification.c
	$(C) $(FLAGS) -c basicClassification.c
advancedClassificationLoop.o : advancedClassificationLoop.c NumClass.h
	$(C) $(FLAGS) -c advancedClassificationLoop.c
advancedClassificationRecursion.o : advancedClassificationRecursion.c NumClass.h
	$(C) $(FLAGS) -c advancedClassificationRecursion.c



clean:
	rm -rf *.o *.a *.so mains maindloop maindrec
.phony: clean,all