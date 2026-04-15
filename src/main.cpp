#include <iostream>

using namespace std;

// Estrutura do nó da lista encadeada simples.
struct No {
    int valor;
    No* proximo;
};

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
}

// Intercala duas listas ordenadas e retorna a cabeca da lista resultante.
No* intercalarListasOrdenadas(No* a, No* b) {
    if (a == nullptr) {
        return b;
    }
    if (b == nullptr) {
        return a;
    }

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
}

// Libera toda a memória alocada para a lista.
void liberarLista(No*& cabeca) {
    while (cabeca != nullptr) {
        No* temporario = cabeca;
        cabeca = cabeca->proximo;
        delete temporario;
    }
}

int main() {
    No* lista = nullptr;

    int n;
    cout << "Digite a quantidade de valores a inserir (ex: 100, 1000, 10000, 100000): ";
    cin >> n;

    if (n <= 0) {
        cout << "Quantidade invalida.\n";
        return 1;
    }

    cout << "Digite " << n << " valores (inteiros), separados por espaco ou quebra de linha:\n";
    for (int i = 0; i < n; i++) {
        int valor;
        cin >> valor;
        inserirNoFinal(lista, valor);
    }

    // Para N muito grande (10000/100000), imprimir tudo fica inviavel.
    // Se quiser, comente as linhas abaixo.
    cout << "Lista original: ";
    imprimirLista(lista);

    mergeSortLista(lista);

    cout << "Lista ordenada: ";
    imprimirLista(lista);

    liberarLista(lista);
    return 0;
}