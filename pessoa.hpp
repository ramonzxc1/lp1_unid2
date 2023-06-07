#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include "util.hpp"

class Pessoa
{
	private:
		std::string nome;
		std::string cpf;
		Data dataNascimento;
		Endereco enderecoPessoal;
		std::string estadoCivil; // possíveis: solteiro(a), casado(a), viuvo(a), divorciado(a))
		int qtdFilhos;

	public:
		Pessoa();
		Pessoa(std::string nome_, std::string cpf_, Data dataNascimento_, 
			   Endereco enderecoPessoa_, std::string estadoCivil_, int qtdFilhos_);

		std::string get_nome();
		std::string get_cpf();
		Data 		get_dataNascimento();
		Endereco 	get_enderecoPessoal();
		std::string get_estadoCivil();
		int 		get_qtdFilhos();

		void set_nome(std::string nome_);
		void set_cpf(std::string cpf_);
		void set_dataNascimento(Data dataNascimento_);
		void set_enderecoPessoal(Endereco enderecoPessoal_);
		void set_estadoCivil(std::string estadoCivil_);
		void set_qtdFilhos(int qtdFilhos_);
};

#endif