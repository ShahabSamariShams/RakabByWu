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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
    }
    addCity(cityToAdd);
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
        cityToAdd.addCity("MORINA", false);
        cityToAdd.addCity("TALMONE", true);
        cityToAdd.addCity("ARMENTO", false);
        cityToAdd.addCity("ROLLO", true);
        cityToAdd.addCity("LIA", false);
        cityToAdd.addCity("OLIVADI", false);
    }
    addCity(cityToAdd);
}

void Map::addCity(City toBeAdded){
    try{
        theMap.at(toBeAdded.getName());
    }
    catch(std::out_of_range exception){
        theMap[toBeAdded.getName()] = toBeAdded;
    }
}