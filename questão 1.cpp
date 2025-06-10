#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int buscaLinear(const vector<string>& livros, const string& titulo) {
    for (int i = 0; i < livros.size(); i++) {
        if (livros[i] == titulo) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(const vector<string>& livrosOrdenados, const string& titulo) {
    int esquerda = 0, direita = livrosOrdenados.size() - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (livrosOrdenados[meio] == titulo) {
            return meio;
        } else if (livrosOrdenados[meio] < titulo) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }

    return -1;
}

int main() {
    vector<string> livros = {
        "A Culpa é das Estrelas", "A Droga da Obediência", "A Estrada", "A Fera de Gaia", "A Menina que Roubava Livros",
        "A Montanha Mágica", "A Revolução dos Bichos", "A Sombra do Vento", "A Teia de Charlotte", "1984",
        "Admirável Mundo Novo", "Alice no País das Maravilhas", "O Alquimista", "Cem Anos de Solidão", "A Hora da Estrela",
        "A Metamorfose", "As Crônicas de Nárnia: O Leão, a Feiticeira e o Guarda-Roupa", "Assassinato no Expresso do Oriente",
        "Corte de Espinhos e Rosas", "Crepúsculo", "Dom Casmurro", "Duna", "Ensaio sobre a Cegueira", "Fahrenheit 451",
        "Frankenstein", "O Grande Gatsby", "Harry Potter e a Pedra Filosofal", "Jogos Vorazes",
        "Memórias Póstumas de Brás Cubas", "O Código Da Vinci", "O Cortiço", "O Guia do Mochileiro das Galáxias",
        "O Iluminado", "O Ladrão de Raios", "O Pequeno Príncipe", "O Poder do Hábito", "O Silmarillion",
        "O Sol é Para Todos", "O Senhor dos Anéis: A Sociedade do Anel", "Onde Vivem os Monstros",
        "Orgulho e Preconceito", "O Retrato de Dorian Gray", "Percy Jackson e o Ladrão de Raios",
        "Sapiens: Uma Breve História da Humanidade", "O Hobbit", "Um Estudo em Vermelho", "Vidas Secas"
    };

    string livroBuscado = "O Hobbit";

    // Busca Linear
    int indiceLinear = buscaLinear(livros, livroBuscado);
    cout << "Busca Linear - Índice: " << indiceLinear << endl;

    // Busca Binária (lista precisa estar ordenada)
    vector<string> livrosOrdenados = livros;
    sort(livrosOrdenados.begin(), livrosOrdenados.end());

    int indiceBinaria = buscaBinaria(livrosOrdenados, livroBuscado);
    cout << "Busca Binária - Índice na lista ordenada: " << indiceBinaria << endl;

    return 0;
}
