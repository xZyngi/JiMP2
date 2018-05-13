//
// Created by owsikami on 09.05.18.
//

#include "Serialization.h"

void academia::Room::Serialize(academia::Serializer *c) const {
    c->Header("room");
    c->IntegerField("id", id_);
    c->StringField("name", name_);
    c->StringField("type", EnumToString(type_));
    c->Footer("room");
}

std::string academia::Room::EnumToString(academia::Room::Type enumerator) const {
    switch (enumerator)
    {
        case academia::Room::Type::COMPUTER_LAB:   return "COMPUTER_LAB";
        case academia::Room::Type::CLASSROOM:   return "CLASSROOM";
        case academia::Room::Type::LECTURE_HALL: return "LECTURE_HALL";

    }

}
void academia::Building::Serialize(academia::Serializer *c) const{
    c->Header("building");
    c->IntegerField("id", id_);
    c->StringField("name", name_);




    c->ArrayField("rooms",this->ReferenceVectorFromRooms());
    c->Footer("building");


}

int academia::Building::Id() const {
    return id_;
}

std::vector<std::reference_wrapper<const academia::Serializable>> academia::Building::ReferenceVectorFromRooms() const {
    std::vector<std::reference_wrapper<const academia::Serializable>> result;
    for (auto &room:rooms_) {
        result.emplace_back(std::cref(room));
    }
    return result;
}

// ------**  JSON SERIALIZER **-------



void academia::JsonSerializer::IntegerField(const std::string &field_name, int value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": "+std::to_string(value);


}

void academia::JsonSerializer::DoubleField(const std::string &field_name, double value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": "+std::to_string(value);
}

void academia::JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": \""+value +"\"";
}

void academia::JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": \""+std::to_string(value) +"\""; //tooooo BOOOOOOOL
}

void academia::JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}

void academia::JsonSerializer::ArrayField(const std::string &field_name,
                                          const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    this->EnterComma();
    out_<<"\""+ field_name +"\": ";
    out_<<"[";
    bool is_first_serializable = true;
    
    for(auto i:value){
        //[EnterComa]
        if(is_first_serializable){
            is_first_serializable= false;
        } else {
            out_<<", ";
        }
        //[/EnterComa]

        is_first_=true;
        i.get().Serialize(this);
    }


    out_<<"]";

}

void academia::JsonSerializer::Header(const std::string &object_name) {
    out_<<"{";

}

void academia::JsonSerializer::Footer(const std::string &object_name) {

    out_<<"}";

}


// ------**  XML SERIALIZER  **-------

void academia::XmlSerializer::IntegerField(const std::string &field_name, int value) {
    out_<<"<"+field_name+">";
    out_<<std::to_string(value);
    out_<<"<\\"+field_name+">";

}

void academia::XmlSerializer::DoubleField(const std::string &field_name, double value) {
    out_<<"<"+field_name+">";
    out_<<std::to_string(value);
    out_<<"<\\"+field_name+">";
}

void academia::XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
    out_<<"<"+field_name+">";
    out_<<value;
    out_<<"<\\"+field_name+">";
}

void academia::XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    out_<<"<"+field_name+">";
    out_<<std::to_string(value);
    out_<<"<\\"+field_name+">";
}

void academia::XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}

void academia::XmlSerializer::ArrayField(const std::string &field_name,
                                         const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
    out_<<"<"+field_name+">";
    for(auto i:value){
        i.get().Serialize(this);
    }
    out_<<"<\\"+field_name+">";

}

void academia::XmlSerializer::Header(const std::string &object_name) {
    out_<<"<"+object_name+">";
}

void academia::XmlSerializer::Footer(const std::string &object_name) {
    out_<<"<\\"+object_name+">";

}


// -------** BUILDING REPOSITORY **--------

void academia::BuildingRepository::StoreAll(academia::Serializer *c) const {
    c->Header("building_repository");

    c->ArrayField("buildings", this->ReferenceVectorFromBuildings());
    c->Footer("building_repository");

}

void academia::BuildingRepository::Add(const academia::Building &building) {
    buildings_.emplace_back(building);

}

std::experimental::optional<academia::Building> academia::BuildingRepository::operator[](int id) const{
    for (auto & i: buildings_){
        if(i.Id()==id){
            return i;
        }
    }
}

std::vector<std::reference_wrapper<const academia::Serializable>>
academia::BuildingRepository::ReferenceVectorFromBuildings() const {
    std::vector<std::reference_wrapper<const academia::Serializable>> result;
    for (auto &building:buildings_) {
        result.emplace_back(std::cref(building));
    }
    return result;
}