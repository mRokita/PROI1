//
// Created by mrokita on 06.03.19.
//

#include <gtkmm/treemodelcolumn.h>
#include <gtkmm/liststore.h>
#include <gtkmm/treeview.h>
#include <iostream>
#include "../include/MainWindow.h"

MainWindow::MainWindow(json api_data) {
    set_default_size(800, 500);
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);
    for(json::iterator i = api_data.begin(); i != api_data.end(); ++i){
        Gtk::TreeModel::Row row = *(m_refTreeModel->append());
        auto country = (*i)["country"].get<std::string>();
        auto population = (*i)["total"].get<std::uint32_t>();
        row[m_Columns.m_col_country] = country;
        row[m_Columns.m_col_population] = population;
        std::cout << country << " " << population << std::endl;
    }

    m_TreeView.append_column("Country", m_Columns.m_col_country);
    m_TreeView.append_column("Population", m_Columns.m_col_population);
    add(m_TreeView);
    show_all_children();

    std::cout << "xd\n";
}


