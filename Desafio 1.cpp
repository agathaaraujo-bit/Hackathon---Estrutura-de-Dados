#include <iostream>
using namespace std;

void mostrarVetor(int vetor[], int tamanho){
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int insertionSort(int vetor[], int tamanho) {
    int comparacoes = 0;
    
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;
        
        while (j >= 0) {
            comparacoes++;
            
            if (vetor[j] > chave) {
                vetor[j + 1] = vetor[j];
                j--;
            } else {
                break;
            }
        }
        
        vetor[j + 1] = chave;
    }
    
    return comparacoes;
}
int main() {
    int n;
    
    cout << "digite a quantidade de competidores: ";
    cin >> n;
    
    int tempos[n];
    
    for (int i = 0; i < n; i++) {
        cout << "digite o tempo do competidor: " << i + 1 << ": ";
        cin >> tempos[i];
    }
    cout << "\nVetor antes da ordenação: ";
    mostrarVetor(tempos, n);
    
    int comparacoes = insertionSort(tempos, n);
    
    cout << "Vetor depois da ordenação: ";
    mostrarVetor(tempos, n);
    cout << "quantidade de comparacoes: " << comparacoes << endl;
    

}
