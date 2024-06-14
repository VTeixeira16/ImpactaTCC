#include "BD_Graphics.hpp"
#include "BD_Curl.hpp"

#include <iostream>
#include <random>
#include <time.h>

#include <windows.h>
//#include "BD_Texture.hpp"

BlueDjinn blueDjinn(1920,1080);

#define MACHINE_NAME        "TCC_DESKTOP_WINDOWS_12"
#define MAX_NUMBERS         60

enum GAME_STATE {
    ST_IDLE,
    ST_INIT_PLAY,
    ST_PLAYING,
    ST_PROCESS_GAME,
    ST_ENDGAME
};

const char *formatData(){
    char currentDateTime[24] = {0};

    time_t currentTime;
    time(&currentTime);

    // Converte o tempo atual para uma estrutura tm
    struct tm *localTime = localtime(&currentTime);

    // Extrai as informa��es de data e hora
    int year = localTime->tm_year + 1900; // tm_year � o n�mero de anos desde 1900
    int month = localTime->tm_mon + 1;    // tm_mon � o n�mero de meses desde janeiro (0-11)
    int day = localTime->tm_mday;         // Dia do m�s (1-31)
    int hour = localTime->tm_hour;        // Hora do dia (0-23)
    int minute = localTime->tm_min;       // Minuto (0-59)
    int second = localTime->tm_sec;       // Segundo (0-59)

    sprintf(currentDateTime, "%04d-%02d-%02dT%02d:%02d:%02d.001Z", year, month, day, hour, minute, second);
    std::cout << "HORA ATUAL(currentDateTime): " << currentDateTime << std::endl;

    // "2024-04-22T21:46:44.411Z"

    return strdup(currentDateTime);

}

int LoadData() {

    blueDjinn.Init();

    blueDjinn.LoadAndGetShader("shaders/defaultVS.glsl", "shaders/defaultFS.glsl", nullptr, "sprite", "image");
    blueDjinn.LoadAndGetShader("shaders/textVS.glsl", "shaders/textFS.glsl", nullptr, "text", "text");

    blueDjinn.LoadTexture("resources/textures/cartela.png", true, "cartela");
    blueDjinn.LoadTexture("resources/textures/fundoCartela.png", true, "fundoCartela");


    //blueDjinn.LoadFont("resources/fonts/OCRAEXT.ttf", 64, "fontA_64");
    blueDjinn.LoadFont("resources/fonts/Antonio-Bold.ttf", 72, "fontContador");
    blueDjinn.LoadFont("resources/fonts/Antonio-Bold.ttf", 72, "fontA_72");
    blueDjinn.LoadFont("resources/fonts/Antonio-Bold.ttf", 50, "fontA_50");



    //Ter� uma fun��o na main para carregar as imagens
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;


    return 0;
}

void cleanSortedData(std::vector<unsigned int>& cardNumbers, std::vector<unsigned int>& ballNumbers, std::vector<bool>& cardMarked) {

    cardNumbers.assign(cardNumbers.size(), 0);
    ballNumbers.assign(ballNumbers.size(), 0);
    cardMarked.assign(cardMarked.size(), false);

}

void criaSorteio(std::vector<unsigned int> &cardNumbers) {

    std::vector<unsigned int> allNumbers(MAX_NUMBERS);

    for (int i = 0; i < allNumbers.size(); i++) {
        allNumbers[i] = i + 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, MAX_NUMBERS - 1);
    int random_index;

    //Vou criar um while que vai verificar se allNumbers ainda tem elementos e abastecer os 15 ou 30 primeiros itens da lista (baseado em cardNumbers Size)
    int count = 0;
    while (!allNumbers.empty() && count < cardNumbers.size()) {
        std::uniform_int_distribution<> dis(0, allNumbers.size() - 1);
        random_index = dis(gen);

        cardNumbers[count] = allNumbers[random_index];
        allNumbers.erase(allNumbers.begin() + random_index);

        count++;
    }
        std::sort(cardNumbers.begin(), cardNumbers.end());
}

int countMarked(std::vector<unsigned int>& cardNumbers, std::vector<unsigned int>& ballNumbers, std::vector<bool>& cardMarked) {
    unsigned int marked = 0;
    unsigned int count = 0;
    std::cout << "size(cardNumbers):" << cardNumbers.size() << std::endl;
    std::cout << "size(ballNumbers):" << ballNumbers.size() << std::endl;
    
    while (count < cardNumbers.size() && count < ballNumbers.size()) {

        std::cout << "count:" << count << std::endl;

        for (int i = 0; i < ballNumbers.size(); i++) {
            if (cardNumbers[count] == ballNumbers[i]) {
                cardMarked[count] = true;
                marked++;
                break;
            }
        }


        count++;
    }


    return marked;
}

int main(){

    //verificarAPI("https://localhost:7013/api/LoginData/1", CURL_GET, "");
    //realizarSolicitacaoHTTP("https://example.com", "GET", "");



    LoadData();
    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;

    //Card Position Data
    glm::vec2 cardPosition = glm::vec2(110, 110);
    glm::vec2 ballsPosition = glm::vec2(50, 700);
    std::vector<unsigned int> cardRow = { 90, 340, 590, 840, 1090 };
    std::vector<unsigned int> cardLine = { 70, 270, 470 };

    glm::vec3 colorDefault  = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 colorMarked = glm::vec3(1.0f, 0.0f, 0.0f);

    GAME_STATE gameState = ST_IDLE;

    std::vector<unsigned int> ballSorted(30);

    std::vector<unsigned int> cardNumbers(15);
    std::vector<bool> cardMarked(15);
    int countNumbers = 0;
    int totalCountNumbers = 0;
    int games = 0;

    //Random in CPP
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 60);


    criaSorteio(cardNumbers);
    criaSorteio(ballSorted);


    //TODO - REMOVER
    //for (int i = 0; i < ballSorted.size(); i++) {
    //    ballSorted[i] = dis(gen);
    //}

    //BD_Core_curl_get("https://localhost:7013/api/LoginData/1");





    while (!blueDjinn.isActive){

        switch (gameState)
        {
        case ST_IDLE:
            if (blueDjinn.GetKeyInput(GLFW_KEY_ENTER) || blueDjinn.GetKeyInput(GLFW_KEY_KP_ENTER)) {
                gameState = ST_INIT_PLAY;
            }
            if (blueDjinn.GetKeyInput(GLFW_KEY_F1)) {

                //const char* currentTime = formatData();
                //std::cout << "HORA ATUAL: " << currentTime << std::endl;
                //char body[128] = { 0 };
                //sprintf(body, "{ \"machineName\": \"%s\", \"dateTimePlay\": \"%s\", \"hitsTotal\": %i, \"totalGames\": %i}", MACHINE_NAME, currentTime, totalCountNumbers, games);
                verificarAPI("https://localhost:7013/api/GamesNumber/DeleteLast", CURL_DELETE, "");
                //std::this_thread::sleep_for(std::chrono::milliseconds(500));
                Sleep(500);

            }
            break;
        case ST_INIT_PLAY:
            countNumbers = 0;
            cleanSortedData(cardNumbers, ballSorted, cardMarked);

            criaSorteio(cardNumbers);
            criaSorteio(ballSorted);
            //std::sort(std::begin(cardNumbers), std::end(cardNumbers));
            ////TODO - Remover depois
            //std::sort(std::begin(ballSorted), std::end(ballSorted));
            gameState = ST_PLAYING;
            break;
        case ST_PLAYING:
            //Verfica se n�mero sorteado tem na cartela

            countNumbers = countMarked(cardNumbers, ballSorted, cardMarked);

            games++;
            totalCountNumbers += countNumbers;
            gameState = ST_PROCESS_GAME;
            break;
        case ST_PROCESS_GAME:
            if (!blueDjinn.GetKeyInput(GLFW_KEY_ENTER) && !blueDjinn.GetKeyInput(GLFW_KEY_KP_ENTER)) {
                gameState = ST_ENDGAME;
            }
            break;
        case ST_ENDGAME:
            if (blueDjinn.GetKeyInput(GLFW_KEY_ENTER) || blueDjinn.GetKeyInput(GLFW_KEY_KP_ENTER)) {
                //Continua Partida
                const char* currentTime = formatData();
                std::cout << "HORA ATUAL: " << currentTime << std::endl;
                char body[128] = { 0 };
                sprintf(body, "{ \"machineName\": \"%s\", \"dateTimePlay\": \"%s\", \"hitsTotal\": %i}", MACHINE_NAME, currentTime, countNumbers);
                verificarAPI("https://localhost:7013/api/HitsNumber", CURL_POST, body);
                gameState = ST_IDLE;
            }
            if (blueDjinn.GetKeyInput(GLFW_KEY_SPACE)) {
                //Encerra partida
                const char* currentTime = formatData();
                std::cout << "HORA ATUAL: " << currentTime << std::endl;
                char body[128] = { 0 };
                sprintf(body, "{ \"machineName\": \"%s\", \"dateTimePlay\": \"%s\", \"hitsTotal\": %i, \"totalGames\": %i}", MACHINE_NAME, currentTime, totalCountNumbers, games);
                verificarAPI("https://localhost:7013/api/GamesNumber", CURL_POST, body);
                gameState = ST_IDLE;
                games = 0;
                totalCountNumbers = 0;
            }


            break;
        default:
            break;
        }


        blueDjinn.InitRender();

        
        std::string countText = "Contador: " + std::to_string(countNumbers);
        blueDjinn.DrawText2D("fontContador", countText, 0, 0, 2, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));

        std::string gameStateText = "Estado Atual: " + std::to_string(gameState);
        blueDjinn.DrawText2D("fontContador", gameStateText, 400, 0, 2, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));

        std::string gameQttText = "Partidas: " + std::to_string(games);
        blueDjinn.DrawText2D("fontContador", gameQttText, 900, 0, 2, 1.0f, glm::vec3(0.0f, 0.0f, 0.0f));



        //blueDjinn.DrawSimpleTexture("container", 0, 0, 4);
//        blueDjinn.DrawTexture("fundoCartela", glm::vec3(cardPosition.x - 10, cardPosition.y - 10, 0), glm::vec2(102, 103), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

        blueDjinn.DrawSimpleTexture("fundoCartela", cardPosition.x, cardPosition.y, 0);
        blueDjinn.DrawSimpleTexture("cartela", cardPosition.x, cardPosition.y, 1);

        //blueDjinn.DrawSimpleTexture("impacta", 200, 200, 10);
        //blueDjinn.DrawSimpleTexture("container", 300, 300, 0);
        int i = 0;
        for (int l = 0; l < cardLine.size(); l++) {
            for (int r = 0; r < cardRow.size(); r++){
                std::string numbString = std::to_string(cardNumbers[i]);
                blueDjinn.DrawText2D("fontA_72", numbString, cardPosition.x + cardRow[r], cardPosition.y + cardLine[l], 2, 1.0f, cardMarked[i] == true ? colorMarked : colorDefault);
                i++;
            }
        }
        
        int ballX = 0;
        int ballY = 0;
        for (int j = 0; j < ballSorted.size(); j++){ 
            std::string numbString = std::to_string(ballSorted[j]);
            //Divide bolas sorteadas em 2 linhas
            if (j < ballSorted.size() / 2) {
                blueDjinn.DrawText2D("fontA_50", numbString, ballsPosition.x + (j * 55), ballsPosition.y, 2, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
            } else {
                blueDjinn.DrawText2D("fontA_50", numbString, ballsPosition.x + ((j - ballSorted.size() / 2) * 55), ballsPosition.y + 60, 2, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
            }
        }


        //blueDjinn.DrawText2D("fontA_32", "FonteB", 200, 400, 30, 1.0f, glm::vec3(0.0f, 1.0f, 0.0f));

        //blueDjinn.DrawText2D("fontA_64", "FonteA", 200, 600, 0, 1.0f, glm::vec3(1.0f, 0.0f, 0.0f));
        //blueDjinn.DrawText2D("fontA_32", "FonteB", 200, 600, 2, 1.0f, glm::vec3(0.0f, 1.0f, 0.0f));



        blueDjinn.EndRender();
    }
    glfwTerminate();
    std::cout << "Final do programa" << std::endl;

    return 0;
}
