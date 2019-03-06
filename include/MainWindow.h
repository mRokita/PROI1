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
    explicit MainWindow(json api_data);
    MainWindow() : MainWindow(json::parse("[]")) {};
    ~MainWindow() { std::cout << "MainWindow::destroy" << std::endl;}
protected:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord {
    public:
        ModelColumns() {
            std::cout << "ModelColumns::create" << std::endl;
            add(m_col_country);
            add(m_col_population_total);
            add(m_col_population_male);
            add(m_col_population_female);
        }
        ~ModelColumns() { std::cout << "ModelColumns::destroy" << std::endl;}
        Gtk::TreeModelColumn<Glib::ustring> m_col_country;
        Gtk::TreeModelColumn<int> m_col_population_total;
        Gtk::TreeModelColumn<int> m_col_population_male;
        Gtk::TreeModelColumn<int> m_col_population_female;
    };

    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
    ModelColumns m_Columns;
    Gtk::ScrolledWindow m_ScrolledWindow;
};

#endif //PROI1_MAINWINDOW_H
