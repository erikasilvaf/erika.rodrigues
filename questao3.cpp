#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Geração de vetor aleatório
vector<int> gerarVetorAleatorio(int tamanho, int min, int max) {
    vector<int> vetor;
    srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        vetor.push_back(rand() % (max - min + 1) + min);
    }
    return vetor;
}

// Bubble Sort
void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}

// QuickSort
int particionar(vector<int>& v, int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;
    for (int j = inicio; j < fim; j++) {
        if (v[j] < pivo) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[fim]);
    return i + 1;
}

void quickSort(vector<int>& v, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(v, inicio, fim);
        quickSort(v, inicio, p - 1);
        quickSort(v, p + 1, fim);
    }
}

// Função para imprimir vetor (opcional)
void imprimir(const vector<int>& v) {
    for (int num : v)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> dados = gerarVetorAleatorio(50, 1, 500);

    vector<int> bubble = dados;
    vector<int> quick = dados;

    // Bubble Sort com medição de tempo
    auto inicioBubble = high_resolution_clock::now();
    bubbleSort(bubble);
    auto fimBubble = high_resolution_clock::now();
    auto tempoBubble = duration_cast<microseconds>(fimBubble - inicioBubble).count();

    // QuickSort com medição de tempo
    auto inicioQuick = high_resolution_clock::now();
    quickSort(quick, 0, quick.size() - 1);
    auto fimQuick = high_resolution_clock::now();
    auto tempoQuick = duration_cast<microseconds>(fimQuick - inicioQuick).count();

    cout << "Tempo Bubble Sort: " << tempoBubble << " microssegundos\n";
    cout << "Tempo QuickSort: " << tempoQuick << " microssegundos\n";

    return 0;
}