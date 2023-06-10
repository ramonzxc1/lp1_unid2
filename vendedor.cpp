#include "vendedor.hpp"

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
void Vendedor::calcularSalario(int diasFaltas)
{
    // Salario base.

    float salario = stof(get_salario());

    // As faltas deverão ser descontadas do salário base.
    salario = salario - diasFaltas * (salario / (365.25/12.0)); // Um dia em um ano: 365.25/12.0
    // Após, adicionar uma gratificação que dependerá do tipo de vendedor (25%
    // para vendedores A, 10% para vendedores B e 5% para vendedores C)
    if(this->tipoVendedor == 'A')
        salario = salario + salario * 0.25;
    else if(this->tipoVendedor == 'B')
        salario = salario + salario * 0.10;
    else if(this->tipoVendedor == 'C')
        salario = salario + salario * 0.05;

    // Por último, somar o adicional por filho do funcionário.
    salario = salario + 100.0 * get_qtdFilhos();

    this->set_salario(to_string(salario));

}
float Vendedor::calcularRecisao(Data desligamento)
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