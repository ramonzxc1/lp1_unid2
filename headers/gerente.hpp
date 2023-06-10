#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "pessoa.hpp"
#include "funcionario.hpp"

#include <iostream>

class Gerente: public Pessoa, public Funcionario
{
    private:
        float participacaoLucros;
    
    public:
        Gerente();
        Gerente(std::string nome_, std::string cpf_, Data dataNascimento_, 
                 Endereco enderecoPessoal_, std::string estadoCivil_, 
                 int qtdFilhos_, std::string salario_, std::string matricula_,
                 Data ingressoEmpresa_, float participacaoLucros_);

        float get_participacaoLucros();
        void set_participacaoLucros(float participacaoLucros_);

        void calcularSalario(int diasFaltas);
		float calcularRecisao(Data desligamento);
};

#endif