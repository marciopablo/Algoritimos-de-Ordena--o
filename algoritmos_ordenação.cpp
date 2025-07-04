#include "algoritmos_ordenação.h"
#include <chrono>
#include <algorithm>

// Bubble sort

ResultadoOrdenacao bubble_sort(std::vector<int>& lista) {
    int tam = lista.size();
    int trocas = 0;
    int comparacoes = 0;

    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            comparacoes++;
            if (lista[j] > lista[j + 1]) {
                std::swap(lista[j], lista[j + 1]);
                trocas++;
            }
        }
    }

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao = fim - inicio;

    return { trocas, comparacoes, duracao.count() };
}



// Seletion sort

ResultadoOrdenacao selection_sort(std::vector<int>& lista) {
    int tam = lista.size();
    int trocas = 0;
    int comparacoes = 0;

    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < tam - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < tam; j++) {
            comparacoes++; 
            if (lista[j] < lista[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(lista[i], lista[min_index]);
            trocas++;
        }
    }

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao = fim - inicio;

    return { trocas, comparacoes, duracao.count() };
}

// Insertion sort

ResultadoOrdenacao insertion_sort(std::vector<int>& lista) {
    int tam = lista.size();
    int trocas = 0;
    int comparacoes = 0;

    auto inicio = std::chrono::high_resolution_clock::now();

    for (int i = 1; i < tam; i++) {
        int chave = lista[i];
        int j = i - 1;

        while (j >= 0) {
            comparacoes++;
            if (lista[j] > chave) {
                lista[j + 1] = lista[j];
                trocas++;
                j--;
            } else {
                break; 
            }
        }

        lista[j + 1] = chave;
    }

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao = fim - inicio;

    return { trocas, comparacoes, duracao.count() };
}




// Quick sort

int particionamento_quick(std::vector<int>& lista, int esquerda, int direita, int& comparacoes, int& trocas) {
    int pivo = lista[direita];
    int i = esquerda;
    int j = direita - 1;

    while (j >= i) {
        while (i <= j && lista[i] < pivo) {
            comparacoes++;
            i++;
        }
        while (i <= j && lista[j] > pivo) {
            comparacoes++;
            j--;
        }

        if (j >= i) {
            std::swap(lista[i], lista[j]);
            trocas++;
            i++;
            j--;
        }
    }

    std::swap(lista[i], lista[direita]);
    trocas++;
    return i;
}

void quick_sort_recursivo(std::vector<int>& lista, int esquerda, int direita, int& comparacoes, int& trocas) {
    if (esquerda < direita) {
        int indice_pivo = particionamento_quick(lista, esquerda, direita, comparacoes, trocas);
        quick_sort_recursivo(lista, esquerda, indice_pivo - 1, comparacoes, trocas);
        quick_sort_recursivo(lista, indice_pivo + 1, direita, comparacoes, trocas);
    }
}

ResultadoOrdenacao quick_sort(std::vector<int>& lista) {
    int comparacoes = 0;
    int trocas = 0;

    auto inicio = std::chrono::high_resolution_clock::now();

    quick_sort_recursivo(lista, 0, lista.size() - 1, comparacoes, trocas);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao = fim - inicio;

    return { trocas, comparacoes, duracao.count() };
}






// Merge sort

void intercalar_merge(std::vector<int>& lista, int esquerda, int meio, int direita, int& comparacoes, int& trocas) {
    int i = esquerda;
    int j = meio + 1;

    std::vector<int> temp;
    temp.reserve(direita - esquerda + 1);

    while (i <= meio && j <= direita) {
        comparacoes++;
        if (lista[i] <= lista[j]) {
            temp.push_back(lista[i]);
            i++;
        } else {
            temp.push_back(lista[j]);
            j++;
        }
        trocas++; 
    }

    while (i <= meio) {
        temp.push_back(lista[i]);
        i++;
        trocas++;
    }

    while (j <= direita) {
        temp.push_back(lista[j]);
        j++;
        trocas++;
    }

    for (int k = 0; k < temp.size(); ++k) {
        lista[esquerda + k] = temp[k];
        trocas++; 
    }
}

void merge_sort_recursivo(std::vector<int>& lista, int esquerda, int direita, int& comparacoes, int& trocas) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        merge_sort_recursivo(lista, esquerda, meio, comparacoes, trocas);
        merge_sort_recursivo(lista, meio + 1, direita, comparacoes, trocas);
        intercalar_merge(lista, esquerda, meio, direita, comparacoes, trocas);
    }
}

ResultadoOrdenacao merge_sort(std::vector<int>& lista) {
    int comparacoes = 0;
    int trocas = 0;

    auto inicio = std::chrono::high_resolution_clock::now();

    merge_sort_recursivo(lista, 0, lista.size() - 1, comparacoes, trocas);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duracao = fim - inicio;

    return { trocas, comparacoes, duracao.count() };
}