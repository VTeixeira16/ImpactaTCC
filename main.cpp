#include "BD_Graphics.hpp"
#include "BD_Core.hpp"

#include <iostream>
#include "texture.h"
//    ResourceManager resourceManager;

BlueDjinn blueDjinn(800,600);

int main(){

    std::cout << __FUNCTION__ << " " << __LINE__ << std::endl;

    verificarAPI("https://localhost:7013/api/LoginData/1");
    verificarAPI("https://localhost:7013/api/LoginData/2");
    verificarAPI("https://localhost:7013/api/LoginData/3");

    blueDjinn.Init();

    while (!blueDjinn.isActive){
        blueDjinn.Render();
    }
    glfwTerminate();
    std::cout << "Final do programa" << std::endl;

    return 0;
}
