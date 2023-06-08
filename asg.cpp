#include "asg.hpp"

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
    // Salario base.

    float salario = stof(get_salario());

    // As faltas deverão ser descontadas do salário base.
    salario = salario - diasFaltas * (salario / (365.25/12));
    // Após, adicionar o adicional de insalubridade
    salario = salario + salario * adicionalInsalubridade;
    // Por último, somar o adicional por filho do funcionário.
    salario = salario + 100.0 * get_qtdFilhos();

    return salario;
}
float Asg::calcularRecisao(Data desligamento)
{
    // O funcionário ganha um salário base por ano trabalhado.
    
    float salario_base = stof(get_salario());

    // Calculando o tempo em dias totais de trabalho.

    Data tempo_de_trabalho;
    tempo_de_trabalho.ano = desligamento.ano - get_ingressoEmpresa().ano;
    tempo_de_trabalho.mes = desligamento.mes - get_ingressoEmpresa().mes;
    tempo_de_trabalho.dia = desligamento.dia - get_ingressoEmpresa().dia;

    // Quantidade de dias em:
    //   ano: 365.25/1.0;
    //   mes: 365.25/12.0;
    //   dia: 365.25/365.25.

    float dias_trabalhados  =   (365.25/1.0)    * tempo_de_trabalho.ano
                              + (365.25/12.0)   * tempo_de_trabalho.mes
                              + (365.25/365.25) * tempo_de_trabalho.dia;

    // Retornando a quantidade de anos de trabalho vezes o salario.

    // Convertendo dias para anos:
    //   dias_trabalhados/365.25

    return (dias_trabalhados/365.25) * salario_base;
}