CXX=		g++ $(CXXFLAGS)
EXAMPLE=	main.o
OBJS =		$(EXAMPLE)

LIBS=		-pthread -std=c++11

CXXFLAGS= -g

all:		example

example:	$(EXAMPLE)
		$(CXX) -o example $(EXAMPLE) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
		rm -f $(OBJS) $(OBJS:.o=.d) example

%.o : %.cc
		$(CXX) -c -o $@ -MD -MP ${CXXFLAGS} $<

-include	$(OBJS:.o=.d)
