#include "../headers/empresa.hpp"

#include <iostream>

using namespace std;

int main()
{
    Empresa *atacadoDosCalcado = new Empresa(156289.56, "Atacado dos Calcados", "40.101.588/0001-98");
    atacadoDosCalcado->carregarFuncoes();
}