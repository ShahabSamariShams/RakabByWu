#include "map.h"

Map::Map(){
    City cityToAdd;
    //BELLA--------------------------------
    cityToAdd.setName("BELLA");
    {
        cityToAdd.addCity("CALINE", true);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("PLADACI", true);
        cityToAdd.addCity("BORGE", true);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("MORINA", false);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //CALINE--------------------------------
    cityToAdd.setName("CALINE");
    {
        cityToAdd.addCity("BELLA", true);
        cityToAdd.addCity("ENNA", true);
        cityToAdd.addCity("ATELA", true);
        cityToAdd.addCity("PLADACI", true);
        cityToAdd.addCity("BORGE", true);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("MORINA", false);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //ENNA--------------------------------
    cityToAdd.setName("ENNA");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", true);
        cityToAdd.addCity("ATELA", true);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("BORGE", true);
        cityToAdd.addCity("DIMASE", true);
        cityToAdd.addCity("MORINA", false);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //ATELA--------------------------------
    cityToAdd.setName("ATELA");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", true);
        cityToAdd.addCity("ENNA", true);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("BORGE", false);
        cityToAdd.addCity("DIMASE", true);
        cityToAdd.addCity("MORINA", false);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("MamadAbad", true);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //DIMASE--------------------------------
    cityToAdd.setName("DIMASE");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", true);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("BORGE", true);
        cityToAdd.addCity("ATELA", true);
        cityToAdd.addCity("MORINA", false);
        cityToAdd.addCity("OLIVADI", true);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("MamadAbad", true);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //BORGE--------------------------------
    cityToAdd.setName("BORGE");
    {
        cityToAdd.addCity("BELLA", true);
        cityToAdd.addCity("CALINE", true);
        cityToAdd.addCity("ENNA", true);
        cityToAdd.addCity("PLADACI", true);
        cityToAdd.addCity("DIMASE", true);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("MORINA", true);
        cityToAdd.addCity("OLIVADI", true);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //PLADACI--------------------------------
    cityToAdd.setName("PLADACI");
    {
        cityToAdd.addCity("BELLA", true);
        cityToAdd.addCity("CALINE", true);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", true);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("MORINA", true);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("ROLLO", true);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //MORINA--------------------------------
    cityToAdd.setName("MORINA");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", true);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("PLADACI", true);
        cityToAdd.addCity("OLIVADI", true);
        cityToAdd.addCity("ROLLO", true);
        cityToAdd.addCity("TALMONE", true);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", true);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //OLIVADI--------------------------------
    cityToAdd.setName("OLIVADI");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", true);
        cityToAdd.addCity("DIMASE", true);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("MORINA", true);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", true);
        cityToAdd.addCity("LIA", true);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //LIA--------------------------------
    cityToAdd.setName("LIA");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", false);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("MORINA", false);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("ARMENTO", true);
        cityToAdd.addCity("OLIVADI", true);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //ARMENTO--------------------------------
    cityToAdd.setName("ARMENTO");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", false);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("MORINA", true);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("TALMONE", true);
        cityToAdd.addCity("ELINIA", false);
        cityToAdd.addCity("LIA", true);
        cityToAdd.addCity("OLIVADI", true);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //TALMONE--------------------------------
    cityToAdd.setName("TALMONE");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", false);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("MORINA", true);
        cityToAdd.addCity("ROLLO", true);
        cityToAdd.addCity("ARMENTO", true);
        cityToAdd.addCity("ELINIA", true);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //ROLLO--------------------------------
    cityToAdd.setName("ROLLO");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", false);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("PLADACI", true);
        cityToAdd.addCity("MORINA", true);
        cityToAdd.addCity("TALMONE", true);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("ELINIA", true);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //ELINIA--------------------------------
    cityToAdd.setName("ELINIA");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", false);
        cityToAdd.addCity("DIMASE", false);
        cityToAdd.addCity("ATELA", false);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("MORINA", true);
        cityToAdd.addCity("TALMONE", true);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("ROLLO", true);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("MamadAbad", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
    //MamadAbad--------------------------------
    cityToAdd.setName("MamadAbad");
    {
        cityToAdd.addCity("BELLA", false);
        cityToAdd.addCity("CALINE", false);
        cityToAdd.addCity("ENNA", false);
        cityToAdd.addCity("BORGE", false);
        cityToAdd.addCity("DIMASE", true);
        cityToAdd.addCity("ATELA", true);
        cityToAdd.addCity("PLADACI", false);
        cityToAdd.addCity("MORINA", false);
        cityToAdd.addCity("TALMONE", false);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("ROLLO", false);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("OLIVADI", false);
        cityToAdd.addCity("ELINIA", false);
    }
    addCity(cityToAdd);
    cityToAdd.emptyVicinitiess();
}

void Map::addCity(City toBeAdded){
    try{
        theMap.at(toBeAdded.getName());
    }
    catch(std::out_of_range exception){
        theMap[toBeAdded.getName()] = toBeAdded;
    }
}

City* Map::toBeFoughtFor(std::string cityName){
    try{
        theMap.at(cityName);
        if(theMap[cityName].getFightability())
            return &theMap[cityName];
        return NULL;
    } 
    catch(std::out_of_range exception){
        return NULL;
    }
}

std::unordered_map <std::string, City> Map::getTheMap(){
    return theMap;
}