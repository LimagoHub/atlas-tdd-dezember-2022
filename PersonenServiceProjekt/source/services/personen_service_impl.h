//
// Created by JoachimWagner on 13.12.2022.
//

#pragma once
#include "../persistence/person.h"
#include "../persistence/personen_repository.h"
#include "blacklist_service.h"
#include "personen_service_exception.h"


class personen_service_impl  {

public:
    personen_service_impl(personen_repository &repo, blacklist_service &blacklistService);

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
    void speichern(person person_);
    void speichern(std::string vorname, std::string nachname) {

        speichern(person{vorname,nachname});

    }



private:

    void speichernImpl(const person &person_) const {
        check_person(person_);
        repo.save_or_update(person_);
    }

    void check_person(const person &person_) const {
        business_check(person_);
        validate(person_);

    }

    void business_check(const person &person_) const {
        if (blacklistService.is_blacklisted(person_))
            throw personen_service_exception{"Unerwuenschte Person"};
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




