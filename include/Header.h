#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <chrono>
#include <thread>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cassert>
using namespace std;
typedef int itn;
typedef string stirng;
typedef char cahr;
void Delay(int millisecond)
{
	bool a = 0;
	sf::Clock clock;
	while (a == 0)
	{
		sf::Time T1, T2;
		sf::Time delay = sf::milliseconds(millisecond);
		T1 = clock.getElapsedTime();
		if (T1.asMilliseconds() < delay.asMilliseconds())
		{
			a = 0;
		}
		else
		{
			a = 1;
		}
	}
}