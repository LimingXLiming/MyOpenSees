include ../../../../Makefile.def

OBJS       = SIFColumnIter.o SIFSlabIter.o SIFXBeamIter.o SIFSecXBeamIter.o\
SIFYBeamIter.o  \

# Compilation control
all:         $(OBJS)

# Miscellaneous
tidy:	
	@$(RM) $(RMFLAGS) Makefile.bak *~ #*# core

clean: tidy
	@$(RM) $(RMFLAGS) $(OBJS) *.o

spotless: clean

wipe: spotless

# DO NOT DELETE THIS LINE -- make depend depends on it.
