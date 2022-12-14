//
// Created by JoachimWagner on 13.12.2022.
//
#include "personen_service_impl.h"

void personen_service_impl::speichern(person person_) {
    try {
        speichernImpl(person_);
    } catch (const personen_service_exception) {
        throw;
//    } catch(const std::exception &ex) {
//        throw personen_service_exception{"Fehler beim Speichern", ex};
    }catch(...) {
        throw personen_service_exception{"Fehler beim Speichern"};
    }
}

personen_service_impl::personen_service_impl(personen_repository &repo, blacklist_service &blacklistService) : repo(
        repo), blacklistService(blacklistService) {}

