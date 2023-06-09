compilar:
	g++ -c -Wall -Wextra main.cpp asg.cpp empresa.cpp funcionario.cpp gerente.cpp pessoa.cpp vendedor.cpp

linkar:
	g++ -o main main.o asg.o empresa.o funcionario.o gerente.o pessoa.o vendedor.o

rodar:
	./main