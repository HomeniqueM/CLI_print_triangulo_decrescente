
#include <iostream>
#include <string>
#include <functional>


void basico (){
    std::cout << "Basico \n"; 
    for(int i = 5; i > 0; --i){
        for(int j = 1; j<= i;++j){
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void medio (){ 
    std::cout << "Medio \n"; 
    for(int i = 5; i > 0; std::cout << "\n", --i)
        for(int j = 1; j <= i; std::cout << j << " ", ++j){}
}


void avancado ( ){ 
    std::cout << "Avancado \n"; 
    for(std::string s{"1 2 3 4 5 "}; s.size() > 0;
        s = s.substr(0,s.size() -2 )){
        std::cout << s << "\n";
        }
}

auto demente()->int{ 
    std::function<std::string (int)> f; 
    f =[&f] (int n){
        return (n == 1) ? "1": f(n-1) + " " + std::to_string(n);
    };
    auto fun = [&f]<typename Ts>(Ts... n){
        return ((f(n)+ "\n")+ ...);
    };

    std::cout << fun( 5,4,3,2,1);
}

void espaco ( ){ 
    std::cout << "\n==============" << "\n";
}
int main(int argc, char const *argv[])
{
    basico();
    espaco();
    medio ();
    espaco();
    avancado();
     espaco();
    demente();
    
    return 0;
}
