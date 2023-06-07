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
float Vendedor::calcularSalario(int diasFaltas)
{
    /*
    o cálculo do salário do Vendedor deverá ser feito da seguinte forma:
    
    1. As faltas deverão ser descontadas do salário base;
    2. Após, adicionar uma gratificação que dependerá do tipo de vendedor (25%
    para vendedores A, 10% para vendedores B e 5% para vendedores C)
    3. Por último, somar o adicional por filho do funcionário
    */
    return 0.0;

}
float Vendedor::calcularRecisao(Data desligamento)
{
    /*
    O cálculo da rescisão (demissão) deve ser feita da seguinte forma:
    
    1. O funcionário ganha um salário base por ano trabalhado.
    2. O tempo de trabalho será calculado subtraindo os elementos da struct Data
    considerando a data de ingresso (classe Funcionario) e data de desligamento
    (passado como parâmetro da função calculaRecisão.
    3. A dica é converter os meses e dias para frações de ano.
    */
    return 0.0;
}