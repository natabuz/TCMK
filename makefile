one: 
	g++ -c -fPIC lint.cpp
	g++ -shared -o liblint.so lint.o
	LD_LIBRARY_PATH=./ g++ main.cpp -llint -I. -Wl,-rpath,. -L. -o Prog
	
two:
	swig -c++ -python lint.i
	g++ -fPIC -c lint.cpp
	g++ -fPIC -c lint_wrap.cxx -I/usr/include/python2.7
	g++ -shared lint.o lint_wrap.o -o _lint.so
	
clear:
	rm -f *.o
	rm lint_wrap.cxx
