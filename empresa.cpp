#include "empresa.hpp"

using namespace std;

Empresa::Empresa()
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
    Pessoa dono_empty;
    dono_empty.set_nome("");
    dono_empty.set_cpf("");
    dono_empty.set_dataNascimento(data_empty);
    dono_empty.set_enderecoPessoal(endereco_empty);
    dono_empty.set_estadoCivil("");
    dono_empty.set_qtdFilhos(0);

    this->faturamentoMensal = 0.0;
    this->nomeEmpresa = "";
    this->cnpj = "";
    this->dono = dono_empty;
    this->asgs.clear();
    this->vendedores.clear();
    this->gerentes.clear();
}
Empresa::Empresa(float faturamentoMensal_, std::string nomeEmpresa_, std::string cnpj_)
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
    Pessoa dono_empty;
    dono_empty.set_nome("");
    dono_empty.set_cpf("");
    dono_empty.set_dataNascimento(data_empty);
    dono_empty.set_enderecoPessoal(endereco_empty);
    dono_empty.set_estadoCivil("");
    dono_empty.set_qtdFilhos(0);

    this->faturamentoMensal = faturamentoMensal_;
    this->nomeEmpresa = nomeEmpresa_;
    this->cnpj = cnpj_;
    this->dono = dono_empty;
    this->asgs.clear();
    this->vendedores.clear();
    this->gerentes.clear();
}
float Empresa::get_faturamentoMensal()
{
    return this->faturamentoMensal;
}
std::string Empresa::get_nomeEmpresa()
{
    return this->nomeEmpresa;
}
std::string Empresa::get_cnpj()
{
    return this->cnpj;
}
Pessoa Empresa::get_dono()
{
    return this->dono;
}
std::vector<Asg> Empresa::get_asgs()
{
    return this->asgs;
}
std::vector<Vendedor> Empresa::get_vendedores()
{
    return this->vendedores;
}
std::vector<Gerente> Empresa::get_gerentes()
{
    return this->gerentes;
}

void Empresa::set_faturamentoMensal(float faturamentoMensal_)
{
    this->faturamentoMensal = faturamentoMensal_;
}
void Empresa::set_nomeEmpresa(std::string nomeEmpresa_)
{
    this->nomeEmpresa = nomeEmpresa_;
}
void Empresa::set_cnpj(std::string cnpj_)
{
    this->cnpj = cnpj_;
}
void Empresa::carregarFuncoes()
{
    /*
    Esse é o principal método do programa, deve ler um
    arquivo chamado funcoes.txt e chamar cada uma das funções presentes nas
    linhas desse arquivo até a última linha.
    */
}
void Empresa::carregarEmpresa()
{
    /*
    Lê o arquivo “empresa.txt” e carrega todos os dados da
    empresa (apenas: nome, faturamento, cnpj)
    */
} 
void Empresa::carregarAsg()
{
    /*
    Lê o arquivo “asg.txt” e carrega todos os dados desse arquivo
    no vector asgs.
    */
}
void Empresa::carregarVendedor()
{
    /*
    Lê o arquivo “vendedor.txt” e carrega todos os dados
    desse arquivo no vector vendedores.
    */
}
void Empresa::carregarGerente()
{
    /*
    Lê o arquivo “gerente.txt” e carrega todos os dados desse
    arquivo no vector gerentes.
    */
}
void Empresa::carregarDono()
{
    /*
    Lê o arquivo “dono.txt” e carrega todos os dados desse
    arquivo em dono.
    */
}
void Empresa::imprimeAsgs()
{
    // Imprime todas os atributos de todos os asgs;
}
void Empresa::imprimeVendedores()
{
    // Imprime todas os atributos de todos os vendedores;
}
void Empresa::imprimeGerentes()
{
    // Imprime todas os atributos de todos os gerentes;
}
void Empresa::imprimeDono()
{
    // Imprime todas os atributos de dono
}
void Empresa::buscaFuncionario(int matricula_)
{
    // Caso não encontre deve imprimir a mensagem "Funcionário não encontrado no sistema”
}
void Empresa::calculaSalarioFuncionario(int matricula_)
{
    // Caso não encontre deve imprimir a mensagem "Funcionário não encontrado no sistema”
}
void Empresa::calculaTodosOsSalarios()
{
    /*
    Essa   função   deve   salvar   em   um   arquivo   o
    resultado dos cálculos como o nome, cargo e salário de todos funcionários,
    salvando   também   o   total   de   salários   de   ASGs,   VENDEDORES   e
    GERENTES e, por fim, a soma de todos os salários. Esses resultados
    também devem ser mostrados no console.
    */
}
void Empresa::calcularRecisao(int matricula_, Data desligamento_)
{
    /*
    Calcula   o   valor   da
    rescisão de um funcionário.  Caso não encontre deve imprimir a mensagem
    "Funcionário não encontrado no sistema”
    */
}