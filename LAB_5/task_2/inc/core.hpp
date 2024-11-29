#pragma once

#include <iostream>
#include <fstream>

class Encoder
{
private:
    std::vector<std::byte> key = std::vector<std::byte>(256);
    int x = 0;
    int y = 0;
    std::vector<std::byte> S = std::vector<std::byte>(256);

    void init(std::vector<std::byte>& key) //инициализация вектора-перестановки ключём, используется алгоритм ключевого расписания KSA
    {
        int key_length = key.size();
        
        for (int i = 0; i < 256; i++)
            S[i] = std::byte(i);
        
        int j = 0;
        for (int i = 0; i < 256; i++)
        {
            j = (j + static_cast<int>(S[i]) + static_cast<int>(key[i % key_length])) % 256;
            std::swap(S[i], S[j]);
        }
    }

    std::byte keyIem() //Генерация ключевого потока
    {
        x = (x + 1) % 256;
        y = (y + static_cast<int>(S[x])) % 256;

        std::swap(S[x], S[y]);

        return S[(static_cast<int>(S[x]) + static_cast<int>(S[y])) % 256];
    }

    std::vector<std::byte> encode(std::vector<std::byte>& data)
    {
        std::vector<std::byte> cipher(data.size());

       for (int i = 0; i < data.size(); i++)
            cipher[i] = static_cast<std::byte>(data[i] ^ keyIem());

       return cipher;
    }
    
    std::vector<std::byte> decode(std::vector<std::byte>& data)
    {
        return encode(data);
    }

public:
    Encoder(std::vector<std::byte>& key)
    {
        init(key);
    }

    void setKey(std::vector<std::byte>& new_key)
    {   
        key = new_key;
        init(key);
    }

    void process_file(const std::string& intput_file, const std::string& output_file, bool flag)
    {
        try
        {
            std::ifstream input(intput_file);
            if (!input)
                throw std::runtime_error("Failed to open input file");

            input.seekg(0, std::ios::end);
            std::streamsize size = input.tellg();
            input.seekg(0, std::ios::beg);

            std::vector<std::byte> data(size);

            if (!input.read(reinterpret_cast<char*>(data.data()), size))
                throw std::runtime_error("Failed to read input file");

            input.close();

            std::vector<std::byte> result;

            if (!flag)
                result = decode(data);
            else
                result = encode(data);

            std::ofstream output(output_file, std::ios::binary);
            if (!output)
                throw std::runtime_error("Failed to open output file");

            output.write(reinterpret_cast<const char*>(result.data()), result.size());
            output.close();
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
};
