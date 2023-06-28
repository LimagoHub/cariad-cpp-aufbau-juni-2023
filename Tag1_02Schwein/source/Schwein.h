//
// Created by JoachimWagner on 26.06.2023.
//

#pragma once
#include <string>
#include <stdexcept>
#include <ostream>

class Schwein {
    std::string name;
    int gewicht;

    inline void setGewicht(int gewicht) {
        Schwein::gewicht = gewicht;
    }

public:

    static const inline std::string default_name{"Nobody"};
    static const inline int initial_weight{10};

    explicit Schwein(const std::string &name = default_name) :  gewicht{initial_weight} {
        setName(name);
    }



    void setName(const std::string &name) {
        if(name == "Elsa") throw std::invalid_argument("Name nicht erlaubt");
        Schwein::name = name;
    }
    void fuettern() {
        setGewicht(getGewicht() + 1);
    }

   // Generierter Code


    const std::string &getName() const {
        return name;
    }

    int getGewicht() const {
        return gewicht;
    }
    bool operator==(const Schwein &rhs) const {
        return name == rhs.name &&
               gewicht == rhs.gewicht;
    }

    bool operator!=(const Schwein &rhs) const {
        return !(rhs == *this);
    }

    friend std::ostream &operator<<(std::ostream &os, const Schwein &schwein) {
        os << "name: " << schwein.name << " gewicht: " << schwein.gewicht;
        return os;
    }
};


