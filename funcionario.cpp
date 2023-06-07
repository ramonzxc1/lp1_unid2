#include "funcionario.hpp"

using namespace std;

std::string Funcionario::get_salario()
{
	return this->salario;
}
std::string Funcionario::get_matricula()
{
	return this->matricula;
}
Data Funcionario::get_ingressoEmpresa()
{
	return this->ingressoEmpresa;
}
void Funcionario::set_salario(std::string salario_)
{
	this->salario = salario_;
}
void Funcionario::set_matricula(std::string matricula_)
{
	this->matricula = matricula_;
}
void Funcionario::set_ingressoEmpresa(Data ingressoEmpresa_)
{
	this->ingressoEmpresa = ingressoEmpresa_;
}