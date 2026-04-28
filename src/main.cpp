#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

// Estrutura do nó da lista encadeada simples.
struct No {
    int valor;
    No* proximo;
};

// Insere um valor no início da lista.
void inserirNoInicio(No*& cabeca, int valor) {
    No* novoNo = new No{valor, cabeca};
    cabeca = novoNo;
}

// Insere um valor ao final da lista.
void inserirNoFinal(No*& cabeca, int valor) {
    No* novoNo = new No{valor, nullptr};

    if (cabeca == nullptr) {
        cabeca = novoNo;
        return;
    }

    No* atual = cabeca;
    while (atual->proximo != nullptr) {
        atual = atual->proximo;
    }
    atual->proximo = novoNo;
}

// Remove um valor da lista (primeira ocorrência).
void removerValor(No*& cabeca, int valor) {
    if (cabeca == nullptr) return;

    if (cabeca->valor == valor) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
        return;
    }

    No* atual = cabeca;
    while (atual->proximo != nullptr && atual->proximo->valor != valor) {
        atual = atual->proximo;
    }

    if (atual->proximo != nullptr) {
        No* temp = atual->proximo;
        atual->proximo = temp->proximo;
        delete temp;
    }
}

// Busca um valor na lista.
bool buscarValor(No* cabeca, int valor) {
    while (cabeca != nullptr) {
        if (cabeca->valor == valor) return true;
        cabeca = cabeca->proximo;
    }
    return false;
}

// Retorna o tamanho da lista.
int tamanhoLista(No* cabeca) {
    int count = 0;
    while (cabeca != nullptr) {
        count++;
        cabeca = cabeca->proximo;
    }
    return count;
}

// Imprime todos os elementos da lista.
void imprimirLista(const No* cabeca) {
    const No* atual = cabeca;

    while (atual != nullptr) {
        cout << atual->valor;
        if (atual->proximo != nullptr) {
            cout << " -> ";
        }
        atual = atual->proximo;
    }
    cout << '\n';
}

// Divide a lista em duas metades usando ponteiros lento/rapido.
void dividirLista(No* origem, No*& frente, No*& tras) {
    if (origem == nullptr || origem->proximo == nullptr) {
        frente = origem;
        tras = nullptr;
        return;
    }

    No* lento = origem;
    No* rapido = origem->proximo;

    while (rapido != nullptr) {
        rapido = rapido->proximo;
        if (rapido != nullptr) {
            lento = lento->proximo;
            rapido = rapido->proximo;
        }
    }

    frente = origem;
    tras = lento->proximo;
    lento->proximo = nullptr;

    cout << "Divisao: ";
    imprimirLista(frente);
    cout << " | ";
    imprimirLista(tras);
}

// Intercala duas listas ordenadas e retorna a cabeca da lista resultante.
No* intercalarListasOrdenadas(No* a, No* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    No* resultado = nullptr;

    if (a->valor <= b->valor) {
        resultado = a;
        resultado->proximo = intercalarListasOrdenadas(a->proximo, b);
    } else {
        resultado = b;
        resultado->proximo = intercalarListasOrdenadas(a, b->proximo);
    }

    return resultado;
}

// Ordena a lista encadeada com Merge Sort (ordem crescente).
void mergeSortLista(No*& cabeca) {
    if (cabeca == nullptr || cabeca->proximo == nullptr) {
        return;
    }

    No* frente = nullptr;
    No* tras = nullptr;

    dividirLista(cabeca, frente, tras);

    mergeSortLista(frente);
    mergeSortLista(tras);

    cabeca = intercalarListasOrdenadas(frente, tras);

    cout << "Merge: ";
    imprimirLista(cabeca);
}

// Libera toda a memória alocada para a lista.
void liberarLista(No*& cabeca) {
    while (cabeca != nullptr) {
        No* temporario = cabeca;
        cabeca = cabeca->proximo;
        delete temporario;
    }
}

// Carrega dados de um arquivo para a lista.
void carregarDeArquivo(No*& lista, const string& nomeArquivo) {
    ifstream file(nomeArquivo);
    int valor;
    while (file >> valor) {
        inserirNoFinal(lista, valor);
    }
}

// Executa o teste automatico para um arquivo/caso e mede o tempo do Merge Sort.
void executarTeste(const string& nomeCaso, const string& nomeArquivo) {
    No* lista = nullptr;
    carregarDeArquivo(lista, nomeArquivo);

    cout << "\n=== " << nomeCaso << " (" << nomeArquivo << ") ===\n";
    cout << "Lista original: ";
    imprimirLista(lista);
    cout << "Tamanho da lista: " << tamanhoLista(lista) << endl;

    auto inicio = chrono::high_resolution_clock::now();
    mergeSortLista(lista);
    auto fim = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> duracao = fim - inicio;

    cout << "Lista ordenada: ";
    imprimirLista(lista);
    cout << "Tempo de execucao do Merge Sort: " << duracao.count() << " microsegundos\n";

    liberarLista(lista);
}

// Menu de teste automatico com os 3 casos.
void menuTeste() {
    cout << "\n   MODO TESTE AUTOMATICO  \n";
    executarTeste("Melhor Caso",    "melhor_caso_10.txt");
    executarTeste("Pior Caso",      "pior_caso_10.txt");
    executarTeste("Quase Ordenado", "quase_ordenado_10.txt");
}

// Menu de insercao e operacoes manuais na lista.
void menuManual() {
    No* lista = nullptr;
    int opcao;

    do {
        cout << "\n   MODO MANUAL   \n";
        cout << "1. Inserir valor\n";
        cout << "2. Imprimir lista\n";
        cout << "3. Ordenar lista (Merge Sort)\n";
        cout << "4. Buscar valor\n";
        cout << "5. Remover valor\n";
        cout << "0. Voltar ao menu principal\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
                int valor, posicao;
                cout << "Digite o valor a inserir: ";
                cin >> valor;
                cout << "Inserir no (1) inicio ou (2) final? ";
                cin >> posicao;
                if (posicao == 1) {
                    inserirNoInicio(lista, valor);
                    cout << "Valor inserido no inicio.\n";
                } else if (posicao == 2) {
                    inserirNoFinal(lista, valor);
                    cout << "Valor inserido no final.\n";
                } else {
                    cout << "Opcao invalida.\n";
                }
                break;
            }
            case 2: {
                cout << "Lista atual: ";
                imprimirLista(lista);
                cout << "Tamanho: " << tamanhoLista(lista) << endl;
                break;
            }
            case 3: {
                auto inicio = chrono::high_resolution_clock::now();
                mergeSortLista(lista);
                auto fim = chrono::high_resolution_clock::now();
                chrono::duration<double, micro> duracao = fim - inicio;

                cout << "Lista ordenada: ";
                imprimirLista(lista);
                cout << "Tempo de execucao do Merge Sort: " << duracao.count() << " microsegundos\n";
                break;
            }
            case 4: {
                int valor;
                cout << "Digite o valor a buscar: ";
                cin >> valor;
                cout << (buscarValor(lista, valor) ? "Encontrado" : "Nao encontrado") << endl;
                break;
            }
            case 5: {
                int valor;
                cout << "Digite o valor a remover: ";
                cin >> valor;
                removerValor(lista, valor);
                cout << "Lista apos remocao: ";
                imprimirLista(lista);
                break;
            }
            case 0:
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    liberarLista(lista);
}

int main() {
    int opcao;

    do {
        cout << "\n      MENU PRINCIPAL \n";
        cout << "1. Teste automatico (melhor, pior e quase ordenado)\n";
        cout << "2. Inserir elementos manualmente\n";
        cout << "0. Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                menuTeste();
                break;
            case 2:
                menuManual();
                break;
            case 0:
                cout << "Encerrando programa.\n";
                break;
            default:
                cout << "Opcao invalida.\n";
        }
    } while (opcao != 0);

    return 0;
}
