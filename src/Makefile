main: programa
 
Scanner.cc: Scanner.l
  flex++ -o $<
 
parse.cc: Parser.y
  bisonc++ $<
 
Scanner.o: Scanner.cc
  g++ -c $<
 
parse.o: parse.cc
  g++ -c $<
 
programa: parse.o Scanner.o
  g++ -o $@ $< -lfl
 
clean:
  rm -rf *.o *.cc *.h *.ih
