#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include "pessoa.hpp"
#include "funcionario.hpp"

#include <iostream>

class Vendedor: public Pessoa, public Funcionario
{
    private:
        char tipoVendedor;

    public:
        Vendedor();
        Vendedor(std::string nome_, std::string cpf_, Data dataNascimento_, 
                 Endereco enderecoPessoal_, std::string estadoCivil_, 
                 int qtdFilhos_, std::string salario_, std::string matricula_,
                 Data ingressoEmpresa_, char tipoVendedor_);

        char get_tipoVendedor();
        void set_tipoVendedor(char tipoVendedor_);

        void calcularSalario(int diasFaltas);
		float calcularRecisao(Data desligamento);


};

#endif