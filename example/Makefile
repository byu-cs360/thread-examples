CXX=		g++ $(CCFLAGS)
EXAMPLE=	main.o
OBJS =		$(EXAMPLE)

LIBS=		-pthread -std=c++11

CCFLAGS= -g

all:		example

example:	$(EXAMPLE)
		$(CXX) -o example $(EXAMPLE) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
		rm -f $(OBJS) $(OBJS:.o=.d) example

%.o : %.cc
		$(CXX) -c -o $@ -MD -MP ${CPPFLAGS} ${CXXFLAGS} $<

-include	$(OBJS:.o=.d)
