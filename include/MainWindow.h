//
// Created by mrokita on 06.03.19.
//

#ifndef PROI1_MAINWINDOW_H
#define PROI1_MAINWINDOW_H

#include <gtkmm.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

class MainWindow : public Gtk::Window {
public:
    MainWindow(json api_data);
    MainWindow() : MainWindow(json::parse("[]")) {};
protected:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
        public:
            ModelColumns()
            { add(m_col_country); add(m_col_population); }

            Gtk::TreeModelColumn<Glib::ustring> m_col_country;
            Gtk::TreeModelColumn<int> m_col_population;
    };
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
    ModelColumns m_Columns;
    Gtk::ScrolledWindow m_ScrolledWindow;
};


#endif //PROI1_MAINWINDOW_H
