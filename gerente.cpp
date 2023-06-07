#include "gerente.hpp"

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
    /*
    o cálculo do salário do Vendedor deverá ser feito da seguinte forma:

    1. As faltas deverão ser descontadas do salário base;
    2. Após, some a participação no lucros (atributo da própria classe)
    3. Por último, somar o adicional por filho do funcionário.
    */
    return 0.0;
}
float Gerente::calcularRecisao(Data desligamento)
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