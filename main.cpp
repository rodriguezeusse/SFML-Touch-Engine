#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Engine.cpp"


using namespace std;
int main()
{	
srand(static_cast<unsigned>(time(NULL)));
	////Initialize Engine Object
	Engine game;
	
	//////Game Loop///////
	while(game.running())
	{
		game.update();
		game.render();	
	}
	//////Game Loop///////
	
	return 0;
}