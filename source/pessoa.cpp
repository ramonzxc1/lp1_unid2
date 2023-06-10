#include "../headers/pessoa.hpp"

using namespace std;

Pessoa::Pessoa()
{
	this->nome = "";
	this->cpf = "";
	this->dataNascimento.ano = 0;
	this->dataNascimento.mes = 0;
	this->dataNascimento.dia = 0;
	this->enderecoPessoal.cidade = "";
	this->enderecoPessoal.bairro = "";
	this->enderecoPessoal.rua = "";
	this->enderecoPessoal.cep = "";
	this->enderecoPessoal.numero = 0;
	this->estadoCivil = "";
	this->qtdFilhos = 0;
};
Pessoa::Pessoa(std::string nome_, std::string cpf_, Data dataNascimento_, Endereco enderecoPessoa_, std::string estadoCivil_, int qtdFilhos_)
{
	this->nome = nome_;
	this->cpf = cpf_;
	this->dataNascimento = dataNascimento_;
	this->enderecoPessoal = enderecoPessoa_;
	this->estadoCivil = estadoCivil_;
	this->qtdFilhos = qtdFilhos_;
};

std::string Pessoa::get_nome()
{
	return this->nome;
}
std::string Pessoa::get_cpf()
{
	return this->cpf;
}
Data Pessoa::get_dataNascimento()
{
	return this->dataNascimento;
}
Endereco Pessoa::get_enderecoPessoal()
{
	return this->enderecoPessoal;
}
std::string Pessoa::get_estadoCivil()
{
	return this->estadoCivil;
}
int Pessoa::get_qtdFilhos()
{
	return this->qtdFilhos;
}
void Pessoa::set_nome(std::string nome_)
{
	this->nome = nome_;
}
void Pessoa::set_cpf(std::string cpf_)
{
	this->cpf = cpf_;
}
void Pessoa::set_dataNascimento(Data dataNascimento_)
{
	this->dataNascimento = dataNascimento_;
}
void Pessoa::set_enderecoPessoal(Endereco enderecoPessoal_)
{
	this->enderecoPessoal = enderecoPessoal_;
}
void Pessoa::set_estadoCivil(std::string estadoCivil_)
{
	this->estadoCivil = estadoCivil_;
}
void Pessoa::set_qtdFilhos(int qtdFilhos_)
{
	this->qtdFilhos = qtdFilhos_;
}