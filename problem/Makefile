CXX=		g++ $(CXXFLAGS)
PROBLEM=		main.o worker.o
OBJS =		$(PROBLEM)

LIBS=		-pthread -std=c++11

CXXFLAGS= -g

all:		problem

problem:	$(PROBLEM)
		$(CXX) -o problem $(PROBLEM) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
		rm -f $(OBJS) $(OBJS:.o=.d) problem

%.o : %.cc
		$(CXX) -c -o $@ -MD -MP ${CXXFLAGS} $<

-include	$(OBJS:.o=.d)
