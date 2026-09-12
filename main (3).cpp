#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Jogador {
    string nome;
    int pontuacao;
};

void insertionSort(vector<Jogador>& jogadores) {
    for (int i = 1; i < jogadores.size(); i++) {
        Jogador atual = jogadores[i];
        int j = i - 1;


        while (j >= 0 &&
               jogadores[j].pontuacao < atual.pontuacao) {
            jogadores[j + 1] = jogadores[j];
            j--;
        }

        jogadores[j + 1] = atual;
    }
}

int main() {
    int N;

    cout << "Digite a quantidade de jogadores: ";
    cin >> N;

    vector<Jogador> jogadores(N);

    for (int i = 0; i < N; i++) {
        cout << "\nDigite o nome do jogador " << i + 1 << ": ";
        cin >> jogadores[i].nome;

        cout << "Digite a pontuacao: ";
        cin >> jogadores[i].pontuacao;
    }

    insertionSort(jogadores);

    cout << "\n===== RANKING FINAL =====\n";

    for (int i = 0; i < N; i++) {
        cout << i + 1 << "o lugar - "
             << jogadores[i].nome
             << " - "
             << jogadores[i].pontuacao
             << " pontos\n";
    }

    return 0;
}