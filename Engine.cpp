#include <iostream>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System/Vector2.hpp>

using namespace std;
using namespace sf;

class Engine
{
	private:
	///////Window//////
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;
	///////Window//////
	
	////////Mouse Positions///////
	Vector2i mousePosWindow;
	Vector2f mousePosView;
	////////Mouse Positions///////
	
	
	//////Game Object//////
	CircleShape touchPos;
	CircleShape touchPos2;
	CircleShape touchPos3;
	CircleShape touchPos4;
	CircleShape touchPos5;
	CircleShape touchPos6;
	CircleShape touchPos7;
	//////Game Object//////
	
		//Private Functions
		void initVariables()
		{
			this->window = nullptr_t();
		}
		void initWindow()
		{
			this->videoMode.height =2998;
			this->videoMode.width = 1440;
			this->window = new RenderWindow(this->videoMode, "Multitouch", Style::Titlebar | Style::Close);
			this->window->setFramerateLimit(120);
		}
		
		void initTouch()
		{
			
			this->touchPos.setRadius(100.f);
			this->touchPos.setPointCount(20);
			this->touchPos.setFillColor(Color(255,0,0));
			this->touchPos2.setRadius(100.f);
			this->touchPos2.setPointCount(20);
			this->touchPos2.setFillColor(Color(255,0,0));
			this->touchPos3.setRadius(100.f);
			this->touchPos3.setPointCount(20);
			this->touchPos3.setFillColor(Color(255,0,0));
			this->touchPos4.setRadius(100.f);
			this->touchPos4.setPointCount(20);
			this->touchPos4.setFillColor(Color(255,0,0));
			this->touchPos5.setRadius(100.f);
			this->touchPos5.setPointCount(20);
			this->touchPos5.setFillColor(Color(255,0,0));
			this->touchPos6.setRadius(100.f);
			this->touchPos6.setPointCount(20);
			this->touchPos6.setFillColor(Color(255,0,0));
			this->touchPos7.setRadius(100.f);
			this->touchPos7.setPointCount(20);
			this->touchPos7.setFillColor(Color(255,0,0));
			
		
		}
	
	public:
		Engine()
		{
			this->initVariables();
			this->initWindow();
			this->initTouch();
		}
		~Engine()
		{
			delete this->window;
		}
		//Accessors
		const bool running() const
		{
			return this->window->isOpen();
		}
		
		
		///////////////Functions////////////////
		
		
		void pollEvents()
		{
			while(this->window->pollEvent(this->ev))
		{
			switch(this->ev.type)
			{
				case Event::Closed:
					this->window->close();
					break;
				case Event::KeyPressed:
					if(this->ev.key.code == Keyboard::Escape)
					this->window->close();
					break;
			}
			
		}
			
		}
		
		
		void updateMousePositions()
		{
			
			this->mousePosWindow = Mouse::getPosition(*this->window);
			this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
			
		}
		
		void updateTouchPos()
		{
			/// avoids touchPos to be left on screen
			this->touchPos.setPosition(Touch::getPosition(0, *this->window).x, Touch::getPosition(0, *this->window).y);
			
			this->touchPos2.setPosition(Touch::getPosition(1, *this->window).x, Touch::getPosition(1, *this->window).y);
			
			this->touchPos3.setPosition(Touch::getPosition(2, *this->window).x, Touch::getPosition(2, *this->window).y);
			
			this->touchPos4.setPosition(Touch::getPosition(3, *this->window).x, Touch::getPosition(3, *this->window).y);
			
			this->touchPos5.setPosition(Touch::getPosition(4, *this->window).x, Touch::getPosition(4, *this->window).y);
			
			this->touchPos6.setPosition(Touch::getPosition(5, *this->window).x, Touch::getPosition(5, *this->window).y);
			
			this->touchPos7.setPosition(Touch::getPosition(6, *this->window).x, Touch::getPosition(6, *this->window).y);
			
		if(Touch::isDown(0))
		{
				this->touchPos.setPosition(Touch::getPosition(0, *this->window).x- this->touchPos.getRadius(), Touch::getPosition(0, *this->window).y- this->touchPos.getRadius());
		}
			if(Touch::isDown(1))
		{
				this->touchPos2.setPosition(Touch::getPosition(1, *this->window).x- this->touchPos2.getRadius(), Touch::getPosition(1, *this->window).y- this->touchPos2.getRadius());
		}
		
		if(Touch::isDown(2))
		{
				this->touchPos3.setPosition(Touch::getPosition(2, *this->window).x- this->touchPos3.getRadius(), Touch::getPosition(2, *this->window).y- this->touchPos3.getRadius());
		}
		
		if(Touch::isDown(3))
		{
				this->touchPos4.setPosition(Touch::getPosition(3, *this->window).x- this->touchPos4.getRadius(), Touch::getPosition(3, *this->window).y- this->touchPos4.getRadius());
		}
		
		if(Touch::isDown(4))
		{
				this->touchPos5.setPosition(Touch::getPosition(4, *this->window).x- this->touchPos5.getRadius(), Touch::getPosition(4, *this->window).y- this->touchPos5.getRadius());
		}
		if(Touch::isDown(5))
		{
				this->touchPos6.setPosition(Touch::getPosition(5, *this->window).x- this->touchPos6.getRadius(), Touch::getPosition(5, *this->window).y- this->touchPos6.getRadius());
		}
		if(Touch::isDown(6))
		{
				this->touchPos7.setPosition(Touch::getPosition(6, *this->window).x- this->touchPos7.getRadius(), Touch::getPosition(6, *this->window).y- this->touchPos7.getRadius());
		}
			
		}
		
		void update()
		{
			this->pollEvents();
			this->updateMousePositions();
			this->updateTouchPos();	
			
			}
		
		
		void renderTouch()
		{
			this->window->draw(this->touchPos);
			this->window->draw(this->touchPos2);
			this->window->draw(this->touchPos3);
			this->window->draw(this->touchPos4);
			this->window->draw(this->touchPos5);
			this->window->draw(this->touchPos6);
			this->window->draw(this->touchPos7);
		}
		void render()
		{
			this->window->clear(Color(0,0,0,0));
			
			/////Draw Objects//////
			this->renderTouch();
			this->window->display();
		}
	protected:
	///////////////Functions////////////////
};