#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "pessoa.hpp"
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

#include <iostream>
#include <vector>

class Empresa
{
    private:
        float faturamentoMensal;
        std::string nomeEmpresa;
        std::string cnpj;
        Pessoa dono;
        std::vector<Asg> asgs;
        std::vector<Vendedor> vendedores;
        std::vector<Gerente> gerentes;

    public:
        Empresa();
        Empresa(float faturamentoMensal_, std::string nomeEmpresa_, std::string cpnj_);

        float get_faturamentoMensal();
        std::string get_nomeEmpresa();
        std::string get_cnpj();
        Pessoa get_dono();
        std::vector<Asg> get_asgs();
        std::vector<Vendedor> get_vendedores();
        std::vector<Gerente> get_gerentes();

        void set_faturamentoMensal(float faturamentoMensal_);
        void set_nomeEmpresa(std::string nomeEmpresa_);
        void set_cnpj(std::string cnpj_);

        void carregarFuncoes();
        void carregarEmpresa();
        void carregarAsg();
        void carregarVendedor();
        void carregarGerente();
        void carregaDono();
        void imprimeAsgs();
        void imprimeVendedores();
        void imprimeGerentes();
        void imprimeDono();
        bool buscaFuncionario(std::string matricula_);
        void calculaSalarioFuncionario(std::string matricula_); 
        void calculaTodoOsSalarios();
        void calcularRecisao(std::string matricula_, Data desligamento_);
};

#endif