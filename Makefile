compilar:
	g++ -c -Wall -Wextra source/main.cpp -o objects/main.o
	g++ -c -Wall -Wextra source/asg.cpp -o objects/asg.o
	g++ -c -Wall -Wextra source/empresa.cpp -o objects/empresa.o
	g++ -c -Wall -Wextra source/funcionario.cpp -o objects/funcionario.o
	g++ -c -Wall -Wextra source/gerente.cpp -o objects/gerente.o
	g++ -c -Wall -Wextra source/pessoa.cpp -o objects/pessoa.o
	g++ -c -Wall -Wextra source/vendedor.cpp -o objects/vendedor.o

linkar:
	g++ -o exec objects/main.o objects/asg.o objects/empresa.o objects/funcionario.o objects/gerente.o objects/pessoa.o objects/vendedor.o

rodar:
	./exec

limpar:
	rm -f objects/*.o