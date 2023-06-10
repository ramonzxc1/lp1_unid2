#ifndef ASG_HPP
#define ASG_HPP

#include "pessoa.hpp"
#include "funcionario.hpp"

class Asg: public Pessoa, public Funcionario
{
    private:
        float adicionalInsalubridade;
    public:
        Asg();
        Asg(std::string nome_, std::string cpf_, Data dataNascimento_, 
            Endereco enderecoPessoal_, std::string estadoCivil_, 
            int qtdFilhos_, std::string salario_, std::string matricula_,
            Data ingressoEmpresa_, float adicionalInsalubridade_);

        float get_adicionalInsalubridade();
        
        void set_adicionalInsalubridade(float adicionalInsalubridade_);

        float calcularSalario(int diasFaltas);
        float calcularRecisao(Data desligamento);
};

#endif