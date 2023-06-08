#include "empresa.hpp"

#include <fstream>
#include <string>

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
    int matricula;
    Data desligamento;

    fstream arquivo;
    arquivo.open("arquivos para leitura/funcoes.txt", ios::in);
    string linha;
    while(getline(arquivo, linha))
    {
        if(linha == "carregarEmpresa()")        this->carregarEmpresa();
        else if(linha == "carregarAsg()")       this->carregarAsg();
        else if(linha == "carregarVendedor()")  this->carregarVendedor();
        else if(linha == "carregarGerente()")   this->carregarGerente();
        else if(linha == "carregaDono()")       this->carregaDono();
        else if(linha == "imprimeAsgs()")       this->imprimeAsgs();
        else if(linha == "imprimeVendedores()") this->imprimeVendedores();
        else if(linha == "imprimeGerentes()")   this->imprimeGerentes();
        else if(linha == "imprimeDono()")       this->imprimeDono();
        /*
        // Como saber qual funcionario e matricula devo buscar?
        // "matricula" no .txt vai dar problema na hora de converter para inteiro com stoi.
        else if(linha == "buscaFuncionario()")
        {
            getline(arquivo, linha);
            matricula = stoi(linha);
            this->buscaFuncionario(matricula); 
        }
        // Como saber qual funcionario e matricula devo calcular?
        // "matricula" no .txt vai dar problema na hora de converter para inteiro com stoi.
        else if(linha == "calculaSalarioFuncionario()") 
        {
            getline(arquivo, linha);
            matricula = stoi(linha);
            this->calculaSalarioFuncionario(matricula);
        }
        */

        else if(linha == "calculaTodoOsSalarios()") this->calculaTodoOsSalarios();
        
        /*
        // Como saber qual funcionario, matricula e data devo calcular?
        // "matricula", "ano", "mes" e "dia" no .txt vao dar problema na hora de converter para inteiro com stoi.
        else if(linha == "calcularRecisao()")
        {
            getline(arquivo, linha);
            matricula = stoi(linha);
            getline(arquivo, linha);
            desligamento.ano = stoi(linha);
            getline(arquivo, linha);
            desligamento.mes = stoi(linha);
            getline(arquivo, linha);
            desligamento.dia = stoi(linha);
            this->calcularRecisao(matricula, desligamento);
        }
        */
    }
    arquivo.close();
}
void Empresa::carregarEmpresa()
{
    /*
    Lê o arquivo “empresa.txt” e carrega todos os dados da
    empresa (apenas: nome, faturamento, cnpj)
    */

    fstream arquivo;
    arquivo.open("arquivos para leitura/empresa.txt", ios::in);
    string linha;
    getline(arquivo, linha); // Ignora linha 1.
    getline(arquivo, linha); // Ignora linha 2.
    getline(arquivo, linha);
    this->set_nomeEmpresa(linha);
    getline(arquivo, linha);
    this->set_cnpj(linha);
    getline(arquivo, linha);
    this->set_faturamentoMensal(stof(linha));
    arquivo.close(); // Fecha o arquivo sem ler a ultima linha, ou seja, ignorando-a.
} 
void Empresa::carregarAsg()
{
    /*
    Lê o arquivo “asg.txt” e carrega todos os dados desse arquivo
    no vector asgs.
    */
    Asg temp_asg;
    Endereco temp_endereco;
    Data temp_data;


    fstream arquivo;
    arquivo.open("arquivos para leitura/asg.txt", ios::in);
    string linha;
    while(getline(arquivo, linha)) // Ignora linha 1.
    {
        getline(arquivo, linha); // Ignora linha 2.
        getline(arquivo, linha); // Ignora linha 3.

        getline(arquivo, linha);
        temp_asg.set_nome(linha);
        getline(arquivo, linha);
        temp_asg.set_cpf(linha);
        getline(arquivo, linha);
        temp_asg.set_qtdFilhos(stoi(linha));
        getline(arquivo, linha);
        temp_asg.set_estadoCivil(linha);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_endereco.cidade = linha;
        getline(arquivo, linha);
        temp_endereco.cep = linha;
        getline(arquivo, linha);
        temp_endereco.bairro = linha;
        getline(arquivo, linha);
        temp_endereco.rua = linha;
        getline(arquivo, linha);
        temp_endereco.numero = stoi(linha);

        temp_asg.set_enderecoPessoal(temp_endereco);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_data.ano = stoi(linha);
        getline(arquivo, linha);
        temp_data.mes = stoi(linha);
        getline(arquivo, linha);
        temp_data.dia = stoi(linha);

        temp_asg.set_dataNascimento(temp_data);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_asg.set_matricula(linha);
        getline(arquivo, linha);
        temp_asg.set_salario(linha);
        getline(arquivo, linha);
        temp_asg.set_adicionalInsalubridade(stof(linha));
        getline(arquivo, linha);
        temp_asg.calcularSalario(stoi(linha));
        
        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_data.ano = stoi(linha);
        getline(arquivo, linha);
        temp_data.mes = stoi(linha);
        getline(arquivo, linha);
        temp_data.dia = stoi(linha);

        temp_asg.set_ingressoEmpresa(temp_data);

        this->asgs.push_back(temp_asg);
    }
    arquivo.close();
}
void Empresa::carregarVendedor()
{
    /*
    Lê o arquivo “vendedor.txt” e carrega todos os dados
    desse arquivo no vector vendedores.
    */
    Vendedor temp_vendedor;
    Endereco temp_endereco;
    Data temp_data;


    fstream arquivo;
    arquivo.open("arquivos para leitura/vendedor.txt", ios::in);
    string linha;
    while(getline(arquivo, linha)) // Ignora linha 1.
    {
        getline(arquivo, linha); // Ignora linha 2.
        getline(arquivo, linha); // Ignora linha 3.

        getline(arquivo, linha);
        temp_vendedor.set_nome(linha);
        getline(arquivo, linha);
        temp_vendedor.set_cpf(linha);
        getline(arquivo, linha);
        temp_vendedor.set_qtdFilhos(stoi(linha));
        getline(arquivo, linha);
        temp_vendedor.set_estadoCivil(linha);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_endereco.cidade = linha;
        getline(arquivo, linha);
        temp_endereco.cep = linha;
        getline(arquivo, linha);
        temp_endereco.bairro = linha;
        getline(arquivo, linha);
        temp_endereco.rua = linha;
        getline(arquivo, linha);
        temp_endereco.numero = stoi(linha);

        temp_vendedor.set_enderecoPessoal(temp_endereco);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_data.ano = stoi(linha);
        getline(arquivo, linha);
        temp_data.mes = stoi(linha);
        getline(arquivo, linha);
        temp_data.dia = stoi(linha);

        temp_vendedor.set_dataNascimento(temp_data);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_vendedor.set_matricula(linha);
        getline(arquivo, linha);
        temp_vendedor.set_salario(linha);
        getline(arquivo, linha);
        temp_vendedor.set_tipoVendedor(linha[0]); // Primeiro char da string linha.
        getline(arquivo, linha);
        temp_vendedor.calcularSalario(stoi(linha));
        
        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_data.ano = stoi(linha);
        getline(arquivo, linha);
        temp_data.mes = stoi(linha);
        getline(arquivo, linha);
        temp_data.dia = stoi(linha);

        temp_vendedor.set_ingressoEmpresa(temp_data);

        this->vendedores.push_back(temp_vendedor);
    }
    arquivo.close();
}
void Empresa::carregarGerente()
{
    /*
    Lê o arquivo “gerente.txt” e carrega todos os dados desse
    arquivo no vector gerentes.
    */
    Gerente temp_gerente;
    Endereco temp_endereco;
    Data temp_data;

    fstream arquivo;
    arquivo.open("arquivos para leitura/gerente.txt", ios::in);
    string linha;
    while(getline(arquivo, linha)) // Ignora linha 1.
    {
        getline(arquivo, linha); // Ignora linha 2.
        getline(arquivo, linha); // Ignora linha 3.

        getline(arquivo, linha);
        temp_gerente.set_nome(linha);
        getline(arquivo, linha);
        temp_gerente.set_cpf(linha);
        getline(arquivo, linha);
        temp_gerente.set_qtdFilhos(stoi(linha));
        getline(arquivo, linha);
        temp_gerente.set_estadoCivil(linha);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_endereco.cidade = linha;
        getline(arquivo, linha);
        temp_endereco.cep = linha;
        getline(arquivo, linha);
        temp_endereco.bairro = linha;
        getline(arquivo, linha);
        temp_endereco.rua = linha;
        getline(arquivo, linha);
        temp_endereco.numero = stoi(linha);

        temp_gerente.set_enderecoPessoal(temp_endereco);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_data.ano = stoi(linha);
        getline(arquivo, linha);
        temp_data.mes = stoi(linha);
        getline(arquivo, linha);
        temp_data.dia = stoi(linha);

        temp_gerente.set_dataNascimento(temp_data);

        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_gerente.set_matricula(linha);
        getline(arquivo, linha);
        temp_gerente.set_salario(linha);
        getline(arquivo, linha);
        temp_gerente.set_participacaoLucros(stof(linha)); // Primeiro char da string linha.
        getline(arquivo, linha);
        temp_gerente.calcularSalario(stoi(linha));
        
        getline(arquivo, linha); // Ignora linha.

        getline(arquivo, linha);
        temp_data.ano = stoi(linha);
        getline(arquivo, linha);
        temp_data.mes = stoi(linha);
        getline(arquivo, linha);
        temp_data.dia = stoi(linha);

        temp_gerente.set_ingressoEmpresa(temp_data);

        this->gerentes.push_back(temp_gerente);
    }
    arquivo.close();
}
void Empresa::carregaDono()
{
    /*
    Lê o arquivo “dono.txt” e carrega todos os dados desse
    arquivo em dono.
    */
   
    Endereco temp_endereco;
    Data temp_data;

    fstream arquivo;
    arquivo.open("arquivos para leitura/dono.txt", ios::in);
    string linha;

    getline(arquivo, linha); // Ignora linha 2.
    getline(arquivo, linha); // Ignora linha 3.

    getline(arquivo, linha);
    dono.set_nome(linha);
    getline(arquivo, linha);
    dono.set_cpf(linha);
    getline(arquivo, linha);
    dono.set_qtdFilhos(stoi(linha));
    getline(arquivo, linha);
    dono.set_estadoCivil(linha);

    getline(arquivo, linha);
    temp_endereco.cidade = linha;
    getline(arquivo, linha);
    temp_endereco.cep = linha;
    getline(arquivo, linha);
    temp_endereco.bairro = linha;
    getline(arquivo, linha);
    temp_endereco.rua = linha;
    getline(arquivo, linha);
    temp_endereco.numero = stoi(linha);

    dono.set_enderecoPessoal(temp_endereco);

    getline(arquivo, linha);
    temp_data.ano = stoi(linha);
    getline(arquivo, linha);
    temp_data.mes = stoi(linha);
    getline(arquivo, linha);
    temp_data.dia = stoi(linha);

    dono.set_dataNascimento(temp_data);
   
    arquivo.close(); // Fecha o arquivo sem ler a ultima linha, ou seja, ignorando-a.
}
void Empresa::imprimeAsgs()
{
    int contador = 0;
    // Imprime todas os atributos de todos os asgs;
    for(auto i : this->asgs)
    {
        cout << "##############################################\n";
        cout << "ASG N°: ";
        cout << contador << endl;
        cout << "##### DADOS PESSOAIS #####\n";
        cout << i.get_nome() << endl;
        cout << i.get_cpf() << endl;
        cout << i.get_qtdFilhos() << endl;
        cout << i.get_estadoCivil() << endl;
        cout << "***** Endereço (cidade, cep, bairro, rua e numero) ****\n";
        cout << i.get_enderecoPessoal().cidade << endl;
        cout << i.get_enderecoPessoal().cep << endl;
        cout << i.get_enderecoPessoal().bairro << endl;
        cout << i.get_enderecoPessoal().rua << endl;
        cout << i.get_enderecoPessoal().numero << endl;
        cout << "***** Data de nascimento (ano, mes, dia) ****\n";
        cout << i.get_dataNascimento().ano << endl;
        cout << i.get_dataNascimento().mes << endl;
        cout << i.get_dataNascimento().dia << endl;
        cout << "##### DADOS FUNCIONAIS #####\n";
        cout << i.get_matricula() << endl;
        cout << i.get_salario() << endl;
        cout << i.get_adicionalInsalubridade() << endl;
        // cout << i.get_falta() << endl; // Tenho que adicionar este membro? qnt_faltas?
        cout << "***** Data de ingresso (ano, mes, dia) ****\n";
        cout << i.get_ingressoEmpresa().ano << endl;
        cout << i.get_ingressoEmpresa().mes << endl;
        cout << i.get_ingressoEmpresa().dia << endl;

        contador++;
    }
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
void Empresa::calculaTodoOsSalarios()
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