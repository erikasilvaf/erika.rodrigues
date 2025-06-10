#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct para representar um paciente
struct Paciente {
    string nome;
    int prioridade; // 1 = urgente, 5 = não urgente
};

// Função para imprimir os pacientes
void imprimirPacientes(const vector<Paciente>& pacientes) {
    for (const auto& p : pacientes) {
        cout << p.nome << " (Prioridade: " << p.prioridade << ")\n";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(vector<Paciente>& pacientes) {
    int n = pacientes.size();
    for (int i = 0; i < n - 1; i++) {
        bool trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (pacientes[j].prioridade > pacientes[j + 1].prioridade) {
                swap(pacientes[j], pacientes[j + 1]);
                trocou = true;
            }
        }
        if (!trocou) break; // Otimização: já está ordenado
    }
}

// Selection Sort
void selectionSort(vector<Paciente>& pacientes) {
    int n = pacientes.size();
    for (int i = 0; i < n - 1; i++) {
        int indiceMenor = i;
        for (int j = i + 1; j < n; j++) {
            if (pacientes[j].prioridade < pacientes[indiceMenor].prioridade) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            swap(pacientes[i], pacientes[indiceMenor]);
        }
    }
}

int main() {
    // Lista original
    vector<Paciente> lista = {
        {"Ana", 5}, {"Pedro", 2}, {"Carla", 4}, {"Lucas", 1},
        {"Mariana", 3}, {"Fernanda", 5}, {"Rafael", 2}, {"Beatriz", 4},
        {"Guilherme", 1}, {"Sofia", 3}
    };

    // Cópias para cada algoritmo
    vector<Paciente> listaBubble = lista;
    vector<Paciente> listaSelection = lista;

    // Ordenação
    cout << "Original:\n";
    imprimirPacientes(lista);

    bubbleSort(listaBubble);
    cout << "Ordenado com Bubble Sort:\n";
    imprimirPacientes(listaBubble);

    selectionSort(listaSelection);
    cout << "Ordenado com Selection Sort:\n";
    imprimirPacientes(listaSelection);

    return 0;
}