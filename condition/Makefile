CXX=		g++ $(CXXFLAGS)
CONDITION=	main.o first.o second.o
OBJS =		$(CONDITION)

LIBS=		-pthread -std=c++11

CXXFLAGS= -g

all:		condition

condition:	$(CONDITION)
		$(CXX) -o condition $(CONDITION) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
		rm -f $(OBJS) $(OBJS:.o=.d) condition

%.o : %.cc
		$(CXX) -c -o $@ -MD -MP ${CXXFLAGS} $<

-include	$(OBJS:.o=.d)
