#include "stdio.h" //Vai sumir conforme usarmos o padr�o de CPP

#include "curl/curl.h"

/*Windows Specific Additional Depenedencies*/
#pragma comment (lib,"Normaliz.lib")
#pragma comment (lib,"Ws2_32.lib")
#pragma comment (lib,"Wldap32.lib")
#pragma comment (lib,"Crypt32.lib")

#include "BD_Curl.hpp"

size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int verificarAPI(const char *endpoint, int typeRequisition, const char *body) {
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


        // Definir a op��o espec�fica do tipo de solicita��o
        if (typeRequisition == CURL_GET) {
            // Nada a fazer para solicita��o GET
        } else if (typeRequisition == CURL_POST) {
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body);

            struct curl_slist *headers = NULL;
            headers = curl_slist_append(headers, "Content-Type: application/json");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        } else if (typeRequisition == CURL_UPDATE) {
//            url += "/update";
        } else if (typeRequisition == CURL_DELETE) {
//            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
//            // Defina a URL do endpoint de exclus�o
//            url += "/delete";
//            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        } else {
            std::cerr << "Tipo de solicita��o inv�lido" << std::endl;
            return 1;
        }

// Realiza a solicita��o HTTP GET
        res = curl_easy_perform(curl);
        if(res != CURLE_OK){
            std::cerr << "Erro ao realizar a solicita��o HTTP: " << curl_easy_strerror(res) << std::endl;
        }else {
            // Imprimindo a resposta da API
            std::cout << "Resposta da API: " << response << std::endl;
        }
        // Sempre limpe depois de usar
        curl_easy_cleanup(curl);
    }
    return 0;
}

// Fun��o para fazer a solicita��o HTTP para o endpoint da API em localhost
int realizarSolicitacaoHTTP(const char *endpoint, const std::string& tipoSolicitacao, const std::string& corpoSolicitacao) {
    CURL *curl;
    CURLcode res;
    std::string response;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Definir a URL do endpoint
        std::string url = endpoint;

        // Definir a op��o espec�fica do tipo de solicita��o
        if (tipoSolicitacao == "GET") {
            // Nada a fazer para solicita��o GET
        } else if (tipoSolicitacao == "POST") {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POST, 1L);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, corpoSolicitacao.c_str());
        } else if (tipoSolicitacao == "UPDATE") {
            // Defina a URL do endpoint de atualiza��o
            url += "/update";
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            // Defina aqui os dados do corpo da solicita��o UPDATE, se necess�rio
        } else if (tipoSolicitacao == "DELETE") {
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
            // Defina a URL do endpoint de exclus�o
            url += "/delete";
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        } else {
            std::cerr << "Tipo de solicita��o inv�lido" << std::endl;
            return 1;
        }

        // Realiza a solicita��o HTTP
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            std::cerr << "Erro ao realizar a solicita��o HTTP: " << curl_easy_strerror(res) << std::endl;
        } else {
            // Imprimindo a resposta da API
            std::cout << "Resposta da API: " << response << std::endl;
        }

        // Sempre limpe depois de usar
        curl_easy_cleanup(curl);
    } else {
        std::cout << "Erro ao iniciar CURL " << response << std::endl;

    }
    return 0;
}
