//
// Created by mrokita on 06.03.19.
//

#ifndef PROI1_MAINWINDOW_H
#define PROI1_MAINWINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::Window {
public:
    MainWindow();
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
};


#endif //PROI1_MAINWINDOW_H
