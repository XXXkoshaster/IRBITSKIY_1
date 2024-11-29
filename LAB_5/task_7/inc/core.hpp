#pragma once

#include <iostream>

class Product
{
protected:
    std::string _name;
    unsigned int _id;
    double _weight;
    double _price;
    unsigned int _storage_period;

public:
    Product(std::string name = "name",
            unsigned int id = 0, 
            double weight = 0.0, 
            double price = 0.0, 
            unsigned int storage_period = 7
            ) : _name(name), _id(id), _weight(weight), _price(price), _storage_period(storage_period) {}

    Product(const Product& other) 
    {
        _name = other._name;
        _id = other._id;
        _weight = other._weight;
        _price = other._price;
        _storage_period = other._storage_period;
    }

    Product& operator=(const Product& other)
    {
        if (this != &other) {
            _name = other._name;
            _id = other._id;
            _weight = other._weight;
            _price = other._price;
            _storage_period = other._storage_period;
        }

        return *this;
    }

    virtual double calculate_storage_fee() const
    {
        return 0.05 * _weight;
    }

    virtual void display_info() const
    {
        std::cout << "Name: " << _name << "\nID: " << _id << "\nWeight: " << _weight << "\nPrice: " << _price \
                  << "\nStorage period: " << _storage_period << std::endl;
        std::cout << "++++++++++++++++" << std::endl;

    }

    unsigned int get_product_id() const
    {
        return _id;
    }

    virtual ~Product() = default;
}; 

class PerishableProduct : public Product
{
private:
    time_t _expiration_date;

public:
    PerishableProduct(
            std::string name = "name",
            unsigned int id = 0, 
            double weight = 0.0, 
            double price = 0.0, 
            unsigned int storage_period = 7,
            time_t expiration_date = time(nullptr) + 7 * 24 * 60 * 60
            ) : Product(name, id, weight, price, storage_period), _expiration_date(expiration_date) {}

    double calculate_storage_fee() const
    {
        time_t curr_time = time(nullptr);
        double days_to_expire = difftime(_expiration_date, curr_time) / (60 * 60 * 24);

        return (days_to_expire <= 7) ? Product::calculate_storage_fee() * 1.2 : Product::calculate_storage_fee();
    }

    time_t get_expiration_date() const 
    {
        return _expiration_date;
    }

    ~PerishableProduct() = default;
};

class ElectronicProduct : public Product
{
private:
    unsigned int _warranty_period;
    unsigned int _power_rating;

public:
    ElectronicProduct(
        std::string name = "name",
        unsigned int id = 0, 
        double weight = 0.0, 
        double price = 0.0, 
        unsigned int storage_period = 7,
        unsigned int warranty_period = 0,
        unsigned int power_rating = 0
        ) : Product(name, id, weight, price, storage_period), _warranty_period(warranty_period), _power_rating(power_rating) {}

    void displayInfo() const
    {
        Product::display_info();
        std::cout << "Warranty period:" << _warranty_period << "\nPower raiting:" << _power_rating << std::endl;
    }

    ~ElectronicProduct() = default;
};

class BuildingMaterial : public Product
{
private:
    bool _flammability;

public:
    BuildingMaterial(
        std::string name = "name",
        unsigned int id = 0, 
        double weight = 0.0, 
        double price = 0.0, 
        unsigned int storage_period = 7,
        bool flammability = true
        ) : Product(name, id, weight, price, storage_period), _flammability(flammability) {}


    double calculate_storage_fee() const
    {
        return (_flammability) ? 1.5 * Product::calculate_storage_fee() : Product::calculate_storage_fee();
    }

    bool get_flammability() const
    {
        return _flammability;
    }

    ~BuildingMaterial() = default;
};



class Warehouse
{
private:
    std::vector<Product*> _invetory;

public:
    Warehouse() {}

    Warehouse(const Warehouse& other)
    { 
        for (Product* prod : other._invetory) 
            _invetory.push_back(new Product(*prod));
    }

    Warehouse& operator=(const Warehouse& other)
    {
        if (&other != this)
            for (Product* prod : _invetory)
                delete prod;
        
        _invetory.clear();

        for (Product* prod : other._invetory) 
            _invetory.push_back(new Product(*prod));
    }
    
    void add_prod(Product* prod)
    {
        _invetory.push_back(prod);
    }

    void delete_prod(unsigned int id)
    {
        for (size_t i = 0; i < _invetory.size(); i++) {
            if (_invetory[i]->get_product_id() == id) {
                _invetory.erase(_invetory.begin() + i);
                break;
            }

            continue;
        }
    }

   std::vector<Product*> find_prods_by_category(const std::string& category)
    {
        std::vector<Product*> category_arr;

        for (Product* prod : _invetory) {
            if (category == "PerishableProduct" && dynamic_cast<PerishableProduct*>(prod))
                category_arr.push_back(prod);
            else if (category == "ElectronicProduct" && dynamic_cast<ElectronicProduct*>(prod))
                category_arr.push_back(prod);
            else if (category == "BuildingMaterial" && dynamic_cast<BuildingMaterial*>(prod))
                category_arr.push_back(prod);
        }

        return category_arr;
    }

    double calculate_total_storage_fee() const 
    {
        double total_fee = 0.0;

        for (const Product* prod : _invetory)
            total_fee += prod->calculate_storage_fee();

        return total_fee;
    } 

    std::vector<PerishableProduct*> get_expiring_products(unsigned int days)
    {
        std::vector<PerishableProduct*> exp_products;

        time_t curr_time = time(nullptr);
        time_t deadline = curr_time + days * 24 * 60 * 60;

        for (Product* prod : _invetory) {
            PerishableProduct* perishable = dynamic_cast<PerishableProduct*>(prod);

            if (perishable && perishable->get_expiration_date() <= deadline)
                exp_products.push_back(perishable);
        }

        return exp_products;
    }

    void display_inventory()
    {
        std::vector<Product*> pershible_prods = find_prods_by_category("PerishableProduct");
        std::vector<Product*> electronic_prods = find_prods_by_category("ElectronicProduct");
        std::vector<Product*> building_prods = find_prods_by_category("BuildingMaterial");

        std::cout << "PerishableProduct:" << std::endl;
        for (const Product* prod : pershible_prods) {
            prod->display_info();
            std::cout << "---------------------" << std::endl;
        }
        
        std::cout << "ElectronicProduct:" << std::endl;
        for (const Product* prod : electronic_prods) {
            prod->display_info();
            std::cout << "---------------------" << std::endl;
        }

        std::cout << "BuildingMaterial:" << std::endl;
        for (const Product* prod : building_prods) {
            prod->display_info();
            std::cout << "---------------------" << std::endl;
        }
    }

    Warehouse& operator+= (Warehouse& other)
    {   
        for (Product* prod : other._invetory)
            _invetory.push_back(prod);

        return *this;
    }

    Warehouse& operator-= (unsigned int item_id)
    {   
        for (size_t i = 0; i < _invetory.size(); i++) {
            if (_invetory[i]->get_product_id() == item_id) {
                _invetory.erase(_invetory.begin() + i);
                break;
            } 

            continue;
        }
        
        return *this;
    }
    
    Product* operator[] (unsigned int item_id)
    {   
        for (Product* prod : _invetory) {
            if (prod->get_product_id() == item_id) {
                return prod;
            }

            continue;
        }

        return nullptr;
    }

    friend std::ostream& operator << (std::ostream& stream, const Warehouse& warehouse)
    {
        stream << "Invetory of warehouse\n";
        stream << "=============================\n";

        for (const Product* prod : warehouse._invetory) {
            prod->display_info();
            stream << "-----------------------------\n";
        }

        stream << "Total storage fee: " << warehouse.calculate_total_storage_fee();
        
        stream << "\n=============================\n";

        return stream;
    } 

    ~Warehouse() 
    {
        for (Product* prod : _invetory)
            delete prod;
    }
};
