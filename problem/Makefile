CXX=		g++ $(CCFLAGS)
PROBLEM=		main.o worker.o
OBJS =		$(PROBLEM)

LIBS=		-pthread -std=c++11

CCFLAGS= -g

all:		problem

problem:	$(PROBLEM)
		$(CXX) -o problem $(PROBLEM) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
		rm -f $(OBJS) $(OBJS:.o=.d) problem

%.o : %.cc
		$(CXX) -c -o $@ -MD -MP ${CPPFLAGS} ${CXXFLAGS} $<

-include	$(OBJS:.o=.d)
