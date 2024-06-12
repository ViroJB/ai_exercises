#include "app.h"

App::App() {
    // initialize random seed
    srand(time(NULL));

    std::cout << "App constructor" << std::endl;
}

int main() {
    App* app = new App;
    return 0;
}