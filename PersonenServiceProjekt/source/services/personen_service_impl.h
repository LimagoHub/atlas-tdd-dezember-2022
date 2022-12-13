//
// Created by JoachimWagner on 13.12.2022.
//

#pragma once
#include "../persistence/person.h"
#include "../persistence/personen_repository.h"
#include "personen_service_exception.h"

class personen_service_impl {

public:
    personen_service_impl(personen_repository &repo) : repo(repo) {}

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
    void speichern(person person_) {
        if(person_.getVorname().length() < 2)
            throw personen_service_exception{"Vorname zu kurz"};

        throw personen_service_exception{"Nachname zu kurz"};
    }
private:
    personen_repository &repo;
};



