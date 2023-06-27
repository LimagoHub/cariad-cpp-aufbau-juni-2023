//
// Created by JoachimWagner on 27.06.2023.
//

#pragma once

#include "../persistence/personen_repository.h"
#include "../persistence/person.h"
#include "blacklist_service.h"
#include "personen_service_exception.h"
/*
 *	Vorname < 2 -> PSE
 *	Nachname < 2 -> PSE
 *
 *	Attila -> PSE
 *
 *	Alle technische Exceptions -> PSE
 *
 *	Happy Day -> person an Save_or_update Methode uebergeben
 *
 */
class personen_service_impl {
public:

    personen_service_impl(personen_repository &repo, blacklist_service &blacklistService) :
    repo(repo),blacklistService( blacklistService) {

    }

    void speichern(person &person_){
        try {
            speichern_impl(person_);
        } catch (const personen_service_exception &ex) {
            throw ex;
        } catch (const std::exception &ex) {
            throw personen_service_exception{"Ein Fehler ist aufgetreten", std::make_exception_ptr(ex)};
        }

    }

    void speichern(std::string vorname, std::string nachname) {
        person p{vorname,nachname};
        p.setId("Random");
        speichern(p);
    }


private:

    void speichern_impl(const person &person_) const {
        check_person(person_);
        repo.save_or_update(person_);
    }

    void check_person(const person &person_) const {
        validate(person_);
        business_check(person_);
    }

    void business_check(const person &person_) const {
        if (blacklistService.is_blacklisted(person_))
            throw personen_service_exception{"Blacklisted Person"};
    }

    void validate(const person &person_) const {
        if (person_.getVorname().length() < 2)
            throw personen_service_exception{"Vorname zu kurz"};
        if (person_.getNachname().length() < 2)
            throw personen_service_exception{"Nachname zu kurz"};
    }

    personen_repository &repo;
    blacklist_service &blacklistService;
};
