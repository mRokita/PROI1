//
// Created by mrokita on 06.03.19.
//

#include <gtkmm/treemodelcolumn.h>
#include <gtkmm/liststore.h>
#include <gtkmm/treeview.h>
#include <iostream>
#include "../include/MainWindow.h"

MainWindow::MainWindow(json api_data) {
    std::cout << "MainWindow::create" << std::endl;
    set_default_size(800, 500);
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);
    for(auto i : api_data){
        Gtk::TreeModel::Row row = *(m_refTreeModel->append());
        auto country = i["country"].get<std::string>();
        auto population_total = i["total"].get<std::uint32_t>();
        auto population_male = i["males"].get<std::uint32_t>();
        auto population_female = i["females"].get<std::uint32_t>();
        row[m_Columns.m_col_country] = country;
        row[m_Columns.m_col_population_total] = population_total;
        row[m_Columns.m_col_population_male] = population_male;
        row[m_Columns.m_col_population_female] = population_female;
    }

    m_TreeView.append_column("Country", m_Columns.m_col_country);
    m_TreeView.append_column("Population (total)", m_Columns.m_col_population_total);
    m_TreeView.append_column("Population (male)", m_Columns.m_col_population_male);
    m_TreeView.append_column("Population (female)", m_Columns.m_col_population_female);
    m_ScrolledWindow.set_policy(Gtk::POLICY_NEVER, Gtk::POLICY_ALWAYS);
    m_ScrolledWindow.add(m_TreeView);
    add(m_ScrolledWindow);
    show_all_children();
}


