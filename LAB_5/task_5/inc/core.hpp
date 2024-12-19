#pragma once

#include  <iostream>
#include <regex>

std::string cdecl_translate(const std::string& code)
{
    std::regex declaration_regex(R"(^\s*(int|float|double|char)\s*\(*(\*+)?\s*([_a-zA-Z][_a-zA-Z0-9]*)\)*\s*(.*?);\s*$)");
    std::regex pointer_regax(R"(^\*+)");
    std::regex array_regax(R"(^\[(\d*)\])");
    std::regex func_ptr_regex(R"(\((.*?)\))");

    std::smatch matches;
    if (!std::regex_match(code, matches, declaration_regex)) {
        for (size_t i = 0; i < code.length(); ++i) {
            std::string sub_code = code.substr(0, i + 1);
            if (!std::regex_match(sub_code, declaration_regex))
                return "Syntax error at position " + std::to_string(i + 1);
        }

        return "Syntax error: invalid declaration";
    }

    std::string base_type = matches[1];
    std::string pointers = matches[2];
    std::string varible = matches[3];
    std::string modifires = matches[4]; 
    
    std::string discription = "declare " + varible + " as ";

    if (!pointers.empty()) {
        for (size_t i = 0; i < pointers.length(); i++)
            discription += "pointer to ";
    }

    while (!modifires.empty()) {
        if (std::regex_search(modifires, matches, pointer_regax)) {
            size_t count = matches[0].length();

            for (size_t i = 0; i < count; i++) 
                discription += "pointer to ";
            
            modifires = modifires.substr(count);

        } else if (std::regex_search(modifires, matches, array_regax)) {
            std::string arr_size = matches[1].str();

            if (arr_size.empty())
                arr_size = "unspecified";

            discription += "array of " + arr_size + " elements of ";
            
            modifires = modifires.substr(matches[0].length());

        } else if (std::regex_search(modifires, matches, func_ptr_regex)) {
            std::string params = matches[1].str();
            
            if (params.empty()) {
                discription += "function returning ";
            } else {
                discription += "function taking " + params + " returning ";
            }
            
            modifires = modifires.substr(matches[0].length());
        
        } else {
            return "Syntax error: invalid modifier in declaration";
        }
    }

    discription += base_type;

    return discription;
}

