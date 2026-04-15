#include <iostream>
#include <fstream>  // Para manipular arquivos
#include <cstdlib>  // Para gerar números aleatórios
#include <ctime>    // Para seed do rand()

// Função para gerar arrays aleatórios
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

// Função para gerar arrays ordenados (melhor caso)
void generateAscendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
}

// Função para gerar arrays em ordem decrescente (pior caso)
void generateDescendingArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

// Função para salvar um array em um arquivo
void saveArrayToFile(const std::string& filename, int arr[], int n) {
    std::ofstream outfile(filename);  // Abre o arquivo para escrita
    if (!outfile.is_open()) {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        return;
    }
    
    for (int i = 0; i < n; i++) {
        outfile << arr[i] << " ";  // Escreve os elementos do array no arquivo
    }
    outfile.close();  // Fecha o arquivo
}

int main() {
    srand(time(0));  // Seed para números aleatórios

    // Tamanhos dos arrays
    int sizes[] = {100, 1000, 10000, 100000};

    // Para cada tamanho de array
    for (int s = 0; s < 4; s++) {
        int n = sizes[s];  // Tamanho do array atual
        int* arr = new int[n];  // Aloca dinamicamente o array

        // Gerar e salvar o melhor caso (array ordenado)
        generateAscendingArray(arr, n);
        saveArrayToFile("melhor_caso_" + std::to_string(n) + ".txt", arr, n);

        // Gerar e salvar o caso médio (array aleatório)
        generateRandomArray(arr, n);
        saveArrayToFile("medio_caso_" + std::to_string(n) + ".txt", arr, n);

        // Gerar e salvar o pior caso (array em ordem decrescente)
        generateDescendingArray(arr, n);
        saveArrayToFile("pior_caso_" + std::to_string(n) + ".txt", arr, n);

        delete[] arr;  // Libera a memória do array
    }

    std::cout << "Arrays gerados e salvos nos arquivos!" << std::endl;

    return 0;
}
