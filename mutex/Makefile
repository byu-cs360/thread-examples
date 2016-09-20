CXX=		g++ $(CCFLAGS)
MUTEX=		main.o worker.o
OBJS =		$(MUTEX)

LIBS=		-pthread -std=c++11

CCFLAGS= -g

all:		mutex

mutex:	$(MUTEX)
		$(CXX) -o mutex $(MUTEX) $(LIBS)

clean:
		rm -f $(OBJS) $(OBJS:.o=.d)

realclean:
		rm -f $(OBJS) $(OBJS:.o=.d) mutex

%.o : %.cc
		$(CXX) -c -o $@ -MD -MP ${CPPFLAGS} ${CXXFLAGS} $<

-include	$(OBJS:.o=.d)
