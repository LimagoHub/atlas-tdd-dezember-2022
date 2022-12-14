#pragma once
#include <stdexcept>
#include "euro_to_dollar_presenter.h"
#include "../view/euro_to_dollar_view.h"
#include <stdexcept>


class euro_to_dollar_presenter_impl :
	public euro_to_dollar_presenter
{
private:
	euro_to_dollar_view* view_{ nullptr };
	euro_to_dollar_calculator* model_{ nullptr };
public:
	euro_to_dollar_presenter_impl() = default;

	void set_model(euro_to_dollar_calculator* model) override
	{

		model_ = model;
	}

	void set_view(euro_to_dollar_view* view) override
	{
		view_ = view;
		//populate_items();
	}

	void populate_items() const override
	{
        view_->set_euro("0");
        view_->set_dollar("0");
        view_->set_rechnen_enabled(true);
	}

    //Euro string aus view lesen
    // eurowert wandeln -> double (Im fehlerfall -> Fehlermeldung im Dollarfeld)
    // servicecall -> bei Fehler -> Fehlermeldung im Dollarfeld
    // double dollar -> string
    // ergebnis in das Dollarfeld schreiben
    /*
     *
    */
	void rechnen() const override
	{
        try {
            double euro= std::stod(view_->get_euro());
            double dollar = model_->convert(euro);
            view_->set_dollar(std::to_string(dollar));
        } catch (const std::invalid_argument &ex) {
            view_->set_dollar("Keine Zahl");
        } catch(...) {
            view_->set_dollar("Fehler im Service");
        }
	}

	void beenden() const override
	{
        view_->dispose();
	}

	void update_rechnen_action_state() const override
	{
        try {
            std::stod(view_->get_euro());

            view_->set_rechnen_enabled(true);
        } catch (const std::invalid_argument &ex) {
            view_->set_rechnen_enabled(false);
        }
	}
};

