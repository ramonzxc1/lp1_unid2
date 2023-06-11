#include "../headers/asg.hpp"

using namespace std;

Asg::Asg()
{
    Data data_empty;
    data_empty.ano = 0;
    data_empty.mes = 0;
    data_empty.dia = 0;
    Endereco endereco_empty;
    endereco_empty.cidade = "";
    endereco_empty.bairro = "";
    endereco_empty.rua = "";
    endereco_empty.cep = "";
    endereco_empty.numero = 0;
    this->set_nome("");
    this->set_cpf("");
    this->set_dataNascimento(data_empty);
    this->set_enderecoPessoal(endereco_empty);
    this->set_estadoCivil("");
    this->set_qtdFilhos(0);
    this->set_salario("");
    this->set_matricula("");
    this->set_ingressoEmpresa(data_empty);
    this->adicionalInsalubridade = 0.0;
}
Asg::Asg(string nome_, string cpf_, Data dataNascimento_, Endereco enderecoPessoal_, 
         string estadoCivil_, int qtdFilhos_, string salario_, string matricula_,
         Data ingressoEmpresa_, float adicionalInsalubridade_)
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
    this->adicionalInsalubridade = adicionalInsalubridade_;
}
float Asg::get_adicionalInsalubridade()
{
    return this->adicionalInsalubridade;
}
void Asg::set_adicionalInsalubridade(float adicionalInsalubridade_)
{
    this->adicionalInsalubridade = adicionalInsalubridade_;
}
float Asg::calcularSalario(int diasFaltas)
{  
    float salario_base = stof(get_salario());

    // Tempo de trabalho em dias.
    float tempo_de_trabalho = diasFaltas / 30; // Um mes tem 30 dias
    
    float desconto_salario = tempo_de_trabalho * salario_base;

    float salario_calculado;
    // As faltas deverão ser descontadas do salário base.
    salario_calculado = salario_base - desconto_salario;
    // Após, adicionar o adicional de insalubridade
    salario_calculado += adicionalInsalubridade * salario_calculado;
    // Por último, somar o adicional por filho do funcionário.
    salario_calculado += 100.0 * get_qtdFilhos(); // Cada filho incrementa 100.0 reais.
    
    // Retornando o salario calculado.
    return salario_calculado;
}
float Asg::calcularRecisao(Data desligamento)
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