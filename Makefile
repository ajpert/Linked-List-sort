CC = g++ -std=c++11
exe_file = a
$(exe_file): prog.o node.o linked_list.o
	$(CC)  prog.o node.o linked_list.o -o $(exe_file)
prog.o: prog.cpp
	$(CC) -c prog.cpp
node.o: node.cpp
	$(CC) -c node.cpp
linked_list.o: linked_list.cpp
	$(CC) -c linked_list.cpp
clean:
	rm -f *.out *.o $(exe_file)