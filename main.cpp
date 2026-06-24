#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

// Struct para guardar as informacoes de cada departamento
struct Departamento {
    string codigo;
    string nome;
    string palavrasChave[5];
};

// Funcao que abre o arquivo txt e joga os dados dentro do vector
void carregarArquivo(vector<Departamento>& departamentos, string nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    // Se o arquivo nao abrir, mostra erro e sai da funcao
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    Departamento depto;

    // Enquanto conseguir ler uma linha completa do arquivo, salva no vector
    while (arquivo >> depto.codigo >> depto.nome
                   >> depto.palavrasChave[0]
                   >> depto.palavrasChave[1]
                   >> depto.palavrasChave[2]
                   >> depto.palavrasChave[3]
                   >> depto.palavrasChave[4]) {
        departamentos.push_back(depto);
    }

    // Fecha o arquivo depois de terminar a leitura
    arquivo.close();

    cout << "Arquivo importado com sucesso!" << endl;
    cout << "Total de departamentos carregados: " << departamentos.size() << endl;
}

// Funcao para pesquisar qual departamento tem uma palavra-chave digitada
void pesquisarPorPalavraChave(vector<Departamento>& departamentos) {
    string palavra;
    bool encontrado = false;

    cout << "\nDigite a palavra-chave para pesquisar: ";
    cin >> palavra;

    // Percorre todos os departamentos cadastrados
    for (int i = 0; i < departamentos.size(); i++) {
        // Percorre as 5 palavras-chave de cada departamento
        for (int j = 0; j < 5; j++) {
            if (departamentos[i].palavrasChave[j] == palavra) {
                cout << "\nPalavra-chave encontrada!" << endl;
                cout << "Departamento: " << departamentos[i].nome << endl;
                encontrado = true;
            }
        }
    }

    // Se nao achou em nenhum departamento, avisa o usuario
    if (!encontrado) {
        cout << "\nNenhum departamento encontrado para essa palavra-chave." << endl;
    }
}

// Funcao para pesquisar os dados usando o nome do departamento
void pesquisarPorDepartamento(vector<Departamento>& departamentos) {
    string nomeDepartamento;
    bool encontrado = false;

    cout << "\nDigite o nome do departamento: ";
    cin >> nomeDepartamento;

    // Percorre o vector procurando um departamento com o nome digitado
    for (int i = 0; i < departamentos.size(); i++) {
        if (departamentos[i].nome == nomeDepartamento) {
            cout << "\nDepartamento encontrado!" << endl;
            cout << "Codigo identificador: " << departamentos[i].codigo << endl;

            cout << "Palavras-chave: ";
            // Mostra todas as palavras-chave do departamento encontrado
            for (int j = 0; j < 5; j++) {
                cout << departamentos[i].palavrasChave[j] << " ";
            }

            cout << endl;
            encontrado = true;
        }
    }

    // Caso o departamento nao exista no arquivo
    if (!encontrado) {
        cout << "\nDepartamento nao encontrado." << endl;
    }
}

// Funcao que mostra todos os departamentos carregados do arquivo
void exibirTodos(vector<Departamento>& departamentos) {
    cout << "\n=== Departamentos cadastrados ===" << endl;

    // Percorre todos os departamentos e mostra as informacoes de cada um
    for (int i = 0; i < departamentos.size(); i++) {
        cout << "\nCodigo: " << departamentos[i].codigo << endl;
        cout << "Departamento: " << departamentos[i].nome << endl;
        cout << "Palavras-chave: ";

        // Mostra as 5 palavras-chave do departamento
        for (int j = 0; j < 5; j++) {
            cout << departamentos[i].palavrasChave[j] << " ";
        }

        cout << endl;
    }
}

int main() {
    // Configura o console do Windows para aceitar acentos corretamente
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // Vector onde vao ficar guardados os departamentos lidos do arquivo
    vector<Departamento> departamentos;
    int opcao;
    string nomeArquivo;

    // O usuario escolhe qual arquivo vai ser lido
    cout << "Digite o nome do arquivo: ";
    cin >> nomeArquivo;

    carregarArquivo(departamentos, nomeArquivo);

    // Se nao carregou nada, nao tem como continuar o programa
    if (departamentos.empty()) {
        cout << "\nNenhum dado foi carregado. Verifique o arquivo." << endl;
        return 0;
    }

    // Menu principal, repete ate o usuario escolher sair
    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1 - Pesquisar por palavra-chave" << endl;
        cout << "2 - Pesquisar por departamento" << endl;
        cout << "3 - Exibir todos os departamentos" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Escolhe qual funcao chamar de acordo com a opcao digitada
        switch (opcao) {
            case 1:
                pesquisarPorPalavraChave(departamentos);
                break;

            case 2:
                pesquisarPorDepartamento(departamentos);
                break;

            case 3:
                exibirTodos(departamentos);
                break;

            case 0:
                cout << "\nEncerrando o programa..." << endl;
                break;

            default:
                cout << "\nOpcao invalida. Tente novamente." << endl;
        }

    } while (opcao != 0);

    return 0;
}
