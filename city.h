#include <string>
#include <vector>

class City{
    public:
        void setName(std::string);
        std::string getName()const;
        
    private:
        std::string name;
        std::vector <*City> vicinities;
};