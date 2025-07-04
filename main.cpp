#include <iostream>
#include <vector>
#include <iomanip>
#include "algoritmos_ordenação.h"
#include "gerador_vetores.h"

int main() {
    int n, escolha;

    std::cout << "Informe o tamanho do vetor: ";
    std::cin >> n;

    std::cout << "Escolha o tipo de vetor:\n";
    std::cout << "1 - Aleatório\n";
    std::cout << "2 - Quase ordenado\n";
    std::cout << "3 - Inversamente ordenado\n";
    std::cout << "Sua escolha: ";
    std::cin >> escolha;

    std::vector<int> base;

    switch (escolha) {
        case 1:
            base = gerar_vetor_aleatorio(n);
            break;
        case 2:
            base = gerar_vetor_quase_ordenado(n);
            break;
        case 3:
            base = gerar_vetor_inversamente_ordenado(n);
            break;
        default:
            std::cerr << "Escolha inválida!\n";
            return 1;
    }

    std::vector<int> v_bubble    = base;
    std::vector<int> v_selection = base;
    std::vector<int> v_insertion = base;
    std::vector<int> v_quick     = base;
    std::vector<int> v_merge     = base;

    ResultadoOrdenacao r_bubble    = bubble_sort(v_bubble);
    ResultadoOrdenacao r_selection = selection_sort(v_selection);
    ResultadoOrdenacao r_insertion = insertion_sort(v_insertion);
    ResultadoOrdenacao r_quick     = quick_sort(v_quick);
    ResultadoOrdenacao r_merge     = merge_sort(v_merge);

    std::cout << "\nResultados para n = " << n << "\n";
    std::cout << std::left << std::setw(15) << "Algoritmo"
              << std::setw(12) << "Trocas"
              << std::setw(15) << "Comparações"
              << "Tempo (ms)" << "\n";

    std::cout << std::string(50, '-') << "\n";

    std::cout << std::left << std::setw(15) << "Bubble Sort"
              << std::setw(12) << r_bubble.trocas
              << std::setw(15) << r_bubble.comparacoes
              << r_bubble.tempo_ms << "\n";

    std::cout << std::left << std::setw(15) << "Selection Sort"
              << std::setw(12) << r_selection.trocas
              << std::setw(15) << r_selection.comparacoes
              << r_selection.tempo_ms << "\n";

    std::cout << std::left << std::setw(15) << "Insertion Sort"
              << std::setw(12) << r_insertion.trocas
              << std::setw(15) << r_insertion.comparacoes
              << r_insertion.tempo_ms << "\n";

    std::cout << std::left << std::setw(15) << "Quick Sort"
              << std::setw(12) << r_quick.trocas
              << std::setw(15) << r_quick.comparacoes
              << r_quick.tempo_ms << "\n";

    std::cout << std::left << std::setw(15) << "Merge Sort"
              << std::setw(12) << r_merge.trocas
              << std::setw(15) << r_merge.comparacoes
              << r_merge.tempo_ms << "\n";

    return 0;
}
