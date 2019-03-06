#include <iostream>
#include <gtkmm.h>
#include <curl/curl.h>
#include "../include/MainWindow.h"

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "pl.mrokita.proi1");

    MainWindow window;

    return app->run(window);
}

void get_api_data(){
    curl_global_init(CURL_GLOBAL_ALL);

    CURL* handle = curl_easy_init();
    std::string buffer;
    curl_easy_setopt(handle, CURLOPT_URL, "http://api.population.io/1.0/population/2019/aged/18/");


}