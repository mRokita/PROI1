//
// Created by mrokita on 06.03.19.
//

#include <gtkmm/treemodelcolumn.h>
#include <gtkmm/liststore.h>
#include <gtkmm/treeview.h>
#include <iostream>
#include "../include/MainWindow.h"

MainWindow::MainWindow() {
    set_default_size(800, 500);
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    Gtk::TreeModel::Row row = *(m_refTreeModel->append());
    m_TreeView.set_model(m_refTreeModel);
    row[m_Columns.m_col_country] = "Polska";
    row[m_Columns.m_col_population] = 10;

    m_TreeView.append_column("Kraj", m_Columns.m_col_country);
    m_TreeView.append_column("Populacja", m_Columns.m_col_population);
    add(m_TreeView);
    show_all_children();

    std::cout << "xd\n";
}