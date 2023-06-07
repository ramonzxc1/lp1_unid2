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
    float temp_salario = stof(get_salario());

    // As faltas deverão ser descontadas do salário base.
    temp_salario = temp_salario - diasFaltas * (temp_salario / (365.25/12));
    // Após, adicionar o adicional de insalubridade
    temp_salario = temp_salario + temp_salario * adicionalInsalubridade;
    // Por último, somar o adicional por filho do funcionário.
    temp_salario = temp_salario + 100.0 * get_qtdFilhos();

    return temp_salario;
}
float Asg::calcularRecisao(Data desligamento)
{
    /*
    O cálculo da rescisão (demissão) deve ser feita da seguinte forma:

    1. O funcionário ganha um salário base por ano trabalhado.
    2. O tempo de trabalho será calculado em subtraindo os elementos da struct
    Data considerando a data de ingresso (classe Funcionario) e data de
    desligamento (passado como parâmetro da função calculaRecisão.
    3. A dica é converter os meses e dias para frações de ano.
    */

    Data temp_data;
    temp_data.ano = desligamento.ano - get_ingressoEmpresa().ano;
    temp_data.mes = desligamento.mes - get_ingressoEmpresa().mes;
    temp_data.dia = desligamento.dia - get_ingressoEmpresa().dia;

    float temp_dias = (365.25)*temp_data.ano + (365.25/12)*temp_data.mes + (1.0)*temp_data.dia;

    float temp_salario = stof(get_salario());

    return (temp_dias/365.25) * temp_salario;
}