//
// Created by mrokita on 06.03.19.
//

#include <gtkmm/treemodelcolumn.h>
#include <gtkmm/liststore.h>
#include "../include/MainWindow.h"

class ModelColumns : public Gtk::TreeModelColumnRecord
{
public:

    ModelColumns()
    { add(m_col_country); add(m_col_population); }

    Gtk::TreeModelColumn<Glib::ustring> m_col_country;
    Gtk::TreeModelColumn<int> m_col_population;
};

ModelColumns m_Columns;

MainWindow::MainWindow(void){
    set_default_size(800, 500);
    Glib::RefPtr<Gtk::ListStore> refListStore =
            Gtk::ListStore::create(m_Columns);
    Gtk::TreeModel::Row row = *refListStore->append();
    row[m_Columns.m_col_country] = "Polska";
    row[m_Columns.m_col_population] = 10;
}