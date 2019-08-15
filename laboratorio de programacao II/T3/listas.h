#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

struct agencia{
       int codigo_da_agencia;
       char* nome;
       char* endereco;
       char data[50];
       char* nome_gerente;
       struct agencia* ant;
       struct agencia* prox;
};
typedef struct agencia Agencia;

struct clientes{
    int cpf;
    char* nome;
    char* telefone;
    int codigo_agencia;
    struct clientes* ant;
    struct clientes* prox;
};
typedef struct clientes Clientes;

struct gerente{
    int cpf;
    char* nome;
    char* telefone;
    int codigo_agencia;
    struct gerente* ant;
    struct gerente* prox;
};
typedef struct gerente Gerente;

struct contas{
    int numero_conta;
    int cpf_cliente_conta;
    int codigo_agencia_conta;
    int dia;
    int mes;
    int ano;
    float saldo;
    float limite;
    float total;
    struct contas* ant;
    struct contas* prox;
};
typedef struct contas Contas;

struct transacoes{
    int codigo_transacao;
    int dia;
    int mes;
    int ano;
    int numero_conta_tran;
    int tipo_transacao; ///(verificar saldo, efetuar saque, efetuar transferência ou efetuar pagamento)
    int codigo_agencia_da_trans;
    float valor;
    struct transacoes* ant;
    struct transacoes* prox;
};
typedef struct transacoes Transacoes;

///criação
void Agencia_cria(Agencia** inicio);
void Clientes_cria(Clientes** inicio);
void Gerente_cria(Gerente** inicio);
void Contas_cria(Contas** inicio);
void Transacoes_cria(Transacoes** inicio);


///buscas
Agencia* Agencia_busca (Agencia* inicio, int v);
void Clientes_busca_imprime_cliente_allcontas(Clientes* inicio, int cpf_ver);
Clientes* Clientes_busca_AGespecifica(Clientes* inicio, int codigo_ag, int cpf_ver);
Clientes* Clientes_busca_existe(Clientes* inicio, int cpf_ver);
void Clientes_busca_imprime_cliente_allcontas(Clientes* inicio, int cpf_ver);
Gerente* Gerente_busca (Gerente* inicio, int cpf_ver);

///inserir
void Agencia_insere (Agencia** inicio, char* nome_novo, char* end_novo, char* gerent_novo, int codigo_AGnovo);
void Clientes_insere(Clientes** inicio, char* nome_novo, char* telefone_novo, int agencia_novo, int cpf_novo);
void Gerente_insere(Gerente** inicio, char* nome_novo, char* telefone_novo, int agencia_novo, int cpf_novo);
void Transacoes_insere(Transacoes** inicio, int codigo_transacao,int numero_conta_tran,int codigo_agencia_da_trans,float valor, int dia,int mes,int ano, int tipo);

///inserir no final
void Agencia_insere_final (Agencia** inicio, char* nome_novo, char* end_novo, char* gerent_novo, int codigo_AGnovo);

///retirar
void Agencia_retira (Agencia** inicio, int v);
void retira_todos_os_clientes_vinculado_agencia(Clientes** inicio, int v);
void retira_cliente_vinculado_agencia(Clientes** inicio, int agencia_ver, int cpf_ver);
void retira_gerente_da_agencia(Gerente** inicio, int v);
void retira_gerente_agencia(Gerente** inicio, int codigo_de_agencia);
void retira_todos_cliente(Clientes** inicio, int cpf_ver);
void retira_todas_transacoes_apartir_agencia(Transacoes** inicio,int v);
void retira_todas_contas_apartir_agencia(Contas** inicio,int v);
void retira_todas_contas(Contas** inicio, int cpf_ver);
void retira_todas_contas_apartir_clientes(Contas** inicio,int v);

///imprimir para frente
void Agencia_imprime(Agencia* inicio);
void Clientes_imprime(Clientes* inicio);
void Gerente_imprime(Gerente* inicio);
void imprime_clientes_de_uma_agencia(Clientes* inicio, int codigo_agencia_verf);
void imprime_transacoes_de_uma_agencia(Transacoes* inicio_TR, int codigo_agencia_exc);
void imprime_contas_de_uma_agencia(Contas* inicio_CO, int codigo_agencia_exc);
void imprime_conta_cliente_especifico_agencia_espcifica(Contas** inicio_CO,int cpf_ver,int codigo_agencia_ver);
void imprime_contas_de_um_cliente(Contas** inicio, int cpf_ver);

///imprimir para tras
void Agencia_imprime_para_tras(Agencia* inicio);

///apenas ler strings
char* le_frases();

///imprimir clientes de uma agência
void imprime_clientes_de_uma_agencia(Clientes* c, int codigo_agencia_verf);

///vazia°
int Agencia_vazia(Agencia* inicio);
int Clientes_vazia(Clientes* inicio);
int Gerente_vazia(Gerente* inicio);
#endif // LISTAS_H_INCLUDED
