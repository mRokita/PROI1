#include <iostream>
#include <gtkmm.h>
#include <curl/curl.h>
#include "../include/MainWindow.h"

size_t curl_write(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void get_api_data(){
    curl_global_init(CURL_GLOBAL_ALL);

    CURL* handle = curl_easy_init();
    std::string buffer;
    curl_easy_setopt(handle, CURLOPT_URL, "http://api.population.io/1.0/population/2019/aged/18/");
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curl_write);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &buffer);
    curl_easy_perform(handle);
    std::cout << buffer;
}

int main(int argc, char *argv[]) {
    get_api_data();
    auto app = Gtk::Application::create(argc, argv, "pl.mrokita.proi1");

    MainWindow window;

    return app->run(window);
}
