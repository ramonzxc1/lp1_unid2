#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "util.hpp"
#include <iostream>

class Funcionario
{
	private:
		std::string salario;
		std::string matricula;
		Data ingressoEmpresa;
	public:
		std::string get_salario();
		std::string get_matricula();
		Data 		get_ingressoEmpresa();

		void set_salario(std::string salario_);
		void set_matricula(std::string matricula_);
		void set_ingressoEmpresa(Data ingressoEmpresa_);

		virtual void calcularSalario(int diasFaltas) = 0;
		virtual float calcularRecisao(Data desligamento) = 0;
};

#endif