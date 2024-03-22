#include "stdio.h" //Vai sumir conforme usarmos o padrão de CPP
#include "curl.h"
#include "BD_Core_curl.hpp"

//int verificarAPI(char *endpoint) {
//    CURL *curl;
//    CURLcode res;

//    curl = curl_easy_init();

//    printf("endpoint:%s\n", endpoint);
//    if(curl) {
//        curl_easy_setopt(curl, CURLOPT_URL, "https://localhost:7013/LoginData/1");
//        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
//        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

//        res = curl_easy_perform(curl);
//        if(res != CURLE_OK)
//            std::cerr << "Erro ao realizar a solicitação HTTP: " << curl_easy_strerror(res) << std::endl;

//        curl_easy_cleanup(curl);
//    }
//    return 0;
//}

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int verificarAPI(char *endpoint) {
    CURL *curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, endpoint);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Realiza a solicitação HTTP GET
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            std::cerr << "Erro ao realizar a solicitação HTTP: " << curl_easy_strerror(res) << std::endl;
        }else {
            // Imprimindo a resposta da API
            std::cout << "Resposta da API: " << response << std::endl;
        }
        // Sempre limpe depois de usar
        curl_easy_cleanup(curl);
    }
    return 0;
}
