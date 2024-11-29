#include "../inc/core.hpp"

int main()
{
    // Создаем экземпляры продуктов
    Product* product1 = new Product("Product1", 1, 10.0, 100.0, 30);
    PerishableProduct* perishable1 = new PerishableProduct("Perishable1", 2, 5.0, 50.0, 10, time(nullptr) + 5 * 24 * 60 * 60);
    ElectronicProduct* electronic1 = new ElectronicProduct("Electronic1", 3, 2.0, 200.0, 15, 24, 100);
    BuildingMaterial* material1 = new BuildingMaterial("Material1", 4, 20.0, 300.0, 60, true);

    // Создаем склад и добавляем продукты
    Warehouse warehouse;
    warehouse.add_prod(product1);
    warehouse.add_prod(perishable1);
    warehouse.add_prod(electronic1);
    warehouse.add_prod(material1);

    // Отображаем инвентарь склада
    std::cout << "Initial Inventory:" << std::endl;
    warehouse.display_inventory();

    // Рассчитываем общую стоимость хранения
    double total_fee = warehouse.calculate_total_storage_fee();
    std::cout << "Total Storage Fee: " << total_fee << std::endl;

    // Находим продукты по категориям
    std::vector<Product*> perishables = warehouse.find_prods_by_category("PerishableProduct");
    std::cout << "Perishable Products:" << std::endl;
    for (Product* prod : perishables) {
        prod->display_info();
    }

    // Получаем продукты, срок годности которых истекает в ближайшие 7 дней
    std::vector<PerishableProduct*> expiring_products = warehouse.get_expiring_products(7);
    std::cout << "Expiring Products in 7 days:" << std::endl;
    for (PerishableProduct* prod : expiring_products) {
        prod->display_info();
    }

    // Удаляем продукт по ID
    warehouse.delete_prod(2);
    std::cout << "Inventory after deleting product with ID 1:" << std::endl;
    warehouse.display_inventory();

    // Используем оператор вывода для отображения инвентаря
    std::cout << warehouse;

    // Освобождаем память
    delete product1;
    delete perishable1;
    delete electronic1;
    delete material1;

    return 0;
}