#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <limits>

using namespace std;

struct Cliente {
    string nome;
    string pedido;
};

void desafio03() {
    queue<Cliente> fila;
    int opcao;

    do {
        cout << "\n=== DESAFIO 03 - FILA DO CAFE ===\n";
        cout << "1. Entrar na fila\n2. Atender primeiro cliente\n3. Listar fila\n0. Voltar\nOpcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcao == 1) {
            Cliente cliente;
            cout << "Nome: ";
            getline(cin, cliente.nome);
            cout << "Pedido: ";
            getline(cin, cliente.pedido);
            fila.push(cliente);
            cout << "Cliente entrou na fila.\n";
        } else if (opcao == 2) {
            if (fila.empty()) {
                cout << "Nao ha clientes na fila. Atendimento impossivel.\n";
            } else {
                Cliente cliente = fila.front();
                fila.pop();
                cout << "Atendendo: " << cliente.nome
                     << " | Pedido: " << cliente.pedido << "\n";
            }
        } else if (opcao == 3) {
            if (fila.empty()) {
                cout << "A fila esta vazia.\n";
            } else {
                queue<Cliente> copia = fila;
                int posicao = 1;
                while (!copia.empty()) {
                    Cliente cliente = copia.front();
                    copia.pop();
                    cout << posicao++ << ". " << cliente.nome
                         << " | Pedido: " << cliente.pedido << "\n";
                }
            }
        }
    } while (opcao != 0);
}

void desafio04() {
    stack<string> historico;
    int opcao;

    do {
        cout << "\n=== DESAFIO 04 - HISTORICO DE COMANDOS ===\n";
        cout << "1. Inserir acao\n2. Desfazer ultima acao\n3. Visualizar historico\n0. Voltar\nOpcao: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcao == 1) {
            string acao;
            cout << "Digite a acao: ";
            getline(cin, acao);
            historico.push(acao);
            cout << "Acao registrada.\n";
        } else if (opcao == 2) {
            if (historico.empty()) {
                cout << "Nao ha acoes para desfazer.\n";
            } else {
                cout << "Desfeita: " << historico.top() << "\n";
                historico.pop();
            }
        } else if (opcao == 3) {
            if (historico.empty()) {
                cout << "O historico esta vazio.\n";
            } else {
                stack<string> copia = historico;
                int posicao = 1;
                cout << "Acoes da mais recente para a mais antiga:\n";
                while (!copia.empty()) {
                    cout << posicao++ << ". " << copia.top() << "\n";
                    copia.pop();
                }
            }
        }
    } while (opcao != 0);
}

bool fecha(char abertura, char fechamento) {
    return (abertura == '(' && fechamento == ')') ||
           (abertura == '[' && fechamento == ']') ||
           (abertura == '{' && fechamento == '}');
}

bool balanceada(const string& expressao) {
    stack<char> pilha;

    for (char caractere : expressao) {
        if (caractere == '(' || caractere == '[' || caractere == '{') {
            pilha.push(caractere);
        } else if (caractere == ')' || caractere == ']' || caractere == '}') {
            if (pilha.empty() || !fecha(pilha.top(), caractere)) {
                return false;
            }
            pilha.pop();
        }
    }

    return pilha.empty();
}

void desafio05() {
    string expressao;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\n=== DESAFIO 05 - PARENTESES SOB CONTROLE ===\n";
    cout << "Digite uma expressao: ";
    getline(cin, expressao);

    cout << (balanceada(expressao) ? "VALIDA\n" : "INVALIDA\n");
}

int main() {
    int desafio;

    do {
        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "3. Fila do Cafe\n4. Historico de Comandos\n5. Parenteses Sob Controle\n0. Sair\nEscolha: ";
        cin >> desafio;

        switch (desafio) {
            case 3: desafio03(); break;
            case 4: desafio04(); break;
            case 5: desafio05(); break;
            case 0: cout << "Programa encerrado.\n"; break;
            default: cout << "Opcao invalida.\n";
        }
    } while (desafio != 0);

    return 0;
}
