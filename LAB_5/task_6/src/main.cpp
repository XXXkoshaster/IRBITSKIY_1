#include "../inc/core.hpp"

int main() {
    // Создание пустого вектора
    Vector vec1;
    std::cout << "Initial size: " << vec1.size() << ", capacity: " << vec1.capacity() << "\n";

    // Добавление элементов
    vec1.push_back(1.1);
    vec1.push_back(2.2);
    vec1.push_back(3.3);
    std::cout << "After push_back: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1.at(i) << " ";
    }
    std::cout << "\n";

    // Доступ к первому и последнему элементу
    std::cout << "Front: " << vec1.front() << ", Back: " << vec1.back() << "\n";

    // Изменение размера
    vec1.resize(5, 0.0); // Увеличиваем размер до 5, заполняем нулями
    std::cout << "After resize to 5: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1.at(i) << " ";
    }
    std::cout << "\n";

    // Вставка элемента
    vec1.insert(2, 9.9); // Вставляем 9.9 на позицию 2
    std::cout << "After insert at index 2: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1.at(i) << " ";
    }
    std::cout << "\n";

    // Удаление элемента
    vec1.erase(1); // Удаляем элемент на позиции 1
    std::cout << "After erase at index 1: ";
    for (size_t i = 0; i < vec1.size(); ++i) {
        std::cout << vec1.at(i) << " ";
    }
    std::cout << "\n";


    std::cout << "Capacity: " << vec1.capacity() << "\n";
    std::cout << "Size: " << vec1.size() << "\n";
    // Уменьшение до точного размера
    vec1.shrink_to_fit();
    std::cout << "After shrink_to_fit - Capacity: " << vec1.capacity() << "\n";

    // Использование итераторов
    std::cout << "Using iterators: ";
    for (auto it = vec1.begin(); it != vec1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // Сравнение векторов
    Vector vec2{1.1, 9.9, 3.3};
    if (vec1 == vec2) {
        std::cout << "vec1 and vec2 are equal\n";
    } else {
        std::cout << "vec1 and vec2 are not equal\n";
    }

    // Очистка
    vec1.clear();
    std::cout << "After clear: size = " << vec1.size() << ", capacity = " << vec1.capacity() << "\n";

    return 0;
}