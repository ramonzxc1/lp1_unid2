#include "../headers/vendedor.hpp"

using namespace std;

Vendedor::Vendedor()
{
    Data temp_data;
    temp_data.ano = 0;
    temp_data.mes = 0;
    temp_data.dia = 0;
    Endereco temp_endereco;
    temp_endereco.cidade = "";
    temp_endereco.bairro = "";
    temp_endereco.rua = "";
    temp_endereco.cep = "";
    temp_endereco.numero = 0;
    this->set_nome("");
    this->set_cpf("");
    this->set_dataNascimento(temp_data);
    this->set_enderecoPessoal(temp_endereco);
    this->set_estadoCivil("");
    this->set_qtdFilhos(0);
    this->set_salario("");
    this->set_matricula("");
    this->set_ingressoEmpresa(temp_data);
    this->tipoVendedor = '\0';
}
Vendedor::Vendedor(string nome_, string cpf_, Data dataNascimento_, Endereco enderecoPessoal_, 
                   string estadoCivil_, int qtdFilhos_, string salario_, string matricula_,
                   Data ingressoEmpresa_, char tipoVendedor_)
{
    this->set_nome(nome_);
    this->set_cpf(cpf_);
    this->set_dataNascimento(dataNascimento_);
    this->set_enderecoPessoal(enderecoPessoal_);
    this->set_estadoCivil(estadoCivil_);
    this->set_qtdFilhos(qtdFilhos_);
    this->set_salario(salario_);
    this->set_matricula(matricula_);
    this->set_ingressoEmpresa(ingressoEmpresa_);
    this->tipoVendedor = tipoVendedor_;
}
char Vendedor::get_tipoVendedor()
{
    return this->tipoVendedor;
}
void Vendedor::set_tipoVendedor(char tipoVendedor_)
{
    this->tipoVendedor = tipoVendedor_;
}
float Vendedor::calcularSalario(int diasFaltas)
{
    float salario_base = stof(get_salario());

    // Tempo de trabalho em dias.
    float tempo_de_trabalho = diasFaltas / 31; // Para simplificar, um mes tem 31 dias, que eh o maximo que um funcionario pode faltar num mes.

    float desconto_salario = tempo_de_trabalho * salario_base;

    float salario_calculado;
    // As faltas deverão ser descontadas do salário base.
    salario_calculado = salario_base - desconto_salario;
    // Após, adicionar uma gratificação que dependerá do tipo de vendedor
    // (25% para vendedores A, 10% para vendedores B e 5% para vendedores C)
    if(this->tipoVendedor == 'A')
        salario_calculado += salario_calculado * 0.25;
    else if(this->tipoVendedor == 'B')
        salario_calculado += salario_calculado * 0.10;
    else if(this->tipoVendedor == 'C')
        salario_calculado += salario_calculado * 0.05;
    // Por último, somar o adicional por filho do funcionário.
    salario_calculado += 100.0 * get_qtdFilhos(); // Cada filho incrementa 100.0 reais.
    
    // Retornando o salario calculado.
    return salario_calculado;
}
float Vendedor::calcularRecisao(Data desligamento)
{
    float salario_base = stof(get_salario());

    float anos_trabalhados;
    // (ano/ano) * (ano/1) == ano/1 == ano
    anos_trabalhados  = (1.0/1.0) * (desligamento.ano - get_ingressoEmpresa().ano);
    // (ano/mes) * (mes/1) == ano/1 == ano
    anos_trabalhados += (1.0/12.0) * (desligamento.mes - get_ingressoEmpresa().mes);
    // (ano/dia) * (dia/1) == ano/1 == ano
    anos_trabalhados += (1.0/365.0) * (desligamento.dia - get_ingressoEmpresa().dia);

    // Retornando o salario base por ano trabalhado.
    return anos_trabalhados * salario_base;
}