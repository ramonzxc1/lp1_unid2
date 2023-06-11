#include "../headers/gerente.hpp"

using namespace std;

Gerente::Gerente()
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
    this->participacaoLucros = 0.0;
}
Gerente::Gerente(std::string nome_, std::string cpf_, Data dataNascimento_, 
                 Endereco enderecoPessoal_, std::string estadoCivil_, 
                 int qtdFilhos_, std::string salario_, std::string matricula_,
                 Data ingressoEmpresa_, float participacaoLucros_)
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
    this->participacaoLucros = participacaoLucros_;
}

float Gerente::get_participacaoLucros()
{
    return this->participacaoLucros;
}
void Gerente::set_participacaoLucros(float participacaoLucros_)
{
    this->participacaoLucros = participacaoLucros_;
}
float Gerente::calcularSalario(int diasFaltas)
{
    float salario_base = stof(get_salario());

    // Tempo de trabalho em dias.
    float tempo_de_trabalho = diasFaltas / 31; // Para simplificar, um mes tem 31 dias, que eh o maximo que um funcionario pode faltar num mes.
    
    float desconto_salario = tempo_de_trabalho * salario_base;

    float salario_calculado;
    // As faltas deverão ser descontadas do salário base.
    salario_calculado = salario_base - desconto_salario;
    // Após, some a participação no lucros
    salario_calculado += this->participacaoLucros;
    // Por último, somar o adicional por filho do funcionário.
    salario_calculado += 100.0 * get_qtdFilhos(); // Cada filho incrementa 100.0 reais.
    
    // Retornando o salario calculado.
    return salario_calculado;
}
float Gerente::calcularRecisao(Data desligamento)
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